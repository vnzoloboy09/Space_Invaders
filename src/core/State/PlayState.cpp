#include "PlayState.h"
#include "MainMenuState.h"
#include "StateManager.h"
#include "core/ui/Button.h"

PlayState::PlayState(StateManager* sm, TextureManager* texManager)
    : State(sm, texManager) 
{
	m_buttons.emplace_back(std::make_unique<Button>(
		10, 10, 100, 40, "back_button",
		[this]() { m_stateManager->queueStateChange<MainMenuState>(m_stateManager, m_texManager); }
	));

	// Player
	Entity player = m_entityManager.createEntity();
	m_transforms.add(player, { 600.0f, 800.0f, 64, 64 });
	m_sprites.add(player, { "player_texture" });
	m_velocities.add(player, { 0.0f, 0.0f });
	m_healths.add(player, { 100 });
	m_collisions.add(player, { false, true });

	// Enemy
	for (int r = 0; r < 5; r++) {
		for (int c = 0; c < 10; c++) {
			Entity enemy = m_entityManager.createEntity();
			m_transforms.add(enemy, { 100.0f + c * 70.0f, 50.0f + r * 70.0f, 64, 64 });
			m_sprites.add(enemy, { "enemy_texture" });
			m_enemyTypes.add(enemy, { EnemyKind::Basic });
			m_collisions.add(enemy, { false, true });

		}
	}
}

PlayState::~PlayState() {}

void PlayState::handleEvents(SDL_Event& e) 
{

}

void PlayState::update(float dt)
{
	int mx, my;
	SDL_GetMouseState(&mx, &my);

	bool mousePressed = SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT);

	for (auto& button : m_buttons)
	{
		button->update(mx, my, mousePressed);
	}

	m_movementSystem.update(m_transforms, m_velocities, dt);
}

void PlayState::render(Renderer* renderer)
{
	for (auto& button : m_buttons)
	{
		button->render(renderer, m_texManager);
	}

	for (auto& [entity, sprite] : m_sprites.all()) {
		auto& t = m_transforms.get(entity);
		renderer->draw(
			m_texManager->getTexture(sprite.textureID.c_str()),
			nullptr,
			&t.rect
		);
	}
}
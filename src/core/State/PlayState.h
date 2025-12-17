#pragma once

#include <memory>
#include <vector>

#include "State.h"
#include "ecs/Entity.h"
#include "ecs/ComponentStorage.h"
#include "ecs/Component.h"
#include "ecs/System.h"

class Button;

class PlayState : public State {
public:
    PlayState(StateManager* sm, TextureManager* texManager);
    ~PlayState();

    void handleEvents(SDL_Event& e) override;
    void update(float dt) override;
    void render(Renderer* renderer) override;

private:
    std::vector<std::unique_ptr<Button>> m_buttons;

    EntityManager m_entityManager;

    ComponentStorage<TransformComponent> m_transforms;
    ComponentStorage<SpriteComponent> m_sprites;
    ComponentStorage<VelocityComponent> m_velocities;
    ComponentStorage<HealthComponent> m_healths;
    ComponentStorage<EnemyTypeComponent> m_enemyTypes;
	ComponentStorage<CollisionComponent> m_collisions;

    MovementSystem m_movementSystem;
    EnemyAISystem m_enemyAISystem;
};


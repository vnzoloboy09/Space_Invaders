#pragma once
#include <string>

struct TransformComponent {
    float x, y;
    int w, h;
	SDL_Rect rect = { static_cast<int>(x), static_cast<int>(y), w, h };
};

struct SpriteComponent {
    std::string textureID;
};

struct VelocityComponent {
    float vx, vy;
};

struct HealthComponent {
    int hp;
};

struct CollisionComponent {
    bool isTrigger;
    bool isSolid;
};

enum class EnemyKind {
    Basic,
    Fast,
    Tank,
    Shooter
};

struct EnemyTypeComponent {
    EnemyKind type;
};
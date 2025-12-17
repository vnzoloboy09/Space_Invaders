#pragma once

#include "ComponentStorage.h"
#include "Component.h"
#include <cmath>

class MovementSystem
{
public:
	void update(class ComponentStorage<struct TransformComponent>& transforms,
		class ComponentStorage<struct VelocityComponent>& velocities,
		float deltaTime)
	{
		for (auto& [entity, velocity] : velocities.all())
		{
			if (transforms.has(entity))
			{
				auto& transform = transforms.get(entity);
				transform.x += velocity.vx * deltaTime;
				transform.y += velocity.vy * deltaTime;
			}
		}
	}
};

class EnemyAISystem {
public:
    void update(float dt,
        ComponentStorage<TransformComponent>& transforms,
        ComponentStorage<EnemyTypeComponent>& enemies)
    {
        for (auto& [entity, enemy] : enemies.all()) {
            auto& t = transforms.get(entity);

            switch (enemy.type) {
            case EnemyKind::Basic:
                t.x += 40 * dt;
                break;

            case EnemyKind::Fast:
                t.x += 120 * dt;
                break;

            case EnemyKind::Tank:
                t.x += 20 * dt;
                break;

            case EnemyKind::Shooter:
                t.x += 50 * dt;
                // shooting logic later
                break;
            }
        }
    }
};

inline bool AABB(const TransformComponent& a, const TransformComponent& b) {
    return (
        a.x < b.x + b.w &&
        a.x + a.w > b.x &&
        a.y < b.y + b.h &&
        a.y + a.h > b.y
        );
}

class CollisionSystem {
public:
    template<typename OnCollisionFn>
    void update(ComponentStorage<TransformComponent>& transforms,
        ComponentStorage<CollisionComponent>& collisions,
        OnCollisionFn onCollision)
    {
        auto& allTransforms = transforms.all();

        for (auto itA = allTransforms.begin(); itA != allTransforms.end(); ++itA) {
            Entity a = itA->first;
            if (!collisions.has(a)) continue;

            auto& tA = itA->second;

            for (auto itB = std::next(itA); itB != allTransforms.end(); ++itB) {
                Entity b = itB->first;
                if (!collisions.has(b)) continue;

                auto& tB = itB->second;

                if (AABB(tA, tB)) {
                    onCollision(a, b);
                }
            }
        }
    }
};

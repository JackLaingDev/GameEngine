#include "Utils.h"


std::array<bool, 2> Utils::isIn(ColliderComponent& collider1, ColliderComponent& collider2)
{
	auto collider1Pos = collider1.position;
	auto collider2Pos = collider2.position;

	auto collider1Size = collider1.size;
	auto collider2Size = collider2.size;

	bool inX = !(collider1Pos.x + collider1Size.x <= collider2Pos.x || collider1Pos.x >= collider2Pos.x + collider2Size.x);
	bool inY = !(collider1Pos.y + collider1Size.y <= collider2Pos.y || collider1Pos.y >= collider2Pos.y + collider2Size.y);

	std::array<bool, 2> collisions = { inX, inY };

	return collisions;
}

std::array<bool, 2> Utils::isIn(TerrainColliderComponent& collider, Region& region)
{
	auto colliderPos = collider.position;
	auto regionPos = region.pos;

	auto colliderSize = collider.size;
	auto regionSize = region.size;

	bool inX = !(colliderPos.x + colliderSize.x <= regionPos.x || colliderPos.x >= regionPos.x + regionSize.x);
	bool inY = !(colliderPos.y + colliderSize.y <= regionPos.y || colliderPos.y >= regionPos.y + regionSize.y);


	std::array<bool, 2> collisions = { inX, inY };

	return collisions;
}

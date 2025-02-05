#ifndef Utils_H 
#define Utils_H

#include <iostream> 
#include <array>

#include "Component.h"
#include "TerrainManager.h"


// Class declaration
class Utils {
private:


public:

	static std::array<bool, 2> isIn(ColliderComponent& collider1, ColliderComponent& collider2);
	static std::array<bool, 2> isIn(TerrainColliderComponent& collider, Region& region);

};

#endif 

#ifndef Utils_H 
#define Utils_H

#include <iostream> 
#include <vector>

#include "Component.h"
#include "TerrainManager.h"


// Class declaration
class Utils {
private:


public:

	static bool isIn(ColliderComponent& collider1, ColliderComponent& collider2);
	static bool isIn(TerrainColliderComponent& collider, Region& region);

};

#endif 

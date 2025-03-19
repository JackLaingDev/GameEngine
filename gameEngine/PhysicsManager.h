#ifndef PhysicsManager_H 
#define PhysicsManager_H

#include <iostream> 

#include "EntityManager.h"

// Class declaration
class PhysicsManager {
private:
    
    EntityManager* entityManager;

public:

    PhysicsManager(EntityManager* entityManager);

    void update(float deltatime);

};

#endif 

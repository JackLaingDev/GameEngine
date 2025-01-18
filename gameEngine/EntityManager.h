#ifndef EntityManager_H 
#define EntityManager_H

#include <unordered_map>
#include <typeindex>
#include <memory>
#include "Component.h"
#include <iostream> 

// Class declaration
class EntityManager {
private:
    std::unordered_map<int, std::unordered_map < std::type_index, std::unique_ptr<Component>>> entities;

public:

};

#endif 

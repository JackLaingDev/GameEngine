#ifndef EntityManager_H 
#define EntityManager_H

#include <unordered_map>
#include <typeindex>
#include <memory>
#include <iostream> 

#include "Component.h"
#include "Entity.h"

// Class declaration
class EntityManager {
private:
    std::unordered_map<int, std::unordered_map < std::type_index, std::unique_ptr<Component>>> entities;

public:

    template <typename T, typename... Args>
    void addComponent(Entity entity, Args... args) {
		int entityID = entity.getId();

		// Accesses the std::unordered_map for a given entity and creates and stores a unique pointer to its component
		entities[entityID][std::type_index(typeid(T))] = std::make_unique<T>(std::forward<Args>(args)...);
    }
    
    template <typename T>
    T* getComponent(Entity entity) {
		int entityID = entity.getId();

		// Check entity exists
		if (entities.find(entityID) != entities.end()) {

			auto& componentMap = entities[entityID];
			std::type_index type_index = typeid(T);

			// Check component of type T exists in Entity
			auto it = componentMap.find(type_index);
			if (it != componentMap.end()) {

				return static_cast<T*>(it->second.get()); // Converts to derived class ptr instead of base class ptr
			}

		}
		return nullptr;
    }

};

#endif 

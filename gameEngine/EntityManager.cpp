#include "EntityManager.h"

template <typename T, typename... Args>
void EntityManager::addComponent(Entity entity, Args... args) {
	int entityID = entity.getId();

	// Accesses the std::unordered_map for a given entity and creates and stores a unique pointer to its component
	entities[entityID][std::type_index(typeid(T))] = std::make_unique<T>(std::forward<Args>(args)...);
}
#include "renderManager.h"

RenderManager::RenderManager(std::unique_ptr<sf::RenderWindow> window, EntityManager* entityManager) 
	: window(std::move(window)), entityManager(entityManager)
{
}

void RenderManager::render()
{

}

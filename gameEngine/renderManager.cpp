#include "renderManager.h"

RenderManager::RenderManager(std::unique_ptr<sf::RenderWindow> window, EntityManager* entityManager, TerrainManager* terrainManager)
	: window(std::move(window)), entityManager(entityManager), terrainManager(terrainManager)
{
}

void RenderManager::renderEntities()
{

	const auto& entitiesToRender = entityManager->getEntitiesByComponent<RectangleComponent>();

	for (const auto& entity : entitiesToRender) {
		auto rect = entityManager->getComponent<RectangleComponent>(entity);
		auto transform = entityManager->getComponent<TransformComponent>(entity);

		rect->rectangle.setPosition(transform->position);

		window->draw(rect->rectangle);
	}

	window->display();
}

void RenderManager::renderTerrain()
{
	window->clear(sf::Color::Black);

	auto regions = terrainManager->regions;

	for (const auto& region : regions) {
		window->draw(region.rect);
	}
}

sf::RenderWindow* RenderManager::getWindow()
{
	return window.get();
}

#include "renderManager.h"

RenderManager::RenderManager(std::unique_ptr<sf::RenderWindow> window) : window(std::move(window))
{
}

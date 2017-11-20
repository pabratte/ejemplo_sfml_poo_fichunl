#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics/RenderWindow.hpp>

class Entity {
public:
virtual void update() = 0;
virtual void draw(sf::RenderWindow &w) = 0;
};

#endif


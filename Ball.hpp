#ifndef BALL_H
#define BALL_H
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "poo_game/Entity.h"

class Ball: public Entity{
public:
	Ball();
	void update(float elapsed) override;
	void draw(sf::RenderWindow &w) override;
	sf::Sprite &getSprite();
private:
	sf::Texture texBall;
	sf::Sprite spBall;
	sf::Vector2f velBall;
};

#endif


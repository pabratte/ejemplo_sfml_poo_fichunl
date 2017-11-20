#ifndef CHARACTER_H
#define CHARACTER_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "poo_game/Entity.h"
#include "Ball.h"

class Character: public Entity{
public:
	Character(const sf::Vector2f &pos);
	void update() override;
	void draw(sf::RenderWindow &w) override;
	sf::Sprite &getSprite();
	bool collidesWithBall(Ball *b);
	
private:
	sf::Sprite spChar;
	sf::Texture texChar;
	
	const float CHAR_VEL = 5;
};

#endif


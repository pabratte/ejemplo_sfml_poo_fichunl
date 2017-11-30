#ifndef CHARACTER_H
#define CHARACTER_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "poo_game/Entity.hpp"
#include "Ball.hpp"

class Player: public Entity{
public:
	Player(const sf::Vector2f &pos);
	void update(float elapsed) override;
	void draw(sf::RenderWindow &w) override;
	sf::Sprite &getSprite();
	bool collidesWithBall(Ball *b);
	
private:
	sf::Sprite spChar;
	sf::Texture texChar;
	
	const float CHAR_VEL = 5;
};

#endif


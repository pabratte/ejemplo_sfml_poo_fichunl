#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Game {
public:
	Game();
	void run();
	
private:
	sf::RenderWindow w;
	sf::Texture texChar;
	sf::Texture texBackground;
	sf::Texture texBall;
	sf::Sprite spChar;
	sf::Sprite spBackground;
	sf::Sprite spBall;
	sf::Vector2f velBall;
	
	void init();
	void update();
	void draw();
};

#endif


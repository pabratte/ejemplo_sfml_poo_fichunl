#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics/RenderWindow.hpp>

class Game {
public:
	Game();
	void run();
	
private:
	sf::RenderWindow w;
	
	void init();
	void update();
	void draw();
};

#endif


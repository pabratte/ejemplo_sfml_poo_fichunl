#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Character.h"
#include <vector>
using namespace std;

class Game {
public:
	Game();
	void run();
	void add(Entity *e);
	
private:
	sf::RenderWindow w;
	sf::Texture texBackground;
	sf::Sprite spBackground;
	
	
	Character *character;
	Ball *ball;
	
	vector<Entity *> entities;
	
	void init();
	void update();
	void draw();
};

#endif


#include "poo_game/Game.hpp"
#include "PlayScene.hpp"
#include "MenuScene.hpp"
using namespace sf;

int main(int argc, char *argv[]){
	BaseScene *scene = new MenuScene();
	Game &g = Game::create(sf::VideoMode(640, 400), scene, "Ejemplo SFML POO");
	g.run();
	
	return 0;
}


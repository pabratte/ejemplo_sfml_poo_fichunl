#ifndef MENUSCENE_HPP
#define MENUSCENE_HPP
#include "poo_game/BaseScene.hpp"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

class MenuScene : public BaseScene {
	sf::Text titleText;
	sf::Text scoreText;
	sf::Text pressStartText;
	sf::Font titleFont;
	
public:
	MenuScene();
	void update(float elapsed);
	void draw(sf::RenderWindow &w);
};

#endif


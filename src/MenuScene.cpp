#include "MenuScene.hpp"
#include <iostream>
#include "poo_game/Game.hpp"
#include "PlayScene.hpp"
#include <sstream>
#include "Global.hpp"
using namespace std;

MenuScene::MenuScene(){
	if(!titleFont.loadFromFile("assets/fonts/Cave-Story.ttf")){
		cerr<<"ERROR: no se encontro la fuente "<<"assets/font/Cave-Story.ttf"<<endl;
	}
	titleText.setFont(titleFont);
	titleText.setColor(sf::Color::White);
	titleText.setString("Ejemplo SFML");
	titleText.setCharacterSize(120);
	// centra el texto
	titleText.setPosition(sf::Vector2f((640-titleText.getLocalBounds().width)/2.0, 0));
	
	scoreText.setFont(titleFont);
	scoreText.setColor(sf::Color::White);
	stringstream ss;
	ss<<"HIGH SCORE: "<<Global::highScore;
	scoreText.setString(ss.str());
	scoreText.setCharacterSize(40);
	scoreText.setPosition(sf::Vector2f((640-scoreText.getLocalBounds().width)/2.0, 150));
	
	pressStartText.setFont(titleFont);
	pressStartText.setColor(sf::Color::White);
	pressStartText.setString("Presione ENTER para comenzar");
	pressStartText.setCharacterSize(40);
	pressStartText.setPosition(sf::Vector2f((640-pressStartText.getLocalBounds().width)/2.0, 250));
}

void MenuScene::update(float elapsed){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
		Game::getInstance().switchScene(new PlayScene());
	}
}

void MenuScene::draw(sf::RenderWindow &w){
	BaseScene::draw(w);
	w.draw(titleText);
	w.draw(scoreText);
	w.draw(pressStartText);
}

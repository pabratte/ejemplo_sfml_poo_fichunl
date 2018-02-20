#include "PlayScene.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include <sstream>
#include "Global.hpp"
#include "MenuScene.hpp"
#include "poo_game/Game.hpp"
using namespace std;

PlayScene::PlayScene(){
	player = new Player(sf::Vector2f(304, 306));
	add(player);
	
	minVel = 150;
	createNewBall(minVel);
	timeToNewBall.restart();
	if(!fontScoreText.loadFromFile("assets/fonts/Cave-Story.ttf")){
		cerr<<"ERROR: no se encontro la fuente "<<"assets/font/Cave-Story.ttf"<<endl;
	}
	
	texBackground.loadFromFile("assets/images/background.png");
	spBackground.setTexture(texBackground);
	
	score = 0;
	scoreText.setFont(fontScoreText);
	scoreText.setColor(sf::Color::White);
}


void PlayScene::update(float elapsed){
	// actualiza al personaje
	BaseScene::update(elapsed);
	
	// crear nueva pelota
	if(timeToNewBall.getElapsedTime().asSeconds()>10){
		minVel += 50;
		createNewBall(minVel);
		timeToNewBall.restart();
	}
	
	// revisa colisiones entre el personaje y las pelotas
	for(const auto &ball: balls){
		if(player->collidesWithBall(ball)){
			if(score > Global::highScore){
				Global::highScore = score;
			}
			Game::getInstance().switchScene(new MenuScene());
		}
	}
	
	// actualiza el puntaje
	score += elapsed;
	stringstream tmp;
	tmp<<"SCORE: "<<int(score);
	scoreText.setString(tmp.str());
}

void PlayScene::draw(sf::RenderWindow &w){
	w.draw(spBackground);
	BaseScene::draw(w);
	w.draw(scoreText);
}

void PlayScene::createNewBall(float minVel){
	Ball *b = new Ball();
	balls.push_back(b);
	add(b);
}


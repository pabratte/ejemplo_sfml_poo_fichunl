#include "Game.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <cstdlib>
using namespace std;

Game::Game(){
	init();
}

void Game::init(){
	// crear la ventana de juego
	w.create(sf::VideoMode(640,400),"Ejemplo de SFML");
	
	// limitar la cantidad de actualizaciones por segundo
	w.setFramerateLimit(60);
	
	// cargar las texturas
	texBackground.loadFromFile("assets/images/background.png");
	texChar.loadFromFile("assets/images/char.png");
	texBall.loadFromFile("assets/images/ball.png");
	
	// crear los sprites
	spBackground.setTexture(texBackground);
	spChar.setTexture(texChar);
	spBall.setTexture(texBall);
	// posicionar al personaje
	spChar.setPosition(304, 306);
	
	// posicionar la pelota
	srand(time(0));
	spBall.setPosition(rand()%608, rand()%200);
	velBall.x = 2+rand()%3;
	velBall.y = 2+rand()%3;
}

void Game::run(){
	// correr el bucle de juego
	while(w.isOpen()) {
		// esto es necesario para quitar todos 
		// los eventos de la cola de la ventana
		sf::Event e;
		while(w.pollEvent(e)) {
			if(e.type == sf::Event::Closed)
				w.close();	
		}
		
		// actualizar
		update();
		
		// dibujar
		draw();
	}
}


void Game::update(){
	// mover al personaje
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		spChar.move(-5, 0);
	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		spChar.move(5, 0);
	}
	
	// mover la pelota
	spBall.move(velBall);
	
	// limitar el movimiento de la pelota a la ventana
	sf::Vector2f ballPos = spBall.getPosition();
	if(ballPos.x < 0){
		ballPos.x = 0;
		velBall.x *= -1;
	}
	if(ballPos.x > 608){
		ballPos.x = 608;
		velBall.x *= -1;
	}
	if(ballPos.y < 0){
		ballPos.y = 0;
		velBall.y *= -1;
	}
	if(ballPos.y > 306){
		ballPos.y = 306;
		velBall.y *= -1;
	}
	spBall.setPosition(ballPos);
	
	// limitar el movimiento del personaje a la ventana
	sf::Vector2f charPos = spChar.getPosition();
	if(charPos.x < 0) charPos.x = 0;
	if(charPos.x > 608) charPos.x = 608;
	spChar.setPosition(charPos);
	
	// detectar colisiones entre el personaje y la bola
	sf::FloatRect charRect = spChar.getGlobalBounds();
	sf::FloatRect ballRect = spBall.getGlobalBounds();
	if(charRect.intersects(ballRect)){
		w.close();
	}
}

void Game::draw(){
	// limpiar la pantalla
	w.clear(sf::Color::Black);
	// dibujar los sprites del juego
	w.draw(spBackground);
	w.draw(spChar);
	w.draw(spBall);
	// refrescar la ventana
	w.display();
}



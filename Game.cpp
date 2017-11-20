#include "Game.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Keyboard.hpp>

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
	
	// crear los sprites
	spBackground.setTexture(texBackground);
	spChar.setTexture(texChar);
	
	// posicionar al personaje
	spChar.setPosition(304, 306);
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
	
	// limitar el movimiento del personaje a la ventana
	sf::Vector2f charPos = spChar.getPosition();
	if(charPos.x < 0) charPos.x = 0;
	if(charPos.x > 608) charPos.x = 608;
	spChar.setPosition(charPos);
}

void Game::draw(){
	// limpiar la pantalla
	w.clear(sf::Color::Black);
	// dibujar los sprites del juego
	w.draw(spBackground);
	w.draw(spChar);
	// refrescar la ventana
	w.display();
}



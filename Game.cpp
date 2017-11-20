#include "Game.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>

Game::Game(){
	init();
}

void Game::init(){
	w.create(sf::VideoMode(640,400),"Ejemplo de SFML");
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
	
}

void Game::draw(){
	w.clear(sf::Color::Black);
	/// draw game objects here...
	w.display();
}



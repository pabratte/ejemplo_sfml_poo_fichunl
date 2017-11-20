#include "Game.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>

Game::Game(){
	init();
}

void Game::init(){
	// crear la ventana de juego
	w.create(sf::VideoMode(640,400),"Ejemplo de SFML");
	
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



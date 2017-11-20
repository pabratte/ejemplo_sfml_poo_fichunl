#include "Game.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <cstdlib>
#include "Ball.h"
using namespace std;

Game::Game(){
	init();
}

void Game::init(){
	// crear la ventana de juego
	w.create(sf::VideoMode(640,400),"Ejemplo de SFML");
	
	// limitar la cantidad de actualizaciones por segundo
	w.setFramerateLimit(60);
	
	// crear el fondo
	texBackground.loadFromFile("assets/images/background.png");
	spBackground.setTexture(texBackground);
	
	
	// crear al personaje
	character = new Character(sf::Vector2f(304, 306));
	add(character);
	
	// crear la pelota
	ball = new Ball();
	add(ball);
}

void Game::add(Entity *e){
	entities.push_back(e);
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
	for(auto e: entities){
		e->update();
	}
	
	// detectar colisiones entre el personaje y la bola
	if(character->collidesWithBall(ball)){
		w.close();
	}
}

void Game::draw(){
	// limpiar la pantalla
	w.clear(sf::Color::Black);
	// dibujar los elementos del juego
	w.draw(spBackground);
	for(auto e: entities){
		e->draw(w);
	}
	// refrescar la ventana
	w.display();
}



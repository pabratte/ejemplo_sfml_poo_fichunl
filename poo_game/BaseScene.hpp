#ifndef BASESCENE_HPP
#define BASESCENE_HPP
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Entity.hpp"
#include <vector>
using namespace std;


/***
 * Representa una escena del juego.
 * Para crear una nueva clase de escena, heredar de �sta clase
 * y redefinir el comportamiento de los m�todos
 */ 
class BaseScene {
public:
	/// constructor
	BaseScene();
	
	/// funci�n que ser� invocada para actualizar la escena
	virtual void update(float elapsed);
	
	/// funci�n que ser� invocada para dibujar la escena
	virtual void draw(sf::RenderWindow &w);

	/// funci�n que ser� invocada para notificar a la escena de un evento
	virtual void process_event(const sf::Event &e);

	/// agrega un nuevo actor a la escena
	void add(Entity *e);
	
	/// eliminar un actor de la escena
	void remove(Entity *e);
	
private:
	vector<Entity *> entities;
	vector<Entity *> to_delete;
};

#endif


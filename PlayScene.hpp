#ifndef PLAYSCENE_HPP
#define PLAYSCENE_HPP
#include <string>
#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "poo_game/BaseScene.hpp"
#include "Player.hpp"
#include "Ball.hpp"

using namespace std;

class PlayScene: public BaseScene{
private:
	Player *player;						/// el jugador
	vector<Ball *> balls;				/// arreglo con las pelotas
	float minVel;						/// velocidad mínima de la próxima pelota que se creara
	sf::Clock timeToNewBall;			/// reloj para medir cuándo crear una nueva pelota
	float score;						/// puntaje
	sf::Text scoreText;					/// texto para mostrar el puntaje
	sf::Font fontScoreText;				/// fuente del texto
	void createNewBall(float minVel);	/// agregar una nueva pelota
	sf::Texture texBackground;			/// textura del fondo
	sf::Sprite spBackground;			/// sprite del fondo
	
public:
	PlayScene();
	void update(float elapsed);
	void draw(sf::RenderWindow &w);
};

#endif


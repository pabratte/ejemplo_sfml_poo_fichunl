#include "Ball.h"


Ball::Ball(){
	texBall.loadFromFile("assets/images/ball.png");
	spBall.setTexture(texBall);
	
	srand(time(0));
	spBall.setPosition(rand()%608, rand()%200);
	velBall.x = 2+rand()%3;
	velBall.y = 2+rand()%3;
}

void Ball::update(float elapsed){
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
}

void Ball::draw(sf::RenderWindow &w){
	w.draw(spBall);
}

sf::Sprite &Ball::getSprite(){
	return spBall;
}

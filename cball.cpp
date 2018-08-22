/** Copyright (C) Belkebir Mohand Tahar, 2018
 *
 * You can do whatever you want with this code as long as it is not something bad ;)
*/

#include "cball.h"

#include <ctime>

CBall::CBall()
	: sf::RectangleShape(sf::Vector2f(10, 10))
{
	srand(time(nullptr));
	lastDirection = Direction(rand() % DOWN_RIGHT); //To make the ball go to a random direction at the beginning of the game
}

void CBall::go(Direction direction)
{
	lastDirection = direction;
	switch (lastDirection) {
	case UP_LEFT:
		this->move(-0.25f, -0.25f);
		break;
	case UP_RIGHT:
		this->move(0.25f, -0.25f);
		break;
	case DOWN_LEFT:
		this->move(-0.25f, 0.25f);
		break;
	case DOWN_RIGHT:
		this->move(0.25f, 0.25f);
	}
}

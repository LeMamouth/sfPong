/** Copyright (C) Belkebir Mohand Tahar, 2018
 *
 * You can do whatever you want with this code as long as it is not something bad ;)
*/

#ifndef CBALL_H
#define CBALL_H

#include <SFML/Graphics.hpp>

enum Direction {
	UP_RIGHT,
	UP_LEFT,
	DOWN_LEFT,
	DOWN_RIGHT
};

class CBall : public sf::RectangleShape {
public:
	CBall();
	void go(Direction direction);
	Direction lastDirection;
};

#endif // CBALL_H

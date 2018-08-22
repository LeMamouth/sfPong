/** Copyright (C) Belkebir Mohand Tahar, 2018
 *
 * You can do whatever you want with this code as long as it is not something bad ;)
*/

#include "cpaddle.h"

CPaddle::CPaddle(float w, float h)
	: sf::RectangleShape(sf::Vector2f(w, h))
{
}

CPaddle::CPaddle(CPaddle& other)
	: sf::RectangleShape(sf::Vector2f(other.getSize().x, other.getSize().y))
{
}

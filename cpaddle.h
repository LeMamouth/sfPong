/** Copyright (C) Belkebir Mohand Tahar, 2018
 *
 * You can do whatever you want with this code as long as it is not something bad ;)
*/

#ifndef CPADDLE_H
#define CPADDLE_H

#include <SFML/Graphics.hpp>

class CPaddle : public sf::RectangleShape {
public:
	CPaddle(float w, float h);
	CPaddle(CPaddle& other);
};

#endif // CPADDLE_H

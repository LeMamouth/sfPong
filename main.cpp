/** Copyright (C) Belkebir Mohand Tahar, 2018
 *
 * You can do whatever you want with this code as long as it is not something bad ;)
*/

#include <SFML/Graphics.hpp>

#include "cball.h"
#include "cpaddle.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;
	sf::RenderWindow window(sf::VideoMode(640, 480), "Pong mais fait par Mr.Belkebir (Si, si)", sf::Style::Close, settings);
	sf::Event event;
	sf::Font font;
	font.loadFromFile("assets/volter.ttf");

	bool pause = true;

	CPaddle leftPaddle(10.0f, 80.0f), rightPaddle(leftPaddle);
	CBall ball;

	sf::RectangleShape screenCenter(sf::Vector2f(2, 480));
	screenCenter.setPosition(window.getSize().x / 2 - screenCenter.getSize().x / 2, 0);
	screenCenter.setFillColor(sf::Color::White);

	leftPaddle.setPosition(0, window.getSize().y / 2 - leftPaddle.getSize().y / 2);
	rightPaddle.setPosition(630, window.getSize().y / 2 - leftPaddle.getSize().y / 2);

	unsigned int leftScore = 0, rightScore = 0;

	sf::Text leftScoreDisplay(std::to_string(leftScore), font), rightScoreDisplay(std::to_string(rightScore), font);
	leftScoreDisplay.setPosition(window.getSize().x / 4, 20);
	rightScoreDisplay.setPosition((window.getSize().x / 2 + window.getSize().x) / 2, 20);

	ball.setPosition(window.getSize().x / 2 - ball.getSize().x / 2, window.getSize().y / 2 - ball.getSize().y / 2);

	while (window.isOpen()) {
		if (pause) {
			window.waitEvent(event);
		} else {
			window.pollEvent(event);
		}
		switch (event.type) {
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::KeyPressed:
			switch (event.key.code) {
			case sf::Keyboard::Up:
				if (leftPaddle.getPosition().y >= 0)
					leftPaddle.move(0, -1);
				break;
			case sf::Keyboard::Down:
				if (leftPaddle.getPosition().y <= 430)
					leftPaddle.move(0, 1);
				break;
			case sf::Keyboard::Enter:
				pause = pause ? false : true;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
		ball.go(ball.lastDirection);

		if (ball.getPosition().x <= leftPaddle.getPosition().x + leftPaddle.getSize().x && ball.getPosition().y >= leftPaddle.getPosition().y && ball.getPosition().y <= leftPaddle.getPosition().y + leftPaddle.getSize().y) {
			switch (ball.lastDirection) {
			case UP_LEFT:
				ball.go(UP_RIGHT);
				break;
			case DOWN_LEFT:
				ball.go(DOWN_RIGHT);
				break;
			default:
				break;
			}
		} else if (ball.getPosition().x >= rightPaddle.getPosition().x && ball.getPosition().y >= rightPaddle.getPosition().y && ball.getPosition().y <= rightPaddle.getPosition().y + rightPaddle.getSize().y) {
			ball.setPosition(630, ball.getPosition().y);
			switch (ball.lastDirection) {
			case UP_RIGHT:
				ball.go(UP_LEFT);
				break;
			case DOWN_RIGHT:
				ball.go(DOWN_LEFT);
				break;
			default:
				break;
			}
		}

		if (ball.getPosition().y <= 0) {
			ball.setPosition(ball.getPosition().x, 0);
			switch (ball.lastDirection) {
			case UP_LEFT:
				ball.go(DOWN_LEFT);
				break;
			case UP_RIGHT:
				ball.go(DOWN_RIGHT);
				break;
			default:
				break;
			}
		} else if (ball.getPosition().y >= 470) {
			ball.setPosition(ball.getPosition().x, 470);
			switch (ball.lastDirection) {
			case DOWN_RIGHT:
				ball.go(UP_RIGHT);
				break;
			case DOWN_LEFT:
				ball.go(UP_LEFT);
				break;
			default:
				break;
			}
		}
		if (ball.getPosition().x < 0) {
			rightScore++;
			ball.setPosition(window.getSize().x / 2 - ball.getSize().x / 2, window.getSize().y / 2 - ball.getSize().y / 2);
			pause = true;
		} else if (ball.getPosition().x > 640) {
			leftScore++;
			ball.setPosition(window.getSize().x / 2 - ball.getSize().x / 2, window.getSize().y / 2 - ball.getSize().y / 2);
			pause = true;
		}
		if (rightPaddle.getPosition().y < ball.getPosition().y)
			rightPaddle.move(0, 20.0f);
		if (rightPaddle.getPosition().y + rightPaddle.getSize().y > ball.getPosition().y)
			rightPaddle.move(0, -20.0f);

		leftScoreDisplay.setString(std::to_string(leftScore));
		rightScoreDisplay.setString(std::to_string(rightScore));
		window.clear(sf::Color::Black);
		window.draw(leftPaddle);
		window.draw(rightPaddle);
		window.draw(screenCenter);
		window.draw(ball);
		window.draw(leftScoreDisplay);
		window.draw(rightScoreDisplay);
		window.display();
	}
	return EXIT_SUCCESS;
}


#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	rect.setFillColor(sf::Color::White);
	rect.setSize(sf::Vector2f(50,50));
	rect.setPosition(50,300);

	rect2.setFillColor(sf::Color::Black);
	rect2.setSize(sf::Vector2f(50, 50));
	rect2.setPosition(window->getSize().x - 200, 300);

	rect3.setFillColor(sf::Color::Green);
	rect3.setSize(sf::Vector2f(50, 50));
	rect3.setPosition((window->getSize().x)/2, (window->getSize().y) / 2);
	



	speed = 200.0f;
	player_speed = 400.0f;
	reverse = false;
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::A)) { 
		if (!(rect2.getPosition().x - 50 < - 50)) {
			rect2.move(-(player_speed * dt), 0);
		}
	}if (input->isKeyDown(sf::Keyboard::W)) { 
		if (!(rect2.getPosition().y + 50 <= 50)) {
			rect2.move(0, -(player_speed * dt));
		}
	}if (input->isKeyDown(sf::Keyboard::S)) { 
		if (!(rect2.getPosition().y >= window->getSize().y - 50)) {
			rect2.move(0, player_speed * dt);
		}	
	}if (input->isKeyDown(sf::Keyboard::D)) { 
		if (!(rect2.getPosition().x - 50 >= window->getSize().x-100)) {
			rect2.move(player_speed * dt, 0);
		}
	}

}

// Update game objects
void Level::update(float dt)
{
	//handles collision for the reversing of rectangle 1
	if (rect.getPosition().x - 60 >= window->getSize().x-100) { 
		reverse = true;
	}
	else if (rect.getPosition().x <= 0) {
		reverse = false;
	}
		
	if (reverse == true) {
		rect.move(-(speed * dt), 0);
	} if (reverse == false) {
		rect.move(speed * dt, 0);
	}

	//handles the collision for rectangle 2
	if (rect2.getPosition().x - 50 >= window->getSize().x - 100) {
		rect2.move(0, 0);
	}if (rect2.getPosition().y + 50 >= window->getSize().y + 100) {
		rect2.move(0, 0);
	}

	if (rect3.getPosition().x - 50 > window->getSize().x - 100) {
		rect3.move(speed * dt, 0);
	}



	
	
}

// Render level
void Level::render()
{
	beginDraw();

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->draw(rect);
	window->draw(rect2);
	window->draw(rect3);

	window->display();
	
}
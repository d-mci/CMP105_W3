#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	sf::RectangleShape rect;
	sf::RectangleShape rect2;
	sf::RectangleShape rect3;
	sf::Clock clock;

	Input* input;


	float speed;	
	float player_speed;
	bool reverse;
};
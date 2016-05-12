#include "Game.h"
#include "Input.h"
#include <iostream>

Game::Game()
{
}

void Game::Input()
{
	if (Input::GetMouseDown(Input::LEFT_MOUSE))
	{
		std::cout << "Click!" << std::endl;
	}
}

void Game::Update()
{
}

void Game::Render()
{
}

Game::~Game()
{
}

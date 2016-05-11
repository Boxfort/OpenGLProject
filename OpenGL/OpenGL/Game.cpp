#include "Game.h"
#include "Input.h"
#include <iostream>

Game::Game()
{
}

void Game::Input()
{
	if (Input::GetKeyDown(Input::KEY_UP))
	{
		std::cout << "Pressed up!" << std::endl;
	}
	if (Input::GetKeyUp(Input::KEY_UP))
	{
		std::cout << "Released up!" << std::endl;
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

#include "GameInventory.hpp"
#include <iostream>

using namespace std;
using namespace sf;

GameInventory::GameInventory(Game * game)
{
	this->game = game;
	auto x = (Vector2f)this->game->window.getSize();

	m_view.setSize(x);
	m_view.setCenter(x*.5f);

	GameState::texture_manager->addElement("inventory_background", "data\\inventory.png");

	m_background.setTexture(GameState::texture_manager->getElement("inventory_background"));

	m_background.setScale(x.x / m_background.getTexture()->getSize().x, x.y / m_background.getTexture()->getSize().y);


	for (int j = 0; j < 10; ++j)
		for (int i = 0; i < 4; ++i)
			m_items_pos.push_back(IntRect(538 + 57 * i, 95 + 41.5 * j, 52, 39));
			

	
}

void GameInventory::draw(const float delta_time)
{
	game->window.setView(m_view);
	game->window.draw(m_background);

}

void GameInventory::update(const float delta_time)
{

}

void GameInventory::eventLoop()
{
	Event event;

	while (game->window.pollEvent(event))
	{
		switch (event.type)
		{
		case Event::Closed:
		{
			game->window.close();
			break;
		}

		case Event::KeyPressed:
		{
			if (event.key.code == Keyboard::A)
			{
				game->popState();
				return;
			}


			else	if (event.key.code == Keyboard::Escape) game->window.close();
			break;
		}
		default: break;
		}
	}

}

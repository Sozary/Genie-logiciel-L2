#include <iostream>
#include "Monster.h"

using namespace sf;
using namespace std;

Monstre::Monstre(string classe, int pvMax, int mana, int armure, int force, sf::Vector2i position, sf::Vector2f scale, DIRECTION orientation) : Entite(classe, pvMax, mana, armure, force),m_orientation(orientation)
, m_position(position){
	GameState::texture_manager->addElement("monsters_sprites", "data\\hgsshoennpokemonoverworld.png");
	m_sprite.setTexture(GameState::texture_manager->getElement("monsters_sprites"));

	textureUpdate();
	m_sprite.setPosition((Vector2f)position);
	m_sprite.setScale(scale);

}

Monstre::~Monstre()
{
}

Competence * Monstre::choisir_competence()
{
	return new Competence("Griffure", 15, 1, 5, 0);
}

sf::Vector2i Monstre::recupPos() const
{
	return m_position;
}

void Monstre::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_sprite);
}

void Monstre::textureUpdate()
{
	switch (m_orientation)
	{
	case UP:
		m_sprite.setTextureRect({ BASIC_M_P.x,BASIC_M_P.y,32,32 });
		break;
	case DOWN:
		m_sprite.setTextureRect({ BASIC_M_P.x,BASIC_M_P.y+64,32,32 });
		break;
	case LEFT:
		m_sprite.setTextureRect({ BASIC_M_P.x+32,BASIC_M_P.y,32,32 });
		break;
	case RIGHT:
		m_sprite.setTextureRect({ BASIC_M_P.x+32,BASIC_M_P.y+64,32,32 });
		break;

	}
}

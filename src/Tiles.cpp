#include "../include/Tiles.h"

Tiles::Tiles()
{
    m_index_texture = 0;
    m_intRect.height = SPRITE_SIZE;
    m_intRect.width = SPRITE_SIZE;
    m_intRect.top = 0;
    m_intRect.left = 0;
    m_solid = false;
}


void Tiles::set_index_texture(unsigned int index)
{
    m_index_texture = index;
}

void Tiles::set_intRect(unsigned int top, unsigned int left)
{
    m_intRect.top = top;
    m_intRect.left = left;
}

void Tiles::set_solidity(bool solidity)
{
    m_solid = solidity;
}

unsigned int Tiles::get_index_texture()
{
    return m_index_texture;
}

sf::IntRect Tiles::get_intRect()
{
    return m_intRect;
}

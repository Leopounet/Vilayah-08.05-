#include "../include/Map.h"

Map::Map()
{
    Tiles t;
    t.set_index_texture(1);
    t.set_intRect(34, 0);
    for(unsigned int tile = 0; tile < MAP_WIDTH * MAP_HEIGHT; tile++)
    {
        m_tiles_background.push_back(t);
        m_tiles_nbackground.push_back(t);
    }

    m_rect.setSize(sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE));
}

void Map::draw_background(sf::RenderWindow& window)
{
    unsigned int pos = 0;
    for(unsigned int y = 0; y < MAP_HEIGHT; y++)
    {
        for(unsigned int x = 0; x < MAP_WIDTH; x++)
        {
            pos = x + y * MAP_WIDTH;
            m_rect.setPosition(sf::Vector2f(x * SPRITE_SIZE, y * SPRITE_SIZE));
            m_rect.setTexture(m_textures.get_texture(m_tiles_background[pos].get_index_texture()));
            m_rect.setTextureRect(m_tiles_background[pos].get_intRect());
            window.draw(m_rect);
        }
    }
}

void Map::draw_nbackground(sf::RenderWindow& window)
{
    unsigned int pos = 0;
    for(unsigned int y = 0; y < MAP_HEIGHT; y++)
    {
        for(unsigned int x = 0; x < MAP_WIDTH; x++)
        {
            pos = x + y * MAP_WIDTH;
            m_rect.setPosition(sf::Vector2f(x * SPRITE_SIZE, y * SPRITE_SIZE));
            m_rect.setTexture(m_textures.get_texture(m_tiles_nbackground[pos].get_index_texture()));
            m_rect.setTextureRect(m_tiles_nbackground[pos].get_intRect());
            window.draw(m_rect);
        }
    }
}

void Map::set_tile(unsigned int pos_x, unsigned int pos_y, unsigned int left, unsigned int top, bool solid, unsigned int texture_index)
{
    unsigned int pos = pos_x + MAP_WIDTH * pos_y;
    if(m_textures.m_background[texture_index] == false)
    {
        m_tiles_nbackground[pos].set_intRect(top, left);
        m_tiles_nbackground[pos].set_index_texture(texture_index);
        m_tiles_nbackground[pos].set_solidity(solid);
    }
    else
    {
        m_tiles_background[pos].set_intRect(top, left);
        m_tiles_background[pos].set_index_texture(texture_index);
        m_tiles_background[pos].set_solidity(solid);
    }
}

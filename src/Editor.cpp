#include "../include/Editor.h"

Editor::Editor()
{
    m_index_current_texture = 0;
    m_intRect.height = SPRITE_SIZE;
    m_intRect.width = SPRITE_SIZE,
    m_intRect.left = 2;
    m_intRect.top = 2;
    m_rect.setTexture(m_textures.get_texture(m_index_current_texture));
    m_rect.setPosition(sf::Vector2f(0, 0));
    m_rect.setSize(sf::Vector2f(EDITOR_WIDTH, EDITOR_HEIGHT));
    m_solid = false;
}

void Editor::draw(sf::RenderWindow& window)
{
    window.draw(m_rect);
}

void Editor::set_tile(double x, double y)
{
    unsigned int pos_x = x / SPRITE_SIZE;
    unsigned int pos_y = y / SPRITE_SIZE;
    m_map->set_tile(pos_x, pos_y, m_intRect.left, m_intRect.top, m_solid, m_index_current_texture);
}

void Editor::change_texture(unsigned int new_index)
{
    m_index_current_texture = new_index;
    m_rect.setTexture(m_textures.get_texture(m_index_current_texture));
}

void Editor::change_current_map(Map * map)
{
    m_map = map;
}

void Editor::set_intRect(double x, double y)
{
    m_intRect.left = (int(x) - SCREEN_WIDTH) / (SPRITE_SIZE + SPACE_BETWEEN_SPRITES) * (SPRITE_SIZE + SPACE_BETWEEN_SPRITES) + SPACE_BETWEEN_SPRITES;
    m_intRect.top = int(y) / (SPRITE_SIZE + SPACE_BETWEEN_SPRITES) * (SPRITE_SIZE + SPACE_BETWEEN_SPRITES) + SPACE_BETWEEN_SPRITES;
}

void Editor::save_map()
{

}

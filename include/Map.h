#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "Tiles.h"
#include <vector>

/**
 * @brief Class to represent of a map. Maps are constituted of backgrounds tiles and not backgrounds tiles.
 **/
class Map
{
public:

    /**
     * @brief Constructor of a map. Not background tiles are set as transparent.
     **/
    Map();

    /**
     * @brief Draws the background of the map.
     * @param window : The window that shall be drawn on.
     **/
    void draw_background(sf::RenderWindow& window);

    /**
     * @brief Draws the not background of the map.
     * @param window : The window that shall be drawn on.
     **/
    void draw_nbackground(sf::RenderWindow& window);

    /**
     * @brief Sets a tile at a given position.
     * @param pos_x : The x position of the tile.
     * @param pos_y : The y position of the tile.
     * @param left : The left position of the intrect.
     * @param top : The top position of the intrect.
     * @param solid : The solidity of the tile.
     * @param texture_index : The index of the sprite sheet.
     **/
    void set_tile(unsigned int pos_x, unsigned int pos_y, unsigned int left, unsigned int top, bool solid, unsigned int texture_index);

    /**
     * @brief Returns a tile at a given position of the background tiles.
     * @param x : The x position of the tile.
     * @param y : The y position of the tile.
     **/
    Tiles get_tile_background(unsigned int x, unsigned int y);

    /**
     * @brief Returns a tile at a given position of the not background tiles.
     * @param x : The x position of the tile.
     * @param y : The y position of the tile.
     **/
    Tiles get_tile_nbackground(unsigned int x, unsigned int y);

private:
    std::vector<Tiles> m_tiles_background;  //List of background tiles
    std::vector<Tiles> m_tiles_nbackground; //List of not background tiles
    sf::RectangleShape m_rect;              //A rectangle to store sprites
    Textures m_textures;                    //List of textures
};

#endif // MAP_H_INCLUDED

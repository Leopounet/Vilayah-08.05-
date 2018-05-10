#ifndef TILES_H_INCLUDED
#define TILES_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Textures.h"

#define SPRITE_SIZE 32                                 //size of a sprite (width and height)
#define SCREEN_WIDTH 832                                //width of the playing part of the screen
#define SCREEN_HEIGHT 832                               //width of the playing part of the screen
#define MAP_WIDTH SCREEN_WIDTH / SPRITE_SIZE            //width of a map in sprites
#define MAP_HEIGHT SCREEN_HEIGHT / SPRITE_SIZE          //height of a map in sprites

/**
 * @brief A class to represent tiles. Tiles are defined as being solid or not.
 **/
class Tiles
{
public:

    /**
     * @brief Constructor of a tile. Set as not solid.
     **/
    Tiles();


    /**
     * @brief Sets the index of the texture.
     * @param index : The index of the texture.
     **/
    void set_index_texture(unsigned int index);

    /**
     * @brief Sets the intrect of the texture.
     * @param top : The top position of the intrect.
     * @param left : The left position of the intrect.
     **/
    void set_intRect(unsigned int top, unsigned int left);

    /**
     * @brief Sets the solidity of the tile.
     * @param solidity : True if the tile is solid.
     **/
    void set_solidity(bool solidity);

    /**
     * @brief Returns the index of the texture.
     **/
    unsigned int get_index_texture();

    /**
     * @brief Returns the intrect of the texture.
     **/
    sf::IntRect get_intRect();

private:

    unsigned int m_index_texture;   //Index of the texture
    sf::IntRect m_intRect;          //Rectangle on the sprite sheet
    bool m_solid;                   //True if the tile is solid

};

#endif // TILES_H_INCLUDED

#ifndef EDITOR_H_INCLUDED
#define EDITOR_H_INCLUDED

#include <iostream>
#include <vector>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <dos.h>
#include <windows.h>
#include "Textures.h"
#include <fstream>
#include "Map.h"

#include <SFML/Graphics.hpp>

#define PAGE_LINE 6                                     //Number of line on a page
#define SIZE_OF_NAME 200                                //Size max of a name of a texture
#define FONT_SIZE 25
#define FONT "data/fonts/Crimson-Roman.ttf"
#define FONT_COLOR_R 255
#define FONT_COLOR_G 255
#define FONT_COLOR_B 255

#define WIDTH 1308                                      //width of the total screen
#define HEIGHT 1000                                      //height of the total screen
#define EDITOR_WIDTH 476                                //width of the editor part of the screen
#define EDITOR_HEIGHT 850                               //height of the editor part of the screen
#define FILE_HANDLER_WIDTH 1308                         //width of the file handler
#define FILE_HANDLER_HEIGHT 150                         //height of the file handler
#define FPS 1000 / 60                                   //frames that are displayed per seconds
#define NB_SIDE 8                                       //number of side of a map
#define SPACE_BETWEEN_SPRITES 2                         //space between two sprites on the sprite sheet

/**
 * @brief A class to represent an editor.
 **/
class Editor
{
public:

    /**
     * @brief Constructor of an editor.
     **/
    Editor();

    /**
     * @brief Draws the editor.
     * @param window : The window to draw on.
     **/
    void draw(sf::RenderWindow& window);

    /**
     * @brief Sets a tile at a given position on the current map that is being modified.
     * @param x : The x coordinate of the mouse.
     * @param y : The y coordinate of the mouse.
     **/
    void set_tile(double x, double y);

    /**
     * @brief Changes the current map that is being modified.
     * @param map : A pointer to the new map.
     **/
    void change_current_map(Map * map);

    /**
     * @brief Changes the current sprite sheet.
     * @param new_index : The index of the new texture to use.
     **/
    void change_texture(unsigned int new_index);

    /**
     * @brief Sets the new position of the rectangle on the current sprite sheet.
     * @param x : The x position of the mouse.
     * @param y : The y position of the mouse.
     **/
    void set_intRect(double x, double y);

    /**
     * @brief Saves the current map.
     **/
    void save_map();

private:

    unsigned int m_index_current_texture;   //Current index of the texture that is being used
    sf::IntRect m_intRect;                  //The intrect to choose the current sprite on the sprite sheet
    Textures m_textures;                    //The list of textures
    Map * m_map;                            //A pointer to the map that is being modified
    sf::RectangleShape m_rect;              //A rectangle to store the sprite sheet
    bool m_solid;                           //True if the current sprite is solid

};

#endif // EDITOR_H_INCLUDED

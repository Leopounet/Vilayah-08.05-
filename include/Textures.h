#ifndef TEXTURES_H_INCLUDED
#define TEXTURES_H_INCLUDED

#include <vector>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

#define MAX_TEXTURE 100                                 //Maximum sprite sheet

/**
 * @brief A class to load textures and use them. It also stores in memory whether a sprite sheet is made of background tiles or not.
 **/
class Textures
{
public:

    /**
     * @brief Constructor of textures. Loads every textures.
     **/
    Textures();

    /**
     * @brief Returns the index of texture thanks to its name.
     * @param name : The name of the texture.
     * @return -1 if the texture does not exist.
     **/
    int get_index(std::string name);

    /**
     * @brief Returns a pointer to a texture at a given index.
     * @param index : The index of the pointer to the texture to return.
     * @return An null pointer if the index is not valid.
     **/
    sf::Texture * get_texture(unsigned int index);

    /**
     * @brief Adds a texture to the list.
     * @param name : The name that shall be used to find the texture.
     * @param p_texture : A pointer to the texture.
     * @param background : True if the texture is background (true by default).
     **/
    void add_texture(std::string name, sf::Texture * p_texture, bool background = true);

    std::vector<sf::Texture *> m_p_textures_list;   //The list of pointer to textures
    std::vector<std::string> m_texture_name;        //The list of name of textures
    std::vector<bool> m_background;                 //The list of whether the texture is a background or not
    unsigned int m_size;                            //Number of current texture

    //TEXTURES (give explicit names please)
    sf::Texture background_1;
    sf::Texture background_2;
    sf::Texture buildings1;
    sf::Texture buildings2;

};

#endif // TEXTURES_H_INCLUDED

#include "../include/Textures.h"

Textures::Textures()
{
    for(unsigned int texture = 0; texture < MAX_TEXTURE; texture++)
    {
        sf::Texture * text = nullptr;
        m_p_textures_list.push_back(text);
        m_texture_name.push_back("");
        m_background.push_back(false);
    }

    m_size = 1;

    //ADD YOUR TEXTURES HERE, PLEASE REMEMBER TO CREATE A VARIABLE TO STORE IT IN THE HEADER
    background_1.loadFromFile("data/images/backgrounds1.png");
    this->add_texture("backgrounds", &background_1, true);

    background_2.loadFromFile("data/images/backgrounds2.png");
    this->add_texture("backgrounds2", &background_2, true);

    buildings1.loadFromFile("data/images/buildings1.png");
    this->add_texture("buildings1", &buildings1, false);

    buildings2.loadFromFile("data/images/buildings2.png");
    this->add_texture("buildings1", &buildings2, false);
}

int Textures::get_index(std::string name)
{
    for(unsigned int texture = 0; texture < m_size; texture++)
    {
        if(m_texture_name[texture] == name)
        {
            return texture;
        }
    }
    return -1;
}

sf::Texture * Textures::get_texture(unsigned int index)
{
    if(index < m_size)
    {
        return m_p_textures_list[index];
    }
    return nullptr;
}

void Textures::add_texture(std::string name, sf::Texture * p_texture, bool background)
{
    m_p_textures_list[m_size] = p_texture;
    m_texture_name[m_size] = name;
    m_background[m_size] = background;
    m_size++;
}

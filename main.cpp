#include <iostream>
#include "include/Editor.h"
#include "include/Textures.h"
#include "include/Map.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML works!", sf::Style::Close);

    sf::View main_view(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
    sf::View misc_view(sf::FloatRect(0, 0, EDITOR_WIDTH, EDITOR_HEIGHT));
    sf::View file_view(sf::FloatRect(0, 0, FILE_HANDLER_WIDTH, FILE_HANDLER_HEIGHT));

    main_view.setViewport(sf::FloatRect(0,
                                        0,
                                        float(SCREEN_WIDTH) / WIDTH,
                                        float(SCREEN_HEIGHT) / HEIGHT));

    misc_view.setViewport(sf::FloatRect(float(SCREEN_WIDTH) / WIDTH,
                                        0,
                                        float(EDITOR_WIDTH) / WIDTH,
                                        float(EDITOR_HEIGHT) / HEIGHT));

    file_view.setViewport(sf::FloatRect(0,
                                        float(SCREEN_HEIGHT) / HEIGHT,
                                        float(FILE_HANDLER_WIDTH) / WIDTH,
                                        float(FILE_HANDLER_HEIGHT) /HEIGHT));

    Editor editor;
    Map map1;
    Map map2;

    editor.change_texture(1);
    editor.change_current_map(&map1);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            //Main view events
            window.setView(main_view);

            if(event.type == sf::Event::MouseButtonPressed)
            {
                if(event.mouseButton.button == sf::Mouse::Left)
                {

                }
            }

            //misc view event
            window.setView(misc_view);

            if(event.type == sf::Event::MouseButtonPressed)
            {
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    int x = event.mouseButton.x;
                    int y = event.mouseButton.y;
                    if(x < WIDTH && y >= 0 && x >= SCREEN_WIDTH && y < SCREEN_HEIGHT)
                    {
                        editor.set_intRect(x, y);
                    }
                }
            }

            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::A)
                {
                    editor.change_texture(3);
                }
            }

            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::C)
                {
                    editor.change_texture(4);
                }
            }

            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::B)
                {
                    editor.change_texture(1);
                }
            }

            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::D)
                {
                    editor.change_texture(2);
                }
            }

            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::E)
                {
                    editor.save_map();
                }
            }

            //file handling events
            window.setView(file_view);
        }

        window.clear();

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            int x = sf::Mouse::getPosition(window).x;
            int y = sf::Mouse::getPosition(window).y;
            if(x >= 0 && y >= 0 && x < SCREEN_WIDTH && y < SCREEN_HEIGHT)
            {
                editor.set_tile(x, y);
            }
        }

        //Draw the main view
        window.setView(main_view);

        map1.draw_background(window);
        map1.draw_nbackground(window);

        //Draw the misc view
        window.setView(misc_view);

        editor.draw(window);

        //Draw the file view
        window.setView(file_view);

        window.display();
    }

    return 0;
}

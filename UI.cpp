#include "UI.h"




void UI()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "LC", sf::Style::Titlebar | sf::Style::Close);

    Menu menu(window.getSize().x, window.getSize().y);

    while(window.isOpen())
    {
        int cur_w = menu.get_window();

        switch(cur_w)
        {
            case 0:
            {
                sf::Event event;
                while(window.pollEvent(event))
                {
                    switch(event.type)
                    {
                        case sf::Event::Closed:
                        {
                            window.close();
                            break;
                        }
                        case sf::Event::KeyPressed:
                        {
                            switch(event.key.code)
                            {
                               case sf::Keyboard::Up:
                               {
                                   menu.moveup();
                                   break;
                               }
                               case sf::Keyboard::Down:
                               {
                                   menu.movedown();
                                   break;
                               }




                            }
                            break;
                        }

                        case sf::Event::KeyReleased:
                        {
                            switch(event.key.code)
                            {
                                case sf::Keyboard::Enter:
                                {
                                    menu.enter(window);
                                    break;
                                }

                                case sf::Keyboard::Escape:
                                {
                                    window.close();
                                    break;
                                }

                            }
                            break;
                        }

                    }
                 }
                menu.draw(window);
                break;
            }

            case 3:
            {
                int line = menu.get_line();
                sf::Event event;
                while(window.pollEvent(event))
                {

                    switch(event.type)
                    {
                        case sf::Event::TextEntered:
                        {


                            switch(line)
                            {
                            case 0:
                                {

                                    menu.complete(event.text.unicode);

                                    break;
                                }
                            case 1:
                                {
                                    menu.complete2(event.text.unicode);
                                    break;
                                }
                            case 2:
                                {

                                    menu.complete3(event.text.unicode);
                                    break;
                                }
                            }
                            break;

                        }


                        case sf::Event::Closed:
                        {
                            window.close();
                            break;
                        }

                        case sf::Event::KeyReleased:
                        {
                            switch(event.key.code)
                            {

                               case sf::Keyboard::Enter:
                               {
                                    switch(line)
                                    {
                                    case 0:
                                        {
                                            menu.removec();
                                            menu.enter(window);
                                            break;
                                        }
                                    case 1:
                                        {
                                            menu.removec2();
                                            menu.enter(window);
                                            break;
                                        }
                                    case 2:
                                        {
                                            menu.removec3();
                                            menu.enter(window);
                                            break;
                                        }
                                    }
                                    break;
                               }

                               case sf::Keyboard::Backspace:
                                {
                                    switch(line)
                                    {
                                    case 0:
                                        {
                                            menu.removec();

                                            break;
                                        }
                                    case 1:
                                        {

                                            menu.removec2();
                                            break;
                                        }
                                    case 2:
                                        {

                                            menu.removec3();
                                            break;
                                        }
                                    }
                                    break;
                                }

                               case sf::Keyboard::Escape:
                                {

                                    window.close();
                                    break;
                                }
                            }
                            break;
                        }

                        case sf::Event::KeyPressed:
                        {

                             switch(event.key.code)
                             {


                               case sf::Keyboard::Backspace:
                                {
                                    switch(line)
                                    {
                                    case 0:
                                        {
                                            menu.removec();

                                            break;
                                        }
                                    case 1:
                                        {
                                            menu.removec2();

                                            break;
                                        }
                                    case 2:
                                        {
                                            menu.removec3();

                                            break;
                                        }
                                    }
                                    break;
                                }


                            }
                            break;
                        }

                        }


                    }
                menu.draw(window);
                break;
            }

            case 4:
            {
                    sf::Event event;
                    while(window.pollEvent(event))
                    {
                        switch(event.type)
                        {

                             case sf::Event::Closed:
                            {
                                window.close();
                                break;
                            }
                            case sf::Event::KeyReleased:
                            {
                                switch(event.key.code)
                                {
                                    case sf::Keyboard::Escape:
                                    {

                                        window.close();
                                        break;
                                    }

                                    default:
                                    {

                                        menu.enter(window);
                                        break;
                                    }
                                }

                            }

                        }
                    }
                    break;
            }
            default:
            {

                sf::Event event;
                while(window.pollEvent(event))
                {
                    switch(event.type)
                    {
                        case sf::Event::TextEntered:
                        {
                            menu.complete(event.text.unicode);
                            break;
                        }

                        case sf::Event::Closed:
                        {
                            window.close();
                            break;
                        }

                        case sf::Event::KeyReleased:
                        {
                            switch(event.key.code)
                            {

                               case sf::Keyboard::Enter:
                               {
                                   menu.removec();
                                   menu.enter(window);
                                   break;
                               }
                                case sf::Keyboard::Backspace:
                                {
                                    menu.removec();

                                    break;
                                }



                               case sf::Keyboard::Escape:
                                {
                                    menu.removec();
                                    window.close();
                                    break;
                                }
                            }
                            break;
                        }

                               case sf::Event::KeyPressed:
                                {
                                    switch(event.key.code)
                                    {
                                        case sf::Keyboard::Backspace:
                                        {
                                            menu.removec();

                                            break;
                                        }
                                    }
                                    break;
                                }
                    }
                }
                menu.draw(window);

                break;
            }

            }
    }


}



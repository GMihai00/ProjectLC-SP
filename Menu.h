#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include "Operations.h"
#include "Arbore.h"
#include "Fprop.h"
#include "FNN.h"
#include "FND.h"
#include "FNC.h"
using namespace std;

const int MAX_WINDOWS = 10;

class Menu{

protected:

    float width;
    float height;
    int cur_window;
    int cur_line;
    int last_line;
    sf::Font font;
    vector <sf::Text> txt[MAX_WINDOWS];

public:
    Menu(float w, float h);
    ~Menu();

    void draw(sf::RenderWindow &window);
    void moveup();
    void movedown();
    void moveotherscreen();
    void enter(sf::RenderWindow &window);
    void complete(char x);
    void removec();
    int get_window();

};

#endif // MENU_H_INCLUDED

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
#include "RichText.h"

using namespace std;

const int MAX_WINDOWS = 20;

class Menu{

protected:

    float width;
    float height;
    int cur_window; // 9 printwindow
    int cur_line;
    int last_line;
    sf::Font font;
    vector <sf::Text> txt[MAX_WINDOWS];
public:
    Menu(float w, float h);
    ~Menu();

    // afiseaza meniul
    void draw(sf::RenderWindow &window);
    // mutate la blocul de sus
    void moveup();
    // mutate la blocul de jos
    void movedown();
    // mutate pe alt tab
    void moveotherscreen();
    // ce se intampla cand apasam tasta entere
    void enter(sf::RenderWindow &window);
    // metode folosite pt adaugarea sau stergea unui caracter din bloc
    void complete(char x);
    void complete2(char x);
    void complete3(char x);
    void removec();
    void removec2();
    void removec3();
    // returneaza indicele ferestrei curente
    int get_window();
    // returneaza indicele liniei ferestre curente
    int get_line();
    // reseteaza aplicatia si se intoarce la fereastra principala
    void resetapp();
    // vizualizare transformare din structura stricta in structura relaxata WIP
    friend void transformare_structura_relaxata_in_structura_stricta(string c2, map <string,int> m, sfe::RichText,  sf::RenderWindow window);

};

#endif // MENU_H_INCLUDED

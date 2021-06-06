#include "Menu.h"

void transformare_structura_relaxata_in_structura_stricta(string c2, map <string,int> m, sf::RenderWindow &window)
{
    string dublicat;

    bool ok[c2.size()];

    sf::Font font;
    if(!font.loadFromFile("Semi-Coder-Regular.otf"))
    {
        //eroare
    }


    sfe::RichText visualtxt(font);

    visualtxt << c2;

    window.clear();
    window.draw(visualtxt);
    window.display();




    dublicat = c2;
    int cnt2 = 0;
    for(int j = 0; j < c2.size(); j++)
    {
        if( dublicat[j] == '!' ||  dublicat[j] == '|' ||  dublicat[j] == '&' ||  dublicat[j] == '>'  ||  dublicat[j] == '~')
        {
            /* marchez ca si nevizitati operatori logici */
            cnt2++;
            ok[cnt2] = false;
        }
    }


    for(int i = 1; i <= cnt2; i++)
    {
        int valmax = 0;
        int pozmax;
        int cntmax;
        int cnt = 0;

        for(int j = 0; j <  dublicat.size(); j++)
        {
            if( dublicat[j] == '!' ||  dublicat[j] == '|' ||  dublicat[j] == '&' ||  dublicat[j] == '>'  ||  dublicat[j] == '~')
            {
                /* iau cel mai la dreapta semn cu cea mai mare prioritate */
                cnt++;

                if(ok[cnt] == false)
                {
                    string cpy2;
                    cpy2.clear();
                    cpy2.push_back(dublicat[j]);

                    if(m[cpy2] >= valmax)
                    {
                        valmax = m[cpy2];
                        pozmax = j;
                        cntmax = cnt;

                    }
                }
            }
        }
            /* marchez operatorul ca si vizitat*/
            ok[cntmax] = true;



            /* pun paranteze daca nu sunt deja puse , la ! trebuie pus doar la literalul din dreapta, la restul de operatori si in stanga si in dreapta*/

            if(dublicat[pozmax] =='!')
            {

                if(pozmax + 1 >= dublicat.size() || !(pozmax - 1 < 0 || dublicat[pozmax - 1] == '(' ||  dublicat[pozmax - 1] == '!' ||  dublicat[pozmax - 1] == '|' ||  dublicat[pozmax - 1] == '&' ||  dublicat[pozmax - 1] == '>'  ||  dublicat[pozmax - 1] == '~'))
                {

                    int cnt = 0;
                            while(window.isOpen() && cnt == 0)
                            {sf::Event event;
                                while(window.pollEvent(event) && cnt == 0)
                                {

                                    switch(event.type)
                                    {
                                        case sf::Event::Closed:
                                        {
                                            cnt++;
                                            window.close();
                                            break;
                                        }

                                        case sf::Event::KeyReleased:
                                        {
                                           visualtxt.setCharacterColor(0, pozmax, sf::Color::Red);
                                            visualtxt << sf::Color::Red << "\nPropozitia nu este bine formata!";
                                            window.clear();
                                            window.draw(visualtxt);
                                            window.display();
                                            return;

                                            cnt++;
                                            break;
                                        }
                                    }
                                }
                            }

                }

                string cpy2;

                cpy2.clear();


                int cntp = 0;
                for(int p = pozmax + 1; p < dublicat.size(); p++)
                {
                    if(dublicat[p] == '(')
                        cntp++;
                    else
                    if(dublicat[p] == ')')
                        cntp--;

                    if(cntp == 0 && (p + 1 >= dublicat.size() || dublicat[p + 1] == '!' || dublicat[p + 1] == '&'|| dublicat[p + 1] == '|' || dublicat[p + 1] == '>' || dublicat[p + 1] == '~' || dublicat[p + 1] == ')'))
                    {

                        if(pozmax - 1 >= 0)
                        {
                            if(dublicat[pozmax - 1] == '(' && dublicat[p + 1] == ')')
                                p = dublicat.size() + 1;
                            else
                            {
                                int f = p;
                                for(int p = 0; p < pozmax; p++)
                                    cpy2.push_back(dublicat[p]);
                                cpy2.push_back('(');
                                cpy2.push_back(dublicat[pozmax]);
                                for(int p = pozmax + 1; p <= f; p++)
                                    cpy2.push_back(dublicat[p]);
                                cpy2.push_back(')');
                                for(int p = f + 1; p < dublicat.size(); p++)
                                    cpy2.push_back(dublicat[p]);
                                p = dublicat.size() + 1;
                                dublicat = cpy2;
                            }
                        }
                        else
                        {
                                int f = p;
                                for(int p = 0; p < pozmax; p++)
                                    cpy2.push_back(dublicat[p]);
                                cpy2.push_back('(');
                                cpy2.push_back(dublicat[pozmax]);
                                for(int p = pozmax + 1; p <= f; p++)
                                    cpy2.push_back(dublicat[p]);
                                cpy2.push_back(')');
                                for(int p = f + 1; p < dublicat.size(); p++)
                                    cpy2.push_back(dublicat[p]);
                                p = dublicat.size() + 1;
                                dublicat = cpy2;
                        }
                    }


                }

                if(cntp!=0)
                {
                    /*
                    ss << '\n' <<"Propozita nu este bine formata";
                    */
                    int cnt = 0;
                            while(window.isOpen() && cnt == 0)
                            {sf::Event event;
                                while(window.pollEvent(event) && cnt == 0)
                                {

                                    switch(event.type)
                                    {
                                        case sf::Event::Closed:
                                        {
                                            cnt++;
                                            window.close();
                                            break;
                                        }

                                        case sf::Event::KeyReleased:
                                        {
                                           visualtxt.setCharacterColor(0, pozmax, sf::Color::Red);
                                            visualtxt << sf::Color::Red << "\nPropozitia nu este bine formata!";
                                            window.clear();
                                            window.draw(visualtxt);
                                            window.display();
                                            return;

                                            cnt++;
                                            break;
                                        }
                                    }
                                }
                            }
                }

                            visualtxt.clear();
                            visualtxt << sf::Color::White << dublicat;

                            int cnt = 0;
                            while(window.isOpen() && cnt == 0)
                            {sf::Event event;
                                while(window.pollEvent(event) && cnt == 0)
                                {

                                    switch(event.type)
                                    {
                                        case sf::Event::Closed:
                                        {
                                            cnt++;
                                            window.close();
                                            break;
                                        }

                                        case sf::Event::KeyReleased:
                                        {
                                            window.clear();
                                            visualtxt.setCharacterColor(0, pozmax + 1, sf::Color::Green);
                                             window.draw(visualtxt);
                                            window.display();
                                            visualtxt.setCharacterColor(0, pozmax + 1, sf::Color::White);

                                            cnt++;
                                            break;
                                        }
                                    }
                                }
                            }

            }
            else
            {
                if(pozmax - 1 < 0 || pozmax + 1 >= dublicat.size())
                {
                       int cnt = 0;
                            while(window.isOpen() && cnt == 0)
                            {sf::Event event;
                                while(window.pollEvent(event) && cnt == 0)
                                {

                                    switch(event.type)
                                    {
                                        case sf::Event::Closed:
                                        {
                                            cnt++;
                                            window.close();
                                            break;
                                        }

                                        case sf::Event::KeyReleased:
                                        {
                                           visualtxt.setCharacterColor(0, pozmax, sf::Color::Red);
                                            visualtxt << sf::Color::Red << "\nPropozitia nu este bine formata!";
                                            window.clear();
                                            window.draw(visualtxt);
                                            window.display();
                                            return;

                                            cnt++;
                                            break;
                                        }
                                    }
                                }
                            }
                }
                string cpy2;

                cpy2.clear();


                int cntp  = 0;

                int pozst;
                for(int p = pozmax - 1; p >= 0; p--)
                {
                    if(dublicat[p] == '(')
                        cntp++;
                    else
                    if(dublicat[p] == ')')
                        cntp--;

                    if(cntp == 0 && (p - 1 < 0 || dublicat[p - 1] == '!' || dublicat[p - 1] == '&'|| dublicat[p - 1] == '|' || dublicat[p - 1] == '>' ||  dublicat[p - 1] == '~' || dublicat[p - 1] == '('))
                    {
                        pozst = p;
                        p = -1;
                    }
                }

                if(cntp!=0)
                {
                    /*
                    ss << '\n' <<"Propozita nu este bine formata";
                    ss << '\n' <<".Numarul de paranteze deschise nu este egal cu nr de paranteze inchise";
                    */

                    int cnt = 0;
                            while(window.isOpen() && cnt == 0)
                            {sf::Event event;
                                while(window.pollEvent(event) && cnt == 0)
                                {

                                    switch(event.type)
                                    {
                                        case sf::Event::Closed:
                                        {
                                            cnt++;
                                            window.close();
                                            break;
                                        }

                                        case sf::Event::KeyReleased:
                                        {
                                           visualtxt.setCharacterColor(0, pozmax, sf::Color::Red);
                                            visualtxt << sf::Color::Red << "\nPropozitia nu este bine formata!";
                                            window.clear();
                                            window.draw(visualtxt);
                                            window.display();
                                            return;

                                            cnt++;
                                            break;
                                        }
                                    }
                                }
                            }
                }

                int pozdr;
                cntp = 0;
                for(int p = pozmax + 1; p < dublicat.size(); p++)
                {
                    if(dublicat[p] == '(')
                        cntp++;
                    else
                    if(dublicat[p] == ')')
                        cntp--;

                    if(cntp == 0 && (p + 1 >= dublicat.size() || dublicat[p + 1] == '!' || dublicat[p + 1] == '&'|| dublicat[p + 1] == '|' || dublicat[p + 1] == '>' ||  dublicat[p + 1] == '~' || dublicat[p + 1] == ')'))
                    {
                        pozdr = p;
                        p = dublicat.size() + 1;

                    }


                }

                if(cntp!=0)
                {
                   /* ss << '\n' <<"Propozita nu este bine formata";
                    ss << '\n' <<".Numarul de paranteze deschise nu este egal cu nr de paranteze inchise";
                    */

                    int cnt = 0;
                            while(window.isOpen() && cnt == 0)
                            {sf::Event event;
                                while(window.pollEvent(event) && cnt == 0)
                                {

                                    switch(event.type)
                                    {
                                        case sf::Event::Closed:
                                        {
                                            cnt++;
                                            window.close();
                                            break;
                                        }

                                        case sf::Event::KeyReleased:
                                        {
                                           visualtxt.setCharacterColor(0, pozmax, sf::Color::Red);
                                            visualtxt << sf::Color::Red << "\nPropozitia nu este bine formata!";
                                            window.clear();
                                            window.draw(visualtxt);
                                            window.display();
                                            return;

                                            cnt++;
                                            break;
                                        }
                                    }
                                }
                            }

                }


                if(pozst - 1 >= 0 && pozdr + 1 < dublicat.size())
                {

                    if(dublicat[pozst - 1] == '(' && dublicat[pozdr + 1] == ')')
                        cntp = 0;
                    else
                    {
                        for(int p = 0; p <= pozst - 1; p++)
                            cpy2.push_back(dublicat[p]);
                        cpy2.push_back('(');
                        for(int p = pozst; p <= pozdr; p++)
                            cpy2.push_back(dublicat[p]);
                        cpy2.push_back(')');
                        for(int p = pozdr + 1; p < dublicat.size(); p++)
                            cpy2.push_back(dublicat[p]);
                            dublicat = cpy2;
                    }
                }
                else
                {

                    for(int p = 0; p <= pozst - 1; p++)
                            cpy2.push_back(dublicat[p]);
                        cpy2.push_back('(');
                        for(int p = pozst; p <= pozdr; p++)
                            cpy2.push_back(dublicat[p]);
                        cpy2.push_back(')');

                        for(int p = pozdr + 1; p < dublicat.size(); p++)
                            cpy2.push_back(dublicat[p]);
                            dublicat = cpy2;
                            visualtxt.clear();
                            visualtxt << sf::Color::White << dublicat;

                            int cnt = 0;
                            while(window.isOpen() && cnt == 0)
                            {sf::Event event;
                                while(window.pollEvent(event) && cnt == 0)
                                {

                                    switch(event.type)
                                    {
                                        case sf::Event::Closed:
                                        {
                                            cnt++;
                                            window.close();
                                            break;
                                        }

                                        case sf::Event::KeyReleased:
                                        {
                                            window.clear();
                                            visualtxt.setCharacterColor(0, pozmax + 1, sf::Color::Green);
                                             window.draw(visualtxt);
                                            window.display();
                                            visualtxt.setCharacterColor(0, pozmax + 1, sf::Color::White);

                                            cnt++;
                                            break;
                                        }
                                    }
                                }
                            }

                }




            }
        }


}


Menu::Menu(float w, float h)
{
    if(!font.loadFromFile("Semi-Coder-Regular.otf"))
    {
        //eroare
    }
    float sw = 13;

    width = w;
    height = h;

    sf::Text f;
    f.setFont(font);
    f.setString("Relaxat->Strict");
    f.setColor(sf::Color::Green);
    f.setPosition(sf::Vector2f(w / 2.3, h / (sw + 1)));


    txt[0].push_back(f);
    f.setFont(font);
    f.setString("Valoare adevar");
    f.setColor(sf::Color::White);
    f.setPosition(sf::Vector2f(w / 2.3, h / (sw + 1) * 2));
    txt[0].push_back(f);
    f.setFont(font);
    f.setString("Satisfiabilitate");
    f.setColor(sf::Color::White);
    f.setPosition(sf::Vector2f(w / 2.3, h / (sw + 1) * 3));
    txt[0].push_back(f);
    f.setFont(font);
    f.setString("Validitate");
    f.setColor(sf::Color::White);
     f.setPosition(sf::Vector2f(w / 2.3, h / (sw + 1) * 4));
    txt[0].push_back(f);
    f.setFont(font);
    f.setString("Echivalenta");
    f.setColor(sf::Color::White);
     f.setPosition(sf::Vector2f(w / 2.3, h / (sw + 1) * 5));
    txt[0].push_back(f);
    f.setFont(font);
    f.setString("Trans FNN");
    f.setColor(sf::Color::White);
     f.setPosition(sf::Vector2f(w / 2.3, h / (sw + 1) * 6));
    txt[0].push_back(f);
    f.setFont(font);
    f.setString("Trans FND");
    f.setPosition(sf::Vector2f(w / 2.3, h / (sw + 1) * 7));
    f.setColor(sf::Color::White);
    txt[0].push_back(f);
    f.setFont(font);
     f.setPosition(sf::Vector2f(w / 2.3, h / (sw + 1) * 8));
    f.setString("Trans FNC");
    f.setColor(sf::Color::White);
    txt[0].push_back(f);
    f.setFont(font);
     f.setPosition(sf::Vector2f(w / 2.3, h / (sw + 1) * 9));
    f.setString("Rezolutie");
    f.setColor(sf::Color::White);
    txt[0].push_back(f);
    f.setFont(font);
     f.setPosition(sf::Vector2f(w / 2.3, h / (sw + 1) * 10));
    f.setString("DP");
    f.setColor(sf::Color::White);
    txt[0].push_back(f);
    f.setFont(font);
    f.setPosition(sf::Vector2f(w / 2.3, h / (sw + 1) * 11));
    f.setString("DPLL");
    f.setColor(sf::Color::White);
    txt[0].push_back(f);
    f.setFont(font);
    f.setPosition(sf::Vector2f(w / 2.3, h / (sw + 1) * 12));
    f.setString("Iesire");
    f.setColor(sf::Color::White);

    txt[0].push_back(f);

    cur_window = 0;
    cur_line = 0;
    last_line = 0;
    f.setFont(font);
    f.setPosition(sf::Vector2f(w / 2.3, h / 2));
    f.setString("Introduceti formula prop.");
    f.setColor(sf::Color::White);
    txt[1].push_back(f);

    f.setFont(font);
    f.setPosition(sf::Vector2f(w / 2.3, h / 3 ));
    f.setString("Introduceti formula prop.");
    f.setColor(sf::Color::White);
    txt[2].push_back(f);

    f.setFont(font);
    f.setPosition(sf::Vector2f(w / 2.3, h / 3 * 2));
    f.setString("Introduceti formula prop.");
    f.setColor(sf::Color::White);
    txt[2].push_back(f);


    f.setFont(font);
    f.setPosition(sf::Vector2f(w / 2.3, h / 4 ));
    f.setString("Introduceti formula prop.");
    f.setColor(sf::Color::White);
    txt[3].push_back(f);

    f.setFont(font);
    f.setPosition(sf::Vector2f(w / 2.3, h / 4 * 2));
    f.setString("Literalul");
    f.setColor(sf::Color::White);
    txt[3].push_back(f);

    f.setFont(font);
    f.setPosition(sf::Vector2f(w / 2.3, h / 4 * 3));
    f.setString("Valoarea de adevar(A/F)");
    f.setColor(sf::Color::White);
    txt[3].push_back(f);

    f.setFont(font);
    f.setPosition(sf::Vector2f(0.0, 0.0));
    f.setColor(sf::Color::White);
    txt[4].push_back(f);

    // txt[5] pt verificare corectitudine si mai pot sa adaug vizualizari si la restul


}

Menu::~Menu()
{

}

void Menu::resetapp()
{
    float w = width;
    float h = height;
    int sw = 13;
    cur_window = 0;
    cur_line = 0;
    last_line = 0;
    txt[0][0].setString("Relaxat->Strict");
    txt[0][0].setColor(sf::Color::Green);
    txt[0][0].setPosition(sf::Vector2f(w / 2.3, h / (sw + 1)));
    txt[0][0].setCharacterSize(30);


    txt[0][1].setString("Valoare adevar");
    txt[0][1].setColor(sf::Color::White);
    txt[0][1].setPosition(sf::Vector2f(w / 2.3, h / (sw + 1) * 2));
    txt[0][1].setCharacterSize(30);

    txt[0][2].setString("Satisfiabilitate");
    txt[0][2].setColor(sf::Color::White);
    txt[0][2].setPosition(sf::Vector2f(w / 2.3, h / (sw + 1) * 3));
    txt[0][2].setCharacterSize(30);


    txt[0][3].setString("Validitate");
    txt[0][3].setColor(sf::Color::White);
    txt[0][3].setPosition(sf::Vector2f(w / 2.3, h / (sw + 1) * 4));
    txt[0][3].setCharacterSize(30);

    txt[0][4].setString("Echivalenta");
    txt[0][4].setColor(sf::Color::White);
    txt[0][4].setPosition(sf::Vector2f(w / 2.3, h / (sw + 1) * 5));
    txt[0][4].setCharacterSize(30);

    txt[0][5].setString("Trans FNN");
    txt[0][5].setColor(sf::Color::White);
    txt[0][5].setPosition(sf::Vector2f(w / 2.3, h / (sw + 1) * 6));
    txt[0][5].setCharacterSize(30);

    txt[0][6].setString("Trans FND");
    txt[0][6].setColor(sf::Color::White);
    txt[0][6].setPosition(sf::Vector2f(w / 2.3, h / (sw + 1) * 7));
    txt[0][6].setCharacterSize(30);

    txt[0][7].setString("Trans FNC");
    txt[0][7].setColor(sf::Color::White);
    txt[0][7].setPosition(sf::Vector2f(w / 2.3, h / (sw + 1) * 8));
    txt[0][7].setCharacterSize(30);

    txt[0][8].setString("Rezolutie");
    txt[0][8].setColor(sf::Color::White);
    txt[0][8].setPosition(sf::Vector2f(w / 2.3, h / (sw + 1) * 9));
    txt[0][8].setCharacterSize(30);

    txt[0][9].setString("DP");
    txt[0][9].setColor(sf::Color::White);
    txt[0][9].setPosition(sf::Vector2f(w / 2.3, h / (sw + 1) * 10));
    txt[0][9].setCharacterSize(30);

    txt[0][10].setString("DPLL");
    txt[0][10].setColor(sf::Color::White);
    txt[0][10].setPosition(sf::Vector2f(w / 2.3, h / (sw + 1) * 11));
    txt[0][10].setCharacterSize(30);

    txt[0][11].setString("Iesire");
    txt[0][11].setColor(sf::Color::White);
    txt[0][11].setPosition(sf::Vector2f(w / 2.3, h / (sw + 1) * 12));
    txt[0][11].setCharacterSize(30);

    txt[1][0].setPosition(sf::Vector2f(w / 2.3, h / 2));
    txt[1][0].setString("Introduceti formula prop.");
    txt[1][0].setColor(sf::Color::White);
    txt[1][0].setCharacterSize(30);

    txt[2][0].setPosition(sf::Vector2f(w / 2.3, h / 3 ));
    txt[2][0].setString("Introduceti formula prop.");
    txt[2][0].setColor(sf::Color::White);
    txt[2][0].setCharacterSize(30);

    txt[2][1].setPosition(sf::Vector2f(w / 2.3, h / 4 * 2));
    txt[2][1].setString("Introduceti formula prop.");;
    txt[2][1].setColor(sf::Color::White);
    txt[2][1].setCharacterSize(30);

    txt[3][0].setPosition(sf::Vector2f(w / 2.3, h / 4 ));
    txt[3][0].setString("Introduceti formula prop.");
    txt[3][0].setColor(sf::Color::White);
    txt[3][0].setCharacterSize(30);


    txt[3][1].setPosition(sf::Vector2f(w / 2.3, h / 4 * 2 ));
    txt[3][1].setString("Literalul");
    txt[3][1].setColor(sf::Color::White);
    txt[3][1].setCharacterSize(30);


    txt[3][2].setPosition(sf::Vector2f(w / 2.3, h / 4 * 3 ));
    txt[3][2].setString("Valoarea de adevar(A/F)");
    txt[3][2].setColor(sf::Color::White);
    txt[3][2].setCharacterSize(30);


    for(int i = 0; i < txt[4].size(); i++)
    {
        txt[4][i].setString("");
        txt[4][i].setCharacterSize(30);
    }




    for(int i =0 ; i <= 4; i++)
    {
        for(int j = 0; j < txt[i].size(); j++)
                txt[i][j].setScale(sf::Vector2f(1.0, 1.0));
    }



}
void Menu::draw(sf::RenderWindow &window)
{
    window.clear();

    for(int i = 0; i < txt[cur_window].size(); i++)
        window.draw(txt[cur_window][i]);

    window.display();
}

void Menu::moveup()
{
    if(cur_line - 1 >= 0)
    {
        txt[cur_window][cur_line].setColor(sf::Color::White);
        cur_line--;
        txt[cur_window][cur_line].setColor(sf::Color::Green);
        last_line = cur_line;
    }
}

void Menu::movedown()
{
    if(cur_line + 1 < txt[cur_window].size())
    {
        txt[cur_window][cur_line].setColor(sf::Color::White);
        cur_line++;
        txt[cur_window][cur_line].setColor(sf::Color::Green);
        last_line = cur_line;
    }
}

void Menu::enter(sf::RenderWindow &window)
{

    ofstream out("txt.out");
    switch(cur_window)
    {

    case 0:
        {
            switch(cur_line)
            {

                case 1:
                {
                    cur_window = 3;
                    last_line = cur_line;
                    cur_line  = 0;
                    txt[cur_window][cur_line].setColor(sf::Color::Green);
                    break;
                }
                case 4:
                {
                    cur_window = 2;
                    last_line = cur_line;
                    cur_line = 0;
                    txt[cur_window][cur_line].setColor(sf::Color::Green);
                    break;
                }

                case 11:
                {
                    window.close();
                    break;
                }
                default :
                {
                    cur_window = 1;
                    last_line = cur_line;
                    cur_line = 0;
                    txt[cur_window][cur_line].setColor(sf::Color::Green);
                    break;

                }
            }

            break;
        }

    case 4:
    {
           this->resetapp();
           this->draw(window);

           break;
    }
    default:
    {
        txt[cur_window][cur_line].setColor(sf::Color::White);
        if(cur_line < txt[cur_window].size())
            cur_line++;
        if(cur_line < txt[cur_window].size())
        txt[cur_window][cur_line].setColor(sf::Color::Green);


        if(cur_line == txt[cur_window].size() || cur_window == 3 && cur_line == 1)
        {
            ostringstream ss;
            Fprop* ex;
            switch(last_line)
            {
                case 0:
                {
                    ex = new Fprop;


                    string s = txt[cur_window][0].getString();
                    cur_window = 4;
                    map <string, int> m ={{"!", 5}, {"&", 4}, {"|", 3}, {">", 2}, {"~", 1}};
                    transformare_structura_relaxata_in_structura_stricta(s, m, window);

                     int cnt = 0;
                            while(window.isOpen() && cnt == 0)
                            {sf::Event event;
                                while(window.pollEvent(event) && cnt == 0)
                                {

                                    switch(event.type)
                                    {
                                        case sf::Event::Closed:
                                        {
                                            cnt++;
                                            window.close();
                                            break;
                                        }

                                        case sf::Event::KeyReleased:
                                        {
                                               ex->setformula(s, ss);
                                            ex->update_arbore();
                                            txt[cur_window][0].setString(ex->getformula());

                                            ex->getarbore()->Afisare(ss);
                                            ss <<'\n';
                                            ss <<"Forma in sintaxa stricta :" << ex->getformula()<<'\n';



                                            txt[cur_window][0].setString(ss.str());
                                            txt[cur_window][0].setPosition(sf::Vector2f(0., 0.));
                                            txt[cur_window][0].setStyle(sf::Text::Style::Regular);



                                            string s2 = ss.str();
                                            if(s2.size() > 1000)
                                                txt[cur_window][0].setScale(sf::Vector2f(0.5, 0.5));
                                                if(ss.str().size() > 10000)
                                                            txt[cur_window][0].setScale(sf::Vector2f(0.1, 0.1));

                                            this->draw(window);

                                            cnt++;
                                            break;
                                        }
                                    }
                                }
                            }


                    break;



                }
                case 1:
                {
                    ex = new Fprop;

                    string s = txt[cur_window][0].getString();
                     map <string, int> m ={{"!", 5}, {"&", 4}, {"|", 3}, {">", 2}, {"~", 1}};
                    transformare_structura_relaxata_in_structura_stricta(s, m, window);


                     int cnt = 0;
                            while(window.isOpen() && cnt == 0)
                            {sf::Event event;
                                while(window.pollEvent(event) && cnt == 0)
                                {

                                    switch(event.type)
                                    {
                                        case sf::Event::Closed:
                                        {
                                            cnt++;
                                            window.close();
                                            break;
                                        }

                                        case sf::Event::KeyReleased:
                                        {
                                            ex->setformula(s, ss);
                                            ex->update_arbore();
                                            ex->update_literali();
                                            txt[cur_window][0].setString(ex->getformula());
                                            this->draw(window);
                                            int size_literali = ex->get_size_literali();

                                            string s1;
                                            map <string, int> m;
                                            set <string> sl;



                                            bool ok = true;
                                            while(ok)
                                            {
                                                int line = cur_line;
                                                txt[cur_window][cur_line].setColor(sf::Color::Green);
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
                                                                    this->complete(event.text.unicode);
                                                                    break;
                                                                }
                                                            case 1:
                                                                {
                                                                    this->complete2(event.text.unicode);
                                                                    break;
                                                                }
                                                            case 2:
                                                                {
                                                                    this->complete3(event.text.unicode);
                                                                    break;
                                                                }
                                                            }
                                                            break;

                                                        }

                                                        case sf::Event::Closed:
                                                        {
                                                            ok = false;
                                                            break;
                                                        }

                                                        case sf::Event::KeyReleased:
                                                        {
                                                            switch(event.key.code)
                                                            {

                                                               case sf::Keyboard::Enter:
                                                               {
                                                                   string s1;
                                                                    switch(line)
                                                                    {
                                                                    case 0:
                                                                        {
                                                                            this->removec();
                                                                            this->enter(window);
                                                                            break;
                                                                        }
                                                                    case 1:
                                                                        {
                                                                            this->removec2();
                                                                            s1 = txt[cur_window][cur_line].getString();

                                                                            if(ex->verif_is_in_set(s1) == false)
                                                                            {
                                                                                txt[cur_window][cur_line].setString("Eroare.Literalul respectiv nu exista in formula");

                                                                            }
                                                                            else
                                                                            if(sl.find(s1) != sl.end())
                                                                            {
                                                                                 txt[cur_window][cur_line].setString("Eroare.Literalul respectiv are deja o interpretare");
                                                                            }
                                                                            else
                                                                            {

                                                                                 txt[cur_window][cur_line].setColor(sf::Color::White);
                                                                                cur_line++;
                                                                            }



                                                                            break;
                                                                        }
                                                                    case 2:
                                                                        {
                                                                            this->removec3();
                                                                            s1 = txt[cur_window][cur_line].getString();
                                                                            if(!(s1 == "A" || s1 == "F"))
                                                                                txt[cur_window][cur_line].setString("Eroare.Introduceti o valoare de adevar valida");
                                                                            else
                                                                            {
                                                                                txt[cur_window][cur_line].setColor(sf::Color::White);
                                                                                cur_line--;
                                                                                s1 = txt[cur_window][cur_line].getString();
                                                                                string val;
                                                                                val = txt[cur_window][cur_line + 1].getString();
                                                                                if(val == "A")
                                                                                {
                                                                                    m[s1] = 1;
                                                                                    sl.insert(s1);
                                                                                }
                                                                                else
                                                                                if(val == "F")
                                                                                {
                                                                                    m[s1] = 0;
                                                                                    sl.insert(s1);
                                                                                }


                                                                                 if(sl.size() == size_literali)
                                                                                        ok = false;
                                                                                txt[cur_window][1].setString("Literalul");
                                                                                txt[cur_window][2].setString("Valoarea de adevar(A/F)");
                                                                            }

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
                                                                            this->removec();
                                                                            this->removec();
                                                                            break;
                                                                        }
                                                                    case 1:
                                                                        {
                                                                            this->removec2();
                                                                            this->removec2();
                                                                            break;
                                                                        }
                                                                    case 2:
                                                                        {
                                                                            this->removec3();
                                                                            this->removec3();
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
                                                    }
                                                }
                                                this->draw(window);


                                            }


                                            ss <<"Valoarea de adevar sub interpretarea data a expresiei  este:";

                                            int a = ex->det_arb_val_interpretare(m);
                                            if(a == 1)
                                                ss <<"A";
                                            else
                                                ss <<"F";

                                            ss <<'\n';


                                            cur_window = 4;
                                            txt[cur_window][0].setString(ss.str());
                                            txt[cur_window][0].setPosition(sf::Vector2f(0.,0.));

                                            this->draw(window);
                                            cur_window = 4;

                                            cnt++;
                                            break;
                                        }
                                    }
                                }
                            }


                    break;
                }
                case 2:
                {
                    ex = new Fprop;

                    string s = txt[cur_window][0].getString();
                      map <string, int> m ={{"!", 5}, {"&", 4}, {"|", 3}, {">", 2}, {"~", 1}};
                    transformare_structura_relaxata_in_structura_stricta(s, m, window);

                            int cnt = 0;
                            while(window.isOpen() && cnt == 0)
                            {sf::Event event;
                                while(window.pollEvent(event) && cnt == 0)
                                {

                                    switch(event.type)
                                    {
                                        case sf::Event::Closed:
                                        {
                                            cnt++;
                                            window.close();
                                            break;
                                        }

                                        case sf::Event::KeyReleased:
                                        {
                                              ex->setformula(s, ss);
                                            ex->update_arbore();
                                            ex->update_literali();
                                            ex->update_satisfiabilitate();

                                            int y = ex->getsatisfiabilitate();
                                            txt[cur_window][0].setString(ex->getformula());
                                            this->draw(window);

                                            if(y == 1)
                                                ss <<"Formula este satisfiabila\n";
                                            else
                                                ss <<"Formula nu este satisfiabila\n";



                                            txt[cur_window][0].setString(ss.str());
                                            txt[cur_window][0].setPosition(sf::Vector2f(0.,0.));
                                            this->draw(window);
                                            cur_window= 4;
                                            cnt++;
                                            break;
                                        }
                                    }
                                }
                            }

                    break;
                }
                case 3:
                {
                    ex = new Fprop;

                    string s = txt[cur_window][0].getString();
                      map <string, int> m ={{"!", 5}, {"&", 4}, {"|", 3}, {">", 2}, {"~", 1}};
                    transformare_structura_relaxata_in_structura_stricta(s, m, window);


                      int cnt = 0;
                            while(window.isOpen() && cnt == 0)
                            {sf::Event event;
                                while(window.pollEvent(event) && cnt == 0)
                                {

                                    switch(event.type)
                                    {
                                        case sf::Event::Closed:
                                        {
                                            cnt++;
                                            window.close();
                                            break;
                                        }

                                        case sf::Event::KeyReleased:
                                        {
                                                ex->setformula(s, ss);
                                                ex->update_arbore();
                                                ex->update_literali();
                                                ex->update_validitate();

                                                int y = ex->getvaliditate();
                                                txt[cur_window][0].setString(ex->getformula());
                                                this->draw(window);

                                                if(y == 1)
                                                    ss <<"Formula este valida\n";
                                                else
                                                    ss <<"Formula nu este valida\n";

                                                cur_window = 4;
                                                txt[cur_window][0].setString(ss.str());
                                                txt[cur_window][0].setPosition(sf::Vector2f(0.,0.));

                                                this->draw(window);

                                            cnt++;
                                            break;
                                        }
                                    }
                                }
                            }



                    break;
                }
                case 4:
                {
                    ex = new Fprop;

                    string s = txt[cur_window][0].getString();
                      map <string, int> m ={{"!", 5}, {"&", 4}, {"|", 3}, {">", 2}, {"~", 1}};
                    transformare_structura_relaxata_in_structura_stricta(s, m, window);

                      int cnt = 0;
                            while(window.isOpen() && cnt == 0)
                            {sf::Event event;
                                while(window.pollEvent(event) && cnt == 0)
                                {

                                    switch(event.type)
                                    {
                                        case sf::Event::Closed:
                                        {
                                            cnt++;
                                            window.close();
                                            break;
                                        }

                                        case sf::Event::KeyReleased:
                                        {
                                            ex->setformula(s, ss);
                                            ex->update_arbore();
                                            ex->update_literali();
                                            txt[cur_window][0].setString(ex->getformula());
                                            this->draw(window);

                                            Fprop* ex2 = new Fprop;

                                            string s2 = txt[cur_window][1].getString();
                                             transformare_structura_relaxata_in_structura_stricta(s2, m, window);
                                            int cnt2 = 0;
                                            while(window.isOpen() && cnt2 == 0)
                                            {sf::Event event;
                                                while(window.pollEvent(event) && cnt2 == 0)
                                                {

                                                    switch(event.type)
                                                    {
                                                        case sf::Event::Closed:
                                                        {
                                                            cnt++;
                                                            window.close();
                                                            break;
                                                        }

                                                        case sf::Event::KeyReleased:
                                                        {
                                                              ex2->setformula(s2, ss);
                                                            ex2->update_arbore();
                                                            ex2->update_literali();
                                                            txt[cur_window][1].setString(ex2->getformula());

                                                            this->draw(window);


                                                            if(echivalent(*ex, *ex2))
                                                                ss <<"Formulele sunt echivalente\n";
                                                            else
                                                                ss <<"Formulele nu sunt echivalente\n";


                                                            cur_window = 4;
                                                            txt[cur_window][0].setString(ss.str());


                                                            txt[cur_window][0].setPosition(sf::Vector2f(0.,0.));

                                                            this->draw(window);
                                                            cnt2++;

                                                            break;
                                                        }
                                                    }
                                                }
                                            }
                                          cnt++;
                                            break;
                                        }
                                    }
                                }
                            }



                    break;
                }
                case 5:
                {
                    ex = new FNN;
                    string s = txt[cur_window][0].getString();
                      map <string, int> m ={{"!", 5}, {"&", 4}, {"|", 3}, {">", 2}, {"~", 1}};
                    transformare_structura_relaxata_in_structura_stricta(s, m, window);

                      int cnt = 0;

                      ex->setformula(s, ss);



                    ex->transformareFNN(ss);

                    string reguli = ss.str();
                    int cnt2 = 0;
                    int cnt3 = 0;
                    sfe::RichText rtvisual(font);
                    rtvisual.setCharacterSize(25);
                    rtvisual << sf::Color::White;
                    rtvisual << " ";

                            while(window.isOpen() && cnt == 0)
                            {sf::Event event;
                                while(window.pollEvent(event) && cnt == 0)
                                {

                                    switch(event.type)
                                    {
                                        case sf::Event::Closed:
                                        {
                                            cnt++;
                                            window.close();
                                            break;
                                        }

                                        case sf::Event::KeyReleased:
                                        {


                                             if(cnt2 < reguli.size())
                                             {



                                                        rtvisual.clear();



                                                        while(cnt2 < reguli.size() && reguli[cnt2] != '\n')
                                                        {
                                                            if(cnt2 - 1 < reguli.size() && (reguli[cnt2 - 1] == '|'   || reguli[cnt2 - 1] == '!' || reguli[cnt2 - 1] == '~' || reguli[cnt2 - 1] == '>'))
                                                                rtvisual <<" ";

                                                            rtvisual << reguli[cnt2];
                                                            if(cnt2 + 1 < reguli.size() && (reguli[cnt2 + 1] == '|'    || reguli[cnt2 + 1] == '~' || reguli[cnt2 + 1] == '>'))
                                                                rtvisual <<" ";



                                                            cnt2++;
                                                        }
                                                        while(cnt2 < reguli.size() && reguli[cnt2] == '\n')
                                                            cnt2++;

                                                        window.clear();
                                                        window.draw(rtvisual);
                                                        window.display();




                                             }
                                             else
                                            if(cnt3 == 0)
                                            {
                                                cnt3++;
                                                ex->update_arbore();
                                                        txt[cur_window][0].setString(ex->getformula());
                                                        this->draw(window);
                                                        ex->getarbore()->Afisare(ss);
                                                        ss <<'\n';
                                                        ss <<"Forma FNN a formulei este :" << ex->getformula()<<'\n';

                                                        cur_window = 4;
                                                        txt[cur_window][0].setString(ss.str());
                                                        txt[cur_window][0].setPosition(sf::Vector2f(0.,0.));
                                                         int f = string(txt[cur_window][0].getString()).size();
                                                        f = 1ll * this->width * this->height / 100 /  f;

                                                         if(ss.str().size() > 1000)
                                                            txt[cur_window][0].setScale(sf::Vector2f(0.5, 0.5));
                                                            if(ss.str().size() > 10000)
                                                            txt[cur_window][0].setScale(sf::Vector2f(0.1, 0.1));

                                                        this->draw(window);
                                            }
                                            else
                                                cnt++;
                                            break;
                                        }
                                    }
                                }
                                    }






                            break;
                }
                case 6:
                {
                    ex = new FND;
                   string s = txt[cur_window][0].getString();
                     map <string, int> m ={{"!", 5}, {"&", 4}, {"|", 3}, {">", 2}, {"~", 1}};
                    transformare_structura_relaxata_in_structura_stricta(s, m, window);

                            int cnt = 0;

                      ex->setformula(s, ss);



                    ex->transformare_in_FND(ss);

                    string reguli = ss.str();
                    int cnt2 = 0;
                    int cnt3 = 0;
                    sfe::RichText rtvisual(font);
                    rtvisual.setCharacterSize(25);
                    rtvisual << sf::Color::White;
                    rtvisual << " ";

                            while(window.isOpen() && cnt == 0)
                            {sf::Event event;
                                while(window.pollEvent(event) && cnt == 0)
                                {

                                    switch(event.type)
                                    {
                                        case sf::Event::Closed:
                                        {
                                            cnt++;
                                            window.close();
                                            break;
                                        }

                                        case sf::Event::KeyReleased:
                                        {


                                             if(cnt2 < reguli.size())
                                             {



                                                        rtvisual.clear();



                                                        while(cnt2 < reguli.size() && reguli[cnt2] != '\n')
                                                        {
                                                            if(cnt2 - 1 < reguli.size() && (reguli[cnt2 - 1] == '|'   || reguli[cnt2 - 1] == '!' || reguli[cnt2 - 1] == '~' || reguli[cnt2 - 1] == '>'))
                                                                rtvisual <<" ";

                                                            rtvisual << reguli[cnt2];
                                                            if(cnt2 + 1 < reguli.size() && (reguli[cnt2 + 1] == '|'    || reguli[cnt2 + 1] == '~' || reguli[cnt2 + 1] == '>'))
                                                                rtvisual <<" ";



                                                            cnt2++;
                                                        }
                                                        while(cnt2 < reguli.size() && reguli[cnt2] == '\n')
                                                            cnt2++;

                                                        window.clear();
                                                        window.draw(rtvisual);
                                                        window.display();




                                             }
                                             else
                                            if(cnt3 == 0)
                                            {
                                                cnt3++;
                                                ex->update_arbore();
                                                        txt[cur_window][0].setString(ex->getformula());
                                                        this->draw(window);
                                                        ex->getarbore()->Afisare(ss);
                                                        ss <<'\n';
                                                        ss <<"Forma FND a formulei este :" << ex->getformula()<<'\n';

                                                        cur_window = 4;
                                                        txt[cur_window][0].setString(ss.str());
                                                        txt[cur_window][0].setPosition(sf::Vector2f(0.,0.));
                                                         int f = string(txt[cur_window][0].getString()).size();
                                                        f = 1ll * this->width * this->height / 100 /  f;

                                                        if(ss.str().size() > 1000)
                                                            txt[cur_window][0].setScale(sf::Vector2f(0.5, 0.5));
                                                        this->draw(window);
                                                        if(ss.str().size() > 10000)
                                                            txt[cur_window][0].setScale(sf::Vector2f(0.1, 0.1));
                                            }
                                            else
                                                cnt++;
                                            break;
                                        }
                                    }
                                }
                                    }


                    break;
                }
                case 7:
                {
                    ex = new FNC;
                    string s = txt[cur_window][0].getString();
                      map <string, int> m ={{"!", 5}, {"&", 4}, {"|", 3}, {">", 2}, {"~", 1}};
                    transformare_structura_relaxata_in_structura_stricta(s, m, window);


                                                 int cnt = 0;

                      ex->setformula(s, ss);



                    ex->transformare_in_FNC(ss);

                    string reguli = ss.str();
                    int cnt2 = 0;
                    int cnt3 = 0;
                    sfe::RichText rtvisual(font);
                    rtvisual.setCharacterSize(25);
                    rtvisual << sf::Color::White;
                    rtvisual << " ";

                            while(window.isOpen() && cnt == 0)
                            {sf::Event event;
                                while(window.pollEvent(event) && cnt == 0)
                                {

                                    switch(event.type)
                                    {
                                        case sf::Event::Closed:
                                        {
                                            cnt++;
                                            window.close();
                                            break;
                                        }

                                        case sf::Event::KeyReleased:
                                        {


                                             if(cnt2 < reguli.size())
                                             {



                                                        rtvisual.clear();



                                                        while(cnt2 < reguli.size() && reguli[cnt2] != '\n')
                                                        {
                                                            if(cnt2 - 1 < reguli.size() && (reguli[cnt2 - 1] == '|'   || reguli[cnt2 - 1] == '!' || reguli[cnt2 - 1] == '~' || reguli[cnt2 - 1] == '>'))
                                                                rtvisual <<" ";

                                                            rtvisual << reguli[cnt2];
                                                            if(cnt2 + 1 < reguli.size() && (reguli[cnt2 + 1] == '|'    || reguli[cnt2 + 1] == '~' || reguli[cnt2 + 1] == '>'))
                                                                rtvisual <<" ";



                                                            cnt2++;
                                                        }
                                                        while(cnt2 < reguli.size() && reguli[cnt2] == '\n')
                                                            cnt2++;

                                                        window.clear();
                                                        window.draw(rtvisual);
                                                        window.display();




                                             }
                                             else
                                            if(cnt3 == 0)
                                            {
                                                cnt3++;
                                                ex->update_arbore();
                                                        txt[cur_window][0].setString(ex->getformula());
                                                        this->draw(window);
                                                        ex->getarbore()->Afisare(ss);
                                                        ss <<'\n';
                                                        ss <<"Forma FNC a formulei este :" << ex->getformula()<<'\n';

                                                        cur_window = 4;
                                                        txt[cur_window][0].setString(ss.str());
                                                        txt[cur_window][0].setPosition(sf::Vector2f(0.,0.));
                                                         int f = string(txt[cur_window][0].getString()).size();
                                                        f = 1ll * this->width * this->height / 100 /  f;
                                                        if(ss.str().size() > 1000)
                                                            txt[cur_window][0].setScale(sf::Vector2f(0.5, 0.5));
                                                        if(ss.str().size() > 10000)
                                                            txt[cur_window][0].setScale(sf::Vector2f(0.1, 0.1));
                                                        this->draw(window);
                                            }
                                            else
                                                cnt++;
                                            break;
                                        }
                                    }
                                }
                                    }


                    break;
                }
                case 8:
                {
                    ex = new FNC;

                    string s = txt[cur_window][0].getString();
                      map <string, int> m ={{"!", 5}, {"&", 4}, {"|", 3}, {">", 2}, {"~", 1}};
                    transformare_structura_relaxata_in_structura_stricta(s, m, window);

                      int cnt = 0;

                                    ex->setformula(s, ss);
                                ex->transformare_in_FNC(ss);
                                ex->update_arbore();
                                txt[cur_window][0].setString(ex->getformula());


                                ex->update_literali();
                                ex->update_clauze();
                                ex->rezolutie(ss);

                    string reguli = ss.str();
                    int cnt2 = 0;
                    int cnt3 = 0;
                    sfe::RichText rtvisual(font);
                    rtvisual.setCharacterSize(25);
                    rtvisual << sf::Color::White;
                    rtvisual << " ";

                            while(window.isOpen() && cnt == 0)
                            {sf::Event event;
                                while(window.pollEvent(event) && cnt == 0)
                                {

                                    switch(event.type)
                                    {
                                        case sf::Event::Closed:
                                        {
                                            cnt++;
                                            window.close();
                                            break;
                                        }

                                        case sf::Event::KeyReleased:
                                        {


                                             if(cnt2 < reguli.size())
                                             {



                                                        rtvisual.clear();



                                                        while(cnt2 < reguli.size() && reguli[cnt2] != '\n')
                                                        {
                                                            if(cnt2 - 1 < reguli.size() && (reguli[cnt2 - 1] == '|'   || reguli[cnt2 - 1] == '!' || reguli[cnt2 - 1] == '~' || reguli[cnt2 - 1] == '>'))
                                                                rtvisual <<" ";

                                                            rtvisual << reguli[cnt2];
                                                            if(cnt2 + 1 < reguli.size() && (reguli[cnt2 + 1] == '|'    || reguli[cnt2 + 1] == '~' || reguli[cnt2 + 1] == '>'))
                                                                rtvisual <<" ";



                                                            cnt2++;
                                                        }
                                                        while(cnt2 < reguli.size() && reguli[cnt2] == '\n')
                                                            cnt2++;

                                                        window.clear();
                                                        window.draw(rtvisual);
                                                        window.display();




                                             }
                                             else
                                            if(cnt3 == 0)
                                            {

                                            cur_window  = 4;
                                            txt[cur_window][0].setPosition(sf::Vector2f(0., 0.));
                                            txt[cur_window][0].setString(ss.str());
                                             int f = string(txt[cur_window][0].getString()).size();
                                            f = 1ll * this->width * this->height / 100 /  f;

                                            if(ss.str().size() > 1000)
                                                txt[cur_window][0].setScale(sf::Vector2f(0.5, 0.5));
                                                if(ss.str().size() > 10000)
                                                            txt[cur_window][0].setScale(sf::Vector2f(0.1, 0.1));
                                            this->draw(window);
                                            cnt3++;

                                            }
                                            else
                                                cnt++;
                                            break;
                                        }
                                    }
                                }
                                    }





                    break;
                }
                case 9:
                {
                    ex = new FNC;

                    string s = txt[cur_window][0].getString();
                      map <string, int> m ={{"!", 5}, {"&", 4}, {"|", 3}, {">", 2}, {"~", 1}};
                    transformare_structura_relaxata_in_structura_stricta(s, m, window);

                      int cnt = 0;

                                    ex->setformula(s, ss);
                                ex->transformare_in_FNC(ss);
                                ex->update_arbore();
                                txt[cur_window][0].setString(ex->getformula());


                                ex->update_literali();
                                ex->update_clauze();
                                ex->DP(ss);

                    string reguli = ss.str();
                    int cnt2 = 0;
                    int cnt3 = 0;
                    sfe::RichText rtvisual(font);
                    rtvisual.setCharacterSize(25);
                    rtvisual << sf::Color::White;
                    rtvisual << " ";

                            while(window.isOpen() && cnt == 0)
                            {sf::Event event;
                                while(window.pollEvent(event) && cnt == 0)
                                {

                                    switch(event.type)
                                    {
                                        case sf::Event::Closed:
                                        {
                                            cnt++;
                                            window.close();
                                            break;
                                        }

                                        case sf::Event::KeyReleased:
                                        {


                                             if(cnt2 < reguli.size())
                                             {



                                                        rtvisual.clear();



                                                        while(cnt2 < reguli.size() && reguli[cnt2] != '\n')
                                                        {
                                                            if(cnt2 - 1 < reguli.size() && (reguli[cnt2 - 1] == '|'   || reguli[cnt2 - 1] == '!' || reguli[cnt2 - 1] == '~' || reguli[cnt2 - 1] == '>'))
                                                                rtvisual <<" ";

                                                            rtvisual << reguli[cnt2];
                                                            if(cnt2 + 1 < reguli.size() && (reguli[cnt2 + 1] == '|'    || reguli[cnt2 + 1] == '~' || reguli[cnt2 + 1] == '>'))
                                                                rtvisual <<" ";



                                                            cnt2++;
                                                        }
                                                        while(cnt2 < reguli.size() && reguli[cnt2] == '\n')
                                                            cnt2++;

                                                        window.clear();
                                                        window.draw(rtvisual);
                                                        window.display();




                                             }
                                             else
                                            if(cnt3 == 0)
                                            {

                                            cur_window  = 4;
                                            txt[cur_window][0].setPosition(sf::Vector2f(0., 0.));
                                            txt[cur_window][0].setString(ss.str());
                                             int f = string(txt[cur_window][0].getString()).size();
                                            f = 1ll * this->width * this->height / 100 /  f;

                                            if(ss.str().size() > 1000)
                                                txt[cur_window][0].setScale(sf::Vector2f(0.5, 0.5));
                                                if(ss.str().size() > 10000)
                                                            txt[cur_window][0].setScale(sf::Vector2f(0.1, 0.1));
                                            this->draw(window);
                                            cnt3++;

                                            }
                                            else
                                                cnt++;
                                            break;
                                        }
                                    }
                                }
                                    }



                    break;
                }
                case 10:
                {
                    ex = new FNC;

                    string s = txt[cur_window][0].getString();
                      map <string, int> m ={{"!", 5}, {"&", 4}, {"|", 3}, {">", 2}, {"~", 1}};
                    transformare_structura_relaxata_in_structura_stricta(s, m, window);

                      int cnt = 0;

                                    ex->setformula(s, ss);
                                ex->transformare_in_FNC(ss);
                                ex->update_arbore();
                                txt[cur_window][0].setString(ex->getformula());


                                ex->update_literali();
                                ex->update_clauze();
                                ex->DPLL(ss);

                    string reguli = ss.str();
                    int cnt2 = 0;
                    int cnt3 = 0;
                    sfe::RichText rtvisual(font);
                    rtvisual.setCharacterSize(25);
                    rtvisual << sf::Color::White;
                    rtvisual << " ";

                            while(window.isOpen() && cnt == 0)
                            {sf::Event event;
                                while(window.pollEvent(event) && cnt == 0)
                                {

                                    switch(event.type)
                                    {
                                        case sf::Event::Closed:
                                        {
                                            cnt++;
                                            window.close();
                                            break;
                                        }

                                        case sf::Event::KeyReleased:
                                        {


                                             if(cnt2 < reguli.size())
                                             {



                                                        rtvisual.clear();



                                                        while(cnt2 < reguli.size() && reguli[cnt2] != '\n')
                                                        {
                                                            if(cnt2 - 1 < reguli.size() && (reguli[cnt2 - 1] == '|'   || reguli[cnt2 - 1] == '!' || reguli[cnt2 - 1] == '~' || reguli[cnt2 - 1] == '>'))
                                                                rtvisual <<" ";

                                                            rtvisual << reguli[cnt2];
                                                            if(cnt2 + 1 < reguli.size() && (reguli[cnt2 + 1] == '|'    || reguli[cnt2 + 1] == '~' || reguli[cnt2 + 1] == '>'))
                                                                rtvisual <<" ";



                                                            cnt2++;
                                                        }
                                                        while(cnt2 < reguli.size() && reguli[cnt2] == '\n')
                                                            cnt2++;

                                                        window.clear();
                                                        window.draw(rtvisual);
                                                        window.display();




                                             }
                                             else
                                            if(cnt3 == 0)
                                            {

                                            cur_window  = 4;
                                            txt[cur_window][0].setPosition(sf::Vector2f(0., 0.));
                                            txt[cur_window][0].setString(ss.str());
                                             int f = string(txt[cur_window][0].getString()).size();
                                            f = 1ll * this->width * this->height / 100 /  f;

                                            if(ss.str().size() > 1000)
                                                txt[cur_window][0].setScale(sf::Vector2f(0.5, 0.5));
                                                if(ss.str().size() > 10000)
                                                            txt[cur_window][0].setScale(sf::Vector2f(0.1, 0.1));
                                            this->draw(window);
                                            cnt3++;

                                            }
                                            else
                                                cnt++;
                                            break;
                                        }
                                    }
                                }
                                    }



                    break;
                }
                delete ex;
            }

            out << ss.str() <<"\n\n";
        }

    }

    }
}

void Menu::complete(char x)
{
    if(cur_line < txt[cur_window].size())
    {
        string a = txt[cur_window][cur_line].getString();
        if(a == "Introduceti formula prop.")
            a.clear();
        a.push_back(x);
        txt[cur_window][cur_line].setString(a);
    }

}

void Menu::complete2(char x)
{
      if(cur_line < txt[cur_window].size())
    {
        string a = txt[cur_window][cur_line].getString();
        if(a == "Literalul")
            a.clear();
        if(a == "Eroare.Literalul respectiv nu exista in formula")
            a.clear();

        if(a == "Eroare.Literalul respectiv are deja o interpretare")
            a.clear();
        a.push_back(x);
        txt[cur_window][cur_line].setString(a);
    }
}

void Menu::complete3(char x)
{
      if(cur_line < txt[cur_window].size())
    {
        string a = txt[cur_window][cur_line].getString();
        if(a == "Valoarea de adevar(A/F)")
            a.clear();
        if(a == "Eroare.Introduceti o valoare de adevar valida")
            a.clear();
        a.push_back(x);
        txt[cur_window][cur_line].setString(a);
    }
}


void Menu::removec()
{
    if(cur_line < txt[cur_window].size())
    {
        string a = txt[cur_window][cur_line].getString();

        if(a == "Introduceti formula prop.")
            a.clear();
        if(a.size() != 0)
            a.pop_back();

        if(a.size() == 0)
            a = "Introduceti formula prop.";
        txt[cur_window][cur_line].setString(a);

    }
}

void Menu::removec2()
{
    if(cur_line < txt[cur_window].size())
    {
        string a = txt[cur_window][cur_line].getString();

        if(a == "Literalul")
            a.clear();

        if(a == "Eroare.Literalul respectiv nu exista in formula")
            a.clear();

        if(a == "Eroare.Literalul respectiv are deja o interpretare")
            a.clear();

        if(a.size() != 0)
            a.pop_back();

        if(a.size() == 0)
            a = "Literalul";
        txt[cur_window][cur_line].setString(a);

    }
}

void Menu::removec3()
{
    if(cur_line < txt[cur_window].size())
    {
        string a = txt[cur_window][cur_line].getString();

        if(a == "Valoarea de adevar(A/F)")
            a.clear();
        if(a.size() != 0)
            a.pop_back();

        if(a == "Eroare.Introduceti o valoare de adevar valida")
            a.clear();
        if(a.size() == 0)
            a = "Valoarea de adevar(A/F)";
        txt[cur_window][cur_line].setString(a);

    }
}


int Menu::get_window()
{
    return this->cur_window;
}

int Menu::get_line()
{
    return this->cur_line;
}


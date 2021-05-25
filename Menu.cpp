#include "Menu.h"


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
    f.setPosition(sf::Vector2f(w / 2.3, h / (sw + 1) * 13));
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




}

Menu::~Menu()
{

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

    switch(cur_window)
    {

    case 0:
        {
            switch(cur_line)
            {

                case 1:
                {
                    cur_window = 3;
                    cur_line  = 0;
                    txt[cur_window][cur_line].setColor(sf::Color::Green);
                    break;
                }
                case 4:
                {
                    cur_window = 2;
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
                    cur_line = 0;
                    txt[cur_window][cur_line].setColor(sf::Color::Green);
                    break;

                }
            }

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
                    ex->setformula(s);
                    ex->update_arbore();
                    txt[cur_window][0].setString(ex->getformula());

                    ex->getarbore()->Afisare(ss);
                    ss <<'\n';
                    ss <<"Forma in sintaxa stricta :" << ex->getformula()<<'\n';

                    txt[cur_window][0].setString(ss.str());
                    txt[cur_window][0].setPosition(sf::Vector2f(0., 0.));
                    txt[cur_window][0].setStyle(sf::Text::Style::Regular);
                    txt[cur_window][0].setLetterSpacing(0.5);
                    txt[cur_window][0].setLineSpacing(0.5);
                    this->draw(window);
                    break;



                }
                case 1:
                {
                    ex = new Fprop;

                    string s = txt[cur_window][0].getString();

                    ex->setformula(s);
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

                    cout << ss.str();

                    txt[cur_window][1].setString("");
                    txt[cur_window][2].setString("");
                    txt[cur_window][0].setString(ss.str());
                    txt[cur_window][0].setPosition(sf::Vector2f(0.,0.));


                    this->draw(window);


                    break;
                }
                case 2:
                {
                    ex = new Fprop;

                    string s = txt[cur_window][0].getString();
                    ex->setformula(s);
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
                    break;
                }
                case 3:
                {
                    ex = new Fprop;

                    string s = txt[cur_window][0].getString();
                    ex->setformula(s);
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

                    txt[cur_window][0].setString(ss.str());
                    txt[cur_window][0].setPosition(sf::Vector2f(0.,0.));
                    this->draw(window);
                    break;
                }
                case 4:
                {
                    ex = new Fprop;

                    string s = txt[cur_window][0].getString();
                    ex->setformula(s);
                    ex->update_arbore();
                    ex->update_literali();
                    txt[cur_window][0].setString(ex->getformula());
                    this->draw(window);

                    Fprop* ex2 = new Fprop;

                    string s2 = txt[cur_window][1].getString();

                    ex2->setformula(s2);
                    ex2->update_arbore();
                    ex2->update_literali();
                    txt[cur_window][1].setString(ex2->getformula());
                    this->draw(window);


                    if(echivalent(*ex, *ex2))
                        ss <<"Formulele sunt echivalente\n";
                    else
                        ss <<"Formulele nu sunt echivalente\n";


                    txt[cur_window][0].setString(ss.str());
                    txt[cur_window][1].setString("");
                    txt[cur_window][0].setPosition(sf::Vector2f(0.,0.));

                    this->draw(window);
                    break;
                }
                case 5:
                {
                    ex = new FNN;
                    string s = txt[cur_window][0].getString();
                    ex->setformula(s);
                    ex->transformareFNN();
                    ex->update_arbore();
                    txt[cur_window][0].setString(ex->getformula());
                    this->draw(window);
                    ex->getarbore()->Afisare(ss);
                    ss <<'\n';
                    ss <<"Forma FNN a formulei este :" << ex->getformula()<<'\n';

                    txt[cur_window][0].setString(ss.str());
                    txt[cur_window][0].setPosition(sf::Vector2f(0.,0.));
                    this->draw(window);

                    break;
                }
                case 6:
                {
                    ex = new FND;
                   string s = txt[cur_window][0].getString();
                    ex->setformula(s);
                    ex->transformare_in_FND();
                    ex->update_arbore();
                    txt[cur_window][0].setString(ex->getformula());
                    this->draw(window);
                    ex->getarbore()->Afisare(ss);
                    ss <<'\n';
                    ss <<"Forma FND a formulei este :" << ex->getformula()<<'\n';

                    txt[cur_window][0].setString(ss.str());
                    txt[cur_window][0].setPosition(sf::Vector2f(0.,0.));
                    this->draw(window);
                    break;
                }
                case 7:
                {
                    ex = new FNC;
                    string s = txt[cur_window][0].getString();
                    ex->setformula(s);
                    ex->transformare_in_FNC();
                    ex->update_arbore();
                    txt[cur_window][0].setString(ex->getformula());
                    this->draw(window);
                    ex->getarbore()->Afisare(ss);
                    ss <<'\n';
                    ss <<"Forma FNC a formulei este :" << ex->getformula()<<'\n';

                    txt[cur_window][0].setString(ss.str());
                    txt[cur_window][0].setPosition(sf::Vector2f(0.,0.));
                    this->draw(window);
                    break;
                }
                case 8:
                {
                    ex = new FNC;

                    string s = txt[cur_window][0].getString();
                    ex->setformula(s);
                    ex->transformare_in_FNC();
                    ex->update_arbore();
                    txt[cur_window][0].setString(ex->getformula());
                    this->draw(window);
                    ex->update_literali();
                    ex->update_clauze();
                    ex->rezolutie();
                    break;
                }
                case 9:
                {
                    ex = new FNC;

                    string s = txt[cur_window][0].getString();
                    ex->setformula(s);
                    ex->transformare_in_FNC();
                    ex->update_arbore();
                    txt[cur_window][0].setString(ex->getformula());
                    this->draw(window);
                    ex->update_literali();
                    ex->update_clauze();
                    ex->DP();
                    break;
                }
                case 10:
                {
                    ex = new FNC;

                    string s = txt[cur_window][0].getString();
                    ex->setformula(s);
                    ex->transformare_in_FNC();
                    ex->update_arbore();
                    txt[cur_window][0].setString(ex->getformula());
                    this->draw(window);
                    ex->update_literali();
                    ex->update_clauze();
                    ex->DPLL();

                    break;
                }
                delete ex;
            }

         while(window.isOpen())
         {
             sf::Event event;
             while(window.pollEvent(event))
                switch(event.type)
                {
                    case sf::Event::KeyPressed:
                    {
                        window.close();
                        break;
                    }
                    case sf::Event::Closed:
                    {
                            window.close();
                            break;
                    }
                }
         }

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


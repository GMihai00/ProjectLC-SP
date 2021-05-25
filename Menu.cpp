#include "Menu.h"


Menu::Menu(float w, float h)
{
    if(!font.loadFromFile("arial.ttf"))
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
    f.setString("Trans. FNN");
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
    f.setPosition(sf::Vector2f(w / 2.3, h / 3 * 2));
    f.setString("Introduceti multimea de clauze cu formatul literal->valoare de adevar(0/1) separate printr- un spatiu");
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

                case 4:
                {
                    cur_window = 2;
                    cur_line = 0;
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
                    break;

                }
            }

            break;
        }

    default:
    {
       if(cur_line < txt[cur_window].size())
            cur_line++;

       if(cur_line == txt[cur_window].size())
       {
            Fprop* ex;
            switch(last_line)
            {
                case 0:
                {
                    ex = new Fprop;

                    string s = txt[cur_window][0].getString();
                    ex->setformula(s);
                    ex->update_arbore();
                    ex->getarbore()->Afisare(cout);
                    cout <<'\n';
                    cout <<"Forma in sintaxa stricta :" << ex->getformula()<<'\n';
                    break;


                }
                case 1:
                {
                    ex = new Fprop;

                    string s = txt[cur_window][0].getString();;

                    ex->setformula(s);
                    ex->update_arbore();
                    ex->update_literali();

                    int size_literali = ex->get_size_literali();
                    cout <<"Introduceti valorile de adevar ale literalilor.Valorile de adevar trebuie introduse sub formatul nume_literal valoare_adevar(A/F).\n";

                    string s1;
                    map <string, int> m;
                    set <string> sl;

                    window.close();
                    while(cin >> s1)
                    {

                        if(ex->verif_is_in_set(s1) == false)
                        {
                            cout << s1;
                            string val;
                            cin >> val;
                            cout <<"Eroare.Literalul respectiv nu exista in formula\n";
                             fflush(stdin);

                        }
                        else
                        {
                            string val;
                            cin >> val;

                            if(sl.find(s1) == sl.end())
                            {
                                if(val == "A")
                                {
                                    m[s1] = 1;
                                    sl.insert(s);
                                }
                                else
                                if(val == "F")
                                {
                                    m[s1] = 0;
                                    sl.insert(s1);
                                }
                                else
                                {
                                    cout <<"Eroare!Ati introdus o valoare de adevar inexistenta\n";
                                }

                            }
                            else
                                cout <<"Eroare!Ati introdus deja valoarea de adevar a acestui literal\n";


                            fflush(stdin);
                             if(sl.size() == size_literali)
                                break;
                        }

                    }

                    cout <<"Valoarea de adevar sub interpretarea data a expresiei  este:";

                    int a = ex->det_arb_val_interpretare(m);
                    if(a == 1)
                        cout <<"A";
                    else
                        cout <<"F";

                    cout <<'\n';




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

                    if(y == 1)
                        cout <<"Formula este satisfiabila\n";
                    else
                        cout <<"Formula nu este satisfiabila\n";
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

                    if(y == 1)
                        cout <<"Formula este valida\n";
                    else
                        cout <<"Formula nu este valida\n";
                    break;
                }
                case 4:
                {
                    ex = new Fprop;

                    string s = txt[cur_window][0].getString();
                    ex->setformula(s);
                    ex->update_arbore();
                    ex->update_literali();

                    Fprop* ex2 = new Fprop;

                    string s2 = txt[cur_window][1].getString();

                    ex2->setformula(s2);
                    ex2->update_arbore();
                    ex2->update_literali();


                    if(echivalent(*ex, *ex2))
                        cout <<"Formulele sunt echivalente\n";
                    else
                        cout <<"Formulele nu sunt echivalente\n";


                    break;
                }
                case 5:
                {
                    ex = new FNN;
                    string s = txt[cur_window][0].getString();
                    ex->setformula(s);
                    ex->transformareFNN();
                    ex->update_arbore();
                    ex->getarbore()->Afisare(cout);
                    cout <<'\n';
                    cout <<"Forma FNN a formulei este :" << ex->getformula()<<'\n';


                    break;
                }
                case 6:
                {
                    ex = new FND;
                   string s = txt[cur_window][0].getString();
                    ex->setformula(s);
                    ex->transformare_in_FND();
                    ex->update_arbore();
                    ex->getarbore()->Afisare(cout);
                    cout <<'\n';
                    cout <<"Forma FND a formulei este :" << ex->getformula()<<'\n';

                    break;
                }
                case 7:
                {
                    ex = new FNC;
                    string s = txt[cur_window][0].getString();
                    ex->setformula(s);
                    ex->transformare_in_FNC();
                    ex->update_arbore();
                    ex->getarbore()->Afisare(cout);
                    cout <<'\n';
                    cout <<"Forma FNC a formulei este :" << ex->getformula()<<'\n';
                    break;
                }
                case 8:
                {
                    ex = new FNC;

                    string s = txt[cur_window][0].getString();
                    ex->setformula(s);
                    ex->transformare_in_FNC();
                    ex->update_arbore();
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
                    ex->update_literali();
                    ex->update_clauze();
                    ex->DPLL();

                    break;
                }
                delete ex;
            }
         window.close();
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

int Menu::get_window()
{
    return this->cur_window;
}


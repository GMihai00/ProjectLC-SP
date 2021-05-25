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
                        case sf::Event::KeyReleased:
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
                    }
                }
                menu.draw(window);
                break;

            }

            }
    }
    /*
    cout  <<"Pentru trasnformarea unei propozitii din sintaxa relaxata in sintaxa stricta si afisarea arborelui corespunzator apasati tasta 1"<<endl;
    cout  <<"Pentru verificarea valori sub interpretare a unei propozitii apasati tasta 2"<<endl;
    cout  <<"Pentru verificarea satisfiabilitati unei propozitii apasati tasta 3"<<endl;
    cout  <<"Pentru verificarea validitati unei propozitii apasati tasta 4"<<endl;
    cout  <<"Pentru verificare daca doua propozitii sunt echivalente apasati tasta 5"<<endl;
    cout  <<"Pentru transformarea unei formule in FNN apasati tasta 6"<<endl;
    cout  <<"Pentru transformarea unei formule in FND apasati tasta 7"<<endl;
    cout  <<"Pentru transformarea unei formule in FNC apasati tasta 8"<<endl;
    cout  <<"Pentru aplicarea rezolutiei propozitionale apasati tasta 9"<<endl;
    cout  <<"Pentru aplicarea DP  apasati tasta 10"<<endl;
    cout  <<"Pentru aplicarea DPLL  apasati tasta 11"<<endl;
    cout <<'\n';



    Fprop* ex;
    int x;
    do
    {

        cin >> x;

        switch(x)
        {
            case 1:
            {
                ex = new Fprop;

                string s;
                cout <<"Introduceti formula :";
                fflush(stdin);
                getline(cin, s);
                ex->setformula(s);
                ex->update_arbore();
                ex->getarbore()->Afisare(cout);
                cout <<'\n';
                cout <<"Forma in sintaxa stricta :" << ex->getformula()<<'\n';
                break;


            }
            case 2:
            {
                ex = new Fprop;

                string s;
                cout <<"Introduceti formula :";
                 fflush(stdin);
                getline(cin, s);
                ex->setformula(s);
                ex->update_arbore();
                ex->update_literali();

                int size_literali = ex->get_size_literali();
                cout <<"Introduceti valorile de adevar ale literalilor.Valorile de adevar trebuie introduse sub formatul nume_literal valoare_adevar(A/F).\n";

                string s1;
                map <string, int> m;
                set <string> sl;

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
            case 3:
            {
                ex = new Fprop;

                string s;
                cout <<"Introduceti formula :";
                 fflush(stdin);
                getline(cin, s);
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
            case 4:
            {
                ex = new Fprop;

                string s;
                cout <<"Introduceti formula :";
                 fflush(stdin);
                getline(cin, s);
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
            case 5:
            {
                ex = new Fprop;

                string s;
                cout <<"Introduceti prima formula :";
                fflush(stdin);
                getline(cin, s);
                ex->setformula(s);
                ex->update_arbore();
                ex->update_literali();

                Fprop* ex2 = new Fprop;

                string s2;
                cout <<"Introduceti a doua formula :";
                fflush(stdin);
                getline(cin, s2);

                ex2->setformula(s2);
                ex2->update_arbore();
                ex2->update_literali();


                if(echivalent(*ex, *ex2))
                    cout <<"Formulele sunt echivalente\n";
                else
                    cout <<"Formulele nu sunt echivalente\n";


                break;
            }
            case 6:
            {
                ex = new FNN;
                string s;
                cout <<"Introduceti prima formula :";
                 fflush(stdin);
                getline(cin, s);
                ex->setformula(s);
                ex->transformareFNN();
                ex->update_arbore();
                ex->getarbore()->Afisare(cout);
                cout <<'\n';
                cout <<"Forma FNN a formulei este :" << ex->getformula()<<'\n';


                break;
            }
            case 7:
            {
                ex = new FND;
                string s;
                cout <<"Introduceti prima formula :";
               fflush(stdin);
                getline(cin, s);
                ex->setformula(s);
                ex->transformare_in_FND();
                ex->update_arbore();
                ex->getarbore()->Afisare(cout);
                cout <<'\n';
                cout <<"Forma FND a formulei este :" << ex->getformula()<<'\n';

                break;
            }
            case 8:
            {
                ex = new FNC;
                string s;
                cout <<"Introduceti prima formula :";
                fflush(stdin);
                getline(cin, s);
                ex->setformula(s);
                ex->transformare_in_FNC();
                ex->update_arbore();
                ex->getarbore()->Afisare(cout);
                cout <<'\n';
                cout <<"Forma FNC a formulei este :" << ex->getformula()<<'\n';
                break;
            }
            case 9:
            {
                ex = new FNC;

                string s;
                cout <<"Introduceti prima formula :";
               fflush(stdin);
                getline(cin, s);
                ex->setformula(s);
                ex->transformare_in_FNC();
                ex->update_arbore();
                ex->update_literali();
                ex->update_clauze();
                ex->rezolutie();
                break;
            }
            case 10:
            {
                ex = new FNC;

                string s;
                cout <<"Introduceti prima formula :";
                 fflush(stdin);
                getline(cin, s);
                ex->setformula(s);
                ex->transformare_in_FNC();
                ex->update_arbore();
                ex->update_literali();
                ex->update_clauze();
                ex->DP();
                break;
            }
            case 11:
            {
                ex = new FNC;

                string s;
                cout <<"Introduceti prima formula :";
                fflush(stdin);
                getline(cin, s);
                ex->setformula(s);
                ex->transformare_in_FNC();
                ex->update_arbore();
                ex->update_literali();
                ex->update_clauze();
                ex->DPLL();

                break;
            }
            default:
            {
                cout <<"Ati incercat sa utilizati o comanda inexistenta, va rog sa reintroduceti numarul unei comenzi existente" <<'\n';
                break;
            }
        }

    }while(x <= 0 || x >= 12);

    */

}



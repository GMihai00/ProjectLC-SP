#include "FNC.h"


FNC::FNC(set <set <string> > x, string s, Arbore* a):FNN(s, a)
{
    this->clauze = x;
}

void FNC::transformare_in_FNC()
{
    this->transformareFNN();
    string forma_intermediara = this->formula;
    forma_intermediara = distributivitate1(forma_intermediara);
    this->formula = forma_intermediara;
}

void FNC::update_clauze()
{
    set < set <string> > set1;
    set <string> set2;
    string s = this->formula;

    for(int i = 0;i < s.size(); i++)
    {

        if(s[i] == '&')
        {
            if(set2.size() == 1 && *set2.begin() == "t")
            {
                set < set <string> > set3;
                set3.insert(set2);
                this->clauze = set3;
                return;

            }
            if(set2.size()!= 0)
            set1.insert(set2);
            set2.clear();
        }
        else
        if(s[i] != '(' && s[i] != ')' && s[i] != '|' )
        {
            string s2;
            s2.push_back(s[i]);

            i++;
            while(i < s.size() && s[i] !=')' && s[i] != '|' && s[i] != '&')
            {
                s2.push_back(s[i]);
                i++;
            }
            i--;

            set2.insert(s2);
            string l_c;

            if(s2[0] == '!')
                for(int j = 1; j < s2.size(); j++)
                    l_c.push_back(s2[j]);
            else
                l_c = "!" + s2;

                if(set2.find(l_c) != set2.end())
                    set2.clear();

        }

    }

    if(set2.size() != 0)
        set1.insert(set2);

    if(set2.size() == 1 && *set2.begin() == "t")
        {
                set < set <string> > set3;
                set3.insert(set2);
                this->clauze = set3;
                return;

        }

    this->clauze = set1;

}
void FNC::rezolutie()
{
    set < set <string> > set_clauze =  this->clauze;
    cout << '\n' << "Am determinat setul de clauze corespunzator FNC:"<<'\n';

    cout <<"{";
    set < set <string> >:: iterator it = set_clauze.begin();
    while(it!=set_clauze.end())
    {
        set <string> p = *it;
        cout <<"{";
        set <string> ::iterator it2 = p.begin();
        while(it2 != p.end())
        {
            cout << *it2;
            it2++;
            if(it2 != p.end())
                cout <<",";
        }
        cout <<"}";
        it++;
        if(it != set_clauze.end())
        cout <<",";
    }
    cout <<"}";
    cout <<'\n';

    if(*((*set_clauze.begin()).begin()) == "t")
    {
        cout << '\n' <<"Propozitia este nesatisfiabila";
        this->satisfiabilitate = 0;
        return;
    }
    if(set_clauze.size() == 0)
    {
        cout << '\n' <<"Propozitia este nesatisfiabila";
        this->satisfiabilitate = 0;
        return;

    }
    combina_clauzele(set_clauze);
    if(set_clauze.find({"eroare"}) != set_clauze.end())
    {
        cout << '\n' <<"Propozitia este nesatisfiabila";
        this->satisfiabilitate = 0;
        return;
    }
    cout <<'\n'<< "Dupa ce au fost incercate toate combinatiile posibile de clauze nu s-a obtinut clauza vida"<<'\n';
    cout <<'\n'<< "Setul de clauze final este:";
    cout <<"{";
    it = set_clauze.begin();
    while(it!=set_clauze.end())
    {
        set <string> p = *it;
        cout <<"{";
        set <string> ::iterator it2 = p.begin();
        while(it2 != p.end())
        {
            cout << *it2;
            it2++;
            if(it2 != p.end())
                cout <<",";
        }
        cout <<"}";
        it++;
        if(it != set_clauze.end())
        cout <<",";
    }
    cout <<"}";
    cout <<'\n';
    cout << '\n' <<"Propozitia este satisfiabila";
    this->satisfiabilitate = 1;
}

void FNC::DP()
{


    set <string> set_literali_cu_negatie =  get_literali_cu_negatie(this->formula);
    set < set <string> > set_clauze =  this->clauze;
    cout << '\n' << "Am determinat setul de clauze corespunzator FNC:"<<'\n';


    cout <<"{";
    set < set <string> >:: iterator it = set_clauze.begin();
    while(it!=set_clauze.end())
    {
        set <string> p = *it;
        cout <<"{";
        set <string> ::iterator it2 = p.begin();
        while(it2 != p.end())
        {
            cout << *it2;
            it2++;
            if(it2 != p.end())
                cout <<",";
        }
        cout <<"}";
        it++;
        if(it != set_clauze.end())
            cout <<",";
    }
    cout <<"}";
    cout <<"\n\n";

    if(*((*set_clauze.begin()).begin()) == "t")
    {
        cout << '\n' <<"Propozitia este nesatisfiabila";
        this->satisfiabilitate = 0;
        return;
    }

    if(set_clauze.size() == 0)
    {
        cout << '\n' <<"Formula este satisfiabila";
        this->satisfiabilitate = 1;
        return;
    }
    int cnt = 0;
    int ok = -1;
    aplica_regula_1_si_2(set_clauze,set_literali_cu_negatie,cnt, ok);

    if(ok != -1)
    {
        this->satisfiabilitate = ok;
        return;
    }
    rezolutie_propozitionala2(set_clauze,set_literali_cu_negatie, ok);
    this->satisfiabilitate = ok;



}

void FNC::DPLL()
{


    set <string> set_literali_cu_negatie =  get_literali_cu_negatie(this->formula);
    set < set <string> > set_clauze =  this->clauze;
    cout <<'\n';
    cout << '\n' << "Am determinat setul de clauze corespunzator FNC:"<<'\n';

    cout <<"{";

    set < set <string> >:: iterator it = set_clauze.begin();
    while(it != set_clauze.end())
    {
        set <string> p = *it;
        cout <<"{";
        set <string> ::iterator it2 = p.begin();
        while(it2 != p.end())
        {
            cout << *it2;
            it2++;
            if(it2 != p.end())
                cout <<",";
        }
        cout <<"}";
        it++;
        if(it != set_clauze.end())
            cout <<",";
    }
    cout <<"}";
    cout <<"\n\n";
         if(*((*set_clauze.begin()).begin()) == "t")
    {
        cout << '\n' <<"Propozitia este nesatisfiabila";
        this->satisfiabilitate = 0;
        return;
    }

    int cnt = 0;
    int ok = -1;
    aplica_regula_1_si_2(set_clauze,set_literali_cu_negatie,cnt, ok);

    if(ok != -1)
    {
        this->satisfiabilitate = ok;
        return;
    }

    impartire_dupa_literali(set_literali_cu_negatie,set_clauze, ok);

    if(ok == -1)
    {
        cout <<"Nu s-a gasit nicio o ramura satisfiabila in DPLL\n";
        cout << '\n' <<"Formula este nesatisfiabila";
        this->satisfiabilitate = 0;
    }
    else
        this->satisfiabilitate = ok;



}

void FNC::build_formula_from_clauze()
{
    //WIP//
    return;
}

#include "FNC.h"


FNC::FNC(set <set <string> > x, string s, Arbore* a):FNN(s, a)
{
    this->clauze = x;
}

void FNC::transformare_in_FNC(ostringstream& ss)
{
    this->transformareFNN(ss);
    string forma_intermediara = this->formula;
    forma_intermediara = distributivitate1(forma_intermediara, ss);
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
void FNC::rezolutie(ostringstream& ss)
{
    set < set <string> > set_clauze =  this->clauze;
    ss << '\n' << "Am determinat setul de clauze corespunzator FNC:"<<'\n';

    ss <<"{";
    set < set <string> >:: iterator it = set_clauze.begin();
    while(it!=set_clauze.end())
    {
        set <string> p = *it;
        ss <<"{";
        set <string> ::iterator it2 = p.begin();
        while(it2 != p.end())
        {
            ss << *it2;
            it2++;
            if(it2 != p.end())
                ss <<",";
        }
        ss <<"}";
        it++;
        if(it != set_clauze.end())
        ss <<",";
    }
    ss <<"}";
    ss <<'\n';

    if(*((*set_clauze.begin()).begin()) == "t")
    {
        ss << '\n' <<"Propozitia este nesatisfiabila";
        this->satisfiabilitate = 0;
        return;
    }
    if(set_clauze.size() == 0)
    {
       ss << '\n' <<"Propozitia este nesatisfiabila";
        this->satisfiabilitate = 0;
        return;

    }
    combina_clauzele(set_clauze, ss);
    if(set_clauze.find({"eroare"}) != set_clauze.end())
    {
        ss << '\n' <<"Propozitia este nesatisfiabila";
        this->satisfiabilitate = 0;
        return;
    }
    ss <<'\n'<< "Dupa ce au fost incercate toate combinatiile posibile de clauze nu s-a obtinut clauza vida"<<'\n';
    ss <<'\n'<< "Setul de clauze final este:";
    ss <<"{";
    it = set_clauze.begin();
    while(it!=set_clauze.end())
    {
        set <string> p = *it;
        ss <<"{";
        set <string> ::iterator it2 = p.begin();
        while(it2 != p.end())
        {
            ss << *it2;
            it2++;
            if(it2 != p.end())
                cout <<",";
        }
        ss <<"}";
        it++;
        if(it != set_clauze.end())
        ss <<",";
    }
    ss <<"}";
    ss <<'\n';
    ss << '\n' <<"Propozitia este satisfiabila";
    this->satisfiabilitate = 1;
}

void FNC::DP(ostringstream &ss)
{


    set <string> set_literali_cu_negatie =  get_literali_cu_negatie(this->formula);
    set < set <string> > set_clauze =  this->clauze;
    ss << '\n' << "Am determinat setul de clauze corespunzator FNC:"<<'\n';


    ss <<"{";
    set < set <string> >:: iterator it = set_clauze.begin();
    while(it!=set_clauze.end())
    {
        set <string> p = *it;
        ss <<"{";
        set <string> ::iterator it2 = p.begin();
        while(it2 != p.end())
        {
            ss << *it2;
            it2++;
            if(it2 != p.end())
                ss <<",";
        }
        ss <<"}";
        it++;
        if(it != set_clauze.end())
            ss <<",";
    }
    ss <<"}";
    ss <<"\n\n";

    if(*((*set_clauze.begin()).begin()) == "t")
    {
        ss << '\n' <<"Propozitia este nesatisfiabila";
        this->satisfiabilitate = 0;
        return;
    }

    if(set_clauze.size() == 0)
    {
        ss << '\n' <<"Formula este satisfiabila";
        this->satisfiabilitate = 1;
        return;
    }
    int cnt = 0;
    int ok = -1;
    aplica_regula_1_si_2(set_clauze,set_literali_cu_negatie,cnt, ok, ss);

    if(ok != -1)
    {
        this->satisfiabilitate = ok;
        return;
    }
    rezolutie_propozitionala2(set_clauze,set_literali_cu_negatie, ok, ss);
    this->satisfiabilitate = ok;



}

void FNC::DPLL(ostringstream& ss)
{


    set <string> set_literali_cu_negatie =  get_literali_cu_negatie(this->formula);
    set < set <string> > set_clauze =  this->clauze;
    ss <<'\n';
    ss << '\n' << "Am determinat setul de clauze corespunzator FNC:"<<'\n';

    ss <<"{";

    set < set <string> >:: iterator it = set_clauze.begin();
    while(it != set_clauze.end())
    {
        set <string> p = *it;
        ss <<"{";
        set <string> ::iterator it2 = p.begin();
        while(it2 != p.end())
        {
            ss << *it2;
            it2++;
            if(it2 != p.end())
                ss <<",";
        }
        ss <<"}";
        it++;
        if(it != set_clauze.end())
            ss <<",";
    }
    ss <<"}";
    ss <<"\n\n";
         if(*((*set_clauze.begin()).begin()) == "t")
    {
        ss << '\n' <<"Propozitia este nesatisfiabila";
        this->satisfiabilitate = 0;
        return;
    }

    int cnt = 0;
    int ok = -1;
    aplica_regula_1_si_2(set_clauze,set_literali_cu_negatie,cnt, ok, ss);

    if(ok != -1)
    {
        this->satisfiabilitate = ok;
        return;
    }

    impartire_dupa_literali(set_literali_cu_negatie,set_clauze, ok, ss);

    if(ok == -1)
    {
        ss <<"Nu s-a gasit nicio o ramura satisfiabila in DPLL\n";
        ss << '\n' <<"Formula este nesatisfiabila";
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

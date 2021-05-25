#include <bits/stdc++.h>
#include "UI.h"

using namespace std;

/*
const int dim = 1e5 + 7;
const int dim2 = 100;

ofstream out("txt.out");

int nr_formule_propozitionale;

map <string, int> m;
vector <string> v[dim2];
vector <string> lista_formule;
set <string> lista_literali[dim2];
vector <string> lista_formula_FNN;
vector <string> lista_formula_FND;
vector <string> lista_formula_FNC;

int fiudr[dim][dim2];
int fiust[dim][dim2];
int p[dim][dim2];
int st[dim];
bool ok[dim];


int op1(int x)
{

    return 1 - x;
}

int op2(int x, int y)
{

    return x * y;
}

int op3(int x, int y)
{

    return x + y - x*y;
}

int op4(int x, int y)
{

    return x * y + (1 - x);
}



int op6(int x, int y)
{

    return x *y  + (1 - x) * (1 - y);
}

*/


/*
string transformare_structura_relaxata_in_structura_stricta(string c2)
{
    string dublicat;

    dublicat = c2;
    int cnt2 = 0;
    for(int j = 0; j < c2.size(); j++)
    {
        if( dublicat[j] == '!' ||  dublicat[j] == '|' ||  dublicat[j] == '&' ||  dublicat[j] == '>'  ||  dublicat[j] == '~')
        {

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

            ok[cntmax] = true;



            if(dublicat[pozmax] =='!')
            {

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
                    out << '\n' <<"Propozita nu este bine formata";
                    exit(0);
                }

            }
            else
            {
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
                    out << '\n' <<"Propozita nu este bine formata";
                    out << '\n' <<".Numarul de paranteze deschise nu este egal cu nr de paranteze inchise";
                    exit(0);
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
                    out << '\n' <<"Propozita nu este bine formata";
                    out << '\n' <<".Numarul de paranteze deschise nu este egal cu nr de paranteze inchise";
                    exit(0);
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

                }




            }
        }

    return dublicat;
}

void buildarb(string c2, int cnt_formule)
{
    for(int i = 0; i <= c2.size(); i++)
        p[i][cnt_formule] = -1;

    stack <char> q;
    stack <int> qval;

    string coppy;
    int cntp = 0;
    char s;

    for(int i = 0; i < c2.size(); i++)
    {
        s = c2[i];
        if(s == ' ')
            continue;

        if(s == '(')
            {
                cntp++;
                q.push(s);
                coppy.clear();
                coppy.push_back(s);
                qval.push(v[cnt_formule].size() + 1);
                v[cnt_formule].push_back(coppy);
            }
        else
        if(s != ')')
            {
                q.push(s);
                qval.push(v[cnt_formule].size() + 1);

                coppy.clear();

                coppy.push_back(s);
                if(c2[i] == '&' || c2[i] == '|' || c2[i] == '>'  || c2[i] == '~' || c2[i] == '!' || c2[i] == '(')
                {
                    v[cnt_formule].push_back(coppy);
                    continue;
                }
                else
                {

                bool ok2 = true;
                i++;
                while(i < c2.size() && ok2 == true && c2[i] != '&' && c2[i] != '|' && c2[i] != '>'  && c2[i] != '~' && c2[i] != '!' && c2[i] != '(' && c2[i] != ')')
                {
                    if(c2[i] == ' ')
                    {
                        ok2 = false;
                        i++;
                    }
                    else
                    {
                        coppy.push_back(c2[i]);
                        i++;
                    }
                }
                lista_literali[cnt_formule].insert(coppy);

                if(i < c2.size())
                    i--;
                }
                v[cnt_formule].push_back(coppy);


            }
        else
        {

            cntp--;
            if(cntp < 0)
            {
                out << '\n' <<"Prop nu esti bine formata";
                out << '\n' <<".Numarul de paranteze deschise nu este egal cu nr de paranteze inchise";
                exit(0);
            }

            if(q.empty())
            {
                out << '\n' <<"Prop nu esti bine formata";
                out << '\n' <<".Numarul de paranteze deschise nu este egal cu nr de paranteze inchise";
                exit(0);
            }

            char f1 = q.top();
            int f1val = qval.top();
            q.pop();
            qval.pop();

            if(f1 == '&' || f1 == '|' || f1 == '>'  || f1 == '~' || f1 == '!' || f1 == '(')
            {
                out << '\n' <<"Prop nu esti bine formata";
                out << '\n' <<"Conector inaintea unei paranteze inchise";
                exit(0);
            }

            if(q.empty())
            {
                out << '\n' <<"Prop nu esti bine formata";
                out << '\n' <<"S-a gasit un set de parantezari corecte,dar nu exista niciun conector in interiorul acestora";
                exit(0);
            }

            char f2 = q.top();
            int f2val = qval.top();
            q.pop();
            qval.pop();



            if(f2 == '&' || f2 == '|' || f2 == '>'  || f2 == '~')
            {
                if(q.empty())
                {
                    out << '\n' <<"Prop nu esti bine formata";
                    out << '\n' <<"S-a dat peste un conector ce cere doi literali ,dar se afla doar unul";
                    exit(0);
                }

                char f3 = q.top();
                int f3val = qval.top();
                q.pop();
                qval.pop();

                if(f3 == '&' || f3 == '|' || f3 == '>'  || f3 == '~' || f3 == '!' || f3 == '(')
                {
                    out << '\n' <<"Prop nu esti bine formata";
                    out << '\n' <<"S-a dat peste un conector ce cere doi literali ,dar langa acesta se afla un literal si un alt conector";
                    exit(0);
                }


                if(q.empty())
                {
                    out << '\n' <<"Prop nu esti bine formata";
                    out << '\n' <<"Lipsa unei paranteze deschise";
                    exit(0);
                }
                int f4 = q.top();
                q.pop();
                qval.pop();
                if(f4 != '(')
                {
                    out << '\n' <<"Prop nu esti bine formata";
                    out << '\n' <<"Lipsa unei paranteze deschise";
                    exit(0);
                }


                p[f3val][cnt_formule] = f2val;
                p[f1val][cnt_formule] = f2val;
                fiudr[f2val][cnt_formule] = f1val;
                fiust[f2val][cnt_formule] = f3val;

                q.push('A');
                qval.push(f2val);
                continue;
            }
            else
            if(f2 == '!')
            {

                if(q.empty())
                {
                    out << '\n' <<"Prop nu esti bine formata";
                    out << '\n' <<"S-a dat peste un conector care cere un literal,dar acesta lipseste";
                    exit(0);
                }
                int f4 = q.top();
                q.pop();
                qval.pop();
                if(f4 != '(')
                {
                    out << '\n' <<"Prop nu esti bine formata";
                    out << '\n' <<"Lipsa unei paranteze deschise";
                    exit(0);
                }

                p[f1val][cnt_formule] = f2val;
                fiudr[f2val][cnt_formule] = f1val;
                q.push('A');
                qval.push(f2val);
                continue;

            }
            else
            {
                out << '\n' <<"Prop nu esti bine formata";
                out << '\n' <<"S-au gasit 2 literali unul langa celalat";
                exit(0);
            }

        }
    }

    if(q.size() != 1)
        {
            out << '\n' <<"Prop nu esti bine formata";
            out << '\n' <<"Numar insuficient de paranteze inchise";
            exit(0);
        }

}


int calcul_valoare_sub_interpretare(int poz,int cnt_formule)
{
    if(v[cnt_formule][poz - 1][0] == '!')
        return(op1(calcul_valoare_sub_interpretare(fiudr[poz][cnt_formule],cnt_formule)));
    if(v[cnt_formule][poz - 1][0] == '&')
        return(op2(calcul_valoare_sub_interpretare(fiust[poz][cnt_formule],cnt_formule),calcul_valoare_sub_interpretare(fiudr[poz][cnt_formule],cnt_formule)));
    if(v[cnt_formule][poz - 1][0] == '|')
        return(op3(calcul_valoare_sub_interpretare(fiust[poz][cnt_formule],cnt_formule),calcul_valoare_sub_interpretare(fiudr[poz][cnt_formule],cnt_formule)));
    if(v[cnt_formule][poz - 1][0] == '>')
        return(op4(calcul_valoare_sub_interpretare(fiust[poz][cnt_formule],cnt_formule),calcul_valoare_sub_interpretare(fiudr[poz][cnt_formule],cnt_formule)));
    if(v[cnt_formule][poz - 1][0] == '~')
        return(op6(calcul_valoare_sub_interpretare(fiust[poz][cnt_formule],cnt_formule),calcul_valoare_sub_interpretare(fiudr[poz][cnt_formule],cnt_formule)));


    return m[v[cnt_formule][poz - 1]];


}


void transformare_in_FNN(int cnt_formula)
{
    string forma_intermediara;

    forma_intermediara = lista_formule[cnt_formula - 1];

    forma_intermediara = reducere1(forma_intermediara);
    forma_intermediara = reducere2(forma_intermediara);
    forma_intermediara = De_Morgan(forma_intermediara);


    lista_formula_FNN.push_back(forma_intermediara);


}

void transformare_in_FNC(int cnt_formula)
{
    string forma_noua;
    out << '\n' <<"Mai intai am transformat in formula in FNN efectuand pasii:\n";

    transformare_in_FNN(cnt_formula);

    forma_noua = distributivitate1(lista_formula_FNN[lista_formula_FNN.size() - 1]);
    lista_formula_FNC.push_back(forma_noua);

}

void transformare_in_FND(int cnt_formula)
{

    string forma_noua;
    out << '\n' <<"Mai intai am transformat in formula in FNN efectuand pasii:\n";

    transformare_in_FNN(cnt_formula);
    forma_noua = distributivitate2(lista_formula_FNN[lista_formula_FNN.size() - 1]);
    lista_formula_FND.push_back(forma_noua);

}

set < set <string> >  determinare_clauze(string s)
{
    set < set <string> > set1;
    set <string> set2;

    for(int i = 0;i < s.size(); i++)
    {

        if(s[i] == '&')
        {
            if(set2.size() == 1 && *set2.begin() == "t")
            {
                out << '\n' <<"Propozitia este nesatisfiabila";
                exit(0);
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
                out << '\n' <<"Propozitia este nesatisfiabila";
                exit(0);
        }

    return set1;

}



void rezolutie_propozitionala(string s)
{
    set < set <string> > set_clauze =  determinare_clauze(s);
    out << '\n' << "Am determinat setul de clauze corespunzator FNC, ignorand tautologiile:"<<'\n';

    out <<"{";
    set < set <string> >:: iterator it = set_clauze.begin();
    while(it!=set_clauze.end())
    {
        set <string> p = *it;
        out <<"{";
        set <string> ::iterator it2 = p.begin();
        while(it2 != p.end())
        {
            out << *it2;
            it2++;
            if(it2 != p.end())
                out <<",";
        }
        out <<"}";
        it++;
        if(it != set_clauze.end())
        out <<",";
    }
    out <<"}";
    out <<'\n';

    if(set_clauze.size() == 0)
    {
        out << '\n' <<"Propozitia este nesatisfiabila";
        exit(0);
    }
    combina_clauzele(set_clauze);
    if(set_clauze.find({"eroare"}) != set_clauze.end())
    {
        out << '\n' <<"Propozitia este nesatisfiabila";
        exit(0);
    }
    out <<'\n'<< "Dupa ce au fost incercate toate combinatiile posibile de clauze nu s-a obtinut clauza vida"<<'\n';
    out <<'\n'<< "Setul de clauze final este:";
    out <<"{";
    it = set_clauze.begin();
    while(it!=set_clauze.end())
    {
        set <string> p = *it;
        out <<"{";
        set <string> ::iterator it2 = p.begin();
        while(it2 != p.end())
        {
            out << *it2;
            it2++;
            if(it2 != p.end())
                out <<",";
        }
        out <<"}";
        it++;
        if(it != set_clauze.end())
        out <<",";
    }
    out <<"}";
    out <<'\n';
    out << '\n' <<"Propozitia este satisfiabila";
}



void bt(int k,int rad1,int rad2,int cnt_formule1,int cnt_formule2)
{
    if(k == lista_literali[cnt_formule1].size())
    {
        set <string>::iterator it;
        int i = 0;
        for(it = lista_literali[cnt_formule1].begin(); it != lista_literali[cnt_formule1].end(); it++)
        {
            m[*it] = st[i];
            i++;
        }

        if(calcul_valoare_sub_interpretare(rad1,cnt_formule1) != calcul_valoare_sub_interpretare(rad2,cnt_formule2))
        {
            out << '\n' <<"Prop nu sunt echivalente";
            exit(0);
        }
    }
    else
        for(int i = 0;i <= 1; i++)
        {
            st[k] = i;
            bt(k + 1,rad1,rad2,cnt_formule1,cnt_formule2);
        }
}


void bt_satisfiabilitate(int k,int rad,int cnt_formula)
{

    if(k == lista_literali[cnt_formula].size())
    {
        set <string>::iterator it;
        int i = 0;
        for(it = lista_literali[cnt_formula].begin(); it != lista_literali[cnt_formula].end(); it++)
        {
            m[*it] = st[i];
            i++;
        }

        if(calcul_valoare_sub_interpretare(rad,cnt_formula) == 1)
        {
            out << '\n' <<"Prop este satisfiabila";
            exit(0);
        }

    }
    else
        for(int i = 0;i <= 1; i++)
        {
            st[k] = i;
            bt_satisfiabilitate(k + 1,rad,cnt_formula);
        }
}


void bt_validitate(int k,int rad,int cnt_formula)
{

    if(k == lista_literali[cnt_formula].size())
    {
        set <string>::iterator it;
        int i = 0;
        for(it = lista_literali[cnt_formula].begin(); it != lista_literali[cnt_formula].end(); it++)
        {
            m[*it] = st[i];
            i++;
        }

        if(calcul_valoare_sub_interpretare(rad,cnt_formula) == 0)
        {
            out << '\n' <<"Prop nu este valida";
            exit(0);
        }

    }
    else
        for(int i = 0;i <= 1; i++)
        {
            st[k] = i;
            bt_validitate(k + 1,rad,cnt_formula);
        }
}

void declarare_valori_conectori()
{
    string semne;
    semne.push_back('!');
    m[semne] = 5;

    semne.pop_back();
    semne.push_back('&');
    m[semne] = 4;
    semne.pop_back();
    semne.push_back('|');
    m[semne] = 3;
    semne.pop_back();
    semne.push_back('>');
    m[semne] = 2;
    semne.pop_back();
    semne.push_back('~');
    m[semne] = 1;
    semne.pop_back();
    semne.push_back('t');
    m[semne] = 0;
    semne.pop_back();
    semne.push_back('T');
    m[semne] = 1;
}

void introducere_valori_sub_interpretare()
{
    string s2;

    while(cin >> s2)
    {
        // in s2 e literalul , iar in x valoarea de adevar 0 / 1
        if(s2[0] == '.')
                break;
        int x;
        cin >> x;
        m[s2] = x;
    }
    // este necesar ca dupa scrierea fiecarei interpretari sa se introduca  '.'
    // interpreaterea va fi de forma nume literal (pe o linie) 1 / 0 (1 -> A, 0 -> F) (pe alta linie)
}

int determinare_radacina(int cnt_formule)
{
    for(int i = 0; i < v[cnt_formule].size(); i++)
        if(v[cnt_formule][i][0] != '(')
            if(p[i + 1][cnt_formule] == -1)
                return(i + 1);
}


void citire_formula()
{
    nr_formule_propozitionale++;
    string formula;

    cout << '\n' <<"Introduceti formula propozitionala aleasa:";
    cin >> formula;
    out << formula << '\n' << '\n';
    formula = transformare_structura_relaxata_in_structura_stricta(formula);
    buildarb(formula,nr_formule_propozitionale);
    lista_formule.push_back(formula);

}

int calcul_valoare_sub_interpretare_formula(int nr_formule_propozitionale)
{
    out << '\n' <<"Introduceti pe rand literalul apoi 1 daca valoarea sub interpretare a sa este A alftel introducti 0"<<endl;
    out << '\n' <<"Dupa ce ati terminat de introdus toti literali impreuna cu valorile sale sub interpretare va rog apasati tasta '.' "<<endl;
    introducere_valori_sub_interpretare();
    int radacina = determinare_radacina(nr_formule_propozitionale);
    return calcul_valoare_sub_interpretare(radacina,nr_formule_propozitionale);
}

void verificiare_echivalenta(int indice_prop1, int indice_prop2)
{
    int radacina1 = determinare_radacina(indice_prop1);
    int radacina2 = determinare_radacina(indice_prop2);

    bt(0,radacina1,radacina2,indice_prop1,indice_prop2);
    out << '\n' <<"Prop sunt echivalente";

}

void verificare_satisfiabilitate(int nr_formule_propozitionale)
{

    int radacina = determinare_radacina(nr_formule_propozitionale);

    bt_satisfiabilitate(0,radacina,nr_formule_propozitionale);
    out << '\n' <<"Formula este nesatisfiabila";
}

void verificare_validitate(int nr_formule_propozitionale)
{

    int radacina = determinare_radacina(nr_formule_propozitionale);

    bt_validitate(0,radacina,nr_formule_propozitionale);
    out << '\n' <<"Formula este valida";
}



void DP(string s)
{

    set <string> set_literali_cu_negatie =  get_literali_cu_negatie(s);
    set < set <string> > set_clauze =  determinare_clauze(s);
    out << '\n' << "Am determinat setul de clauze corespunzator FNC:"<<'\n';

    out <<"{";
    set < set <string> >:: iterator it = set_clauze.begin();
    while(it!=set_clauze.end())
    {
        set <string> p = *it;
        out <<"{";
        set <string> ::iterator it2 = p.begin();
        while(it2 != p.end())
        {
            out << *it2;
            it2++;
            if(it2 != p.end())
                out <<",";
        }
        out <<"}";
        it++;
        if(it != set_clauze.end())
            out <<",";
    }
    out <<"}";
    out <<'\n\n';

        if(*((*set_clauze.begin()).begin()) == "t")
    {
        out << '\n' <<"Propozitia este nesatisfiabila";
        return;
    }


    if(set_clauze.size() == 0)
    {
        out << '\n' <<"Formula este satisfiabila";
        exit(0);
    }
    int cnt = 0;
    int ok = -1;
    aplica_regula_1_si_2(set_clauze,set_literali_cu_negatie,cnt, ok);

    rezolutie_propozitionala2(set_clauze,set_literali_cu_negatie, ok);


}


void DPLL(string s)
{

    set <string> set_literali_cu_negatie =  get_literali_cu_negatie(s);
    set < set <string> > set_clauze =  determinare_clauze(s);
    out <<'\n';
    out << '\n' << "Am determinat setul de clauze corespunzator FNC, ignorand tautologiile:"<<'\n';

    out <<"{";

    set < set <string> >:: iterator it = set_clauze.begin();
    while(it != set_clauze.end())
    {
        set <string> p = *it;
        out <<"{";
        set <string> ::iterator it2 = p.begin();
        while(it2 != p.end())
        {
            out << *it2;
            it2++;
            if(it2 != p.end())
                out <<",";
        }
        out <<"}";
        it++;
        if(it != set_clauze.end())
            out <<",";
    }
    out <<"}";
    out <<'\n';
         if(*((*set_clauze.begin()).begin()) == "t")
    {
        out << '\n' <<"Propozitia este nesatisfiabila";
        return;
    }

    int cnt = 0;
    int ok;
    aplica_regula_1_si_2(set_clauze,set_literali_cu_negatie,cnt, ok);


    impartire_dupa_literali(set_literali_cu_negatie,set_clauze, ok);

    out <<"Nu s-a gasit nicio o ramura satisfiabila in DPLL\n";
    out << '\n' <<"Formula este nesatisfiabila";


}

void UI()
{
    cout  <<"Pentru trasnformarea unei propozitii din sintaxa relaxata in sintaxa stricta apasati tasta 1"<<endl;
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

    int x;
    cin >> x;
    out << x<<'\n' <<'\n';
    switch(x)
    {
        case 1:
            {
                citire_formula();
                out << '\n' <<"Forma in sintaxa stricta a formulei introdusa este:" <<  lista_formule[nr_formule_propozitionale - 1];
                break;
            }
        case 2:
            {
                citire_formula();
                out << '\n' <<"Forma in sintaxa stricta a formulei introdusa este:" <<  lista_formule[nr_formule_propozitionale - 1];
                out << '\n' <<"Valuarea sub interpretare este:" << calcul_valoare_sub_interpretare_formula(nr_formule_propozitionale)<<endl;
                break;
            }
        case 3:
            {
                citire_formula();
                out << '\n' <<"Forma in sintaxa stricta a formulei introdusa este:" <<  lista_formule[nr_formule_propozitionale - 1] <<'\n';
                verificare_satisfiabilitate(nr_formule_propozitionale);
                break;
            }
        case 4:
            {
                citire_formula();
                out << '\n' <<"Forma in sintaxa stricta a formulei introdusa este:" <<  lista_formule[nr_formule_propozitionale - 1] <<'\n';
                verificare_validitate(nr_formule_propozitionale);
                break;
            }
        case 5:
            {
                citire_formula();
                out << '\n' <<"Forma in sintaxa stricta a primei formule introdusa este:" <<  lista_formule[nr_formule_propozitionale - 1] <<'\n';
                citire_formula();
                out << '\n' <<"Forma in sintaxa stricta a celei de a doua formula introdusa este:" <<  lista_formule[nr_formule_propozitionale - 1] << '\n';
                verificiare_echivalenta(1,2);
                break;
            }
        case 6:
            {
                citire_formula();
                out << '\n' <<"Forma in sintaxa stricta a formulei introduse este:" <<  lista_formule[nr_formule_propozitionale - 1] <<'\n';
                transformare_in_FNN(nr_formule_propozitionale);
                out << '\n' << "Forma normal negativa a formulei initiale este:" << lista_formula_FNN[lista_formula_FNN.size() - 1];
                break;
            }
        case 7:
            {
                citire_formula();
                out << '\n' <<"Forma in sintaxa stricta a formulei introdusa este:" <<  lista_formule[nr_formule_propozitionale - 1] <<'\n';
                transformare_in_FND(nr_formule_propozitionale);
                out << '\n' << "Forma normal disjunctiva a formulei initiale este:" << lista_formula_FND[lista_formula_FND.size() - 1];
                break;

            }
        case 8:
            {
                citire_formula();
                out << '\n' <<"Forma in sintaxa stricta a formulei introdusa este:" <<  lista_formule[nr_formule_propozitionale - 1] <<'\n';
                transformare_in_FNC(nr_formule_propozitionale);
                out << '\n' << "Forma normal conjuctiva a formulei initiale este:" << lista_formula_FNC[lista_formula_FNC.size() - 1];
                break;
            }
        case 9:
            {
                citire_formula();
                out << '\n' <<"Forma in sintaxa stricta a formulei introdusa este:" <<  lista_formule[nr_formule_propozitionale - 1] <<'\n';
                transformare_in_FNC(nr_formule_propozitionale);
                rezolutie_propozitionala(lista_formula_FNC[lista_formula_FNC.size() - 1]);
                break;
            }
        case 10:
            {
                citire_formula();
                out << '\n' <<"Forma in sintaxa stricta a formulei introdusa este:" <<  lista_formule[nr_formule_propozitionale - 1] <<'\n';
                transformare_in_FNC(nr_formule_propozitionale);
                DP(lista_formula_FNC[lista_formula_FNC.size() - 1]);
                break;

            }
        case 11:
            {
                citire_formula();
                out << '\n' <<"Forma in sintaxa stricta a formulei introdusa este:" <<  lista_formule[nr_formule_propozitionale - 1] <<'\n';
                out << '\n' <<"Am transformat formula in una din FNC a sa" <<'\n';
                transformare_in_FNC(nr_formule_propozitionale);
                out << '\n' << "Forma normal conjuctiva a formulei initiale este:" << lista_formula_FNC[lista_formula_FNC.size() - 1]<<'\n';
                DPLL(lista_formula_FNC[lista_formula_FNC.size() - 1]);

            }

    }
}

int main()
{
     Va rog sa folositi notatiile acestea pentru operatii:
    1.∧  &
    2.∨ |
    3.=> >
    4.<=> ~
    5.¬ !

    Pt ⊥ am folosit t
    Pt T am folosit T

    NU FOLOSITI EMOJIURI PE POST DE PROPOZITII DEOARECE ACESTEA SUNT FORMATE DIN MAI MULTE CARACTERE!
    COMPILATORUL MINGW SPECIFIC C++ NU VA RECUNOASTE TOATE SIMBOLURILE!
    SUNT CONSIDERATE PROPOZITII ORICE CARACTER DIFERIT DE SIMBOLURI OPERATIILOR!


    nr_formule_propozitionale = 0;
    declarare_valori_conectori();




    UI();


    return 0;
}
*/


int main()
{

        UI();

}


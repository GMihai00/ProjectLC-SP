#include "Operations.h"

int op1(int x)
{
    /*operatia !*/
    return 1 - x;
}

int op2(int x, int y)
{
    /*operatia &*/
    return x * y;
}

int op3(int x, int y)
{
    /*operatia |*/
    return x + y - x*y;
}

int op4(int x, int y)
{
    /*operatia >*/
    return x * y + (1 - x);
}



int op6(int x, int y)
{
    /*operatia ~*/
    return x *y  + (1 - x) * (1 - y);
}

string transformare_structura_relaxata_in_structura_stricta(string c2, map <string,int> m, ostream& ss)
{
    string dublicat;

    bool ok[c2.size()];




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
                    cout <<"Prop nu este bine formata";
                    exit(0);
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
                    ss << '\n' <<"Propozita nu este bine formata";
                    exit(0);
                }

            }
            else
            {
                if(pozmax + 1 >= dublicat.size() || pozmax - 1 < 0)
                {
                    cout <<"Prop nu este bine formata";
                    exit(0);
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
                    ss << '\n' <<"Propozita nu este bine formata";
                    ss << '\n' <<".Numarul de paranteze deschise nu este egal cu nr de paranteze inchise";
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
                    ss << '\n' <<"Propozita nu este bine formata";
                    ss << '\n' <<".Numarul de paranteze deschise nu este egal cu nr de paranteze inchise";
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


string reducere1(string s, ostream& ss)
{
    string cpys;

    bool redus = false;
    int cnt = 0;

    while(redus == false)
    {
        cnt++;
        cpys = s;
        int poz = -1;
        int l;
        int nrpd = 0;
        int nppdmax = 0;
        for(int i = 0; i < cpys.size(); i++)
        {
            if(cpys[i] == '(')
                nrpd++;
            else
            if(cpys[i] == ')')
                nrpd--;
            else
            if(cpys[i] == '>')
            {
                if(nrpd > nppdmax)
                {
                    poz = i;
                    nppdmax = nrpd;
                }

            }
        }

        if(poz == -1)
            redus = true;
        else
        {
            int cntp = 0;
            for(int i = poz - 1; i >= 0; i--)
            {
                if(cpys[i] == ')')
                    cntp--;
                else
                if(cpys[i] == '(')
                    cntp++;

                if(cntp == 0 && (i - 1 < 0 || cpys[i - 1] == '!' || cpys[i - 1] == '&' || cpys[i - 1] == '|' || cpys[i - 1] == '(' ||  cpys[i - 1] == '~' || cpys[i - 1] == '>'))
                {
                    l = i;
                    i = -1;
                }
            }

        string cpys2;


        for(int i = 0; i < l; i++)
            cpys2.push_back(cpys[i]);
        cpys2.push_back('(');
        cpys2.push_back('!');
        for(int i = l; i < poz; i++)
            cpys2.push_back(cpys[i]);
        cpys2.push_back(')');
        cpys2.push_back('|');
        for(int i = poz + 1;i < cpys.size(); i++)
            cpys2.push_back(cpys[i]);


        s = cpys2;

        }

        if(redus == false)
        {   if(cnt == 1)
                ss << '\n' <<"Operatiile de reducere a implicatiei  efectuate sunt:\n";
            ss << '\n' << cpys <<" echivalent cu "<< s<<'\n';
        }
    }

    return s;
}

string reducere2(string s, ostream& ss)
{
    string cpys;

    bool redus = false;
    int cnt = 0;
    while(redus == false)
    {
        cnt++;
        cpys = s;
        int poz = -1;
        int l;
        int r;
        int nrpd = 0;
        int nppdmax = 0;
        for(int i = 0; i < cpys.size(); i++)
        {
            if(cpys[i] == '(')
                nrpd++;
            else
            if(cpys[i] == ')')
                nrpd--;
            else
            if(cpys[i] == '~')
            {
                poz = i;
                if(nrpd > nppdmax)
                {
                    poz = i;
                    nppdmax = nrpd;
                }
            }
        }

        if(poz == -1)
            redus = true;
        else
        {
            int cntp = 0;
            for(int i = poz - 1; i >= 0; i--)
            {
                if(cpys[i] == ')')
                    cntp--;
                else
                if(cpys[i] == '(')
                    cntp++;

                if(cntp == 0 && (i - 1 < 0 || cpys[i - 1] == '!' || cpys[i - 1] == '&' || cpys[i - 1] == '|' || cpys[i - 1] == '(' ||  cpys[i - 1] == '~' || cpys[i - 1] == '>'))
                {
                    l = i;
                    i = -1;
                }
            }
            cntp = 0;
            for(int i = poz + 1; i < cpys.size(); i++)
            {
                if(cpys[i] == '(')
                    cntp++;
                else
                if(cpys[i] == ')')
                    cntp--;

                if(cntp == 0 && (i + 1 >= cpys.size()  || cpys[i + 1] == '&' || cpys[i + 1] == '|' || cpys[i + 1] == ')' ||  cpys[i + 1] == '~' || cpys[i + 1] == '>'))
                {
                    r = i;
                    i = cpys.size() + 1;
                }
            }

        string cpys2;


        for(int i = 0; i < l; i++)
            cpys2.push_back(cpys[i]);
        cpys2.push_back('(');
        cpys2.push_back('(');
        cpys2.push_back('!');


        for(int i = l; i < poz; i++)
            cpys2.push_back(cpys[i]);
        cpys2.push_back(')');
        cpys2.push_back('|');
        for(int i = poz + 1; i <= r; i++)
            cpys2.push_back(cpys[i]);
        cpys2.push_back(')');
        cpys2.push_back('&');
        cpys2.push_back('(');
        cpys2.push_back('(');
        cpys2.push_back('!');
        for(int i = poz + 1; i <= r; i++)
            cpys2.push_back(cpys[i]);
        cpys2.push_back(')');
        cpys2.push_back('|');
        for(int i = l; i < poz; i++)
            cpys2.push_back(cpys[i]);
            cpys2.push_back(')');
        for(int i = r + 1; i < cpys.size(); i++)
            cpys2.push_back(cpys[i]);
        s = cpys2;

        }
        if(redus == false)
        {    if(cnt == 1)
                ss << '\n' <<"Operatiile de reducere a echivalentei  efectuate sunt:\n";
            ss << '\n' << cpys <<" echivalent cu "<< s<<'\n';
        }
    }

    return s;

}

string De_Morgan(string s, ostream& ss)
{
    string cpys;

    bool redus = false;
    int cnt = 0;

    while(redus == false)
    {
        cnt++;
        cpys = s;
        int poz = -1;
        for(int i = 0;i < cpys.size() - 1; i++)
        {
            if(cpys[i] == '!' && cpys[i + 1] == '(')
            {
                poz = i;
                i = cpys.size() + 1;
            }

        }

        if(poz == -1)
            redus = true;
        else
        {
            string cpys2;

            int r;
            int cntp = 0;

            for(int i = poz + 1; i < cpys.size(); i++)
            {
                if(cpys[i] == '(')
                    cntp++;
                else
                if(cpys[i] == ')')
                    cntp--;

                if(cntp == 0)
                {
                    r = i;
                    i = cpys.size() + 1;
                }
            }

            for(int i = 0; i < poz - 1; i++)
                cpys2.push_back(cpys[i]);

            for(int i = poz + 1; i <= r; i++)
            {
                if(cpys[i] == '&')
                    cpys2.push_back('|');
                else
                if(cpys[i] == '|')
                    cpys2.push_back('&');
                else
                if(cpys[i] == '!' && cpys[i + 1] !='(')
                {
                    int cntp2 = 1;
                    cpys2.pop_back();
                    i++;
                    while(cpys[i] != '!' && cpys[i] != '|' && cpys[i] !='&' && cpys[i] != '(' && cpys[i] != ')')
                    {
                        cpys2.push_back(cpys[i]);
                        i++;
                    }
                }
                else
                if(cpys[i] != '!' && cpys[i] != '(' && cpys[i] != ')')
                {
                    cpys2.push_back('(');
                    cpys2.push_back('!');
                    while(cpys[i] != '!' && cpys[i] != '|' && cpys[i] !='&' && cpys[i] != '(' && cpys[i] != ')')
                    {
                        cpys2.push_back(cpys[i]);
                        i++;
                    }
                    i--;
                    cpys2.push_back(')');
                }
                else
                    cpys2.push_back(cpys[i]);
            }
            for(int i = r + 2;i < cpys.size(); i++)
                cpys2.push_back(cpys[i]);




            s = cpys2;
        }
        if(redus == false)
        {    if(cnt == 1)
               ss << '\n' <<"Operatiile de tip De Morgan efectuate sunt:\n";
            ss << '\n' << cpys <<" echivalent cu "<< s<<'\n';
        }
    }
    return s;

}


pair <int,int> conector_semnificiativ(string s)
{
    int cntp = 0;
    int cntsi = 0;
    int poz_conector = -1;

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(')
            cntp++;
        else
        if(s[i] == ')')
            cntp--;
        else
        if(s[i] == '&')
        {
            if(cntp == 1)
                poz_conector = i;
            cntsi++;
        }
        else
        if(s[i] == '|')
            if(cntp == 1)
                poz_conector = i;
    }

    return make_pair(cntsi,poz_conector);

}

pair <int,int> conector_semnificiativ2(string s)
{
    int cntp = 0;
    int cntsau = 0;
    int poz_conector = -1;

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(')
            cntp++;
        else
        if(s[i] == ')')
            cntp--;
        else
        if(s[i] == '&')
        {
            if(cntp == 1)
                poz_conector = i;

        }
        else
        if(s[i] == '|')
        {
                if(cntp == 1)
                poz_conector = i;
                cntsau++;
        }
    }

    return make_pair(cntsau,poz_conector);

}


string distributivitate1(string s, ostream& ss)
{

    ss << '\n' <<"Formula curenta este:" << s<<'\n';
    pair <int,int> p = conector_semnificiativ(s);
    int nrsi = p.first;
    int p_conector = p.second;
    if(p_conector!= -1)
        ss << '\n' <<"Am determinat cel mai semnificativ conector al propozitie curente acesta fiind:" << s[p_conector] <<'\n';
    if(nrsi == 0)
    {
        ss << '\n' <<"Formula curenta este in FNC deoarece contine conectori de un singur tip"<<'\n';
        return s;
    }

    int st;
    int cntp = 0;

    for(int i = p_conector - 1; i >= 0; i--)
    {
        if(s[i] == '(')
            cntp++;
        else
        if(s[i] == ')')
            cntp--;

        if(cntp == 0 && (i - 1 < 0 || s[i - 1] == '|' || s[i - 1] == '&'|| s[i - 1] == '('))
        {
            st = i;
            i = -1;
        }


    }

    int dr;
    cntp = 0;

    for(int i = p_conector + 1; i < s.size(); i++)
    {
        if(s[i] == '(')
            cntp++;
        else
        if(s[i] == ')')
            cntp--;

        if(cntp == 0 && (i + 1 >= s.size() || s[i + 1] == '|' || s[i + 1] == '&'|| s[i + 1] == ')'))
        {
            dr = i;
            i = s.size() + 1;
        }
    }

    string formulast;
    string formuladr;

    for(int i = st; i < p_conector; i++)
        formulast.push_back(s[i]);

    ss << '\n' <<"Formula din stanga conectorului cel mai semnificativ este:" << formulast << '\n';

    for(int i = p_conector + 1; i <= dr; i++)
        formuladr.push_back(s[i]);

    ss << '\n' <<"Formula din dreapta conectorului cel mai semnificativ este:" << formuladr << '\n';

    if(s[p_conector] == '&')
    {
        ss << '\n' <<"Conectorul cel mai semnificativ este & deci va trebui sa verific doar daca formula din stanga si din dreapta sunt sub forma de FNC" <<'\n';
        return("(" + distributivitate1(formulast, ss) + s[p_conector] + distributivitate1(formuladr, ss) + ")");
    }
    else
    {


       ss << '\n' <<"Conectorul cel mai semnificativ este | deci va trebui sa aplic distributivitatea si eventual asociativitatea si comutativitatea dintre doi literali conectati de un conector" <<'\n';

        string formulanoua;
        pair <int,int> pst = conector_semnificiativ(formulast);
        int nrsist = pst.first;
        int pst_conector = pst.second;



        if(nrsist == 0)
        {
            string cpyformula;
            cpyformula = formulast;
            formulast = formuladr;
            formuladr = cpyformula;
        }
            pst = conector_semnificiativ(formulast);
            nrsist = pst.first;
            pst_conector = pst.second;

            if(pst_conector!= -1)
                ss << '\n' <<"Am determinat cel mai semnificativ conector al propozitie din stanga acesta fiind:" << formulast[pst_conector] <<'\n';

            int stst;
            int cntpst = 0;

            for(int i = pst_conector - 1; i >= 0; i--)
            {
                if(formulast[i] == '(')
                    cntpst++;
                else
                if(formulast[i] == ')')
                    cntpst--;

                if(cntpst == 0 && (i - 1 < 0 || formulast[i - 1] == '|' || formulast[i - 1] == '&'|| formulast[i - 1] == '('))
                {
                    stst = i;
                    i = -1;
                }


            }

            int drst;
            cntpst = 0;

            for(int i = pst_conector + 1; i < formulast.size(); i++)
            {
                if(formulast[i] == '(')
                    cntpst++;
                else
                if(formulast[i] == ')')
                    cntpst--;

                if(cntpst == 0 && (i + 1 >= formulast.size() || formulast[i + 1] == '|' || formulast[i + 1] == '&'|| formulast[i + 1] == ')'))
                {
                    drst = i;
                    i = formulast.size() + 1;
                }
            }

            string formulastv2;
            string formuladrv2;

            for(int i = stst; i < pst_conector; i++)
                formulastv2.push_back(formulast[i]);

            ss << '\n' <<"Formula din stanga celui mai semnificativ semn al formulei din stanga este:" << formulastv2 <<'\n';
            for(int i = pst_conector + 1; i <= drst; i++)
                formuladrv2.push_back(formulast[i]);
            ss << '\n' <<"Formula din dreapta celui mai semnificativ semn al formulei din stanga este:" << formuladrv2 <<'\n';


            pair <int,int> pst2 = conector_semnificiativ(formulast);
            int nrsist2 = pst2.first;
            int pst_conector2 = pst2.second;

            if(nrsist2 == 0)
            {
                string cpyformula;
                cpyformula = formulastv2;
                formulastv2 = formuladrv2;
                formuladrv2 = cpyformula;
            }

            if(formulast[pst_conector] == '|')
            {
                formulanoua =  formulastv2  + "|(" + formuladrv2 + "|" + formuladr + ")";
                ss << '\n' << "Am aplicat asociativitate fata de conectorul | si am obtinut:" << formulanoua <<'\n';
            }
            else
            {
                formulanoua = "(" + formulastv2 + "|" + formuladr +  ")&(" + formuladrv2 + "|" + formuladr + ")";
                ss << '\n' << "Am aplicat distributivitatea conectorului & fata de conectorul | si am obtinut:" << formulanoua <<'\n';
            }

        return(distributivitate1("(" + formulanoua + ")", ss));


    }

}

string distributivitate2(string s, ostream& ss)
{
    ss << '\n' <<"Formula curenta este:" << s<<'\n';
    pair <int,int> p = conector_semnificiativ2(s);
    int nrsi = p.first;
    int p_conector = p.second;
    if(p_conector!= -1)
        ss << '\n' <<"Am determinat cel mai semnificativ conector al propozitie curente acesta fiind:" << s[p_conector] <<'\n';
    if(nrsi == 0)
    {   ss << '\n' <<"Formula curenta este in FNC deoarece contine conectori de un singur tip"<<'\n';
        return s;

    }

    int st;
    int cntp = 0;

    for(int i = p_conector - 1; i >= 0; i--)
    {
        if(s[i] == '(')
            cntp++;
        else
        if(s[i] == ')')
            cntp--;

        if(cntp == 0 && (i - 1 < 0 || s[i - 1] == '|' || s[i - 1] == '&'|| s[i - 1] == '('))
        {
            st = i;
            i = -1;
        }


    }

    int dr;
    cntp = 0;

    for(int i = p_conector + 1; i < s.size(); i++)
    {
        if(s[i] == '(')
            cntp++;
        else
        if(s[i] == ')')
            cntp--;

        if(cntp == 0 && (i + 1 >= s.size() || s[i + 1] == '|' || s[i + 1] == '&'|| s[i + 1] == ')'))
        {
            dr = i;
            i = s.size() + 1;
        }
    }

    string formulast;
    string formuladr;

    for(int i = st; i < p_conector; i++)
        formulast.push_back(s[i]);

    ss << '\n' <<"Formula din stanga conectorului cel mai semnificativ este:" << formulast << '\n';
    for(int i = p_conector + 1; i <= dr; i++)
        formuladr.push_back(s[i]);

    ss << '\n' <<"Formula din dreapta conectorului cel mai semnificativ este:" << formuladr << '\n';

    if(s[p_conector] == '|')
    {
        ss << '\n' <<"Conectorul cel mai semnificativ este | deci va trebui sa verific doar daca formula din stanga si din dreapta sunt sub forma de FND" <<'\n';
        return("(" + distributivitate2(formulast, ss) + s[p_conector] + distributivitate2(formuladr, ss) + ")");
    }
    else
    {

        ss << '\n' <<"Conectorul cel mai semnificativ este & deci va trebui sa aplic distributivitatea si eventual asociativitatea si comutativitatea dintre doi literali conectati de un conector" <<'\n';

        string formulanoua;
        pair <int,int> pst = conector_semnificiativ2(formulast);
        int nrsist = pst.first;
        int pst_conector = pst.second;
        if(pst_conector!= -1)
            ss << '\n' <<"Am determinat cel mai semnificativ conector al propozitie curente acesta fiind:" << formulast[pst_conector] <<'\n';
        if(nrsist == 0)
        {
            string cpyformula;
            cpyformula = formulast;
            formulast = formuladr;
            formuladr = cpyformula;
        }
            pst = conector_semnificiativ(formulast);
            nrsist = pst.first;
            pst_conector = pst.second;

            int stst;
            int cntpst = 0;

            for(int i = pst_conector - 1; i >= 0; i--)
            {
                if(formulast[i] == '(')
                    cntpst++;
                else
                if(formulast[i] == ')')
                    cntpst--;

                if(cntpst == 0 && (i - 1 < 0 || formulast[i - 1] == '|' || formulast[i - 1] == '&'|| formulast[i - 1] == '('))
                {
                    stst = i;
                    i = -1;
                }


            }

            int drst;
            cntpst = 0;

            for(int i = pst_conector + 1; i < formulast.size(); i++)
            {
                if(formulast[i] == '(')
                    cntpst++;
                else
                if(formulast[i] == ')')
                    cntpst--;

                if(cntpst == 0 && (i + 1 >= formulast.size() || formulast[i + 1] == '|' || formulast[i + 1] == '&'|| formulast[i + 1] == ')'))
                {
                    drst = i;
                    i = formulast.size() + 1;
                }
            }

            string formulastv2;
            string formuladrv2;

            for(int i = stst; i < pst_conector; i++)
                formulastv2.push_back(formulast[i]);

            ss << '\n' <<"Formula din stanga celui mai semnificativ semn al formulei din stanga este:" << formulastv2 <<'\n';

            for(int i = pst_conector + 1; i <= drst; i++)
                formuladrv2.push_back(formulast[i]);

            ss << '\n' <<"Formula din dreapta celui mai semnificativ semn al formulei din stanga este:" << formuladrv2 <<'\n';

            pair <int,int> pst2 = conector_semnificiativ(formulast);
            int nrsist2 = pst2.first;
            int pst_conector2 = pst2.second;

            if(nrsist2 == 0)
            {
                string cpyformula;
                cpyformula = formulastv2;
                formulastv2 = formuladrv2;
                formuladrv2 = cpyformula;
            }

            if(formulast[pst_conector] == '&')
            {
                formulanoua =  formulastv2  + "&(" + formuladrv2 + "&" + formuladr + ")";
                ss << '\n' << "Am aplicat asociativitate fata de conectorul & si am obtinut:" << formulanoua <<'\n';
            }
            else
            {
                formulanoua = "(" + formulastv2 + "&" + formuladr +  ")|(" + formuladrv2 + "&" + formuladr + ")";
                ss  << '\n' << "Am aplicat distributivitatea conectorului | fata de conectorul & si am obtinut:" << formulanoua <<'\n';
            }

        return(distributivitate2("(" + formulanoua + ")", ss));


    }


}

void combina_clauzele(set < set <string> > &set_clauze, ostream& ss)
{

    vector < set <string> > lista_clauze;


    for(auto it:set_clauze)
        lista_clauze.push_back(it);

    for(int i = 0; i < lista_clauze.size(); i++)
        for(int j = 0; j < lista_clauze.size(); j++)
        {
            if(i != j)
            {
                int cnt_literali_complementari = 0;
                string literal_complementar;
                for(auto it:lista_clauze[i])
                {
                    string l_c;
                    if(it[0] == '!')
                        for(int p = 1; p < it.size(); p++)
                            l_c.push_back(it[p]);
                    else
                        l_c = "!" + it;


                    if(lista_clauze[j].find(l_c) != lista_clauze[j].end())
                    {
                        cnt_literali_complementari++;
                        literal_complementar = l_c;
                    }
                }

                if(cnt_literali_complementari == 1)
                {
                    set <string> set2;

                    for(auto it:lista_clauze[i])
                        set2.insert(it);
                    for(auto it:lista_clauze[j])
                        set2.insert(it);

                    set2.erase(literal_complementar);
                    string l_c_2;
                    if(literal_complementar[0] == '!')
                        {
                            for(int p = 1 ; p < literal_complementar.size(); p++)
                                l_c_2.push_back(literal_complementar[p]);
                            literal_complementar = l_c_2;
                        }
                    else
                        literal_complementar = "!" + literal_complementar;
                    set2.erase(literal_complementar);

                    if(set2.size() == 0)
                    {
                        ss << '\n' <<"Combinand clauza ";
                        set <string>::iterator it;
                        it = lista_clauze[i].begin();
                        ss <<"{";
                        while(it != lista_clauze[i].end())
                        {
                            ss << *it;
                            it++;
                            if(it != lista_clauze[i].end())
                                ss <<",";

                        }
                        ss <<"} cu clauza ";
                        ss <<"{";
                        it = lista_clauze[j].begin();
                        while(it != lista_clauze[j].end())
                        {
                            ss << *it;
                            it++;
                            if(it != lista_clauze[j].end())
                                ss <<",";

                        }
                        ss <<"} am obtinut clauza {}" <<'\n';

                        ss << '\n' <<"Propozitia este nesatisfiabila";

                        set <string> a;
                        a.insert("eroare");
                        set_clauze.insert(a);

                        return;
                    }

                    if(set_clauze.find(set2) == set_clauze.end())
                    {
                        ss << '\n' <<"Combinand clauza ";
                        set <string>::iterator it;
                        it = lista_clauze[i].begin();
                       ss <<"{";
                        while(it != lista_clauze[i].end())
                        {
                            ss   << *it;
                            it++;
                            if(it != lista_clauze[i].end())
                               ss <<",";

                        }
                        ss <<"} cu clauza ";
                        ss <<"{";
                        it = lista_clauze[j].begin();
                        while(it != lista_clauze[j].end())
                        {
                            ss << *it;
                            it++;
                            if(it != lista_clauze[j].end())
                                ss <<",";

                        }
                        ss <<"} am obtinut clauza ";
                        ss <<"{";
                        it = set2.begin();
                        while(it != set2.end())
                        {
                            ss << *it;
                            it++;
                            if(it != set2.end())
                                ss <<",";

                        }
                        ss <<"}\n";

                        set_clauze.insert(set2);
                        lista_clauze.push_back(set2);

                        if(set2.size() == 1)
                        {
                            string l_c;

                            for(auto it:set2)
                                if(it[0] == '!')
                                    for(int p = 1; p < it.size();p++)
                                        l_c.push_back(it[p]);
                                else
                                    l_c = "!" + it;

                            set <string> set3;
                            set3.insert(l_c);

                            if(set_clauze.find(set3) != set_clauze.end())
                            {
                                string l_pc = *set2.begin();
                                ss << '\n' <<"Combinand clauza {";
                                ss << l_pc <<"} cu clauza ";
                                ss << "{" << l_c <<"} am obtinut clauza {}" <<'\n';

                                ss << '\n' <<"Propozitia este nesatisfiabila";
                                set <string> a;
                                a.insert("eroare");
                                set_clauze.insert(a);
                                return;
                            }
                        }
                    }

                }



            }
        }

}

set <string> get_literali_cu_negatie(string s)
{
    set <string> set2;

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] != '&' && s[i] != '|' && s[i] != '(' && s[i] != ')')
        {
            string s2;
            s2.push_back(s[i]);
            i++;
            while(i < s.size() && s[i] != '&' && s[i] != '|' && s[i] != '(' && s[i] != ')')
            {
                s2.push_back(s[i]);
                i++;
            }
            set2.insert(s2);
        }
    }

    return set2;
}


void regula_clauzei_cu_un_literar(set < set <string> > &set_clauze,int &modif,set <string> &set_literali_cu_negatie, int& ok, ostream& ss)
{
    modif = 0;
    int nrop = 0;
    set < set < string> >:: iterator it;
    bool okd = true;


    for(it = set_clauze.begin(); it != set_clauze.end(); it++)
    {
        if(okd == false)
        {
            it = set_clauze.begin();
            okd = true;
        }
        set <string > set2 = *it;
        if(set2.size() == 1)
        {
            okd = false;
            nrop++;
            string s2 = *set2.begin();
            ss <<'\n'<< "Aplicand regula clauzei cu un literal pentru literalul " << s2 <<" am obtinut setul nou de clauze ";
            string complementar;

            if(s2[0] == '!')
                for(int i = 1; i < s2.size(); i++)
                    complementar.push_back(s2[i]);
            else
                {
                    complementar.push_back('!');
                    complementar = complementar + s2;
                }


            vector < set <string> > eliminare;
            vector < set <string> > toadd;
            set < set <string> >:: iterator it2;

            for(it2 = set_clauze.begin(); it2 != set_clauze.end(); it2++)
            {
                set <string > set3 = *it2;
                if(set3.find(complementar) != set3.end())
                {
                    set < string > erase3;
                    for(auto it3:set3)
                        erase3.insert(it3);

                    eliminare.push_back(erase3);
                    set3.erase(complementar);

                    set < string > toaddd;
                    for(auto it3:set3)
                        toaddd.insert(it3);
                    toadd.push_back(toaddd);


                }
                if(set3.size() == 0)
                {
                    ss << '\n' <<"Formula nu este satisfiabila";
                    ok = 0;
                    return;
                }

                if(set3.find(s2) != set3.end())
                {
                    eliminare.push_back(set3);

                }

            }

            for(int i = 0; i < eliminare.size(); i++)
                set_clauze.erase(eliminare[i]);

            for(int i = 0; i < toadd.size(); i++)
            {
                set_clauze.insert(toadd[i]);
            }

            ss <<"{";
            set < set <string> >:: iterator it4 = set_clauze.begin();
            while(it4!=set_clauze.end())
            {
                set <string> p = *it4;
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
                it4++;
                if(it4 != set_clauze.end())
                ss <<",";
            }
            ss <<"}";
            ss <<'\n';

            if(set_clauze.size() == 0)
            {
                ss << '\n' <<"Formula este satisfiabila";
                ok = 1;
                return;
            }
        }

    }

    set_literali_cu_negatie.clear();

    for(auto it:set_clauze)
        for(auto it2:it)
            set_literali_cu_negatie.insert(it2);

    if(set_clauze.size() == 0)
    {
        ss << '\n' <<"Formula este satisfiabila";
        ok = 1;
        return;
    }


    if(nrop != 0 )
    {
        modif = 1;
        ss <<'\n'<<'\n';
    }
    else
    {
        modif = 0;
    }

}

void regula_literalului_pur(set < set <string> > &set_clauze,int &modif,set <string> &set_literali_cu_negatie, int&ok, ostream& ss)
{
    int nrop = 0;

    vector <string> erase2;
    set <string>::iterator it;
    it = set_literali_cu_negatie.begin();
    while(it !=set_literali_cu_negatie.end())
    {
        string f = *it;
        string complementar;

        if(f[0] == '!')
            for(int i = 1; i < f.size(); i++)
                complementar.push_back(f[i]);
        else
            complementar = "!" + f;

        if(set_literali_cu_negatie.find(complementar) == set_literali_cu_negatie.end())
        {
            ss <<"Aplicand regula literalului pur pentru literalul " << f <<" obtinem setul de clauze ";
            nrop++;
            vector < set <string> > eliminare;

            for(auto it2:set_clauze)
            {
                if(it2.find(f) != it2.end())
                    eliminare.push_back(it2);
            }

            for(int i = 0; i < eliminare.size(); i++)
                set_clauze.erase(eliminare[i]);

            set_literali_cu_negatie.clear();
            ss <<"{";
            set < set <string> >:: iterator it4 = set_clauze.begin();
            while(it4!=set_clauze.end())
            {
                set <string> p = *it4;
                ss <<"{";
                set <string> ::iterator it2 = p.begin();
                while(it2 != p.end())
                {
                    string f2 = *it2;
                    set_literali_cu_negatie.insert(f2);
                    ss << *it2;
                    it2++;
                    if(it2 != p.end())
                        ss <<",";
                }
                ss <<"}";
                it4++;
                if(it4 != set_clauze.end())
                ss <<",";
            }
            ss <<"}";
            ss <<'\n';

            it = set_literali_cu_negatie.begin();

            if(set_clauze.size() == 0)
            {
                ss << '\n' <<"Formula este satisfiabila";
                ok = 1;
                return;
            }

        }
        else
            it++;


    }

    if(nrop == 0)
        modif = 0;
    else
        {
            modif = 1;
            ss <<'\n'<<'\n';
        }
}



void aplica_regula_1_si_2(set < set < string> > &set_clauze ,set <string> &set_literali_cu_negatie,int &modif2, int& ok, ostream&ss)
{
    int modif = 1;

    while(modif != 0)
    {
            regula_clauzei_cu_un_literar(set_clauze,modif,set_literali_cu_negatie, ok, ss);
            if(modif != 0)
                modif2 = 1;
            regula_literalului_pur(set_clauze,modif,set_literali_cu_negatie, ok, ss);

            if(modif != 0)
                modif2 = 1;
    }
}

void combina_clauzele2(set < set < string> > set_clauze ,set <string> set_literali_cu_negatie, int &ok, ostream& ss)
{

    vector < set <string> > lista_clauze;


    for(auto it:set_clauze)
        lista_clauze.push_back(it);

    set < set < string > > ::iterator it3;
    set < set < string > > ::iterator it4;


    for(it3 = set_clauze.begin();it3 != set_clauze.end(); it3++)
        for(it4 = set_clauze.begin();it4 != set_clauze.end(); it4++)
        {

            int modif2 = 0;
            aplica_regula_1_si_2(set_clauze,set_literali_cu_negatie,modif2, ok, ss);
            if(modif2 == 1)
            {
                if(set_clauze.size() == 0)
                    break;
                else
                {
                    it3 = set_clauze.begin();
                    it4 = set_clauze.begin();
                }
            }

            set < string> set_1 = *it3;
            set <string> set_2 = *it4;

            if(set_1 != set_2)
            {
                int cnt_literali_complementari = 0;
                string literal_complementar;
                for(auto it:set_1)
                {
                    string l_c;
                    if(it[0] == '!')
                        for(int i = 1; i < it.size(); i++)
                            l_c.push_back(it[i]);
                    else
                        l_c = "!" + it;


                    if(set_2.find(l_c) != set_2.end())
                    {
                        cnt_literali_complementari++;
                        literal_complementar = l_c;
                    }
                }

                if(cnt_literali_complementari == 1)
                {

                    set <string> set2;

                    for(auto it:set_1)
                        set2.insert(it);

                    for(auto it:set_2)
                        set2.insert(it);

                    set2.erase(literal_complementar);
                    string l_c_2;
                    if(literal_complementar[0] == '!')
                    {
                        for(int j = 1 ; j < literal_complementar.size(); j++)
                            l_c_2.push_back(literal_complementar[j]);
                        literal_complementar = l_c_2;
                    }
                    else
                        literal_complementar = "!" + literal_complementar;
                    set2.erase(literal_complementar);


                    if(set2.size() == 0)
                    {
                        ss <<"Combinand clauza ";

                        set <string>::iterator it5;
                        it5 = set_1.begin();
                        ss <<"{";
                        while(it5 != set_1.end())
                        {
                            ss << *it5;
                            it5++;
                            if(it5 != set_1.end())
                                ss <<",";
                        }
                        ss <<"}";
                        ss <<" cu clauza ";
                        it5 = set_2.begin();
                        ss <<"{";
                        while(it5 != set_2.end())
                        {
                            ss << *it5;
                            it5++;
                            if(it5 != set_2.end())
                                ss <<",";
                        }
                        ss <<"}";
                        ss <<" am obtinut setul de clauza ";

                        ss <<"{}";

                        ss << '\n' <<"Propozitia este nesatisfiabila";
                         ok = 0;
                         return;
                    }

                    if(set_clauze.find(set2) == set_clauze.end())
                    {
                        ss <<"Combinand clauza ";

                        set <string>::iterator it5;
                        it5 = set_1.begin();
                        ss <<"{";
                        while(it5 != set_1.end())
                        {
                            ss << *it5;
                            it5++;
                            if(it5 != set_1.end())
                                ss <<",";
                        }
                        ss <<"}";
                        ss <<" cu clauza ";
                        it5 = set_2.begin();
                        ss <<"{";
                        while(it5 != set_2.end())
                        {
                            ss << *it5;
                            it5++;
                            if(it5 != set_2.end())
                                ss <<",";
                        }
                        ss <<"}";
                        ss <<" am obtinut setul de clauza ";
                        it5 = set2.begin();
                        ss <<"{";
                        while(it5 != set2.end())
                        {
                            ss << *it5;
                            it5++;
                            if(it5 != set2.end())
                                ss <<",";
                        }
                        ss <<"}\n";

                        set_clauze.insert(set2);
                        lista_clauze.push_back(set2);

                        if(set2.size() == 1)
                        {
                            string l_c;

                            for(auto it:set2)
                                if(it[0] == '!')
                                    for(int i = 1; i < it.size(); i++)
                                        l_c.push_back(it[i]);
                                else
                                    l_c = "!" + it;

                            set <string> set3;
                            set3.insert(l_c);

                            if(set_clauze.find(set3) != set_clauze.end())
                            {
                                ss <<"Combinand clauza {" << *set2.begin() << "} cu clauza {" << *set3.begin() <<"} am obtinut clauza {}";
                                ss << '\n' <<"Propozitia este nesatisfiabila";
                                ok = 0;
                                return;
                            }
                        }
                    }

                }



            }
        }
        ok = 1;

}



void rezolutie_propozitionala2(set < set < string> > set_clauze ,set <string> set_literali_cu_negatie, int &ok, ostream& ss)
{
    combina_clauzele2(set_clauze,set_literali_cu_negatie, ok, ss);
    if(ok == 1)
        ss << '\n' <<"Formula este satisfiabila";
}

void regula_clauzei_cu_un_literar2(set < set <string> > &set_clauze,int &modif,set <string> &set_literali_cu_negatie, int&ok, ostream& ss)
{
    modif = 1;
    int nrop = 0;
    set < set < string> >:: iterator it;
    bool okd = true;

    for(it = set_clauze.begin(); it != set_clauze.end(); it++)
    {
        if(okd == false)
        {
            it = set_clauze.begin();
            okd = true;
        }
        set <string > set2 = *it;
        if(set2.size() == 1)
        {
            okd = false;
            nrop++;
            string s2 = *set2.begin();
            ss <<'\n'<< "Aplicand regula clauzei cu un literal pentru literalul " << s2 <<" am obtinut setul nou de clauze ";

            string complementar;

            if(s2[0] == '!')
                for(int i = 1; i < s2.size(); i++)
                    complementar.push_back(s2[i]);
            else
                {
                    complementar.push_back('!');
                    complementar = complementar + s2;
                }


        vector < set <string> > eliminare;
        vector < set <string> > toadd;
        set < set <string> >:: iterator it5;

        for(it5 = set_clauze.begin(); it5 != set_clauze.end(); it5++)
        {
            set <string > set3 = *it5;
            if(set3.find(complementar) != set3.end())
            {
                set < string > erase3;
                for(auto it3:set3)
                    erase3.insert(it3);
                eliminare.push_back(erase3);

                set3.erase(complementar);

                set < string > toaddd;
                for(auto it3:set3)
                    toaddd.insert(it3);
                toadd.push_back(toaddd);


            }
            if(set3.size() == 0)
            {
                modif = 2;
            }

            if(set3.find(s2) != set3.end())
            {
                eliminare.push_back(set3);

            }

        }

        for(int i = 0; i < eliminare.size(); i++)
            set_clauze.erase(eliminare[i]);

        for(int i = 0; i < toadd.size(); i++)
        {
            set_clauze.insert(toadd[i]);
        }

        ss <<"{";
        set < set <string> >:: iterator it4 = set_clauze.begin();
        while(it4!=set_clauze.end())
        {
            set <string> p = *it4;
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
            it4++;
            if(it4 != set_clauze.end())
            ss <<",";
        }
        ss <<"}";
        ss <<'\n';

        if(set_clauze.size() == 0)
        {
                ss <<"Pe una dintre ramurile DPLL s-a obtinut setul de clauze {}\n";
                ss << '\n' <<"Formula este satisfiabila";
                ok = 1;
                return;
        }
        }

    }

    set_literali_cu_negatie.clear();

    for(auto it:set_clauze)
        for(auto it2:it)
            set_literali_cu_negatie.insert(it2);

    if(set_clauze.size() == 0)
    {
        ss <<"Pe una dintre ramurile DPLL s-a obtinut setul de clauze {}\n";
        ss << '\n' <<"Formula este satisfiabila";
        ok = 1;
        return;
    }


    if(nrop != 0 && modif != 2)
    {
        modif = 1;
        ss <<'\n';
    }
    else
    if(modif != 2)
    {
        modif = 0;
    }


}

void regula_literalului_pur2(set < set <string> > &set_clauze,int &modif,set <string> &set_literali_cu_negatie, int &ok, ostream& ss)
{

    int nrop = 0;

    set <string>::iterator it;

    it = set_literali_cu_negatie.begin();

    while(it != set_literali_cu_negatie.end())
    {
        string f = *it;

        string complementar;

        if(f[0] == '!')
            for(int i = 1; i < f.size(); i++)
                complementar.push_back(f[i]);
        else
            complementar = "!" + f;

        if(set_literali_cu_negatie.find(complementar) == set_literali_cu_negatie.end())
        {
            ss <<"Aplicand regula literalului pur " << f <<" am obtinut setul de clauze ";
            nrop++;

            vector < set <string> > eliminare;

            for(auto it2:set_clauze)
            {
                if(it2.find(f) != it2.end())
                    eliminare.push_back(it2);
            }
            set_literali_cu_negatie.clear();



            for(int i = 0; i < eliminare.size(); i++)
                set_clauze.erase(eliminare[i]);

            ss <<"{";
            set < set <string> >:: iterator it4 = set_clauze.begin();
            while(it4!=set_clauze.end())
            {
                set <string> p = *it4;
                ss <<"{";
                set <string> ::iterator it2 = p.begin();
                while(it2 != p.end())
                {
                    string f2 = *it2;
                    set_literali_cu_negatie.insert(f2);
                    ss << *it2;
                    it2++;
                    if(it2 != p.end())
                        ss <<",";
                }
                ss <<"}";
                it4++;
                if(it4 != set_clauze.end())
                ss <<",";
            }
            ss <<"}";
            ss <<'\n';

            it = set_literali_cu_negatie.begin();

        }
        else
            it++;

    }


    if(set_clauze.size() == 0)
    {
        ss <<"Pe una dintre ramurile DPLL s-a obtinut setul de clauze {}\n";
        ss << '\n' <<"Formula este satisfiabila";
        ok = 1;
        return;
    }

    if(nrop == 0)
        modif = 0;
    else
        {
            modif = 1;
            ss <<'\n';
        }

}


void aplica_regula_1_si_2_2(set < set < string> > &set_clauze ,set <string> &set_literali_cu_negatie,int &modif2, int &ok, ostream&ss)
{
    int modif = 1;
    modif2 = 1;


    while(modif != 0)
    {
        regula_clauzei_cu_un_literar2(set_clauze,modif,set_literali_cu_negatie, ok, ss);


        if(modif == 2)
        {
            modif = 0;
            modif2 = 0;
        }
        else
            regula_literalului_pur2(set_clauze,modif,set_literali_cu_negatie, ok, ss);


    }

}


void impartire_dupa_literali(set <string> set_literali_cu_negatie, set < set <string> > set_clauze, int &ok, ostream& ss)
{

    if(ok != -1)
        return;

    ss <<"Setul curent de clauze este:";
    ss <<"{";
    set < set <string> >:: iterator it4 = set_clauze.begin();
    while(it4!=set_clauze.end())
    {
        set <string> p = *it4;
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
        it4++;
        if(it4 != set_clauze.end())
            ss <<",";
    }
    ss <<"}";
    ss <<'\n';

    set <string> set_literali_cu_negatie1 = set_literali_cu_negatie;
    set < set <string> > set_clauze1 = set_clauze;
    set <string> set_literali_cu_negatie2 = set_literali_cu_negatie;
    set < set <string> > set_clauze2 = set_clauze;
    set < string>::iterator it = set_literali_cu_negatie.begin();

    string literal = *it;


    ss <<"Se aplica regula de impartire dupa literalul " << literal << " obtinanduse noile seturi de clauze: ";

    string complementar;

    if(literal[0] == '!')
        for(int i = 1; i < literal.size(); i++)
            complementar.push_back(literal[i]);
    else
        complementar = "!" + literal;

    set <string> f;
    f.insert(complementar);
    set_literali_cu_negatie2.insert(complementar);
    set_clauze2.insert(f);
    int modif2;

    ss <<"{";
    it4 = set_clauze2.begin();
    while(it4!=set_clauze2.end())
    {
        set <string> p = *it4;
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
        it4++;
        if(it4 != set_clauze2.end())
            ss <<",";
    }
    ss <<"}";
    ss <<" si ";

    f.clear();
    f.insert(literal);
    set_clauze1.insert(f);

    ss <<"{";
    it4 = set_clauze1.begin();
    while(it4!=set_clauze1.end())
    {
        set <string> p = *it4;
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
        it4++;
        if(it4 != set_clauze1.end())
            ss <<",";
    }
    ss <<"}";
    ss <<'\n';

    ss <<"Se incearca aplicarea regulilor 1 si 2 asupra noilor seturi de clauze\n";

    aplica_regula_1_si_2_2(set_clauze2,set_literali_cu_negatie2,modif2, ok, ss);
    aplica_regula_1_si_2_2(set_clauze1,set_literali_cu_negatie1,modif2, ok, ss);



    if(modif2 != 0)
    {
        ss <<"Problema satisfiabilitatii primului set de clauze nu a fost inca rezolvata deci aplicam din nou DPLL pentru noul set de clauze\n";
        impartire_dupa_literali(set_literali_cu_negatie2,set_clauze2, ok, ss);

    }
    else

    if(modif2 != 0)
    {
        ss <<"Problema satisfiabilitatii celui deal doilea set de clauze nu a fost inca rezolvata deci aplicam din nou DPLL pentru noul set de clauze\n";
        impartire_dupa_literali(set_literali_cu_negatie1,set_clauze1, ok, ss);
    }


}


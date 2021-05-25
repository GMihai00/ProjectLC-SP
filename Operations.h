#ifndef OPERATIONS_H_INCLUDED
#define OPERATIONS_H_INCLUDED

#include <bits/stdc++.h>

using namespace std;



int op1(int );

int op2(int , int );

int op3(int , int );

int op4(int , int );

int op6(int , int );

string transformare_structura_relaxata_in_structura_stricta(string = "", map <string, int> = {{"!", 5}, {"&", 4}, {"|", 3}, {">", 2}, {"~", 1}});

string reducere1(string );
string reducere2(string );
string De_Morgan(string );
pair <int,int> conector_semnificiativ(string );
pair <int,int> conector_semnificiativ2(string );
string distributivitate1(string );
string distributivitate2(string );
void combina_clauzele(set < set <string> > &);
void rezolutie_propozitionala2(set < set < string> >  ,set <string> , int &);
void combina_clauzele2(set < set < string> >  ,set <string> , int &);
void aplica_regula_1_si_2(set < set < string> > & ,set <string> &,int &, int&);
void regula_literalului_pur(set < set <string> > &,int &,set <string> &, int&);
void regula_clauzei_cu_un_literar(set < set <string> > &,int &,set <string> &, int&);
set <string> get_literali_cu_negatie(string );
void regula_clauzei_cu_un_literar2(set < set <string> > &,int &,set <string> &, int&);
void regula_literalului_pur2(set < set <string> > &,int &,set <string> &, int&);
void aplica_regula_1_si_2_2(set < set < string> > & ,set <string> &,int &, int&);
void impartire_dupa_literali(set <string> , set < set <string> > , int&);


#endif // OPERATIONS_H_INCLUDED

#ifndef OPERATIONS_H_INCLUDED
#define OPERATIONS_H_INCLUDED

#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>

using namespace std;


// operatia not
int op1(int );
// operatia si
int op2(int , int );
// operatia sau
int op3(int , int );
// operatia implicatie
int op4(int , int );
// operatia implicatie dubla
int op6(int , int );

// transforma o prop din structura relaxata in structura stricta si verifica daca este bine formata
string transformare_structura_relaxata_in_structura_stricta(string = "",  map <string, int> = {{"!", 5}, {"&", 4}, {"|", 3}, {">", 2}, {"~", 1}}, ostream& = cout);

// reguli de reducere
string reducere1(string ,ostream&);
string reducere2(string , ostream&);

// De Morgan
string De_Morgan(string , ostream&);

// determina conectorul cel mai semnificativ dintro formula prop.
pair <int,int> conector_semnificiativ(string );
pair <int,int> conector_semnificiativ2(string );

// distributivitate si fata de sau | sau fata de si
string distributivitate1(string , ostream&);
string distributivitate2(string , ostream&);

// combinarea clauzelor rezoluite, DP,DPLL
void combina_clauzele(set < set <string> > &, ostream&);
void rezolutie_propozitionala2(set < set < string> >  ,set <string> , int &, ostream&);
void combina_clauzele2(set < set < string> >  ,set <string> , int &, ostream&);
// reguli specifice rezolutie, DP, DPLL
void aplica_regula_1_si_2(set < set < string> > & ,set <string> &,int &, int&, ostream&);
void regula_literalului_pur(set < set <string> > &,int &,set <string> &, int&);
void regula_clauzei_cu_un_literar(set < set <string> > &,int &,set <string> &, int&);
set <string> get_literali_cu_negatie(string );
void regula_clauzei_cu_un_literar2(set < set <string> > &,int &,set <string> &, int&, ostream&);
void regula_literalului_pur2(set < set <string> > &,int &,set <string> &, int&);
void aplica_regula_1_si_2_2(set < set < string> > & ,set <string> &,int &, int&);
void impartire_dupa_literali(set <string> , set < set <string> > , int&, ostream&);


#endif // OPERATIONS_H_INCLUDED

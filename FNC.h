#ifndef FNC_H_INCLUDED
#define FNC_H_INCLUDED

#include <bits/stdc++.h>
#include "Operations.h"
#include "Fprop.h"
#include "Arbore.h"
#include "FNN.h"

using namespace std;

class FNC : public FNN
{
private:

    set < set <string> > clauze;


public:


     //Transformare din Fprop in FNC
     void transformare_in_FNC(ostringstream& );
     // updateaza setul de clauze
     void update_clauze();
     void build_formula_from_clauze(); //WIP//
     //DP , DPLL, rezolutie //
     void rezolutie(ostringstream& );
    void DP(ostringstream&);
    void DPLL(ostringstream& );
    // constructori//
    FNC(set <set <string> > = { { {} } }, string = "",Arbore* = NULL);





};

#endif // FNC_H_INCLUDED

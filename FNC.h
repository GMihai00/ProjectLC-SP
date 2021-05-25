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
    // date + alea mostenite, modificare formula doar //

public:

    // mostenire FNN //
    // getere //

    // setare //

     // operatii specifice //

     void transformare_in_FNC();
     void update_clauze();
     void build_formula_from_clauze(); //WIP//
     //DP , DPLL, rezolutie //
     void rezolutie();

    // constructori//
    FNC(set <set <string> > = { { {} } }, string = "",Arbore* = NULL);
    void DP();
    void DPLL();




};

#endif // FNC_H_INCLUDED

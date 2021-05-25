#ifndef FNN_H_INCLUDED
#define FNN_H_INCLUDED

#include <bits/stdc++.h>
#include "Operations.h"
#include "Fprop.h"
#include "Arbore.h"

using namespace std;

class FNN : public Fprop
{
public:
     // operatii specifice //
     void transformareFNN();
     virtual void transformare_in_FND();
     virtual void transformare_in_FNC();

    virtual void update_clauze();
    virtual void build_formula_from_clauze();

    virtual void rezolutie();

    virtual void DP();
    virtual void DPLL();
    // constructori//
    FNN(string = "",Arbore* = NULL);
};

#endif // FNN_H_INCLUDED

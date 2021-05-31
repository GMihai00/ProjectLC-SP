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
     //Transformare din Fprop in FNN
     void transformareFNN(ostringstream& );
     //Transformare din Fprop in FND
     virtual void transformare_in_FND();
     //Transformare din Fprop in FNC
     virtual void transformare_in_FNC();

    // actualizeaza setul de clauze
    virtual void update_clauze();

    virtual void build_formula_from_clauze(); // WIP

    virtual void rezolutie();
    // DP
    virtual void DP();
    // DPLL
    virtual void DPLL();

    FNN(string = "",Arbore* = NULL);
};

#endif // FNN_H_INCLUDED

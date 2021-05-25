#ifndef FPROP_H_INCLUDED
#define FPROP_H_INCLUDED

#include <bits/stdc++.h>
#include "Arbore.h"

using namespace std;



class Arbore;

class Fprop
{
    // relatie Arbore, fiecare formula are un arbore  //
protected:

    string formula;
    int validitate; // by default ramane pe -1 , se actualizeaza la calcul //
    int satisfiabilitate; // by default rame pe -1, se actualizeaza la calcul//
    Arbore *arb;
    set <string> literali;

public:
    // getere //
    string getformula();
    bool getvaliditate();
    bool getsatisfiabilitate();
    Arbore* getarbore();
    virtual  void transformareFNN();
    virtual  void transformare_in_FND();
    virtual  void transformare_in_FNC();
    // setare //
    void setformula(string);
    void setarbore(Arbore*);

    // operatii specifice //
    void update_arbore();
    bool det_arb_val_interpretare(map <string, int>) const;
    void update_literali();
    bool verif_is_in_set(string);
    int get_size_literali();
    virtual void update_satisfiabilitate();
    virtual void update_validitate();
    friend bool echivalent(const Fprop&, const Fprop&);
    friend void bt_fprop(int ,map <string, int>,  Node*,const Fprop&, bool &, set <string> );

    // constructori //
    Fprop(string = "",Arbore* = NULL);
    // deconstructori //
    virtual ~Fprop();


    virtual void update_clauze();
    virtual void build_formula_from_clauze();

    virtual void rezolutie();

    virtual void DP();
    virtual void DPLL();
     static  int nr_formule_propozitionale; // initial 0, pt a tine evidenta mai bine , mai intai fa doar cu una //
};


#endif // FPROP_H_INCLUDED

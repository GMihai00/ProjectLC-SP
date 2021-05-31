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
    // returneaza formula
    string getformula();
    // returneaza validitatea
    bool getvaliditate();
    // returneaza satisfiabilitatea
    bool getsatisfiabilitate();
    // returneaza aroborele formulei
    Arbore* getarbore();
    virtual  void transformareFNN(ostringstream&);
    virtual  void transformare_in_FND(ostringstream&);
    virtual  void transformare_in_FNC(ostringstream&);

    // updateaza formula
    void setformula(string, ostream&);
    // updateaza arborele
    void setarbore(Arbore*);

    // construieste arborele corespunzator formulei curente
    void update_arbore();
    // determina valoarea sub o anumita interpretare a formulei prop
    bool det_arb_val_interpretare(map <string, int>) const;
    // updateaza setul de literali
    void update_literali();
    // verifica daca un literal este in set
    bool verif_is_in_set(string);
    // returneaza nr de literali
    int get_size_literali();

    virtual void update_satisfiabilitate();
    virtual void update_validitate();
    // verifica daca doua formule sunt echivaletne
    friend bool echivalent(const Fprop&, const Fprop&);
    // back pe set literali
    friend void bt_fprop(int ,map <string, int>,  Node*,const Fprop&, bool &, set <string> );

    // constructori //
    Fprop(string = "",Arbore* = NULL);
    // deconstructori //
    virtual ~Fprop();


    virtual void update_clauze();
    virtual void build_formula_from_clauze();

    virtual void rezolutie(ostringstream&);

    virtual void DP(ostringstream&);
    virtual void DPLL(ostringstream&);
     static  int nr_formule_propozitionale; // initial 0, pt a tine evidenta mai bine , mai intai fa doar cu una //
};


#endif // FPROP_H_INCLUDED

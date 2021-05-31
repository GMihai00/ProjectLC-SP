#ifndef ARBORE_H_INCLUDED
#define ARBORE_H_INCLUDED

#include <bits/stdc++.h>
#include "Operations.h"

using namespace std;



class Fprop;

typedef struct Node
{
    string key;
    struct Node *left_child, *right_child, *parent;
}Node;


class Arbore
{
protected:
    Node* root;
    int height;
public:

    // returneaza radacina arborelui
    Node* get_root() const;

    // construieste arborele pe baza unei formule propozitionale, reprezentate de un string
    void addnodes(string);
    // updateaza inaltimea arborelui, se apeleaza odata cu addnodes
    void update_height(Node* = NULL, int = 1);

    // afiseaza arborele
    ostream& Afisare(ostream&);
    Arbore();
    Arbore(const Arbore &);
    ~Arbore();

    Arbore& operator =(const Arbore&);

    // determina valoarea sub interpretare a unei formule prop.
    bool det_val_interpretare(Node* = NULL, map <string, int> ={} ) const;


};


#endif // ARBORE_H_INCLUDED

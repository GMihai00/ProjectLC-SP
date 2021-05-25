#ifndef ARBORE_H_INCLUDED
#define ARBORE_H_INCLUDED

#include <bits/stdc++.h>
#include "Operations.h"

using namespace std;


// arborele se modifica la fiecare in parte !!!!!!!!!!!//
class Fprop; // prototip clasa//

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

    Node* get_root() const;

    void addnodes(string);
    void update_height(Node* = NULL, int = 1);

    ostream& Afisare(ostream&);
    Arbore();
    Arbore(const Arbore &);
    ~Arbore();

    Arbore& operator =(const Arbore&);

    bool det_val_interpretare(Node* = NULL, map <string, int> ={} ) const;


};


#endif // ARBORE_H_INCLUDED

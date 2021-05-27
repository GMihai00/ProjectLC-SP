#include "Fprop.h"

string Fprop::getformula()
{
    return this->formula;
}

bool Fprop::getvaliditate()
{
    return this->validitate;
}

bool Fprop::getsatisfiabilitate()
{
    return this->satisfiabilitate;
}

int Fprop::nr_formule_propozitionale = 0;



void Fprop::setarbore(Arbore* a)
{
    this->arb = a;
}


void Fprop::setformula(string s, ostream& ss)
{
    map <string, int> m = {{"!", 5}, {"&", 4}, {"|", 3}, {">", 2}, {"~", 1}};

     s = transformare_structura_relaxata_in_structura_stricta(s, m, ss);
    this->formula = s;
}

Fprop::Fprop(string s, Arbore* arb)
{
    s = transformare_structura_relaxata_in_structura_stricta(s);
    this->formula = s;
    this->validitate = -1;
    this->satisfiabilitate = -1;
    if(arb == NULL)
        arb = new(Arbore);
    this->arb = new(Arbore);
    this->arb = arb;
    nr_formule_propozitionale++;
}


bool Fprop::verif_is_in_set(string s)
{
    return (this->literali.find(s) != this->literali.end());
}

int Fprop::get_size_literali()
{
    return this->literali.size();
}
void Fprop::update_arbore()
{

    queue <Node*> q;

    q.push(this->arb->get_root());

    while(!q.empty())
    {
        Node* f = q.front();
        q.pop();

        if(f != NULL)
        {
            if(f->right_child != NULL)
                q.push(f->right_child);
            if(f->left_child != NULL)
                q.push(f->left_child);

        }
        if(f != this->arb->get_root())
            delete f;

    }

    this->arb->addnodes(this->formula);
    this->arb->update_height(this->arb->get_root());

}

bool Fprop::det_arb_val_interpretare(map <string, int> m ) const
{
    return this->arb->det_val_interpretare(this->arb->get_root(), m);
}

Arbore* Fprop::getarbore()
{
    return this->arb;
}

void Fprop::update_literali()
{
    Node* root = this->arb->get_root();

    queue <Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* cur = q.front();
        q.pop();

        if(cur != NULL)
            if(cur->left_child == NULL && cur->right_child == NULL)
                this->literali.insert(cur->key);
            else
            {
                if(cur->left_child != NULL)
                    q.push(cur->left_child);
                if(cur->right_child != NULL)
                    q.push(cur->right_child);

            }

    }
}

void bt_fprop(int k,map <string, int> m,  Node* root,const Fprop& x, bool &ok, set <string> s)
{
    if(ok == false)

        return;


    set <string>::iterator it;


    if(k == s.size())
    {
        ok = x.arb->det_val_interpretare(root, m);
    }
    else
    {



        it = s.begin();
        advance(it, k);
        for(int i = 0; i <= 1; i++)
        {
            if(m[*it] == -1)
            {
                m[*it] = i;
                bt_fprop(k + 1, m, root, x, ok, s);
                m[*it] = -1;
            }
        }
    }

}

void Fprop::update_satisfiabilitate()
{

    int k = 0;
    bool ok = true;

    map <string, int> m;
    for(auto it : this->literali)
        m[it] = -1;


    Node* newnode = new Node;
    newnode->right_child = this->arb->get_root();
    newnode->key = "!";

    bt_fprop(k, m, newnode, *this, ok, this->literali);
    delete newnode;

    if(ok == false)
        this->satisfiabilitate = 1;
    else
        this->satisfiabilitate = 0;




}

void Fprop::update_validitate()
{
    int k = 0;
    bool ok = true;

    map <string, int> m;
    for(auto it : this->literali)
        m[it] = -1;



    bt_fprop(k, m, this->arb->get_root(), *this, ok, this->literali);

     if(ok == false)
        this->validitate = 0;
    else
        this->validitate = 1;



}
void Fprop::transformareFNN(ostringstream&)
{
    return;
}
void Fprop::transformare_in_FNC(ostringstream&)
{
    return;
}
void Fprop::transformare_in_FND(ostringstream&)
{
    return;
}

void Fprop::update_clauze()
{
    return;
}
void Fprop::build_formula_from_clauze()
{
    return;
}

void Fprop::rezolutie(ostringstream&)
{
    return;
}

void Fprop::DP(ostringstream&)
{
    return;
}
void Fprop::DPLL(ostringstream&)
{
    return;
}

bool echivalent(const Fprop &x, const Fprop &y)
{

    set <string> s;

    for(auto it: x.literali)
        s.insert(it);
    for(auto it: y.literali)
        s.insert(it);

    int k = 0;
    bool ok = true;

    map <string, int> m;
    for(auto it : s)
        m[it] = -1;

    Node* newnode = new Node;
    newnode->left_child = x.arb->get_root();
    newnode->right_child = y.arb->get_root();
    newnode->key = "~";

    bt_fprop(k, m, newnode, x, ok, s);
    delete newnode;
    return ok;
}


Fprop::~Fprop()
{
    // apeleaza cumva deconstructor arbore //

    free(this->arb);
    nr_formule_propozitionale--;
}


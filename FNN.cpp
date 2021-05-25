#include "FNN.h"


FNN::FNN(string s, Arbore* a):Fprop(s, a)
{

}

void FNN::transformareFNN()
{
    string forma_intermediara;
    forma_intermediara = this->formula;
    forma_intermediara = reducere1(forma_intermediara);
    forma_intermediara = reducere2(forma_intermediara);
    forma_intermediara = De_Morgan(forma_intermediara);

    this->formula = forma_intermediara;
}


void FNN::transformare_in_FNC()
{
    return;
}
void FNN::transformare_in_FND()
{
    return;
}

void FNN::update_clauze()
{
    return;
}
void FNN::build_formula_from_clauze()
{
    return;
}

void FNN::rezolutie()
{
    return;
}

void FNN::DP()
{
    return;
}
void FNN::DPLL()
{
    return;
}

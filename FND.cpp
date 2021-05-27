#include "FND.h";

FND::FND(string s,Arbore* a):FNN(s, a)
{
    return;
}

void FND::transformare_in_FND(ostringstream& ss)
{
    this->transformareFNN(ss);
    string forma_intermediara = this->formula;
    forma_intermediara = distributivitate2(forma_intermediara, ss);
    this->formula = forma_intermediara;
}


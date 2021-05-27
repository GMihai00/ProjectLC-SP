#ifndef FND_H_INCLUDED
#define FND_H_INCLUDED

#include <bits/stdc++.h>
#include "Operations.h"
#include "Fprop.h"
#include "Arbore.h"
#include "FNN.h"

using namespace std;

class FND : public FNN
{

public:
     // operatii specifice //
    void transformare_in_FND(ostringstream& );

    // constructori//
    FND(string = "",Arbore* = NULL);

    // deconstructori //

};


#endif // FND_H_INCLUDED

#include "Arbore.h"
#include "Operations.h"


Arbore::Arbore(const Arbore& a)
{
    this->root = new(Node);
    this->root->key = a.root->key;
    this->root->right_child = a.root->right_child;
    this->root->left_child = a.root->left_child;
    this->root->parent = a.root->parent;
    this->height = 0;
}

Arbore::Arbore()
{
    this->root = new(Node);
    this->root = NULL;
    this->height = 0;

}

Arbore::~Arbore()
{

    queue <Node*> q;

    q.push(this->root);

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

        delete f;

    }

}

Arbore& Arbore::operator=(const Arbore& a)
{

    this->root->key = a.root->key;
    this->root->right_child = a.root->right_child;
    this->root->left_child = a.root->left_child;
    this->root->parent = a.root->parent;
    this->height = a.height;

    return *this;

}
Node* Arbore::get_root() const
{
    return this->root;
}


void Arbore::addnodes(string s)
{

    stack < Node* > stnodes;
    stack <string> st;
    int cntp = 0;


    Node* lastnode = new(Node);
    string cpy;

    for(int i = 0; i < s.size(); i++)
    {


        if(s[i] == ' ')
            continue;

        if(s[i] == '(')
        {
            cntp++;
            cpy.push_back(s[i]);
            st.push(cpy);
            cpy.clear();


        }
        else
        if(s[i] != ')')
        {

            Node* newn = new(Node);

            if(s[i] == '&' || s[i] == '|' || s[i] == '>' || s[i] == '~' || s[i] == '!')
                cpy.push_back(s[i]);
            else
            {


                while(!(i == s.size() || s[i] == ')' || s[i] == '&' || s[i] == '|' || s[i] == '>' || s[i] == '~' || s[i] == '!'))
                {
                    if(s[i] != ' ')
                        cpy.push_back(s[i]);
                    i++;

                }
                i--;
            }
            newn->key = cpy;
            newn->left_child = NULL;
            newn->right_child = NULL;
            newn->parent = NULL;
            stnodes.push(newn);
            st.push(cpy);
            cpy.clear();
        }
        else
        {
            cntp--;


            if(cntp < 0)
            {
                cout <<"1";
                throw "Prop nu esti bine formata";
                exit(0);
            }

            if(st.empty())
            {
                cout <<"2";
                cout << '\n' <<"Prop nu esti bine formata";
                exit(0);
            }
            cpy = st.top();
            st.pop();


            if(cpy == "&" || cpy == "|" || cpy == "!" || cpy == ">" || cpy == "~" || cpy == "(")
            {
                cout << "3";
                cout << '\n' <<"Prop nu esti bine formata";
                exit(0);
            }


            if(st.empty())
            {
                cout << "4";
                cout << '\n' <<"Prop nu esti bine formata";
                exit(0);
            }
            cpy = st.top();
            st.pop();


            if(!(cpy == "&" || cpy == "|" || cpy == "!" || cpy == ">" || cpy == "~"))
            {
                cout << "5";
                cout << '\n' <<"Prop nu esti bine formata";
                exit(0);
            }

            if(cpy != "!")
            {
                if(st.empty())
                {
                    cout << "6";
                    cout << '\n' <<"Prop nu esti bine formata";
                    exit(0);
                }
                cpy = st.top();
                st.pop();

                if(cpy == "&" || cpy == "|" || cpy == "!" || cpy == ">" || cpy == "~" || cpy == "(")
                {
                    cout << "7";
                    cout << '\n' <<"Prop nu esti bine formata";
                    exit(0);
                }
            }



            if(st.empty())
            {
                cout <<"8";
                cout << '\n' <<"Prop nu esti bine formata";
                exit(0);
            }
            cpy = st.top();
            st.pop();

            if(cpy != "(")
            {
                cout <<"9";
                cout << '\n' <<"Prop nu esti bine formata";
                exit(0);
            }

            st.push("A");

            Node* rchild = stnodes.top();
            stnodes.pop();
            Node* parent = stnodes.top();
            stnodes.pop();
            if(parent->key != "!")
            {
                Node* lchild = stnodes.top();
                stnodes.pop();
                lchild->parent = parent;
                parent->left_child = lchild;
            }

            rchild->parent = parent;
            parent->right_child = rchild;

            stnodes.push(parent);

            if(cpy.size() != 0)
                cpy.clear();
        }


    }

    if(st.size() != 1)
    {
        cout <<"10";
        cout << "Prop nu esti bine formata";
        cout << '\n' <<"Numar insuficient de paranteze inchise";
        exit(0);
    }

    this->root = stnodes.top();

}

bool Arbore::det_val_interpretare(Node* cur, map <string, int> m)const
{

    if(cur->key == "!")
        return(op1(det_val_interpretare(cur->right_child,m)));
    if(cur->key == "&")
        return(op2(det_val_interpretare(cur->left_child,m),det_val_interpretare(cur->right_child,m)));
    if(cur->key == "|")
        return(op3(det_val_interpretare(cur->left_child,m),det_val_interpretare(cur->right_child,m)));
    if(cur->key == ">")
        return(op4(det_val_interpretare(cur->left_child,m),det_val_interpretare(cur->right_child,m)));
    if(cur->key == "~")
        return(op6(det_val_interpretare(cur->left_child,m),det_val_interpretare(cur->right_child,m)));


    if(cur->key == "T")
        return 1;
    if(cur->key == "t")
        return 0;
    return m[cur->key];
}


void Arbore::update_height(Node* cur, int val)
{
    if(cur != NULL)
    {
        this->height = max(this->height, val);
        update_height(cur->left_child, val + 1);
        update_height(cur->right_child, val + 1);
    }

}

ostream& Arbore::Afisare(ostream &ost)
{

    queue <Node*> q;
     vector < Node*> vprint;
     q.push(this->root);

     bool okst = false;
     bool okdr = false;


    int sizenned = 1;
    int heightcur = 1;


     int n;

     int nrtap;
     int nrspaces;
     int gapsamelevel;



    // calculez cat spatiu ocupa subarborele stang//

    //Afisez si NULL si pun toate intr-o coada //
    /*FORMAT
    * * *
    * L *
    * * *
    */
    while(heightcur <= this->height)
    {
        Node* cur = q.front();
        q.pop();


        if(cur != NULL)
        {
            q.push(cur->left_child);
            q.push(cur->right_child);

        }
        else
        {
            q.push(cur);
            q.push(cur);
        }

        vprint.push_back(cur);

        // "/" inseamna null //
        if(vprint.size() == sizenned)
        {
            n = this->height - heightcur;


            nrspaces = ((1 << n) - 1) * 5;
            gapsamelevel = (((1 << (n + 1)) - 1)) * 5;
            nrtap = (((1 << n) - 1) / 2) * 5;





             for(int i = 1; i <=nrspaces; i++)
                        ost <<" ";

             for(int j = 0; j < vprint.size(); j++)
             {

                 if(vprint[j] != NULL)
                        ost <<"* * *";
                 else
                        ost <<"     ";
                 for(int i = 1; i <= gapsamelevel; i++)
                    ost <<" ";


             }

             ost <<"\n\n";

                  for(int i = 1; i <= nrspaces; i++)
                        ost <<" ";
             for(int j = 0; j < vprint.size(); j++)
             {

                 if(vprint[j] == NULL)
                     ost <<"     ";
                else
                     ost <<"* " << vprint[j]->key <<" *";


                 for(int i = 1; i <= gapsamelevel; i++)
                    ost <<" ";


             }

             ost <<"\n\n";

               for(int i = 1; i <= nrspaces - nrtap; i++)
                ost <<" ";




             for(int j = 0; j < vprint.size(); j++)
             {
                if(vprint[j] != NULL)
                {
                    if(vprint[j]->left_child != NULL)
                        for(int i = 1; i <= nrtap; i++)
                            ost <<"-";
                    else
                        for(int i = 1; i <= nrtap; i++)
                            ost <<" ";

                 ost <<"* * *";


                    if(vprint[j]->right_child != NULL)
                        for(int i = 1; i <= nrtap; i++)
                            ost <<"-";
                    else
                        for(int i = 1; i <= nrtap; i++)
                            ost <<" ";
                }
                else
                    for(int i = 1; i <= nrtap *2 + 5; i++)
                        ost <<" ";

                 for(int i = 1; i <= gapsamelevel - 2 * nrtap; i++)
                    ost <<" ";
             }


              ost <<"\n";



             sizenned *=2;
             heightcur++;
             vprint.clear();




        }


    }

  return ost;
}


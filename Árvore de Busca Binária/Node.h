#include <iostream>

using namespace std;

template <typename chave, typename dado>
class Node
{
    public:

        chave key;

        dado Dado;

        Node <chave, dado>* left;
        Node <chave, dado>* right;

        static Node <chave, dado>* MontaNode(chave k, dado d)
        {
            Node <chave, dado>* P = new Node <chave, dado>;

            if(P)
            {
                P -> left = P -> right = NULL;

                P -> key = k;

                P -> Dado = d;
            }

            return P;
        }

        static void DesmontaNode(Node <chave, dado>* P)
        {
            delete P;
        }
};

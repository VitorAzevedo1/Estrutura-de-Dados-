#include "Node.h"

using namespace std;

template <typename chave, typename dado>
class ArvoreB
{
    int quantidadeNode;

    Node <chave, dado>* root;

    protected:

        static bool Insert(Node <chave, dado> *P, Node <chave, dado>** it)
        {
            if(!(*it))
            {
                *it = P;

                return true;
            }

            if( P -> key < (*it) -> key)
            {
                return ArvoreB <chave,dado> :: Insert(P, &((*it) -> left));
            }

            return ArvoreB <chave,dado> :: Insert(P, &((*it) -> right));
        }

        static pair <bool, dado> Search(Node <chave,dado>* R, chave k)
        {
            dado x;

            if(!R)
            {
                //nao ha o elemento desejado

                return {false, x};
            }

            if(R -> key == k)
            {
                //achou o elemento
                return {true, R -> Dado};
            }

            //nao achou o elemento ainda, mas tem nodes para percorrer ainda

            if(k < R -> key)
            {
                //se o elemento desejado existir ele esta a esquerda
                return  ArvoreB <chave,dado> :: Search(R -> left, k);
            }

            //se o elemento desejado existir ele esta a direita
            return  ArvoreB <chave,dado> :: Search(R -> right, k);
        }

        static Node <chave,dado>* NodeMinimo(Node <chave, dado>* P)
        {
            if(!P)
            {
                return NULL;
            }

            if(!P -> left)
            {
                //achou o node minimo do lado direito
                return P;
            }

            return ArvoreB <chave,dado> :: NodeMinimo(P -> left);
        }

        static bool Erase(Node <chave, dado>** R, chave k)
        {
            if(!(*R))
            {
                //o apontado por R é NUll ele retorna falso, pois não ha um node com esta chave

                return false;
            }

            if((*R) -> key == k)
            {
                //achou o node a ser eliminado
                
                if(!(*R) -> left)
                {
                    // nao tem filho a esquerda

                    Node <chave, dado>* P = *R;

                    *R = P -> right;

                    delete P;

                    return true;
                }

                if(!(*R) -> right)
                {
                    // nao tem filho a direita

                    Node <chave, dado>* P = *R;

                    *R = P -> left;

                    delete P;

                    return true;
                }
                
                Node <chave, dado>* P = ArvoreB <chave,dado> :: NodeMinimo((*R) -> right);

                chave auxK = P -> key;

                P -> key = (*R) -> key;

                (*R) -> key = auxK;

                dado auxD = P -> Dado;

                P -> Dado = (*R) -> Dado;

                (*R) -> Dado = auxD;

                return ArvoreB <chave,dado> :: Erase(&(*R) -> right, k);
            }

            // o node que opontado por R nao eh o R, mas pode ou nao ser entao continua percorrendo

            if(k < (*R) -> key)
            {
                // pode estar a esquerda

                return ArvoreB <chave,dado> :: Erase(&(*R) -> left, k);
            }

            // podeb estar a direita

            return ArvoreB <chave,dado> :: Erase(&(*R) -> right, k);
        }

        static void Clear(Node <chave, dado>* P)
        {
            if(!P)
            {
                if(P -> left)
                {
                    ArvoreB <chave,dado> :: Clear(P -> left);
                }

                if(P -> right)
                {
                    ArvoreB <chave,dado> :: Clear(P -> right);
                }

                delete P;
            }
        }
        
    public:
    
        ArvoreB()
        {
            quantidadeNode = 0;

            root = NULL;
        }

        ~ArvoreB()
        {
            ArvoreB <chave,dado> :: Clear(root);
        }

        pair<bool, dado> search(chave k)
        {
            return ArvoreB <chave, dado> ::Search(root, k);
        }

        bool insert(chave k, dado d)
        {
            Node <chave,dado>* P = Node <chave,dado> :: MontaNode(k, d);

            if(!P)
            {
                return false;
            }

            quantidadeNode++;

            return ArvoreB <chave, dado> :: Insert(P, &root);
        }

        bool erase(chave k)
        {
            // este metodo procura na arvore a chave determinada na chamada inicial do metodo e retorna verdadeiro se excluiu o elemento(se achou ele) e falso
            // se nao excluiu o elemento(nao achou ele);

            // preocupações ao criar este metodo:
            //      1° -> para excluir um node tem que ver se ele tem descentente(s), pois se tiver ele tem que procurar um node para colocar no lugar do node 
            //            excluido para nao perder o acesso a ele, para fazer isso foi criado um metodo statico chamado NodeMinimo, onde ele procura o node 
            //            minimo a direita do node que sera excluido.
            
            //            Para fazer a exclusão de forma correta, devese fazer uma analise de quantos filhos o node que sera excluido possui
            //                 a) tem filhos no left e no right
            //                 b) tem filho somente a esquerda
            //                 c) tem filho somente na direita
            //                 d) nao tem filho  

            bool status = ArvoreB <chave, dado> :: Erase(&root, k);

            quantidadeNode--;

            return status;
        }

        void empty()
        {
            //retorna verdadeiro se estiver vazia
            return !root;
        }

        int size()
        {
            return quantidadeNode;
        }

        void clear()
        {
            ArvoreB <chave, dado> :: Clear(root);

            quantidadeNode = 0;
        }
};


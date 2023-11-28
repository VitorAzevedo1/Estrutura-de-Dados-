#include <iostream>

template <class T>
class Node
{
public:
	T D;
	Node<T>* Next;

	static Node<T>* MontaNode(T E)//metodo estatico que monta meu nó 
	{
		Node<T>* P = new Node;

		if (P)
			//alocou
		{
			P->D = E;
			P->Next = 0;
		}

		return P;
	}

	static T DesmontaNode(Node* P)
	{
		T X;

		if (P)
		{
			X = P->D;
			delete P;
		}

		return X;
	}

};

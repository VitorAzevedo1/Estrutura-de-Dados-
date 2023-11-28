#include "Node.h"

using namespace std;

template <class T>
class Stack
{
private:
	Node<T>* Top;
	int N;//numero de elementos da pilha 

public:
	Stack();
	~Stack();
	bool Push(T E);
	void Pop();
	T top();
	bool Empty();
	int size();
	void Clear();
	void Print();
};

template<class T>
Stack<T>::Stack()//metodo construtor 
{
	Top = 0;
	N = 0;
}

template<class T>
Stack<T>::~Stack()//metodo destrutor
{
	Node<T>* P;

	while (Top)
	{
		P = Top;
		Top = Top->Next;
		Node<T>::DesmontaNode(P);
	}
}

template<class T>
bool Stack<T>::Push(T E)//metodo de inserir um elemento na pilha 
{
	Node<T>* P;
	P = Node<T>::MontaNode(E);

	if (!P)
		//  NULL
	{
		return false;
	}
	P->Next = Top;
	Top = P;
	N++;
	return true;
}

template<class T>
void Stack<T>::Pop()//metodo de remover um elemento da pilha 
{
	if (Top)
		//nao vazia
	{
		Node<T>* P = Top;
		Top = Top->Next;
		Node<T>::DesmontaNode(P);
		N--;
	}
}

template<class T>
T Stack<T>::top()//metodo que da o topo da minha pliha 
//vai dar problema caso estiver vazia 
{
	return Top->D;
}

template<class T>
bool Stack<T>::Empty()//metodo para ver se minha pilha esta vazia
{
	return !Top;
}

template<class T>
int Stack<T>::size()//metodo que retorna o tamnho da minha pilha 
{
	return N;
}

template<class T>
void Stack<T>::Clear()//metodo para limpar minha pilha 
{
	while (Top)
	{
		Node<T>* P = Top;
		Top = Top->Next;
		Node<T>::DesmontaNode(P);
	}
}
template<class T>
void Stack<T>::Print()//metodo para mostrar a pilha 
{
	Node<T>* P = Top;

	cout << "Pilha : [ ";

	while (P)
	{
		cout << P->D << " ";
		P = P->Next;
	}
	cout << "]\n";
}

#include "Node.h"

using namespace std;

template <class T>

class Queue
{
private:
	Node<T>* Head;
	Node<T>* Tail;
	int N;

public:
	Queue();
	~Queue();
	bool Push(T E);
	void Pop();
	T Front();
	void Clear();
	void Empty();
	int size();
	void Print();
};

template <class T>
Queue<T>::Queue()//metodo construtor
{
	Head = Tail = 0;
	N = 0;
}

template <class T>
Queue<T>::~Queue()//metodo destrutor
{
	while (Head)
	{
		Node<T>* P = Head;
		Head = Head->Next;
		Node<T>::DesmontaNode(P);
	}
}

template <class T>
bool Queue<T>::Push(T E)//metodo para inserir um elemento na fila
{
	Node<T>* P = Node<T>::MontaNode(E);

	if (!P)
	{
		return false;
	}
	if (!Head)
	{
		Head = Tail = 0;
	}
	else
	{
		Tail->Next = P;
		Tail = P;
	}
	N++;
	
	return true;
}

template <class T>
void Queue<T>::Pop()//metodo para remover um elemento da fila
{
	if (Head)
	{
		Node<T>* P = Head;
		Head = Head->Next;
		delete P;

		if (!Head)
			//esvaziou a fila
		{
			Tail = 0;
		}
		N--;
	}
}

template <class T>
T Queue<T>::Front()//metodo que retorna a frente da fila
{
	return Head->D;
}

template <class T>
void Queue<T>::Empty()//metodo para ver se a fila esta vazia
{
	return !Head;
}

template <class T>
int Queue<T>::size()//metodo que retorna o tamanho da fila
{
	return N;
}

template <class T>
void Queue<T>::Clear()//metodo para limpar toda fila
{
	while (Head)
	{
		Node<T>* P = Head;
		Head = Head->Next;
		Node<T>::DesmontaNode(P);
	}
	Tail = 0;
	N = 0;
}

template<class T>
void Queue<T>::Print()
{
	Node<T>* P = Head;

	cout << "Fila : [ ";

	while (P)
	{
		cout << P->D << " ";
		P = P->Next;
	}

	cout << "]" << endl; 
}

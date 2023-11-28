#include <iostream>

using namespace std;

typedef int Trem;

class QueueVet
{
private:
	unsigned int tamanho, head, tail;
	Trem* V;

public:
	QueueVet();
	QueueVet(unsigned int n);
	~QueueVet();
	bool Push(Trem T);
	bool Pop();
	Trem Front();
	bool IsEmpty();
	bool IsFull();
	void Print();
	void Clear();

};

QueueVet::QueueVet()
{
	head = 0;
	tail = 0;

	tamanho = 100;

	V = new Trem[tamanho];
}

QueueVet::QueueVet(unsigned int n)
{
	V = new Trem[n];
	tamanho = n;
	head = 0;
	head = tail;
}

QueueVet::~QueueVet()
{
	delete[] V;
}

bool QueueVet::Push(Trem T)
{
	if ((tail + 1) % tamanho != head)
	{
		V[tail] = T;
		tail = (tail + 1) % tamanho;

		return true;
	}

	return false;
}

bool QueueVet::Pop()
{
	if (head == tail)
	{
		return false;
	}

	head = (head + 1) % tamanho;

	return true;
}

Trem QueueVet::Front()
{
	return V[head];
}

bool QueueVet::IsEmpty()
{
	return (tail == head);
}

bool QueueVet::IsFull()
{
	if ((tail + 1) % tamanho == head)
	{
		return true;
	}

	return false;

}

void QueueVet::Print()
{
	cout << "Fila: [ ";
	
	for (int i = head; i < tail; i++)
	{
		cout << V[i % tamanho] << " ";
	}

	cout << "]\n";
}

void QueueVet::Clear()
{
	tail = 0;
	tail = head;
}

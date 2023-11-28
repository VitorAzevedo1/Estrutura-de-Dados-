#include <iostream>

using namespace std;

typedef int Trem;

class StackVet
{
private:
	int Top, N;
	Trem* V;

public:
	StackVet();
	StackVet(int N);
	bool push(Trem T);
	Trem top();
	bool Pop();
	void Clear();
	~StackVet();
	bool IsEmpty();
	bool IsFull();
	void Print();
};

StackVet::StackVet()
{
	Top = 0;
	N = 2;
	V = new Trem[N];
}

StackVet::StackVet(int N)
{
	Top = 0;

	V = new Trem[N];

	this->N = N;

}

bool StackVet::IsEmpty()
{
	return (Top == 0);
}

bool StackVet::IsFull()
{
	return (Top == N);
}

bool StackVet::push(Trem T)
{
	if (Top < N)
	{
		V[Top] = T;
		Top++;

		return true;
	}
	return false;
}

Trem StackVet::top()
{
	Trem x;
	if (Top > 0)
	{
		x = V[Top - 1];
	}
	return x;
}

bool StackVet::Pop()
{
	if (Top > 0)
	{
		Top--;

		return true;
	}

	return false;

}

void StackVet::Print()
{
	cout << "Pilha : [ ";

	for (int i = 0; i < Top; i++)
	{
		cout << V[i] << " ";
	}

	cout << "]" << endl;
}

void StackVet::Clear()
{
	Top = 0;
}

StackVet::~StackVet()
{
	delete[] V;
}

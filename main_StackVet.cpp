#include <iostream>
#include "StackVet.h"

using namespace std;

int main()
{
	StackVet p1;
	Trem t;
	int opcao;

	cout << "Digite 1 para inserir um elemnto da pilha " << endl;
	cout << "Digite 2 para remover um elemento da pilha " << endl;
	cout << "Digite 3 para imprimir a pilha " << endl;
	cout << "Digite 4 para limpar a pilha " << endl;
	cout << "Digite 5 para mostrar o topo da pilha " << endl;
	cout << "Digite 0 para parar o programa " << endl;
	
	while (cin >> opcao)
	{
		system("CLS");
		if (opcao == 1)
		{
			cin >> t;
			p1.push(t);
		}
		else
		{
			if (opcao == 2)
			{
				cin >> t;
				t = p1.Pop();

				cout << "Elemento removido : " << t << endl;
			}
			else
			{
				if (opcao == 3)
				{
					p1.Print();
				}
				else
				{
					if (opcao == 4)
					{
						p1.Clear();
					}
					else
					{
						if (opcao == 5)
						{
							cout << p1.top() << endl;
						}
						else
						{
							if (opcao == 0)
							{
								break;
							}
						}

					}
				}
			}
		}

		cout << "Digite 1 para inserir um elemnto da pilha " << endl;
		cout << "Digite 2 para remover um elemento da pilha " << endl;
		cout << "Digite 3 para imprimir a pilha " << endl;
		cout << "Digite 4 para limpar a pilha " << endl;
		cout << "Digite 5 para mostrar o topo da pilha " << endl;
		cout << "Digite 0 para parar o programa " << endl;
	}
}
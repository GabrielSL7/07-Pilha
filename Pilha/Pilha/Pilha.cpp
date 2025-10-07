#include <iostream>
using namespace std;

struct NO {
	int valor;
	NO* prox;
};

NO* topo = NULL;

void menu();
void inicializar();
void pop();
void push();
void exibir();

int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 5) {
		system("cls");
		cout << "Menu Pilha";
		cout << endl << endl;
		cout << "1 - Inicializar Pilha \n";
		cout << "2 - Inserir elemento (Push) \n";
		cout << "3 - Remover elementos (Pop) \n";
		cout << "4 - Exibir Pilha \n";
		cout << "5 - Sair \n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: push();
			break;
		case 3: pop();
			break;
		case 4: exibir();
			break;
		case 5:
			return;
		default:
			break;
		}

		system("pause");
	}
}

void inicializar()
{
	NO* aux = topo;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	topo = NULL;
	cout << "Pilha inicializada \n";
}

void push()
{
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = topo;
	topo = novo;

	cout << "Elemento " << novo->valor << " inserido no topo da pilha.\n";
}

void pop()
{
	if (topo == NULL) {
		cout << "Pilha vazia! \n";
		return;
	}

	NO* aux = topo;
	cout << "Elemento removido: " << aux->valor << endl;
	topo = topo->prox;
	free(aux);
}

void exibir()
{
	if (topo == NULL) {
		cout << "Pilha vazia! \n";
		return;
	}

	cout << "Conteudo da pilha:\n";
	NO* aux = topo;
	while (aux != NULL) {
		cout << aux->valor;
		if (aux->prox != NULL) cout << " -> ";
		aux = aux->prox;
	}
	cout << " -> NULL\n";
}

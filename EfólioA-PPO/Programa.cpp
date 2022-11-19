#include "Programa.h"

Auxiliar aux;
Programa::Programa()
{
	
	int opcao;
	
	do
	{
		system("cls");
		cout << "\n\n     Seleccione Uma Opcao:"
			<< "\n\t 1 - Inserir atividades"
			<< "\n\t 2 - Ver atividades"
			<< "\n\t 3 - Juntar atividades"
			<< "\n\t 4 - Sair" << endl;
		opcao = aux.inputIntUtilizador();
		switch (opcao)
		{
		case 1:
			cin.ignore();//com isto aqui ja não passa para a frente e deixame continuar com a adição da atividade
			insereAtividade();
			break;
		case 4:
			return ;
		default:
			cout << "Opcao invalida, insira opcao entre 1-4"
				<< "\nPrima enter para continuar"<<endl;
			cin.ignore();
			cin.get();
		}
	} while (opcao != 4);
}

Programa::~Programa()
{
}

void Programa::insereAtividade()
{
	int numero;
	int i=0;
	cout << "Numero de atividades a inserir: " << endl;
	numero=aux.inputIntUtilizador();
	cin.ignore();
	while (i <= numero)
	{
		cout << "Insira os dados da atividade numero " <<i+1<< endl;
		 lista.push_back(Atividade());
		 i++;
	}
	
	

	//fazer primeiro o url e fazes ja as funçoes no aux 
	//posso enviar a string para a função e retornar verdadeiro ou falso comparar primeiro o url com a letra a mais e depois comprar a letra a menos
	//comparar letra a letra
}


#include "Atividade.h"

Atividade::Atividade()
{
	system ("cls");
	Auxiliar aux;
	
	cout << "Titulo da atividade: " << endl;
	getline(cin, this->titulo);
	cout << "Descricao: " << endl;
	getline(cin, this->descricao);
	cout << "Url do video de apresentacao: ";
	getline(cin, this->url);
	while (aux.checkUrl(url) == false)
	{
		cout << "Insira um url valido:" << endl;
		getline(cin, this->url);
	}
	cout << "Sistema: " << endl;
	this->sistema = aux.inputFloatUtilizador();
	cout << "Narrativa: " << endl;
	this->narrativa= aux.inputFloatUtilizador();
	cout << "Agencia: ";
	this->agencia = aux.inputFloatUtilizador();
	cin.ignore();

	cout << "Atividade adicionada com sucesso, prima enter para continuar";
	cin.get();
}

Atividade::~Atividade()
{
}

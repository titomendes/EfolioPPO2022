#pragma once
#include"Atividade.h"
#include"Auxiliar.h"
#include<iomanip>
#include<algorithm>
#include<iostream>
#include<vector>
class Programa
{
private:                              //vetor de atividades privada
	vector<Atividade>lista;
	vector<Atividade>::iterator it;
	vector<Atividade>::iterator it2;  // iterador do vetor

public:                       
	Programa();                   //construtor 
	~Programa();                  //destrutor
	void insereAtividade();          //fun��o de inserir as atividades
	void verAtividades();            //ver as atividades
	void juntarAtividades();         // jun��o de atividades
	void imprimeLista();             // imprime a lista de atividades
	void imprimeAtividade(vector<Atividade>::iterator it);    //imprime uma atividade
	bool verificaTitulo(string nome);                   //fun��o para verificar se existem nomes iguais
	void ordenar(int opcao);                      //fun��o para ordenar o vetor

};



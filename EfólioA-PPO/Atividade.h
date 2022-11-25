#pragma once
#include"Auxiliar.h"
#include<string>
#include<iostream>
using namespace std;


class Atividade
{
private:                           //atributos privados da atividade
	string titulo;
	string descricao;
	string url;
	float sistema;
	float narrativa;
	float agencia;

public:
	Atividade(string titulo, string descricao,string url,float sistema,float narrativa, float agencia);     //construtor com atributos
	Atividade();                                      //construtor vazio para ser usado na junção de atividades
	~Atividade();       //destrutor

	//Metodos get/set
	string getTitulo() { return titulo; }
	void setTitulo(string titulo) { this->titulo = titulo; }
	string getDescricao() { return descricao; }
	void setDescricao(string descricao) { this->descricao = descricao; }
	string getUrl() { return url; }
	void setUrl(string url) { this->url = url; }
	float getSistema() { return sistema; }
	void setSistema(float sistema) { this->sistema = sistema; }
	float getNarrativa() { return narrativa; }
	void setNarrativa(float narrativa) { this->narrativa = narrativa; }
	float getAgencia() { return agencia; }
	void setAgencia(float agencia) { this->agencia = agencia; }



	//Overload do operador + para a junção das atividades
	Atividade operator+( Atividade& a)
	{
		Atividade atividade;
		if (this->sistema < a.sistema)                // se o sistema da primeira atividade for maior que o sistema de a, a atividade fica com o sistema de a que é a segunda atividade     
			atividade.sistema= a.sistema;             
		else               
			atividade.sistema=this->sistema;          // Aqui se for ao contrário a atividade fica com o sistema da segunda atividade
														//esta logica é usada para os outros atributos
		if (this->narrativa < a.narrativa)
			atividade.narrativa = a.narrativa;
		else
			atividade.narrativa = this->narrativa;

		if (this->agencia < a.agencia)
			atividade.agencia = a.agencia;
		else
			atividade.agencia = this->agencia;
	
		return atividade;
	}
	

};



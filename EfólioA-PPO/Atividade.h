#pragma once
#include"Auxiliar.h"
#include<string>
#include<iostream>
using namespace std;


class Atividade
{
private:
	string titulo;
	string descricao;
	string url;
	float sistema;
	float narrativa;
	float agencia;

public://fica a faltar metodo de adicionar com sobrecarga
	Atividade();
	~Atividade();
	string getTitulo() { return titulo; }
	void setTitulo(string titulo) { this->titulo = titulo; }
	string getDescricao() { return descricao; }
	void setDescricao(string descricao) { this->descricao = descricao; }
	string getUrl() { return url; }
	void setUrl(string Url) { this->url = url; }
	float getSistema() { return sistema; }
	void setSistema(float sistema) { this->sistema = sistema; }
	float getNarrativa() { return narrativa; }
	void setNarrativa(float narrativa) { this->narrativa = narrativa; }
	float getAgencia() { return agencia; }
	void setAgencia(float agencia) { this->agencia = agencia; }
	

};



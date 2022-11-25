#include "Atividade.h"

Atividade::Atividade(string titulo, string descricao, string url, float sistema, float narrativa, float agencia)
{
	this->titulo = titulo;
	this->descricao = descricao;
	this->url = url;
	this->sistema = sistema;
	this->narrativa = narrativa;
	this->agencia = agencia;
}

Atividade::~Atividade()
{
}

Atividade::Atividade()
{

}

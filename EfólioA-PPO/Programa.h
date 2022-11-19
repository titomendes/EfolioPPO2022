#pragma once
#include"Atividade.h"
#include"Auxiliar.h"
#include<iostream>
#include<vector>
class Programa
{
private:
	vector<Atividade>lista;
	vector<Atividade>::iterator it;

public:
	Programa();
	~Programa();
	void insereAtividade();


};



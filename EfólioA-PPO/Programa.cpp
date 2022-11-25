#include "Programa.h"

Programa::Programa()       //construtor de inicio do programa
{
	int opcao;         
	do                // Mostra o menu enquanto o utilizador selecionar uma opcao
	{
		system("cls");   //limpa o ecr�
		cout << "\n\n     Seleccione Uma Opcao:"            //Mostra menu
			<< "\n\t 1 - Inserir atividades"
			<< "\n\t 2 - Ver atividades"
			<< "\n\t 3 - Juntar atividades"
			<< "\n\t 4 - Sair" << endl;
		opcao = inputIntUtilizador();           // uso de uma fun��o auxiliar para ter a certeza que um numero � inserido
		cin.ignore();          //limpeza do buffer para o programa n�o saltar op�oes com o enter que fica preso no buffer
		switch (opcao)
		{
		case 1:                // Vai para a fun��o de inserir as atividades
			insereAtividade(); 
			break;
		case 2:            
			if (lista.empty())       // verifica se existem ou n�o atividades no vetor
			{
				cout << "Nao existem atividades inseridas" << endl;
				sairDoEcra();     // fun��o auxiliar para sair do ecr�
			}
			else               // se existirem vai para a fun��o de ver as atividades
			verAtividades();
			break;
		case 3: 
			if (lista.empty())           // verifica se existem ou n�o atividades no vetor
			{
				cout << "Nao existem atividades inseridas" << endl;
				sairDoEcra();
			}
			else            // se existirem vai para a fun��o de juntar as atividades
			juntarAtividades();          
			break;
		case 4:            
			return ;       // se a op��o inserida for 4 o programa termina
		default:
			cout << "Opcao invalida, insira opcao entre 1-4"<<endl;       //qualquer outro valor vai ser inv�lido 
			sairDoEcra();                //  volta ao inicio
			
		}
	} while (opcao);       
}

Programa::~Programa()          //destrutor de Programa
{ 
}

//fun��o de inserir as atividades no vetor
void Programa::insereAtividade()       
{
	int numero;
	cout << "Numero de atividades a inserir: " << endl;       //pede o numero de atividades
	numero=inputIntUtilizador();        //com a fun��o auxiliar insere o valor digitado no numero
	cin.ignore();                    //limpeza o buffer
	if (numero <=0)               // se o valor for inferior ou igual a 0
	{
		cout <<numero<< " nao e um numero valido,insira um numero positivo " << endl;
		insereAtividade();      // volta ao inicio da fun��o
	}
	
	while (numero >0)           //enquanto o numero for maior que 0 vai pedir os dados da atividade
	{ 
		//variaveis auxiliares para inserir na atividade
		string titulo;
		string descricao;
		string url;
		float sistema;
		float narrativa;
		float agencia;

		system("cls");      //limpeza do ecr�

		//Aqui vou pedir os dados para inserir na atividade
		cout << "Titulo da atividade: " << endl;
		getline(cin, titulo);          
		while (verificaTitulo(titulo))              //chama a fun��o e verifica se existe algum nome igual
		{
			cout << "Ja existe uma atividade com esse titulo, coloque outro:" << endl;
			getline(cin, titulo);                   //pede outro se for igual
		}
		cout << "Descricao: " << endl;
		getline(cin, descricao);       
		cout << "Url do video de apresentacao: ";
		getline(cin,url);
		while (checkUrl(url) == false)    //enquanto a fun��o retornar falso (que vai chamar outras duas fun��es auxiliares para verficar o protcolo do url)
		{
			cout << "Insira um url valido:" << endl;
			getline(cin,url);
		}
		cout << "Sistema: " << endl;
		sistema = inputFloatUtilizador();   //chamada da fun��o para introduzir variaveis float
		cout << "Narrativa: " << endl;
		narrativa = inputFloatUtilizador();
		cout << "Agencia: ";
		agencia = inputFloatUtilizador();
		cin.ignore();      
		
		lista.push_back(Atividade(titulo, descricao, url, sistema, narrativa, agencia));    //adiciona a atividade ao vetor
		 numero--;          // decrementa o numero 
	}
	cout << "Atividade adicionada com sucesso" << endl;
	sairDoEcra();
}

//Fun��o para ver as atividades e escolher a ordena��o
void Programa::verAtividades()
{
		int opcao;
		cout << "Ver atividades ordenadas por sistema(0), narrativa(1),agencia(2)" << endl;
		opcao = inputIntUtilizador();
		cin.ignore();
		if (opcao < 0 || opcao>2) //se a opc�o n�o for entre 0 e 2 a fun��o volta ao inicio chamando-a
		{
			cout << "So opcoes entre 0 e 2" << endl;
			verAtividades();     
		}
			ordenar(opcao);    //fun��o que tem os metodos de ordena��o com a op��o  como argumento
		
		imprimeLista();    // imprime a lista no ecr�
		sairDoEcra();
}

//Fun��o para ordenar o vetor
void Programa::ordenar(int opcao)
{
	auto sortLista = [opcao](Atividade& A1, Atividade& A2)  //fun��o lambda que captura a op��o para usar no switch e com 2 atividades como argumentos
	{
		switch (opcao)   ///escolha do tipo de orden��o, dependendo da op��o o switch devolve para a fun��o sort as variaveis para ordenar e se � descendente ou ascendente
		{
		case 0:
			return A1.getSistema() > A2.getSistema();  
			break;
		case 1:
			return A1.getNarrativa() > A2.getNarrativa();
			break;
		case 2:
			return A1.getAgencia() > A2.getAgencia();
			break;
		}
	};
	sort(lista.begin(), lista.end(), sortLista);   //fun��o sort que usa o vetor e a fun��o sortLista como argumento
}

//Fun��o de juntar atividades
void Programa::juntarAtividades()
{
	string nomeAux;       // titulo auxilar para procucar o titulo no vetor
	Atividade  a3;    // 3 atividades, 2 para copiar os elementos de 
	vector<Atividade>::iterator itAux1, itAux2;
	bool flag = false;

	imprimeLista();
	cout << "\nInsira o nome da primeira atividade : " << endl;
	getline(cin, nomeAux);

	for (it = lista.begin(); it != lista.end(); it++)
	{
		if (nomeAux == it->getTitulo())
		{
			itAux1 = it;
			flag = true;
			break;
		}
	}
	if (flag == false)
	{
		cout << "Nao existe essa atividade no sistema";
		sairDoEcra();
		return;
	}
	flag = false;
	cout << "Insira o nome da segunda atividade: " << endl;
	getline(cin, nomeAux);


	for (it2 = lista.begin(); it2 != lista.end(); it2++)
	{
		if (nomeAux == it2->getTitulo())
		{  
			itAux2 = it;
			flag = true;
		}
	}
	if (flag == false)
	{
		cout << "Nao existe essa atividade no sistema";
		sairDoEcra();
		return;
	}

	a3 = (*itAux1) + (*itAux2);

	cout << "Juncao de " << itAux1->getTitulo() << " mais " << itAux2->getTitulo()
		<< "\n\nSistema: " << setprecision(2) << a3.getSistema()
		<< "\nNarrativa: " << setprecision(2) << a3.getNarrativa()
		<< "\nAgencia: " << setprecision(2) << a3.getAgencia() << endl << endl;
	//cin.ignore();
	sairDoEcra();
}

void Programa::imprimeLista()
{
	system("cls");
	cout << "Atividades existentes"<< endl<<endl;
	for (it = lista.begin(); it != lista.end(); it++)
	{
		imprimeAtividade(it);
	}	
}

void Programa::imprimeAtividade(vector<Atividade> ::iterator it)
{

	cout << "Titulo: " << it->getTitulo()
		<< "\nDescricao: " << it->getDescricao()
		<< "\nUrl: " << it->getUrl()
		<< "\nSistema: " << setprecision(2) << it->getSistema()
		<< "\nNarrativa: " << setprecision(2) << it->getNarrativa()
		<< "\nAgencia: " << setprecision(2) << it->getAgencia() << endl << endl;

}

bool Programa::verificaTitulo(string titulo)
{
	bool verifica = false;
	for (it = lista.begin(); it != lista.end(); it++)
	{
		if (titulo == it->getTitulo())
		{
			verifica = true;
			break;
		}
	}
	return verifica;
}
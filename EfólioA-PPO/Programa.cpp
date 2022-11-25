#include "Programa.h"

Programa::Programa()       //construtor de inicio do programa
{
	int opcao;         
	do                // Mostra o menu enquanto o utilizador selecionar uma opcao
	{
		system("cls");   //limpa o ecrã
		cout << "\n\n     Seleccione Uma Opcao:"            //Mostra menu
			<< "\n\t 1 - Inserir atividades"
			<< "\n\t 2 - Ver atividades"
			<< "\n\t 3 - Juntar atividades"
			<< "\n\t 4 - Sair" << endl;
		opcao = inputIntUtilizador();           // uso de uma função auxiliar para ter a certeza que um numero é inserido
		cin.ignore();          //limpeza do buffer para o programa não saltar opçoes com o enter que fica preso no buffer
		switch (opcao)
		{
		case 1:                // Vai para a função de inserir as atividades
			insereAtividade(); 
			break;
		case 2:            
			if (lista.empty())       // verifica se existem ou não atividades no vetor
			{
				cout << "Nao existem atividades inseridas" << endl;
				sairDoEcra();     // função auxiliar para sair do ecrã
			}
			else               // se existirem vai para a função de ver as atividades
			verAtividades();
			break;
		case 3: 
			if (lista.empty())           // verifica se existem ou não atividades no vetor
			{
				cout << "Nao existem atividades inseridas" << endl;
				sairDoEcra();
			}
			else            // se existirem vai para a função de juntar as atividades
			juntarAtividades();          
			break;
		case 4:            
			return ;       // se a opção inserida for 4 o programa termina
		default:
			cout << "Opcao invalida, insira opcao entre 1-4"<<endl;       //qualquer outro valor vai ser inválido 
			sairDoEcra();                //  volta ao inicio
			
		}
	} while (opcao);       
}

Programa::~Programa()          //destrutor de Programa
{ 
}

//função de inserir as atividades no vetor
void Programa::insereAtividade()       
{
	int numero;
	cout << "Numero de atividades a inserir: " << endl;       //pede o numero de atividades
	numero=inputIntUtilizador();        //com a função auxiliar insere o valor digitado no numero
	cin.ignore();                    //limpeza o buffer
	if (numero <=0)               // se o valor for inferior ou igual a 0
	{
		cout <<numero<< " nao e um numero valido,insira um numero positivo " << endl;
		insereAtividade();      // volta ao inicio da função
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

		system("cls");      //limpeza do ecrã

		//Aqui vou pedir os dados para inserir na atividade
		cout << "Titulo da atividade: " << endl;
		getline(cin, titulo);          
		while (verificaTitulo(titulo))              //chama a função e verifica se existe algum nome igual
		{
			cout << "Ja existe uma atividade com esse titulo, coloque outro:" << endl;
			getline(cin, titulo);                   //pede outro se for igual
		}
		cout << "Descricao: " << endl;
		getline(cin, descricao);       
		cout << "Url do video de apresentacao: ";
		getline(cin,url);
		while (checkUrl(url) == false)    //enquanto a função retornar falso (que vai chamar outras duas funções auxiliares para verficar o protcolo do url)
		{
			cout << "Insira um url valido:" << endl;
			getline(cin,url);
		}
		cout << "Sistema: " << endl;
		sistema = inputFloatUtilizador();   //chamada da função para introduzir variaveis float
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

//Função para ver as atividades e escolher a ordenação
void Programa::verAtividades()
{
		int opcao;
		cout << "Ver atividades ordenadas por sistema(0), narrativa(1),agencia(2)" << endl;
		opcao = inputIntUtilizador();
		cin.ignore();
		if (opcao < 0 || opcao>2) //se a opcão não for entre 0 e 2 a função volta ao inicio chamando-a
		{
			cout << "So opcoes entre 0 e 2" << endl;
			verAtividades();     
		}
			ordenar(opcao);    //função que tem os metodos de ordenação com a opção  como argumento
		
		imprimeLista();    // imprime a lista no ecrã
		sairDoEcra();
}

//Função para ordenar o vetor
void Programa::ordenar(int opcao)
{
	auto sortLista = [opcao](Atividade& A1, Atividade& A2)  //função lambda que captura a opção para usar no switch e com 2 atividades como argumentos
	{
		switch (opcao)   ///escolha do tipo de ordenção, dependendo da opção o switch devolve para a função sort as variaveis para ordenar e se é descendente ou ascendente
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
	sort(lista.begin(), lista.end(), sortLista);   //função sort que usa o vetor e a função sortLista como argumento
}

//Função de juntar atividades
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
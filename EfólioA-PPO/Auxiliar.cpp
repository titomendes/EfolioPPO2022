#include "Auxiliar.h"

int inputIntUtilizador()//função de checar os numeros, fazer mais uma de float
{
    int numero;
    while(!(cin>>numero))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "So valores numericos : ";
    }
    return numero;
}

float inputFloatUtilizador()
{
    string aux;
    float numero;

    cin >> aux;
    while (1)
    {
        if (aux.find_first_not_of("1234567890.") != string::npos)
        {
            cout << "So valores numericos validos : " << endl;
            cin >> aux;
        }
        else
        {
            numero = stof(aux);
            break;
        }
    }

    if (numero < 0 || numero>1)
    {
        cout << "\nInsira valores entre 0 e 1: ";
        inputFloatUtilizador();
    }
    return numero;
    
}


    bool checkUrl(string url)//verifica o url enviando o url para duas funçoes
    {
        if (verificaTeste(url) == false && verificaTeste2(url) == false)
            return false;
        else if (url == "http://" || url == "https://")
        {
            cout << "So o protocolo nao e suficente" << endl;
                return false;
        }
        else 
            return true;
    }

    bool verificaTeste(string url)//verificar a string mais pequena
    {
        string subString = url.substr(0, 7);
        string teste = "http://";
        if (teste.compare(subString) == 0)
            return true;
        else
            return false;         
    }

    bool verificaTeste2(string url)//verificar a string maior
    {
        string subString = url.substr(0, 8);
        string teste2 = "https://";
        if (subString.compare(teste2) == 0)
            return true;
        else
            return false;
    }

     void sairDoEcra()
    {
        cout << "Prima enter para continuar";
        cin.get();
    }

    

    

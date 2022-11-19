#include "Auxiliar.h"

using namespace std;

int Auxiliar::inputIntUtilizador()//função de checar os numeros, fazer mais uma de float
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
float Auxiliar::inputFloatUtilizador()//função de checar os numeros, fazer mais uma de float
{
    float numero;
    while (!(cin >> numero))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "So valores numericos : ";
    }
    if (numero < 0 || numero>1)
    {
        cout << "\nInsira valores entre 0 e 1: ";
        inputFloatUtilizador();
    }

    return numero;
}






    bool Auxiliar::checkUrl(string url)//verifica o url enviando o url para duas funçoes
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
    bool Auxiliar::verificaTeste(string url)//verificar a string mais pequena
    {
        string subString = url.substr(0, 7);
        string teste = "http://";
        if (teste.compare(subString) == 0)
            return true;
        else
            return false;         
    }

    bool Auxiliar::verificaTeste2(string url)//verificar a string maior
    {
        string subString = url.substr(0, 8);
        string teste2 = "https://";
        if (subString.compare(teste2) == 0)
            return true;
        else
            return false;
    }

  

    

    

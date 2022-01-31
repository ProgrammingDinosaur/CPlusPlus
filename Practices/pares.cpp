#include <iostream>
#include <string>
using namespace std;

int count_pares(int num_a)
{
    int pares = 0;
    for (int i = 0;i <= num_a; i++)
    {

        if (i == 0) 
        {
            pares++;
            cout << "Par encontrado: "<<i<<endl;
        }
        else if (i % 2 == 0)
        {
            pares++;
            cout << "Par encontrado: "<<i<<endl;
        }
        else
        {
            ;
        }
        
    }
    return pares;
}

int main()
{
    int num = 0;
    cout << "Ingrese numero a buscar los pares: ";
    cin >> num;
    cout << "Buscando pares... espere...."<<endl;
    int pares_encontrados = count_pares(num);
    cout << "Terminado!"<<endl;
    cout << "Pares encontrados: " << to_string(pares_encontrados)<<endl;
    return 0;
}
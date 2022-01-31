#include <iostream>
#include <string>
#include <math.h>


using namespace std;

bool checar_palindromo(string supuesto_palindromo)
{ 
    int contar = 0;
 
    for (int i = 0; supuesto_palindromo[i]-1; i++)
        if (supuesto_palindromo[i] != ' ')
            supuesto_palindromo[contar++] = supuesto_palindromo[i];
    for (int i = 0; i<supuesto_palindromo.length();i++)
    {
        supuesto_palindromo[i] = tolower(supuesto_palindromo[i]);
    }
    cout << supuesto_palindromo<<endl;
    int len_cadena = supuesto_palindromo.length();
    bool palindromo = true;
    for(int i=0;i < len_cadena ;i++){
        if(supuesto_palindromo[i] != supuesto_palindromo[len_cadena-i-1]){
            palindromo = false;

            break;
        }
}
    return palindromo;
}

int main()
{
string palindromo;
cout << "Ingresa la frase/palabra a checar: ";
getline(cin,palindromo);
bool palindromo_res = checar_palindromo(palindromo);

if (palindromo_res){
    cout <<"La palabra es palindromo";
}
else
{
    cout << "La palabra  no es palindromo";
}
}
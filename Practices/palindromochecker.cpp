#include <iostream>
#include <string>
#include <math.h>


using namespace std;

bool checar_palindromo(string supuesto_palindromo)
{ 
    string palind = supuesto_palindromo;
    int contar = 0;
    int espacios = 0;
    for (int i = 0; i < palind[i]-1; i++){
        if (palind[i] != ' ') {
            palind[contar++] = palind[i];
            
        }
        else{
            espacios++;
        }}

    int len_cadena = (palind.length()-espacios);
    for (int j = 0; j<(len_cadena);j++)
    {
        palind[j] = tolower(palind[j]);
    }

    bool palindromo = true;
    for(int k=0;k < len_cadena ;k++){
        if(palind[k] != palind[len_cadena-k-1]){
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
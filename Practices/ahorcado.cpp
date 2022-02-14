//*Importar librerías *//

#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>

using namespace std; //Definir espacio de trabajo


string definir_palabra() //Definir función para especificar palabra
{
    string palabra; //Definir variable para almacenar la palabra
    cout << "Ingresa la palabra para jugar: "; //Retroalimentación al usuario
    cin >> palabra; //Pedir al usuario que ingrese la palabra
    //*Convertir la palabra a minúscula*//
    for (int i = 0; i<(palabra.length());i++) //Iterar toda la palabra
    {
        palabra[i] = tolower(palabra[i]); //Convertir letra en minúscula
    }

    return palabra; //Regresar palabra
}

vector <int> encontrar_ocurrencias_letra(char letra,string palabra) //Función para encontrar en qué parte de la palabra está la letra ingresada
{
    
    vector<int> letras_ocurrencias; //Definir variable de almacenamiento para las ocurrencias de la letra
    for(int i =0; i < palabra.length(); i++) //Loop que revisa cada letra de la palabra
        if(palabra[i] == letra) //Condición si la letra actual del loop es igual a la letra ingresada
            letras_ocurrencias.push_back(i);  //Si cumple la condición anterior agregar a la variable "letras ocurrencias"

    return letras_ocurrencias; //Regresar la ocurrencia de la letra en la palabra
}

bool revisar_estado_juego(vector <bool> letras,int vidas) //Función qe revisa si el juego ha terminado
{
    bool palabra_adivinada = true; //Definir variable que dice si la palabra ya fue adivinada
    for (int i: letras) //Loop por el vector booleano que define que letras han sido adivinadas
    { 
        if (i == false) //Condición si un valor del vector es falso
        { 
            palabra_adivinada = false; //Si se cumple la condición la palabra no ha sido adivinada           
            break; //Salir del loop al saber que la palabra aún no es adivinada
        }
    }
    
    return ((palabra_adivinada) || (vidas == 0)); //Regresar el valor de la condición si se ha adivinado la palabra o si ya no quedan vidas
}

bool gameloop(vector <bool> &letras, string &palabra,vector <char> &adivinadas,int &vidas) //Loop del Juego de ahorcado (se pasan las variables del juego almacenadas en main por referencia)
{   

    char intento; //Variable "char" que almacenará el intento entrado por el jugador
    int cont = 0; //Definir Contador de letras
    for (int i: letras) //Loop por el vector de booleanos que define qué letras han sido adivinadas
    { 

        if (i == true) //Si la letra de la iteración actual del loop es verdadera 
        {
            cout << palabra[cont]; //Si se cumple la condición anterior imprimir la letra tal cuál

        }
        else
        {
            cout<<"*"; //Si la letra no ha sido adivinada imprimir un asterisco en su lugar
        }
    cont++; //Incrementar contador de letras
    
    }
    
    bool intento_valido = false; //Definir variable que dicta si la letra ingresada es válida o no
    while(intento_valido == false) //While que repetirá lo mismo hasta que la letra ingresada sea válida
    {
        cout<<"\nIngresa una letra para adivinar: "; //Retroalimentación al usuario
        cin >> intento; //Pedir al usuario que ingrese la letra para intentar adivinar 
        if (find(adivinadas.begin(),adivinadas.end(),intento) != adivinadas.end()) //Si la letra ya ha sido ingresada anteriormente
        {          
            intento_valido = false; //Si se  cumple la condición la letra no es válida, asignar falso a variable de intento
            cout << "Ups! Ya has entrado esa letra, intenta de nuevo\n"; //Retroalimentación de error al usuario
        }
        else
        {
        adivinadas.push_back(intento); //De lo contrario agregar la nueva letra a la lista de letras ingresadas
        intento_valido = true; //Definir el intento como válido
        }
    }
    vector <int> ocurrencias = encontrar_ocurrencias_letra(intento,palabra); //Definir la variable de ocurrencias encontradas como el resultado de la función de "encontrar ocurrencias"
    
    if (ocurrencias.size() == 0) //Si no hay ocurrencias de la letra en la palabra
    {
        vidas--; //Si no hay ocurrencias disminuir una vida
        cout << "Ups! Esa letra no forma parte de la palabra, pierdes una vida"<<" te quedan: "<<vidas<<" vidas\n"; //Decirle al usuario que perdió una vida
    }
    else
    {
        for (int j: ocurrencias) //Si existen ocurrencias iterar por todas ellas
        {
            letras[j] = true; //En el índice donde existan ocurrencias asignar el valor de verdadero dentro de variable "letras"
            cout << "\nFelicidades! Tu letra esta en la palabra\n"; //Retroalimentación de éxito al jugador
        }
    }
    

    return revisar_estado_juego(letras,vidas); //Regresar el valor del estado del juego con la función "revisar estado de juego"
    }

int main() //función main
{
    int vidas = 3; //Definir vidas iniciales como 3
    string palabra = definir_palabra(); //Llamar función "definir palabra para que el usuario defina la palabra"
    int num_chars = palabra.length();  //Almacenar en una variable la longitud de la palabra
    vector <bool> letras_palabra (num_chars,false); //Crear vector de booleanos con la longitud de la palabra, para almacenar si las letras han sido adivinadas (por defecto falso)
    vector <char> adivinadas; //Definir el vector para almacenar letras entradas por el usuario
    cout << "Usted ha seleccionado la palabra: "<<palabra<<endl; //Retroalimentar al usuario la palabra que escogió
    cout << "Llego la hora de jugar!!!!!\n"; //Darle a conocer al usuario que el juego va a comenzar
    bool juego_terminado = false; //Definir variable que dirá cuando termine el juego
    while (vidas > 0 && juego_terminado == false) //Mientras el juego no haya terminado y las vidas sean mayor a 0 seguir con el juego
    {
    juego_terminado = gameloop(letras_palabra,palabra,adivinadas,vidas); //Ejecutar un loop del juego y regresar el estado del mismo
    }
    ///*ESTA PARTE DEL CÓDIGO SE EJECUTA UNA VEZ EL JUEGO ACABA*///
    if (vidas == 0) //Si al acabar las vidas son igual a  0, es decir perdió
    {
        cout << "\nHas perdido el juego de ahorcado y moriste... ya sera en otra ocasion"; //Decir al usuario que perdió
    }
    else
    {
        cout << "\nAdivinaste la palabra _"<<palabra<<"_ y has ganado le juego!"; //Si acaba el juego con vidas decirle al usuario que ganó
    }
    return 0; //Si todo sale bien regresar 0 y acabar la ejecución
}

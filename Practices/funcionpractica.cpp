//*Importar Librerías*//

#include <iostream> //Libería principal para entrada y salida
#include <cmath> //Librería para matemáticas

//Definición de espacio de trabajo

using namespace std;

//*Funciones Secuandarias*//

int Restar(int num_uno, int num_dos) //Definición de función Restar
{
    return num_uno-num_dos; //Regresar resta de parámetro num_uno y num_dos
}

int Multiplicar(int num_uno, int num_dos)//Definición de función Multiplicar
{
    return num_uno*num_dos; //Regresar multiplicación de parámetro num_uno y num_dos
}

float Dividir(int num_uno, int num_dos) //Definición de función Dividir
{
    float resultado = num_uno/num_dos; //Definir flotante con resultado de la división de num_uno y num_dos
    return resultado; //Regresar Resultado
}

int PotenciarCuadrado(int num) //Definición de función para potenciar al cuadrado
{
    return num*num; //Regresar número multiplicado por si mismo (potencia cuadrada)
}

float RaizCuadrada(int num) //Definición de función para obtener raíz cuadrada
{
    return sqrt(num); //Regresar raíz cuadrada del númerp usando librería "cmath"
}


//*Función Main*//

int main()
{
    int resta_a = 11; //Definir parámetro de resta 1
    int resta_b = 8;  //Definir parámetro de resta 2

    cout<< "Resta de: "<< resta_a << " y "<< resta_b <<" = " << Restar(resta_a,resta_b)<<endl; //Imprimir resultado de resta de 2 parámetros

    int mult_a = 7; //Definir parámetro multiplicación 1
    int mult_b = 8; //Definir parámetro multiplicación 1

    cout<< "Multiplicacion de: "<< mult_a << " y "<< mult_b <<" = " << Multiplicar(mult_a,mult_b)<<endl; //Imprimir resultado de multiplicación de 2 parámetros

    int div_a = 77; //Definir parámetro división 1
    int div_b = 11; //Definir parámetro división 1

    cout<< "Division de: "<< div_a << " entre "<< div_b <<" = " << Dividir(div_a,div_b)<<endl; //Imprimir resultado de divisón de 2 parámetros
    
    int pot_cuadrada_num = 5; //Definir parámetro para potenciar al cuadrado

    cout<< "Potencia Cuadrada de "<< pot_cuadrada_num <<" = " << PotenciarCuadrado(pot_cuadrada_num)<<endl; //Imprimir resultado del número ingresado al cuadrado
    
    int raiz_cuadr_num = 144; //Definir parámetro al cual sacar raíz cuadrada

    cout<< "Raiz Cuadrada de "<< raiz_cuadr_num <<" = " << RaizCuadrada(raiz_cuadr_num)<<endl; //Imprimir resultado de la raiz cuadrada del número
    
    return 0; //Regresar 0 si todo sale bien
}
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <time.h> 

using namespace std;
int solicitar_problema(vector <string> opciones)
{

    int problema;
    bool valid_request = false;
    while (valid_request == false)
        {
        
        cout << "Por favor ingresa el numero de la opcion con la que necesitas ayuda, por favor :)\n";
        int opcion_cont = 1;
        for (string i : opciones)
        {
            cout <<opcion_cont<<"."<< i<<endl;
            opcion_cont++;
        }
        cout << "Ingresa el numero de tu problema: ";
        cin >> problema;
        if (problema > 0 && problema <= opciones.size())
        {
            cout << "Disculpa! Parece que yo no puedo ayudarte con tu problema, te transferire al area correspondiente para tratarlo, vale? :)\nFue un gusto atenderte. Liverpool es parte de tu vida.\n";
            valid_request = true;
            

        }else{
            cout << "Vaya... parece que el numero que ingresaste no forma parte de la lista de opciones, intenta de nuevo! Recuerda, ingresa un numero entre 1 y "<< to_string(opciones.size())<<endl;
        }
        
        }
    return problema;
}

bool confirmar_decision ()
{
    bool seguir = false;
    int decision;
    while (seguir == false){
        cout << "Esta seguro de su seleccion? Presione 1 para continuar, o 0 para regresar"<<endl;
        cin >> decision;
        if (decision != 0 && decision!= 1){
            cout << "Su entrada no fue valida, intente de nuevo.";
        }else{
            seguir = true;
        }
    }
    return decision;
}

int pregunta_seleccioanda(vector <string> opciones)
{
    string nombres_bot[] = {"Ramiro","Roberto","Angel","Isaac","Ricardo","Eduardo","Arturo","Samuel","Alfredo","Nicolas","Efrain","Alan"};
    srand ( time(NULL));
    int name_select = rand() % (sizeof(nombres_bot)/sizeof(nombres_bot[0]));
    cout << "Hola bienvenido a servicio al cliente de Liverpol!\nLiverpool, es parte de tu vida\nHola mi nombre es "<< nombres_bot[name_select] << " y estoy para servirte.\n";
    
    int decision = 2;
    int request_result;
    
    request_result = solicitar_problema(opciones);
    decision = confirmar_decision();
    while (decision != 1)
    {
        request_result = solicitar_problema(opciones);

        decision = confirmar_decision();

    }
    return request_result;
}


int main()
{
vector <string> preguntas = {"Compras en Linea Liverpool","Devoluciones","Rastreo de Envio","Acciones de tarjeta Liverpool","Servicio al Cliente"};
int problema_usuario = pregunta_seleccioanda(preguntas);
cout << "Transfiriendote al area de  "<<preguntas[problema_usuario-1]<<".........espera un momento.........";
system("pause");

return 0;

}

///*Ada Lovelace fue una condesa, hija de Lord, un poeta, y Lady Baron, una mujer con amplios conocimientos de Ciencia. 
///Ada Lovelace se dedicó a la matemática desde pequeña, es conocida como la primera programadora ya que dedicó gran parte de su vida a
// lograr que los humanos pudieran dar instrucciones a las máquinas. Cosa que ella implementó en una máquina que producía telares. Ella 
//logró  hacer que con ciertos movimientos hechos a la maquina en forma de binaria (si el textil era perforado o no) la máquina realizara ciertas
//tareas básicas, con lo que fue la primera manera de dar "código" a una máquina
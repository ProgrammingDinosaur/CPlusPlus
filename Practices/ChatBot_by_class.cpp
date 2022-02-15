#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <time.h> 

using namespace std;

class Chatbot{
    private: 
        vector <string> questions;
        vector <string> nombres_bot;
    public:
        string tienda;
        string catchphrase;
    Chatbot(vector <string> _nombres,vector <string> _preguntas,string _tienda,string _catchphrase){
        nombres_bot = _nombres;
        questions = _preguntas;
        tienda = _tienda;
        catchphrase = _catchphrase;
    }
    
    vector <string> get_pregunstas(){
        return questions;
    }

    void set_preguntas(vector <string> _preguntas){
        questions = _preguntas;
    }

    vector <string> get_nombres(){
        return nombres_bot;
    }

    void set_nombres(vector <string> _nombres){
        nombres_bot = _nombres;
    }
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
                cout << "Disculpa! Parece que yo no puedo ayudarte con tu problema, te transferire al area correspondiente para tratarlo, vale? :)\nFue un gusto atenderte."<<catchphrase<<endl;
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

    int inicializar_bot()
    {
        
        srand ( time(NULL));
        int name_select = rand() % nombres_bot.size();
        cout << "Hola bienvenido a servicio al cliente de " <<tienda<<"\n"<<catchphrase<<"\nHola mi nombre es "<< nombres_bot[name_select] << " y estoy para servirte.\n";
        
        int decision = 2;
        int request_result;
        
        request_result = solicitar_problema(questions);
        decision = confirmar_decision();
        while (decision != 1)
        {
            request_result = solicitar_problema(questions);

            decision = confirmar_decision();

        }
        return request_result;
    }

};

int main()
{

Chatbot cb_sears({"Homero","Krusty","Bart","Bort","Hank Scorpio","Cosme Fulanito","El senor Bolainas","Smithers"},
    {"Compras en Linea Sears","Devoluciones","Servicio al Cliente"},
    "Sears",
    "Sears me Entiende");
Chatbot cb_coppel({"Miguel","Santiago","Samuel","Lorena","Maria","Roxana"},
    {"Pago tarjeta Coppel","Revisar Deuda","Banca Coppel"},
    "Coppel",
    "Coppel mejora tu vida");

Chatbot cb_asus({"Joanna","Ricardo","Karla","Dolores","William","Dakota"},
    {"Solicitud de Servicio","Soporte Tecnico","Ventas","Garantia"},
    "ASUS",
    "In Search of Incredible");
//Demo
int problema_usuario = cb_coppel.inicializar_bot();

return 0;

}

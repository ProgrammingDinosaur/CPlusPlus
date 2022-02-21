
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class CitaGym {
private:
    string nombre_completo;
    int duracion_horas = 1;
    int duracion_minutos = 30;
    vector<int> ids_credencial ={8352,43523,3325245};
        int id_usuario = 0;


   public: 
        int hora_entrada = 12;
        int minutos_entrada= 0;
        int hora_salida = 0;
        int minutos_salida = 0;
        string gym_name = "GYM GYM";
   
        CitaGym(string nombre, int credencial) {
            cout << "Bienvenido a Gimnasio " << gym_name << endl;
            cout << "Hola " <<nombre << " comenzando tu registro..." << endl;
            nombre_completo = nombre;
            id_usuario = credencial;
            bool valido = false;
            for(int id : ids_credencial)
            {
                if (id_usuario == id)
                {
                    valido = true;
                    break;
                    
                }
            }
            if (valido) {
                cout << "Bienvenido " << nombre_completo << endl;
            }
            else {
                cout << "No apareces en el registro, te recomendamos comprar una suscripcion"<<endl;
            }

        }




};

class Persona {
public:
    int id_credencial;
    string nombre;

    Persona(string _nombre, int credencial) {
        nombre = _nombre;
        id_credencial = credencial;
    }
};


int main()
{
    Persona p1("Roberto",899989);
    Persona p2("Gerardo",8352);

    CitaGym cita1(p1.nombre,p1.id_credencial);
    CitaGym cita2(p2.nombre, p2.id_credencial);


}

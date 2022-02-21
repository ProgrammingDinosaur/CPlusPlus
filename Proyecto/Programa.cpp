
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class CitaGym {
    private:
        string nombre_completo;
        int duracion_horas = 1;
        int duracion_minutos = 30;
        vector<int> ids_credencial;
        int id_usuario = 0;

   public: 
        int hora_entrada = 12;
        int minutos_entrada= 0;
        int hora_salida = 0;
        int minutos_salida = 0;
        string gym_name = "";
   
        CitaGym(string nombre_gym,vector <int> credencial_ids_validos ) {

            gym_name = nombre_gym;
            cout << "Bienvenido a Gimnasio " << gym_name<<endl;
            ids_credencial = credencial_ids_validos;
        }

        void creador_cita(string nombre, int credencial) {
            cout << "Hola Continua tu registro a continuacion: " << endl;
            nombre_completo = nombre;
            id_usuario = credencial;
            bool valido = false;
            for(int id : ids_credencial)
            {
                if (id_usuario == id)
                {
                    valido = true;
                    cout << "Bienvenido"<<endl;
                    break;
                    
                }
            }
            if (valido) {
                cout << "Ingresa la hora de ingreso: ";
            }
            else {
                cout << "No apareces en el registro, te recomendamos comprar una suscripcion";
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
    Persona p1("Roberto", 899989);
    Persona p2("Gerardo", 90);
    CitaGym gym1("Gym default", { 342,32434,44224284 });
    gym1.creador_cita(p1.nombre,p1.id_credencial);

}

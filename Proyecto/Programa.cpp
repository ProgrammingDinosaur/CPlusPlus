
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class CitaGym {
    struct Hora
    {
        int horas = 0;
        int minutos = 0;
    };
    private:
        string nombre_completo;
        vector<int> ids_credencial ={8352,43523,3325245};
        int id_usuario = 0;
        struct Hora duracion;


    public: 
        int hora_entrada = 12;
        int minutos_entrada= 0;
        int dur_hor = 0;
        int dur_min = 0;
        string gym_name = "GYM GYM";
   
        CitaGym(string nombre, int credencial,int hora_ent,int min_ent,int horas_dur,int minu_dur) {
            cout << "Bienvenido a Gimnasio " << gym_name << endl;
            cout << "Hola " <<nombre << " comenzando tu registro..." << endl;
            hora_entrada = hora_ent;
            dur_hor = horas_dur;
            dur_min = minu_dur;
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
        void cambiar_ids_validos(vector<int> ids_new) {
            ids_credencial = ids_new;
        }

        vector<int> get_valid_ids() {
            return ids_credencial;
        }

        struct Hora calcular_duracion(int hora_ent,int min_ent,int hora_dura,int min_dura) {
            struct Hora hora_sal= { 0,0 };
            int min_dif = min_ent + min_dura;
            if (min_dif >= 60) {
                hora_sal.horas = hora_ent + hora_dura + 1;
                hora_sal.minutos = min_dif - 60;

            }
            else {

                hora_sal.horas = hora_ent + hora_dura;
                hora_sal.minutos = min_dif;

            }
            return hora_sal;
        }

        void registrar_salida() {
            struct Hora hora_salida = calcular_duracion(hora_entrada, minutos_entrada, dur_hor, dur_min);
            cout <<nombre_completo << " Empezando Registro de salida... Hora de Salida " << to_string(hora_salida.horas) << ":" << to_string(hora_salida.minutos) <<endl;
            cout << "Gracias por tu visita " << nombre_completo;
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
    //Persona Parametros
    //1.Nombre, 2. ID
    Persona p1("Roberto",899989);
    Persona p2("Gerardo",8352);

    //Cita GYM Parametros:
    //1.Nombre Persona 2. ID 3. Hora Entrada (Horas) 4.Hora entrada (Minutos) 5.Duracion cita (Horas) 6. Duracion cita (Minutos)
    //Cita GYM Métodos
    CitaGym cita1(p1.nombre,p1.id_credencial,12,30,1,30); //Entrada Roberto
    CitaGym cita2(p2.nombre, p2.id_credencial,14,30,1,30); //Entrada Gerardo
    cita2.registrar_salida(); //Salida Gerardo

}

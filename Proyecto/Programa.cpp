
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

class CitaGym {
    struct Hora
    {
        int horas = 0;
        int minutos = 0;
    };
    private:
        string nombre_completo;
        vector<int> ids_credencial ={10,56,89,32,66,98,99,12,0,1,2,3,4,5,6,7,8,9,76,77,24,44};
        int id_usuario = 0;
        struct Hora duracion;
        bool valid_entry = false;

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
            valid_entry = false;
            for(int id : ids_credencial)
            {
                if (id_usuario == id)
                {
                    valid_entry = true;
                    break;
                    
                }
            }
            if (valid_entry) {
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

        void registrar_salida(vector<string> maquinas_usadas = {}) {
            if (valid_entry) {
                struct Hora hora_salida = calcular_duracion(hora_entrada, minutos_entrada, dur_hor, dur_min);
                cout << nombre_completo << " Empezando Registro de salida... Hora de Salida "
                    << to_string(hora_salida.horas) << ":" << to_string(hora_salida.minutos)
                        << " " <<"Usted uso "<<maquinas_usadas.size()<<" maquinas" << endl;
                cout << "Gracias por tu visita " << nombre_completo << endl;
            }
        }


};

class Persona {
public:
    int id_credencial;
    string nombre;


    Persona(string _nombre, int credencial = 0) {
        nombre = _nombre;
        id_credencial = credencial;
    }
};


int main()
{
    srand(time(NULL));
    Persona p1("Roberto", (rand()%99));
    Persona p2("Gerardo", (rand() % 99));
    Persona p3("Hugo", (rand() % 99));
    Persona p4("Daniel", (rand() % 99));
    Persona p5("Paula", (rand() % 99));
    Persona p6("Manuel", (rand() % 99));
    Persona p7("Martina", (rand() % 99));
    Persona p8("Alberto", (rand() % 99));
    Persona p9("Ivan", (rand() % 99));
    Persona p10("Oscar", (rand() % 99));

    Persona p11("Ana", (rand() % 99));
    Persona p12("Jaime", (rand() % 99));
    Persona p13("Lucia", (rand() % 99));
    Persona p14("Valeria", (rand() % 99));
    Persona p15("Antonio", (rand() % 99));
    Persona p16("Silvia", (rand() % 99));
    Persona p17("Marco", (rand() % 99));
    Persona p18("Gael", (rand() % 99));
    Persona p19("Alejandra", (rand() % 99));
    Persona p20("Carla", (rand() % 99));

    Persona p21("Raul", (rand() % 99));
    Persona p22("Camila", (rand() % 99));
    Persona p23("Miguel", (rand() % 99));
    Persona p24("Jonathan", (rand() % 99));
    Persona p25("Miguel", (rand() % 99));
    Persona p26("Sofia", (rand() % 99));
    Persona p27("Andres", (rand() % 99));
    Persona p28("Vanessa", (rand() % 99));
    Persona p29("Jimena", (rand() % 99));
    Persona p30("Maria", (rand() % 99));

    Persona p31("Cesar", (rand() % 99));
    Persona p32("Elisa", (rand() % 99));
    Persona p33("Joab", (rand() % 99));
    Persona p34("Pablo", (rand() % 99));
    Persona p35("Fernanda", (rand() % 99));
    Persona p36("Eduardo", (rand() % 99));
    Persona p37("Luis", (rand() % 99));
    Persona p38("Emma", (rand() % 99));
    Persona p39("Sebastian", (rand() % 99));
    Persona p40("Isabella", (rand() % 99));

    //Cita GYM Parametros:
    //1.Nombre Persona 2. ID 3. Hora Entrada (Horas) 4.Hora entrada (Minutos) 5.Duracion cita (Horas) 6. Duracion cita (Minutos)
    //Cita GYM Métodos
    CitaGym cita1(p1.nombre, p1.id_credencial, 12, 30, 1, 30); //Entrada Roberto
    CitaGym cita2(p2.nombre, p2.id_credencial, 14, 30, 1, 30); //Entrada Gerardo
    CitaGym cita3(p3.nombre, p3.id_credencial, 14, 30, 1, 30); //Entrada Hugo
    CitaGym cita4(p4.nombre, p4.id_credencial, 14, 30, 1, 30); //Entrada Daniel
    CitaGym cita5(p5.nombre, p5.id_credencial, 14, 30, 1, 30); //Entrada Paula
    CitaGym cita6(p6.nombre, p6.id_credencial, 14, 30, 1, 30); //Entrada Manuel
    CitaGym cita7(p7.nombre, p7.id_credencial, 14, 30, 1, 30); //Entrada Martina
    CitaGym cita8(p8.nombre, p8.id_credencial, 14, 30, 1, 30); //Entrada Alberto
    CitaGym cita9(p9.nombre, p9.id_credencial, 14, 30, 1, 30); //Entrada Ivan
    CitaGym cita10(p10.nombre, p10.id_credencial, 14, 30, 1, 30); //Entrada Oscar
    CitaGym cita11(p11.nombre, p11.id_credencial, 14, 30, 1, 30); //Entrada Ana
    CitaGym cita12(p12.nombre, p12.id_credencial, 14, 30, 1, 30); //Entrada Jaime
    CitaGym cita13(p13.nombre, p13.id_credencial, 14, 30, 1, 30); //Entrada Lucia
    CitaGym cita14(p14.nombre, p14.id_credencial, 14, 30, 1, 30); //Entrada Valeria
    CitaGym cita15(p15.nombre, p15.id_credencial, 14, 30, 1, 30); //Entrada Antonio
    CitaGym cita16(p16.nombre, p16.id_credencial, 14, 30, 1, 30); //Entrada Silvia
    CitaGym cita17(p17.nombre, p17.id_credencial, 14, 30, 1, 30); //Entrada Marco
    CitaGym cita18(p18.nombre, p18.id_credencial, 14, 30, 1, 30); //Entrada Gael
    CitaGym cita19(p19.nombre, p19.id_credencial, 14, 30, 1, 30); //Entrada Alejandra
    CitaGym cita20(p20.nombre, p20.id_credencial, 14, 30, 1, 30); //Entrada Carla
    CitaGym cita21(p21.nombre, p21.id_credencial, 14, 30, 1, 30); //Entrada Raul
    CitaGym cita22(p22.nombre, p22.id_credencial, 14, 30, 1, 30); //Entrada Camila
    CitaGym cita23(p23.nombre, p23.id_credencial, 14, 30, 1, 30); //Entrada Miguel
    CitaGym cita24(p24.nombre, p24.id_credencial, 14, 30, 1, 30); //Entrada Jonathan
    CitaGym cita25(p25.nombre, p25.id_credencial, 14, 30, 1, 30); //Entrada Miguel
    CitaGym cita26(p26.nombre, p26.id_credencial, 14, 30, 1, 30); //Entrada Sofia
    CitaGym cita27(p27.nombre, p27.id_credencial, 14, 30, 1, 30); //Entrada Andres
    CitaGym cita28(p28.nombre, p28.id_credencial, 14, 30, 1, 30); //Entrada Vanessa
    CitaGym cita29(p29.nombre, p29.id_credencial, 14, 30, 1, 30); //Entrada Jimena
    CitaGym cita30(p30.nombre, p30.id_credencial, 14, 30, 1, 30); //Entrada Maria
    CitaGym cita31(p31.nombre, p31.id_credencial, 14, 30, 1, 30); //Entrada Cesar
    CitaGym cita32(p32.nombre, p32.id_credencial, 14, 30, 1, 30); //Entrada Elisa
    CitaGym cita33(p33.nombre, p33.id_credencial, 14, 30, 1, 30); //Entrada Joab
    CitaGym cita34(p34.nombre, p34.id_credencial, 14, 30, 1, 30); //Entrada Pablo
    CitaGym cita35(p35.nombre, p35.id_credencial, 14, 30, 1, 30); //Entrada Fernanda
    CitaGym cita36(p36.nombre, p36.id_credencial, 14, 30, 1, 30); //Entrada Eduardo
    CitaGym cita37(p37.nombre, p37.id_credencial, 14, 30, 1, 30); //Entrada Luis
    CitaGym cita38(p38.nombre, p38.id_credencial, 14, 30, 1, 30); //Entrada Emma
    CitaGym cita39(p39.nombre, p39.id_credencial, 14, 30, 1, 30); //Entrada Sebastian
    CitaGym cita40(p40.nombre, p40.id_credencial, 14, 30, 1, 30); //Entrada Isabela


    //Salida toma el argumento de máquinas, seguir ejmeplo de "Gerardo"
    cita1.registrar_salida({"Elpitica","Caminadora"}); //Salida Gerardo
    cita2.registrar_salida();
    cita3.registrar_salida();
    cita4.registrar_salida();
    cita5.registrar_salida();
    cita6.registrar_salida();
    cita7.registrar_salida();
    cita8.registrar_salida();
    cita9.registrar_salida();
    cita10.registrar_salida();
    cita11.registrar_salida();
    cita12.registrar_salida();
    cita13.registrar_salida();
    cita14.registrar_salida();
    cita15.registrar_salida();
    cita16.registrar_salida();
    cita17.registrar_salida();
    cita18.registrar_salida();
    cita19.registrar_salida();
    cita20.registrar_salida();
    cita21.registrar_salida();
    cita22.registrar_salida();
    cita23.registrar_salida();
    cita24.registrar_salida();
    cita25.registrar_salida();
    cita26.registrar_salida();
    cita27.registrar_salida();
    cita28.registrar_salida();
    cita29.registrar_salida();
    cita30.registrar_salida();
    cita31.registrar_salida();
    cita32.registrar_salida();
    cita33.registrar_salida();
    cita34.registrar_salida();
    cita35.registrar_salida();
    cita36.registrar_salida();
    cita37.registrar_salida();
    cita38.registrar_salida();
    cita39.registrar_salida();
    cita40.registrar_salida();

}



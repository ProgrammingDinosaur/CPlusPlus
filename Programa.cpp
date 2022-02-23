
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <map>

using namespace std;


class Persona {
public:
    int id_credencial;
    string nombre;
    int cita_asignada;
    Persona(string _nombre, int credencial = 0) {
        nombre = _nombre;
        id_credencial = credencial;
    }

};

class CitaGym {
    struct Hora
    {
        int horas = 0;
        int minutos = 0;
    };
private:
    string nombre_completo;
    vector<int> ids_credencial = { 10,56,89,32,66,98,99,12,0,1,2,3,4,5,6,7,8,9,76,77,24,44 };
    int id_usuario = 0;
    struct Hora duracion;
    bool valid_entry = false;
    int cita_id;

public:
    int hora_entrada = 12;
    int minutos_entrada = 0;
    int dur_hor = 0;
    int dur_min = 0;
    string gym_name = "GYM GYM";

    CitaGym(Persona& personi, int hora_ent, int min_ent, int horas_dur, int minu_dur) {

        cout << "Bienvenido a Gimnasio " << gym_name << endl;
        cout << "Hola " << personi.nombre << " comenzando tu registro..." << endl;
        hora_entrada = hora_ent;
        dur_hor = horas_dur;
        dur_min = minu_dur;
        nombre_completo = personi.nombre;
        id_usuario = personi.id_credencial;
        valid_entry = false;
        cita_id = rand() % 9999;
        personi.cita_asignada = cita_id;
        for (int id : ids_credencial)
        {
            if (id_usuario == id)
            {
                valid_entry = true;
                break;

            }
        }
        if (valid_entry) {
            cout << "===Bienvenido===\nGimnasio ==="<<gym_name<<"===\n" << nombre_completo << " se te ha asignado la cita #" << cita_id << "\n\n";
        }
        else {
            cout << nombre_completo<< " No apareces en el registro, te recomendamos comprar una suscripcion" << "\n";
            cout << "Contamos con menusalidad e inscripcion" << endl;
            cout << "La mensualidad tiene un costo de $500.00" << endl;
            cout << "Y la inscripcion es una vez y tiene un costo de 200\n\n";
        }

    }
    void cambiar_ids_validos(vector<int> ids_new) {
        ids_credencial = ids_new;
    }

    vector<int> get_valid_ids() {
        return ids_credencial;
    }

    struct Hora calcular_duracion(int hora_ent, int min_ent, int hora_dura, int min_dura) {
        struct Hora hora_sal = { 0,0 };
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
                << " " << "Usted uso " << maquinas_usadas.size() << " maquinas" << endl;
            cout << "Gracias por tu visita " << nombre_completo << "\n\n";
        }
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
    CitaGym cita1(p1, 12, 30, 1, 30); //Entrada Roberto
    CitaGym cita2(p2, 14, 30, 1, 30); //Entrada Gerardo
    CitaGym cita3(p3, 14, 30, 1, 30); //Entrada Hugo
    CitaGym cita4(p4, 14, 30, 1, 30); //Entrada Daniel
    CitaGym cita5(p5, 14, 30, 1, 30); //Entrada Paula
    CitaGym cita6(p6, 14, 30, 1, 30); //Entrada Manuel
    CitaGym cita7(p7, 14, 30, 1, 30); //Entrada Martina
    CitaGym cita8(p8, 14, 30, 1, 30); //Entrada Alberto
    CitaGym cita9(p9, 14, 30, 1, 30); //Entrada Ivan
    CitaGym cita10(p10, 14, 30, 1, 30); //Entrada Oscar
    CitaGym cita11(p11, 14, 30, 1, 30); //Entrada Ana
    CitaGym cita12(p12, 14, 30, 1, 30); //Entrada Jaime
    CitaGym cita13(p13, 14, 30, 1, 30); //Entrada Lucia
    CitaGym cita14(p14, 14, 30, 1, 30); //Entrada Valeria
    CitaGym cita15(p15, 14, 30, 1, 30); //Entrada Antonio
    CitaGym cita16(p16, 14, 30, 1, 30); //Entrada Silvia
    CitaGym cita17(p17, 14, 30, 1, 30); //Entrada Marco
    CitaGym cita18(p18, 14, 30, 1, 30); //Entrada Gael
    CitaGym cita19(p19, 14, 30, 1, 30); //Entrada Alejandra
    CitaGym cita20(p20, 14, 30, 1, 30); //Entrada Carla
    CitaGym cita21(p21, 14, 30, 1, 30); //Entrada Raul
    CitaGym cita22(p22, 14, 30, 1, 30); //Entrada Camila
    CitaGym cita23(p23, 14, 30, 1, 30); //Entrada Miguel
    CitaGym cita24(p24, 14, 30, 1, 30); //Entrada Jonathan
    CitaGym cita25(p25, 14, 30, 1, 30); //Entrada Miguel
    CitaGym cita26(p26, 14, 30, 1, 30); //Entrada Sofia
    CitaGym cita27(p27, 14, 30, 1, 30); //Entrada Andres
    CitaGym cita28(p28, 14, 30, 1, 30); //Entrada Vanessa
    CitaGym cita29(p29, 14, 30, 1, 30); //Entrada Jimena
    CitaGym cita30(p30, 14, 30, 1, 30); //Entrada Maria
    CitaGym cita31(p31, 14, 30, 1, 30); //Entrada Cesar
    CitaGym cita32(p32, 14, 30, 1, 30); //Entrada Elisa
    CitaGym cita33(p33, 14, 30, 1, 30); //Entrada Joab
    CitaGym cita34(p34, 14, 30, 1, 30); //Entrada Pablo
    CitaGym cita35(p35, 14, 30, 1, 30); //Entrada Fernanda
    CitaGym cita36(p36, 14, 30, 1, 30); //Entrada Eduardo
    CitaGym cita37(p37, 14, 30, 1, 30); //Entrada Luis
    CitaGym cita38(p38, 14, 30, 1, 30); //Entrada Emma
    CitaGym cita39(p39, 14, 30, 1, 30); //Entrada Sebastian
    CitaGym cita40(p40, 14, 30, 1, 30); //Entrada Isabela


    //Salida toma el argumento de máquinas, seguir ejmeplo de "Gerardo"
    cita1.registrar_salida({ "Caminadora","Eliptica","Remo" });
    cita2.registrar_salida({ "Caminadora", "Mancuernas", "press de banca" });
    cita3.registrar_salida({ "Eliptica", "bicicleta", "remo con mancuernas", "prensa" });
    cita4.registrar_salida({ "Caminadora", "escalera infinita", "sentadilla con barra", "gluteo" });
    cita5.registrar_salida({ "Eliptica", "bicicleta", "abductores", "femoral" });
    cita6.registrar_salida({ "Fondos", "bicep", "tricep" });
    cita7.registrar_salida({ "Caminadora", "Sentadilla bulgara", "Burpees" });
    cita8.registrar_salida({ "Eliptica", "sentadilla perfecta", "copa a una mano" });
    cita9.registrar_salida({ "Caminadora", "Remo", "Cuadricep" });
    cita10.registrar_salida({ "Bicicleta" "Tricep con cuerda", "escalera infinita" });

    cita11.registrar_salida({ "Caminadora", "Espalda baja", "Remo con mancuernas" });
    cita12.registrar_salida({ "Eliptica", "Jalon con barra", "Fondos" });
    cita13.registrar_salida({ "Bicicleta", "Burpees", "Bicep con mancuernas" });
    cita14.registrar_salida({ "Burpees", "Tricep con cuerda", "Jalon con mancuerna" });
    cita15.registrar_salida({ "Caminadora", "Press de pecho", "Pecho con mancuernas" });
    cita16.registrar_salida({ "Eliptica", "Escalera infinita", "Desplantes", "Prensa" });
    cita17.registrar_salida({ "Bicicleta", "sentadilla perfecta", "femoral" });
    cita18.registrar_salida({ "Caminadora", "Deltoides con mancuerna", "Press militar" });
    cita19.registrar_salida({ "Eliptica", "Peso muerto", "Jalon con barra" });
    cita20.registrar_salida({ "Caminadora", "Escalera infinita", "Bicep" ,"Tricep" });

    cita21.registrar_salida({ "Burpees", "Jalon con barra", "fondos", "REMO con mancuerna" });
    cita22.registrar_salida({ "Escalera infinita", "Caminadora", "sentadilla con barra", "gluteo" });
    cita23.registrar_salida({ "Eliptica", "Caminadora", "Press de pecho", "fondos" });
    cita24.registrar_salida({ "Caminadora", "Abductores", "femoral" });
    cita25.registrar_salida({ "Press de banca", "Fondos", "Press con mancuerna" });
    cita26.registrar_salida({ "Eliptica", "Desplantes", "sentadilla con barra" });
    cita27.registrar_salida({ "Caminadora", "eliptica", "Prensa" ,"Deltoides con mancuerna" });
    cita28.registrar_salida({ "Bicicleta", "peso muerto", "tricep", "bicep" });
    cita29.registrar_salida({ "Eliptica", "press militar", "cuadricep" });
    cita30.registrar_salida({ "Caminadora", "Burpees", "remo con mancuerna" });

    cita31.registrar_salida({ "Eliptica", "Escalera infinita", "cuadricep", "femoral" });
    cita32.registrar_salida({ "Caminadora", "Tricep con cuerda", "Copa a una mano" });
    cita33.registrar_salida({ "Caminadora" "Abdominales", "Burpees" });
    cita34.registrar_salida({ "Burpees", "Press de banca", "Fondos" });
    cita35.registrar_salida({ "Bicicleta", "Abductores", "Jalon con barra", "Desplantes" });
    cita36.registrar_salida({ "Eliptica", "abdominales", "peso muerto" });
    cita37.registrar_salida({ "Caminadora", "Sentadilla perfecta", "sentadilla con barra" });
    cita38.registrar_salida({ "Eliptica", "Abdominales", "sentadilla bulgara" });
    cita39.registrar_salida({ "Bicicleta", "Gluteo", "Jalon con mancuerna" });
    cita40.registrar_salida({ "Burpees", "Press militar", "fondos", "remo" });
}



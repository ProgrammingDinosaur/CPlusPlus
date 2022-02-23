//Librerías
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std; //Espacio de Trabajo Std

/**
*Clase Persona
*Miembros Publicos: 1.id_credencial (int) 2. Nombre (string) 3. Cita asignada (int)
*Constructor :Toma el nombre (string) de la persona y el id (int) de la credencial, los asigna a los miembros correspondientes
*/
class Persona {
public:
    int id_credencial;
    string nombre;
    int cita_asignada;

    /**Constructor
    * Asigna los parametros a los miembros Nombre y ID
    *   Parametros:
    *       _nombre: string con el nombre
    *       credencial: id de la credencial
    */
    Persona(string _nombre, int credencial = 0) {
        //Asigna Variables
        nombre = _nombre;
        id_credencial = credencial;
    }

};
/**
*Clase Cita GYM
*Miembros Privados: 1.Nombre (string) 2.Ids de credencial validos (vector <int>) 3.Id Usuario (int) 4. Duracion (struct Hora)
*                    5.Entrada valida (bool) 6 Cita id (int)
* Miembros Publicos: 1. Hora entrada (int) 2. Minutos Entrada (int) 3.Duracion Horas (int), valor default: 0 
*                    4.Nombre Gym (string) 5. Arreglo con hora de salida y hora de entrada (idx: 0 = entrada, idx: 1= salida)
*Constructor :Toma una referencia a la persona, la hora y minutos de entrada, así como la duaración en horas y minutos que estará en el GYM
*             De la referencia a Persona toma los miembros id y nombre y los asigna a miembros propios de la clase CitaGym
*             También asigna la hora de entrada y de salida a las variables para eso
*              Ocurre lo mismo con la duración
*/
class CitaGym {
    //Definicion Struct Personalizada para almacenar horas
    struct Hora
    {
        int horas = 0;
        int minutos = 0;
    };
private:
    string nombre_completo;
    //Definir ids de personas que pueden entrar
    vector<int> ids_credencial = { 10,56,89,32,66,98,99,12,0,1,2,3,4,5,6,7,8,9,76,77,24,44,11,98 }; 
    int id_usuario = 0;
    struct Hora duracion;
    bool valid_entry = false;
    int cita_id;

public:
    int hora_entrada ;
    int minutos_entrada;
    int dur_hor = 0;
    int dur_min = 0;
    int horario[2] = { 7, 20 };
    string gym_name = "GYM GYM";  //Nombre GYM

    /** Constructor
    *   
    *   Asigna las variables a los miembros correspondientes
    *   Revisa si la cita es en horario valido
    *   Genera id de cita
    *   Checa si credencial es valida y ejecuta la acción correspondiente
    * 
    *   Parametros: 
    *       Personi: Referencia a objeto de tipo Persona
    *       hora_ent: int con la hora de entrada
    *       min_ent: int con el minuto de entrada
    *       horas_dur: int con las horas que la persona estará en el gym
    *       minu_dur: int con los minutos que estará la persona en el gym
    */
    CitaGym(Persona& personi, int hora_ent, int min_ent, int horas_dur, int minu_dur) {

        //Da la bienvenida al usuario
        cout << "Bienvenido a Gimnasio " << gym_name << endl;
        cout << "Hola " << personi.nombre << " comenzando tu registro..." << endl;

        //Asignar Variables
        hora_entrada = hora_ent;
        dur_hor = horas_dur;
        dur_min = minu_dur;
        nombre_completo = personi.nombre;
        id_usuario = personi.id_credencial;
        valid_entry = false;
        //Numero de Cita aleatorio
        cita_id = rand() % 9999;
        personi.cita_asignada = cita_id;
        //Revisa si la cita se genera en un horario válido, si es así permite seguir
        //De lo contrario rechaza al usuario y le dice los horarios válidos
        if (hora_ent > horario[0] && hora_ent < horario[1]) {
        //Loop que revisa si el id de credencial es valido, es decir, se encuentra en el vector de ids validos
        for (int id : ids_credencial)
        {
            if (id_usuario == id)
            {
                valid_entry = true;
                break;

            }
        }
        //Si la credencial es valida dar bienvenida al servicio y dar id generado
        if (valid_entry) {
            cout << "===Bienvenido===\nGimnasio ===" << gym_name << "===\n" << nombre_completo << " se te ha asignado la cita #" << cita_id << "\n\n";
        }
        //Si no es valida ofrecer opciones para comprar suscripcion al GYM
        else {
            cout << nombre_completo << " No apareces en el registro, te recomendamos comprar una suscripcion" << "\n";
            cout << "Contamos con menusalidad e inscripcion" << endl;
            cout << "La mensualidad tiene un costo de $500.00" << endl;
            cout << "Y la inscripcion es una vez y tiene un costo de 200\n\n";
        }
        }
        else {

            cout << "Usted esta intentando hacer una cita en un horario que el GYM no esta abierto\nIntente con otro horario, recuerde abrimos de " <<
                horario[0] << " a " << horario[1];
        }
    }
    //Setter de los ids validos
    void cambiar_ids_validos(vector<int> ids_new) {
        ids_credencial = ids_new;
    }
    //Getter de los ids validos
    vector<int> get_valid_ids() {
        return ids_credencial;
    }

    /**
    * Función calcular duracíón
    *   
    *   Suma la hora de entrada y la duración para obtener hora de salida
    * 
    *   Parametros:
    *       hora_ent: int de la hora de entrada
    *       min_ent: int del minuto de entrada
    *       hora_dura: int con las horas de duración de la sesión
    *       min_dura: int con los minutos de duración de la sesión
    *       
    *   Regresa: Structura de tipo Hora que contiene hora y minuto de salida.
    */
    struct Hora calcular_duracion(int hora_ent, int min_ent, int hora_dura, int min_dura) {
        struct Hora hora_sal = { 0,0 };
        int min_dif = min_ent + min_dura;
        //Suma 1 a las horas y resta 60  a los  minutos si la suma de estos es mayor a 60
        //Si no suman 60 los minutos la suma es tal cual
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
    /**
    * Función Registrar Salida
    *   Calcula la hora de salida, la registra y le da la despedida al usuario. Así como un resumen de su sesión
    *   
    *   Parámetros:
    *      maquinas_usadas: vector de string que contendrá las máquinas usadas durante la sesión (valor por defecto ={})
    *     
    */
    void registrar_salida(vector<string> maquinas_usadas = {}) {
        if (valid_entry) {
            struct Hora hora_salida = calcular_duracion(hora_entrada, minutos_entrada, dur_hor, dur_min);//Llama función "calcular duración"
            cout << nombre_completo << " Empezando Registro de salida... Hora de Salida "
                << to_string(hora_salida.horas) << ":" << to_string(hora_salida.minutos)
                << " " << "Usted uso " << maquinas_usadas.size() << " maquinas" << endl;
            cout << "Gracias por tu visita " << nombre_completo << "\n\n";
        }
    }


};

//Main
int main()
{
    srand(time(NULL)); //Semilla "Aleatoria"

    //Creación de Personas con Argumentos  1. Nombre   2. ID
    //Asignación aleatoria de ID (0-100)
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


    //Registro de Salidas con el parametro de las maquinas usadas en un Vector
    //La salida se registra con la instancia de la cita

    cita1.registrar_salida({ "Caminadora","Eliptica","Remo" }); //Vector con Caminadora, Eliptica y Remo
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



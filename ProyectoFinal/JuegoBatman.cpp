#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <unordered_map> //Regresar variables de diferente tipo
#include <Windows.h>

using namespace std;


class Player {
public:
	bool estaVivo = true;
	int puntaje = 0;

};

class Pregunta
{

public:
	//(String (Pregunta), (String[] opciones, int (opcion correcta))
	unordered_map<string, tuple<vector<string>, int>> pregunta =
	{	//Pregunta
		{"Puede ser cruel, poetico o ciego. Pero cuando se niega, es violencia lo que puedes encontrar.",
		//Opciones
		{{"Justicia","La politica","Amor","Violencia"},
		//Indice (0-3) respuesta correcta
		0}}, //Arreglos empiezan en 0, opciones: 0,1,2,3... (ordenados)
		//Pregunta
		{"Que hace un mentiroso cuando esta muerto?",
		//Opciones
		{{"Se muere","Canta","Sigue Mintiendo","Nace"},
		//Indice (0-3) respuesta correcta
		2}},
		{"Batman es bueno?",
		//Opciones
		{{"Falso","Verdadero"},
		//Indice (0-1) respuesta correcta (0 Falso, 1 Verdadero)
		1}},



	};
		//NO SE USA
		/*void ComenzarJuegoTodosAcertijos() {
			cout << "JAJA, QUE COMIENCEN LOS ACERTIJOS\n\n";
			for (auto iterador: pregunta){
				cout << iterador.first<<endl;
				int counter = 1;
				for (auto opcion : get<0>(iterador.second)) {
					cout << counter<<". " << opcion << endl;
					counter++;
				}
				int answerIdx;
				cout << "Ingresa el numero de tu respuesta: ";
				cin >> answerIdx;
				answerIdx += 1;
				if (answerIdx == get<1>(iterador.second)) {
					cout << "Sobreviviste\n";

				}
				else {
					cout << "Has muerto\n";
				}
				system("pause");
				system("cls");
			}
		}*/
		
		//Booleano sobre si el jugador vive (Verdadero), 
		// O muere (falso)
		bool PreguntaAleatoria() {
			//if que determine si es matematico o de texto NO ESTA IMPLEMENTADO AUN->JOSE
			int idxSelected = rand() % pregunta.size();
			auto it = pregunta.begin(); //"Truco" para indice aleatorio
			advance(it, idxSelected); // "Truco" parte 2 (0+Random)
			string key = it->first; //Mapa, (First(String),Second(Opciones, repsuesta))
			// key (pregunta)  -> acceder a las opciones y a la repsuesta
			cout << key << endl; //Imprimir pregunta 
			int counter = 1; 
			//auto -> arreglo 
			// preguntas : iterar por todas las respuestas
			// Pregunta accede (Opciones, respuesta) get<0> obtiene el primero que son las opciones
			for (auto preguntas: get<0>(it->second)) {
				cout << counter << ". " << preguntas << endl;
				counter++;
				//1. Op1
				//2.OP2
				//3.OP3
				//ETC...
			}
			int repsuesta; //Contenedor de la repsuesta del jugador
			cout << "Ingresa el numero de tu respuesta: ";
			cin >> repsuesta;
			//get<1> (Respuesta) indice 
			if (repsuesta == get<1>(it->second)) {
				cout << "Es correcto!"<<endl;
				return true;
			}
			else {
				cout << "Te has equivocado, es hora de morir"<<endl;
				return false;
			}

		}

		//JOSE
		// ->
		//Hacer una funcion que genere 2 numeros aleatorios y pedir al jugador le resultado de su suma,
		//resta, multiplicacion o division (Switch case)
		// generar numero del 0 al 3
		// 0-> suma, 1 -> resta,2 -> division, 3 -> multiplicacion
		// Switch on ^
		//cin >> pedir el numero
		//If comparar la entrada  con el resultado real y determinar si el jugador muere
		//return resultado == entrada

		//EDUARDO->

};
	
class Puerta {

private:
	float probabilidadMorirPuerta1 = .50; //50% de morir
	float probabilidadMorirPuerta2 = .1; //1% de morir
	

public:

	//Se ejecuta despues
	float PJugadorMuere() {
		//Ilusion de eleccion
		int puertaSeleccionada = rand() % 2; //0-1 al azar
		switch (puertaSeleccionada) {
		//Puerta de muerte muy segura
		case 0:
			return probabilidadMorirPuerta1;
			break;
		case 1:
			//Puerta buena
			return probabilidadMorirPuerta2;
			break;

		}
	}

	//bool* ->*<- me permite regresar un arreglo
	bool* PuertaMagica() {
		bool results[2];
		cout << "Te encuentras ante 3 puertas, escoge 1,2 o 3: ";
		int puertaSeleccionada;
		cin >> puertaSeleccionada;
		//Ilusión de la elección
		//Puertas son aleatorias

		int acertijo = rand() % 3; //Donde esta el acertijo
		//Si caemos en el acertijo
			if (acertijo == puertaSeleccionada) {
				results[0] = true;
				results[1] = false;
				return results; //t,f
			}
			//Si no caimos en el acertijo
			else {
				//calculamos "probabilidad"
				float probabilidad = PJugadorMuere();
				//rand() ->(0-1) 0.01 / 0.87
				//si rand() > 50% morimos
				if (rand() > probabilidad) {
					results[0] = false;
					results[1] = true;
					return results; //f,t
				}
				else {
					results[0] = false;
					results[1] = false;
					return results; //f,f
				}
						
			}

	}


};
	
class GameLoop {
private:
	Puerta puerta; 
	Pregunta pregunta;
	Player player;
public:
	bool* puertaResultado;
	GameLoop() {
		puerta = Puerta();
		pregunta = Pregunta();
		player = Player();
	}

	void Juego() {
		//bool siGanoElJuego
		while (player.estaVivo) {
			//if player.puntaje == 5
			//{
			// break; para salir 
			//}
			//else

				player.puntaje++;
				puertaResultado = puerta.PuertaMagica(); //Hacerlo Pasar por una puerta
				//Resultado es un bool[2] 
				//resultado[0] es si el jugador paso por un acertijo
				//resultlado[1] es si se murio en la puerta
				bool acertijo = puertaResultado[0];
				bool murioporPendejo = puertaResultado[1];
				if (murioporPendejo) {
					player.estaVivo = false;
					cout << "Escogiste la puerta equivocada y has muerto"<<endl;
				}
				else if (acertijo) {
					//Hacerle la pregunta del acertijo
					//Asignamos si el juagdor esta vivo al resultado del acertijo
					player.estaVivo = pregunta.PreguntaAleatoria();


				}
				//No hubo acertijo pero tampoco te moriste en las puertas
				else {
					cout << "Escogiste bien y sobrevives otro dia para contarlo"<<endl;
				}
				
			}
		//EDUARDO ->
		//Si el jugador gana
		// IF
		//Hacer x cosa: Mensaje de felicidades 
		// return para no seguir
		//Si muere hacer lo que sigue ->
		cout << "Tu puntaje fue de: " << player.puntaje;
		return;
		
	}

};




int main()
{
	srand(time(NULL)); //Semilla aleatoria para random
	GameLoop juego = GameLoop(); //Inicializamos el juego
	juego.Juego(); //Comenzamos a jugar

	
}


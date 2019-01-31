// mazo.cpp
// Definición de la clase Mazo

#include "mazo.h"

// Constructor
// Inicializa el naipe con las cartas 
Mazo::Mazo() : naipe(nullptr), primera(0) {
	inicializar();
}

// Destructor
// Libera toda la memoria asignada al Mazo
Mazo::~Mazo() {
	//Eliminamos todas las cartas del mazo 
	for (int i = 0; i < NUMCARTAS; ++i)
		if (naipe[i] != nullptr)
			delete naipe[i];
	delete[] naipe;
}

// Inicializa un Mazo 
void Mazo::inicializar() {
	int maxCartas = 0;

	naipe = new Carta*[NUMCARTAS];

	// Inicializamos el mazo de cartas
	// 13 cartas por cada palo y todas boca abajo
	while (maxCartas < NUMCARTAS) {

		for (int i = 0; i < MAX_PALOS; ++i)
			for (int j = 1; j <= MAX_RANGO; ++j)
				naipe[maxCartas++] = new Carta(Rango(j), Palo(i), false);
	}
}

// Toma el mazo y desordena las cartas moviéndolas en diferentes posiciones del vector de manera aleatoria
// Utiliza la función 'random_shuffle' de la biblioteca estándar de C++ (Librería <algorithm>)
void Mazo::barajar() {
	
	// std::random_shuffle(naipe[0], naipe[NUMCARTAS - 1]);
}

// Función que obtiene la dirección de memoria de la primera carta del mazo y la retorna
// La siguiente carta del mazo es la primera
Carta* Mazo::tomarCarta() {
	Carta* tmp = naipe[primera];
	
	naipe[primera] = nullptr;
	++primera;
	
	return tmp;
}
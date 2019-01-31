// main.cpp

#include "mazo.h"
#include <iostream>

int main() {

	Mazo m;

	m.barajar();

	// Método para mostrar las cartas del mazo
	for (int i = 0; i < MAX_PALOS; ++i) {
		for (int j = 0; j < MAX_RANGO; ++j) {
			Carta* tmp = m.tomarCarta();
			std::cout << static_cast<int>(tmp->getValor()) << static_cast<int>(tmp->getPalo()) << " ";
			delete tmp;
		}
		std::cout << std::endl;
	} 

	return 0;
}
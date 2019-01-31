// main.cpp

#include "mazo.h"
#include <iostream>

int main() {
	Mazo m;

	//m.barajar();

	for (int i = 0; i < NUMCARTAS; ++i) {
		for (int j = 0; j < 13; ++j) {
			Carta* tmp = m.tomarCarta();
			std::cout << static_cast<int>(tmp->getValor()) << static_cast<int>(tmp->getPalo()) << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}
// juego.cpp
// Definición de la clase Juego

#include "juego.h"

Juego::Juego() : listaJugadores(nullptr), baraja(nullptr) { }

Juego::~Juego() { }

void Juego::run() {
	intro();
	menuPrincipal();
}

void Juego::intro(){
	HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD consolaAttr;

	if (!consola)
		EXIT_FAILURE;

	CONSOLE_SCREEN_BUFFER_INFO info;
	bool salir = false;
	int i = 0;

	GetConsoleScreenBufferInfo(consola, &info);
	consolaAttr = info.wAttributes;
	
	PlaySound(TEXT("intro.wav"), NULL, SND_FILENAME | SND_ASYNC);

	do {
		system("cls");

		if (i > NUM_COLORES)
			i = 1;

		SetConsoleTextAttribute(consola, i++);

		std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
		std::cout <<
			"\t\t.------..------..------..------..------..------..------..------..------." << std::endl <<
			"\t\t|B.--. ||L.--. ||A.--. ||C.--. ||K.--. ||J.--. ||A.--. ||C.--. ||K.--. |" << std::endl <<
			"\t\t| :(): || :/\\: || (\\/) || :/\\: || :/\\: || :(): || (\\/) || :/\\: || :/\\: |" << std::endl <<
			"\t\t| ()() || (__) || :\\/: || :\\/: || :\\/: || ()() || :\\/: || :\\/: || :\\/: |" << std::endl <<
			"\t\t| '--'B|| '--'L|| '--'A|| '--'C|| '--'K|| '--'J|| '--'A|| '--'C|| '--'K|" << std::endl <<
			"\t\t`------'`------'`------'`------'`------'`------'`------'`------'`------'";
		std::cout << std::endl << std::endl << std::endl;
		
		SetConsoleTextAttribute(consola, consolaAttr);
		std::cout << "\t\tPRESIONE ENTER PARA CONTINUAR...";

		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	
		if (GetAsyncKeyState(VK_RETURN))
			salir = true;

	} while (!salir);
	
	SetConsoleTextAttribute(consola, consolaAttr);
	PlaySound(NULL, 0, 0);
}

void Juego::menuPrincipal() {
	char opcion;
	bool salir = false;

	while (!salir) {
		do {
			system("cls");
			
			std::cout << "  -----------------------------" << std::endl;
			std::cout << "  1. NUEVA PARTIDA DE BLACKJACK" << std::endl;
			std::cout << "  2. CARGAR PARTIDA" << std::endl;
			std::cout << "  3. SALIR" << std::endl;
			std::cout << "  -----------------------------" << std::endl;
			std::cout << "         Opcion: ";

			std::cin.get(opcion);

		} while (opcion < '1' || opcion > '3');

		switch (opcion) {
		case '1':
			// nuevoJuego();
			break;
		case '2':
			// cargarJuego();
			break;
		case '3':
			salir = true;
			break;
		}
	}
}

void Juego::nuevoJuego() {
	int numJugadores;
	std::string nombreJugador;

	
	
	std::cin.ignore();
	std::cin.clear();

	do {
		system("cls");

		std::cout << "  ---------------------------------" << std::endl;
		std::cout << "  DIGITE LA CANTIDAD DE JUGADORES ( 1 - 7 ): ";

		std::cin >> numJugadores;
	
	} while (numJugadores < 1 || numJugadores > 7 || !isalnum(numJugadores));

	system("cls");

	for (int i = 1; i <= numJugadores; ++i) {
		std::cout << "DIGITE EL NOMBRE DEL JUGADOR #" << i << " :";
		std::getline(std::cin, nombreJugador);

		JugadorGenerico* nuevoJugador = new Jugador(nombreJugador, false);
		listaJugadores->insertarElemento(nuevoJugador);

		std::cout << std::endl << std::endl;
	}

	JugadorGenerico* laCasa = new Dealer("LA CASA", false, false);
	listaJugadores->insertarElemento(laCasa);
} 

void Juego::repartirCartas() {
	Mazo* barajaCartas = new Mazo();

	Lista::iterador tmp = listaJugadores->getInicio();

	while (tmp) {
		tmp->getDato()->setManoInicial(barajaCartas);
		tmp = tmp->getNext();
	}
}


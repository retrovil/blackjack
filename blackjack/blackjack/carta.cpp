// carta.cpp
// Definición de la clase Carta

#include "carta.h"

// Constructor por Default
// Crea un AS de ESPADAS y boca abajo
Carta::Carta() : valorCarta(Rango::A), paloCarta(Palo::ESPADAS), bocaArriba(false) { }

// Constructor por parámetros
// Recibe el rango, palo y la posición inicial de la carta
Carta::Carta(Rango r, Palo p, bool b) : valorCarta(r), paloCarta(p), bocaArriba(b) { }

// Destructor
// Vacío puesto que no hay memoria por liberar en Carta
Carta::~Carta() { }

// Actualiza el valor de la carta - Rango 
void Carta::setValor(Rango r) { valorCarta = r; }

// Actualiza el palo de la carta 
void Carta::setPalo(Palo p) { paloCarta = p; }

// Actualiza el valor de la carta - Rango 
void Carta::ponerBocaArriba(bool b) { bocaArriba = b; }

// Retorna el valor de la carta
Rango Carta::getValor() { return valorCarta; }

// Retorna el palo de la carta
Palo Carta::getPalo() { return paloCarta; }

// Voltea la carta - boca arriba a boca abajo o viceversa
void Carta::voltear() { bocaArriba = !bocaArriba; }
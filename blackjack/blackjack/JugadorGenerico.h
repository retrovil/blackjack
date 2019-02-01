// JugadorGenerico.h
// Declaración de la clase abstracta JugadorGenerico

#ifndef JUGADORGENERICO_H
#define JUGADORGENERICO_H

#include "mano.h"
#include <string>

class JugadorGenerico {
public:
	JugadorGenerico() { }
	JugadorGenerico(std::string n) : nickname(n) { }  
	virtual ~JugadorGenerico() { }

	virtual void pedirCarta() const = 0 ;
	
protected:
	std::string nickname;
	Mano manoJugador;
};

#endif


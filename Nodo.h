#ifndef NODO
#define NODO
#include "Neurona.h"

using namespace std;

class Nodo {
	public:
		Neurona *neurona;
		int indice;
		Nodo *siguiente;
};

#endif

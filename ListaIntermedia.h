#include "NeuronaEntrada.h"
#include <iostream>

using namespace std;

class NodoIntermedio {
    public:
        NeuronaIntermedia *neurona;
        int indice;
        NodoIntermedio *sig;
    };
    
class ListaIntermedia {
    NodoIntermedio *raiz;
    NodoIntermedio *fondo;
public:
    ListaIntermedia();
    void insertar(NeuronaIntermedia* neuronaI, int indiceNeurona);
    NeuronaIntermedia *extraer();
    NodoIntermedio *obtener(int i);
    bool vacia();
};


ListaIntermedia::ListaIntermedia()
{
    raiz = NULL;
    fondo = NULL;
}

void ListaIntermedia::insertar(NeuronaIntermedia* neuronaI, int indiceNeurona)
{
    NodoIntermedio *nuevo;
    nuevo = new NodoIntermedio();
    nuevo->neurona = neuronaI;
    nuevo->indice = indiceNeurona;
    nuevo->sig = NULL;
    if (vacia()) 
    {
        raiz = nuevo;
        fondo = nuevo;
    }
    else {
        fondo->sig = nuevo;
        fondo = nuevo;
    }
}

NeuronaIntermedia *ListaIntermedia::extraer()
{
	NeuronaIntermedia* salida = raiz->neurona;
    NodoIntermedio *bor = raiz;
    if (!vacia())
    {
        
        if (raiz == fondo)
        {
            raiz = NULL;
            fondo = NULL;
        }
        else 
        {
            raiz = raiz->sig;
        }
        delete bor;
        return salida;
    }
    else
        return salida;
}

NodoIntermedio *ListaIntermedia::obtener(int i)
{
	NodoIntermedio* salida = raiz;
    while (!vacia())
    {
    	if(salida->indice == i){
    		return salida;
		}
		else
		salida = salida->sig;
    }
        return salida;
}

bool ListaIntermedia::vacia()
{
    if (raiz == NULL)
        return true;
    else
        return false;
}

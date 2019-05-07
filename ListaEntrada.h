#include "NeuronaEntrada.h"
#include <iostream>

using namespace std;

class NodoEntrada {
    public:
        NeuronaEntrada *neurona;
        int indice;
        NodoEntrada *sig;
    };
    
class ListaEntrada {
    NodoEntrada *raiz;
    NodoEntrada *fondo;
public:
    ListaEntrada();
    void insertar(NeuronaEntrada* neuronaE, int indiceNeurona);
    NeuronaEntrada *extraer();
    NodoEntrada *obtener(int i);
    bool vacia();
};


ListaEntrada::ListaEntrada()
{
    raiz = NULL;
    fondo = NULL;
}

void ListaEntrada::insertar(NeuronaEntrada* neuronaE, int indiceNeurona)
{
    NodoEntrada *nuevo;
    nuevo = new NodoEntrada();
    nuevo->neurona = neuronaE;
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

NeuronaEntrada *ListaEntrada::extraer()
{
	NeuronaEntrada* salida = raiz->neurona;
    NodoEntrada *bor = raiz;
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

NodoEntrada *ListaEntrada::obtener(int i)
{
	NodoEntrada* salida = raiz;
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

bool ListaEntrada::vacia()
{
    if (raiz == NULL)
        return true;
    else
        return false;
}

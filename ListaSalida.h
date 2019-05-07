
#include <iostream>

using namespace std;

class NodoSalida {
    public:
        NeuronaSalida *neurona;
        int indice;
        NodoSalida *sig;
    };
    
class ListaSalida {
    NodoSalida *raiz;
    NodoSalida *fondo;
public:
    ListaSalida();
    void insertar(NeuronaSalida* neuronaS, int indiceNeurona);
    NeuronaSalida *extraer();
    NodoSalida *obtener(int i);
    bool vacia();
};


ListaSalida::ListaSalida()
{
    raiz = NULL;
    fondo = NULL;
}

void ListaSalida::insertar(NeuronaSalida* neuronaS, int indiceNeurona)
{
    NodoSalida *nuevo;
    nuevo = new NodoSalida();
    nuevo->neurona = neuronaS;
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

NeuronaSalida *ListaSalida::extraer()
{
	NeuronaSalida* salida = raiz->neurona;
    NodoSalida *bor = raiz;
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

NodoSalida *ListaSalida::obtener(int i)
{
	NodoSalida* salida = raiz;
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

bool ListaSalida::vacia()
{
    if (raiz == NULL)
        return true;
    else
        return false;
}

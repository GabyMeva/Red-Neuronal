#include <iostream>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include "Neurona.h"
#include "NeuronaEntrada.h"
#include "NeuronaIntermedia.h"
#include "NeuronaSalida.h"
#include "ListaEntrada.h"
#include "ListaIntermedia.h"
#include "ListaSalida.h"
#define capas 20
#define neuronasPorCapa 50
#define clases 1
#define ALPHA 0.15
#define caracteristicas 3 //2
#define patrones 2877

using namespace std;

double pesosIntermedios [capas][caracteristicas+1]; //2 x 3
double pesosCapaSalida [clases][capas+1]; //3
double soluciones [clases][patrones];
double solucion [patrones];
double arreglo [patrones][caracteristicas];

int arr[patrones];
int totalNeuronas = 4;
int arregloBinario[5];

void pesoAleatorio(){
	double aleatorio;
	for(int a=0; a<capas; a++){
		for(int i=0; i<caracteristicas+1; i++){
			aleatorio = 1 + rand() % ((10+1) - 1);
			aleatorio = aleatorio / 10;
			if(aleatorio == 1)
			aleatorio = 0.1;
			if(aleatorio > 0.5)
			aleatorio = aleatorio * -1;
			pesosIntermedios[a][i] = aleatorio;
		}
	}
	
		for(int i=0; i<clases; i++){
			for(int j=0; j<capas+1; j++){
				aleatorio = 1 + rand() % ((10+1) - 1);
				aleatorio = aleatorio / 10;
				if(aleatorio == 1)
				aleatorio = 0.1;
				if(aleatorio > 0.5)
				aleatorio = aleatorio * -1;
				pesosCapaSalida[i][j] = aleatorio;
			}
		}
}

void archivo_entradas(){
	ifstream fi;
	double valor;
	string datos;
	int f=0;
	int c=0;
		
	//fi.open("entradas_convertidas_normales.txt",ios::in);
	fi.open("enteros_convertidos.txt",ios::in);
	if(fi.is_open()){
		//cout << "abriendo archivo";
		while(getline(fi,datos)){
			while(f< patrones){
				//cout << "while filas\n";
				//cout << f;
				while(c< caracteristicas){
					//cout << "while columnas\n";
					fi >> arreglo[f][c];
					c++;
				}
				if(c == caracteristicas){
					c=0;
					f++;
				}
			}
		}
		}
		fi.close();
}

void archivo_salidas(){
	ifstream archivo; //objeto para las operaciones de lectura
  	string datos;
  	int i=0;
	//archivo.open("salidas_convertidas_normales.txt",ios::in);
	archivo.open("salidas_convertidas.txt",ios::in);
	archivo>>solucion[i];
	while(getline(archivo,datos)){
		i++;
		cout << "\n";
		archivo>>solucion[i];
	}
	archivo.close();
	
}

void convierte_decimal_binario(int numero){
	for(int i=4; i>=0; i--){
		if(numero == 0){
			arregloBinario[i] = 0;
		}
		if(numero == 1){
			arregloBinario[i] = 1;
			numero=0;
		}
		else{
			arregloBinario[i] = numero%2;
			numero = numero/2;
		}
	}
}

void llena_matriz_soluciones(){
	int numero=0;
	for(int i=0; i<patrones; i++){
		numero = solucion[i];
		convierte_decimal_binario(numero);
		for(int j=0; j<clases; j++){
			soluciones[i][j]  = arregloBinario[j];
		}
	}

}

int main()
{
    ListaEntrada *lista1 = new ListaEntrada();
    ListaIntermedia *lista2 = new ListaIntermedia();
    ListaSalida *lista3 = new ListaSalida();
    //Lista *lista3 = new Lista();
	 //3 patrones, 3 caracteristicas

	int neuronas=0;

	pesoAleatorio();
	archivo_entradas();
	archivo_salidas();

    for(int i=0; i<caracteristicas; i++){ //capa de entrada
    	lista1->insertar(new NeuronaEntrada(), i);
    }
    
    for(int j=0; j<capas; j++){ // insertar neuronas intermedias con pesos diferentes
    	lista2->insertar(new NeuronaIntermedia(), j);
    	lista2->obtener(j)->neurona->valoresNeurona(4);
    	lista2->obtener(j)->neurona->setPesos(pesosIntermedios[j]);
	}
	
	for(int k=0; k<clases; k++){
		lista3->insertar(new NeuronaSalida(), k);
		lista3->obtener(k)->neurona->valoresNeurona(capas+1);
		lista3->obtener(k)->neurona->setPesos(pesosCapaSalida[k]);
	}
	
	//llena_matriz_soluciones();
	double sumatoria_errores=0;
	int vueltitas = 0;
	bool entrena = true;
	
	
	double vector_entradas[caracteristicas];
	double vectorG[capas];
	
	for(int i=0; i<patrones; i++){
		cout << "\n" << solucion[i];
	}
	
	cout << "G";
	while(entrena && vueltitas<100000){
		sumatoria_errores=0;
	for(int patron=0; patron<patrones; patron++){
		
	for(int i=0; i<caracteristicas; i++){ //capa de entrada
    	lista1->obtener(i)->neurona->setEntrada(arreglo[patron][i]);
    	//cout << "\n eeeeeeeeeee" <<  lista1->obtener(i)->neurona->getSalida();
    }
	//cout << "G1";
	for(int j=0; j<caracteristicas; j++){ //capaIntermedia
    	vector_entradas[j] = lista1->obtener(j)->neurona->getSalida();
	}
	//cout << "G2";
	for(int i=0; i<capas; i++){
		lista2->obtener(i)->neurona->setEntradas(vector_entradas);
	}
	//cout << "G";
	for(int k=0; k<capas; k++){
		vectorG[k] = lista2->obtener(k)->neurona->getSalida();
	}
	
	for(int k=0; k<clases; k++){
		lista3->obtener(k)->neurona->setEntradas(vectorG);
	}
	
	double capa_adelante[clases]; //2
	double capa_adelante2[clases]; //10
		
		//for(int i=0; i<clases; i++){
			lista3->obtener(0)->neurona->setSalidaEsperada(solucion[patron]);
		//}
		
		//cout << "------"<< solucion[patron]<< "----" << lista3->obtener(0)->neurona->getSalidaEsperada();

	
	for(int i=0; i<clases; i++){
		capa_adelante[i] = lista3->obtener(i)->neurona->getError();
	}
	
	lista3->obtener(0)->neurona->ajustaPeso(ALPHA);
	for(int k=0; k<capas; k++){
		for(int j=0; j<clases; j++){
			capa_adelante2[j] = lista3->obtener(j)->neurona->getPesos()[k];
		}
		
		lista2->obtener(k)->neurona->getError(clases, clases, capa_adelante, capa_adelante2);
    	lista2->obtener(k)->neurona->ajustaPeso(ALPHA);
		
	}
	
	sumatoria_errores += lista3->obtener(0)->neurona->getErrorCuadratico();


	}
	sumatoria_errores = sumatoria_errores*0.5;
	
	if(sumatoria_errores <= 0.001){
		entrena=false;
		cout << "Terminó en la iteracion: " << vueltitas;
	}
	else{
		//cout << "\n La red no pudo entrenar adecuadamente quedando con un error de: " << sumatoria_errores; ;
	}
	
	vueltitas++;
	if(vueltitas%100 == 0)
	cout << "\n " << sumatoria_errores;
}

//guarda pesos Intermedios
ofstream pesosfin("pesosIntermediosT.txt", ios::trunc); // objeto para la escritura en el archivo
	int i=0;						// crea el archivo, si existe lo borra
	
		for(i;i<capas;i++){
			for(int j=0;j<caracteristicas+1;j++){
				pesosfin << lista2->obtener(i)->neurona->getPesos()[j];
				if(j==caracteristicas){
					pesosfin <<"\n";
				}
				//
				if(j<caracteristicas){
					pesosfin << ",";	
				}
			}
		}
	pesosfin.close();
//guarda pesos Fin
ofstream pesosfs("pesosSalidaT.txt", ios::trunc); // objeto para la escritura en el archivo
	int k=0;						// crea el archivo, si existe lo borra
	
		for(k;k<clases;k++){
			for(int j=0;j<capas+1;j++){
				pesosfs << lista3->obtener(k)->neurona->getPesos()[j];
			/*	if(j==capas-1){
					pesosfs <<"\n";
				}*/
				//
				if(j<capas){
					pesosfs << ",";	
				}
			}
		}
	pesosfs.close();	
	
	////////////////paso de patrones
	int s1[clases];
	cout << "\n Salida de la red para temperatura: ";
	int aciertos=0;
	//fstream escrib;
	ofstream escrib("escribe.txt", ios::trunc);
	for(int patron=0; patron<patrones; patron++){
		
	for(int i=0; i<caracteristicas; i++){ //capa de entrada
    	lista1->obtener(i)->neurona->setEntrada(arreglo[patron][i]);
    }

	double vector_entradas3[caracteristicas];
	double vector_entradas0[capas];
	for(int j=0; j<caracteristicas; j++){
    	vector_entradas3[j] = lista1->obtener(j)->neurona->getSalida();
	}
	
	for(int i=0; i<capas; i++){
		lista2->obtener(i)->neurona->setEntradas(vector_entradas3);	
	}
	
	for(int k=0; k<capas; k++){
		vector_entradas0[k] = lista2->obtener(k)->neurona->getSalida();
	}
	
	for(int k=0; k<clases; k++){
		lista3->obtener(k)->neurona->setEntradas(vector_entradas0);
	}
	
	cout << "\n Patron: " << patron;
	cout << "\n Salida esperada: ";
	//cout << solucion[patron] << " ";
	cout << soluciones[patron][0] << " ";
	/*cout << soluciones[patron][1] << " ";
	cout << soluciones[patron][2] << " ";
	cout << soluciones[patron][3] << " ";
	cout << soluciones[patron][4] << " ";*/
	cout << "\n Salida real de la red: ";
	/*cout << lista3->obtener(0)->neurona->getSalida();
	if(lista3->obtener(0)->neurona->getSalida() == solucion[patron])
	aciertos++;*/
	
	escrib <<lista3->obtener(0)->neurona->getSalida();
	escrib << "\n ";
	
	}
	escrib.close();
	cout << "\n___________Resultado de validacion__________";
	cout << "\nDe " << patrones << " aprendió bien " << aciertos << " el " << (aciertos*100)/patrones << "%";
	
	getch();
	
	

	
    return 0;
}

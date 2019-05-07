#ifndef NEURONAINTERMEDIA
#define NEURONAINTERMEDIA

#include <iostream>
#include <math.h>
#include "Neurona.h"

#define e 2.71828

using namespace std;

class NeuronaIntermedia : public Neurona {
	public:
		
		NeuronaIntermedia();	
		NeuronaIntermedia(double entradas[], double pesos[]);
		
		double getSalida(){	
			//salida = 1/(1 + (pow(e,- sumatoria())));
			salida = 1/(1+ (exp(-sumatoria())));
			return salida;
		}
		
		/*double getError(double errores[]){
			for(int i=0; i<(sizeof(errores)/sizeof(errores)); i++){
				error += getSalida()*errores[i];
				//sumatoria de la salida de la neurona* cada error de las neuronas de adelante
			}	 
		}*/
		
		double getError(int numeroPesos,int numeroerrores, double errores[], double pesosSali[]){
			double sumaError=0;
			/*pesosSalida = new double [numeroPesos];
			for(int i=0; i<numeroPesos; i++){
				pesosSalida[i] = pesosSali[i];
				cout << "\n __________pesosSalida________________: " << pesosSalida[i];
			}
			cout << "\errores " << errores[0];*/
			//int g=0;
			//int a =0;
			for(int k=0; k<numeroerrores; k++){
				//for(int i=0; i<numeroPesos/5; i++){
				sumaError += (errores[k] * pesosSali[k]);
				//cout << "\n sumaError" << sumaError;
				//}
				//a++;
				//g=5*a;
			}
			error = getSalida()*(1-getSalida())*sumaError;
			//cout << "Neurona Interedia" << sumaError;
			return error;	 
		}
		
		private: 
		double * pesosSalida;
	};
	
	NeuronaIntermedia::NeuronaIntermedia(){
		
	}
	
	NeuronaIntermedia::NeuronaIntermedia(double entradas[], double pesos[]){
		setEntradas(entradas);
		setPesos(pesos);
	}
#endif

#ifndef NEURONA
#define NEURONA

#include <iostream>
#include <math.h>
#include <conio.h>


using namespace std;

class Neurona {
	public: // métodos publicos
	
		void valoresNeurona(int numero){
			numero_entradas = numero;
			entradas = new double[numero_entradas];
			pesos = new double[numero_entradas];
			pesosAjustados = new double[numero_entradas];
			//cout << "Numero entradas" << numero_entradas;
		}
  
		void setEntradas(double arregloentradas []){
			for(int i=0; i<numero_entradas-1; i++){
				entradas[i] = arregloentradas[i]; //for
			}
			entradas[numero_entradas-1] = -1;
		}
		
		void setPesos(double arreglopesos []){
			//cout << "\n Neurona";
			for(int i=0; i<numero_entradas; i++){
				pesos[i] = arreglopesos[i]; //for
				//cout << " Pesos: " << pesos[i];
			}
		}
		
		double* getEntradas(){
			return entradas;
		}
		
		double* getPesos(){
			return pesos;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
		}
		
		double sumatoria(){ //de operación
			double suma=0;
			//cout << "\n Empieza la sumatoria " << numero_entradas;
			for(int i=0; i<numero_entradas; i++){
				//cout << "\nvalor de i: " << i;
				suma += entradas[i] * pesos[i];
				//cout << "\n Entradas: " << entradas[i] << " pesos: " << pesos[i];
				//cout << "\nSuma: " << suma;
			}
			return suma;
		}
		
		void ajustaPeso(double factorAprendizaje){ //factorAprendizaje = alfa
		//cout << "Ajusta1";
			for(int i=0; i<numero_entradas; i++){
				pesosAjustados[i] = pesos[i]; //for
			}
			/*for(int i=0; i<caracteristicas; i++){
				correccionPeso = 0;
				correccionPeso = pesos[i] * (factorAprendizaje*error*entradas[i]);
				pesosAjustados[i] = pesos[i] + correccionPeso;
			}*/
			//for para revisar que los pesos cambien a los que se modifican
			//cout << "Ajusta2";
			for(int i=0; i<numero_entradas; i++){
				correccionPeso = 0;
				correccionPeso = (factorAprendizaje*error*entradas[i]);
				pesosAjustados[i] = pesosAjustados[i] + correccionPeso;
			}
			//cout << "Ajusta3";
			for(int i=0; i<numero_entradas; i++){
				pesos[i] = pesosAjustados[i]; //for
				//cout << "\nPesos: " << i << " "<< pesosAjustados[i];
			}
		}
		//l
		
		virtual double getSalida() = 0; // método polimórfico
	
	protected:
		double *entradas;
		double *pesos;
		double salida;
		double error;
		double correccionPeso;
		double *pesosAjustados; // para guardar como se vayan ajustando los pesos
		int numero_entradas;
};

#endif


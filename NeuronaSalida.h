#include <iostream>
#include <math.h>
#include "Neurona.h"

using namespace std;

class NeuronaSalida : public Neurona {
	public:
		NeuronaSalida();		
		NeuronaSalida(double entradas[], double pesos[], double t);
		void setSalidaEsperada(double t);
		double getSalidaEsperada();
		
		/*double getSalida(){
			if(sumatoria()>0)
            return 1.0;
        else
            return 0.0;
		}*/
		double getSalida(){	
			//salida = 1/(1 + (pow(e,- sumatoria())));
			salida = 1/(1+(exp(-sumatoria())));
			return salida;
		}
		
		/*double getError(){
			error = (salida_esperada - getSalida());
			return error;
		}*/
		double getError(){
			error = (salida_esperada-getSalida())*getSalida()*(1-getSalida());
			return error;
		}
		
		double getErrorCuadratico(){
			error_cuadratico = pow((salida_esperada - getSalida()), 2);
			return error_cuadratico;
		}
		
	private:
		double salida_esperada;
		//parámetro agregado
		double error_cuadratico;
	};
	
	NeuronaSalida::NeuronaSalida(){
		
	}
	
	NeuronaSalida::NeuronaSalida(double entradas[], double pesos[], double t){
		setEntradas(entradas);
		setPesos(pesos);
		t = salida_esperada;
	}
	
	void NeuronaSalida::setSalidaEsperada(double t){
		salida_esperada = t;
	}
	
	double NeuronaSalida::getSalidaEsperada(){
		return salida_esperada;
	}

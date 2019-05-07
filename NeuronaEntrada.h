#ifndef NEURONAENTRADA
#define NEURONAENTRADA


#include <iostream>
#include "Neurona.h"

using namespace std;

class NeuronaEntrada : public Neurona {
	public:
		NeuronaEntrada();
		NeuronaEntrada(double entrada);
		void setEntrada(double entrada);

		double getSalida(){
			return entrada;
		}
		
		private:
			double entrada;
	};
	
	NeuronaEntrada::NeuronaEntrada(){
		
	}
	
	NeuronaEntrada::NeuronaEntrada(double entra){
		entrada = entra;
	}
	
	void NeuronaEntrada::setEntrada(double entra){
		entrada = entra;
	}
	
#endif

#ifndef RESERVA_H_
#define RESERVA_H_

#include <iostream>
#include <string.h>
#include <list>
#include <fstream>
#include <cstdlib>
using namespace std;

class Reserva {
private:
	string nombreR_;
	int codigoB_;
	int fecha_;
	int hora_;
	int tipoR_;

public:
	Reserva()
	{
		//Constructor vac�o
	nombreR_="";
	codigoB_=0;
	fecha_=0;
	hora_=0;
	tipoR_=0;

	}
	Reserva(string nombreR,int codigoB,int fecha,int hora,int tipoR);
	//OBSERVADORES
	inline string getNombreR()const{
		return nombreR_;
	}
	inline int getCodigoB()const{
		return codigoB_;
	}
	inline int getFecha()const{
		return fecha_;
	}
	inline int getHora()const{
		return hora_;
	}
	inline int getTipoR()const{
		return tipoR_;
	}
	//MODIFICADORES
	void setNombreR(string nombreR){
		nombreR_=nombreR;
	}
	void setCodigoB(int codigoB){
		codigoB_=codigoB;
	}
	void setFecha(int fecha){
		fecha_=fecha;
	}
	void setHora(int hora){
		hora_=hora;
	}
	void setTipoR(int tipoR){
		tipoR_=tipoR;
	}

	//METODOS PROPIOS DE LA CLASE RESERVA
	
	void seleccionar_reserva();
	void buscar_reserva();
	inline string getllamada_solicitud()
	{
		string llamada_solicitud= "Mi reserva es" + getNombreR()+ "con codigo de la reserva"+ to_string(getCodigoB());
		return llamada_solicitud;
	}

	inline string getllamada_cancelacion()
		{
			string llamada_cancelacion= "Mi reserva es" + getNombreR()+ "con codigo de la reserva"+ to_string(getCodigoB()) + "solicito su cancelacion";
			return llamada_cancelacion;
		}
	inline string getllamada_cambio()
			{
				string llamada_cambio= "Mi reserva es" + getNombreR()+ "con codigo de la reserva"+ to_string(getCodigoB()) + "solicito el cambio de reserva";
				return llamada_cambio;
			}

	void seleccionar_reserva1(char *fichero);
	void confirmar_reserva(char*fichero);
	void denegar_reserva(char*fichero);
	void cambiar_reserva(char *fichero);
	int contar(char*nombre);





};

#endif /* RESERVA_H_ */

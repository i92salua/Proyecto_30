#ifndef ADMINISTRADOR_H_
#define ADMINISTRADOR_H_
#include <iostream>
#include <string.h>
#include <list>
#include <fstream>
using namespace std;

class Administrador {
private:
	string nombre_;
	string apellidos_;
	string dni_;
	int tlf_;
	string direccion_;
	string correo_;
	int NSS_;
	int horas_;
	float nomina_;
	int codigoA_;

public:
	Administrador(string nombre="",string apellidos="",string dni="",int tlf=0,string direccion="",string correo="",int NSS=0,int horas=0,int nomina=0,int codigoA=0);
	/*Administrador(){
        nombre_="";
        apellidos_="";
        dni_="";
        tlf_=0;
        direccion_="";
        correo_="";
        NSS_=0;
        horas_=0;
        nomina_=0.0;
        codigoA_=0;
    }*/
	//OBSERVADORES
	inline string getNombre()const{return nombre_;}
	inline string getApellidos()const{return apellidos_;}
	inline string getDni()const{return dni_;}
	inline int getTlf(){return tlf_;}
	inline string getDireccion(){return direccion_;}
	inline string getCorreo(){return correo_;}
	inline int getNSS(){return NSS_;}
	inline int getHoras(){return horas_;}
	inline float getNomina(){return nomina_;}
	inline int getCodigoA(){return codigoA_;}
	inline string getApellidosyNombre(){return apellidos_+','+nombre_;}

	//MODIFICADORES
	void setNombre(string nombre){nombre_=nombre;}
	void setApellidos(string apellidos){apellidos_=apellidos;}
	void setTlf(int tlf){tlf_=tlf;}
	void setDireccion(string direccion){direccion_=direccion;}
	void setCorreo(string correo){correo_=correo;}
	void setNSS(int NSS){NSS_=NSS;}
	void setNomina(float nomina){nomina_=nomina;}
	void setCodigoA(int codigoA){codigoA_=codigoA;}


	//METODOS DE LA CLASE ADMINISTRADOR
	inline bool comprobar_dni(string &dni)
		string cad="TRWAGMYFPDXBNJZSQVHLCKE";
	if(dni.size()!=9){
		return false;
	}
	dni[8]=toupper(dni[8]);
	if(isdigit(dni[8])){
	return false;
	}
	for(int i=0;i<8;i++){
		if(!isdigit(dni[i])){
			return false;
		}
	}
	string s;
		for(int j=0;j<8;j++){
			s[j]=dni[j];
		}
	int numero=stoi(s);
	int res=numero%23;
	if(cad[res]==dni[8]){			
		return true;
	}
	else{
		return false;
		}
}	

		inline bool sethoras(int horas)
		{
			if(horas>0 and horas<=60)
			{
				cout<<"Esta en el rango de horas semanales"<<endl;
				horas_=horas;
				return true;
			}
			else{return false;}
		}

};

#endif /* ADMINISTRADOR_H_ */

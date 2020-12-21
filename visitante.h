#ifndef _VIS_
#define _VIS_

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

class Visitante{
private:
    int tlf_, codigoR_, codigoV_, edad_;
    string nombre_, apellidos_, nombrecompleto_, DNI_, Fech_, REsp_, auto_;
public:
    Visitante(string dni, string nombre="\0", string apellidos="\0", int edad=0, string Fech="\0",
        string REsp="\0", string auto="\0", int tlf=0, int codigoR=0, int codigoV=0);
    
    inline void setNombre(string nombre){nombre_=nombre;}
    inline string getNombre() const {return nombre_;}
	inline void setApellidos(string apellidos){apellidos_=apellidos;}
    inline string getApellidos() const {return apellidos_;}
    inline void setDNI(string dni){DNI_=dni;}
    inline string getDNI() const {return DNI_;}
    inline void setEdad(int edad){edad_=edad;}
    inline int getEdad() const {return edad_;}
    inline void setTlf(int tlf){tlf_=tlf;}
    inline date setFech(string Fech){Fech_=Fech;}
    inline void setResp(string REsp){REsp_=REsp;}
    inline void setAuto(string auto){auto_=auto;}
    inline void setRuta(string codigoR){codigoR_=codigoR;}
    inline void setCodigo(string codigoV){codigoV_=codigoV;}
    inline string nombrecompleto() const {return apellidos_+","+nombre_;}
    bool MayordeEdad(int *n);
    bool CompruebaDNI(string *n);
}

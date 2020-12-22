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
    string nombre_, apellidos_, nombrecompleto_, DNI_, Fech_, REsp_, autori_;
public:
    Visitante(string dni_=" ",string nombre_="\0",string apellidos_=" ",int edad=0,string Fech_=" ",string REsp_=" ",string autori_=" ",int tlf_=0,int codigoR_=0,int codigoV_=0);
    
    inline void setNombre(string nombre){nombre_=nombre;}
    inline string getNombre() const {return nombre_;}
	inline void setApellidos(string apellidos){apellidos_=apellidos;}
    inline string getApellidos() const {return apellidos_;}
    inline void setDNI(string dni){DNI_=dni;}
    inline string getDNI() const {return DNI_;}
    inline void setEdad(int edad){edad_=edad;}
    inline int getEdad() const {return edad_;}
    inline void setTlf(int tlf){tlf_=tlf;}
    inline string setFech(string Fech){Fech_=Fech;}
    inline void setResp(string REsp){REsp_=REsp;}
    inline void setAuto(string autori){autori_=autori;}
    inline void setRuta(int codigoR){codigoR_=codigoR;}
    inline void setCodigo(int codigoV){codigoV_=codigoV;}
    inline string nombrecompleto() const {return apellidos_+","+nombre_;}
    bool MayordeEdad(int n);
    bool revisor_dni(string &dni);
    void add_visitante();
    void del_visitante(char * fdatosv);
};

#endif

#ifndef _MON_
#define _MON_

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

class Monitor{
private:
    int tlf_, NSS_, horas_, codigoM_;
    float nomina_;
    string nombre_, apellidos_, nombrecompleto_, DNI_, direc_, correo_;
public:
    Monitor(string dni="", string nombre="", string apellidos="", int tlf=0, string direc="", string correo="", int nss=0, int horas=0, int codigoM=0, float nomina=0);
    inline void setNombre(string nombre){nombre_=nombre;}
    inline string getNombre() const {return nombre_;}
	inline void setApellidos(string apellidos){apellidos_=apellidos;}
    inline string getApellidos() const {return apellidos_;}
    inline void setDNI(string dni){DNI_=dni;}
    inline string getDNI() const {return DNI_;}
    inline void setTlf(int tlf){tlf_=tlf;}
    inline int getTlf() const {return tlf_;}
    inline void setDirec(string direc){direc_=direc;}
    inline string getDirec() const {return direc_;}
    inline void setCor(string correo){correo_=correo;}
    inline string getCor() const {return correo_;}
    inline void imprimirNSS(int nss){NSS_=nss;}
    inline int imprimirNSS() const {return NSS_;}
    inline void horasT(int horas){horas_=horas;}
    inline int horasT_imprimir() const {return horas_;}
    inline void setCodigoM(int codigoM){codigoM_=codigoM;}
    inline void setNomina(float nomina){nomina_=nomina;}
    inline float getNomina(){return nomina_;}
    inline string nombrecompleto() const {return apellidos_+","+nombre_;}
    bool revisor_dni(string &dni);
    void add_monitor();
    void del_monitor(char * fdatosm);
};

#endif

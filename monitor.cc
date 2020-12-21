#include "monitor.h"
#include <stdio.h>

Monitor::Monitor(string dni, string nombre, string apellidos, int tlf, string direc,
        string correo, int nss, int horas, int codigoM, float nomina){
    setDNI(dni);
	setNombre(nombre);
	setApellidos(apellidos);
	setDirec(direc);
	setTlf(tlf);
	setCor(correo);
	imprimirNSS(nss);
    horasT(horas);
    setCodigoM(codigoM);
	setNomina(nomina);
}

bool Monitor::revisor_dni(string &dni){
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
void Monitor::add_monitor(){
    ofstream f; 
    string fdatosm=DNI_+".txt";
    f.open(fdatosm, ofstream::app);
        if(f.is_open()){
                f<<DNI_<<','<<nombre_<<','<<apellidos_<<','<<tlf_<<','<<direc_<<','<<correo_<<','<<NSS_<<','<<horas_<<','<<codigoM_<<','<<nomina_<<endl; 
        }
        else{
            cout<<"Error al abrir el fichero"<<endl;
        }
    cout<<endl;
    f.close();
}
void Monitor::del_monitor(char * fdatosm){
	remove(fdatosm);
}

#include "monitor.h"

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
	setNomina(nomina)
}

char letraDNI(int dni){
  char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE";

  return letra[dni%23];
}

bool Monitor::CompruebaDNI(string *n){
	if(strlen(dni)!=9)
		return 0;
	else
		return(letraDNI(atoi(n))==dni[8]);
}

void Monitor::add_monitor(){
    ofstream f; 
    string fdatosm=DNIM_+".txt";
    f.open(fdatosm, ofstream::app);
        if(f.is_open()){
                f<<DNI_<<','<<nombre_<<','<<apellidos_<<','<<tlf_<<','<<direc_<<','<<correo_<<','<<nss_<<','<<horas_<<','<<codigoM_<<','<<nomina_<<endl; 
        }
        else{
            cout<<"Error al abrir el fichero"<<endl;
            aux++;
        }
    cout<<endl;
    f.close();
}
void Monitor::del_monitor(char * fdatosm){
	remove(fdatosm);
}

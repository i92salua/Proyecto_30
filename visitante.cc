#include "visitante.h"

Visitante::Visitante(string dni, string nombre, string apellidos, int edad, string Fech,
        string REsp, string auto, int tlf, int codigoR, int codigoV){
    setDNI(dni);
	setNombre(nombre);
	setApellidos(apellidos);
	setEdad(edad);
	setFech(Fech);
	setTlf(tlf);
	setResp(REsp);
	setAuto(auto);
    setRuta(codigoR);
    setCodigo(codigoV);
}

bool Visitante::MayordeEdad(int *n){
	while(n>0){
		if(n>=18){
		return true;
	}
	else{
		return false;
	}
}

char letraDNI(int dni){
  char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE";

  return letra[dni%23];
}

bool Visitante::CompruebaDNI(string *n){
	if(strlen(dni)!=9)
		return 0;
	else
		return(letraDNI(atoi(n))==dni[8]);
}

void Visitante::add_visitante(){
    ofstream f; 
    string fdatosv=DNIV_+".txt";
    f.open(fdatosv, ofstream::app);
        if(f.is_open()){
                f<<DNI_<<','<<nombre_<<','<<apellidos_<<','<<edad_<<','<<Fech_<<','<<REsp_<<','<<auto_<<','<<codigoR_<<','<<codigoV_<<endl; 
        }
        else{
            cout<<"Error al abrir el fichero"<<endl;
            aux++;
        }
    cout<<endl;
    f.close();
}
void Visitante::del_visitante(char * fdatosv){
	remove(fdatosv);
}

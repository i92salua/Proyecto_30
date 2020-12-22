#include "visitante.h"
#include <stdio.h>

Visitante::Visitante(string dni, string nombre, string apellidos, int edad, string Fech, string REsp, string autori, int tlf, int codigoR, int codigoV){
    //setDNI(dni);
	DNI_=dni;
	setNombre(nombre);
	setApellidos(apellidos);
	setEdad(edad);
	setFech(Fech);
	setResp(REsp);
	setAuto(autori);
	setTlf(tlf);
    setRuta(codigoR);
    setCodigo(codigoV);
	add_visitante();
}

bool Visitante::revisor_dni(string &dni){
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
void Visitante::add_visitante(){
    ofstream f; 
    string fdatosv=DNI_+".txt";
    f.open(fdatosv, ofstream::app);
        if(f.is_open()){
                f<<DNI_<<','<<nombre_<<','<<apellidos_<<','<<edad_<<','<<Fech_<<','<<REsp_<<','<<autori_<<','<<codigoR_<<','<<codigoV_<<endl; 
        }
        else{
            cout<<"Error al abrir el fichero"<<endl;
        }
    cout<<endl;
    f.close();
}
void Visitante::del_visitante(char *fdatosv){
	remove(fdatosv);
}

bool Visitante::MayordeEdad(int n){
	while(n>0){
		if(n>=18){
		return true;
	}
	else{
		return false;
		}
	}
	return false;
}
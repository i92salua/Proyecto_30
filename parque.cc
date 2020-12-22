#include "parque.h"
Parque::Parque(){}

void Parque::ficherito(){
    string nombre, provincia, municipio, flora, fauna, relieve, menciones, rutas;
    int extension;
    cout<<"Vamos a introducir los datos del parque"<<endl;
    cout<<"Cual es el nombre del parque"<<endl;
    getline(cin, nombre);
    ofstream f; 
    f.open(nombre+".txt", ofstream::app);
    while(f.is_open()){
        if(f.is_open()){
            f<<nombre<<endl;
            cout<<"En que provincia se encuentra"<<endl;
            getline(cin, provincia);
            f<<provincia<<endl;
            cout<<"En que municipio se encuentra"<<endl;
            getline(cin, municipio);
            f<<municipio<<endl;
            cout<<"Cual es la flora del parque"<<endl;
            getline(cin,flora);
            f<<flora<<endl;
            cout<<"Cual es el releieve del parque"<<endl;
            getline(cin, relieve);
            f<<relieve<<endl;
            cout<<"Cuales son las menciones del parque"<<endl;
            getline(cin,menciones);
            f<<menciones<<endl;
            cout<<"Cuales son las rutas que estan en ese parque, escribelas separada por ','"<<endl;
            getline(cin, rutas);
            f<<rutas<<endl;
            cout<<"Cual es la extension del parque en kilometros cuadrados"<<endl;
            cin>>extension;
            f<<extension<<endl;
            f.close();
        }
        else{
            cout<<"Error al abrir el fichero"<<endl;
        }
    }
    nombre_=nombre;
    provincia_=provincia;
    municipio_=municipio;
    flora_=flora;
    fauna_=fauna;
    relieve_=relieve;
    menciones_=menciones;
    rutas_=rutas;
    extension_=extension;
}

int main(){
 Parque p;

    p.ficherito();
}
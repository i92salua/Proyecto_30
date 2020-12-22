#include "parque.h"
#define MAX 255

Parque::Parque(){}

void Parque::crearFichero(char *Fname){
    string nombre, provincia, municipio, flora, fauna, relieve, menciones, rutas;
    int extension;
    cout<<"Vamos a introducir los datos del parque"<<endl;
    ofstream f; 
    f.open(Fname);
        if(f.is_open()){
            cout<<"Cual es el nombre del parque"<<endl;
            cin.ignore();
            getline(cin, nombre);
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
            cout<<"Cual es la fauna del parque"<<endl;
            getline(cin,fauna);
            f<<fauna<<endl;
            cout<<"Cual es el relieve del parque"<<endl;
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

/*
Esta funcion recoje los valores introducidos por el usuario en un fichero
El nombre del fichero esta dado en el main
*/

void Parque::leeFicheros(char *Fname){
    ifstream f;
    f.open(Fname, fstream::in);
    if(f.is_open()){
        char nombre[MAX], provincia[MAX], municipio[MAX], flora[MAX], fauna[MAX], relieve[MAX], menciones[MAX], rutas[MAX], extension[MAX] ;
        f.getline(nombre, MAX, '\n');
            f.getline(provincia, MAX, '\n');
            f.getline(municipio, MAX, '\n');
            f.getline(flora, MAX, '\n');
            f.getline(fauna, MAX, '\n');
            f.getline(relieve, MAX, '\n');
            f.getline(menciones, MAX, '\n');
            f.getline(rutas, MAX, '\n');
            f.getline(extension, MAX, '\n');
        
        nombre_=nombre;
        provincia_=provincia;
        municipio_=municipio;
        flora_=flora;
        fauna_=fauna;
        relieve_=relieve;
        menciones_=menciones;
        rutas_=rutas;
        extension_=atoi(extension);
    }   
    else{
        cout<<"Error al abrir el fichero"<<endl;
        exit(EXIT_FAILURE);
    }
}

/*
Esta funcion lee el fichero con los datos y guarda los datos en sus correspondientes variables
*/
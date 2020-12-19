#include "ruta.h"
#define MAX 255

Ruta::Ruta(){
}

void Ruta::asignaValores(){
    string Fname;
    cout<<"Nombre del fichero donde esta la ruta con .txt incluido "<<endl;
    cin>>Fname;
    int contCodi=0, contDuri=0, contDistan=0;
    float  contDifil=0.0, contTipo=0.0;
    int numLineas=contar(Fname);
    cout<<numLineas<<endl; 
    fstream f;
    f.open(Fname, fstream::in);
    if(f.is_open()){
        char codigoT[MAX], duracionT[MAX], dificultadT[MAX], distanciaT[MAX], tipoT[MAX];
        while(f.getline(codigoT, MAX, ',')){
            f.getline(distanciaT, MAX, ',');
            contDistan=contDistan+atoi(distanciaT);
            f.getline(dificultadT, MAX, ',');
            contDifil=contDifil+atoi(dificultadT);
            f.getline(duracionT, MAX, ',');
            contDuri=contDuri+atoi(duracionT);
            f.getline(tipoT, MAX, '\n');
            contTipo=contTipo+atoi(tipoT);
        }
        /*cout<<contDistan<<endl;
        cout<<contDifil<<endl;
        cout<<contDuri<<endl;
        cout<<contTipo<<endl;*/
        duracionR_=contDuri;
        dificultadR_=contDifil/numLineas;
        distanciaR_=contDistan;
        tipoR_=contTipo/numLineas;
    }   
    else{
        cout<<"Error al abrir el fichero"<<endl;
        exit(EXIT_FAILURE);
    }
}

int Ruta::contar(string nombre){
    ifstream f;
    f.open(nombre, fstream::in);
    int cont=0;
    char lin[MAX];
    while(f.getline(lin, MAX, '\n')){
        cont++;
    }
    return cont;
}
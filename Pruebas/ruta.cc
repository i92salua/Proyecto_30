#include "ruta.h"
#define MAX 255

Ruta::Ruta(){
}

void Ruta::asignaValores(char *Fname){
    int contCodi=0, contDuri=0, contDistan=0;
    float  contDifil=0.0, contTipo=0.0;
    int numLineas=contar(Fname);
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

/*
La funcion asignaValores recibe como parametro el nombre del fichero donde estan todos los tramos de las rutas
El fichero contiene su infromacion de esta forma "codigo del tramo, distancia, difilcultad, tiempo, tipo"
Esta funcion lee el fichero y va guardando en un contador el valor de cada apartado de la ruta, por ejemplo el segundo numero de nuestro fichero es la distancia,
la funcion recorre todo el fichero sumando la distancia de cada tramo para despues asignarselo a la variable distanciaR_, ya que la distancia total de la ruta sera la suma de la distancia de todos los tramos
*/

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

/*
Esta funcion  nos permite contar las lineas de un fichero esto nos sirve para la funcion asignaValores() ya que necesitamos conocer el numero de lineas de cada fichero para poder hacer la media de la difilcultad y el tipo 
*/
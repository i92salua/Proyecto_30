#ifndef parque_h
#define parque_h
#include <iostream>
#include <fstream>
#include<string>
using namespace std;

class Parque{
    private:
        string nombre_, provincia_, municipio_, flora_, fauna_, relieve_, menciones_, rutas_;
        int extension_;
    public:
        Parque();
        void crearFichero(char *Fname);
        void leeFicheros(char *Fname);
        inline string getNombre(){return nombre_;}
        inline string getProvincia(){return provincia_;}
        inline string getMuncipio(){return municipio_;}
        inline string getFlora(){return flora_;}
        inline string getFauna(){return fauna_;}
        inline string getRelieve(){return relieve_;}
        inline string getMenciones(){return menciones_;}  
        inline string getRutas(){return rutas_;}
        inline int getExtenion(){return extension_;}  
};
#endif

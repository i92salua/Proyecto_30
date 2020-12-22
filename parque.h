#ifndef parque_h
#define parque_h
#include <iostream>
#include <fstream>
#include<string.h>
using namespace std;

class Parque{
    private:
        string nombre_, provincia_, municipio_, flora_, fauna_, relieve_, menciones_, rutas_;
        int extension_;
    public:
        Parque();
        void ficherito();
        inline string getParque(){return nombre_;}
        inline string getProvincia(){return provincia_;}
        inline string getMuncipio(){return municipio_;}
        inline string getFlora(){return flora_;}
        inline string getFauna(){return fauna_;}
        inline string getRelieve(){return relieve_;}
        inline string getMencioes(){return menciones_;}    
};
#endif

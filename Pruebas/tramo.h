#ifndef tramo_h
#define tramo_h
#include <iostream>
#include <fstream>
#include <list>
#include<string.h>
using namespace std;


class Tramo{
    private:
        int codigoT_;                   //Identificador del tramo
        int duracionT_;                 //Duracion en minutos de la ruta
        float dificultadT_;               //Dificultad de la ruta
        int distanciaT_;                //Distancia de la ruta en metros
        float tipoT_;                     //Tipo del que es la ruta ya se a pie o en bicicleta
        list <Tramo> tramo_;
    public:
        Tramo();
        inline int getCodigoT(){return codigoT_;}
        inline int getDuracionT(){return duracionT_;}
        inline float getDifilcultadT(){ return dificultadT_;}
        inline int getdistanciaT(){return distanciaT_;}
        inline float tipoT(){return tipoT_;}
        void select_tramo();
        void add_tramo(char *Fname);
        void delete_tramo(char *Fname);
        int contar(char* nombre);
};
#endif
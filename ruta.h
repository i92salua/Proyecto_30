#ifndef ruta_h
#define ruta_h
#include <iostream>
#include <fstream>

using namespace std;

class Ruta{
    private:
        int codigoR_;                   //Identificador de la ruta
        int duracionR_;                 //Duracion en minutos de la ruta
        int dificultadR_;               //Dificultad de la ruta
        int distanciaR_;                //Distancia de la ruta
        int parque_;                    //Parque al que pertenece dicha ruta
        int tipoR_;                     //Tipo del que es la ruta ya se a pie o en bicicleta
    public:
        Ruta();
        inline int getCodigoR(){return codigoR_;}
        inline int getDuracionR(){return duracionR_;}
        inline int getDifilcultadR(){ return dificultadR_;}
        inline int getdistanciaR(){return distanciaR_;}
        inline int getParque(){return parque_;}
        inline int tipoR(){return tipoR_;}
        inline void setCodigoR(int codigoR){codigoR_=codigoR;}
        void asignaValores(char * Fname);
        int contar(string nombre);
};
#endif
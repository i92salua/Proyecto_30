#include "ruta.h"
#include "tramo.h"


void testRuta(){
    Ruta r;
    r.asignaValores("prueba_ruta.txt");
    int duri=r.getDuracionR();
    float difil=r.getDifilcultadR();
    int distan=r.getdistanciaR();
    float tip=r.tipoR();
    int cont=0;
    if(210==duri){
        cout<<"Test de la duracion pasado con exito"<<endl;
        cont++;
    }
    else{
        cout<<"Fallo en el test de la duracion"<<endl;
    }
    if(7750==distan){
        cout<<"Test de la distancia pasado con exito"<<endl;
        cont++;
    }
    else{
        cout<<"Fallo en el test de la distancia"<<endl;
    }
    if(1==difil){
        cout<<"Test de la diflcultad pasado con exito"<<endl;
        cont++;
    }
    else{
        cout<<"Fallo en el test de la difilcultad"<<endl;
    }
    if(1==tip){
        cout<<"Test del tipo de tramo pasado con exito"<<endl;
        cont++;
    }
    else{
        cout<<"Fallo en el test del tipo de tramo"<<endl;
    }
    cout<<endl;
    cout<<"La prueba ha pasado "<<cont<<" test de 4 posibles"<<endl; 
    
}
/*
void testTramos(){
    Tramo t;
    Ruta r;
    t.delete_tramo("prueba_delete2.txt");
    r.asignaValores("prueba_delete2.txt");
    int duri=r.getDuracionR();
    float difil=r.getDifilcultadR();
    int distan=r.getdistanciaR();
    float tip=r.tipoR();
    r.asignaValores("prueba_delete1.txt");
    int duri1=r.getDuracionR();
    float difil1=r.getDifilcultadR();
    int distan1=r.getdistanciaR();
    float tip1=r.tipoR();
    ASSERT_EQUAL(duri1,duri);
    ASSERT_EQUAL(distan1,distan);
    ASSERT_EQUAL(difil1,difil);
    ASSERT_EQUAL(tip1,tip);
}
*/


int main() {
    testRuta();
}
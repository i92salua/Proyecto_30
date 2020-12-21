#include "ruta.h"
#include "tramo.h"

int main(){
    Tramo t;
    Ruta r;
    int op;
    do{
        cout<<"---------Parques Naturales de andalucia---------"<<endl;
        cout<<"Que deseas hacer?"<<endl;
        cout<<"1.-Crear una ruta "<<endl;
        cout<<"2.-Modificar una ruta"<<endl;
        cout<<"3.-Ver datos de la ruta"<<endl;
        cout<<"4.-"<<endl;
        cout<<"5.-"<<endl;
        cout<<"6.-"<<endl;
        cout<<"7.-"<<endl;
        cin>>op;
        cout<<endl;
        switch(op){
            case 1:{
                int aux;
                cout<<"Para crear una ruta tienes que elegir los tramos de la misma "<<endl;
                cout<<endl;
                t.select_tramo();
                cout<<endl;
                char Fname[255];
                cout<<endl;
                cout<<"Nombre del fichero donde creaaras la ruta con .txt incluido "<<endl;
                cin>>Fname;
                cout<<"Vamos a añadir los tramos"<<endl;
                t.add_tramo(Fname);
            }break;

            case 2:{
                int aux;
                char Fname[255];
                cout<<endl;
                cout<<"Nombre del fichero donde esta la ruta con .txt incluido "<<endl;
                cin>>Fname;
                cout<<endl;
                cout<<endl;
                cout<<"Que quieres hacer borrar o añadir un tramo"<<endl;
                cout<<"1.- Añadir          2.-Borrar          3.-Ver los tramos disponibles"<<endl;
                cin>> aux;
                if(aux==1){
                    t.add_tramo(Fname);
                }
                else if(aux==2){
                    t.delete_tramo(Fname);
                }
                else if (aux==3){
                    t.select_tramo();
                }
                else{    
                    cout<<"Valor incorrecto"<<endl;
                    exit(EXIT_FAILURE);
                }
            }break;

            case 3:{
                int aux,num=1;
                char Fname[255];
                cout<<"Nombre del fichero donde esta la ruta con .txt incluido "<<endl;
                cin>>Fname;
                r.asignaValores(Fname);
                do{
                    cout<<"Que quieres ver de la ruta"<<endl;
                    cout<<"1.- Duracion     2.-Dificultad       3.-Distancia        4.-Tipo de ruta     5.-Salir"<<endl;
                    cin>>aux;
                    switch(aux){
                        case 1:{
                            cout<<"La duracion de la ruta es: "<<r.getDuracionR()<<" minutos"<<endl;
                        }break;
                        case 2:{
                            cout<<r.getDifilcultadR()<<endl;
                            float Q=r.getDifilcultadR();
                            if(Q>=0 ||Q<=1){
                                cout<<"La difilcultad de la ruta es facil"<<endl;
                            }
                            else if(Q>1 ||Q<=2){
                                cout<<"La difilcultad de la ruta es media"<<endl;
                            }
                            else if(Q>2 ||Q<=2.5){
                                cout<<"La difilcultad de la ruta es media-alta"<<endl;
                            }
                            else if(Q>2.5){
                                cout<<"La difilcultad de la ruta es alta"<<endl;
                            }
                        }break;
                        case 3:{
                            cout<<"La distancia total de la ruta es: "<< r.getdistanciaR()<<" metros"<<endl;
                        }break;
                        case 4:{
                            float Q=r.tipoR();
                            if(Q>=0 ||Q<=1.5){
                                cout<<"La ruta se puede hacer a pie pero hay tramos que se pueden hacer con bicicleta"<<endl;
                            }
                            else if(Q>1.5 ||Q<2){
                                cout<<"La ruta se puede hacer mayormente en bicicleta pero hay tramos que hay que hacerlos a pie"<<endl;
                            }
                            else if(Q==2){
                                cout<<"La ruta se puede hacer toda en bicicleta"<<endl;
                            }
                        }break;
                        case 5:{
                            num=0;
                        }
                        default:{
                            cout<<"Opcion incorrecta"<<endl;
                            num=0;
                        }
                    }
                }while(num!=0);
            }
            default:{
                cout<<"Saliendo del programa"<<endl;
                op=0;
            } 
        }
    }while(op!=0);

}
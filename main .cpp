#include "ruta.h"
#include "tramo.h"
#include "Reserva.h"
#include "administrador.h"
#include "visitante.h"
#include "monitor.h"
#include "parque.h"

int main(){
    Tramo t;
    Ruta r;
    Reserva s;
    Administrador a;
    Visitante v;
    Monitor m;
    Parque p;
    int op;
    do{
        cout<<"---------Parques Naturales de andalucia---------"<<endl;
        cout<<"Que deseas hacer?"<<endl;
        cout<<"1.-Crear una ruta "<<endl;
        cout<<"2.-Modificar una ruta"<<endl;
        cout<<"3.-Ver datos de la ruta"<<endl;
        cout<<"4.Crear un visitante-"<<endl;
        cout<<"5.Crear un monitor-"<<endl;
        cout<<"6.Eliminar visitante-"<<endl;
        cout<<"7.Eliminar monitor-"<<endl;
        cout<<"8.-Seleccionar una reserva"<<endl;
        cout<<"9.-Cambiar una reserva"<<endl;
        cout<<"10.-Crear fichero con las caracteristicas del parque"<<endl;
        cout<<"11.-Ver caracteristicas de un parque"<<endl;
        cout<<"12.-Salir del programa"<<endl;
        cin>>op;
        cout<<"-------------------------------------------------"<<endl;
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
                cout<<"Vamos a a�adir los tramos"<<endl;
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
                cout<<"Que quieres hacer borrar o a�adir un tramo"<<endl;
                cout<<"1.- A�adir          2.-Borrar          3.-Ver los tramos disponibles"<<endl;
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
            }break;
            
            case 4:{
                int edad, codigoR, codigoV;
                string dni, nombre, apellidos, Fech, REsp, autori;
                cout<<"dime los datos del visitante"<<endl;
                do{
				    cout<<"Introduzca dni"<<endl;
				    cin>>dni;
			    }while(v.revisor_dni(dni)==false);
                cout<<"Nombre: "<<endl;
                cin>>nombre;
                cout<<"Apellidos: "<<endl;
                cin>>apellidos;
                cout<<"Edad: "<<endl;
                cin>>edad;
                bool n=v.MayordeEdad(edad);
                cout<<"¿tiene autorizacion?"<<endl;
                cin>>autori;
                if(autori=="no" && n==false){
                    cout<<"no se puede aceptar la visita de esa persona"<<endl;
                    EXIT_FAILURE;
                }
                cout<<"Fecha de nacimiento: "<<endl;
                cin>>Fech;
                cout<<"¿Algun requisito especial?"<<endl;
                cin>>REsp;
                cout<<"codigo de ruta al que pertenece: "<<endl;
                cin>>codigoR;
                cout<<"codigo de visitante: "<<endl;
                cin>>codigoV;
                Visitante(dni, nombre, apellidos, edad, Fech, REsp, autori, codigoR, codigoV);
            }break;
            case 5:{
                float nomina;
                int edad, tlf, nss, codigoM, horas;
                string dni, nombre, apellidos, direc, correo, autori;
                cout<<"dime los datos del monitor"<<endl;
                do{
				    cout<<"Introduzca dni"<<endl;
				    cin>>dni;
			    }while(m.revisor_dni(dni)==false);
                cout<<"Nombre: "<<endl;
                cin>>nombre;
                cout<<"Apellidos: "<<endl;
                cin>>apellidos;
                cout<<"Direccion: "<<endl;
                cin>>direc;
                cout<<"Telefono: "<<endl;
                cin>>tlf;
                cout<<"Correo: "<<endl;
                cin>>correo;
                cout<<"NSS: "<<endl;
                cin>>nss;
                cout<<"Horas de trabajo: "<<endl;
                cin>>horas;
                cout<<"Codigo del monitor: "<<endl;
                cin>>codigoM;
                cout<<"Nomina: "<<endl;
                cin>>nomina;
                Monitor(dni, nombre, apellidos, tlf, direc, correo, nss, horas, codigoM, nomina);
            }break;

            case 6:{
                char fdatosv[255];
                cout<<"Nombre del fichero donde esta el visitante con .txt incluido "<<endl;
                cin>>fdatosv;
                v.del_visitante(fdatosv);
            }break;

            case 7:{
                char fdatosm[255];
                cout<<"Nombre del fichero donde esta el visitante con .txt incluido "<<endl;
                cin>>fdatosm;
                m.del_monitor(fdatosm);
            }break;

            case 8:{
                int aux;
                char fichero[255];
                cout<<"Para buscar una reserva tenemos que seleccionar las reservas hechas "<<endl;
                cin>>fichero;
                cout<<endl;
                s.seleccionar_reserva1(fichero);
                cout<<endl;
                cout<<endl;
                cout<<"Procedemos a la confirmacion de reservas"<<endl;
                s.confirmar_reserva(fichero);
            }break;

            case 9:{
                int aux;
                char fichero[255];
                cout<<endl;
                cout<<"Nombre del fichero donde estan la lista de reservas con .txt incluido "<<endl;
                cin>>fichero;
                cout<<endl;
                cout<<endl;
                cout<<"Que quieres hacer denegar o cambiar un tramo"<<endl;
                cout<<"1.- Cambiar(Confirmar otra vez)          2.-Denegar          3.-Ver la lista de reservas"<<endl;
                cin>> aux;
                    if(aux==1){
                        s.confirmar_reserva(fichero);
                    }
                    else if(aux==2){
                        s.denegar_reserva(fichero);
                    }
                    else if (aux==3){
                        s.seleccionar_reserva1(fichero);
                    }
                else{
                    cout<<"Valor incorrecto"<<endl;
                    exit(EXIT_FAILURE);
                }
            }break;

            case 10:{
                char Fname[255];
                cout<<"Nombre del fichero donde quieres que se guarde el parque con .txt incluido"<<endl;
                cin>>Fname;
                p.crearFichero(Fname);
            }break;

            case 11:{
                int aux, num;
                char Fname[255];
                cout<<"Nombre del fichero donde qesta guardada la informacion del parque con .txt incluido"<<endl;
                cin>>Fname;
                p.leeFicheros(Fname);
                
                do{
                    cout<<"Que quieres ver del parque"<<endl;
                    cout<<"1.-Nombre     2.-Provincia en la que se encuentra       3.-Municipio en el que se encuentra        4.-La flora del parque     5.-La fauna del parque     6.-El relieve del parque        7.-Las menciones del parque     8.-Las rutas del parque     9.-La extension del parque      10.-Salir"<<endl;
                    cin>>aux;
                    if(aux>0 || aux<11){
                        if(aux==1){
                            cout<<"El nombre del parque es: "<<p.getNombre()<<endl;
                        }
                        else if(aux==2){
                            cout<<"El parque se encuentra en: "<<p.getProvincia()<<endl;
                        }
                        else if(aux==3){
                            cout<<"El parque se encuentra en el municipio: "<<p.getMuncipio()<<endl;
                        }
                        else if(aux==4){
                            cout<<"La flora del parque es: "<<p.getFlora()<<endl;
                        }
                        else if(aux==5){
                            cout<<"La fauna del parque es: "<<p.getFauna()<<endl;
                        }
                        else if(aux==6){
                            cout<<"El relieve del parque es: "<<p.getRelieve()<<endl;
                        }
                        else if(aux==7){
                            cout<<"Las menciones del parque son: "<<p.getMenciones()<<endl;
                        }
                        else if(aux==8){
                            cout<<"El parque cuenta con las siguientes rutas: "<<endl;
                            cout<<p.getRutas()<<endl;
                        }
                        else if(aux==9){
                            cout<<"El parque tiene "<<p.getExtenion()<<" kilometros cuadrados"<<endl;
                        }
                        else if(aux==10){
                            num=1;
                        }
                    }
                    else{
                        cout<<"Opcion incorrecta"<<endl;
                        exit(EXIT_FAILURE);
                    }
                    cout<<endl;
                }while(num!=1);
            }break;
            default:{
                cout<<"Saliendo del programa"<<endl;
                op=0;
            }break;
        }
    }while(op!=0);
}


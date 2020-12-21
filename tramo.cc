#include "tramo.h"
#define MAX 255

Tramo::Tramo(){
    
}

void Tramo::select_tramo(){
    cout<<"Actualmente en nuestro parque tenemos los siguientes tramos"<<endl;
    cout<<"Estan ordenados de la siguiente froma:"<<endl;
    cout<<"Codigo del tramo     Distancia del tramo     Difilcultad del tramo     Duracion del tramo      Tipo del tramo"<<endl;
    cout<<"1                    2000                    2                         55                      1 "<<endl;
    cout<<"2                    1500                    2                         40                      1 "<<endl;
    cout<<"3                    1000                    1                         30                      2 "<<endl;
    cout<<"4                    500                     1                         15                      2 "<<endl;
    cout<<"5                    3000                    3                         80                      1 "<<endl;
    cout<<"6                    2500                    2                         75                      2 "<<endl;
    cout<<"7                    750                     2                         25                      1 "<<endl;        
    cout<<"8                    1250                    1                         25                      2 "<<endl;        
    cout<<"9                    1300                    2                         30                      1 "<<endl;        
    cout<<"10                   4000                    2                         90                      2 "<<endl;        
            
}

void Tramo::add_tramo(char * Fname){
    int cod_T;
    ofstream f; 
    f.open(Fname, ofstream::app);
    int aux=0, aux1;
    while(aux==0){
        if(f.is_open()){
            cout<<"Dime el codigo del tramo a seleccionar"<<endl;
            cin>>cod_T;
            if(cod_T<1 || cod_T>10){
                cout<<"Codigo del tramo incorreccto"<<endl;
                exit(EXIT_FAILURE);
            }        
            if(cod_T==1){
                f<<1<<','<<2000<<','<<2<<','<<55<<','<<1<<endl; 
            }
            else if(cod_T==2){
                f<<2<<','<<1500<<','<<2<<','<<40<<','<<1<<endl; 
            }
            else if(cod_T==3){
                f<<3<<','<<1000<<','<<1<<','<<30<<','<<2<<"\n"; 
            }
            else if(cod_T==4){
                f<<4<<','<<500<<','<<1<<','<<15<<','<<2<<"\n"; 
            }
            else if(cod_T==5){
                f<<5<<','<<3000<<','<<3<<','<<80<<','<<1<<"\n"; 
            }
            else if(cod_T==6){
                f<<6<<','<<2500<<','<<2<<','<<75<<','<<2<<"\n"; 
            }
            else if(cod_T==7){
                f<<7<<','<<750<<','<<2<<','<<25<<','<<1<<"\n"; 
            }
            else if(cod_T==8){
                f<<8<<','<<1250<<','<<1<<','<<25<<','<<2<<"\n"; 
            }
            else if(cod_T==9){
                f<<9<<','<<1300<<','<<2<<','<<35<<','<<1<<"\n"; 
            }
            else if(cod_T==10){
                f<<10<<','<<4000<<','<<2<<','<<90<<','<<2<<"\n"; 
            }
        }
        else{
            cout<<"Error al abrir el fichero"<<endl;
            aux++;
        }
        cout<<"Añadir mas tramos?"<<endl;
        cout<<"1-Si     2-No"<<endl;
        cin>>aux1;
        if(aux1==2){
            aux++;
        }
    }
    cout<<endl;
    f.close();
}

/*
La funcion add_tramo() sirve tanto para crear un ruta como para modificarla.
Le tenemos que pasar el nombre del fichero que queramos desde el main si el nombre no existe creara el fichero y si existe añadira abrira el fichero para poder añadir mas tramos
Si el fichero se ha abierto correctamente nos dara la opcion a elegir el codigo del tramo que queramos añadir al fichero si el valor introducido no existe nos dara error
Una vez añadido un tramo nos preguntara si queremos añadir mas si decimos que si volveremos al paso anterior en caso contrario acabara la funcion 
*/

void Tramo::delete_tramo(char *Fname){
    int num,cont;  
    cout<<"Tu ruta actual tiene estos tramos:"<<endl;
    ifstream f;
    f.open(Fname, fstream::in);
    if(f.is_open()){
        char aux[MAX];
        while(f.getline(aux, MAX, ',')){
            cout<<aux<<" ";
        }
        cout<<endl;
    }
    f.close();
    cont=contar(Fname);
    int numDeletes=0;
    
    while(numDeletes==0){
        cout<<"Deseas eliminar el ultimo tramo?"<<endl;
        cout<<"1-Si     2-No"<<endl;
        cin>>num;
        
        if(num==1){
            cout<<"Eliminando ultimo tramo............"<<endl;
            ifstream f(Fname);
            ofstream file;
            file.open("temporal.txt", ios::out);
            char ch;
            int line=1;
            while(f.get(ch)){
                if(ch=='\n'){
                    line++;
                }
                if(line!=cont){
                    file<<ch;
                }
            }
            f.close();
            file.close();
            remove(Fname);        
            rename("temporal.txt" ,Fname);
            for(int i=0;i<3;i++){
                cout<<"."<<endl;
            }
            cout<<"Ultimo tramo eliminado con exito"<<endl;
            cout<<endl;
        }

        int numerito;
        cout<<"Quieres eliminar mas tramos?"<<endl;
        cout<<"1-Si     2-No"<<endl;
        cin>>numerito;
        if(numerito==2){
            cout<<"Sus cambios han sido guardados"<<endl;
            cout<<endl;
            numDeletes++;
        }
    }
    
    f.close(); 
     
}

/*
La funcion delete_tramos() elimina el ultimo tramo del fichero que le pasemos por el main
Nos muestra los tramos que tengamos en el fichero que le pasemos y hay confirmamos si lo queremos eliminar o no
El programa crea un fichero temporal donde vamos a introducir todos los valores menos el ultimo y despues elimina el fichero original y renombra el fichero temporal con el nombre del anterior fichero
Nos preguntara si queremos eliminar mas tramos, si respondemos si volveremos al paso anterior, si no acabara la funcion
*/

int Tramo::contar(char *nombre){
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
Esta funcion  nos permite contar las lineas de un fichero esto nos sirve para la funcion delete_tramos() ya que necesitamos conocer el numero de lineas de cada fichero 
*/
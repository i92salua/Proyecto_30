#include "tramo.h"
#define MAX 255

Tramo::Tramo(){
    
}

void Tramo::select_tramo(){
    /*fstream f;
    f.open("tramos.txt", fstream::in);
    if(f.is_open()){
        char codigoT[MAX], duracionT[MAX], dificultadT[MAX], distanciaT[MAX], tipoT[MAX];
        while(f.getline(codigoT, MAX, ',')){
            f.getline(distanciaT, MAX, ',');
            f.getline(dificultadT, MAX, ',');
            f.getline(duracionT, MAX, ',');
            f.getline(tipoT, MAX, '\n');
            Tramo aux(atoi(codigoT), atoi(duracionT), atoi(dificultadT), atoi(distanciaT), atoi(tipoT));
            tramo_.push_back(aux);
        }
    }   
    else{
        cout<<"Error al abrir el fichero"<<endl;
        exit(EXIT_FAILURE);
    }
    list <Tramo>::iterator it;
    for(it=tramo_.begin();it!=tramo_.end();it++){
        cout<< it <<" "<<endl;
    }*/
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

void Tramo::add_tramo(){
    int cod_T;
    string name, fname;
    
    cout<<"Dime el nombre del ruta que vas a crear"<<endl;
    cin>>name; 
    fname=name+".txt";
    ofstream f; 
    f.open(fname);
    int aux=0, aux1;
    while(aux==0){
        if(f.is_open()){
            cout<<"Dime el codigo del tramo al seleccionar"<<endl;
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
        cout<<"Aniadir mas tramos?"<<endl;
        cout<<"1-Si     2-No"<<endl;
        cin>>aux1;
        if(aux1==2){
            aux++;
        }
    }
    cout<<endl;
    f.close();
}

void Tramo::delete_tramo(){
    string name, name2;
    int num,cont;
    //cout<<"Nombre de la ruta?"<<endl;
    //cin>>name;
    //string nombreF=name+".txt";
    char Fname[MAX];
    cout<<"Nombre del fichero donde esta la ruta con .txt incluido "<<endl;
    cin>>Fname;
    cout<<endl;
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
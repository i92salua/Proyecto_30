#include "Reserva.h"

Reserva::Reserva(string nombreR,int codigoB,int fecha,int hora,int tipoR) {
	// TODO Auto-generated constructor stub
	nombreR_=nombreR;
	codigoB_=codigoB;
	fecha_=fecha;
	hora_=hora;
	tipoR_=tipoR;
}



void Reserva::seleccionar_reserva()
{

string nombrefichero = "reserva.txt";



	//Abrimos el fichero en modo escritura (si el fichero no existe lo crea)
	ofstream salida(nombrefichero);

	if(!salida)
	{
		cout << "Error al abrir el fichero." << endl;
		exit(-1);
	}

	string nombre1 = "Angel_Fernandez";
	int codigo1 = 234;
	string nombre2 = "Francico_Escribano";
	int codigo2 = 342;
	string nombre3 = "Jesus_Perez";
	int codigo3 = 212;
	string nombre4="Javier_Romero";
	int codigo4=345;
	string nombre5="Alvaro_Sanchez";
	int codigo5=406;
	string nombre6 = "Angel_Fernandez";
	int codigo6 = 234;
	string nombre7 = "Juan_Moral";
	int codigo7 = 543;
	string nombre8 = "Rafael_Romero";
	int codigo8 = 577;
	string nombre9="Jose_Caballero";
	int codigo9=587;
	string nombre10="Alicia_Ramos";
	int codigo10=598;
	string nombre11="Raquel_Ruiz";
	int codigo11=603;


	salida << nombre1 << " " << codigo1 << endl;
	salida << nombre2 << " " << codigo2 << endl;
	salida << nombre3 << " " << codigo3 << endl;
	salida << nombre4 << " " << codigo4 << endl;
	salida << nombre5 << " " << codigo5 << endl;
	salida << nombre6 << " " << codigo6 << endl;
	salida << nombre7 << " " << codigo7 << endl;
	salida << nombre8 << " " << codigo8 << endl;
	salida << nombre9 << " " << codigo9 << endl;
	salida << nombre10 << " " << codigo10 << endl;
	salida << nombre11 << " " << codigo11 << endl;

	salida.close();
	
}
void Reserva::buscar_reserva()
{
	//LEER DE UN FICHERO
	string nombrefichero="reserva.txt";
		
	ifstream entrada(nombrefichero);

	if(!entrada)
	{
		cout << "Error al abrir el fichero." << endl;
		exit(-1);
	}

	//recorro mi fichero leyendo
	string nombre;
	string codigo_cadena;
	int codigo;

	while(getline(entrada,nombre,'\n') )
	{
		entrada >> codigo;
		getline(entrada,codigo_cadena,'\n');
		codigo = atoi(codigo_cadena.c_str());
		cout << "El nombre de la reserva es"<< nombre << " con c�digo " << codigo << endl;
		}


		entrada.close();
	}



/*
 La funci�n buscar_reserva() sirve para buscar los codigos y los nombres de las reservas.
 Primeramente, se crea un fichero donde se escribe el codigo de la reserva y el nombre asigando, que va a ser una acotacion del nombre de la persona que lo solicita.
 Y despues, va a comprobar leyendo dicho fichero, para ver que se ha creado correctamente los datos introducidos.
 */



void Reserva::seleccionar_reserva1(char *fichero){

	    cout<<"Actualmente en nuestro parque tenemos los siguientes reservas solicitudas"<<endl;
	    cout<<"Estan ordenados de la siguiente froma:"<<endl;
	    cout<<"Codigo Reserva     Nombre Reserva     Fecha Reserva     Hora Reserva      Tipo de la ruta"<<endl;
	    cout<<"234                  angel_rd             11/01/2019          10:30                      1 "<<endl;
	    cout<<"342                  fran_ez              03/02/2019          11:30                      1 "<<endl;
	    cout<<"212                  jesus_pt             04/01/2019          9:30                       2"<<endl;
	    cout<<"345                  javier_rr            06/02/2019          10:15                      2 "<<endl;
	    cout<<"406                  alvaro_sq            14/03/2019          11:45                      1 "<<endl;
	    cout<<"543                  juan_ml              14/04/2019          10:30                      2 "<<endl;
	    cout<<"577                  rafael_rp            20/04/2019          17:30                      1 "<<endl;
	    cout<<"587                  jose_cj              22/04/2019          12:15                      2 "<<endl;
	    cout<<"598                  alicia_rq            30/04/2019          11:45                      1 "<<endl;
	    cout<<"603                  raquel_rr            03/05/2019          9:30                       2"<<endl;

	}

	void Reserva::confirmar_reserva(char * fichero){
	    int cod_R;
	    ofstream f;
	    f.open(fichero, ofstream::app);
	    int aux=0, aux1;
	    while(aux==0){
	        if(f.is_open()){
	            cout<<"Dime el codigo de la reserva al seleccionar"<<endl;
	            cin>>cod_R;
	            if(cod_R<0){
	                cout<<"Codigo del tramo incorreccto"<<endl;
	                exit(EXIT_FAILURE);
	            }
	            if(cod_R==234){
	                f<<234<<','<<"angel_rd"<<','<<"11/01/2019"<<','<<"10:30"<<','<<1<<"\n";
	            }
	            else if(cod_R==342){
	                f<<342<<','<<"fran_ez"<<','<<"03/02/2019"<<','<<"11:30"<<','<<1<<"\n";
	            }
	            else if(cod_R==212){
	                f<<212<<','<<"jesus_pt"<<','<<"04/01/2019"<<','<<"9:30"<<','<<2<<"\n";
	            }
	            else if(cod_R==345){
	            	 f<<345<<','<<"javier_rr"<<','<<"06/02/2019"<<','<<"10:15"<<','<<2<<"\n";
	            }
	            else if(cod_R==406){
	                f<<406<<','<<"alvaro_sq"<<','<<"14/03/2019"<<','<<"11:45"<<','<<1<<"\n";
	            }
	            else if(cod_R==543){
	                f<<543<<','<<"juan_ml"<<','<<"14/04/2019"<<','<<"10:30"<<','<<2<<"\n";
	            }
	            else if(cod_R==577){
	                f<<577<<','<<"rafael_rp"<<','<<"20/04/2019"<<','<<"17:30"<<','<<1<<"\n";
	            }
	            else if(cod_R==587){
	                f<<577<<','<<"jose_cj"<<','<<"22/04/2019"<<','<<"12:15"<<','<<2<<"\n";
	            }
	            else if(cod_R==598){
	                f<<598<<','<<"alicia_rq"<<','<<"30/04/2019"<<','<<"11:45"<<','<<1<<"\n";
	            }
	            else if(cod_R==603){
	                f<<603<<','<<"raquel_rr"<<','<<"03/05/2019"<<','<<"9:30"<<','<<2<<"\n";
	            }
	        }
	        else{
	            cout<<"Error al abrir el fichero"<<endl;
	            aux++;
	        }
	        cout<<"Se confirman mas reservas?"<<endl;
	        cout<<"1-Si     2-No"<<endl;
	        cin>>aux1;
	        if(aux1==2){
	            aux++;
	        }
	    }
	    cout<<endl;
	    f.close();
	    /*
	    La funcion confirmar_reserva() sirve tanto para confirmar una reserva como para cambiarla.
	    Le tenemos que pasar el nombre del fichero que queramos desde el main si el nombre no existe creara el fichero y si existe a�adira abrira el fichero para poder a�adir mas reservas
	    Si el fichero se ha abierto correctamente nos dara la opcion a elegir el codigo de la reserva que queramos a�adir al fichero si el valor introducido no existe nos dara error
	    Una vez confirmada una reserva nos preguntara si queremos confirmar m�s, si decimos que si, volveremos al paso anterior en caso contrario acabara la funcion
	    */
	}

	void Reserva::denegar_reserva(char *fichero){
	    int num,cont;
	    cout<<"La lista de reservas actualmente es:"<<endl;
	    ifstream f;
	    f.open(fichero, fstream::in);
	    if(f.is_open()){
	        char aux[1000];
	        while(f.getline(aux, 1000, ',')){
	            cout<<aux<<" ";
	        }
	        cout<<endl;
	    }
	    f.close();
	    cont=contar(fichero);
	    int numDenegar=0;

	    while(numDenegar==0){
	        cout<<"Deseas eliminar al ultima reserva?"<<endl;
	        cout<<"1-Si     2-No"<<endl;
	        cin>>num;

	        if(num==1){
	            cout<<"Eliminando ultima reserva............"<<endl;
	            ifstream f(fichero);
	            ofstream file;
	            file.open("temporal2.txt", ios::out);
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
	            remove(fichero);
	            rename("temporal2.txt" ,fichero);
	            for(int i=0;i<3;i++){
	                cout<<"."<<endl;
	            }
	            cout<<"Ultima reserva eliminado con exito"<<endl;
	            cout<<endl;
	        }

	        int volver;
	        cout<<"Quieres eliminar mas reservas?"<<endl;
	        cout<<"1-Si     2-No"<<endl;
	        cin>>volver;
	        if(volver==2){
	            cout<<"Sus cambios han sido guardados"<<endl;
	            cout<<endl;
	            numDenegar++;
	        }
	    }

	    f.close();
	    /*
	    La funcion denegar_reserva() elimina la ultima reserva del fichero que le pasemos por el main
	    Nos muestra las reservas que tengamos en el fichero que le pasemos y hay confirmamos si lo queremos eliminar o no
	    El programa crea un fichero temporal donde vamos a introducir todos los valores menos el ultimo y despues elimina el fichero original y renombra el fichero temporal con el nombre del anterior fichero
	    Nos preguntara si queremos eliminar mas reservas, si respondemos si volveremos al paso anterior, si no acabara la funcion
	    */
	}

	int Reserva::contar(char *nombre){			/*
Esta funcion  nos permite contar las lineas de un fichero esto nos sirve para la funcion denegar_reserva() ya que necesitamos conocer el numero de lineas de cada fichero
*/
	    ifstream f;
	    f.open(nombre, fstream::in);
	    int cont=0;
	    char lin[1000];
	    while(f.getline(lin, 1000, '\n')){
	        cont++;
	    }
	    return cont;
	}





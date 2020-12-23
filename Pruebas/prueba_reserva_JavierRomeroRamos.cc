#include "Reserva.h"
#include "gtest/gtest.h"
#include <string>
#include <fstream>


TEST(Reserva,confirmar_reserva)
{
	Reserva s(1,"Prueba");
	bool resultado = s.confirmar_reserva("234             angel_rd             11/01/2019          10:30                      1 ");
	resultado = s.confirmar_reserva("342                  fran_ez              03/02/2019          11:30                      1");
	resultado = s.confirmar_reserva("212                  jesus_pt             04/01/2019          9:30                       2");
	resultado = s.confirmar_reserva("345                  javier_rr            06/02/2019          10:15                      2");
	resultado = s.confirmar_reserva("406                  alvaro_sq            14/03/2019          11:45                      1");
	resultado = s.confirmar_reserva("543                  juan_ml              14/04/2019          10:30                      2");
	resultado = s.confirmar_reserva("577                  rafael_rp            20/04/2019          17:30                      1 ");
	resultado = s.confirmar_reserva("587                  jose_cj              22/04/2019          12:15                      2");
	resultado = s.confirmar_reserva("598                  alicia_rq            30/04/2019          11:45                      1");
	resultado = s.confirmar_reserva("603                  raquel_rr            03/05/2019          9:30                       2");

	s.confirmar_reserva();

	char nom[256], n[256];
	string nombre;
	int numero, i=0;
	ifstream salida("salida.txt");
	const char v[] = {1,2,3,4,5,6,7,8,9,10};
	const char* v2[] = {"angel_rd","fran_ez","jesus_pt","javier_rr","alvaro_sq","juan_ml","rafael_rp","jose_cj","alicia_rq","raquel_rr"};
	while(salida.getline(n,256,','))
	{
		numero=atoi(n);
		salida.getline(nom,256,'\n');
		nombre = nom;
		EXPECT_EQ(v2[i], nombre);
		EXPECT_EQ(v[i], numero);
		i++;
	}
	EXPECT_GT(i,2);
	salida.close();
}

TEST(Reserva, buscar_reserva)
{
	Reserva s(1,"Prueba");
	bool resultado = s.seleccionar_reserva("Angel_Fernandez 234");
	resultado = s.seleccionar_reserva("Francico_Escribano   342");
	resultado = s.seleccionar_reserva("Jesus_Perez   212");
	resultado = s.seleccionar_reserva("Javier_Romero  345");
	resultado = s.seleccionar_reserva("Alvaro_Sanchez 406");
	resultado = s.seleccionar_reserva("Juan_Moral  543");
	resultado = s.seleccionar_reserva("Rafael_Romero  577");
	resultado = s.seleccionar_reserva("Jose_Caballero  587");
	resultado = s.seleccionar_reserva("Alicia_Ramos  598");
	resultado = s.seleccionar_reserva("Raquel_Ruiz  603");
	
	s.buscar_reserva();
}

#include "gtest/gtest.h"
#include "ruta.h"
#include "parque.h"
#include <iostream>
#include <fstream>
#include <string.h>

TEST(Ruta, asignaValores){
    Ruta r;
    r.asignaValores("prueba_ruta.txt");
    int duri=r.getDuracionR();
    float difil=r.getDifilcultadR();
    int distan=r.getdistanciaR();
    float tip=r.tipoR();
    EXPECT_EQ(210,duri);
    EXPECT_EQ(7750,distan);
    EXPECT_EQ(1,difil);
    EXPECT_EQ(1,tip);
}

TEST(Parque, leeFicheros){
    Parque p;
    p.leeFicheros("parque_prueba.txt");
    string nombre=p.getNombre();
    string provincia=p.getProvincia();
    string municipio=p.getMuncipio();
    string flora=p.getFlora();
    string fauna=p.getFauna();
    string relieve=p.getRelieve();
    string menciones=p.getMenciones();
    string rutas=p.getRutas();
    int extension=p.getExtenion();

    EXPECT_EQ("Parque de cordoba",nombre);
    EXPECT_EQ("Cordoba",provincia);
    EXPECT_EQ("Palma del rio",municipio);
    EXPECT_EQ("El ecosistema tiene arboles de hoja perenne",flora);
    EXPECT_EQ("La fauna consta de patos y insectos",fauna);
    EXPECT_EQ("Pasa el rio guadalquivir",relieve);
    EXPECT_EQ("Gano el premio de fotografia de 2020",menciones);
    EXPECT_EQ("EL parque contiene 2 rutas, la ruta de los patos y la ruta del rio",rutas);
    EXPECT_EQ(2000,extension);
}

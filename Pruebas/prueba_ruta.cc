#include "gtest/gtest.h"
#include "ruta.h"
#include "tramo.h"
#include <iostream>
#include <fstream>
#include <string.h>

TEST(Ruta, asignaValores){
    Ruta r;
    char Fname="ruta.txt";
    r.asignaValores(Fname);
    int duri=r.getDuracionR();
    float difil=r.getDifilcultadR();
    int distan=r.getdistanciaR();
    float tip=r.tipoR();
    EXPECT_EQ(235,duri);
    EXPECT_EQ(8500,distan);
    EXPECT_EQ(2.25,difil);
    EXPECT_EQ(1.25,tip);
}

TEST(Tramo, delete_tramo)){
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
    EXPECT_EQ(duri1,duri);
    EXPECT_EQ(distan1,distan);
    EXPECT_EQ(difil1,difil);
    EXPECT_EQ(tip1,tip);
}

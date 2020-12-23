#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "ruta.h"
#include "tramo.h"

void thisIsATest() {
	ASSERTM("start writing tests", false);	
}

void testRuta(){
    Ruta r;
    r.asignaValores("ruta1.txt");
    int duri=r.getDuracionR();
    float difil=r.getDifilcultadR();
    int distan=r.getdistanciaR();
    float tip=r.tipoR();
    ASSERT_EQUAL(235,duri);
    ASSERT_EQUAL(8500,distan);
    ASSERT_EQUAL(2.25,difil);
    ASSERT_EQUAL(1.25,tip);
}

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

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s {};
    s.push_back(CUTE(testRuta));    
    s.push_back(CUTE(testTramos));     
	s.push_back(CUTE(thisIsATest));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
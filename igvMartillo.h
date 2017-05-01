#pragma once
#include <GL/glut.h>
#include <iostream>
#include <Windows.h>
#include "igvMallaMartillo.h"
using namespace std;
class igvMartillo
{

private:
	
	double coorMundoX;
	double coorMundoY;
	//Proporcion entre las coordenadas de mundo y de ventana 
	double ratio;
	//Tamaño de la venta
	int tamVentanaX;
	int tamVentanaY;
	//Tam coordenadas mundo
	double tamViewPortX;
	double tamViewPortY;

	bool mallaMartilloCargada;
	 
	double rotacionGolpe;

	void generarMartillo();

public:
	igvMartillo(void);
	virtual ~igvMartillo(void);
	//Genera el martillo en la posicion x,y. Por defecto la z=2
	void cargarMartillo(int x,int y);
	void golpear();
	void levantar();
	igvMallaMartillo *mallaMartillo;

};


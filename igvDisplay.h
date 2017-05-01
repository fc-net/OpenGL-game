#pragma once
#include <GL\glut.h>
#include "igvTextura.h"
#include <iostream>
#include <string>
using namespace std;

class igvDisplay
{
private:

	
	void pintar(int numero,float xMin,float xMax);
	void posicionarlo(float xmin,float xmax);

	//------------------Atributos para las texturas del titulo y los numeros del 0-9
	void pintarTitulo(); 
	 
	void pintarNumero0(float xMin,float xMax);	
	
	void pintarNumero1(float xMin,float xMax);	

	void pintarNumero2(float xMin,float xMax);	

	void pintarNumero3(float xMin,float xMax);

	void pintarNumero4(float xMin,float xMax);	
 
	void pintarNumero5(float xMin,float xMax);	

	void pintarNumero6(float xMin,float xMax);

	void pintarNumero7(float xMin,float xMax);	

	void pintarNumero8(float xMin,float xMax);	

	void pintarNumero9(float xMin,float xMax);	

public:
	igvDisplay(void);
	virtual ~igvDisplay(void);
	/*
	* Dado un numero, dibuja ese numero en la pantalla
	*/
	void generarDisplay(int numero);

	igvTextura *titulo;
	igvTextura *numero0;
	igvTextura *numero1;
	igvTextura *numero2;
	igvTextura *numero3;
	igvTextura *numero4;
	igvTextura *numero5;
	igvTextura *numero6;
	igvTextura *numero7;
	igvTextura *numero8;
	igvTextura *numero9;


};


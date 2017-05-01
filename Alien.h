#pragma once
#include <GL/glut.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "igvPunto3D.h"
#include "igvMallaAlien.h"
#include <vector>

#include "igvColor.h"
#include "igvMaterial.h"
#include "igvFuenteLuz.h"

using namespace std;
class Alien
{
private:
	
	void iniciarMovimiento(vector<igvPunto3D> &entornoActual);//Genera el movimiento de un alien aleatorio
	void generarAlien(bool topoImpactado,GLuint nombre,igvPunto3D posicion);
	bool subirAlien;
	bool AlienEnMovimiento;
	bool estaImpactado;
	int AlienAleatorio;
	float desplazamiento;
	float tiempoEspera;//Tiempo de espera entre que sale un alien y el siguiente
	int impacto; //Identificador del alien que ha sido impactado 
	double posMaxImpacto;//Posicion maxima a la que se considera que se ha impactado
	double desplazamientoMaxSubida;//Posicion maxima a la que suben
	double desplazamientoMaxBajada;//Posicion maxima a la que bajan
	

	//--------------Variables asociadas al sistema de puntos--------------
	int puntos;
	void actualizarPuntos();
	bool considerarPunto;
	

public:
	Alien();
	virtual ~Alien(void);
	/*
	* Dado el vector de hoyos, situa en cada uno de ellos a un Alien
	*/
	void cargarAlien(vector<igvPunto3D> &entornoActual);
	
	igvMallaAlien *mallaAlien;

	void setImpacto(int _impacto);
	void procesarImpactoRaton(GLuint numeroImpacto);
	/*
	* Establece el nivel de dificultad
		 nivelDificultad es el tiempo que tarda en salir un alien y otro
	*/
	void setDificultad(double nivelDificultad);
	/*
	* Devuelve el numero de puntos totales conseguidos en el momento actual
	*/
	int getPuntos(){return puntos;};
};


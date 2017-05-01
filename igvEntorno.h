#pragma once
#include <GL/glut.h>
#include <cstdlib>
#include <stdio.h>
#include <vector>
#include "igvTextura.h"
#include "igvPunto3D.h"
#include "igvMallaCubo.h"


class igvEntorno
{
	private:

		vector<igvPunto3D> vectorHoyos;
	
		
		void generarSuelo();
		void generarCielo();
		void generarHoyo(float x,float y,float z);


	public:
		igvEntorno(void);
		virtual ~igvEntorno(void);
		void generarEscena();
		/*
		*	Devuelve el vector con las posiciones en la que se encuentran
		    los hoyos del mapa.
			Cada posicion del vector representa la localizacion(x,y,z) de un hoyo
		*/
		vector<igvPunto3D>& getVectorHoyos();

		igvTextura *texturaSuelo;
		igvTextura *texturaCielo;
		igvMallaCubo *mallaCubo;
	
};


#pragma once
#include<GL/glut.h>
#include "igvTextura.h"
#include "igvFuenteLuz.h"
#include "igvPunto3D.h"
#include "igvMaterial.h"


class igvMenu
{

 private:

	

	 //-------Metodos para cargar la textura
	void cargarInicio();
	void cargarDificultad();
	void cargarSalir();
	void cargarFacil();
	void cargarNormal();
	void cargarDificil();

	void cargarSubMenu();
	bool subMenuActivado;
	
	


public:
	igvMenu();
	virtual ~igvMenu(void);
	void activarMenu();
	void accion(GLint objeto,bool &empezarJugar,double &dificultad);


	//-----Texturas para los iconos del menu
	igvTextura *texturaFondo;
	igvTextura *texturaInicio;
	igvTextura *texturaDificultad;
	igvTextura *texturaSalir;
	igvTextura *texturaFacil;
	igvTextura *texturaNormal;
	igvTextura *texturaDificil;


	
};


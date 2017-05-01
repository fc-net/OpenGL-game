#ifndef __IGVESCENA3D
#define __IGVESCENA3D

#include <GL/glut.h>
#include <Windows.h>
#include <vector> 
#include "igvEntorno.h"
#include "Alien.h"
#include "igvMartillo.h"
#include "igvMenu.h"
#include "igvPunto3D.h"
#include "igvDisplay.h"

#include "igvMaterial.h"
#include "igvColor.h"
#include "igvFuenteLuz.h"
#include "igvMallaMartillo.h"
#include "igvMallaAlien.h"

class igvEscena3D {
	protected:

		

		// Atributos
		
		bool posicionesGuardadas;
		//Vector para almacenar las posiciones de los hoyos
		vector<igvPunto3D> vectorPosicionesHoyos;
		
		  
		
		//Posicionamiento del martillo
		int coordenadaX;
		int coordenadaY;

		bool golpear;
		bool martilloBajado;
		bool martilloLevantado;
		bool levantar;
		

		//Metodo para cambiar de vista		 
		bool panoramica;
		bool planta;
		bool paralela;
		 
		//Variables para ver el menu
		double zoom;
		igvPunto3D P,r,v;	
		bool reconfigurarCamara;
		bool empezarJugar;
		bool estadoMenu;
		double dificultad;

	public:
		// atributos públicos
		Alien *alien;	
		GLint objeto;
		igvEntorno *entorno;
		igvMartillo *martillo;
		igvDisplay *display;		
		igvMenu *menu;
		
		// Constructores por defecto y destructor
		igvEscena3D();
		~igvEscena3D();

		// Metodos estáticos

		// Métodos
		// método con las llamadas OpenGL para visualizar la escena
	    void visualizar();

		bool get_panoramica(){return this->panoramica;};
		void set_panoramica(bool _panoramica){this->panoramica=_panoramica;};

		bool get_planta(){return this->planta;};
		void set_planta(bool _planta){this->planta=_planta;};

		void  setParalela(bool _paralela){ this->paralela=_paralela;};
		int getParalela(){return  this->paralela;};

		void setCoordenadaX(int _coordenadaX){this->coordenadaX=_coordenadaX;};
		void setCoordenadaY(int _coordenadaY){this->coordenadaY=_coordenadaY;};
		
		void setGolpear(bool _golpear){this->golpear=_golpear;};
		void setLevantar(bool _levantar){this->levantar=_levantar;};

		igvPunto3D getP(){return P;};
		igvPunto3D getR(){return r;};
		igvPunto3D getV(){return v;};

		double getZoom(){return zoom;};
		bool getReconfigCamara(){return reconfigurarCamara;};
		void setReconfigCamara(bool estado){reconfigurarCamara=estado;};
		
		bool getEstadoMenu(){return estadoMenu;};
		void setEstadoMenu(bool estado){estadoMenu=estado;};

	
};

#endif

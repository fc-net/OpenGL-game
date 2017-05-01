#include "igvEscena3D.h"
 

// Metodos constructores 

igvEscena3D::igvEscena3D () {
	this->posicionesGuardadas=false;
	this->objeto=-1;
	this->golpear=false;
	this->levantar=false;
	this->martilloBajado=false;
	this->martilloLevantado=false;
	this->P.set(0,0,1);
	this->r.set(0,0,0);
	this->v.set(0,1,0);
	this->zoom=1;
	this->reconfigurarCamara=false;
	this->empezarJugar=false;
	this->estadoMenu=true;
	this->dificultad=3;
	

}

igvEscena3D::~igvEscena3D() {	
		
}



void igvEscena3D::visualizar(void) {
	// guarda la matriz de modelado
	glPushMatrix(); 

	
		
		
	//------Activacion del menu------
	if(estadoMenu){
		
		//Aplicacion del foco para el menu
		igvPunto3D posFoco(0,0,5);	
		igvColor cAmbFoco(1,0,0,1);
		igvColor cDifFoco(1,0.25,0.25,1);
		igvColor cEspFoco(1,1,1,1);
		igvPunto3D direccion(0,(coordenadaY*-0.01)+3.75,-5);//0.01=Ratio obtenido 4/800 (tamVentana/numPixeles)
		double anguloFoco=35;//0-90
		double expFoco=0;//0-128
		unsigned int idLuzFoco=GL_LIGHT1;	 
		igvFuenteLuz luzFoco(idLuzFoco,posFoco,cAmbFoco,cDifFoco,cEspFoco,1,0,0,direccion,anguloFoco,expFoco);		
		luzFoco.aplicar();	

		//Aplicacion para el tipo de material
		igvColor coeficienteAmbiental(1,0,0);
		igvColor coeficienteDifuso(1,0,0.0);
		igvColor coeficienteEspecular(0,1,1);

		igvMaterial material(coeficienteAmbiental,coeficienteDifuso,coeficienteEspecular,120);
		material.aplicar();


		menu->activarMenu();		 
		menu->accion(objeto,empezarJugar,dificultad);
			 
		if(empezarJugar){

			reconfigurarCamara=true;
			//Valores de la camara para que el juego se visualice correctamente
			P.set(0,2.4,0.5);
			r.set(0,0,-4);
			v.set(0,1.0,0);
			zoom=0;
			//Desactiva el menu
			estadoMenu=false;
			empezarJugar=false;	
		}		
		objeto=-1;
		
		
	}
	else
	{
			
		//-----Accion de golpear del martillo-----------
		if(golpear)
		{
			if(!martilloBajado){
				martillo->golpear();
				martilloBajado=true;
			}
		}
		else
		{
			if(martilloBajado){
				martillo->levantar();
				martilloBajado=false;
			}
		}
	
	
		martillo->cargarMartillo(coordenadaX,coordenadaY);
		
	
		entorno->generarEscena();
		//Guarda la posicion de los hoyos para introducir a los alien dentro
		if(!posicionesGuardadas){
			vectorPosicionesHoyos=entorno->getVectorHoyos();
			posicionesGuardadas=true;			
		}

		 
		alien->setDificultad(dificultad);
		alien->cargarAlien(vectorPosicionesHoyos);		
	

		//Los impactos validos comienzan a partir del 1	
		if(objeto>0){		
		
			alien->procesarImpactoRaton(objeto);
			objeto=-1;				
		}
		//Finalmente, representamos la puntuacion obtenida
		display->generarDisplay(alien->getPuntos());
	}
	
		

	glPopMatrix (); // restaura la matriz de modelado
}


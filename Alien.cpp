#include "Alien.h"


Alien::Alien( )
{
	this->subirAlien=true;
	this->AlienEnMovimiento=false;
	this->desplazamiento=0.01;
	this->tiempoEspera=2;
	this->impacto=-1;
	this->posMaxImpacto=-1.70;
	this->estaImpactado=false;	
	this->desplazamientoMaxSubida=0.75;
	this->desplazamientoMaxBajada=-1.75;
	this->puntos=0;
	this->considerarPunto=true;
	
}


Alien::~Alien(void)
{
	
}

void Alien::setDificultad(double nivelDificultad){
	this->tiempoEspera=nivelDificultad;

}

void Alien::generarAlien(bool AlienImpactado,GLuint nombre,igvPunto3D posicion){
	glInitNames();
	glPushName(nombre);
	glPushMatrix();
	
		if(AlienImpactado){
			
			mallaAlien->textura->cambiarModoAplicacion();//Cambiamos el modo de aplicacion de textura 

			igvPunto3D direccion=posicion;
			posicion.c[1]+=2;//Hay que subir el foco
			igvColor cAmbFoco(1,0,0,1);
			igvColor cDifFoco(1,1,1,1);
			igvColor cEspFoco(1,1,1,1);			
			double anguloFoco=15;//0-90
			double expFoco=40;//0-128
			unsigned int idLuzFoco=GL_LIGHT1;
	 
			igvFuenteLuz luzFoco(idLuzFoco,posicion,cAmbFoco,cDifFoco,cEspFoco,1,0,0,direccion,anguloFoco,expFoco);
		
			luzFoco.aplicar();

		
			igvColor coeficienteAmbiental(1,0,0);
			igvColor coeficienteDifuso(1,0,0.0);
			igvColor coeficienteEspecular(0,1,1);

			igvMaterial material(coeficienteAmbiental,coeficienteDifuso,coeficienteEspecular,120);
			material.aplicar();
		}
	
		
		glTranslatef(0,-1,0);
		glScalef(1.75,2,2);
		mallaAlien->cargarMallaAlien();

		mallaAlien->textura->restaurarModoAplicacion();//Restauramos el modo de aplicacion para que no afecte al resto de texturas

	glPopMatrix();

	glPopName();

}


void Alien::cargarAlien(vector<igvPunto3D> &entornoActual){
	
	bool AlienImpactado=false;
	GLuint nombreAux=1;
		for(int i=0;i<entornoActual.size();i++){
			glPushMatrix();
				glTranslatef(entornoActual[i].c[0],entornoActual[i].c[1],entornoActual[i].c[2]);
				
				//Los impactos comienzan desde el 1
				if(impacto==i+1 && entornoActual[i].c[1]>posMaxImpacto){
					
					AlienImpactado=true;
					subirAlien=false;	
					actualizarPuntos();
					
				}
				else{
					if(impacto==i+1 && entornoActual[i].c[1]<posMaxImpacto){
						impacto=-1;
					}
					AlienImpactado=false;
					
				}
				 
				generarAlien(AlienImpactado,nombreAux,entornoActual[i]);	
				nombreAux++;
				
				
			glPopMatrix();		
			
		}
		//Si hay algun Alien en movimiento, ralentiza su ejecucion  
		if(AlienEnMovimiento){			 			
			 
			Sleep(tiempoEspera);			 
		}

		iniciarMovimiento(entornoActual);

}




void Alien::iniciarMovimiento(vector<igvPunto3D> &entornoActual){
	
	if(!AlienEnMovimiento){	
		AlienEnMovimiento=true;
		srand(__rdtsc());//Semilla
		AlienAleatorio=rand()%entornoActual.size();
		
	}
	else
	{
		
		//Comprueba si puede seguir subiendo el Alien
		if(subirAlien){
			entornoActual[AlienAleatorio].c[1]+=desplazamiento;//Solo se cambia la posicion Y		
			//Cuando llega al tope, tiene que dejar de subir
			if(entornoActual[AlienAleatorio].c[1]>desplazamientoMaxSubida)
				subirAlien=false;
		}	
		else
		{
			entornoActual[AlienAleatorio].c[1]-=desplazamiento;
			//Cuando llega al minimo,reactivamos la seleccion aleatoria de Alien
			if(entornoActual[AlienAleatorio].c[1]<desplazamientoMaxBajada){
				subirAlien=true;
				AlienEnMovimiento=false;
				impacto=-1;
				considerarPunto=true;
			}
				
		}
		
	}
	
	glutPostRedisplay();
}


void Alien::setImpacto(int _impacto){

	this->impacto=_impacto;
	 
}

void Alien::procesarImpactoRaton(GLuint numeroImpacto){

	this->impacto=(int)numeroImpacto;

}

void Alien::actualizarPuntos(){
	//Aunque se golpee al mismo alien varias veces, solo se considera como punta 1 única vez
	if(considerarPunto){
		puntos++;
		considerarPunto=false;
	}

}
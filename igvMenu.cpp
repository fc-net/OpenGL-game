#include "igvMenu.h"


igvMenu::igvMenu()
{
	this->subMenuActivado=false;

}


igvMenu::~igvMenu(void)
{
	

}


void igvMenu::cargarInicio(){
	
	glEnable(GL_TEXTURE_2D);	 
	
	texturaInicio->aplicar();
	glBegin(GL_QUADS);

		glTexCoord2f(0,0);
		glVertex3f(-2.5,1.5,0.6);

		glTexCoord2f(1,0);
		glVertex3f(2.5,1.5,0.6);

		glTexCoord2f(1,1);
		glVertex3f(2.5,2.5,0.6);

		glTexCoord2f(0,1);
		glVertex3f(-2.5,2.5,0.6);
	
	glEnd(); 
	 
	glDisable(GL_TEXTURE_2D);
}

 

void igvMenu::cargarDificultad(){
	
	glEnable(GL_TEXTURE_2D);
	
	texturaDificultad->aplicar();
	glBegin(GL_QUADS);

		glTexCoord2f(0,0);
		glVertex3f(-2.5,-0.5,0.6);

		glTexCoord2f(1,0);
		glVertex3f(2.5,-0.5,0.6);

		glTexCoord2f(1,1);
		glVertex3f(2.5,0.5,0.6);

		glTexCoord2f(0,1);
		glVertex3f(-2.5,0.5,0.6);
	
	glEnd(); 
	 
	glDisable(GL_TEXTURE_2D);	

}


void igvMenu::cargarSalir(){
	
		glEnable(GL_TEXTURE_2D);
	
	texturaSalir->aplicar();
	glBegin(GL_QUADS);

		glTexCoord2f(0,0);
		glVertex3f(-2.5,-2.5,0.6);

		glTexCoord2f(1,0);
		glVertex3f(2.5,-2.5,0.6);

		glTexCoord2f(1,1);
		glVertex3f(2.5,-1.5,0.6);

		glTexCoord2f(0,1);
		glVertex3f(-2.5,-1.5,0.6);
	
	glEnd(); 
	 
	glDisable(GL_TEXTURE_2D);	
}

  
void igvMenu::activarMenu(){
	 

	glEnable(GL_TEXTURE_2D);


	texturaFondo->aplicar();	

	glBegin(GL_QUADS);

		glTexCoord2f(0.2,0);
		glVertex3f(-4,-4,0);

		glTexCoord2f(1,0);
		glVertex3f(4,-4,0);

		glTexCoord2f(1,1);
		glVertex3f(4,4,0);

		glTexCoord2f(0.2,1);
		glVertex3f(-4,4,0);
	
	glEnd(); 
	glDisable(GL_TEXTURE_2D);
	
	glInitNames();
	 
	
	 //----------------------------------
		glPushName(1);	
		glPushMatrix();			
			glTranslatef(0,2,0);
			glScalef(6,1.25,1);
			glutSolidCube(1);
		glPopMatrix();
		//Dependiendo de si queremos ver el menu o el submenu, se carga una textura u otra
		if(!subMenuActivado)
			cargarInicio();
		else
			cargarFacil();
		glPopName();
	//-----------------------------------
		glPushName(2);
		glPushMatrix();
			glScalef(6,1.25,1);
			glutSolidCube(1);
		glPopMatrix();
		if(!subMenuActivado)
			cargarDificultad();
		else
			cargarNormal();
		glPopName();
	//--------------------------------------
		glPushName(3);
		glPushMatrix();			
			glTranslatef(0,-2,0);	
			glScalef(6,1.25,1);
			glutSolidCube(1);
		glPopMatrix();
		if(!subMenuActivado)
			cargarSalir();
		else
			cargarDificil();
			glPopName();
			 
}

void igvMenu::accion(GLint objeto,bool &empezarJugar,double &dificultad){

	if(!subMenuActivado){
		if(objeto==1)
			empezarJugar=true;
		else
			if(objeto==2){
				subMenuActivado=true;

			}
			else
				if(objeto==3)
					exit(1);
	}
	else{
			

		if(objeto==1){//Facil
			dificultad=7;
			empezarJugar=true;
			subMenuActivado=false;
		}
		else{
			if(objeto==2){//Normal
				dificultad=3;
				empezarJugar=true;
				subMenuActivado=false;
			}
			else{
				
				if(objeto==3){//Dificil
					dificultad=0;
					empezarJugar=true;
					subMenuActivado=false;
				}
			}
			
		}
		

	}
	
}

void igvMenu::cargarFacil(){
	
	 
	glEnable(GL_TEXTURE_2D);	 
	
	texturaFacil->aplicar();
	glBegin(GL_QUADS);

		glTexCoord2f(0,0);
		glVertex3f(-2.5,1.5,0.6);

		glTexCoord2f(1,0);
		glVertex3f(2.5,1.5,0.6);

		glTexCoord2f(1,1);
		glVertex3f(2.5,2.5,0.6);

		glTexCoord2f(0,1);
		glVertex3f(-2.5,2.5,0.6);
	
	glEnd(); 
	 
	glDisable(GL_TEXTURE_2D);

}

void igvMenu::cargarNormal(){
	
	 
	glEnable(GL_TEXTURE_2D);	 
	
	texturaNormal->aplicar();
	glBegin(GL_QUADS);

		glTexCoord2f(0,0);
		glVertex3f(-2.5,-0.5,0.6);

		glTexCoord2f(1,0);
		glVertex3f(2.5,-0.5,0.6);

		glTexCoord2f(1,1);
		glVertex3f(2.5,0.5,0.6);

		glTexCoord2f(0,1);
		glVertex3f(-2.5,0.5,0.6);
	
	glEnd(); 
	 
	glDisable(GL_TEXTURE_2D);
	

}

void igvMenu::cargarDificil(){
	
	
	 
	glEnable(GL_TEXTURE_2D);	 
	texturaDificil->aplicar();
	
	glBegin(GL_QUADS);

		
		glTexCoord2f(0,0);
		glVertex3f(-2.5,-2.5,0.6);

		glTexCoord2f(1,0);
		glVertex3f(2.5,-2.5,0.6);

		glTexCoord2f(1,1);
		glVertex3f(2.5,-1.5,0.6);

		glTexCoord2f(0,1);
		glVertex3f(-2.5,-1.5,0.6);
	
	glEnd(); 
	 
	glDisable(GL_TEXTURE_2D);

}



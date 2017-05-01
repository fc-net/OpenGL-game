#include "igvEntorno.h"


igvEntorno::igvEntorno(void)
{
		 
}


igvEntorno::~igvEntorno(void)
{
	
	 
}





/*
*------------- Genera el suelo--------------
*/
void igvEntorno::generarSuelo(){

	GLfloat verde[]={0,1,0,1.0};

	glPushMatrix();
		glMaterialfv(GL_FRONT,GL_EMISSION,verde);
		glTranslatef(0,-1,0);
		glScalef(10,0.5,10);
		glutSolidCube(1);
	
	glPopMatrix();

	 
	
	glEnable(GL_TEXTURE_2D);
	texturaSuelo->aplicar();
	glBegin(GL_QUADS);

		glTexCoord2f(0,0);
		glVertex3f(-5,-0.7,6);

		glTexCoord2f(1,0);
		glVertex3f(5,-0.7,6);

		glTexCoord2f(1,1);
		glVertex3f(5,-0.7,-5);

		glTexCoord2f(0,1);
		glVertex3f(-5,-0.7,-5);
	
	glEnd();
	glDisable(GL_TEXTURE_2D);

   
}

/*
* ------------Genera el cielo----------------
*/
void igvEntorno::generarCielo(){
	 GLfloat azul[]={0,0,1,1.0};
	glPushMatrix();		 
	glMaterialfv(GL_FRONT,GL_EMISSION,azul);
		glTranslatef(0,2,-5.5);
		glScalef(10,6,1);
		glutSolidCube(1);
	glPopMatrix();

	 
	glEnable(GL_TEXTURE_2D);
	texturaCielo->aplicar();
	glBegin(GL_QUADS);

		glTexCoord2f(0,0);
		glVertex3f(-5,-0.75,-4.9);

		glTexCoord2f(1,0);
		glVertex3f(5,-0.75,-4.9);

		glTexCoord2f(1,1);
		glVertex3f(5,5.25,-4.9);

		glTexCoord2f(0,1);
		glVertex3f(-5,5.25,-4.9);
	
	glEnd();
	glDisable(GL_TEXTURE_2D);
	



}


void igvEntorno::generarHoyo(float x,float y,float z){

	glPushMatrix();

		//Posiciona el hoyo		
		glTranslatef(x,y,z);
		glScalef(5.5,5,5);		
		
		mallaCubo->cargarMallaCubo();

	 glPopMatrix();
}
 


/*
* Metodo principal que monta la escena
*/
void igvEntorno::generarEscena(){

	generarSuelo();
	generarCielo();
	

	double x,y,z;	 

	//---------------------------
	x=-3;
	y=-2;
	z=3;
	igvPunto3D hoyo1(x,y,z);
	vectorHoyos.push_back(hoyo1);
	generarHoyo(x,y,z);
	//---------------------------
	x=0;
	y=-2;
	z=3;
	igvPunto3D hoyo3(x,y,z);
	vectorHoyos.push_back(hoyo3);
	generarHoyo(x,y,z);
	//---------------------------
	x=3;
	y=-2;
	z=3;
	igvPunto3D hoyo2(x,y,z);
	vectorHoyos.push_back(hoyo2);
	generarHoyo(x,y,z);
	//---------------------------
	x=1.5;
	y=-1.75;
	z=1;
	igvPunto3D hoyo4(x,y,z);
	vectorHoyos.push_back(hoyo4);
	generarHoyo(x,y,z);
	//---------------------------
	x=-1.5;
	y=-1.75;
	z=1;
	igvPunto3D hoyo5(x,y,z);
	vectorHoyos.push_back(hoyo5);
	generarHoyo(x,y,z); 
	
}


vector<igvPunto3D>& igvEntorno::getVectorHoyos(){
	return vectorHoyos;
}
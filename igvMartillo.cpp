#include "igvMartillo.h"


igvMartillo::igvMartillo(void)
{
	this->coorMundoX=0;
	this->coorMundoY=0;	 	
	this->ratio=0.0125;//Proporcion entre el tamaño de la venta y las dimensiones de mundo 10/800
	this->tamVentanaX=800;
	this->tamVentanaY=800;
	//Aunque el tam del mundo es de 10, las coordenadas para cada cuadrante, van de -5 a +5
	this->tamViewPortX=5;
	this->tamVentanaY=5;
	this->mallaMartilloCargada=false;
	this->rotacionGolpe=0;
	
	
}


igvMartillo::~igvMartillo(void)
{
	
}


void igvMartillo::generarMartillo(){
	glPushMatrix();
	
		/*if(!mallaMartilloCargada){
			mallaMartillo=new igvMallaMartillo;
			mallaMartilloCargada=true;
		}*/
		
		glRotatef(rotacionGolpe,0,0,1);
		glRotatef(90,0,1,0);

		mallaMartillo->cargarMallaMartillo();

	glPopMatrix();


}


void igvMartillo::cargarMartillo(int x,int y){

	//COORDENADAS DE MUNDO X
	coorMundoX=(x*ratio)-5;
	
	//COORDENADAS DE MUNDO Y
	coorMundoY=-((y*ratio)-7);

	glPushMatrix();
	 
	glTranslated(coorMundoX,coorMundoY,0.5);
	generarMartillo();

	glPopMatrix();
	
}

void igvMartillo::golpear(){
	
	this->rotacionGolpe+=30;

}

void igvMartillo::levantar(){
	
	this->rotacionGolpe-=30;

}

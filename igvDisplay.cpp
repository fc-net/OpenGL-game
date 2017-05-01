#include "igvDisplay.h"


igvDisplay::igvDisplay(void)
{
	
}


igvDisplay::~igvDisplay(void)
{
	

}


void igvDisplay::posicionarlo(float xmin,float xmax){

	glBegin(GL_QUADS);

		glTexCoord2f(0,0);
		glVertex3f(xmin,5,-1);

		glTexCoord2f(1,0);
		glVertex3f(xmax,5,-1);

		glTexCoord2f(1,1);
		glVertex3f(xmax,6,-1);

		glTexCoord2f(0,1);
		glVertex3f(xmin,6,-1);
	
	glEnd(); 

}


void igvDisplay::pintarNumero0(float xMin,float xMax){

	glEnable(GL_TEXTURE_2D);

	numero0->aplicar();
	posicionarlo(xMin,xMax);
	
	glDisable(GL_TEXTURE_2D);

}
void igvDisplay::pintarNumero1(float xMin,float xMax){

	glEnable(GL_TEXTURE_2D);

	
	numero1->aplicar();
	posicionarlo(xMin,xMax);
	
	glDisable(GL_TEXTURE_2D);

}
void igvDisplay::pintarNumero2(float xMin,float xMax){

	glEnable(GL_TEXTURE_2D);

	
	numero2->aplicar();
	posicionarlo(xMin,xMax);
	
	glDisable(GL_TEXTURE_2D);

}
void igvDisplay::pintarNumero3(float xMin,float xMax){

	glEnable(GL_TEXTURE_2D);

	
	numero3->aplicar();
	posicionarlo(xMin,xMax);
	
	glDisable(GL_TEXTURE_2D);

}
void igvDisplay::pintarNumero4(float xMin,float xMax){

	glEnable(GL_TEXTURE_2D);

	
	numero4->aplicar();
	posicionarlo(xMin,xMax);
	
	glDisable(GL_TEXTURE_2D);

}
void igvDisplay::pintarNumero5(float xMin,float xMax){

	glEnable(GL_TEXTURE_2D);

	
	numero5->aplicar();
	posicionarlo(xMin,xMax);
	
	glDisable(GL_TEXTURE_2D);

}
void igvDisplay::pintarNumero6(float xMin,float xMax){

	glEnable(GL_TEXTURE_2D);

	
	numero6->aplicar();
	posicionarlo(xMin,xMax);
	
	glDisable(GL_TEXTURE_2D);

}
void igvDisplay::pintarNumero7(float xMin,float xMax){

	glEnable(GL_TEXTURE_2D);

	
	numero7->aplicar();
	posicionarlo(xMin,xMax);
	
	glDisable(GL_TEXTURE_2D);

}
void igvDisplay::pintarNumero8(float xMin,float xMax){

	glEnable(GL_TEXTURE_2D);

	
	numero8->aplicar();
	posicionarlo(xMin,xMax);
	
	glDisable(GL_TEXTURE_2D);

}
void igvDisplay::pintarNumero9(float xMin,float xMax){

	glEnable(GL_TEXTURE_2D);

	
	numero9->aplicar();
	posicionarlo(xMin,xMax);
	
	glDisable(GL_TEXTURE_2D);

}



void igvDisplay::pintar(int numero,float xMin,float xMax){
	
	if(numero==0)
		pintarNumero0(xMin,xMax);
	else
		if(numero==1)
			pintarNumero1(xMin,xMax);
		else
			if(numero==2)
				pintarNumero2(xMin,xMax);
			else
				if(numero==3)
					pintarNumero3(xMin,xMax);
				else
					if(numero==4)
						pintarNumero4(xMin,xMax);
					else
						if(numero==5)
							pintarNumero5(xMin,xMax);
						else
							if(numero==6)
								pintarNumero6(xMin,xMax);
							else
								if(numero==7)
									pintarNumero7(xMin,xMax);
								else
									if(numero==8)
										pintarNumero8(xMin,xMax);
									else
										if(numero==9)
											pintarNumero9(xMin,xMax);


}


void igvDisplay::pintarTitulo(){
	glEnable(GL_TEXTURE_2D);
	
	titulo->aplicar();
	glBegin(GL_QUADS);

		glTexCoord2f(0.2,0);
		glVertex3f(-4,6,-1);

		glTexCoord2f(1,0);
		glVertex3f(0,6,-1);

		glTexCoord2f(1,1);
		glVertex3f(0,7,-1);

		glTexCoord2f(0.2,1);
		glVertex3f(-4,7,-1);
	
	glEnd(); 

	glDisable(GL_TEXTURE_2D);
}



void igvDisplay::generarDisplay(int numero){
	 
	float min=-3;
	float max=-2;
	string numeroString=to_string(numero);

	pintarTitulo();

	string aux;
	
	//Cada digito es dibujado usando una textura que depende del valor de éste
	for(int i=0;i<numeroString.size();i++){
		
		aux=numeroString[i];
		pintar(atoi(aux.c_str()),min,max);
		min=max;
		max++;

	}
	
	

	
}

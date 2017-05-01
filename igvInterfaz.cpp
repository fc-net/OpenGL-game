#include <cstdlib>
#include <stdio.h>

#include "igvInterfaz.h"

extern igvInterfaz interfaz; // los callbacks deben ser estaticos y se requiere este objeto para acceder desde
                             // ellos a las variables de la clase

// Metodos constructores -----------------------------------

igvInterfaz::igvInterfaz () {
//// Apartado D: inicialización de los atributos para realizar la selección mediante lista de impactos
	modo = IGV_VISUALIZAR;
	objeto_seleccionado = -1;
	boton_retenido = false;
	activarAnimacion=false;
	
}

igvInterfaz::~igvInterfaz () {

	delete interfaz.escena.menu->texturaDificil;
	delete interfaz.escena.menu->texturaNormal;
	delete interfaz.escena.menu->texturaFacil;
	delete interfaz.escena.menu->texturaFondo;
	delete interfaz.escena.menu->texturaSalir;
	delete interfaz.escena.menu->texturaDificultad;
	delete interfaz.escena.menu->texturaInicio;
	delete interfaz.escena.menu;

	
	delete interfaz.escena.entorno->texturaSuelo;
	delete interfaz.escena.entorno->texturaCielo;
	delete interfaz.escena.entorno->mallaCubo->textura;
	delete interfaz.escena.entorno;

	
	delete interfaz.escena.alien->mallaAlien->textura;
	delete interfaz.escena.alien;

	
	delete interfaz.escena.martillo->mallaMartillo->textura;
	delete interfaz.escena.martillo;

	
	delete interfaz.escena.display->titulo;
	delete interfaz.escena.display->numero0;
	delete interfaz.escena.display->numero1;
	delete interfaz.escena.display->numero2;
	delete interfaz.escena.display->numero3;
	delete interfaz.escena.display->numero4;
	delete interfaz.escena.display->numero5;
	delete interfaz.escena.display->numero6;
	delete interfaz.escena.display->numero7;
	delete interfaz.escena.display->numero8;
	delete interfaz.escena.display->numero9;
	delete interfaz.escena.display;

}


// Metodos publicos ----------------------------------------

void igvInterfaz::crear_mundo(void) {

	//Valores iniciales para visualizar correctamente el menu

	interfaz.camara.set(IGV_PARALELA, interfaz.escena.getP(),interfaz.escena.getR(),interfaz.escena.getV(),
		                                -1*5, 1*5, -1*5, 1*5, -1*3, 200);
	interfaz.camara.zoom(interfaz.escena.getZoom());

	//-----------------------------  CARGA INICIAL DE TODAS LAS TEXTURAS ------------------------------
	interfaz.escena.menu=new igvMenu;
	interfaz.escena.menu->texturaInicio=new igvTextura("texturas/menu/comenzar.bmp");
	interfaz.escena.menu->texturaDificultad=new igvTextura("texturas/menu/dificultad.bmp");
	interfaz.escena.menu->texturaSalir=new igvTextura("texturas/menu/salir.bmp");
	interfaz.escena.menu->texturaFondo=new igvTextura("texturas/menu/fondo.bmp");
	interfaz.escena.menu->texturaFacil=new igvTextura("texturas/menu/facil.bmp");
	interfaz.escena.menu->texturaNormal=new igvTextura("texturas/menu/normal.bmp");
	interfaz.escena.menu->texturaDificil=new igvTextura("texturas/menu/dificil.bmp");

	interfaz.escena.entorno=new igvEntorno;
	interfaz.escena.entorno->texturaSuelo=new igvTextura("texturas/grass.bmp");
	interfaz.escena.entorno->texturaCielo=new igvTextura("texturas/sky.bmp");
	interfaz.escena.entorno->mallaCubo=new igvMallaCubo;
	interfaz.escena.entorno->mallaCubo->textura=new igvTextura("texturas/Hoyo_Textura.bmp");



	interfaz.escena.alien=new Alien;
	interfaz.escena.alien->mallaAlien=new igvMallaAlien;
	interfaz.escena.alien->mallaAlien->textura=new igvTextura("texturas/Alien_Textura.bmp");

	interfaz.escena.martillo=new igvMartillo;
	interfaz.escena.martillo->mallaMartillo=new igvMallaMartillo;
	interfaz.escena.martillo->mallaMartillo->textura=new igvTextura("texturas/Martillo_Textura.bmp");

	interfaz.escena.display=new igvDisplay;
	interfaz.escena.display->titulo=new igvTextura("texturas/display/puntuacion.bmp");
	interfaz.escena.display->numero0=new igvTextura("texturas/display/0.bmp");
	interfaz.escena.display->numero1=new igvTextura("texturas/display/1.bmp");
	interfaz.escena.display->numero2=new igvTextura("texturas/display/2.bmp");
	interfaz.escena.display->numero3=new igvTextura("texturas/display/3.bmp");
	interfaz.escena.display->numero4=new igvTextura("texturas/display/4.bmp");
	interfaz.escena.display->numero5=new igvTextura("texturas/display/5.bmp");
	interfaz.escena.display->numero6=new igvTextura("texturas/display/6.bmp");
	interfaz.escena.display->numero7=new igvTextura("texturas/display/7.bmp");
	interfaz.escena.display->numero8=new igvTextura("texturas/display/8.bmp");
	interfaz.escena.display->numero9=new igvTextura("texturas/display/9.bmp");


	

}

void igvInterfaz::configura_entorno(int argc, char** argv,
			                              int _ancho_ventana, int _alto_ventana,
			                              int _pos_X, int _pos_Y,
													          string _titulo){
	// inicialización de las variables de la interfaz																	
	ancho_ventana = _ancho_ventana;
	alto_ventana = _alto_ventana;

	// inicialización de la ventana de visualización
	glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(_ancho_ventana,_alto_ventana);
  glutInitWindowPosition(_pos_X,_pos_Y);
	glutCreateWindow(_titulo.c_str());

	glEnable(GL_DEPTH_TEST); // activa el ocultamiento de superficies por z-buffer
  glClearColor(1.0,1.0,1.0,0.0); // establece el color de fondo de la ventana

	glEnable(GL_LIGHTING); // activa la iluminacion de la escena
  glEnable(GL_NORMALIZE); // normaliza los vectores normales para calculo iluminacion

	crear_mundo(); // crea el mundo a visualizar en la ventana
}

void igvInterfaz::inicia_bucle_visualizacion() {
	glutMainLoop(); // inicia el bucle de visualizacion de OpenGL
}



void igvInterfaz::set_glutKeyboardFunc(unsigned char key, int x, int y) {
	
	switch (key) {
		 case '+': // zoom in
			interfaz.camara.zoom(0.1);
			break;
		  case '-': // zoom out
			interfaz.camara.zoom(-0.1);
			break;

		 case 'v': // cambia la posición de la cámara para mostrar las vistas planta, perfil, alzado o perspectiva

			if(interfaz.escena.get_panoramica())
			{		
				interfaz.camara.set(igvPunto3D(0,5,0),igvPunto3D(0,0,0),igvPunto3D(1,0,0));
				interfaz.camara.aplicar();
				interfaz.escena.set_panoramica(false);
				interfaz.escena.set_planta(true);
			}
			else
			{
				if(interfaz.escena.get_planta())
				{				
					interfaz.camara.set(igvPunto3D(5,0,0),igvPunto3D(0,0,0),igvPunto3D(0,1,0));
					interfaz.camara.aplicar();
					interfaz.escena.set_planta(false);
				}
				else
				{
						if(interfaz.escena.getParalela())
						{
							interfaz.camara.set(igvPunto3D(0,0,5),igvPunto3D(0,0,0),igvPunto3D(0,1,0));
			     			interfaz.camara.aplicar();		
							interfaz.escena.setParalela(false);						
						}
						else
						{				
							interfaz.camara.set(igvPunto3D(3,2,4),igvPunto3D(0,0.75,0),igvPunto3D(0,1,0));
							interfaz.camara.aplicar();	
							interfaz.escena.set_panoramica(true);
							interfaz.escena.setParalela(true);
						}		
				}			
			}
		break;
		case '1':
			interfaz.escena.alien->setImpacto(1);		 
		break;

		case '2':
		interfaz.escena.alien->setImpacto(2);		
		break;

		case '3':
		interfaz.escena.alien->setImpacto(3);		
		break;

		case '4':
		interfaz.escena.alien->setImpacto(5);		
		break;

		case '6':
		interfaz.escena.alien->setImpacto(4);
		break;

		case 'p':
			if(!interfaz.escena.getEstadoMenu()){
				interfaz.escena.setEstadoMenu(true);
				interfaz.camara.set(igvPunto3D(0,0,1),igvPunto3D(0,0,0),igvPunto3D(0,1,0));
				interfaz.camara.zoom(1);
				interfaz.camara.aplicar();					
			
			}
			break;

    case 27: // tecla de escape para SALIR
      exit(1);
    break;
  }
	glutPostRedisplay(); // renueva el contenido de la ventana de vision
}

void igvInterfaz::set_glutReshapeFunc(int w, int h) {

  // dimensiona el viewport al nuevo ancho y alto de la ventana
  // guardamos valores nuevos de la ventana de visualizacion
  interfaz.set_ancho_ventana(w);
  interfaz.set_alto_ventana(h);

	// establece los parámetros de la cámara y de la proyección
	interfaz.camara.aplicar();
}

void igvInterfaz::set_glutDisplayFunc() {

	//Dependiendo de si se esta visualizando el juego o el menu, la posicion de la camara tambien se tiene de reconfigurar
	//Los parametros vienen proporcionados por la escena que es la contiene la camara que se tiene que visualizar
	if(interfaz.escena.getReconfigCamara()){
		interfaz.camara.set(IGV_PARALELA, interfaz.escena.getP(),interfaz.escena.getR(),interfaz.escena.getV(),
											-1*5, 1*5, -1*5, 1*5, -1*3, 200);
		interfaz.camara.zoom(interfaz.escena.getZoom());
		interfaz.camara.aplicar();
		interfaz.escena.setReconfigCamara(false);
	}


	GLuint lista_impactos[1024]; // array con la lista de impactos cuando se visualiza en modo selección

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // borra la ventana y el z-buffer

	// se establece el viewport
	glViewport(0, 0, interfaz.get_ancho_ventana(), interfaz.get_alto_ventana());

	// Apartado D: antes de aplicar las transformaciones de cámara y proyección hay comprobar el modo,
	if (interfaz.modo == IGV_SELECCIONAR) {
		
	  // Apartado D: si se está seleccionando se pasa a modo selección de OpenGL y se pasan los parámetros de selección a la cámara
    interfaz.inicia_seleccion(1024,lista_impactos);
	}

	// aplica las transformaciones en función de los parámetros de la cámara y del modo (visualización o selección)
	interfaz.camara.aplicar();

	// visualiza la escena
	interfaz.escena.visualizar();

	if (interfaz.modo == IGV_SELECCIONAR) {
		
		// Apartado D: salir del modo seleccion y procesar la lista de impactos
		interfaz.finaliza_seleccion(1024,lista_impactos); 
	}	else {
		// refresca la ventana
		glutSwapBuffers();
	}
}


void igvInterfaz::set_glutMouseFunc(GLint boton,GLint estado,GLint x,GLint y) {
	 

	if(estado==0){
		interfaz.boton_retenido=true;
		interfaz.modo=IGV_SELECCIONAR;	
		
		interfaz.cursorX=x;
		interfaz.cursorY=y;			

		interfaz.escena.setGolpear(true);
		
	}

	else
	{				 
		interfaz.escena.setGolpear(false);
		interfaz.boton_retenido=false;		
			
	}
	glutPostRedisplay();
}

void igvInterfaz::set_glutMotionFunc(GLint x,GLint y) {
	 
// guardar la nueva posición del ratón 
		interfaz.cursorX=x;
		interfaz.cursorY=y;			 
	
// renovar el contenido de la ventana de vision 
	glutPostRedisplay();
}

void igvInterfaz::set_glutIdleFunc() {
	
	glutPostRedisplay();	
}


void igvInterfaz::MousePassiveMotion(int x, int y){

	interfaz.escena.setCoordenadaX(x);
	interfaz.escena.setCoordenadaY(y);

}


void igvInterfaz::inicializa_callbacks() {
	glutKeyboardFunc(set_glutKeyboardFunc);
	glutReshapeFunc(set_glutReshapeFunc);
	glutDisplayFunc(set_glutDisplayFunc);
	glutPassiveMotionFunc(MousePassiveMotion);//Nuevo callback para detectar la posicion del raton de forma continua

  glutMouseFunc(set_glutMouseFunc); 
  glutMotionFunc(set_glutMotionFunc); 
	glutIdleFunc(set_glutIdleFunc);
}

void igvInterfaz::inicia_seleccion(int TAMANO_LISTA_IMPACTOS, GLuint *lista_impactos) {
	//  establecer dónde se van a almacenar los impactos
	glSelectBuffer(TAMANO_LISTA_IMPACTOS,lista_impactos);

	//   pasar a modo de seleccion de OpenGL
	glRenderMode(GL_SELECT);

	//  establecer la camara en modo seleccion con los parámetros necesarios para realizar la selección
	// para el alto y el ancho de la ventana de selección probar diferentes tamaños y comprobar la amplitud de la selección
	interfaz.camara.establecerSeleccion(ancho_ventana,alto_ventana,cursorX,cursorY);
}

 
int procesar_impactos(int numero_impactos,GLuint *lista_impactos) {
/*  esta función debe devolver el código del objeto seleccionado, que no tiene porque coincidir con el nombre
   asignado con la pila de nombres, y si se han utilizado nombres jerárquicos hay que tener en cuenta que
   esta función sólo devolver un único código */

	if(numero_impactos==0) return -1;
	//  recorrer la lista de impactos con numero_impactos impactos,
	// guardar el más próximo al observador (minima Z)
	// para empezar, considerar que la mínima Z tiene un valor de 0xffffffff (el tope del tipo GLuint)
	GLuint minz=0xffffffff; 
    char str[100]; 
    string min; 
    int pos, recorrido=0;
    for(int i=0; i<numero_impactos; i++) {
        pos=i+recorrido;
        if(lista_impactos[pos+1]<minz) {
            minz=lista_impactos[pos+1];
            min = "";
           for(int j=0; j<lista_impactos[pos];j++) {
             min = min + itoa(lista_impactos[j+pos+3],str,10);
            }
        }
        recorrido+=2+lista_impactos[pos];
    }
    //cout<<"OBJETO IMPACTADO: "<<min<<endl;
	return atoi(min.c_str());
}
 

void igvInterfaz::finaliza_seleccion(int TAMANO_LISTA_IMPACTOS, GLuint *lista_impactos) {
    	
	//volver a modo visualizacion OpenGL y obtener el número de impactos
    TAMANO_LISTA_IMPACTOS=glRenderMode(GL_RENDER);
    
	//  si hay impactos pasar a procesarlos con la funcion int procesar_impactos(numero_impactos,lista_impactos);
	// obteniendo el objeto seleccionado, si lo hay
	interfaz.escena.objeto=procesar_impactos(TAMANO_LISTA_IMPACTOS, lista_impactos);
	objeto_seleccionado=interfaz.escena.objeto;
	//  seleccion terminada, pasar a visualización normal
    interfaz.modo=IGV_VISUALIZAR;
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glFlush();
    
	// establecer la camara en modo visualización
    interfaz.camara.establecerVisualizacion();
    interfaz.camara.aplicar();
}

void igvInterfaz::setCamara(igvPunto3D a,igvPunto3D b,igvPunto3D c){

	interfaz.camara.set(a,b,c);
	interfaz.camara.aplicar();

}
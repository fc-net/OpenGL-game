#include "igvMaterial.h"

// Metodos constructores 

igvMaterial::igvMaterial () {
	
}

igvMaterial::~igvMaterial () {

}

igvMaterial::igvMaterial (const igvMaterial& p) {	//de copia
	Ka = p.Ka;
	Kd = p.Kd;
	Ks = p.Ks;
	Ns = p.Ns;
}

igvMaterial::igvMaterial(igvColor _Ka, igvColor _Kd, igvColor _Ks, double _Ns) {
	Ka = _Ka;
	Kd = _Kd;
	Ks = _Ks;
	Ns = _Ns;
}

// Metodos publicos 

void igvMaterial::aplicar(void) {

// APARTADO C
// Aplicar los valores de los atributos del objeto igvMaterial:

	
	GLfloat refAmbiental[3];
	GLfloat refDifusa[3];
	GLfloat refEspecular[3];
	GLfloat expPhong[1];
	expPhong[0]=Ns;
	
	for(int i=0;i<3;i++)
	{
		refAmbiental[i]=Ka[i];
		refDifusa[i]=Kd[i];
		refEspecular[i]=Ks[i];			
	}
	// - coeficiente de reflexión de la luz ambiental
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,refAmbiental);
	// - coeficiente de reflexión difuso
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,refDifusa);
	// - coeficiente de reflesión especular
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,refEspecular);	
	// - exponente de Phong
	glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,expPhong);
	// establecer como color de emisión (0.0, 0.0, 0.0) (el objeto no es una fuente de luz)
	GLfloat colorEmision[3]={0,0,0};
	glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,colorEmision);


}

void igvMaterial::set(igvColor _Ka, igvColor _Kd, igvColor _Ks, double _Ns) {
	Ka = _Ka;
	Kd = _Kd;
	Ks = _Ks;
	Ns = _Ns;
}




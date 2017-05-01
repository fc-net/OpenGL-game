#pragma once
#include <GL/glut.h>
#include <iostream>
#include "igvTextura.h"


using namespace std;

class igvMallaAlien
{
private:
	
	
	GLfloat *_v_triangles;
	GLfloat *_vt_triangles;
	GLfloat *_vn_triangles;
	
public:
	igvMallaAlien(void);
	virtual ~igvMallaAlien(void);
	igvTextura *textura;
	void cargarMallaAlien();

};


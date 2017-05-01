#pragma once
#include<GL\glut.h>
#include <iostream>
#include "igvTextura.h"
using namespace std;

class igvMallaCubo
{
private:

	
	GLfloat *_v_triangles;
	GLfloat *_vt_triangles;
	GLfloat *_vn_triangles;

public:
	igvMallaCubo(void);
	virtual ~igvMallaCubo(void);
	void cargarMallaCubo();
	igvTextura *textura;
};


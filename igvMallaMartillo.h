#pragma once
#include<GL\glut.h>
#include "igvTextura.h"

class igvMallaMartillo
{

private:

	
	GLfloat *_v_triangles;
	GLfloat *_vt_triangles;
	GLfloat *_vn_triangles;
	

public:
	igvMallaMartillo(void);
	virtual ~igvMallaMartillo(void);
	void cargarMallaMartillo();
	igvTextura *textura;
};


#include "nastavGl.h"

nastavGl::nastavGl()
{
	glEnable(GL_TEXTURE_2D);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_DEPTH_TEST);
	glLoadIdentity();
	glOrtho(-5, 5, -5, 5, -1, 1);
	glScalef(1, -1, 1);
}

void nastavGl::zmenaGL(int sirka, int vyska)
{
	glViewport(0, 0, sirka, vyska);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5, 5, -5, 5, -1, 1);
	glScalef(1, -1, 1);
}

void nastavGl::obnov()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5, 5, -5, 5, -1, 1);
	glScalef(1, -1, 1);
}

#include "kresliObjekt.h"

void kresliObjekt::kruh(float polomer, float pocetSegmentu)
{
	float x, y;
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < pocetSegmentu; i++) {
		x = polomer * cos(i * 2.0 * 3.14159 / (float)numberofpoints);
		y = polomer * sin(i * 2.0 * 3.14159 / (float)numberofpoints);
		glVertex2f((float)x, (float)y);
	}
	glEnd();
}

void kresliObjekt::srdce()
{
	float xx, yy;

	glColor3f(1.0, 0.0, 0.0);
	glLineWidth(3.0);

	glBegin(GL_LINE_STRIP);

	for (xx = -1.0; xx <= 1.0; xx += 0.01)
	{
		yy = kresliObjekt::vypocet(xx, true);
		//yy = cbrt(xx * xx) + sqrt(1 - (xx * xx));
		glVertex2f(2 * xx, 2 * -yy);
	}

	for (xx = 1.0; xx >= -1.0; xx -= 0.01)
	{
		yy = kresliObjekt::vypocet(xx, false);
		//yy = cbrt(xx * xx) - sqrt(1 - (xx * xx));
		glVertex2f(2 * xx, 2 * -yy);
	}
	glEnd();
}

float kresliObjekt::vypocet(float x, bool plus)
{
	float y;
	if (plus)
	{
		y = cbrt(x * x) + sqrt(1 - (x * x));
	}
	else
	{
		y = cbrt(x * x) - sqrt(1 - (x * x));
	}
	return y;

}

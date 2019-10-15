#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <math.h>

class kresliObjekt
{
public:
	void kruh(float polomer, float pocetSegmentu);		int numberofpoints = 100;
	void srdce(); // //kresli srdce: y = cbrt(x^2) +- sqrt(1-x^2)

private:
	float vypocet(float x, bool plus);



};


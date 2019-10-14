// Cviceni4udalosti.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <math.h>

using namespace std;
//using namespace sf;


int main()
{
	sf::Window Aplikace(sf::VideoMode(800, 600), "Cviceni 4 - udalosti");

	bool jeFull = false;

	//nastaveni OpenGL

	glEnable(GL_TEXTURE_2D);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_DEPTH_TEST);
	glLoadIdentity();
	glOrtho(-5, 5, -5, 5, -1, 1);
	glScalef(1, -1, 1);
	//glTranslatef(0, 2.5, 0);
	int oldX = 0, oldY = 0, newY = 0, newX = 0;
	int mouseX = 0, mouseY = 0;
	double newAngle = 0, rotAngle = 0, oldAngle = 0;

	bool posun = false;
	bool rotace = false;

	while (Aplikace.isOpen())
	{
	

		sf::Event Udalosti;

		while (Aplikace.pollEvent(Udalosti))
		{
			switch (Udalosti.type)
			{
			case sf::Event::Closed:
				Aplikace.close();
				break;
			case sf::Event::Resized:
				glViewport(0, 0, Udalosti.size.width, Udalosti.size.height);
				glMatrixMode(GL_PROJECTION);
				glLoadIdentity();
				glOrtho(-5, 5, -5, 5, -1, 1);
				glScalef(1, -1, 1);
			case sf::Event::KeyPressed:
				switch (Udalosti.key.code)
				{
				case sf::Keyboard::Escape:
					cout << "Pressed ESC " << endl;
					Aplikace.close();
					break;

				case sf::Keyboard::W:
					cout << "Stisknuto W " << endl;
					switch (jeFull)
					{
					case false:
						Aplikace.create(sf::VideoMode(800, 600), "Cviceni 4 - udalosti", sf::Style::Fullscreen);
						//glViewport(0, 0, Udalosti.size.width, Udalosti.size.height);
						glMatrixMode(GL_PROJECTION);
						glLoadIdentity();
						glOrtho(-5, 5, -5, 5, -1, 1);
						glScalef(1, -1, 1);
						jeFull = true;
						break;

					case true:
						Aplikace.create(sf::VideoMode(800, 600), "Cviceni 4 - udalosti", sf::Style::Default);
						glMatrixMode(GL_PROJECTION);
						glLoadIdentity();
						glOrtho(-5, 5, -5, 5, -1, 1);
						glScalef(1, -1, 1);						
						jeFull = false;
						break;


					}
					break;

				}


			case sf::Event::MouseButtonPressed:
				switch (Udalosti.mouseButton.button)
				{
				case sf::Mouse::Left:
					mouseX = sf::Mouse::getPosition().x;
					mouseY = sf::Mouse::getPosition().y;
					cout << mouseX << ";" << mouseY << endl;
					break;

				case sf::Mouse::Right:
					cout << "Prave mysitko " << endl;
					newAngle = atan2(double(-sf::Mouse::getPosition().y), double(+sf::Mouse::getPosition().x));
					
					cout << "ROTANGLE: " << rotAngle * 180 / 3.14159 << endl;
					break;
				}
				break;

			case sf::Event::MouseMoved:

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					float pokus = sf::Mouse::getPosition().x;
					newX = -mouseX + sf::Mouse::getPosition().x + oldX;
					newY = -mouseY + sf::Mouse::getPosition().y + oldY;
					


						posun = true;
					//cout << "Leve mysitko pohyb " << endl;
				}
				else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
				{
				
					rotAngle = -newAngle + atan2(double(-sf::Mouse::getPosition().y ), double(sf::Mouse::getPosition().x)) + oldAngle;

			
					//cout << rotAngle << endl;

					rotace = true;
					//cout << "Prave mysitko pohyb " << endl;
				}
				break;

			case sf::Event::MouseButtonReleased:
				oldX = newX;
				oldY = newY;
				oldAngle = rotAngle;
				cout << "Cudlik byl uvolnen" << endl;
				break;

			}


		}

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		if (rotace == true || posun == true)
		{
			glClear(GL_COLOR_BUFFER_BIT);       // vymazani bitovych rovin barvoveho bufferu (mame RGBA buffer)
			glMatrixMode(GL_MODELVIEW);         // bude se menit matice modelview (matice, do ktere se zapisuje model pro vykresleni)
			glLoadIdentity();                   // vynulovani predchozi transformace
			glTranslatef((float)(newX / 100.0), (float)(newY / 100.0), 0);
			glRotatef((rotAngle * 180.0f / 3.14f * 10), 0, 0, 1.0);
		}
		

		// kresli kruh
		int numberofpoints = 100;
		float perimeter = 4;
		float x, y;
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_LINE_LOOP);
		for (int i = 0; i < numberofpoints; i++) {
			x = perimeter * cos(i * 2.0 * 3.14159 / (float)numberofpoints);
			y = perimeter * sin(i * 2.0 * 3.14159 / (float)numberofpoints);
			glVertex2f((float)x, (float)y);
		}
		glEnd();


		//kresli srdce: y = cbrt(x^2) +- sqrt(1-x^2)

		float xx, yy;

		glColor3f(1.0, 0.0, 0.0);
		glLineWidth(3.0);

		glBegin(GL_LINE_STRIP);

		for (xx = -1.0; xx <= 1.0; xx += 0.01)
		{
			yy = 2 *(cbrt(xx * xx) + sqrt(1 - (xx * xx)));
			glVertex2f(2*xx, -yy);
		}

		for (xx = 1.0; xx >= -1.0; xx -= 0.01)
		{
			yy = 2 * (cbrt(xx * xx) - sqrt(1 - (xx * xx)));
			glVertex2f(2 * xx, -yy);
		}
		glEnd();



		glFlush();

		Aplikace.display();

	}

}

// Spuštění programu: Ctrl+F5 nebo nabídka Ladit > Spustit bez ladění
// Ladění programu: F5 nebo nabídka Ladit > Spustit ladění

// Tipy pro zahájení práce:
//   1. K přidání nebo správě souborů použijte okno Průzkumník řešení.
//   2. Pro připojení ke správě zdrojového kódu použijte okno Team Explorer.
//   3. K zobrazení výstupu sestavení a dalších zpráv použijte okno Výstup.
//   4. K zobrazení chyb použijte okno Seznam chyb.
//   5. Pokud chcete vytvořit nové soubory kódu, přejděte na Projekt > Přidat novou položku. Pokud chcete přidat do projektu existující soubory kódu, přejděte na Projekt > Přidat existující položku.
//   6. Pokud budete chtít v budoucnu znovu otevřít tento projekt, přejděte na Soubor > Otevřít > Projekt a vyberte příslušný soubor .sln.

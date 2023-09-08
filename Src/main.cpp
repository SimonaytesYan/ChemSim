#include <SFML/Graphics.hpp>

#include "CoordSystem/CoordSystem.h"
#include "SubWindow/SubWindow.h"
#include "Vector/Vector.h"

const char kWindowHeader[] = "Windows";

int main()
{
    sf::RenderWindow window(sf::VideoMode(), 
                            kWindowHeader, sf::Style::Fullscreen);

	SubWindow window1(0, 					    0, 
					  window.getSize().x / 2.5, window.getSize().x / 2.5);
	SubWindow window2(window.getSize().x / 2,   window.getSize().y / 3, 
					  window.getSize().x / 2, window.getSize().x / 2);
    
	CoordSystem coord_sys1(window1.getSize().x / 2, window1.getSize().y / 2, 100, 100);
	CoordSystem coord_sys2(window2.getSize().x / 2, window2.getSize().y / 2, 75, 75);

	Vector a(1, 1, sf::Color(255, 0, 0));
	Vector b(-2.5, 1.5, sf::Color(0, 255, 0));
	Vector c(1, 1, sf::Color(0, 0, 255));

	Vector vectors1[] = 
	{
		a,
		a * 2,
		!a,			//normalized
		+a,			//normal
		c,
	};

	Vector vectors2[] = 
	{
		a,
		b,
		a + b,
		-(a + b),	//minus
		a - b,
	};

    printf("(a, b) = %lg\n", (a, b));

	Vector mouse_vector(0, 0);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
				{
					window.close();
				}

				case sf::Event::MouseButtonPressed:
				{
					if (window1.InSubWindow_p(event.mouseButton.x, event.mouseButton.y))
					mouse_vector = Vector(coord_sys1.CoordReverseRecalcX(event.mouseButton.x),
											  coord_sys1.CoordReverseRecalcY(event.mouseButton.y),
											  sf::Color::Magenta);
				}
			}
		}

        window1.clear();
        
        coord_sys1.CoordSystemDraw(&window1);
		coord_sys2.CoordSystemDraw(&window2);

		vectors1[4].RotateVector(0.01);

		for (int i = 0; i < 5; i++)
			vectors1[i].DrawVector(&window1, &coord_sys1, 0, 0);

		for (int i = 0; i < 5; i++)
			vectors2[i].DrawVector(&window2, &coord_sys2, 0, 0);

		mouse_vector.DrawVector(&window1, &coord_sys1, 0, 0);

		window1.Draw(&window);
		window2.Draw(&window);

		window.display();
    }
}

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
					  window.getSize().x / 4, window.getSize().x / 4);
	SubWindow window2(window.getSize().x / 3,   0, 
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

	Vector mouse_vector1(0, 0);
	Vector mouse_vector2(0, 0);

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
					double mouse_x = event.mouseButton.x;
					double mouse_y = event.mouseButton.y;

					if (window1.Inside_p(mouse_x, mouse_y))
						mouse_vector1 = Vector(coord_sys1.CoordReverseRecalcX(mouse_x - window1.GetX0()),
											   coord_sys1.CoordReverseRecalcY(mouse_y - window1.GetY0()),
											   sf::Color::Magenta);
					
					if (window2.Inside_p(mouse_x, mouse_y))
						mouse_vector2 = Vector(coord_sys2.CoordReverseRecalcX(mouse_x - window2.GetX0()),
											   coord_sys2.CoordReverseRecalcY(mouse_y - window2.GetY0()),
											   sf::Color::Magenta);
						
				}
			}
		}
        
        coord_sys1.CoordSystemDraw(&window1);
		coord_sys2.CoordSystemDraw(&window2);

		vectors1[4] = vectors1[4] ^ 0.01;

		for (int i = 0; i < 5; i++)
			vectors1[i].Draw(&window1, &coord_sys1, 0, 0);

		for (int i = 0; i < 5; i++)
			vectors2[i].Draw(&window2, &coord_sys2, 0, 0);

		mouse_vector1.Draw(&window1, &coord_sys1, 0, 0);
		mouse_vector2.Draw(&window2, &coord_sys2, 0, 0);

		window1.Draw(&window);
		window2.Draw(&window);

		window.display();
    }
}

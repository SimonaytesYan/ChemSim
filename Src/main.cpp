#include <SFML/Graphics.hpp>

#include "CoordSystem/CoordSystem.h"
#include "Vector/Vector.h"

const char kWindowHeader[] = "Window";

int main()
{
    sf::RenderWindow window(sf::VideoMode(), 
                            kWindowHeader, sf::Style::Fullscreen);
    
	int windowWeight = window.getSize().x;
	int windowHeight = window.getSize().y;
    
	CoordSystem coord_sys(window.getSize().x / 2, window.getSize().y / 2, 100, 100);

	Vector a(1, 1, sf::Color(255, 0, 0));
	Vector b(-2.5, 1.5, sf::Color(0, 255, 0));
	Vector c(1, 1, sf::Color(0, 0, 255));

	Vector vectors[] = 
	{
		a + b,
		-(a + b),	//minus
		a - b,
		a * 2,
		b / 2,
		!a,			//normalized
		+a,			//normal
	};

    printf("(a, b) = %lg\n", (a, b));

	Vector* mouse_vector = nullptr;

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
					if (mouse_vector != nullptr)
						delete mouse_vector;

					mouse_vector = new Vector(coord_sys.CoordReverseRecalcX(event.mouseButton.x),
											  coord_sys.CoordReverseRecalcY(event.mouseButton.y),
											  sf::Color::Magenta);
				}
			}
		}

        window.clear();
        
        coord_sys.CoordSystemDraw(&window);

        a.DrawVector(&window, &coord_sys, 0, 0);
        b.DrawVector(&window, &coord_sys, 0, 0);
        
        c.RotateVector(0.01);
        c.DrawVector(&window, &coord_sys, -1, -1);

		vectors[0].DrawVector(&window, &coord_sys, 0, 0);
		vectors[1].DrawVector(&window, &coord_sys, 0, 0);
		vectors[2].DrawVector(&window, &coord_sys, 0, 0);
		vectors[3].DrawVector(&window, &coord_sys, 0, 0);
		vectors[4].DrawVector(&window, &coord_sys, 0, 0);
		vectors[5].DrawVector(&window, &coord_sys, 0, 0);
		vectors[6].DrawVector(&window, &coord_sys, a.GetX(), a.GetY());

		if (mouse_vector != nullptr)
			mouse_vector->DrawVector(&window, &coord_sys, 0, 0);

        window.display();
    }
}

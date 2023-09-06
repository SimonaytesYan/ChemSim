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

    Vector a(1, 1, sf::Color(255, 0, 0));
    Vector a_(a);
    Vector b(-2.5, 1.5, sf::Color(0, 255, 0));
    Vector c = SumVector(a, b);

    Vector d(1, 1, sf::Color(255, 255, 255));

    CoordSystem coord_sys(window.getSize().x/2, window.getSize().y/2, 200, 200);

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
            }
        }

        window.clear();
        
        coord_sys.CoordSystemDraw(&window);

        a.DrawVector(&window, &coord_sys, 0, 0);
        b.DrawVector(&window, &coord_sys, 0, 0);
        c.DrawVector(&window, &coord_sys, 0, 0);

        d.RotateVector(0.01);

        d.DrawVector(&window, &coord_sys, 1, -1);


        window.display();
    }
} 
#include "SubWindow.h"

void SubWindow::Draw(sf::RenderWindow* window)      //Clear SubWindow
{
    int weight = 10;

    sf::RectangleShape frame(sf::Vector2f(this->getSize().x - 2 * weight, 
                                          this->getSize().y - 2 * weight));
    frame.setPosition(weight, weight);
    
    frame.setFillColor(sf::Color::Transparent);
    
    frame.setOutlineThickness(weight);
    frame.setOutlineColor(sf::Color(255, 255, 255));

    this->draw(frame);

    this->display();

    sf::Sprite sprite(this->getTexture());
	sprite.setPosition(this->x0, this->y0);
    
	window->draw(sprite);
    
    this->clear();
}


bool SubWindow::Inside_p(double x, double y)
{
    return (this->x0 < x && x < this->x0 + this->getSize().x &&
            this->y0 < y && y < this->y0 + this->getSize().y);
}

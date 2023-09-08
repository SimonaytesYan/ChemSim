#include "SubWindow.h"

void SubWindow::Draw(sf::RenderWindow* window)      //Clear SubWindow
{
    int weight = 10;

    sf::RectangleShape left  (sf::Vector2f(weight, this->getSize().y));
    sf::RectangleShape right (sf::Vector2f(weight, this->getSize().y)); //this->getSize().x  - weight 
    sf::RectangleShape top   (sf::Vector2f(this->getSize().x, weight));
    sf::RectangleShape bottom(sf::Vector2f(this->getSize().x, weight));

    left.setPosition  (sf::Vector2f(0, 0));
    right.setPosition (sf::Vector2f(this->getSize().x  - weight, 0));
    top.setPosition   (sf::Vector2f(0, 0));
    bottom.setPosition(sf::Vector2f(0, this->getSize().y - weight));

    this->draw(left);
    this->draw(right);
    this->draw(top);
    this->draw(bottom);

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

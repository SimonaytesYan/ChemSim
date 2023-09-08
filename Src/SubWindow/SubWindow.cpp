#include "SubWindow.h"

void SubWindow::Draw(sf::RenderWindow* window)
{
    this->display();

    sf::Sprite sprite(this->getTexture());
	sprite.setPosition(this->x0, this->y0);
    
	window->draw(sprite);
}


bool SubWindow::InSubWindow_p(double x, double y)
{
    return (this->x0 < x && x < this->x0 + this->getSize().x &&
            this->y0 < y && y < this->y0 + this->getSize().y);
}

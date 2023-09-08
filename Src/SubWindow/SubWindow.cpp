#include "SubWindow.h"

void SubWindow::Draw(sf::RenderWindow* window)
{
    this->display();

    sf::Sprite sprite(this->getTexture());
	sprite.setPosition(this->x0, this->y0);
    
	window->draw(sprite);
}
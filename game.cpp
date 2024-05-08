#include"game.hpp"

game :: game(int width, int height)
{
    window.create(VideoMode(width, height), "background", Style::Close);
    if(!background.loadFromFile("pictures/167822.png"))
    {
        return ;
    }
}

void game :: render()
{
    sprite.setTexture(background);
    while (window.isOpen())
        {
                Event e;
                while (window.pollEvent(e))
                {
                    if (e.type == Event::Closed)
                            window.close();
                }
                window.clear();
                window.draw(sprite);
                window.display();
        }
} 

void game :: run()
{
    update();
    render();
}





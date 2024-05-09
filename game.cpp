#include"game.hpp"

Game :: Game(int width, int height)
{
    window.create(VideoMode(width, height), "background", Style::Close);
    peaShooter = new PS(1,2);
    if(!background.loadFromFile("pictures/167822.png"))
    {
        return ;
    }
    sprite.setTexture(background);
    window.setFramerateLimit(144);
}

Game :: ~Game(){delete peaShooter;}

void Game :: render()
{
    window.clear();
    window.draw(sprite);
    peaShooter->render(window);
    window.display();  
} 

void Game :: update()
{
    peaShooter -> update(mousePose);
}

void Game :: handleEvents()
{
    mousePose = Vector2f(Mouse::getPosition(window));
    if (event.type == Event :: MouseButtonPressed)
    { 
        if (event.mouseButton.button == Mouse::Right || event.mouseButton.button == Mouse::Left)
        {
            peaShooter->isDragging = true ;
        } 
        if (!peaShooter->sprite.getGlobalBounds().contains(mousePose))
        {
            peaShooter->isDragging = false;
        }
    }
    if(event.type == Event :: MouseButtonReleased)
    {
        peaShooter->isDragging = false;
    }
}


void Game :: run()
{
    while (window.isOpen())
    {
        while (window.pollEvent(event))
            {
                handleEvents();
                if (event.type == Event::Closed)
                window.close();    
            }
    update();       
    render();
    }
}





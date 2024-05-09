#include"game.hpp"

Game :: Game(int width, int height)
{
    window.create(VideoMode(width, height), "background", Style::Close);
    if(!background.loadFromFile("pictures/167822.png"))
    {
        return ;
    }
    sprite.setTexture(background);
    window.setFramerateLimit(144);
    peaShooter.push_back(new PS(1,2));
}

Game :: ~Game(){delete peaShooter[0];}

void Game :: render()
{
    window.clear();
    window.draw(sprite);
    peaShooter[0]->render(window);
    window.display();  
} 

void Game :: update()
{
    peaShooter[0] -> update(mousePose);
}

void Game :: handleEvents()
{
    mousePose = Vector2f(Mouse::getPosition(window));
    if (event.type == Event :: MouseButtonPressed)
    { 
        if (event.mouseButton.button == Mouse::Right || event.mouseButton.button == Mouse::Left)
        {
            peaShooter[0]->isDragging = true ;
        } 
        if (!peaShooter[0]->sprite.getGlobalBounds().contains(mousePose))
        {
            peaShooter[0]->isDragging = false;
        }
    }
    if(event.type == Event :: MouseButtonReleased)
    {
        peaShooter[0]->isDragging = false;
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





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

}

void Game :: handleMousePress(Event event)
{

}

void Game :: handleMouseRelease(Event event)
{

}

void Game :: handleEvents()
{
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case Event::MouseButtonPressed:
            handleMousePress(event);
            break;
        
        case Event::MouseButtonReleased:
            handleMouseRelease(event);
            break;
        default :
        break;    
        }
    }
    
}

void Game :: run()
{
    while (window.isOpen())
    {
        while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                window.close();
            }
        render();
    }
    // update(); 
    // handleEvents();
}





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

void Game :: checkMousePress()
{
    mousePose = Vector2f(Mouse::getPosition(window));
    if (event.mouseButton.button == Mouse::Right)
    {
        return;
    }
    if (peaShooter->sprite.getGlobalBounds().contains(mousePose))
    {
        isDraggimg = true;
    }
    
    
}

void Game :: update()
{

}

void Game :: handleMousePress()
{
    peaShooter->handleMousePress(mousePose);
}

void Game :: handleMouseRelease()
{
    isDraggimg = false;
}

void Game :: handleEvents()
{
    
    if (isDraggimg)
    {
        handleMousePress();
    }
    else 
    {
        handleMouseRelease();
    }
}
    


void Game :: run()
{
    while (window.isOpen())
    {
        checkMousePress();
        handleEvents();
        while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                window.close();
            }
        render();
    }
    // update(); 

}





#include"game.hpp"

Game :: Game(int width, int height)
{
    window.create(VideoMode(width, height), "plantvszombie", Style::Close);
    if(!background.loadFromFile("spriters/front yard/Frontyard.png"))
    {
        return ;
    }
    sprite.setTexture(background);
    window.setFramerateLimit(144);
    peaShooter.push_back(new PS(1,2));
    handler = new Handler;
}

Game :: ~Game(){delete peaShooter[0];}

void Game :: render()
{
    window.clear();
    window.draw(sprite);
    handler->render(window);
    peaShooter[0]->render(window);
    window.display();  
} 
void Game :: poseSavor()
{
    for (int i = 0; i < peaShooter.size(); i++)
    {
        pose.push_back(Vector2f(peaShooter[i]->sprite.getPosition()));
    }
} 

void Game :: update()
{
    peaShooter[0] -> update(mousePose);
    handler->update(pose);
    handler->deleteds(sprite.getGlobalBounds());
}

void Game :: handleEvents()
{
    mousePose = Vector2f(Mouse::getPosition(window));
    if (event.type == Event :: MouseButtonPressed)
    { 
        if ((event.mouseButton.button == Mouse::Right || event.mouseButton.button == Mouse::Left )
        && peaShooter[0]->sprite.getGlobalBounds().contains(mousePose))
        {
            peaShooter[0]->isDragging = true;
            if(pose.size() !=0)
                pose.pop_back();
        } 
    }
    if(event.type == Event :: MouseButtonReleased)
    {
        peaShooter[0]->isDragging = false; 
        if(peaShooter[0]->sprite.getGlobalBounds().contains(mousePose))
        poseSavor();
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





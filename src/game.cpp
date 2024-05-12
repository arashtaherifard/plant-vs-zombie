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
    player = new Player;
    if(!music.openFromFile("music.mp3"))
    {
        return;
    }
    music.setLoop(true);
    music.play();
    blocksPose();
}

void Game :: blocksPose()
{
    blockCenters.resize(45);
    isGenerated.resize(45);
    for (int i = 0; i < 45; i++)
    {
        isGenerated[i] = false;
    }
    blockCenters[0].x = 294;
    blockCenters[0].y = 127;
    int count = 0;
    while (count < 5)
    {
        for (int i = 0; i < 9; i++)
        {
            if (i == 0)
            {
                blockCenters[i].x = 294;
            }
            else
            {
                blockCenters[i].x = blockCenters[i-1].x + 80;
                blockCenters[i].y = blockCenters[i-1].y;
            }
        } 
        count++;
        if(count < 5)
        {
        blockCenters[count * 9].x = 294;
        blockCenters[count * 9].y = blockCenters[count * 9 - 1].y + 100;
        }
    }
    
}

void Game :: PvsZ(vector<FloatRect> zombiesRect)
{
    for(int i = 0; i< zombiesRect.size(); i++)
    {
        if (peaShooter[0]->getRect().intersects(zombiesRect[i]))
        {
            Time time = clock.getElapsedTime();
            if(time.asMilliseconds() >= 1000 && peaShooter[0]->life > 0)
            {   
                peaShooter[0]->life--;
                handler->isCollidedSetter(i, false);           
                clock.restart();    
            }
            
            if (peaShooter[0]-> life == 0)
            {
                peaShooter[0]->life = 5;
                handler->isCollidedSetter(i, true);
            }
        }
    }
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
    handler->deletedOutOfBounds(sprite.getGlobalBounds());
      
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
    else if(event.type == Event :: MouseButtonReleased)
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
        PvsZ(handler->getZombieRect()); 
    }
}





#include"game.hpp"

Game :: Game(int width, int height)
{
    window.create(VideoMode(width, height), "plantvszombie", Style::Close);
    if(!background.loadFromFile("spriters/front yard/Frontyard.png"))
    {
        return ;
    }
    lineFiller();
    for (int i = 0; i < 5; i++)
    {
        blocksPose(i);
    }
    sprite.setTexture(background);
    window.setFramerateLimit(144);
    handler = new Handler;
    player = new Player;
    sidebar = new Sidebar;
    // for (int i = 0; i < 45; i++)
    // {
    //     player->generateSnowShooters(blockCenters[i], i);
    // }
    
    peaShooter.push_back(new PS(blockCenters[0].x,blockCenters[0].y));
    if(!music.openFromFile("music.mp3"))
    {
        return;
    }

    music.setLoop(true);
    music.play();
}

void Game :: lineFiller()
{
    blockCenters.resize(45);
    for (int i = 0; i < 45; i++)
    {
        isGenerated.push_back(false);
    }
    blockCenters[0].x = 300;
    blockCenters[0].y = 160;
    blockCenters[9].x = 300;
    blockCenters[9].y = 255;
    blockCenters[18].x = 300;
    blockCenters[18].y = 360;
    blockCenters[27].x = 300;
    blockCenters[27].y = 460;
    blockCenters[36].x = 300;
    blockCenters[36].y = 560;
}

void Game :: blocksPose(int count)
{
    
    for (int i = count * 9; i < (count +1) * 9; i++)
    {
        if (i != count * 9)
        {
            blockCenters[i].x =  blockCenters[i - 1].x + 88;
            blockCenters[i].y =  blockCenters[i - 1].y;
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
    player->render(window);
    peaShooter[0]->render(window);
    sidebar->render(window);
    window.display();  
} 

void Game :: poseSavor()
{
    for (int i = 0; i < 45; i++)
    {
        if (isGenerated[i])
        {
            pose.push_back(blockCenters[i]);
        }
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





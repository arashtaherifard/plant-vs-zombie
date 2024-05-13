#include"game.hpp"

Game :: Game(int width, int height)
{
    window.create(VideoMode(width, height), "plantvszombie", Style::Close);
    if(!background.loadFromFile("spriters/front yard/Frontyard.png"))
    {
        return ;
    }
    for (int i = 0; i < 45; i++)
    {
        count.push_back(0);
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
    blockCenters[0].x = 295;
    blockCenters[0].y = 140;
    blockCenters[9].x = 295;
    blockCenters[9].y = 235;
    blockCenters[18].x = 295;
    blockCenters[18].y = 330;
    blockCenters[27].x = 295;
    blockCenters[27].y = 435;
    blockCenters[36].x = 295;
    blockCenters[36].y = 520;
}

void Game :: blocksPose(int count)
{
    
    for (int i = count * 9; i < (count +1) * 9; i++)
    {
        if (i != count * 9)
        {
            blockCenters[i].x =  blockCenters[i - 1].x + 82;
            blockCenters[i].y =  blockCenters[i - 1].y;
        }
    }
}

// void Game :: PvsZ()
// {
    
//         for(int i = 0; i< handler->getZombiesCount(); i++)
//         {
//             for(int j = 0; j< player->getPeaShootersCount(); j++)
//             {
//                 if (player->getPeaShooterRect(j).intersects(handler->getZobieRect(i)))
//                 {
//                     Time time = clock.getElapsedTime();
//                     if(time.asMilliseconds() >= 1000 && > 0)
//                     {   
//                         peaShooter[i]->life--;
//                         handler->isCollidedSetter(i, false);           
//                         clock.restart();    
//                     }
                    
//                     if (peaShooter[i]-> life == 0)
//                     {
//                         peaShooter[i]->life = 5;
//                         handler->isCollidedSetter(i, true);
//                     }
//                 } 
//             }
//         }
// }

Game :: ~Game(){}

void Game :: render()
{
    window.clear();
    window.draw(sprite);
    handler->render(window);
    player->render(window);
    sidebar->render(event, window);
    window.display();  
} 

void Game :: snowShooterPoseSavor(Vector2f blockCenter)
{
    snowShooterPose.push_back(blockCenter);
} 

void Game :: peaShooterPoseSavor(Vector2f blockCenter)
{
    peaShooterPose.push_back(blockCenter);
} 

void Game :: update()
{
    handler->generateRandomSuns();
    handler->update(peaShooterPose, snowShooterPose);
    handler->deletedOutOfBounds(sprite.getGlobalBounds());
    sidebar->update(event, window, blockCenters, isGenerated);
}

void Game :: handleEvents()
{
    objectType = sidebar->checkDrag(event, window, blockCenters, isGenerated);
}

void Game :: generatePlants()
{
    
    if(objectType == 1)
    {
        for (int i = 0; i < 45; i++)
            {
                if (isGenerated[i] && count[i]==0)
                {
                    player->generatePeaShooters(blockCenters[i], i);
                    count[i] = 1;
                    peaShooterPoseSavor(blockCenters[i]);
                }   
            } 
    }
    if(objectType == 2)
    {
        for (int i = 0; i < 45; i++)
            {
                if (isGenerated[i] && count[i]==0)
                {
                    player->generateSnowShooters(blockCenters[i], i);
                    count[i] = 1;
                    snowShooterPoseSavor(blockCenters[i]);
                }   
            } 
    }
    if(objectType == 3)
    {
        for (int i = 0; i < 45; i++)
            {
                if (isGenerated[i] && count[i]==0)
                {
                    player->generatePotatos(blockCenters[i], i);
                    count[i] = 1;
                }   
            } 
    }
    if(objectType == 4)
    {
        for (int i = 0; i < 45; i++)
            {
                if (isGenerated[i] && count[i]==0)
                {
                    player->generateFlowers(blockCenters[i], i);
                    count[i] = 1;
                }   
            } 
    }
}

void Game :: run()
{
    
    while (window.isOpen())
    {
        
        while (window.pollEvent(event))
        {
            handleEvents();
            generatePlants();
            if (event.type == Event::Closed)
            window.close();   
        }           
        
        // PvsZ(handler->getZombieRect());
        
        update();
        render();
        
    }
}





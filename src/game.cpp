#include"game.hpp"

Game :: Game(int width, int height)
{
    window.create(VideoMode(width, height), "plantvszombie", Style::Close);
    if(!background.loadFromFile("spriters/front yard/Frontyard.png")||!overTexture.loadFromFile("spriters/images/Losing_Message.png"))
    {
        return ;
    }
    lineFiller();
    for (int i = 0; i < 5; i++)
    {
        blocksPose(i);
    }
    over.setTexture(overTexture);
    over.setScale(2.92, 2);
    sprite.setTexture(background);
    window.setFramerateLimit(144);
    handler = new Handler;
    player = new Player;
    sidebar = new Sidebar;
    if(!music.openFromFile("spriters/mokhtarnameh-barkhiz.mp3") || !gameOver.loadFromFile("spriters/over.wav"))
    {
        return;
    }
    music.setLoop(true);
    music.play();
    GameOver.setBuffer(gameOver);
    isOver = false;
    storage = 0;
}

void Game :: peaShooterVsZ()
{
    for(int i = 0; i< handler->getZombiesCount(); i++)
    {
        for(int j = 0; j< player->getPeaShootersCount(); j++)
        {
            if (player->getPeaShooterRect(j).intersects(handler->getZombieRect(i)))
            {
                player->peaShooterCollide(j);
                handler->isCollidedSetter(i, true); 
                collision[i]++;    
            } 
            else
            {
                if(collision[i] == 0)
                    handler->isCollidedSetter(i, false);  
            }
        }
    }
}

void Game :: potatoVsZ()
{
    for(int i = 0; i< handler->getZombiesCount(); i++)
    {
        for(int j = 0; j< player->getPotatoCount(); j++)
        {
            if (player->getPotatoRect(j).intersects(handler->getZombieRect(i)))
            {
                player->potatoCollide(j);
                handler->isCollidedSetter(i, true);  
                collision[i]++;      
            } 
            else
            {
                if(collision[i] == 0)
                    handler->isCollidedSetter(i, false);  
            }
        }
    }
}

void Game :: snowShooterVsZ()
{
    for(int i = 0; i< handler->getZombiesCount(); i++)
    {
        for(int j = 0; j < player->getSnowShootersCount(); j++)
        {
            if (player->getSnowShooterRect(j).intersects(handler->getZombieRect(i)))
            {
                player->snowShooterCollide(j);
                handler->isCollidedSetter(i, true); 
                collision[i]++;       
            } 
            else
            {
                if(collision[i] == 0)
                    handler->isCollidedSetter(i, false);  
            }
        }
    }
}

void Game :: sunFlowerVsZ()
{
    for(int i = 0; i< handler->getZombiesCount(); i++)
    {
        for(int j = 0; j< player->getSunFlowerCount(); j++)
        {
            if (player->getSunFlowerRect(j).intersects(handler->getZombieRect(i)))
            {
                player->sunFlowerCollide(j);
                handler->isCollidedSetter(i, true);     
                collision[i]++;   
            } 
            else
            {
                if(collision[i] == 0)
                    handler->isCollidedSetter(i, false);  
            }
        }
    }
}

void Game :: peaShooterVsG()
{
    for(int i = 0; i< handler->getGiantsCount(); i++)
    {
        for(int j = 0; j< player->getPeaShootersCount(); j++)
        {
            if (player->getPeaShooterRect(j).intersects(handler->getGiantRect(i)))
            {
                player->peaShooterCollide(j);
                handler->giantCollidedSetter(i, true); 
                collision[i]++;    
            } 
            else
            {
                if(collision[i] == 0)
                    handler->giantCollidedSetter(i, false);  
            }
        }
    }
}

void Game :: potatoVsG()
{
    for(int i = 0; i< handler->getGiantsCount(); i++)
    {
        for(int j = 0; j< player->getPotatoCount(); j++)
        {
            if (player->getPotatoRect(j).intersects(handler->getGiantRect(i)))
            {
                player->potatoCollide(j);
                handler->giantCollidedSetter(i, true);  
                collision[i]++;      
            } 
            else
            {
                if(collision[i] == 0)
                    handler->giantCollidedSetter(i, false);  
            }
        }
    }
}

void Game :: snowShooterVsG()
{
    for(int i = 0; i< handler->getGiantsCount(); i++)
    {
        for(int j = 0; j < player->getSnowShootersCount(); j++)
        {
            if (player->getSnowShooterRect(j).intersects(handler->getGiantRect(i)))
            {
                player->snowShooterCollide(j);
                handler->giantCollidedSetter(i, true); 
                collision[i]++;       
            } 
            else
            {
                if(collision[i] == 0)
                    handler->giantCollidedSetter(i, false);  
            }
        }
    }
}

void Game :: sunFlowerVsG()
{
    for(int i = 0; i< handler->getGiantsCount(); i++)
    {
        for(int j = 0; j< player->getSunFlowerCount(); j++)
        {
            if (player->getSunFlowerRect(j).intersects(handler->getGiantRect(i)))
            {
                player->sunFlowerCollide(j);
                handler->giantCollidedSetter(i, true);     
                collision[i]++;   
            } 
            else
            {
                if(collision[i] == 0)
                    handler->giantCollidedSetter(i, false);  
            }
        }
    }
}

void Game :: lineFiller()
{
    blockCenters.resize(45);
    for (int i = 0; i < 45; i++)
    {
        isGenerated.push_back(false);
    }
    for (int i = 0; i < 45; i++)
    {
        check.push_back(false);
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

void Game :: PvsG()
{
    
    for (int i = 0; i < handler->getGiantsCount(); i++)
    {
        collision.push_back(0);
    }
    
    peaShooterVsG();

    snowShooterVsG();

    potatoVsG();

    sunFlowerVsG();
    
    if (player->getPeaShootersCount() == 0 && player->getSnowShootersCount() == 0 && player->getPotatoCount() == 0 && player->getSunFlowerCount() == 0)
    {
        for (int i = 0; i < handler->getGiantsCount(); i++)
        {
            handler->giantCollidedSetter(i, false);
        }
    }
    collision.clear();
    
}

void Game :: PvsZ()
{
    
    for (int i = 0; i < handler->getZombiesCount(); i++)
    {
        collision.push_back(0);
    }
    
    peaShooterVsZ();

    snowShooterVsZ();

    potatoVsZ();

    sunFlowerVsZ();

    if (player->getPeaShootersCount() == 0 && player->getSnowShootersCount() == 0 && player->getPotatoCount() == 0 && player->getSunFlowerCount() == 0)
    {
        for (int i = 0; i < handler->getZombiesCount(); i++)
        {
            handler->isCollidedSetter(i, false);
        }
    }
    collision.clear();
    
}

Game :: ~Game(){}

void Game :: render()
{
    window.clear();
    window.draw(sprite);
    handler->render(window);
    sidebar->render(event, window);
    player->render(window);
    handler->gameOver(isOver, sprite.getGlobalBounds());
    // if(isOver)
    // {
    //     music.pause();
    //     GameOver.setLoop(true);
    //     GameOver.play();
    //     window.draw(over);
    // }
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
    storage = 0;
    player->sun(window, storage);
    sidebar->sunSetter(storage);
    storage = sidebar->sunGetter();
    handler->generateRandomSuns();
    handler->update(peaShooterPose, snowShooterPose);
    handler->deletedOutOfBounds(sprite.getGlobalBounds());
    sunHandler();
    sidebar->update(event, window, blockCenters, isGenerated);
    player->deleter(isGenerated, peaShooterPose, check, snowShooterPose);
}

void Game :: handleEvents()
{
    storage = sidebar->sunGetter();
    objectType = sidebar->checkDrag(event, window, blockCenters, isGenerated, storage);
}

void Game :: peaShooterGenerator()
{
    for (int i = 0; i < 45; i++)
    {
        if (isGenerated[i] && !check[i])
        {
            player->generatePeaShooters(blockCenters[i], i);
            sidebar->sunSetter(-100);
            storage = sidebar->sunGetter();
            peaShooterPoseSavor(blockCenters[i]);
            check[i] = true;
            isGenerated[i] = false;
        }   
    } 
}
void Game :: potatoGenerator()
{
    for (int i = 0; i < 45; i++)
    {
        if (isGenerated[i] && !check[i])
        {
            sidebar->sunSetter(-50);
            storage = sidebar->sunGetter();
            player->generatePotatos(blockCenters[i], i);
            check[i] = true;
            isGenerated[i] = false;
        }   
    } 
}
void Game :: snowShooterGenerator()
{
    for (int i = 0; i < 45; i++)
    {
        if (isGenerated[i] && !check[i])
        {
            player->generateSnowShooters(blockCenters[i], i);
            sidebar->sunSetter(-150);
            storage = sidebar->sunGetter();
            snowShooterPoseSavor(blockCenters[i]);
            check[i] = true;
            isGenerated[i] = false;
        }   
    } 
}
void Game :: sunFlowerGenerator()
{
    for (int i = 0; i < 45; i++)
    {
        if (isGenerated[i] &&! check[i])
        {
            sidebar->sunSetter(-50);
            storage = sidebar->sunGetter();
            player->generateFlowers(blockCenters[i], i);
            check[i] = true;
            isGenerated[i] = false;
        }   
    } 
}

void Game :: generatePlants()
{
    if(objectType == 1)
    {
        peaShooterGenerator();
    }

    if(objectType == 2)
    {
        snowShooterGenerator();
    }

    if(objectType == 3)
    {
        potatoGenerator();
    }

    if(objectType == 4)
    {
        sunFlowerGenerator();
    }
}

void Game :: sunHandler()
{
    handler->sunCollector(window);
    sidebar->sunSetter(handler->sun);
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
        PvsZ();
        PvsG();
        update();
        render();
        
    }
}





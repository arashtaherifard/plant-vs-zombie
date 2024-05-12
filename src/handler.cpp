#include"handler.hpp"
void Handler :: render(RenderWindow  &window)
{
    deleteZombies();
    for (int i = 0; i < projectiles.size(); i++)
    {
        projectiles[i]->render(window);
    }

    for (int i = 0; i < zombies.size(); i++)
    {
        zombies[i]->render(window);
    }

    for (int i = 0; i < snows.size(); i++)
    {
        snows[i]->render(window);
    }
    
}

void Handler :: collision()
{
    vector <Projectile *> trashPProjectiles;
    vector <Snow *> trashPSnows;
    for (int i = 0; i < projectiles.size(); i++)
    {
        for (int j = 0; j < zombies.size(); j++)
        {
            if (projectiles[i]->getRect().intersects(zombies[j]->getRect()))
            {
                if(zombies[j]->life > 0)
                    zombies[j]->life--;
                trashPProjectiles.push_back(projectiles[i]);
            }
        }
    }
    for (int i = 0; i < snows.size(); i++)
    {
        for (int j = 0; j < zombies.size(); j++)
        {
            if (snows[i]->getRect().intersects(zombies[j]->getRect()))
            {
                if(zombies[j]->life > 0)
                    zombies[j]->life--;
                trashPSnows.push_back(snows[i]);
            }
        }
    }
    for (int i = 0; i < trashPProjectiles.size(); i++)
    {
        projectiles.erase(remove(projectiles.begin(), projectiles.end(), trashPProjectiles[i]), projectiles.end());
        delete trashPProjectiles[i];
    }
    for (int i = 0; i < trashPSnows.size(); i++)
    {
        snows.erase(remove(snows.begin(), snows.end(), trashPSnows[i]), snows.end());
        delete trashPSnows[i];
    }
}

void Handler ::  deleteZombies()
{
    vector <Zombie *> trashZombies;
    for (int i = 0; i < zombies.size(); i++)
    {
        if (zombies[i]->life == 0)
        {
            trashZombies.push_back(zombies[i]);
        }
    }
    for (int i = 0; i < trashZombies.size(); i++)
    {
        zombies.erase(remove(zombies.begin(), zombies.end(), trashZombies[i]), zombies.end());
        delete trashZombies[i];
    }
}

void Handler :: addProjectiles(vector<Vector2f> pose)
{
    for (int i = 0; i < pose.size(); i++)
    {
        projectiles.push_back(new Projectile(pose[i]));
    }
}

void Handler:: addSnows(vector<Vector2f> pose)
{
    for (int i = 0; i < pose.size(); i++)
    {
        snows.push_back(new Snow(pose[i]));
    }
}

void Handler :: deletedOutOfBounds(FloatRect windowBounds)
{
    vector<Projectile *> trashP;
    for (int i = 0; i < projectiles.size(); i++)
    {
        if (!windowBounds.intersects(projectiles[i]->getRect()))
        {
            trashP.push_back(projectiles[i]);
        }
    }
    for (int i = 0; i < trashP.size(); i++)
    {
        projectiles.erase(remove(projectiles.begin(), projectiles.end(), trashP[i]), projectiles.end());
        delete trashP[i];
    }
    vector<Snow *> trashS;
    for (int i = 0; i < snows.size(); i++)
    {
        if (!windowBounds.intersects(snows[i]->getRect()))
        {
            trashS.push_back(snows[i]);
        }
    }
    for (int i = 0; i < trashS.size(); i++)
    {
        snows.erase(remove(snows.begin(), snows.end(), trashS[i]), snows.end());
        delete trashS[i];
    }
}

void Handler :: addZombies()
{
    zombies.push_back(new Zombie());
}

void Handler :: update(vector<Vector2f> pose)
{
    Time Ptime = Pclock.getElapsedTime();
    if(Ptime.asMilliseconds() >= 300)
    {
        Pclock.restart();
        addProjectiles(pose);
    }

    Time Ztime = Zclock.getElapsedTime();
    if(Ztime.asMilliseconds() >= 2000)
    {
        Zclock.restart();
        addZombies();
    }
    
    Time Stime = Sclock.getElapsedTime();
    if(Stime.asMilliseconds() >= 300)
    {
        Sclock.restart();
        addSnows(pose);
    }

    for (int i = 0; i < projectiles.size(); i++)
    {
        projectiles[i]->update();
    }

    for (int i = 0; i < zombies.size(); i++)
    {
        zombies[i]->update();
    }

    for (int i = 0; i < snows.size(); i++)
    {
        snows[i]->update();
    }
    collision();
    
}
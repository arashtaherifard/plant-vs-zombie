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

    for (int i = 0; i < randomSuns.size(); i++)
    {
        randomSuns[i]->render(window);
    }
}

void Handler :: generateRandomSuns()
{
    Time time = clock.getElapsedTime();
    if (time.asMilliseconds() >= 7000)
    {
        clock.restart();
        randomSuns.push_back(new RandomSun());
    }
}

void Handler :: collision()
{
    vector <Projectile *> trashProjectiles;
    vector <Snow *> trashPSnows;
    for (int i = 0; i < projectiles.size(); i++)
    {
        for (int j = 0; j < zombies.size(); j++)
        {
            if (projectiles[i]->getRect().intersects(zombies[j]->getRect()))
            {
                if(zombies[j]->life > 0)
                    zombies[j]->life--;
                trashProjectiles.push_back(projectiles[i]);
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
    for (int i = 0; i < trashProjectiles.size(); i++)
    {
        projectiles.erase(remove(projectiles.begin(), projectiles.end(), trashProjectiles[i]), projectiles.end());
        delete trashProjectiles[i];
    }
    for (int i = 0; i < trashPSnows.size(); i++)
    {
        snows.erase(remove(snows.begin(), snows.end(), trashPSnows[i]), snows.end());
        delete trashPSnows[i];
    }
}

FloatRect Handler :: getZobieRect(int count)
{
    return zombies[count]->getRect();
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
    vector<Zombie*> trashZ;
    for (int i = 0; i < zombies.size(); i++)
    {
        if (!windowBounds.intersects(zombies[i]->getRect()))
        {
            trashZ.push_back(zombies[i]);
        }
    }
    for (int i = 0; i < trashZ.size(); i++)
    {
        zombies.erase(remove(zombies.begin(), zombies.end(), trashZ[i]), zombies.end());
        delete trashZ[i];
    }
    vector<RandomSun*> trashSuns;
    for (int i = 0; i < randomSuns.size(); i++)
    {
        if (!windowBounds.intersects(randomSuns[i]-> getRect()))
        {
            trashSuns.push_back(randomSuns[i]);
        }
    }
    for (int i = 0; i < trashZ.size(); i++)
    {
        randomSuns.erase(remove(randomSuns.begin(), randomSuns.end(), trashSuns[i]), randomSuns.end());
        delete trashSuns[i];
    }
}

void Handler :: addZombies()
{
    zombies.push_back(new Zombie());
}

void Handler :: snowGenerator(vector<Vector2f> pose)
{
    Time Stime = Sclock.getElapsedTime();
    if(Stime.asMilliseconds() >= 500)
    {
        Sclock.restart();
        addSnows(pose);
    }
    for (int i = 0; i < snows.size(); i++)
    {
        snows[i]->update();
    }
    
}

void Handler :: peaGenerator(vector<Vector2f> pose)
{
    Time Ptime = Pclock.getElapsedTime();
    if(Ptime.asMilliseconds() >= 500)
    {
        Pclock.restart();
        addProjectiles(pose);
    }
    for (int i = 0; i < projectiles.size(); i++)
    {
        projectiles[i]->update();
    }
}

void Handler :: update( vector<Vector2f> peaShooterPose, vector<Vector2f> snowShooterPose)
{
    
    Time Ztime = Zclock.getElapsedTime();
    if(Ztime.asMilliseconds() >= 2000)
    {
        Zclock.restart();
        addZombies();
    }
    for (int i = 0; i < zombies.size(); i++)
    {
        zombies[i]->update();
    }
    for (int i = 0; i < randomSuns.size(); i++)
    {
        randomSuns[i]->update();
    }
    peaGenerator(peaShooterPose);
    snowGenerator(snowShooterPose);
    collision();
    
}
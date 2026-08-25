#include"handler.hpp"
using namespace sf;
void Handler :: render(RenderWindow  &window)
{
    
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
    for (int i = 0; i < giants.size(); i++)
    {
        giants[i]->render(window);
    }
    deleteGiants();
    deleteZombies();
}

void Handler :: gameOver(bool &isOver, FloatRect windowBounds)
{
    for (int i = 0; i < zombies.size(); i++)
    {
        if (!windowBounds.intersects(zombies[i]->getRect()))
        {
            isOver = true;
        }
    }
    for (int i = 0; i < giants.size(); i++)
    {
        if (!windowBounds.intersects(giants[i]->getRect()))
        {
            isOver = true;
        }
    }
}

void Handler :: generateRandomSuns()
{
    Time time = clock.getElapsedTime();
    if (time.asMilliseconds() >= 3000)
    {
        clock.restart();
        randomSuns.push_back(new RandomSun());
    }
}

void Handler :: giantCollision()
{
    vector <Projectile *> trashProjectiles;
    vector <Snow *> trashPSnows;
    for (int i = 0; i < projectiles.size(); i++)
    {
        for (int j = 0; j < giants.size(); j++)
        {
            if (projectiles[i]->getRect().intersects(giants[j]->getRect()))
            {
                if(giants[j]->life > 0)
                    giants[j]->life--;
                trashProjectiles.push_back(projectiles[i]);
                for (int i = 0; i < trashProjectiles.size(); i++)
                {
                    projectiles.erase(remove(projectiles.begin(), projectiles.end(), trashProjectiles[i]), projectiles.end());
                }
                trashProjectiles.clear();
            }
        }
        
    }

    for (int i = 0; i < snows.size(); i++)
    {
        for (int j = 0; j < giants.size(); j++)
        {
            if (snows[i]->getRect().intersects(giants[j]->getRect()))
            {
                if(giants[j]->life > 0)
                {
                    giants[j]->freezeSetter();
                    giants[j]->life--;
                }
                trashPSnows.push_back(snows[i]);
                for (int i = 0; i < trashPSnows.size(); i++)
                {
                    snows.erase(remove(snows.begin(), snows.end(), trashPSnows[i]), snows.end());
                }
                trashPSnows.clear();
            }
        }
    }
}

void Handler :: zombieCollision()
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
                for (int i = 0; i < trashProjectiles.size(); i++)
                {
                    projectiles.erase(remove(projectiles.begin(), projectiles.end(), trashProjectiles[i]), projectiles.end());
                }
                trashProjectiles.clear();
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
                {
                    zombies[j]->freezeSetter();
                    zombies[j]->life--;
                }
                trashPSnows.push_back(snows[i]);
                for (int i = 0; i < trashPSnows.size(); i++)
                {
                    snows.erase(remove(snows.begin(), snows.end(), trashPSnows[i]), snows.end());
                }
                trashPSnows.clear();
            }
        }
        
    }
}

FloatRect Handler :: getZombieRect(int count)
{
    return zombies[count]->getRect();
}

FloatRect Handler :: getGiantRect(int count)
{
    return giants[count]->getRect();
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

void Handler ::  deleteGiants()
{
    vector <Giant *> trashGiant;
    for (int i = 0; i < giants.size(); i++)
    {
        if (giants[i]->life == 0)
        {
            trashGiant.push_back(giants[i]);
        }
    }
    for (int i = 0; i < trashGiant.size(); i++)
    {
        giants.erase(remove(giants.begin(), giants.end(), trashGiant[i]), giants.end());
        delete trashGiant[i];
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
    
    vector<RandomSun*> trashSuns;
    for (int i = 0; i < randomSuns.size(); i++)
    {
        if (!windowBounds.intersects(randomSuns[i]-> getRect()))
        {
            trashSuns.push_back(randomSuns[i]);
        }
    }
    for (int i = 0; i < trashSuns.size(); i++)
    {
        randomSuns.erase(remove(randomSuns.begin(), randomSuns.end(), trashSuns[i]), randomSuns.end());
        delete trashSuns[i];
    }
}

void Handler :: addZombies()
{
    zombies.push_back(new Zombie());
}

void Handler :: addgiants()
{
    giants.push_back(new Giant());
}

void Handler :: snowGenerator(vector<Vector2f> pose)
{
    Time Stime = Sclock.getElapsedTime();
    if(Stime.asMilliseconds() >= 2000)
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
    if(Ptime.asMilliseconds() >= 800)
    {
        Pclock.restart();
        addProjectiles(pose);
    }
    for (int i = 0; i < projectiles.size(); i++)
    {
        projectiles[i]->update();
    }
}

void Handler :: deleteCollectedSuns(vector<RandomSun*> &trashSuns)
{
    for (int i = 0; i < trashSuns.size(); i++)
    {
        randomSuns.erase(remove(randomSuns.begin(), randomSuns.end(), trashSuns[i]), randomSuns.end());
        delete trashSuns[i];
    }
}

void Handler :: sunCollector(RenderWindow &window)
{
    vector<RandomSun*> trashSuns;
    Vector2f mousepose = Vector2f(Mouse :: getPosition(window));
    sun = 0;
    for(int i = 0; i < randomSuns.size();i++)
    {
        if (randomSuns[i]->getRect().contains(mousepose))
        {
            sun = sun + randomSunQuantity;
            trashSuns.push_back(randomSuns[i]);
            deleteCollectedSuns(trashSuns);
        }
    }
}

void Handler :: update( vector<Vector2f> peaShooterPose, vector<Vector2f> snowShooterPose)
{
    Time Ztime = Zclock.getElapsedTime();
    if(Ztime.asMilliseconds() >= 6500)
    {
        Zclock.restart();
        addZombies();
    }

    Time Gtime = Gclock.getElapsedTime();
    if(Gtime.asMilliseconds() >= 11000)
    {
        Gclock.restart();
        addgiants();
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
    zombieCollision();
    giantCollision();
    
}
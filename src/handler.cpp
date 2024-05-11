#include"handler.hpp"

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
}

void Handler :: collision()
{
    
    vector <Projectile *> trashProjectiles;
    for (int i = 0; i < projectiles.size(); i++)
    {
        for (int j = 0; j < zombies.size(); j++)
        {
            if (projectiles[i]->getRect().intersects(zombies[j]->getRect()))
            {
                // trashZombies.push_back(zombies[j]);
                if(zombies[j]->life > 0)
                    zombies[j]->life--;
                trashProjectiles.push_back(projectiles[i]);
            }
        }
    }
    for (int i = 0; i < trashProjectiles.size(); i++)
    {
        projectiles.erase(remove(projectiles.begin(), projectiles.end(), trashProjectiles[i]), projectiles.end());
        delete trashProjectiles[i];
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

void Handler :: deletedOutOfBounds(FloatRect windowBounds)
{
    vector<Projectile *> trash;
    for (int i = 0; i < projectiles.size(); i++)
    {
        if (!windowBounds.intersects(projectiles[i]->getRect()))
        {
            trash.push_back(projectiles[i]);
        }
    }
    for (int i = 0; i < trash.size(); i++)
    {
        projectiles.erase(remove(projectiles.begin(), projectiles.end(), trash[i]), projectiles.end());
        delete trash[i];
    }
}

void Handler :: addZombies()
{
    zombies.push_back(new Zombie());
}

void Handler :: update(vector<Vector2f> pose)
{
    Time Ptime = Pclock.getElapsedTime();
    if(Ptime.asMilliseconds() >= 600)
    {
        Pclock.restart();
        addProjectiles(pose);
    }
    Time Ztime = Zclock.getElapsedTime();
    if(Ztime.asMilliseconds() >= 1200)
    {
        Zclock.restart();
        addZombies();
    }
    for (int i = 0; i < projectiles.size(); i++)
    {
        projectiles[i]->update();
    }
    for (int i = 0; i < zombies.size(); i++)
    {
        zombies[i]->update();
    }
    collision();
    deleteZombies();
}
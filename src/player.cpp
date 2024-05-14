#include "player.hpp"
#include "peaShooter.hpp"
using namespace std;
void Player :: render(RenderWindow &Window)
{
    for (int i = 0; i < potatos.size(); i++)
    {
        potatos[i]->render(Window);
    }
    for (int i = 0; i < snowShooters.size(); i++)
    {
        snowShooters[i]->render(Window);
    }
    for (int i = 0; i < peaShooters.size(); i++)
    {
        peaShooters[i]->render(Window);
    }
    for (int i = 0; i < flowers.size(); i++)
    {
        flowers[i]->render(Window);
    }
    
} 

void Player :: generatePeaShooters(Vector2f blocks, int &count)
{
    peaShooters.push_back(new PS(blocks, count));
}

void Player :: generateSnowShooters(Vector2f blocks, int &count)
{
    snowShooters.push_back(new SS(blocks, count));
}

void Player :: generatePotatos(Vector2f blocks, int &count)
{
    potatos.push_back(new potato(blocks, count));
    
}
void Player :: generateFlowers(Vector2f blocks, int &count)
{
    flowers.push_back(new SunFlower(blocks, count));
}

void Player :: trashFiller(vector<bool> &isGenerated, vector<PS*> &trashPeaShooters, vector<SS*> &trashSnowShooters
, vector<potato*> &trashPotatos, vector<SunFlower*> &trashFlowers, vector<Vector2f> &trashPose, vector<Vector2f> &peaShootrerPose, vector<bool> &check)
{
    for (int i = 0; i < peaShooters.size(); i++)
    {
        if (peaShooters[i]->life == 0)
        {
            isGenerated[peaShooters[i]->block] = false;
            check[peaShooters[i]->block] = false;
            trashPeaShooters.push_back(peaShooters[i]);
            trashPose.push_back(peaShootrerPose[i]);
        }
    }

    for (int i = 0; i < snowShooters.size(); i++)
    {
        if (snowShooters[i]->life == 0)
        {
            trashSnowShooters.push_back(snowShooters[i]);
            check[snowShooters[i]->block] = false;
            isGenerated[snowShooters[i]->block] = false;
        }
    }

    for (int i = 0; i < potatos.size(); i++)
    {
        if (potatos[i]->life == 0)
        {
            trashPotatos.push_back(potatos[i]);
            check[potatos[i]->block] = false;
            isGenerated[potatos[i]->block] = false;
        }
    }
    for (int i = 0; i < flowers.size(); i++)
    {
        if (flowers[i]->life == 0)
        {
            trashFlowers.push_back(flowers[i]);
            check[flowers[i]->block] = false;
            isGenerated[flowers[i]->block] = false;
        }
    }
}

void Player :: peaShooterCollide(int count)
{
    peaShooters[count]->isCollided = true;
    peaShooters[count]->collided();
}
void Player :: snowShooterCollide(int count)
{
    snowShooters[count]->isCollided = true;
    snowShooters[count]->collided();
}

void Player :: potatoCollide(int count)
{
    potatos[count]->isCollided = true;
    potatos[count]->collided();
}

void Player :: sunFlowerCollide(int count)
{
    flowers[count]->isCollided = true;
    flowers[count]->collided();
}

FloatRect Player :: getPeaShooterRect(int count)
{
    return peaShooters[count]->getRect();
}

FloatRect Player :: getSnowShooterRect(int count)
{
    return snowShooters[count]->getRect();
}

FloatRect Player :: getPotatoRect(int count)
{
    return potatos[count]->getRect();
}

FloatRect Player :: getSunFlowerRect(int count)
{
    return flowers[count]->getRect();
}

void Player :: deleter(vector<bool> &isGenerated, vector<Vector2f> &peaShootrerPose, vector<bool> &check)
{
    vector<PS*> trashPeaShooters; 
    vector<SS*> trashSnowShooters; 
    vector<potato*> trashPotatos;
    vector<SunFlower*> trashFlowers;
    vector<Vector2f> trashPose;
    trashFiller(isGenerated, trashPeaShooters, trashSnowShooters, trashPotatos, trashFlowers, trashPose, peaShootrerPose, check);
    for (int i = 0; i < trashPose.size(); i++)
    {
        peaShootrerPose.erase(remove(peaShootrerPose.begin(), peaShootrerPose.end(), trashPose[i]), peaShootrerPose.end());
        trashPose.clear();
    }
    
    for (int i = 0; i < trashPeaShooters.size(); i++)
    {
        peaShooters.erase(remove(peaShooters.begin(), peaShooters.end(), trashPeaShooters[i]), peaShooters.end());
        delete trashPeaShooters[i];
    }

    for (int i = 0; i < trashSnowShooters.size(); i++)
    {
        snowShooters.erase(remove(snowShooters.begin(), snowShooters.end(), trashSnowShooters[i]), snowShooters.end());
        delete trashSnowShooters[i];
    }

    for (int i = 0; i < trashPotatos.size(); i++)
    {
        potatos.erase(remove(potatos.begin(), potatos.end(), trashPotatos[i]), potatos.end());
        delete trashPotatos[i];
    }
    for (int i = 0; i < trashFlowers.size(); i++)
    {
        flowers.erase(remove(flowers.begin(), flowers.end(), trashFlowers[i]), flowers.end());
        delete trashFlowers[i];
    }
}

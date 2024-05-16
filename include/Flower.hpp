#pragma once
#include "global.hpp"
using namespace std;
using namespace sf;

class sideFlower {
public:

    sideFlower(float x, float y);
    void render(Event &event, RenderWindow &window);
    bool contains(Vector2f point);
    int checkDrag(Event &event, RenderWindow &window, vector <Vector2f> blocksPose, vector<bool> &isGenerated, int &storage);
    void dragAndDrop(Event &event, RenderWindow &window);
    void update(Event &event, RenderWindow &window, vector <Vector2f> blocksPose, vector<bool> &isGenerated);
    int changeStatus(vector <Vector2f> &blocksPose, vector<bool> &isGenerated, int &storage);
    int getDistance(Vector2f first, Vector2f second);
    
private:
    bool isDim;
    Sprite dimSprite;
    Texture dimImage;
    Clock dimClock;
    int type;
    bool isDragging;
    Vector2f releasedPose;
    Sprite sprite;
    Sprite fakeSprite;
    Texture fake;
    Texture sideFlowerTexture;
};
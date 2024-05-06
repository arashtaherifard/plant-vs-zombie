#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
using namespace std;
using namespace sf;

int main()
{
        RenderWindow window(VideoMode(1400,599,32), "Test 32");

        Texture texture;
        if(!texture.loadFromFile("167822.png"))
        {
            return EXIT_FAILURE;
        }
        Sprite sprite;
        // Vector2u size = texture.getSize();
        sprite.setTexture(texture);
        // sprite.setOrigin(size.x/9 , size.y/9);

        while (window.isOpen())
        {
                Event e;
                while (window.pollEvent(e))
                {
                        if (e.type == Event::Closed)
                                window.close();
                }
                window.clear();
                window.draw(sprite);
                window.display();
        }
}
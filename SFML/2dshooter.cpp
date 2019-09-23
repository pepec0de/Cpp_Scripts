#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <math.h>
#include <vector>
#include <cstdlib>

using namespace sf;

class Bullet
{
public:
    CircleShape bullet;
    Vector2f currVelocity;
    float maxSpeed;

    Bullet(float radius = 5.f)
        : currVelocity(0.f, 0.f), maxSpeed(15.f)
    {
        this->bullet.setRadius(radius);
        this->bullet.setFillColor(Color::Red);
    }
};
int main()
{
    srand(time(NULL));
    RenderWindow window(VideoMode(800, 600), "360 Shooter!", Style::Default);
    window.setFramerateLimit(60);

    // Player
    CircleShape player(25.f);
    player.setFillColor(Color::White);
    player.setPointCount(3);
    Vector2f playerCenter;
    Vector2f mousePosWindow;
    Vector2f aimDir;
    Vector2f aimDirNorm;

    // Bullets
    Bullet b1;
    std::vector<Bullet> bullets;
    //bullets.push_back(Bullet(b1));

    // Enemy
    RectangleShape enemy;
    enemy.setFillColor(Color::Magenta),
                       enemy.setSize(Vector2f(50.f, 50.f));
    int spawnCounter = 10;
    std::vector<RectangleShape> enemies;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }

        // Update

        // Vectors
        playerCenter = Vector2f(player.getPosition().x + player.getRadius(), player.getPosition().y + player.getRadius() );
        mousePosWindow = Vector2f(Mouse::getPosition(window));
        aimDir = mousePosWindow - playerCenter;
        aimDirNorm = aimDir / ( static_cast<float>(sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2))));

        std::cout << aimDirNorm.x << " " << aimDirNorm.y << std::endl;

        // Player
        if(Keyboard::isKeyPressed(Keyboard::A))
        {
            player.move(-10.f, 0.f);
        }
        if(Keyboard::isKeyPressed(Keyboard::D))
        {
            player.move(10.f, 0.f);
        }
        if(Keyboard::isKeyPressed(Keyboard::W))
        {
            player.move(0.f, -10.f);
        }
        if(Keyboard::isKeyPressed(Keyboard::S))
        {
            player.move(0.f, 10.f);
        }

        // Enemy
        if(spawnCounter < 20)
        {
            spawnCounter++;
        }

        if(spawnCounter >= 20 && enemies.size() < 50)
        {
            enemy.setPosition(Vector2f(rand()%window.getSize().x, rand()%window.getSize().y));
            enemies.push_back(RectangleShape(enemy));
            spawnCounter = 0;
        }

        // Shooting
        if(Mouse::isButtonPressed(Mouse::Left))
        {
            b1.bullet.setPosition(playerCenter);
            b1.currVelocity = aimDirNorm * b1.maxSpeed;

            bullets.push_back(Bullet(b1));
        }

        for(int i = 0; i < bullets.size(); i++)
        {
            bullets[i].bullet.move(bullets[i].currVelocity);

            // Out of bounds
            if(bullets[i].bullet.getPosition().x < 0 || bullets[i].bullet.getPosition().x > window.getSize().x
                    || bullets[i].bullet.getPosition().y < 0 || bullets[i].bullet.getPosition().y > window.getSize().y)
            {
                bullets.erase(bullets.begin() + i);
            }
            else
            {
                //Enemy collision
                for(int k = 0; k < enemies.size(); k++)
                {
                    if(bullets[i].bullet.getGlobalBounds().intersects(enemies[k].getGlobalBounds())) {
                        bullets.erase(bullets.begin() + i);
                        enemies.erase(enemies.begin() + k);
                        break;
                    }
                }
            }
        }
        // Draw

        window.clear();

        for(int i = 0; i < enemies.size(); i++)
        {
            window.draw(enemies[i]);
        }
        window.draw(player);

        for(int i = 0; i < bullets.size(); i++)
        {
            window.draw(bullets[i].bullet);
        }
        window.display();
    }
    return 0;
}

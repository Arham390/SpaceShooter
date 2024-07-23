#include<iostream>
using namespace std;
using namespace sf;

class Bullet {
public:
   Bullet(sf::Vector2f position) {
    texture.loadFromFile("img/enemy_laser.png");
    sprite.setTexture(texture);
    sprite.setPosition(position);
       Velocity = sf::Vector2f(0, -10);
    }

  sf::Vector2f getVelocity() const { return Velocity; } 
    void update() {
        // Add velocity to position
        sprite.setPosition(sprite.getPosition() + getVelocity());
    }
    void setVelocity(const sf::Vector2f& velocity) {
        this->Velocity = velocity;
    }

    Sprite sprite;
     Sprite sprite1;
    Texture& getTexture() { return texture; }
     sf::Vector2f getPosition() { return sprite.getPosition(); }
private:
sf::Vector2f Velocity;
    Texture texture;
     Texture texture1;
};

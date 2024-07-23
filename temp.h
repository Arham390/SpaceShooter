#include<iostream>

using namespace std;
class Lives  {
public:
Lives(sf::Vector2f position) {
        texture.loadFromFile("img/heart.png");
        sprite.setTexture(texture);
        sprite.setPosition(position);
        sprite.setScale(0.1,0.1);
        Velocity = sf::Vector2f(0, 0.25);
    }
     sf::Vector2f getVelocity() const { return Velocity; }
    void update() {
        // Add velocity to position
        sprite.setPosition(sprite.getPosition() + getVelocity());
    }

    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f getPosition() { return sprite.getPosition(); }
    sf::Texture& getTexture() { return texture; }

private:
    sf::Vector2f Velocity;
};

class Addon {
//private:
public:
    static const int MAX_LIVES = 100;
    Lives* lives[MAX_LIVES]; // array of pointers to Lives instances
    int num_lives = 0;


    virtual ~Addon() {}
   void generateLives(sf::Vector2f playerPos) {
    if (num_lives < MAX_LIVES) {
        Lives* life = new Lives(sf::Vector2f(playerPos.x, 0)); 
        if (life != nullptr) {  // check if the pointer is not null
            life->sprite.setTexture(life->getTexture());
            lives[num_lives] = life;
            num_lives++;
        }
    }
}

    Lives** getLives() { return lives; }
    int getNumLives() const { return num_lives; }
    Lives* getLife(int index) const { return lives[index]; }
};



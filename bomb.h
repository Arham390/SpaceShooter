
#include <SFML/Graphics.hpp>
#include <iostream>

class Bomb {
public:
    Bomb(sf::Vector2f position) {
        texture.loadFromFile("img/bombpixel.png");
        sprite.setTexture(texture);
        sprite.setPosition(position);
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


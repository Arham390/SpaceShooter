#include <SFML/Graphics.hpp>
#include <iostream>

class Addon {
public:
    virtual ~Addon() {}
    virtual void generate(sf::Vector2f playerPos) = 0;
};

class Lives : public Addon {
public:
    Lives(sf::Vector2f position) {
        texture.loadFromFile("img/heart.png");
        sprite.setTexture(texture);
        sprite.setPosition(position);
        sprite.setScale(0.1,0.1);
        Velocity = sf::Vector2f(0, 0.25);
    }

    void generate(sf::Vector2f playerPos) override {
        if (num_lives < MAX_LIVES) {
            Lives* life = new Lives(sf::Vector2f(playerPos.x, 0)); 
            if (life != nullptr) {  // check if the pointer is not null
                life->sprite.setTexture(life->getTexture());
                lives[num_lives] = life;
                num_lives++;
            }
        }
    }

    sf::Vector2f getVelocity() const { return Velocity; }
    void update() {
        // Add velocity to position
        sprite.setPosition(sprite.getPosition() + getVelocity());
    }
     Lives** getLives() { return lives; }
    int getNumLives() const { return num_lives; }
    Lives* getLife(int index) const { return lives[index]; }

    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f getPosition() { return sprite.getPosition(); }
    sf::Texture& getTexture() { return texture; }

private:
    static const int MAX_LIVES = 100;
    Lives* lives[MAX_LIVES]; // array of pointers to Lives instances
    int num_lives = 0;
    sf::Vector2f Velocity;
};

class Danger : public Addon {
public:
    Danger(sf::Vector2f position) {
        texture.loadFromFile("img/danger.png");
        sprite.setTexture(texture);
        sprite.setPosition(position);
        sprite.setScale(0.1,0.1);
        Velocity = sf::Vector2f(0, 0.25);
    }

    void generate(sf::Vector2f playerPos) override {
        if (num_dangers < MAX_DANGERS) {
            Danger* danger = new Danger(sf::Vector2f(playerPos.x, 0)); 
            if (danger != nullptr) {  // check if the pointer is not null
                danger->sprite.setTexture(danger->getTexture());
                dangers[num_dangers] = danger;
                num_dangers++;
            }
        }
    }
 Danger** getDangers() { return dangers; }
    int getNumDangers() const { return num_dangers; }
    Danger* getDangers(int index) const {
        if (index >= 0 && index < num_dangers) {
            return dangers[index];
        }
        return nullptr; // return nullptr if the index is out of bounds
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
    static const int MAX_DANGERS = 100;
    Danger* dangers[MAX_DANGERS]; // array of pointers to Danger instances
    int num_dangers = 0;
    sf::Vector2f Velocity;
};


class Fire : public Addon {
public:
    Fire(sf::Vector2f position) {
        texture.loadFromFile("img/fire.png");
        sprite.setTexture(texture);
        sprite.setPosition(position);
        sprite.setScale(0.2, 0.2);
        velocity = sf::Vector2f(0, 0.25);
    }

    void generate(sf::Vector2f playerPos) override {
        if (num_fires < MAX_FIRES) {
            Fire* fire = new Fire(sf::Vector2f(playerPos.x, 0));
            if (fire != nullptr) {  // check if the pointer is not null
                fire->sprite.setTexture(fire->getTexture());
                fires[num_fires] = fire;
                num_fires++;
            }
        }
    }

    Fire** getFires() { return fires; }
    int getNumFires() const { return num_fires; }
    Fire* getFire(int index) const {
        if (index >= 0 && index < num_fires) {
            return fires[index];
        }
        return nullptr; // return nullptr if the index is out of bounds
    }
    sf::Vector2f getVelocity() const { return velocity; }
    void update() {
        // Add velocity to position
        sprite.setPosition(sprite.getPosition() + velocity);
    }

    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f getPosition() { return sprite.getPosition(); }
    sf::Texture& getTexture() { return texture; }

private:
    static const int MAX_FIRES = 100;
    Fire* fires[MAX_FIRES]; // array of pointers to Fire instances
    int num_fires = 0;
    sf::Vector2f velocity;
};



class Powerup : public Addon {
public:
    Powerup(sf::Vector2f position) {
        texture.loadFromFile("img/powerup.png");
        sprite.setTexture(texture);
        sprite.setPosition(position);
        sprite.setScale(0.1, 0.1);
        velocity = sf::Vector2f(0, 0.25);
    }

    void generate(sf::Vector2f playerPos) override {
        if (num_powerups < MAX_POWERUPS) {
            Powerup* powerup = new Powerup(sf::Vector2f(playerPos.x, 0));
            if (powerup != nullptr) {  // check if the pointer is not null
                powerup->sprite.setTexture(powerup->getTexture());
                powerups[num_powerups] = powerup;
                num_powerups++;
            }
        }
    }

    Powerup** getPowerups() { return powerups; }
    int getNumPowerups() const { return num_powerups; }
    Powerup* getPowerup(int index) const {
        if (index >= 0 && index < num_powerups) {
            return powerups[index];
        }
        return nullptr; // return nullptr if the index is out of bounds
    }
    sf::Vector2f getVelocity() const { return velocity; }
    void update() {
        // Add velocity to position
        sprite.setPosition(sprite.getPosition() + velocity);
    }

    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f getPosition() { return sprite.getPosition(); }
    sf::Texture& getTexture() { return texture; }

private:
    static const int MAX_POWERUPS = 100;
    Powerup* powerups[MAX_POWERUPS]; // array of pointers to Powerup instances
    int num_powerups = 0;
    sf::Vector2f velocity;
};












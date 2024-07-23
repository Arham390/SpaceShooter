#include <time.h>
class Monster  {
private:
 sf::Texture fireTexture; // Texture for the dragon's fire
  sf::Texture texture;
public:
bool isActive=false; // Indicates whether the dragon is active or not
    sf::Clock activeTimer; // Timer to control the duration of the dragon's appearance
    sf::Clock fireTimer; // Timer to control the interval between firing projectiles
    sf::Vector2f fireDirection; // Direction of the dragon's fire
   
    sf::Sprite sprite;
    sf::Sprite firesprite;
     sf::Vector2f Velocity;

   
    float Timer=0.0f;
 Monster() {
        // Load dragon texture and set position
        texture.loadFromFile("img/monster.png");
        sprite.setTexture(texture);
        sprite.setPosition(0, 0);
        sprite.setScale(0.1,0.1);
        Velocity = sf::Vector2f(0, 0.025);
        // Load fire texture
        fireTexture.loadFromFile("img/light.png");
firesprite.setTexture(texture);
        firesprite.setPosition(0, 0);
        firesprite.setScale(5,5);
          firesprite.setTexture(fireTexture);
        // Set initial fire direction to downwards
        fireDirection = sf::Vector2f(0, 1);
        cout<<"a"<<endl;
    }

  sf::Vector2f getPosition() { return firesprite.getPosition(); }
sf::Texture& getTexture() { return texture; }
sf::Texture& getTexture1() { return fireTexture; }
   };    

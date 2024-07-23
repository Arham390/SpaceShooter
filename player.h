#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;
#include<iostream>
#include"bullet.h"
#include"addon.h"
using namespace std;
class Player
{
private:
  static const int MAX_BULLETS = 100;	// maximum number of bullets allowed on screen
  Bullet *bullets[MAX_BULLETS];	// array to store pointers to the bullets
  int num_bullets = 0;

  int num_bullets1 = 0;
public:
    Bullet * bullet;
  Bullet *bullet1;
  Bullet *bullet2;
  Lives *addon;
  Danger *addon2;
  Fire *addon3;
  Powerup *addon4;
  Texture tex;
  Sprite sprite;
  float speed = 0.1;
  int x, y;
    Player (std::string png_path)
  {
//addon = new Lives(getPosition());
    addon = new Lives (getPosition ());
    addon2 = new Danger (getPosition ());
    addon3 = new Fire (getPosition ());
    addon4 = new Powerup (getPosition ());
//Lives = new Lives(getPosition());
    tex.loadFromFile (png_path);
    sprite.setTexture (tex);
    x = 340;
    y = 700;
    sprite.setPosition (x, y);
    sprite.setScale (0.75, 0.75);
  }

  int getnum_bullets () const
  {
    return num_bullets;
  }
  int getnum_bullets1 () const
  {
    return num_bullets1;
  }
  Bullet *getbullets (int index) const
  {
    return bullets[index];
  }
  Bullet *getbullets () const
  {
    return bullets[0];
  }
  void fire ()
  {
    if (num_bullets < MAX_BULLETS)
      {
	Bullet *bullet = new Bullet (this->getPosition ());
	bullet->sprite.setTexture (bullet->getTexture ());	// set the texture of the bullet sprite
	bullets[num_bullets] = bullet;	// add a pointer to the bullet to the array
	//  cout<<"l"<<endl;
	num_bullets++;		// increment the number of bullets on screen

      }
  }

  Bullet *firet ()
  {
    Bullet *bullet = new Bullet (this->getPosition ());
    bullet->sprite.setTexture (bullet->getTexture ());
    bullet->setVelocity (sf::Vector2f (0, -0.5));
    return bullet;
  }

  Bullet *firet1 ()
  {
    Bullet *bullet1 = new Bullet (this->getPosition ());
    bullet1->sprite.setTexture (bullet->getTexture ());
    bullet1->setVelocity (sf::Vector2f (0, -0.5));
    return bullet1;
  }
  Bullet *firet2 ()
  {
    Bullet *bullet1 = new Bullet (this->getPosition ());
    bullet1->sprite.setTexture (bullet->getTexture ());
    bullet1->setVelocity (sf::Vector2f (0, -0.5));
    return bullet1;
  }
/*
void setOrigin(float x, float y) {
    // Set the origin of the sprite
    sprite.setOrigin(x, y);

    // Update the position of the sprite to take into account the new origin
    float newX = sprite.getPosition().x + sprite.getGlobalBounds().width / 2 - x;
    float newY = sprite.getPosition().y + sprite.getGlobalBounds().height / 2 - y;
    sprite.setPosition(newX, newY);
}
*/
  sf::FloatRect getGlobalBounds ()const
  {
    return sprite.getGlobalBounds ();
  }
  sf::Texture getTexture () const
  {
    return tex;
  }
  sf::Vector2f getPosition () const
  {
    return sprite.getPosition ();
  }
  void setPosition ()
  {
    return sprite.setPosition (340, 700);
  }
  void setPosition (int x, int y)
  {
    return sprite.setPosition (x, y);
  }
  void resetPlayer (int once)
  {
    if (once == 1)
      {
	sprite.setPosition (340, 700);
	once = 0;
      }
  }
  void move (std::string s)
  {
    float delta_x = 0, delta_y = 0;

    if (s == "l")
      delta_x = -1;
    //move the player left
    else if (s == "r")
      {
	delta_x = 1;
      }
    //move the player right
    if (s == "u")
      delta_y = -1;
    else if (s == "d")
      delta_y = 1;

    if (s == "tl")
      {
//cout<<"l key pressed"<<endl;
	delta_y = -0.5;
	delta_x = -0.75;

      }

    else if (s == "tr")
      {
//cout<<"k key pressed"<<endl;
	delta_y = +0.5;
	delta_x = +0.75;

      }

    if (s == "th")
      {
//cout<<"l key pressed"<<endl;
	delta_y = -0.5;
	delta_x = +0.75;

      }
    else if (s == "tj")
      {
//cout<<"k key pressed"<<endl;
	delta_y = +0.5;
	delta_x = -0.75;

      }
    delta_x *= speed;
    delta_y *= speed;

    sprite.move (sf::Vector2f (delta_x, delta_y));

  }

  int setscreenwidth (int x1)
  {
    x = x1;
    return x;
  }

  int setscreenheight (int y1)
  {
    y = y1;
    return y;
  }



  void wrap (int screen_width, int screen_height)
  {
    if (sprite.getPosition ().x < -screen_width)
      {
	sprite.setPosition (screen_width, sprite.getPosition ().y);
      }
    else if (sprite.getPosition ().x > screen_width)
      {
	sprite.setPosition (-sprite.getGlobalBounds ().width,
			    sprite.getPosition ().y);
      }
    if (sprite.getPosition ().y < -screen_height)
      {
	sprite.setPosition (sprite.getPosition ().x, screen_height);
      }
    else if (sprite.getPosition ().y > screen_height)
      {
	sprite.setPosition (sprite.getPosition ().x, -screen_height);
      }
  }






};


#include <iostream>

#include <SFML/Graphics.hpp>
#include"bomb.h"
#include <ctime>		// for std::time function
#include <cstdlib>
#include"monster.h"
#include"beta.h"
#include"gamma.h"
#include"dragon.h"
class Enemy
{
protected:

  Texture en;



  // Generate a random number between 0 and 3
  // std::srand(time(nullptr)); // seed std::rand with current time
  //     n =rand() % 4;
  int n;

  int num_bombs = 0;
  int num_monster = 0;
  int num_monsterl = 0;
  int num_dragon = 0;
  int num_dragonl = 0;
  bool light = false;
public:
  static const int MAX_Monsters = 2;
  Monster *monster[MAX_Monsters];
  static const int MAX_dragons = 2;
  Dragon *dragon[MAX_dragons];
  static const int MAX_BOMBS = 100;
  Bomb *bombs[MAX_BOMBS];
  int m;
  Beta beta;
  Gamma gamma;
  int level = 1;
  int count = 1;
  Sprite ene;
  Sprite ene1;
  Sprite ene2;
  Sprite ene3;
  Sprite ene4;
  Sprite ene5;
    sf::Texture getEn () const
  {
    return en;
  }
  Enemy ()
  {
    count++;
    std::srand (std::time (nullptr));
    n = std::rand () % 4;
    if (n == 0)
      {
	n += 1;
      }
    if (count > 1)
      {
	n = n + 1;
	if (n >= 3)
	  {
	    n = n - 1;
	  }
      }
    cout << n;
    //   m=n;
    //  n=2;
    if (n == 2)
      {
	n++;
      }
    if (level == 1)
      {
	en.loadFromFile ("img/enemy_1.png");
	if (n == 1)
	  {
	    ene.setTexture (en);
	    ene.setScale (1, 1);

	    ene1.setTexture (en);
	    ene1.setScale (1, 1);
	    ene1.setPosition (300, 0);

	    ene2.setTexture (en);
	    ene2.setScale (1, 1);
	    ene2.setPosition (600, 0);

	    ene3.setTexture (en);
	    ene3.setScale (1, 1);
	    ene3.setPosition (600, 150);

	    ene4.setTexture (en);
	    ene4.setScale (1, 1);
	    ene4.setPosition (300, 150);

	    ene5.setTexture (en);
	    ene5.setScale (1, 1);
	    ene5.setPosition (0, 150);
	  }
	else if (n == 2)
	  {
	    ene.setTexture (en);
	    ene.setScale (1, 1);

	    ene1.setTexture (en);
	    ene1.setScale (1, 1);
	    ene1.setPosition (200, 150);

	    ene2.setTexture (en);
	    ene2.setScale (1, 1);
	    ene2.setPosition (600, 0);

	    ene3.setTexture (en);
	    ene3.setScale (1, 1);
	    ene3.setPosition (600, 250);

	    ene4.setTexture (en);
	    ene4.setScale (1, 1);
	    ene4.setPosition (400, 150);

	    ene5.setTexture (en);
	    ene5.setScale (1, 1);
	    ene5.setPosition (0, 250);
	  }
	else if (n == 3)
	  {
	    ene.setTexture (en);
	    ene.setScale (1, 1);
	    ene.setPosition (500, 100);

	    ene1.setTexture (en);
	    ene1.setScale (1, 1);
	    ene1.setPosition (100, 100);

	    ene2.setTexture (en);
	    ene2.setScale (1, 1);
	    ene2.setPosition (300, 250);

	    ene3.setTexture (en);
	    ene3.setScale (1, 1);
	    ene3.setPosition (600, 250);

	    ene4.setTexture (en);
	    ene4.setScale (1, 1);
	    ene4.setPosition (300, 0);

	    ene5.setTexture (en);
	    ene5.setScale (1, 1);
	    ene5.setPosition (0, 250);

	  }

      }

  }

  sf::Vector2f getPosition ()
  {
    return ene.getPosition ();
  }
  sf::Vector2f getPosition1 ()
  {
    return ene1.getPosition ();
  }
  sf::Vector2f getPosition2 ()
  {
    return ene2.getPosition ();
  }
  sf::Vector2f getPosition3 ()
  {
    return ene3.getPosition ();
  }
  sf::Vector2f getPosition4 ()
  {
    return ene4.getPosition ();
  }
  sf::Vector2f getPosition5 ()
  {
    return ene5.getPosition ();
  }
  sf::Texture getTexture ()const
  {
    return en;
  }

  void createbomb (sf::Vector2f playerPos)
  {
    if (num_bombs < MAX_BOMBS)
      {
	Bomb *bomb = new Bomb (sf::Vector2f (playerPos.x + 100, 100));	// set initial position to player ship's x position and top of the screen
	bomb->sprite.setTexture (bomb->getTexture ());
	bombs[num_bombs] = bomb;
	num_bombs++;
      }
  }
  void createmonster ()
  {
    if (num_monster < MAX_Monsters)
      {
	Monster *newMonster = new Monster ();

	newMonster->sprite.setTexture (newMonster->getTexture ());

	monster[num_monster] = newMonster;
	num_monster++;
      }
  }
  void createlight ()
  {
    if (num_monsterl < MAX_Monsters)
      {

	Monster *light = new Monster ();

	light->sprite.setTexture (light->getTexture1 ());
	monster[num_monster] = light;
	num_monsterl++;
      }
  }

  void createdragon ()
  {
    if (num_dragonl < MAX_dragons)
      {
	Dragon *newDragon = new Dragon ();

	newDragon->sprite.setTexture (newDragon->getTexture ());

	dragon[num_dragon] = newDragon;
	num_dragon++;
      }
  }
  void createlightdrag ()
  {
    if (num_dragonl < MAX_dragons)
      {

	Dragon *light = new Dragon ();

	light->sprite.setTexture (light->getTexture1 ());
	dragon[num_dragon] = light;
	num_dragonl++;
      }
  }
  Bomb *getbomba ()
  {
    if (num_bombs > 0)
      {
	return bombs[num_bombs - 1];
      }
    else
      {
	return nullptr;
      }
  }
  void meh ()
  {
    ene.setTexture (en);
    ene.setScale (1, 1);
    ene.setPosition (500, 100);

    ene1.setTexture (en);
    ene1.setScale (1, 1);
    ene1.setPosition (100, 100);

    ene2.setTexture (en);
    ene2.setScale (1, 1);
    ene2.setPosition (300, 250);

    ene3.setTexture (en);
    ene3.setScale (1, 1);
    ene3.setPosition (600, 250);

    ene4.setTexture (en);
    ene4.setScale (1, 1);
    ene4.setPosition (300, 0);

    ene5.setTexture (en);
    ene5.setScale (1, 1);
    ene5.setPosition (0, 250);
  }
  Bomb *getBomb () const
  {
    return *bombs;
  }
  int getnum_bombs () const
  {
    return num_bombs;
  }
  Bomb *getbombs (int index) const
  {
    return bombs[index];
  }
  Monster *getmonsters (int index) const
  {
    return monster[index];
  }
  Monster *getlights (int index) const
  {
    return monster[index];
  }

  Dragon *getdragons (int index) const
  {
    return dragon[index];
  }
  Dragon *getlightsmons (int index) const
  {
    return dragon[index];
  }

  void setlevel ()
  {
    level = 2;
  }
};


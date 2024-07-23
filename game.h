
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include<cmath>
using namespace std;
#include "player.h"
#include "Enemy.h"
#include "menu.h"
#include "record.h"
const char title[] = "OOP-Project, Spring-2023";
using namespace sf;

class Game
{
public:
  Sprite background;		//Game background sprite
  Texture bg_texture;
  Player *p;			//player
  Enemy enemy;
  int x = 2;
  Enemy enemy1;
  Menu m;
  Record r;
  Texture obj8;
  Texture obj6;
  int oncie = 0;


//menu m;
  int jk = 0;
  int count = 0;
  int o = 0;
  int o1 = 0;
  int o2 = 0;
  int o3 = 0;
  int o4 = 0;
  int o5 = 0;
  int lives = 3;
  int space = 0;
  int once = 1;
  int n = 1;
  int c = 0;
  int c1 = 0;
  int bo = 0;
// add other game attributes
  int rand_num;
  float bombTimer = 0.0f;
  float lifeTimer = 0.0f;
  float dangerTimer = 0.0f;
  float FireTimer = 0.0f;
  float PowerupTimer = 0.0f;
  int pi = 0;
  int pp = 0;
  int po = 0;
  int pl = 0;
  int i = 0;
  bool sh = false;
  bool monster = false;
  bool dragon = false;
  float monsterTimer = 0.0f;
  float dragonTimer = 0.0f;
  int countofen = 0;
  bool level2 = false;
  bool level3 = false;
  float monsterGenerator = 0.0f;
  float dragonGenerator = 0.0f;
    std::string topScores[3];
    sf::Sprite fireSprite;
  bool paused = false;
    Game ()
  {
    p = new Player ("img/player_ship.png");
    bg_texture.loadFromFile ("img/background.jpg");
    background.setTexture (bg_texture);
    background.setScale (2, 1.5);

  }


//collision detection
  struct Vector2f
  {
    float x;
    float y;
  };
  bool checkCollisionLive (Lives * life, Player * p)
  {
    sf::Vector2f lifePos = life->getPosition ();
    sf::Vector2f playerPos = p->getPosition ();

    float distance =
      sqrt (pow ((lifePos.x - playerPos.x), 2) +
	    pow ((lifePos.y - playerPos.y), 2));
    float radiusSum =
      (life->getTexture ().getSize ().x / 2) +
      (p->getTexture ().getSize ().x / 2);

    if (distance < radiusSum)
      {
	return true;
      }

    return false;
  }
  bool checkCollisionfire (Fire * fire, Player * p)
  {
    sf::Vector2f firePos = fire->getPosition ();
    sf::Vector2f playerPos = p->getPosition ();

    float distance =
      sqrt (pow ((firePos.x - playerPos.x), 2) +
	    pow ((firePos.y - playerPos.y), 2));
    float radiusSum =
      (fire->getTexture ().getSize ().x / 2) +
      (p->getTexture ().getSize ().x / 2);

    if (distance < radiusSum)
      {
	return true;
      }

    return false;
  }

  bool checkCollisionPo (Powerup * po, Player * p)
  {
    sf::Vector2f poPos = po->getPosition ();
    sf::Vector2f playerPos = p->getPosition ();

    float distance =
      sqrt (pow ((poPos.x - playerPos.x), 2) +
	    pow ((poPos.y - playerPos.y), 2));
    float radiusSum =
      (po->getTexture ().getSize ().x / 2) +
      (p->getTexture ().getSize ().x / 2);

    if (distance < radiusSum)
      {
	return true;
      }

    return false;
  }
  bool checkCollisiondan (Danger * po, Player * p)
  {
    sf::Vector2f poPos = po->getPosition ();
    sf::Vector2f playerPos = p->getPosition ();

    float distance =
      sqrt (pow ((poPos.x - playerPos.x), 2) +
	    pow ((poPos.y - playerPos.y), 2));
    float radiusSum =
      (po->getTexture ().getSize ().x / 2) +
      (p->getTexture ().getSize ().x / 2);

    if (distance < radiusSum)
      {
      lives = lives - 1;
	p->setPosition (700, 700);
	return true;
      }

    return false;
  }
  bool checkCollision (Bullet * bullet, Enemy * enemy)
  {

    sf::Vector2f bulletPos = bullet->getPosition ();
    sf::Vector2f enemyPos = enemy->getPosition ();


    float distance =
      sqrt (pow ((bulletPos.x - enemyPos.x), 2) +
	    pow ((bulletPos.y - enemyPos.y), 2));


    if (distance <
	(bullet->getTexture ().getSize ().x / 2 +
	 enemy->getTexture ().getSize ().x / 2))
      {
	cout << "good aim" << endl;
	cout << "Bullet hit enemy!" << endl;
	cout << "t" << endl;
	countofen++;
	bullet->sprite.setPosition (10000, 10000);
	enemy->ene.setPosition (1000, 1000);
	return true;
      }

    return false;
  }
  bool checkCollision10 (Bullet * bullet, Beta * beta)
  {
    sf::Vector2f bulletPos = bullet->getPosition ();
    sf::Vector2f betaPos = beta->getPosition ();

    float distance =
      sqrt (pow ((bulletPos.x - betaPos.x), 2) +
	    pow ((bulletPos.y - betaPos.y), 2));

    if (distance <
	(bullet->getTexture ().getSize ().x / 2 +
	 beta->getTexture ().getSize ().x / 2))
      {
	cout << "Good aim" << endl;
	cout << "Bullet hit Beta!" << endl;
	cout << "t" << endl;
	countofen++;
	bullet->sprite.setPosition (10000, 10000);
	beta->ene.setPosition (1000, 1000);
	return true;
      }

    return false;
  }

  bool checkCollision1 (Bullet * bullet, Enemy * enemy)
  {

    sf::Vector2f bulletPos = bullet->getPosition ();
    sf::Vector2f enemyPos = enemy->getPosition1 ();


    float distance =
      sqrt (pow ((bulletPos.x - enemyPos.x), 2) +
	    pow ((bulletPos.y - enemyPos.y), 2));


    if (distance <
	(bullet->getTexture ().getSize ().x / 2 +
	 enemy->getTexture ().getSize ().x / 2))
      {
	cout << "good aim" << endl;
	cout << "Bullet hit enemy!" << endl;
	countofen++;
	bullet->sprite.setPosition (10000, 10000);
	enemy->ene1.setPosition (1000, 1000);
	return true;
      }

    return false;
  }
  bool checkCollision1 (Bullet * bullet, Beta * beta)
  {
    sf::Vector2f bulletPos = bullet->getPosition ();
    sf::Vector2f betaPos = beta->getPosition1 ();

    float distance =
      sqrt (pow ((bulletPos.x - betaPos.x), 2) +
	    pow ((bulletPos.y - betaPos.y), 2));

    if (distance <
	(bullet->getTexture ().getSize ().x / 2 +
	 beta->getTexture ().getSize ().x / 2))
      {
	cout << "Good aim" << endl;
	cout << "Bullet hit Beta!" << endl;
	cout << "t" << endl;
	countofen++;
	bullet->sprite.setPosition (10000, 10000);
	beta->ene1.setPosition (1000, 1000);
	return true;
      }

    return false;
  }
  bool checkCollision2 (Bullet * bullet, Enemy * enemy)
  {

    sf::Vector2f bulletPos = bullet->getPosition ();
    sf::Vector2f enemyPos = enemy->getPosition2 ();


    float distance =
      sqrt (pow ((bulletPos.x - enemyPos.x), 2) +
	    pow ((bulletPos.y - enemyPos.y), 2));


    if (distance <
	(bullet->getTexture ().getSize ().x / 2 +
	 enemy->getTexture ().getSize ().x / 2))
      {
	cout << "good aim" << endl;
	cout << "Bullet hit enemy!" << endl;
	countofen++;
	bullet->sprite.setPosition (10000, 10000);
	enemy->ene2.setPosition (1000, 1000);
	return true;
      }

    return false;
  }
  bool checkCollision2 (Bullet * bullet, Beta * beta)
  {
    sf::Vector2f bulletPos = bullet->getPosition ();
    sf::Vector2f betaPos = beta->getPosition2 ();

    float distance =
      sqrt (pow ((bulletPos.x - betaPos.x), 2) +
	    pow ((bulletPos.y - betaPos.y), 2));

    if (distance <
	(bullet->getTexture ().getSize ().x / 2 +
	 beta->getTexture ().getSize ().x / 2))
      {
	cout << "Good aim" << endl;
	cout << "Bullet hit Beta!" << endl;
	cout << "t" << endl;
	countofen++;
	bullet->sprite.setPosition (10000, 10000);
	beta->ene2.setPosition (1000, 1000);
	return true;
      }

    return false;
  }
  bool checkCollision3 (Bullet * bullet, Enemy * enemy)
  {

    sf::Vector2f bulletPos = bullet->getPosition ();
    sf::Vector2f enemyPos = enemy->getPosition3 ();


    float distance =
      sqrt (pow ((bulletPos.x - enemyPos.x), 2) +
	    pow ((bulletPos.y - enemyPos.y), 2));


    if (distance <
	(bullet->getTexture ().getSize ().x / 2 +
	 enemy->getTexture ().getSize ().x / 2))
      {
	cout << "good aim" << endl;
	cout << "Bullet hit enemy!" << endl;
	countofen++;
	bullet->sprite.setPosition (10000, 10000);
	enemy->ene3.setPosition (1000, 1000);
	return true;
      }

    return false;

  }
  bool checkCollision3 (Bullet * bullet, Beta * beta)
  {
    sf::Vector2f bulletPos = bullet->getPosition ();
    sf::Vector2f betaPos = beta->getPosition3 ();

    float distance =
      sqrt (pow ((bulletPos.x - betaPos.x), 2) +
	    pow ((bulletPos.y - betaPos.y), 2));

    if (distance <
	(bullet->getTexture ().getSize ().x / 2 +
	 beta->getTexture ().getSize ().x / 2))
      {
	cout << "Good aim" << endl;
	cout << "Bullet hit Beta!" << endl;
	cout << "t" << endl;
	countofen++;
	bullet->sprite.setPosition (10000, 10000);
	beta->ene3.setPosition (1000, 1000);
	return true;
      }

    return false;
  }

  bool checkCollision4 (Bullet * bullet, Enemy * enemy)
  {

    sf::Vector2f bulletPos = bullet->getPosition ();
    sf::Vector2f enemyPos = enemy->getPosition4 ();


    float distance =
      sqrt (pow ((bulletPos.x - enemyPos.x), 2) +
	    pow ((bulletPos.y - enemyPos.y), 2));


    if (distance <
	(bullet->getTexture ().getSize ().x / 2 +
	 enemy->getTexture ().getSize ().x / 2))
      {
	cout << "good aim" << endl;
	cout << "Bullet hit enemy!" << endl;
	countofen++;
	bullet->sprite.setPosition (10000, 10000);
	enemy->ene4.setPosition (1000, 1000);
	return true;
      }

    return false;
  }
  bool checkCollision4 (Bullet * bullet, Beta * beta)
  {
    sf::Vector2f bulletPos = bullet->getPosition ();
    sf::Vector2f betaPos = beta->getPosition4 ();

    float distance =
      sqrt (pow ((bulletPos.x - betaPos.x), 2) +
	    pow ((bulletPos.y - betaPos.y), 2));

    if (distance <
	(bullet->getTexture ().getSize ().x / 2 +
	 beta->getTexture ().getSize ().x / 2))
      {
	cout << "Good aim" << endl;
	cout << "Bullet hit Beta!" << endl;
	cout << "t" << endl;
	countofen++;
	bullet->sprite.setPosition (10000, 10000);
	beta->ene4.setPosition (1000, 1000);
	return true;
      }

    return false;
  }
  bool checkCollision5 (Bullet * bullet, Enemy * enemy)
  {

    sf::Vector2f bulletPos = bullet->getPosition ();
    sf::Vector2f enemyPos = enemy->getPosition5 ();


    float distance =
      sqrt (pow ((bulletPos.x - enemyPos.x), 2) +
	    pow ((bulletPos.y - enemyPos.y), 2));


    if (distance <
	(bullet->getTexture ().getSize ().x / 2 +
	 enemy->getTexture ().getSize ().x / 2))
      {
	cout << "good aim" << endl;
	cout << "Bullet hit enemy!" << endl;
	countofen++;
	bullet->sprite.setPosition (10000, 10000);
	enemy->ene5.setPosition (1000, 1000);
	return true;
      }

    return false;
  }
  bool checkCollision5 (Bullet * bullet, Beta * beta)
  {
    sf::Vector2f bulletPos = bullet->getPosition ();
    sf::Vector2f betaPos = beta->getPosition5 ();

    float distance =
      sqrt (pow ((bulletPos.x - betaPos.x), 2) +
	    pow ((bulletPos.y - betaPos.y), 2));

    if (distance <
	(bullet->getTexture ().getSize ().x / 2 +
	 beta->getTexture ().getSize ().x / 2))
      {
	cout << "Good aim" << endl;
	cout << "Bullet hit Beta!" << endl;
	cout << "t" << endl;
	countofen++;
	bullet->sprite.setPosition (10000, 10000);
	beta->ene5.setPosition (1000, 1000);
	return true;
      }

    return false;
  }

  bool checkCollision (Bullet * bullet, Gamma * gamma)
  {
    sf::Vector2f bulletPos = bullet->getPosition ();
    sf::Vector2f betaPos = gamma->getPosition ();

    float distance =
      sqrt (pow ((bulletPos.x - betaPos.x), 2) +
	    pow ((bulletPos.y - betaPos.y), 2));

    if (distance <
	(bullet->getTexture ().getSize ().x / 2 +
	 gamma->getTexture ().getSize ().x / 2))
      {
	cout << "Good aim" << endl;
	cout << "Bullet hit Beta!" << endl;
	cout << "t" << endl;
	countofen++;
	bullet->sprite.setPosition (10000, 10000);
	gamma->ene.setPosition (1000, 1000);
	return true;
      }

    sf::Vector2f betaPos1 = gamma->getPosition1 ();

    float distance1 =
      sqrt (pow ((bulletPos.x - betaPos1.x), 2) +
	    pow ((bulletPos.y - betaPos1.y), 2));

    if (distance1 <
	(bullet->getTexture ().getSize ().x / 2 +
	 gamma->getTexture ().getSize ().x / 2))
      {
	cout << "Good aim" << endl;
	cout << "Bullet hit Beta!" << endl;
	cout << "t" << endl;
	countofen++;
	bullet->sprite.setPosition (10000, 10000);
	gamma->ene1.setPosition (1000, 1000);
	return true;
      }

    sf::Vector2f betaPos2 = gamma->getPosition2 ();

    float distance2 =
      sqrt (pow ((bulletPos.x - betaPos2.x), 2) +
	    pow ((bulletPos.y - betaPos2.y), 2));

    if (distance2 <
	(bullet->getTexture ().getSize ().x / 2 +
	 gamma->getTexture ().getSize ().x / 2))
      {
	cout << "Good aim" << endl;
	cout << "Bullet hit Beta!" << endl;
	cout << "t" << endl;
	countofen++;
	bullet->sprite.setPosition (10000, 10000);
	gamma->ene2.setPosition (1000, 1000);
	return true;
      }
    sf::Vector2f betaPos3 = gamma->getPosition3 ();

    float distance3 =
      sqrt (pow ((bulletPos.x - betaPos3.x), 2) +
	    pow ((bulletPos.y - betaPos3.y), 2));

    if (distance3 <
	(bullet->getTexture ().getSize ().x / 2 +
	 gamma->getTexture ().getSize ().x / 2))
      {
	cout << "Good aim" << endl;
	cout << "Bullet hit Beta!" << endl;
	cout << "t" << endl;
	countofen++;
	bullet->sprite.setPosition (10000, 10000);
	gamma->ene3.setPosition (1000, 1000);
	return true;
      }
    sf::Vector2f betaPos4 = gamma->getPosition4 ();

    float distance4 =
      sqrt (pow ((bulletPos.x - betaPos4.x), 2) +
	    pow ((bulletPos.y - betaPos4.y), 2));

    if (distance4 <
	(bullet->getTexture ().getSize ().x / 2 +
	 gamma->getTexture ().getSize ().x / 2))
      {
	cout << "Good aim" << endl;
	cout << "Bullet hit Beta!" << endl;
	cout << "t" << endl;
	countofen++;
	bullet->sprite.setPosition (10000, 10000);
	gamma->ene4.setPosition (1000, 1000);
	return true;
      }
    sf::Vector2f betaPos5 = gamma->getPosition5 ();

    float distance5 =
      sqrt (pow ((bulletPos.x - betaPos5.x), 2) +
	    pow ((bulletPos.y - betaPos5.y), 2));

    if (distance5 <
	(bullet->getTexture ().getSize ().x / 2 +
	 gamma->getTexture ().getSize ().x / 2))
      {
	cout << "Good aim" << endl;
	cout << "Bullet hit Beta!" << endl;
	cout << "t" << endl;
	countofen++;
	bullet->sprite.setPosition (10000, 10000);
	gamma->ene5.setPosition (1000, 1000);
	return true;
      }
    sf::Vector2f betaPos6 = gamma->getPosition6 ();

    float distance6 =
      sqrt (pow ((bulletPos.x - betaPos6.x), 2) +
	    pow ((bulletPos.y - betaPos6.y), 2));

    if (distance6 <
	(bullet->getTexture ().getSize ().x / 2 +
	 gamma->getTexture ().getSize ().x / 2))
      {
	cout << "Good aim" << endl;
	cout << "Bullet hit Beta!" << endl;
	cout << "t" << endl;
	countofen++;
	bullet->sprite.setPosition (10000, 10000);
	gamma->ene6.setPosition (1000, 1000);
	return true;
      }
    sf::Vector2f betaPos7 = gamma->getPosition7 ();

    float distance7 =
      sqrt (pow ((bulletPos.x - betaPos7.x), 2) +
	    pow ((bulletPos.y - betaPos7.y), 2));

    if (distance7 <
	(bullet->getTexture ().getSize ().x / 2 +
	 gamma->getTexture ().getSize ().x / 2))
      {
	cout << "Good aim" << endl;
	cout << "Bullet hit Beta!" << endl;
	cout << "t" << endl;
	countofen++;
	bullet->sprite.setPosition (10000, 10000);
	gamma->ene7.setPosition (1000, 1000);
	return true;
      }
    sf::Vector2f betaPos8 = gamma->getPosition8 ();

    float distance8 =
      sqrt (pow ((bulletPos.x - betaPos8.x), 2) +
	    pow ((bulletPos.y - betaPos8.y), 2));

    if (distance8 <
	(bullet->getTexture ().getSize ().x / 2 +
	 gamma->getTexture ().getSize ().x / 2))
      {
	cout << "Good aim" << endl;
	cout << "Bullet hit Beta!" << endl;
	cout << "t" << endl;
	countofen++;
	bullet->sprite.setPosition (10000, 10000);
	gamma->ene8.setPosition (1000, 1000);
	return true;
      }
    sf::Vector2f betaPos9 = gamma->getPosition9 ();

    float distance9 =
      sqrt (pow ((bulletPos.x - betaPos9.x), 2) +
	    pow ((bulletPos.y - betaPos9.y), 2));

    if (distance9 <
	(bullet->getTexture ().getSize ().x / 2 +
	 gamma->getTexture ().getSize ().x / 2))
      {
	cout << "Good aim" << endl;
	cout << "Bullet hit Beta!" << endl;
	cout << "t" << endl;
	countofen++;
	bullet->sprite.setPosition (10000, 10000);
	gamma->ene9.setPosition (1000, 1000);
	return true;
      }
    sf::Vector2f betaPos10 = gamma->getPosition10 ();

    float distance10 =
      sqrt (pow ((bulletPos.x - betaPos10.x), 2) +
	    pow ((bulletPos.y - betaPos10.y), 2));

    if (distance10 <
	(bullet->getTexture ().getSize ().x / 2 +
	 gamma->getTexture ().getSize ().x / 2))
      {
	cout << "Good aim" << endl;
	cout << "Bullet hit Beta!" << endl;
	cout << "t" << endl;
	countofen++;
	bullet->sprite.setPosition (10000, 10000);
	gamma->ene10.setPosition (1000, 1000);
	return true;
      }
    sf::Vector2f betaPos11 = gamma->getPosition11 ();

    float distance11 =
      sqrt (pow ((bulletPos.x - betaPos11.x), 2) +
	    pow ((bulletPos.y - betaPos11.y), 2));

    if (distance11 <
	(bullet->getTexture ().getSize ().x / 2 +
	 gamma->getTexture ().getSize ().x / 2))
      {
	cout << "Good aim" << endl;
	cout << "Bullet hit Beta!" << endl;
	cout << "t" << endl;
	countofen++;
	bullet->sprite.setPosition (10000, 10000);
	gamma->ene11.setPosition (1000, 1000);
	return true;
      }
    return false;
  }


  bool checkCollisionship (Player * p, Enemy & enemy)
  {
    sf::Vector2f playerPos = p->getPosition ();
    sf::Vector2f enemyPos = enemy.getPosition ();
    float distance =
      std::sqrt (std::pow (playerPos.x - enemyPos.x, 2) +
		 std::pow (playerPos.y - enemyPos.y, 2));
    float collisionDistance =
      p->getTexture ().getSize ().x / 2 +
      enemy.getTexture ().getSize ().x / 2;
    if (distance < collisionDistance)
      {
	std::cout << "Spaceship collided with enemy" << std::endl;
	decreaselife ();

	return true;
      }
    sf::Vector2f enemyPos1 = enemy.getPosition1 ();
    float distance1 =
      std::sqrt (std::pow (playerPos.x - enemyPos1.x, 2) +
		 std::pow (playerPos.y - enemyPos1.y, 2));
    float collisionDistance1 =
      p->getTexture ().getSize ().x / 2 +
      enemy.getTexture ().getSize ().x / 2;
    if (distance1 < collisionDistance1)
      {
	std::cout << "Spaceship collided with enemy" << std::endl;
	decreaselife ();

	return true;
      }
    sf::Vector2f enemyPos2 = enemy.getPosition2 ();
    float distance2 =
      std::sqrt (std::pow (playerPos.x - enemyPos2.x, 2) +
		 std::pow (playerPos.y - enemyPos2.y, 2));
    float collisionDistance2 =
      p->getTexture ().getSize ().x / 2 +
      enemy.getTexture ().getSize ().x / 2;
    if (distance2 < collisionDistance2)
      {
	std::cout << "Spaceship collided with enemy" << std::endl;
	decreaselife ();

	return true;
      }
    sf::Vector2f enemyPos3 = enemy.getPosition3 ();
    float distance3 =
      std::sqrt (std::pow (playerPos.x - enemyPos3.x, 2) +
		 std::pow (playerPos.y - enemyPos3.y, 2));
    float collisionDistance3 =
      p->getTexture ().getSize ().x / 2 +
      enemy.getTexture ().getSize ().x / 2;
    if (distance3 < collisionDistance3)
      {
	std::cout << "Spaceship collided with enemy" << std::endl;
	decreaselife ();

	return true;
      }
    sf::Vector2f enemyPos4 = enemy.getPosition4 ();
    float distance4 =
      std::sqrt (std::pow (playerPos.x - enemyPos4.x, 2) +
		 std::pow (playerPos.y - enemyPos4.y, 2));
    float collisionDistance4 =
      p->getTexture ().getSize ().x / 2 +
      enemy.getTexture ().getSize ().x / 2;
    if (distance4 < collisionDistance4)
      {
	std::cout << "Spaceship collided with enemy" << std::endl;
	decreaselife ();

	return true;
      }
    sf::Vector2f enemyPos5 = enemy.getPosition5 ();
    float distance5 =
      std::sqrt (std::pow (playerPos.x - enemyPos5.x, 2) +
		 std::pow (playerPos.y - enemyPos5.y, 2));
    float collisionDistance5 =
      p->getTexture ().getSize ().x / 2 +
      enemy.getTexture ().getSize ().x / 2;
    if (distance5 < collisionDistance5)
      {
	std::cout << "Spaceship collided with enemy" << std::endl;
	decreaselife ();

	return true;
      }
    return false;
  }
  bool checkCollisionship (Player * p, Beta & beta)
  {
    sf::Vector2f playerPos = p->getPosition ();
    sf::Vector2f enemyPos = enemy.beta.getPosition ();
    float distance =
      std::sqrt (std::pow (playerPos.x - enemyPos.x, 2) +
		 std::pow (playerPos.y - enemyPos.y, 2));
    float collisionDistance =
      p->getTexture ().getSize ().x / 2 +
      enemy.getTexture ().getSize ().x / 2;
    if (distance < collisionDistance)
      {
	std::cout << "Spaceship collided with enemy" << std::endl;
	decreaselife ();

	return true;
      }
    sf::Vector2f enemyPos1 = enemy.beta.getPosition1 ();
    float distance1 =
      std::sqrt (std::pow (playerPos.x - enemyPos1.x, 2) +
		 std::pow (playerPos.y - enemyPos1.y, 2));
    float collisionDistance1 =
      p->getTexture ().getSize ().x / 2 +
      enemy.getTexture ().getSize ().x / 2;
    if (distance1 < collisionDistance1)
      {
	std::cout << "Spaceship collided with enemy" << std::endl;
	decreaselife ();

	return true;
      }
    sf::Vector2f enemyPos2 = enemy.beta.getPosition2 ();
    float distance2 =
      std::sqrt (std::pow (playerPos.x - enemyPos2.x, 2) +
		 std::pow (playerPos.y - enemyPos2.y, 2));
    float collisionDistance2 =
      p->getTexture ().getSize ().x / 2 +
      enemy.getTexture ().getSize ().x / 2;
    if (distance2 < collisionDistance2)
      {
	std::cout << "Spaceship collided with enemy" << std::endl;
	decreaselife ();

	return true;
      }
    sf::Vector2f enemyPos3 = enemy.beta.getPosition3 ();
    float distance3 =
      std::sqrt (std::pow (playerPos.x - enemyPos3.x, 2) +
		 std::pow (playerPos.y - enemyPos3.y, 2));
    float collisionDistance3 =
      p->getTexture ().getSize ().x / 2 +
      enemy.getTexture ().getSize ().x / 2;
    if (distance3 < collisionDistance3)
      {
	std::cout << "Spaceship collided with enemy" << std::endl;
	decreaselife ();

	return true;
      }
    sf::Vector2f enemyPos4 = enemy.beta.getPosition4 ();
    float distance4 =
      std::sqrt (std::pow (playerPos.x - enemyPos4.x, 2) +
		 std::pow (playerPos.y - enemyPos4.y, 2));
    float collisionDistance4 =
      p->getTexture ().getSize ().x / 2 +
      enemy.getTexture ().getSize ().x / 2;
    if (distance4 < collisionDistance4)
      {
	std::cout << "Spaceship collided with enemy" << std::endl;
	decreaselife ();

	return true;
      }
    sf::Vector2f enemyPos5 = enemy.beta.getPosition5 ();
    float distance5 =
      std::sqrt (std::pow (playerPos.x - enemyPos5.x, 2) +
		 std::pow (playerPos.y - enemyPos5.y, 2));
    float collisionDistance5 =
      p->getTexture ().getSize ().x / 2 +
      enemy.getTexture ().getSize ().x / 2;
    if (distance5 < collisionDistance5)
      {
	std::cout << "Spaceship collided with enemy" << std::endl;
	decreaselife ();

	return true;
      }
    return false;
  }
  bool checkCollisionFire (const sf::Sprite & fire, Enemy & enemy)
  {
    sf::FloatRect fireBounds = fireSprite.getGlobalBounds ();
    sf::Vector2f enemyPos = enemy.getPosition ();
    float distance =
      std::sqrt (std::
		 pow (fireBounds.left + fireBounds.width / 2 - enemyPos.x,
		      2) + std::pow (fireBounds.top + fireBounds.height / 2 -
				     enemyPos.y, 2));
    float collisionDistance =
      fireBounds.width / 2 + enemy.getTexture ().getSize ().x / 2;
    if (distance < collisionDistance)
      {
	std::cout << "Fire collided with enemy" << std::endl;
	return true;
      }
    return false;
  }

  sf::Sprite fire ()
  {
    Texture fireTexture;
    sf::Sprite fireSprite;
    fireTexture.loadFromFile ("img/fire10.png");
    fireSprite.setTexture (fireTexture);
    // Set the position and scale of the fire sprite
    fireSprite.setPosition (p->getPosition ().x, p->getPosition ().y - 100);
    return fireSprite;
  }

  bool checkCollisionbomb (Player * p, Bomb * b)
  {
    sf::Vector2f boPos = b->getPosition ();
    sf::Vector2f playerPos = p->getPosition ();

    float distance =
      sqrt (pow ((boPos.x - playerPos.x), 2) +
	    pow ((boPos.y - playerPos.y), 2));
    float radiusSum =
      (b->getTexture ().getSize ().x / 2) +
      (p->getTexture ().getSize ().x / 2);

    if (distance < radiusSum)
      {
	b->sprite.setPosition (100000, 10000);
	p->setPosition (340, 700);
	return true;

      }

    return false;
  }

  bool checkCollisionmons (Player * p, Monster * m)
  {

    sf::Vector2f playerPos = p->getPosition ();
    sf::Vector2f boPos = m->getPosition ();
    float distance =
      sqrt (pow ((boPos.x - playerPos.x), 2) +
	    pow ((boPos.y - playerPos.y), 2));
    float radiusSum =
      (m->getTexture1 ().getSize ().x * 3.5) +
      (p->getTexture ().getSize ().x * 3.5);

    if (distance < radiusSum)
      {
	lives = lives - 1;
	p->setPosition (700, 700);
	return true;

      }

    return false;
  }
  bool checkCollisiondrag (Player * p, Dragon * d)
  {

    sf::Vector2f playerPos = p->getPosition ();
    sf::Vector2f boPos = d->getPosition ();
    float distance =
      sqrt (pow ((boPos.x - playerPos.x), 2) +
	    pow ((boPos.y - playerPos.y), 2));
    float radiusSum =
      (d->getTexture1 ().getSize ().x * 2.5) +
      (p->getTexture ().getSize ().x * 2.5);

    if (distance < radiusSum)
      {
	lives = lives - 1;
	p->setPosition (100, 100);
	return true;

      }

    return false;
  }
  void addlife ()
  {

    lives = lives + 1;
    cout << lives << endl;
    if (lives >= 6)
      {
	lives = 6;
      }
  }
  void decreaselife ()
  {
    lives = lives - 1;
    cout << lives;
    p->setPosition ();
  }
  void start_game ()
  {
    srand (time (0));
    RenderWindow window (VideoMode (780, 780), title);
    Clock clock;
    float timer = 0;

    while (window.isOpen ())
      {

	float time = clock.getElapsedTime ().asSeconds ();
	clock.restart ();
	timer += time;
	//cout<<time<<endl; 
	monsterGenerator += time;
	dragonGenerator += time;
	Event e;
	while (window.pollEvent (e))
	  {
	    if (e.type == Event::Closed)	// If cross/close is clicked/pressed
	      window.close ();	//close the game                                    
	  }
	if (paused != true)
	  {
	    if (oncie == 0)
	      {
		m.mainmenu (obj8);	//pops up main menu on a new window
	      }
	    if (n == 1)
	      {
		string s;
		cout << "enter player name" << endl;
		cin >> s;
		r.setName (s);
		n++;
	      }
	    if (Keyboard::isKeyPressed (Keyboard::Left))	//If left key is pressed
	      p->move ("l");	// Player will move to left
	    if (Keyboard::isKeyPressed (Keyboard::Right))	// If right key is pressed
	      p->move ("r");	//player will move to right
	    if (Keyboard::isKeyPressed (Keyboard::Up))	//If up key is pressed
	      p->move ("u");	//playet will move upwards
	    if (Keyboard::isKeyPressed (Keyboard::Down))	// If down key is pressed
	      p->move ("d");	//player will move downwards
	    if (Keyboard::isKeyPressed (Keyboard::L))	// L key for left tilt
	      p->move ("tl");
	    if (Keyboard::isKeyPressed (Keyboard::K))	// L key for left down
	      p->move ("tr");
	    if (Keyboard::isKeyPressed (Keyboard::H))	// H key for right tilt up
	      p->move ("th");
	    if (Keyboard::isKeyPressed (Keyboard::J))	// J key for right tilt up
	      p->move ("tj");
	    if (Keyboard::isKeyPressed (Keyboard::Space)
		|| Mouse::isButtonPressed (Mouse::Left))
	      {
		if (timer >= 0.1f)
		  {		// limit firing rate to once every 0.2 seconds
		    p->fire ();
		    timer = 0;
		  }
	      }

	    if (Keyboard::isKeyPressed (Keyboard::P))
	      {
		// Call the pause menu
		// create a sprite
		// rotate the sprite by 45 degrees
		m.display_menu (r.texture);

	      }

	    if (sf::Keyboard::isKeyPressed (sf::Keyboard::M))
	      {

		paused = true;

		//   paused = false;
	      }


	    if (sf::Keyboard::isKeyPressed (sf::Keyboard::R))
	      {

		Game r;
		r.start_game ();
		window.close ();
		//   paused = false;
	      }

//need to randomize and add check
	    bombTimer -= time;
	    if (bombTimer <= 0.0f)
	      {
		//(Keyboard::isKeyPressed(Keyboard::Y)) {

		enemy.createbomb (p->getPosition ());

		bombTimer = (float) (rand () % 4 + 1);
if(level2==true){
bombTimer = (float) (rand () % 4 + 1)-0.5;}
if(level3==true){
bombTimer = (float) (rand () % 4 + 1)-1;}		
	      }

	    // ...

// Declare a pointer to the bomb object
// Create a new bomb if the timer reaches zero and there are no bombs on the screen
	    if (pi == 0)
	      {
		lifeTimer = (float) (rand () % 10 + 1);
		pi++;
	      }

	    lifeTimer -= time;
//cout<<lifeTimer<<endl;
	    if (lifeTimer <= -10.0f)
	      {
		//  p->addon->generateLives((p->getPosition()+100));
		p->addon->generate (sf::Vector2f (p->getPosition ().x + 150,
						  p->getPosition ().y - 50));

		cout << "life coming" << endl;
		lifeTimer = (float) (rand () % 10 + 1);
	      }
	    for (int i = 0; i < p->addon->getNumLives (); i++)
	      {

		p->addon->getLife (i)->sprite.move (0, 0.4);
		window.draw (p->addon->getLife (i)->sprite);
		if (checkCollisionLive (p->addon->getLife (i), p))
		  {
		    cout << "life is about to be added" << endl;
		    addlife ();
		  }


	      }
	    if (pp == 0)
	      {
		dangerTimer = (float) (rand () % 10 + 1);
		pp++;
	      }
	    dangerTimer -= time;
//cout<<dangerTimer<<endl;
	    if (dangerTimer <= -15.0f)
	      {
		p->addon2->generate (sf::Vector2f (p->getPosition ().x + 150,
						   p->getPosition ().y - 50));
		cout << "danger coming" << endl;
		dangerTimer = (float) (rand () % 10 + 1);
	      }
	      
	    for (int i = 0; i < p->addon2->getNumDangers (); i++)
	      {
	      if (monster == false && dragon == false)
		  {
		p->addon2->getDangers (i)->sprite.move (0, 0.4);
		window.draw (p->addon2->getDangers (i)->sprite);
if (checkCollisiondan(p->addon2->getDangers(i), p)) {
		  cout << "danger collision detected" << endl;
            }
}

	      }

	    if (po == 0)
	      {
		FireTimer = (float) (rand () % 10 + 1);
		po++;
	      }

	    FireTimer -= time;
//cout<<lifeTimer<<endl;
	    if (FireTimer <= -13.0f)
	      {
		//  p->addon->generateLives((p->getPosition()+100));
		p->addon3->generate (sf::Vector2f (p->getPosition ().x + 150,
						   p->getPosition ().y - 50));

		cout << "Fire coming" << endl;
		FireTimer = (float) (rand () % 10 + 1);
	      }
	    for (int i = 0; i < p->addon3->getNumFires (); i++)
	      {

		p->addon3->getFire (i)->sprite.move (0, 0.4);
		window.draw (p->addon3->getFire (i)->sprite);
		if (checkCollisionfire (p->addon3->getFire (i), p))
		  {
		    cout << "fireeeeeeeeeeee" << endl;

		    fireSprite = fire ();

		    window.draw (fireSprite);

		    sf::Clock clock;

		  }
		if (checkCollisionFire (fireSprite, enemy))
		  {
		    cout << "hell" << endl;

		  }

	      }





	    if (pl == 0)
	      {
		PowerupTimer = (float) (rand () % 10 + 1);
		pl++;
	      }

	    PowerupTimer -= time;
//cout<<lifeTimer<<endl;
	    if (PowerupTimer <= -15.0f)
	      {
		//  p->addon->generateLives((p->getPosition()+100));
		p->addon4->generate (sf::Vector2f (p->getPosition ().x + 150,
						   p->getPosition ().y - 50));

		cout << "Powerup coming" << endl;
		PowerupTimer = (float) (rand () % 10 + 1);
	      }


	    for (int i = 0; i < p->addon4->getNumPowerups (); i++)
	      {
		p->addon4->getPowerup (i)->sprite.move (0, 0.4);
		window.draw (p->addon4->getPowerup (i)->sprite);

		if (checkCollisionPo (p->addon4->getPowerup (i), p))
		  {
		    cout << "shoott" << endl;
		    if (bo == 0)
		      {
			p->bullet = p->firet ();
			p->bullet1 = p->firet1 ();
			p->bullet2 = p->firet2 ();

			bo = 1;
		      }
		    p->bullet->sprite.move (0, -3);
		    window.draw (p->bullet->sprite);
		    window.draw (p->bullet->sprite);
		    sh = true;

		    p->bullet1->sprite.move (15, -3);
		    window.draw (p->bullet1->sprite);
		    window.draw (p->bullet1->sprite);
		    sh = true;

		    p->bullet2->sprite.move (-15, -3);
		    window.draw (p->bullet2->sprite);
		    window.draw (p->bullet2->sprite);
		    sh = true;
		  }



	      }

	    ////////////////////////////////////////////////
	    /////  Call your functions here            ////
	    //////////////////////////////////////////////
	    p->setscreenwidth (window.getSize ().x);
	    p->setscreenheight (window.getSize ().y);
	    p->wrap (window.getSize ().x, window.getSize ().y);
	    if (checkCollisionship (p, enemy))
	      {
		cout << "Spaceship collided with enemy" << endl;
	      }
	    if (checkCollisionship (p, enemy.beta))
	      {
		cout << "Spaceship collided with enemy" << endl;
	      }

	    if (i == 0)
	      {
		enemy.createmonster ();
		enemy.createlight ();
		enemy.createdragon ();
		enemy.createlightdrag ();
		i++;
	      }

	    if (monsterGenerator >= 25.0f)
	      {
		for (int i = 0; i < 1; i++)
		  {


		    // sf::Vector2f firePosition = enemy.getmonsters(i)->sprite.getPosition() + enemy.getmonsters(i)->fireDirection;

		    // Set the position of the fire sprite and draw it

		    if (c == 0)
		      {
			enemy.getmonsters (i)->firesprite.setPosition (0,
								       150);
			c++;
		      }
		    float deltaTime = clock.getElapsedTime ().asSeconds ();


		    if (monsterTimer <= 5.0f)
		      {

			enemy.getmonsters (i)->firesprite.move (0.09, 0);
			window.draw (enemy.getmonsters (i)->firesprite);
			enemy.getmonsters (i)->sprite.move (0.1, 0);
			window.draw (enemy.getmonsters (i)->sprite);
			window.display ();
			monster = true;
			monsterTimer += deltaTime;
			cout << monsterTimer << endl;
			if (checkCollisionmons (p, enemy.getmonsters (i)))
			  {
			    cout << "moooooo" << endl;
			  }
			else
			  {
			    r.setScore (40);
			  }
		      }
		    if (monsterTimer >= 5.0f && monsterTimer <= 9.0f)
		      {

			if (monsterTimer >= 6.0f)
			  {
			    enemy.getmonsters (i)->firesprite.move (-0.09, 0);
			    window.draw (enemy.getmonsters (i)->firesprite);
			    enemy.getmonsters (i)->sprite.move (-0.1, 0);
			    window.draw (enemy.getmonsters (i)->sprite);
			    window.display ();
			  }
			monster = true;
			monsterTimer += deltaTime;
			cout << monsterTimer << endl;
			if (checkCollisionmons (p, enemy.getmonsters (i)))
			  {
			    cout << "moooooo" << endl;
			  }
			else
			  {
			    r.setScore (40);
			  }
		      }
		    if (monsterTimer > 9.0f)
		      {
			monster = false;
		      }

		  }

	      }
	    if (dragonGenerator >= 15.0f)
	      {
		for (int i = 0; i < 1; i++)
		  {

		    if (c1 == 0)
		      {
			// Set dragon position
			enemy.getdragons (i)->sprite.setPosition (300, 100);
			c1++;
		      }

		    float deltaTime = clock.getElapsedTime ().asSeconds ();
		    // Check if the dragon is active
		    if (dragonTimer < 5.0f)
		      {
			// Fire projectiles based on spaceship position
			if (p->getPosition ().x < 200)
			  {
			    enemy.getdragons (i)->firesprite.setPosition (100,
									  300);
									  
			  }

			else if (p->getPosition ().x > 400)
			  {
			    enemy.getdragons (i)->firesprite.setPosition (600,
									  300);
			  }

			else if (p->getPosition ().x > 200
				 && p->getPosition ().x < 400)
			  {
			    enemy.getdragons (i)->firesprite.setPosition (400,
									  300);
			  }

			if (checkCollisiondrag (p, enemy.getdragons (i)))
			  {
			    cout << "moooooo" << endl;
			    p->setPosition (0, 0);
			  }
			else
			  {
			    r.setScore (60);
			  }
			window.draw (enemy.getdragons (i)->sprite);
			window.draw (enemy.getdragons (i)->firesprite);
			dragon = true;
			dragonTimer += deltaTime;
			window.display();
		      }
		    else
		      {
			dragon = false;
		      }
		  }
	      }



	    for (int i = 0; i < enemy.getnum_bombs (); i++)
	      {
		enemy.getbombs (i)->sprite.move (0, 0.3);
		if (monster == false && dragon == false)
		  {
		    window.draw (enemy.getbombs (i)->sprite);
		    if (checkCollisionbomb (p, enemy.getbombs (i)))
		      {
			cout << "bombed" << endl;
			lives = lives - 1;
			cout << lives << endl;
		      }
		  }
	      }


	    // Check for collision between fire and enemy1




	    for (int i = 0; i < p->getnum_bullets (); i++)
	      {
		// window.clear();

		int k = i;
		p->getbullets (i)->sprite.move (0, -7);	// move the bullet up
		window.draw (p->getbullets (i)->sprite);
		// cout << p->getbullets(i)->getPosition().x << ", " << p->getbullets(i)->getPosition().y << endl;
		if (monster == false && dragon == false)
		  {
		    if (checkCollision (p->getbullets (i), &enemy))
		      {

			o = 1;
			count++;
			cout << count << endl;
			r.setScore (20);
		      }
		    if (checkCollision1 (p->getbullets (i), &enemy))
		      {
			o1 = 1;
			count++;
			r.setScore (20);
		      }
		    if (checkCollision2 (p->getbullets (i), &enemy))
		      {
			o2 = 1;
			count++;
			r.setScore (20);
		      }
		    if (checkCollision3 (p->getbullets (i), &enemy))
		      {
			o3 = 1;
			count++;
			r.setScore (20);
		      }
		    if (checkCollision4 (p->getbullets (i), &enemy))
		      {
			o4 = 1;
			count++;
			r.setScore (20);
		      }

		    if (checkCollision5 (p->getbullets (i), &enemy))
		      {


			o5 = 1;
			count++;
			r.setScore (20);
		      }

		    if (level2 == true)
		      {
			if (checkCollision10 (p->getbullets (i), &enemy.beta))
			  {

			    o = 1;
			    count++;
			    cout << count << endl;
			    r.setScore (60);
			  }
			if (checkCollision1 (p->getbullets (i), &enemy.beta))
			  {
			    o1 = 1;
			    count++;
			    r.setScore (60);
			  }
			if (checkCollision2 (p->getbullets (i), &enemy.beta))
			  {
			    o2 = 1;
			    count++;
			    r.setScore (60);
			  }
			if (checkCollision3 (p->getbullets (i), &enemy.beta))
			  {
			    o3 = 1;
			    count++;
			    r.setScore (60);
			  }
			if (checkCollision4 (p->getbullets (i), &enemy.beta))
			  {
			    o4 = 1;
			    count++;
			    r.setScore (60);
			  }

			if (checkCollision5 (p->getbullets (i), &enemy.beta))
			  {


			    o5 = 1;
			    count++;
			    r.setScore (60);
			  }
			if (checkCollision (p->getbullets (i), &enemy.gamma))
			  {
			    r.setScore (90);
			  }
		      }
		    // checkCollision(p->getbullets(k)->sprite , enemy.ene);
		    window.display ();
		    p->speed = 0.75;

		  }
	      }

	    window.clear (Color::Black);	//clears the screen
	    window.draw (background);	// setting background
	    if (lives > 0)
	      {
		if (lives < 3)
		  {
		    cout << "one live lost of 3" << endl;
		    // p->resetPlayer(once);
		    cout << lives << " these are the lives you have remaining"
		      << endl;
		  }
		window.draw (p->sprite);
	      }			// setting player on screen
	    if (lives == 0)
	      {
	      m.endingscreen();
		break;

	      }
	    if (monster != true && dragon != true)
	      {
		if (countofen < 6)
		  {
		    window.draw (enemy.ene);	// draw the enemy sprite

		  }
		if (countofen < 6)
		  {
		    window.draw (enemy.ene1);
		  }

		if (countofen < 6)
		  {
		    window.draw (enemy.ene2);
		  }

		if (countofen < 6)
		  {
		    window.draw (enemy.ene3);
		  }

		if (countofen < 6)
		  {
		    window.draw (enemy.ene4);
		  }

		if (countofen < 6)
		  {
		    window.draw (enemy.ene5);
		  }


	      }
	    cout << "y" << countofen << endl;



	    if (countofen == 6)
	      {
		m.animation ();
		level2 = true;
		p->setPosition (700, 700);
		countofen++;
	      }

	    if (monster != true && dragon != true)
	      {
		if (countofen >= 6)
		  {


		    window.draw (enemy.beta.ene);	// draw the enemy sprite



		    window.draw (enemy.beta.ene1);


		    window.draw (enemy.beta.ene2);


		    window.draw (enemy.beta.ene3);


		    window.draw (enemy.beta.ene4);


		    window.draw (enemy.beta.ene5);


		  }
	      }
	    if (countofen == 22)
	      {
		m.animation ();
		level3 = true;

		countofen++;
	      }


	    if (monster != true && dragon != true)
	      {
	    if (level3 == true || countofen>20)
	      {
		window.draw (enemy.gamma.ene);	// draw the enemy sprite

		window.draw (enemy.gamma.ene1);


		window.draw (enemy.gamma.ene2);


		window.draw (enemy.gamma.ene3);


		window.draw (enemy.gamma.ene4);


		window.draw (enemy.gamma.ene5);

		window.draw (enemy.gamma.ene6);


		window.draw (enemy.gamma.ene7);


		window.draw (enemy.gamma.ene8);


		window.draw (enemy.gamma.ene9);


		window.draw (enemy.gamma.ene10);

		window.draw (enemy.gamma.ene11);
	      }
}
	    window.display ();	//Displying all the sprites
	    oncie++;


	  }
      }
    r.saveScore ();
    cout << r.getScore () << endl;
    //int* topScores =
  }
};


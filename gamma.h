#include<iostream>
using namespace sf;
using namespace std;
class Gamma
{
private:
  Texture en;
  int n;
public:
    Sprite ene;
  Sprite ene1;
  Sprite ene2;
  Sprite ene3;
  Sprite ene4;
  Sprite ene5;
  Sprite ene6;
  Sprite ene7;
  Sprite ene8;
  Sprite ene9;
  Sprite ene10;
  Sprite ene11;

    sf::Texture getTexture () const
  {
    return en;
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
  sf::Vector2f getPosition6 ()
  {
    return ene6.getPosition ();
  }
  sf::Vector2f getPosition7 ()
  {
    return ene7.getPosition ();
  }
  sf::Vector2f getPosition8 ()
  {
    return ene8.getPosition ();
  }
  sf::Vector2f getPosition9 ()
  {
    return ene9.getPosition ();
  }
  sf::Vector2f getPosition10 ()
  {
    return ene10.getPosition ();
  }
  sf::Vector2f getPosition11 ()
  {
    return ene11.getPosition ();
  }



  Gamma ()
  {
    std::srand (std::time (nullptr));
    n = std::rand () % 4;
    if (n == 0)
      {
	n += 1;
      }
    cout << n;
// if(level==2){
    std::srand (std::time (nullptr));
    n = std::rand () % 4;
  //  n = 3;
    if (n == 0)
      {
	n += 1;
      }
    cout << n;
    int m = n;

    en.loadFromFile ("img/enemy_3.png");
    if (n == 1)
      {
	ene.setTexture (en);
	ene.setScale (0.5, 0.5);
	ene.setPosition (150, 100);

	ene1.setTexture (en);
	ene1.setScale (0.5, 0.5);
	ene1.setPosition (250, 100);

	ene2.setTexture (en);
	ene2.setScale (0.5, 0.5);
	ene2.setPosition (350, 100);

	ene3.setTexture (en);
	ene3.setScale (0.5, 0.5);
	ene3.setPosition (450, 100);

	ene4.setTexture (en);
	ene4.setScale (0.5, 0.5);
	ene4.setPosition (150, 200);

	ene5.setTexture (en);
	ene5.setScale (0.5, 0.5);
	ene5.setPosition (250, 200);

	ene6.setTexture (en);
	ene6.setScale (0.5, 0.5);
	ene6.setPosition (350, 200);

	ene7.setTexture (en);
	ene7.setScale (0.5, 0.5);
	ene7.setPosition (450, 200);

	ene8.setTexture (en);
	ene8.setScale (0.5, 0.5);
	ene8.setPosition (150, 300);

	ene9.setTexture (en);
	ene9.setScale (0.5, 0.5);
	ene9.setPosition (250, 300);

	ene10.setTexture (en);
	ene10.setScale (0.5, 0.5);
	ene10.setPosition (350, 300);

	ene11.setTexture (en);
	ene11.setScale (0.5, 0.5);
	ene11.setPosition (450, 300);
      }
    if (n == 2)
      {
	ene.setTexture (en);
	ene.setScale (0.5, 0.5);
	ene.setPosition (300, 100);

	ene1.setTexture (en);
	ene1.setScale (0.5, 0.5);
	ene1.setPosition (200, 200);

	ene2.setTexture (en);
	ene2.setScale (0.5, 0.5);
	ene2.setPosition (400, 200);

	ene3.setTexture (en);
	ene3.setScale (0.5, 0.5);
	ene3.setPosition (100, 300);

	ene4.setTexture (en);
	ene4.setScale (0.5, 0.5);
	ene4.setPosition (200, 300);

	ene5.setTexture (en);
	ene5.setScale (0.5, 0.5);
	ene5.setPosition (300, 200);

	ene6.setTexture (en);
	ene6.setScale (0.5, 0.5);
	ene6.setPosition (400, 300);

	ene7.setTexture (en);
	ene7.setScale (0.5, 0.5);
	ene7.setPosition (500, 300);

	ene8.setTexture (en);
	ene8.setScale (0.5, 0.5);
	ene8.setPosition (300, 300);

	ene9.setTexture (en);
	ene9.setScale (0.5, 0.5);
	ene9.setPosition (200, 400);

	ene10.setTexture (en);
	ene10.setScale (0.5, 0.5);
	ene10.setPosition (300, 400);

	ene11.setTexture (en);
	ene11.setScale (0.5, 0.5);
	ene11.setPosition (400, 400);





      }
    if (n == 3)
      {
	ene.setTexture (en);
	ene.setScale (0.5, 0.5);
	ene.setPosition (100, 100);

	ene1.setTexture (en);
	ene1.setScale (0.5, 0.5);
	ene1.setPosition (200, 200);

	ene2.setTexture (en);
	ene2.setScale (0.5, 0.5);
	ene2.setPosition (400, 200);

	ene3.setTexture (en);
	ene3.setScale (0.5, 0.5);
	ene3.setPosition (500, 100);

	ene4.setTexture (en);
	ene4.setScale (0.5, 0.5);
	ene4.setPosition (200, 300);

	ene5.setTexture (en);
	ene5.setScale (0.5, 0.5);
	ene5.setPosition (300, 300);

	ene6.setTexture (en);
	ene6.setScale (0.5, 0.5);
	ene6.setPosition (400, 300);

	ene7.setTexture (en);
	ene7.setScale (0.5, 0.5);
	ene7.setPosition (100, 400);

	ene8.setTexture (en);
	ene8.setScale (0.5, 0.5);
	ene8.setPosition (500, 400);

	ene9.setTexture (en);
	ene9.setScale (0.5, 0.5);
	ene9.setPosition (300, 200);

	ene10.setTexture (en);
	ene10.setScale (0.5, 0.5);
	ene10.setPosition (100, 250);

	ene11.setTexture (en);
	ene11.setScale (0.5, 0.5);
	ene11.setPosition (500, 250);
      }
  }
//}

};


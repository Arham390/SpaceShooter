#include<iostream> 
using namespace sf;
using namespace std;
class Beta{
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
 sf::Texture getTexture() const {
      return en;
   }
    sf::Vector2f getPosition() { return ene.getPosition(); }
       sf::Vector2f getPosition1() { return ene1.getPosition(); }
      sf::Vector2f getPosition2() { return ene2.getPosition(); }
      sf::Vector2f getPosition3() { return ene3.getPosition(); }
       sf::Vector2f getPosition4() { return ene4.getPosition(); }
          sf::Vector2f getPosition5() { return ene5.getPosition(); }
Beta(){
std::srand(std::time(nullptr));
       n = std::rand() % 4;
       if(n==0){
       n+=1;}
    cout<<n;
// if(level==2){
    std::srand(std::time(nullptr));
       n = std::rand() % 4;
       if(n==0){
       n+=1;}
    cout<<n;
    int m=n;
   
       en.loadFromFile("img/enemy_2.png");
      if(n==1){  
        ene.setTexture(en);
      ene.setScale(1,1);
      ene.setPosition(50,100);
      
        ene1.setTexture(en);
      ene1.setScale(1,1);
      ene1.setPosition(200,0);
     
        ene2.setTexture(en);
      ene2.setScale(1,1);
      ene2.setPosition(150,300);
      
        ene3.setTexture(en);
      ene3.setScale(1,1);
      ene3.setPosition(450,300);
      
        ene4.setTexture(en);
      ene4.setScale(1,1);
      ene4.setPosition(550,100);
      
      ene5.setTexture(en);
      ene5.setScale(1,1);
      ene5.setPosition(400,0);
      
    }
     if(n==2){  
        ene.setTexture(en);
      ene.setScale(1,1);
      ene.setPosition(200,0);
      
        ene1.setTexture(en);
      ene1.setScale(1,1);
      ene1.setPosition(400,0);
     
        ene2.setTexture(en);
      ene2.setScale(1,1);
      ene2.setPosition(100,150);
      
        ene3.setTexture(en);
      ene3.setScale(1,1);
      ene3.setPosition(500,150);
      
        ene4.setTexture(en);
      ene4.setScale(1,1);
      ene4.setPosition(300,300);
      
     
      
    }
     if(n==3){  
       ene.setTexture(en);
ene.setScale(1, 1);
ene.setPosition(100, 0);

ene1.setTexture(en);
ene1.setScale(1, 1);
ene1.setPosition(500, 0);

ene2.setTexture(en);
ene2.setScale(1, 1);
ene2.setPosition(150, 150);

ene3.setTexture(en);
ene3.setScale(1, 1);
ene3.setPosition(450, 150);

ene4.setTexture(en);
ene4.setScale(1, 1);
ene4.setPosition(300, 300);

ene5.setTexture(en);
ene5.setScale(1, 1);
ene5.setPosition(300, 50);

      
    }
    }
//}

};


class Menu{
public:
sf::Sprite sprite;
sf::Texture texture;
Texture obj8;
Texture obj6;
//add menu attributes here
   
Menu()
{
  
             

texture.loadFromFile("img/menu.png");               
sprite.setTexture(texture);
sprite.setPosition(0,0); 				        
                   
//constructors body
}
   sf::Event e;


void mainmenu(sf::Texture obj8)
{

int i=0;
sf::RenderWindow window(sf::VideoMode(320,480), "main menu");
sf::Sprite sprite5;
              sf::Texture texture5;           
              texture5.loadFromFile("img/welcome.png");               
              sprite5.setTexture(texture5);
              sprite5.setPosition(0,0);
              while (window.isOpen()){
              window.clear();
              window.draw(sprite5);
              window.display();
              sf::Event event;
              std::cout<<"press S to start , check terminal"<<std::endl;
               char x='\0';;
               std::cin>>x; 
               if(x=='s'){
               break;}
              while (window.pollEvent(event)){
              if((event.type== sf::Event::Closed))
              break;
              window.close();
              }
           }           
}  



void display_menu(sf::Texture obj4)
{
    sf::RenderWindow window(sf::VideoMode(780, 780), "menu");
  
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
             if (event.key.code == sf::Keyboard::Num1)
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Num2) {
                 help(obj6);
                }
            }
             if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Num3) {
                 sf::RenderWindow window(sf::VideoMode(700,700), "highscores");
                  sf::Sprite sprite;
    sf::Texture texture;
         sf::Sprite sprite1;
    sf::Texture texture1;
          sf::Sprite sprite2;
    sf::Texture texture2;
 texture.loadFromFile("img/badge_1.png");
        sprite.setTexture(texture);
        sprite.setPosition(100,100);
        sprite.setScale(0.5,0.5);
        
          texture1.loadFromFile("img/badge_2.png");
        sprite1.setTexture(texture1);
      
        sprite1.setPosition(300,300);
        sprite1.setScale(0.3,0.3);
        
         texture2.loadFromFile("img/badge_3.png");
        sprite2.setTexture(texture2);
      
        sprite2.setPosition(300,600);
        sprite2.setScale(0.3,0.3);
        
          while (window.isOpen()){
           window.clear();
              window.draw(sprite);
               window.draw(sprite1);
                  window.draw(sprite2);
              window.display();
              sf::Event event;
               std::cout<<"press 2 to return "<<std::endl;
               int x=0;
               std::cin>>x;
               if(x==2){
               break;}
                }
            }
         }   
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Num4) {
                 break;
                }
            }
        }
        window.clear();
        window.draw(sprite);
        window.display();
    }
}

void animation() {
    sf::RenderWindow window(sf::VideoMode(780, 780), "animation");

    sf::Texture texture1;
    texture1.loadFromFile("img/enemy_1.png");
    sf::Sprite sprite1(texture1);
    sprite1.setPosition(0, 300);
    sprite1.setScale(1, 1);

    sf::Texture texture2;
    texture2.loadFromFile("img/enemy_1.png");
    sf::Sprite sprite2(texture2);
    sprite2.setPosition(600, 300);
    sprite2.setScale(1, 1);

    sf::Texture texture3;
    texture3.loadFromFile("img/animation.png");
    sf::Sprite sprite3(texture3);
    sprite3.setScale(2, 2);

    sf::Clock clock;
    const sf::Time animationDuration = sf::seconds(3.0f);

    while (clock.getElapsedTime() < animationDuration) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Num1) {
                    window.close();
                }
            }
        }

        // Move sprite1 and sprite2
        sprite1.move(3, 0);
        sprite2.move(-3, 0);

        window.clear();

        // Draw sprite3 as a background
        window.draw(sprite3);

        // Draw sprite1 and sprite2 on top of the background
        if (sprite1.getPosition().x <= 300 && sprite1.getPosition().y <= 300) {
            // Code to be executed if sprite1's position is less than or equal to (300, 300)
            window.draw(sprite1);
        }
            if (sprite1.getPosition().x <= 300 && sprite1.getPosition().y <= 300) {
        window.draw(sprite2);
}
        window.display();

        // Pause for a short amount of time to control the movement speed
        sf::sleep(sf::milliseconds(10));
    }

    window.close(); // Close the window after the animation duration
}




void pause(){
bool p=true;

}
void help(sf::Texture obj6)
{
sf::RenderWindow window(sf::VideoMode(700,700), "help");
 sf::Sprite sprite;
              sf::Texture texture;           
              texture.loadFromFile("img/controls.png");               
              sprite.setTexture(texture);
              sprite.setPosition(0,0);
              while (window.isOpen()){
              window.clear();
              window.draw(sprite);
              window.display();
              sf::Event event;
               std::cout<<"press 2 to return "<<std::endl;
               int x=0;
               std::cin>>x;
               if(x==2){
               break;}
              while (window.pollEvent(event)){
              if((event.type== sf::Event::Closed)){
              window.close();
                      }
              }
           }   
 }    
 
 
 void endingscreen()
{
sf::RenderWindow window(sf::VideoMode(320,480), "ending");
sf::Sprite sprite;
              sf::Texture texture;           
              texture.loadFromFile("img/gameover.png");               
              sprite.setTexture(texture);
              sprite.setPosition(0,0);
              while (window.isOpen()){
              window.clear();
              window.draw(sprite);
              window.display();
              sf::Event event;
              
              while (window.pollEvent(event)){
              if((event.type== sf::Event::Closed))
              window.close();
              }
           }  
 }
 
};

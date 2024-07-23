#include<iostream>
#include <fstream>
#include <string>
using namespace std;
class Record
{
private:
    int score;
    string name;
    std::string fileName;

public:
 sf::Sprite sprite;
    sf::Texture texture;
      
Record(){


    
      texture.loadFromFile("img/badge_1.png");
        sprite.setTexture(texture);
        sprite.setPosition(600,700);
        sprite.setScale(0.09,0.09);
//        Velocity = sf::Vector2f(0, 0.25);
  
}
const int MAX_BADGES = 3;
   
    Record(std::string name) : fileName(name) {}

    int getScore() const { return score; }
    void setScore(int s) { score = score +s; }
    void setName(string s){
    
    name=s;
    }

    int saveScore()
    {
        std::ofstream outFile("record.txt", std::ios::app);
        if (!outFile)
        {
            return -1; // Error opening file
        }
        outFile <<name<<" "<<score<<endl;
        outFile.close();
        return 0;
    }



};


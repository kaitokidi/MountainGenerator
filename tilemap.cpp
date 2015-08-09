#include <vector>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main() {

    
    sf::Vector2i max;
    std::cin >> max.x >> max.y;
    std::vector < std::vector < int > > matrix (max.y, std::vector <int> (max.x));

    for(int y = 0; y < max.y; ++y){
        for(int x = 0; x < max.x; ++x){
            std::cin >> matrix[y][x];
        }
    }
    
    sf::Texture text;
    sf::Sprite* sprite;
    if(! text.loadFromFile("spritescolors.png")) std::cout << "not loaded" << std::endl;

    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Landscape <3", sf::Style::Resize|sf::Style::Close);
        
    std::vector < sf::Sprite > sprites(10);
    for(int i = 0; i < 10; ++i){
            sprites[i].setTexture(text);
            sprites[i].setTextureRect(sf::IntRect(i*100,0,100,100));
            sprites[i].setScale(window.getSize().y/max.y/sprites[i].getLocalBounds().height,window.getSize().y/max.y/sprites[i].getLocalBounds().height);
    }

    //GAME LOOP
    while(window.isOpen()){

        sf::Event event;
        while(window.pollEvent(event)){
            switch (event.type){
                //Close event
                case sf::Event::Closed:
                    window.close();
                    break;
                //KeyPressed event
                case  sf::Event::KeyPressed:
                    //Close key
                    if (event.key.code == sf::Keyboard::Escape) {
                        window.close();
                    }
                    if (event.key.code == sf::Keyboard::Q) {
                        window.close();
                    }
                    
                    break;
               case sf::Event::Resized:
                    for(int i = 0; i < 10; ++i){
                        sprites[i].setScale(window.getSize().y/max.y/sprites[i].getLocalBounds().height,window.getSize().y/max.y/sprites[i].getLocalBounds().height);
                    }
                    break;
                default:
                    //Do nothing
                    break;
            }
        }   
            
        window.clear();
        for(int y = 0; y < max.y; ++y){
            for(int x = 0; x < max.x; ++x){
                sprite = &sprites[matrix[y][x]];
                sprite->setPosition(x*sprite->getGlobalBounds().width,y*sprite->getGlobalBounds().height);                
                window.draw(*sprite);
            }
        }
        window.display();      
        //g++ -c tilemap.cpp;    g++ -o mapa tilemap.o -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network; ./exe | ./mapa;

    }
}    
    
    
    
    
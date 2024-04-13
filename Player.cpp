#include <SFML/Graphics.hpp>
#include <iostream>
class Player {
public:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f velocity;
    sf::Texture front;
    sf::Texture back;
    sf::Texture left;
    sf::Texture left2;
    sf::Texture right;
    sf::Texture right2;
    int stepCount = 0;
    Player() {
        if (!texture.loadFromFile("cat.png")) {
            std::cerr << "Failed to load player texture!" << std::endl;
        }
        if (!left.loadFromFile("cat1l.png")) {
            std::cerr << "Failed to load player texture!" << std::endl;
        }
        if (!right.loadFromFile("cat1.png")) {
            std::cerr << "Failed to load player texture!" << std::endl;
        }
        if (!front.loadFromFile("cat_a1.png")) {
            std::cerr << "Failed to load player texture!" << std::endl;
        }
        if (!back.loadFromFile("cat_b.png")) {
            std::cerr << "Failed to load player texture!" << std::endl;
        }
        if (!right2.loadFromFile("cat2.png")) {
            std::cerr << "Failed to load player texture!" << std::endl;
        }
        if (!left2.loadFromFile("cat2l.png")) {
            std::cerr << "Failed to load player texture!" << std::endl;
        }
        sprite.setTexture(texture);
        sprite.setPosition(100, 100); // Starting position
        velocity.x = 0;
        velocity.y = 0;
    }

    sf::Texture * changeLeft(){
        if(sprite.getTexture() == &left){
            return &left2;
        }else{
            return &left;
        }
    }

    sf::Texture * changeRight(){
        if(sprite.getTexture() == &right){
            return &right2;
        }else{
            return &right;
        }
    }

    void draw(sf::RenderWindow& window) {

        window.draw(sprite);
    }

    void move(float offsetX, float offsetY) {
        stepCount++;
        if(offsetY == -1){
            sprite.setTexture(back);
        }
        if(offsetY == 1){
            sprite.setTexture(front);
        }
        if(offsetX == -1){
            sf::Texture *l = &left;
            if(stepCount%4 == 0){
                l = changeLeft();
            }
            sprite.setTexture(*l);
        }
        if(offsetX == 1){
            sf::Texture *r = &right;
            if(stepCount%4 == 0){
                r = changeRight();
            }
            sprite.setTexture(*r);
        }
        sprite.move(offsetX * 5.0f, offsetY * 5.0f);

    }

    sf::Vector2f getPosition() {
        return sprite.getPosition();
    }
};

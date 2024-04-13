#include <SFML/Graphics.hpp>
#include <iostream>

class Item {
public:
    sf::Sprite sprite;
    bool collected;
    bool isItFood;
    sf::Texture foodTexture;
    sf::Texture trashTexture;

    Item(float x, float y, bool foodBool) : collected(false), isItFood(foodBool) {
        if (!foodTexture.loadFromFile("food.png")) {
            std::cerr << "Failed to load food texture!" << std::endl;
        }
        if (!trashTexture.loadFromFile("trashcan.png")) {
            std::cerr << "Failed to load trash texture!" << std::endl;
        }
        sprite.setPosition(x, y);
        setTexture();
    }

    void setTexture() {
        sprite.setTexture(isItFood ? foodTexture : trashTexture);
    }

    void draw(sf::RenderWindow& window) const {
        window.draw(sprite);
    }
};


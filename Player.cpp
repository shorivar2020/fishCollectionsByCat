#include <SFML/Graphics.hpp>
#include <iostream>
class Player {
public:
    sf::Sprite sprite;
    sf::Vector2f velocity;
    sf::Texture texture;
    sf::Texture frontTexture;
    sf::Texture backTexture;
    sf::Texture leftTexture;
    sf::Texture left2Texture;
    sf::Texture rightTexture;
    sf::Texture right2Texture;
    int stepCount = 0;

    Player() {
        loadTextures();
        setupSprite();
    }

    void loadTextures() {
        if (!texture.loadFromFile("cat.png") ||
            !frontTexture.loadFromFile("cat_a1.png") ||
            !backTexture.loadFromFile("cat_b.png") ||
            !leftTexture.loadFromFile("cat1l.png") ||
            !left2Texture.loadFromFile("cat2l.png") ||
            !rightTexture.loadFromFile("cat1.png") ||
            !right2Texture.loadFromFile("cat2.png")) {
            std::cerr << "Failed to load player textures!" << std::endl;
        }
    }

    void setupSprite() {
        sprite.setTexture(texture);
        sprite.setPosition(100, 100); // Starting position
        sprite.setOrigin(texture.getSize().x / 2.0f, texture.getSize().y / 2.0f); // Center the origin
        velocity.x = 0;
        velocity.y = 0;
    }

    sf::Texture* changeLeft() {
        return (sprite.getTexture() == &leftTexture) ? &left2Texture : &leftTexture;
    }

    sf::Texture* changeRight() {
        return (sprite.getTexture() == &rightTexture) ? &right2Texture : &rightTexture;
    }

    void draw(sf::RenderWindow& window) const {
        window.draw(sprite);
    }

    void move(float offsetX, float offsetY) {
        stepCount++;
        if (offsetY == -1) {
            sprite.setTexture(backTexture);
        } else if (offsetY == 1) {
            sprite.setTexture(frontTexture);
        } else if (offsetX == -1) {
            sprite.setTexture(*changeLeft());
        } else if (offsetX == 1) {
            sprite.setTexture(*changeRight());
        }
        sprite.move(offsetX * 5.0f, offsetY * 5.0f);
    }
};

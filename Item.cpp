//
// Created by User on 4/13/2024.
//

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

enum Color {
    White,
    Blue,
    Red,
    Green,
};

class Item {
public:
    sf::CircleShape shape;
    bool collected;
    int id;
    Color color;

    Item(float x, float y, int itemId, int note) : id(itemId) {
        shape.setRadius(10);
        if (note == 1) {
            shape.setFillColor(sf::Color::Blue);
        }
        else if (note == 2) {
            shape.setFillColor(sf::Color::Red);
        }
        else if (note == 3) {
            shape.setFillColor(sf::Color::Green);
        }
        else {
            shape.setFillColor(sf::Color::White);
        }
        shape.setPosition(x, y);
        collected = false;
    }
};
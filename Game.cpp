#include <SFML/Graphics.hpp>
#include "Player.cpp"
#include "Item.cpp"

class Game {
public:
    static const int WIDTH = 1200;
    static const int HEIGHT = 600;
    std::vector<Item> items;
    Player player;
    sf::RenderWindow window;
    sf::Sprite sprite;

//    Game() : window(sf::VideoMode(WIDTH, HEIGHT), "SFML Game"), collectedCount(0) {
//        player = Player();
//        initializeItems();
//    }

    void initializeItems() {
        // Initialize items at random positions
        for (int i = 0; i < 5; ++i) {
            float x = static_cast<float>(rand() % WIDTH);
            float y = static_cast<float>(rand() % HEIGHT);
            items.push_back(Item(x, y, i + 1, i+1)); // i + 1 is the unique identifier
        }
    }

    void run() {
        window.create(sf::VideoMode(800, 600), "Simple Game");
        window.setFramerateLimit(60);

        while (window.isOpen()) {
            processEvents();
            window.clear();
            player.draw(window);
            window.display();
        }
    }

    void processEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            player.move(0, -1); // Move up
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            player.move(0, 1); // Move down
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            player.move(-1, 0); // Move left
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            player.move(1, 0); // Move right
        }
    }
};
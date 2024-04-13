#include <SFML/Graphics.hpp>
#include <fstream>
#include "Player.cpp"
#include "Item.cpp"

class Game {
public:
    static const int WIDTH = 1200;
    static const int HEIGHT = 600;
    static const int FRAMERATE = 30;
    const std::string GAME_NAME = "FishCollector";
    const std::string WIN_MESSAGE = "Congratulations! You won!";;
    const std::string LOSE_MESSAGE = "You lose!";
    std::vector<Item> items;
    Player player;
    sf::RenderWindow window;
    sf::Sprite sprite;
    int collectedFood = 0;

    void initializeItems() {
        // Initialize items at random positions
        for (int i = 0; i < 5; ++i) {
            auto x = static_cast<float>(rand() % WIDTH);
            auto y = static_cast<float>(rand() % HEIGHT);
            bool isFood = (rand() % 2 == 0);
            items.emplace_back(x, y, isFood);
        }
    }

    void processEvents() {
        sf::Event event{};
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

    void checkBoundaryExceedance(){
        if (player.sprite.getPosition().x < 0)
            player.sprite.setPosition(0, player.sprite.getPosition().y);
        if (player.sprite.getPosition().x + player.sprite.getGlobalBounds().width > WIDTH)
            player.sprite.setPosition(WIDTH - player.sprite.getGlobalBounds().width, player.sprite.getPosition().y);
        if (player.sprite.getPosition().y < 0)
            player.sprite.setPosition(player.sprite.getPosition().x, 0);
        if (player.sprite.getPosition().y + player.sprite.getGlobalBounds().height > HEIGHT)
            player.sprite.setPosition(player.sprite.getPosition().x, HEIGHT - player.sprite.getGlobalBounds().height);
    }

    void resetGame() {
        collectedFood = 0;
        items.clear();
        initializeItems();
        player.sprite.setPosition(100, 30);
    }

    void update(){
        processEvents();
        //Check player interactions with items
        for (size_t i = 0; i < items.size(); ++i) {
            if (!items[i].collected && player.sprite.getGlobalBounds().intersects(items[i].sprite.getGlobalBounds())) {
                items[i].collected = true;
                if(items[i].isItFood){
                    collectedFood--;
                }else{
                    std::cout << LOSE_MESSAGE << std::endl;
                    resetGame();
                }
                if(collectedFood == 0){
                    std::cout << WIN_MESSAGE << std::endl;
                    resetGame();
                }
            }
        }
        checkBoundaryExceedance();
    }

    void render(){
        window.clear();
        //Display background
        sf::Texture backgroundTexture;
        if (backgroundTexture.loadFromFile("grass.png")) {
            sf::Sprite backgroundSprite(backgroundTexture);
            backgroundSprite.setScale(window.getSize().x / backgroundSprite.getLocalBounds().width,
                                      window.getSize().y / backgroundSprite.getLocalBounds().height);
            window.draw(backgroundSprite);
        }else{
            std::cerr << "Failed to load player texture!" << std::endl;
        }
        //Display items
        for (size_t i = 0; i < items.size(); ++i) {
            if(!items[i].collected){
                items[i].setTexture();
                items[i].draw(window);
            }
        }
        //Display player
        player.draw(window);
        window.display();
    }

    void run() {
        window.create(sf::VideoMode(WIDTH, HEIGHT), GAME_NAME);
        initializeItems();
        window.setFramerateLimit(FRAMERATE);
       while (window.isOpen()) {
            update();
            render();
        }
    }
};

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

// A script to paint a tile on a grid
int main() {
    // Window init
    srand(time(NULL));
    RenderWindow window(VideoMode(320, 320), "Pruebas en SFML");
    window.setFramerateLimit(60);

    // Init objects
    RectangleShape tiles[8][8];
        // Tiles init
        int posx = 0;
        int posy = 0;
        for(int x = 0; x < 8; x++) {
            for(int y = 0; y < 8; y++) {
                tiles[x][y].setSize(Vector2f(39, 39));
                tiles[x][y].setFillColor(Color::White);
                tiles[x][y].setPosition(posx, posy);
                posx += 40;
            }
            posx = 0;
            posy +=40;
        }

    // Window run
    while(window.isOpen()) {
        Event event;
        while(window.pollEvent(event)) {
            // Close window : end app
            if(event.type == Event::Closed) {
                window.close();
            }
        }

        if(Mouse::isButtonPressed(Mouse::Left)) {
            // Escuchadores
            Vector2i mousePos = sf::Mouse::getPosition( window );
            Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );
            std::cout << "X: " << mousePos.x << " Y: " << mousePos.y << std::endl;
            for(int x = 0; x < 8; x++) {
                for(int y = 0; y < 8; y++) {
                    if (tiles[x][y].getGlobalBounds().contains(mousePosF)) {
                        tiles[x][y].setFillColor(Color::Green);
                    }
                }
            }
        }
        // Clean window
        window.clear(Color::Magenta);

        // Draw
        for(int x = 0; x < 8; x++) {
            for(int y = 0; y < 8; y++) {
                window.draw(tiles[x][y]);
            }
        }

        // Final display
        window.display();
    }
    return EXIT_SUCCESS;
}

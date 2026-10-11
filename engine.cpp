#include <SFML/Graphics.hpp>
#include <vector>    

int main() {
    // Opens a fresh window (800x600 pixels)
    sf::RenderWindow window(sf::VideoMode({800, 600}), "test no 3");

    // styling my circle here
         sf::CircleShape Triangle(50.f);
            Triangle.setPointCount(3); 
             Triangle.setFillColor(sf::Color(0, 255, 255));
            Triangle.setPosition({350.f, 250.f});

        // the bullet
        std::vector<sf::CircleShape> bullets;

    // Loop
    while (window.isOpen()) {   
        //  window events (like clicking the close X)
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            // the bullet trigger btn
            if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (mousePressed->button == sf::Mouse::Button::Left) {
                    //white bullet

                    sf::CircleShape newBullet(5.f);
                    newBullet.setFillColor(sf::Color(255, 255, 255));

                    //this spams it at the triangle positon i just made
                    newBullet.setPosition(Triangle.getPosition());

                    // and creates a magazine 
                    bullets.push_back(newBullet);
                }
            }
        } // 🟢 The event loop now correctly closes AFTER checking for the right-click!

        // adding movments 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
            Triangle.move({1.f, 0.f}); //this goes right
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
            Triangle.move({-1.f, 0.f}); //this goes left
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
            Triangle.move({0.f, -1.f}); //this goes up
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
            Triangle.move({0.f, 1.f}); //this goes down
        }
        // adding other stuff
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
            Triangle.setFillColor(sf::Color(255, 0, 128));
        }else{
            Triangle.setFillColor(sf::Color::Cyan);
        }

        // update bullets position
        for (auto& bullet : bullets) {
            bullet.move({0.f, -5.f});
        }

        // bgc
        window.clear(sf::Color(0, 0, 0));
        
            window.draw(Triangle);

            // draw all active bullets
            for (const auto& bullet : bullets) {
                window.draw(bullet);
            }

            window.display();
    }

    return 0;
}

//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// In order to load the resources like background.png, you have to set up
// your target scheme:
//
// - Select "Edit Scheme…" in the "Product" menu;
// - Check the box "use custom working directory";
// - Fill the text field with the folder path containing your resources;
//        (e.g. your project folder)
// - Click OK.
//

#include <SFML/Graphics.hpp>

#include <SFML/Audio.hpp>

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML window");

    // Set the Icon
    const auto icon = sf::Image::loadFromFile("icon.png").value();
    window.setIcon(icon);

    // Load a sprite to display
    const auto texture = sf::Texture::loadFromFile("background.jpg").value();
    sf::Sprite sprite(texture);

    // Create a graphical text to display
    const auto font = sf::Font::loadFromFile("tuffy.ttf").value();
    sf::Text   text(font, "Hello SFML", 50);
    text.setFillColor(sf::Color::Black);

    // Load a music to play
    sf::Music music;
    if (!music.openFromFile("doodle_pop.ogg"))
    {
        return EXIT_FAILURE;
    }

    // Play the music
    music.play();

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        while (const std::optional event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
            {
                window.close();
                break;
            }

            // Escape pressed: exit
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>();
                keyPressed && keyPressed->code == sf::Keyboard::Key::Escape)
            {
                window.close();
                break;
            }
        }

        // Clear screen
        window.clear();

        // Draw the sprite
        window.draw(sprite);

        // Draw the string
        window.draw(text);

        // Update the window
        window.display();
    }
}

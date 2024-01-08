#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Nube
{
public:
    Nube(sf::Vector2f position, sf::Color color)
    {
        shape.setSize(sf::Vector2f(25, 25));
        shape.setPosition(position); // Posición inicial cuadro
        shape.setFillColor(color);
        if (!texture.loadFromFile("./assets/images/nube.png"))
        {
        }
        this->sprite = sf::Sprite(texture);
        this->sprite.setPosition(position); // Posición inicial sprite
    }
    void move(float offsetX, float offsetY)
    {
        sprite.move(offsetX, offsetY);
        shape.move(offsetX, offsetY);
    }
    void draw(sf::RenderWindow &window)
    {
        window.draw(this->shape);
        window.draw(this->sprite);
    }
    void update()
    {
        if (clock.getElapsedTime().asSeconds() >= frameTime)
        {
            currentFrame = (currentFrame + 1) % numFrames;
            sprite.setTextureRect(sf::IntRect((currentFrame * 10), 0, 860, 360));
            clock.restart();
        }
    }

private:
    sf::RectangleShape shape;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock clock;
    float frameTime = 0.1f; // Tiempo entre cada frame en segundos
    int currentFrame = 0;
    int numFrames = 4; // Número total de frames en la animación
    int frameWidth = 860;
    int frameHeight = 360;
};
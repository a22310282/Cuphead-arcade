#include <Cuphead.hpp>
#include <Mugman.hpp>
#include <Hilda.hpp>
#include <Nube.hpp>
#include <Mapa.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

double velocidad = 0.1;
int main()
{
    int position;
    Hilda hilda(sf::Vector2f(50, 103), sf::Color::Black);
    Cuphead cuphead(sf::Vector2f(3, 445), sf::Color::Red);
    Mugman mugman(sf::Vector2f(20, 445), sf::Color::Blue);
    Mapa map(sf::Vector2f(50, 103), sf::Color::Red);
    sf::Texture texture;
    if (!texture.loadFromFile("./assets/images/mapac.png"))
    {
        // Manejar el error si no se puede cargar la imagen
        return -1;
    }
    // Crear un sprite y asignarle la textura
    sf::Sprite sprite(texture);

    sf::Music music;
    if (!music.openFromFile("./assets/music/theme.ogg"))
    {
        // Error al cargar el archivo de música
        return -1;
    }

    // Reproducir la música
    music.play();

    sf::RenderWindow window(sf::VideoMode(1280, 720), "CUPHEAD ARCADE");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            hilda.move(velocidad * -1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            hilda.move(velocidad, 0);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            cuphead.move(velocidad * -1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            cuphead.move(velocidad, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            cuphead.move(0, velocidad * -1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            cuphead.move(0, velocidad);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
        {
            mugman.move(velocidad * -1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
        {
            mugman.move(velocidad, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
        {
            mugman.move(0, velocidad * -1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
        {
            mugman.move(0, velocidad);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
        {
            map.move(0, velocidad);
        }
        // Actualizar animacion
        hilda.update();
        cuphead.update();
        mugman.update();
        map.update();

        window.clear();
        window.draw(sprite);
        hilda.draw(window);
        cuphead.draw(window);
        mugman.draw(window);
        map.draw(window);
        // window.draw(text2);
        window.display();

        if (music.getStatus() != sf::Music::Playing)
        {
            window.close();
        }
    }

    return 0;
}
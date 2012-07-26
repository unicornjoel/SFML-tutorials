#include <SFML/Graphics.hpp>

int main ()
{
	sf::RenderWindow window(sf::VideoMode(300,200), "SFML works!");
	sf::Text text("Hello World!");

	while(window.isOpen())
	{
		sf::Event sfmlevent;
		while(window.pollEvent(sfmlevent))
		{
			if (sfmlevent.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(text);
		window.display();
	}

	return (0);
}
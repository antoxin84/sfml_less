#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{
	RenderWindow window(VideoMode(640, 480), "Lesson");
	Image heroImage; // создание объекта Image (изображение)
	heroImage.loadFromFile("img/hero.png"); //загружаем в него файл
	Texture heroTexture; //создание объекта Texture(текстура)
	heroTexture.loadFromImage(heroImage);// передаём в него объект heroImage
	Sprite heroSprite; //создаём объект Sprite(спрайт)
	heroSprite.setTexture(heroTexture);//передаём в него объект Texture (текстуры)
	heroSprite.setPosition(50, 25);//задаём координаты появления спрайта
	

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(heroSprite);
		window.display();
	}

	return 0;
}
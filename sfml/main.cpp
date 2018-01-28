#include <SFML/Graphics.hpp>
//#include <iostream> 
using namespace sf;
int main()
{
	Clock clock;//создаем переменную времени, т.о. прив€зка ко времени(а не загруженности/мощности процессора)
	RenderWindow window(VideoMode(640, 480), "Lesson");
	Image heroImage; // создание объекта Image (изображение)
	heroImage.loadFromFile("img/hero.png"); //загружаем в него файл
	Texture heroTexture; //создание объекта Texture(текстура)
	heroTexture.loadFromImage(heroImage);// передаЄм в него объект heroImage
	Sprite heroSprite; //создаЄм объект Sprite(спрайт)
	heroSprite.setTexture(heroTexture);//передаЄм в него объект Texture (текстуры)
	heroSprite.setPosition(50, 25);//задаЄм координаты по€влени€ спрайта
	heroSprite.setTextureRect(IntRect(0,192,96,96)); // ѕолучили нужный пр€моугольник с котом
	

	///////////////////////////////////////////////////////////////////////////////////

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();// дать прошедее врем€€ в микросекундах
		clock.restart();//перегружаем врем€
		time = time / 800; //скорость игры
		
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left)||(Keyboard::isKeyPressed(Keyboard::A))) { heroSprite.move(-0.1*time, 0); heroSprite.setTextureRect(IntRect(0, 96, 96, 96)); }//координата Y, на которой герой изображен идущим влево равна 96
		if (Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D))){ heroSprite.move(0.1*time, 0); heroSprite.setTextureRect(IntRect(0, 192, 96, 96)); } //координата Y, на которой герой изображен идущем вправо равна 96+96=192
		if (Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W))) { heroSprite.move(0,-0.1*time); heroSprite.setTextureRect(IntRect(0, 288, 96, 96)); }//координата Y на которой герой изображен идущим вверх равна 288
		if (Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S))) { heroSprite.move(0,0.1*time); heroSprite.setTextureRect(IntRect(0, 0, 96, 96)); } //координата 0, это верхн€€ часть изображени€ с героем, от нее и отталкиваемс€ ровными квадратиками по 96. 
		window.clear();
		window.draw(heroSprite);
		window.display();
	}

	return 0;
}
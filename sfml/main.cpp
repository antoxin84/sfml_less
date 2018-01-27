#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{
	RenderWindow window(VideoMode(640, 480), "Lesson");
	Image heroImage; // �������� ������� Image (�����������)
	heroImage.loadFromFile("img/hero.png"); //��������� � ���� ����
	Texture heroTexture; //�������� ������� Texture(��������)
	heroTexture.loadFromImage(heroImage);// ������� � ���� ������ heroImage
	Sprite heroSprite; //������ ������ Sprite(������)
	heroSprite.setTexture(heroTexture);//������� � ���� ������ Texture (��������)
	heroSprite.setPosition(50, 25);//����� ���������� ��������� �������
	

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
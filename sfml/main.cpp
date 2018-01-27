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
	heroSprite.setTextureRect(IntRect(0,192,96,96)); // �������� ������ ������������� � �����
	

	///////////////////////////////////////////////////////////////////////////////////

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left)||(Keyboard::isKeyPressed(Keyboard::A))) { heroSprite.move(-0.1, 0); heroSprite.setTextureRect(IntRect(0, 96, 96, 96)); }//���������� Y, �� ������� ����� ��������� ������ ����� ����� 96
		if (Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D))){ heroSprite.move(0.1, 0); heroSprite.setTextureRect(IntRect(0, 192, 96, 96)); } //���������� Y, �� ������� ����� ��������� ������ ������ ����� 96+96=192
		if (Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W))) { heroSprite.move(0,-0.1); heroSprite.setTextureRect(IntRect(0, 288, 96, 96)); }//���������� Y �� ������� ����� ��������� ������ ����� ����� 288
		if (Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S))) { heroSprite.move(0,0.1); heroSprite.setTextureRect(IntRect(0, 0, 96, 96)); } //���������� 0, ��� ������� ����� ����������� � ������, �� ��� � ������������� ������� ������������ �� 96. 
		window.clear();
		window.draw(heroSprite);
		window.display();
	}

	return 0;
}
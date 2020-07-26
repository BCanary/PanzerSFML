/*
� ��������� ������� � C++/C � ������� ����� ����������� ���� � "�������������� �������� ����������" SFML/include;
� ������������ - �����, ���� "�������������� �������� ���������" SFML/lib;
� ������������ - ����, ����������� ������������ lib ����� � �������������� �����������, � Release � Debug � ������ -d
������ ����� � ����� NameOfProject/Debug ����� �� SFML/bin, openal32 � ��� � ��������� -d. � Release ��� ��� �������� -d � openal32
*/

#include <iostream>
#include <SFML/Graphics.hpp> // ���������� ����������� ���������� SFML
#include "loadTextures.h"

using namespace std;
using namespace sf; // ���������� ���� ���� sf, ����� �� ������ ������ ��� sf::

void draw(RenderWindow &window) { // �������� ������ ��� ���� ����

	/*
	CircleShape circle(50.0f); // ���� �������� 50 ��������
	circle.setFillColor(Color(100, 0, 0)); // ��������� ���� ������������ ������
	window.draw(circle); // ������ ����
	*/
	//system("dir"); // �����
	//Texture TEXTURE_TILES1;
	//Sprite SPRITE_GROUND_SAND;
	//TEXTURE_TILES1.loadFromFile("tiles1.png");

	//SPRITE_GROUND_SAND.setTexture(TEXTURE_TILES1); // ��������, ��� ���������� ������ �������� ���
	//SPRITE_GROUND_SAND.setTextureRect(IntRect(27, 3, 20, 16));
}

int main() {
	loadTexturesAndSprites(); // ��������� ��������

	RenderWindow window(VideoMode(800, 600), "PanzerSFML debugging"); // ��������� ���� � �������� 800 �� 600 � ������

	while (window.isOpen()) { // ���� ���� �������, �������� �������� ���� �������� � false

		Event event; // ������� ������ �����, �����, ����� ��������� � pollEvent, � ���� ����� ������������ ������
		while (window.pollEvent(event)) { // ���� ����������� �� ���� ������� ���� �� ������ ������ ( ������� � �.� )

			if (event.type == Event::Closed) { // ���� ����� ����� ��������
				window.close(); // ��������� ����
			}
		}

		window.clear(Color(250, 220, 100, 0)); // ������� �������� ��� ���� ������������ ������ rgba

		draw(window); // ������ ������� � ������, ��������� �������� ��� ������� ����������, �������� ����

		window.display(); // ������ ����
	}

}
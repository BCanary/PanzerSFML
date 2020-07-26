/*
В свойствах проекта в C++/C в разделе общее прописываем путь к "дополнительные каталоги включаемых" SFML/include;
В компоновщике - общее, путь "дополнительные каталоги библиотек" SFML/lib;
В компоновщике - ввод, прописываем подключаемые lib файлы в дополнительные зависимости, в Release и Debug с чертой -d
Кидаем файлы в папку NameOfProject/Debug файлы из SFML/bin, openal32 и все с припиской -d. В Release все без приписки -d и openal32
*/

#include <iostream>
#include <SFML/Graphics.hpp> // Подключаем графическую библиотеку SFML
#include "loadTextures.h"

using namespace std;
using namespace sf; // Используем поле имен sf, чтобы не писать каждый раз sf::

void draw(RenderWindow &window) { // Получаем ссылку наа наше окно

	/*
	CircleShape circle(50.0f); // Круг радиусом 50 пикселей
	circle.setFillColor(Color(100, 0, 0)); // Заполняем круг определенным цветом
	window.draw(circle); // Рисуем круг
	*/
	//system("dir"); // Дебаг
	//Texture TEXTURE_TILES1;
	//Sprite SPRITE_GROUND_SAND;
	//TEXTURE_TILES1.loadFromFile("tiles1.png");

	//SPRITE_GROUND_SAND.setTexture(TEXTURE_TILES1); // Работает, при объявлении данной текстуры тут
	//SPRITE_GROUND_SAND.setTextureRect(IntRect(27, 3, 20, 16));
}

int main() {
	loadTexturesAndSprites(); // Загружаем текстуры

	RenderWindow window(VideoMode(800, 600), "PanzerSFML debugging"); // Объявляем окно с размером 800 на 600 и именем

	while (window.isOpen()) { // Пока окно открыто, очевидно закрытие окна приведет к false

		Event event; // Создаем пустой евент, далее, через указатель в pollEvent, в него будут записываться данный
		while (window.pollEvent(event)) { // Цикл прохождения по всем эвентам окна на данный момент ( нажатия и т.п )

			if (event.type == Event::Closed) { // Если евент равен закрытию
				window.close(); // Закрываем окно
			}
		}

		window.clear(Color(250, 220, 100, 0)); // Очищаем заливкой все окно определенным цветом rgba

		draw(window); // Рисуем объекты и прочее, отдельной функцией для большей читаемости, передаем окно

		window.display(); // Рисуем окно
	}

}
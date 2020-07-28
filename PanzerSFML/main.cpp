/*
В свойствах проекта в C++/C в разделе общее прописываем путь к "дополнительные каталоги включаемых" SFML/include;
В компоновщике - общее, путь "дополнительные каталоги библиотек" SFML/lib;
В компоновщике - ввод, прописываем подключаемые lib файлы в дополнительные зависимости, в Release и Debug с чертой -d
Кидаем файлы в папку NameOfProject/Debug файлы из SFML/bin, openal32 и все с припиской -d. В Release все без приписки -d и openal32
*/

#include <iostream>
#include <SFML/Graphics.hpp> // Подключаем графическую библиотеку SFML
#include "Engine.h"

//TODO: Добавить карту, отрисовку карты, добавить больше объектов, перемещение и масштабирование карты (СДЕЛАНО), класс танка, 
//		класс игры, класс интерфейса,перемещение по клику,нарисовать больше текстур земли, декорации (СДЕЛАНО), текстуры интерфейса, пиксельный шрифт
//	    XML карты, map editor, перевод на разные языки, игровую логику


const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;

RenderWindow game_window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game");
//View game_view(FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));

Engine engine(game_window);

int main() {
	engine.start();
}
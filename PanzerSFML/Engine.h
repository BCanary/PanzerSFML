#pragma once
#include <SFML/Graphics.hpp>
#include "SpriteManager.h"
#include "DecorationManager.h"
//#include <thread>

using namespace sf;

class Engine {
public:
	Engine(RenderWindow &window); // Конструктор игрового движка

	void start(); // Запустить игровой движок

	void cameraMoveTo(int x, int y); // Передвинуть камеру на координаты

	int old_camera_x = 0; // Икс игровой камеры
	int old_camera_y = 0;

	int camera_x = 0; // Икс игровой камеры
	int camera_y = 0; // Игрик игровой камеры

	RenderWindow* getRenderWindow(); // Получить игровое окно указателем
	SpriteManager& getSpriteManager(); // Получить адрес менеджера спрайтов
	DecorationManager& getDecorationManager(); // Получить адрес менеджера декораций
private:
	Clock clock_delta_time; // Таймер, для просчета дельты времени
	float delta_time = 0; // Время потраченное на логику и отрисовку

	float world_scale = 5; // Приближение всех объектов
	float gui_scale = 1; // Приближение интерфейса

	int mouse_x = 0;
	int mouse_y = 0;

	int mouse_click_x = 0;
	int mouse_click_y = 0;

	Clock clock_left_mouse_hold; // Таймер, сколько времени, удерживалось ЛКМ
	//std::thread thread_left_mouse_hold;
	int time_left_mouse_hold = 0; // Сколько времени держалось ЛКМ
	bool is_left_mouse_hold = false; // Держится ли мышь на данный момент?
	void cameraMoveByMouse();

	Font font_pixel; // Пиксельный шрифт

	void update(); // Обновление кадра
	void draw(); // Отрисовка кадра

	RenderWindow *window; // Игровое окно
	
	SpriteManager sprite_manager; // Менеджер игровых спрайтов
	DecorationManager decoration_manager = DecorationManager(sprite_manager); // Менеджер декораций
};
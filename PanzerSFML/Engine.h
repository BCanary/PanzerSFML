#pragma once
#include <SFML/Graphics.hpp>
#include "SpriteManager.h"
#include "DecorationManager.h"
//#include <thread>

using namespace sf;

class Engine {
public:
	Engine(RenderWindow &window); // ����������� �������� ������

	void start(); // ��������� ������� ������

	void cameraMoveTo(int x, int y); // ����������� ������ �� ����������

	int old_camera_x = 0; // ��� ������� ������
	int old_camera_y = 0;

	int camera_x = 0; // ��� ������� ������
	int camera_y = 0; // ����� ������� ������

	RenderWindow* getRenderWindow(); // �������� ������� ���� ����������
	SpriteManager& getSpriteManager(); // �������� ����� ��������� ��������
	DecorationManager& getDecorationManager(); // �������� ����� ��������� ���������
private:
	Clock clock_delta_time; // ������, ��� �������� ������ �������
	float delta_time = 0; // ����� ����������� �� ������ � ���������

	float world_scale = 5; // ����������� ���� ��������
	float gui_scale = 1; // ����������� ����������

	int mouse_x = 0;
	int mouse_y = 0;

	int mouse_click_x = 0;
	int mouse_click_y = 0;

	Clock clock_left_mouse_hold; // ������, ������� �������, ������������ ���
	//std::thread thread_left_mouse_hold;
	int time_left_mouse_hold = 0; // ������� ������� ��������� ���
	bool is_left_mouse_hold = false; // �������� �� ���� �� ������ ������?
	void cameraMoveByMouse();

	Font font_pixel; // ���������� �����

	void update(); // ���������� �����
	void draw(); // ��������� �����

	RenderWindow *window; // ������� ����
	
	SpriteManager sprite_manager; // �������� ������� ��������
	DecorationManager decoration_manager = DecorationManager(sprite_manager); // �������� ���������
};
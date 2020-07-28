/*
� ��������� ������� � C++/C � ������� ����� ����������� ���� � "�������������� �������� ����������" SFML/include;
� ������������ - �����, ���� "�������������� �������� ���������" SFML/lib;
� ������������ - ����, ����������� ������������ lib ����� � �������������� �����������, � Release � Debug � ������ -d
������ ����� � ����� NameOfProject/Debug ����� �� SFML/bin, openal32 � ��� � ��������� -d. � Release ��� ��� �������� -d � openal32
*/

#include <iostream>
#include <SFML/Graphics.hpp> // ���������� ����������� ���������� SFML
#include "Engine.h"

//TODO: �������� �����, ��������� �����, �������� ������ ��������, ����������� � ��������������� ����� (�������), ����� �����, 
//		����� ����, ����� ����������,����������� �� �����,���������� ������ ������� �����, ��������� (�������), �������� ����������, ���������� �����
//	    XML �����, map editor, ������� �� ������ �����, ������� ������


const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;

RenderWindow game_window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game");
//View game_view(FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));

Engine engine(game_window);

int main() {
	engine.start();
}
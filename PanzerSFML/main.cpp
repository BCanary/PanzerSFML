/*
� ��������� ������� � C++/C � ������� ����� ����������� ���� � "�������������� �������� ����������" SFML/include;
� ������������ - �����, ���� "�������������� �������� ���������" SFML/lib;
� ������������ - ����, ����������� ������������ lib ����� � �������������� �����������, � Release � Debug � ������ -d
������ ����� � ����� NameOfProject/Debug ����� �� SFML/bin, openal32 � ��� � ��������� -d. � Release ��� ��� �������� -d � openal32
*/

#include <iostream>
#include <SFML/Graphics.hpp> // ���������� ����������� ���������� SFML
#include "Engine.h"

RenderWindow window(VideoMode(900, 800), "Game");
Engine engine(window);

int main() {
	engine.start();
}
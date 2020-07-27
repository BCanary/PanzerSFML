#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include <vector>
#include "tinyxml2.h"
#include <string>
//#include "Engine.h"

using namespace std;
using namespace tinyxml2;

class Map {
public:
	Map(XMLDocument &document);

	string getMapName();

	void draw();
	void update();
private:
	string map_name;

	vector <vector <Tile>> map;
	XMLDocument *map_document;
};
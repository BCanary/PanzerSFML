#include "Map.h"

Map::Map(XMLDocument &document) {
	Map::map_document = &document;

	XMLNode* root = map_document->FirstChildElement("root"); // Получаем рут

	XMLElement* element = root->FirstChildElement("info"); // Получаем элемент с информацией

	Map::map_name = element->FirstChildElement("map_name")->GetText(); //  Получаем имя карты

	int map_height = element->FirstChildElement("map_size")->IntAttribute("height");
	int map_width = element->FirstChildElement("map_size")->IntAttribute("width");

	Map::map.reserve(map_height);
	Map::map.resize(map_width);

	/*
	for (int i = 0; i < map_height; i++) {
		for (int j = 0; j < map_width; j++) {

		}
	}
	*/
};

void Map::draw() {

};

void Map::update() {

};

string Map::getMapName() {
	return map_name;
}
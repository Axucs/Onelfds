﻿//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#include <stdio.h>
#include <tinyxml2.h>

//----------------------------------------------------------
void LoadWorld() {
	tinyxml2::XMLDocument doc;
	if (doc.LoadFile("world.xml") != tinyxml2::XMLError::XML_SUCCESS) {
		printf("doc.LoadFile(\"world.xml\") error\n");
		return;
	}
	tinyxml2::XMLElement* rootNode = doc.FirstChildElement();
	if (!rootNode) {
		printf("\"world.xml\" have not root node\n");
		return;
	}
	tinyxml2::XMLElement* areaNode = rootNode->FirstChildElement("area");
	if (!areaNode) {
		printf("\"world.xml\" have not obj node\n");
		return;
	}
	while (areaNode) {
		//
		areaNode = areaNode->NextSiblingElement("area");
	}
}
//----------------------------------------------------------
void LoadCharacters() {
	tinyxml2::XMLDocument doc;
	if (doc.LoadFile("characters.xml") != tinyxml2::XMLError::XML_SUCCESS) {
		printf("doc.LoadFile(\"character.xml\") error\n");
		return;
	}
	tinyxml2::XMLElement* rootNode = doc.FirstChildElement();
	if (!rootNode) {
		printf("\"character.xml\" have not root node\n");
		return;
	}
	tinyxml2::XMLElement* charNode = rootNode->FirstChildElement("character");
	if (!charNode) {
		printf("\"character.xml\" have not obj node\n");
		return;
	}
	while (charNode) {
		//
		charNode = charNode->NextSiblingElement("character");
	}
}
//----------------------------------------------------------



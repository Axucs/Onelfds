//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#include <stdio.h>
#include <tinyxml2.h>
#include "XMLs.h"
#include "World.h"
#include "Character.h"

//----------------------------------------------------------
World* XML::LoadWorld( const char* fileName) {
	tinyxml2::XMLDocument doc;
	if (doc.LoadFile(fileName) != tinyxml2::XMLError::XML_SUCCESS) {
		printf("doc.LoadFile(\"%s\") error\n", fileName);
		return nullptr;
	}
	tinyxml2::XMLElement* rootNode = doc.FirstChildElement();
	if (!rootNode) {
		printf("\"%s\" have not root node\n", fileName);
		return nullptr;
	}
	tinyxml2::XMLElement* areaNode = rootNode->FirstChildElement("area");
	if (!areaNode) {
		printf("\"%s\" have not obj node\n", fileName);
		return nullptr;
	}
	World* out = new World;
	while (areaNode) {
		int id = 0;
		if (areaNode->QueryIntAttribute("id", &id) != tinyxml2::XMLError::XML_NO_ERROR) {
			printf("While loading \"%s\" we have an error in id of zone\n", fileName);
			return out;
		}
		Zone* zone = new Zone(static_cast<ZoneId>(id));
		//
		out->addZone(zone);
		areaNode = areaNode->NextSiblingElement("area");
	}
	return out;
}
//----------------------------------------------------------
bool XML::LoadCharacters( const char* fileName, World* world) {
	tinyxml2::XMLDocument doc;
	if (doc.LoadFile(fileName) != tinyxml2::XMLError::XML_SUCCESS) {
		printf("doc.LoadFile(\"%s\") error\n", fileName);
		return false;
	}
	tinyxml2::XMLElement* rootNode = doc.FirstChildElement();
	if (!rootNode) {
		printf("\"%s\" have not root node\n", fileName);
		return false;
	}
	tinyxml2::XMLElement* charNode = rootNode->FirstChildElement("character");
	if (!charNode) {
		printf("\"%s\" have not obj node\n", fileName);
		return false;
	}
	while (charNode) {
		Character* chr = new Character;
		//
		world->addCharacter(chr);
		charNode = charNode->NextSiblingElement("character");
	}
	return true;
}
//----------------------------------------------------------



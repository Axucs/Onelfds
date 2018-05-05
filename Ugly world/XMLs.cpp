﻿//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#include <stdio.h>
#include "XMLs.h"
#include "World.h"
#include "Character.h"
#include "Factions.h"

//----------------------------------------------------------
World* XML::LoadWorld(const char* fileName)
{
	tinyxml2::XMLDocument doc;
	if (doc.LoadFile(fileName) != tinyxml2::XMLError::XML_SUCCESS)
	{
		printf("doc.LoadFile(\"%s\") error\n", fileName);
		return nullptr;
	}
	const tinyxml2::XMLElement* rootNode = doc.FirstChildElement();
	if (!rootNode)
	{
		printf("\"%s\" have not root node\n", fileName);
		return nullptr;
	}
	const tinyxml2::XMLElement* areaNode = rootNode->FirstChildElement("area");
	if (!areaNode)
	{
		printf("\"%s\" have not even one area node\n", fileName);
		return nullptr;
	}
	World* out = new World;
	while (areaNode)
	{
		int id = 0;
		if (areaNode->QueryIntAttribute("id", &id) != tinyxml2::XMLError::XML_NO_ERROR)
		{
			printf("While loading \"%s\" we have an error in id of area\n", fileName);
			return out;
		}
		Area* area = new Area(static_cast<AreaId>(id));
		area->SerializeFromXML(areaNode);
		out->addArea(area);
		areaNode = areaNode->NextSiblingElement("area");
	}
	return out;
}
//----------------------------------------------------------
bool XML::LoadCharacters(const char* fileName, World* world)
{
	tinyxml2::XMLDocument doc;
	if (doc.LoadFile(fileName) != tinyxml2::XMLError::XML_SUCCESS)
	{
		printf("doc.LoadFile(\"%s\") error\n", fileName);
		return false;
	}
	const tinyxml2::XMLElement* rootNode = doc.FirstChildElement();
	if (!rootNode)
	{
		printf("\"%s\" have not root node\n", fileName);
		return false;
	}
	const tinyxml2::XMLElement* charNode = rootNode->FirstChildElement("character");
	while (charNode)
	{
		Character* chr = new Character;
		chr->SerializeFromXML(charNode);
		world->addCharacter(chr);
		charNode = charNode->NextSiblingElement("character");
	}
	return true;
}
//----------------------------------------------------------
bool XML::LoadFactions(const char* fileName)
{
	tinyxml2::XMLDocument doc;
	if (doc.LoadFile(fileName) != tinyxml2::XMLError::XML_SUCCESS)
	{
		printf("doc.LoadFile(\"%s\") error\n", fileName);
		return false;
	}
	const tinyxml2::XMLElement* rootNode = doc.FirstChildElement();
	if (!rootNode)
	{
		printf("\"%s\" have not root node\n", fileName);
		return false;
	}
	const tinyxml2::XMLElement* factionNode = rootNode->FirstChildElement("faction");
	while (factionNode)
	{
		Faction* faction = new Faction;
		faction->SerializeFromXML(factionNode);
		FACTIONS->addFaction(faction);
		factionNode = factionNode->NextSiblingElement("faction");
	}
	return true;
}
//----------------------------------------------------------


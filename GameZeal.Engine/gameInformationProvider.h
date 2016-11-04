#ifndef _GAMEINFORMATIONPROVIDER
#define _GAMEINFORMATIONPROVIDER
#pragma once

#include "stdafx.h"

class gameInformationProvider
{
public:
	static string gameInformationProvider::getObjectProperty(int id, string propertyName);
	static void gameInformationProvider::setObjectProperty(int id, string propertyName, string value);
	static void gameInformationProvider::setObjectProperty(int id, string propertyName, int value);
};

#endif
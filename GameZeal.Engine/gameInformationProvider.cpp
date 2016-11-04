#include "stdafx.h"

std::string gameInformationProvider::getObjectProperty(int id, string propertyName)
{
	return string("Arena");
}

void gameInformationProvider::setObjectProperty(int id, string propertyName, string value)
{
	cout << "setting " << propertyName << " : " << value;
}

void gameInformationProvider::setObjectProperty(int id, string propertyName, int value)
{
	cout << "setting " << propertyName + " : " << value;
}

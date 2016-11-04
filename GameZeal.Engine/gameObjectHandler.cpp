#include "stdafx.h"


scriptEngineResult* GetGameObjectProperty(json expression)
{
	auto command = expression.ToObject();
	int id = command["Id"];
	auto propertyName = command["PropertyName"];

	auto value = gameInformationProvider::getObjectProperty(id, propertyName);

	auto result = new scriptEngineResult();
	result->LiteralResult = value;

	return result;
}

scriptEngineResult* SetGameObjectProperty(json expression)
{
	
	auto command = expression.ToObject();

	int id = command["Id"];
	auto propertyName = command["PropertyName"];
	auto value = scriptEngine::Instance->Invoke("Expression", command["Value"]);

	if(value->LiteralResult.length()>0) // !todo replace with ResutType switch
	{
		gameInformationProvider::setObjectProperty(id, propertyName, value->LiteralResult);
	}
	else
	{
		gameInformationProvider::setObjectProperty(id, propertyName, value->NumericResult);
	}
	
	return nullptr;
}

void gameObjectHandler::Register()
{
	RegisterHandler(GetGameObjectProperty);
	RegisterHandler(SetGameObjectProperty);
}

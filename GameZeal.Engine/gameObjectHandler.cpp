#include "stdafx.h"


scriptEngineResult* GetGameObjectProperty(value expression)
{
	auto obj = expression.ToObject();
	auto id = obj[String("Id")].ToInteger();
	auto propertyName = obj[String("PropertyName")].ToString();

	auto value = gameInformationProvider::getObjectProperty(id, Str2UTF8(propertyName));
	auto result = new scriptEngineResult();
	result->LiteralResult = value;

	return result;
}

scriptEngineResult* SetGameObjectProperty(value expression)
{
	auto obj = expression.ToObject();

	auto id = obj[String("Id")].ToInteger();
	auto propertyName = obj[String("PropertyName")].ToString();
	auto value = scriptEngine::Instance->Invoke("Expression", obj[String("Value")]);

	if(value->LiteralResult.length()>0) // !todo replace with ResutType switch
	{
		gameInformationProvider::setObjectProperty(id, Str2UTF8(propertyName), value->LiteralResult);
	}
	else
	{
		gameInformationProvider::setObjectProperty(id, Str2UTF8(propertyName), value->NumericResult);
	}

	return nullptr;
}

void gameObjectHandler::Register()
{
	RegisterHandler(GetGameObjectProperty);
	RegisterHandler(SetGameObjectProperty);
}

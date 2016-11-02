#include "stdafx.h"

scriptEngineResult* GetGameObjectProperty(value expression)
{
	auto obj = expression.ToObject();
	auto id = obj[String("Id")].ToInteger();
	auto propertyName = obj[String("PropertyName")].ToString();
	auto value = scriptEngine::Instance->Invoke("Expression", obj[String("Value")]);
	

	return nullptr;
}

scriptEngineResult* SetGameObjectProperty(value expression)
{
	auto obj = expression.ToObject();

	return nullptr;
}

void gameObjectHandler::Register()
{
	RegisterHandler(GetGameObjectProperty);
	RegisterHandler(SetGameObjectProperty);
}

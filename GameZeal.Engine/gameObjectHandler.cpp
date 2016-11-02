#include "gameObjectHandler.h"
#include "scriptEngine.h"
#include "gameInformationProvider.h"

scriptEngineResult* GetGameObjectProperty(json::value expression)
{
	json::object obj = expression.as_object();
	auto id = obj[U("Id")].as_integer();
	auto propertyName = obj[U("PropertyName")].as_string();

	auto a = gameInformationProvider::getObjectProperty(id, to_utf8string(propertyName));
	auto result = new scriptEngineResult();
	result->LiteralResult = a;

	return result;
}

scriptEngineResult* SetGameObjectProperty(json::value expression)
{
	json::object obj = expression.as_object();
	auto id = obj[U("Id")].as_integer();
	auto propertyName = obj[U("PropertyName")].as_string();
	auto value = scriptEngine::Instance->Invoke("Expression", obj[U("Value")]);

	if(value->LiteralResult.length()>0) //!todo replace with ResutType switch
	{
		gameInformationProvider::setObjectProperty(id, to_utf8string(propertyName), value->LiteralResult);
	}
	else
	{
		gameInformationProvider::setObjectProperty(id, to_utf8string(propertyName), value->NumericResult);
	}

	return nullptr;
}

void gameObjectHandler::Register(scriptEngine* scriptEngine)
{
	typedef scriptEngineResult*(*Handler)(json::value expression);
	scriptEngine->Handlers["GetGameObjectProperty"] = (Handler*)GetGameObjectProperty;
	scriptEngine->Handlers["SetGameObjectProperty"] = (Handler*)SetGameObjectProperty;
}

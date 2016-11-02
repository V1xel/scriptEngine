#include "gameObjectHandler.h"
#include "scriptEngine.h"

scriptEngineResult* GetGameObjectProperty(json::value expression)
{
	json::object obj = expression.as_object();
	auto id = obj[U("Id")].as_integer();
	auto propertyName = obj[U("PropertyName")].as_string();
	auto value = scriptEngine::Instance->Invoke("Expression", obj[U("Value")]);
	
	
}

scriptEngineResult* SetGameObjectProperty(json::value expression)
{
	json::object obj = expression.as_object();
}

void gameObjectHandler::Register(scriptEngine* scriptEngine)
{
	typedef scriptEngineResult*(*Handler)(json::value expression);
	scriptEngine->Handlers["GetGameObjectProperty"] = (Handler*)GetGameObjectProperty;
	scriptEngine->Handlers["SetGameObjectProperty"] = (Handler*)SetGameObjectProperty;
}

#include "announceHandler.h"
#include "scriptEngine.h"

scriptEngineResult* Announce(json::value expression)
{
	json::object obj = expression.as_object();
	std::cout << to_utf8string(obj[U("EventName")].as_string()+U(" ")+ obj[U("CallerId")].as_string());

	return nullptr;
}

void announceHandler::Register(scriptEngine* scriptEngine)
{
	typedef scriptEngineResult*(*Handler)(json::value expression);
	scriptEngine->Handlers["Announce"] = (Handler*)Announce;
}

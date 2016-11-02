#include "scriptEngine.h"
#include "logicalHandler.h"


using namespace web;
using namespace utility::conversions;

scriptEngine* scriptEngine::Instance;

void main()
{
	scriptEngine::Instance = new scriptEngine();
	scriptEngine::Instance->Init();

	auto jsonBuilder = json::value::parse(U("{\"Expression\": {\"GreaterThan\": {\"left\": {\"Number\": 5},\"right\" : {\"Number\": 3} }	}}"));
	auto command = jsonBuilder[U("Expression")].as_object();
	for (auto value : command)
	{
		auto rezz = scriptEngine::Instance->Invoke(to_utf8string(value.first), value.second);

		system("pause");
	}
}

scriptEngineResult* Expression(json::value expression)
{
	json::object command = expression.as_object();
	for (auto value : command)
		return scriptEngine::Instance->Invoke(to_utf8string(value.first), value.second);
}

void scriptEngine::Init()
{
	typedef scriptEngineResult*(*Handler)(json::value expression);
	auto v = (Handler*)Expression;
	scriptEngine::Instance->Handlers["Expression"] = v;

	numericHandler::Register(this);
	literalHandler::Register(this);
	logicalHandler::Register(this);
}

scriptEngineResult* scriptEngine::Invoke(std::string command, json::value expression)
{
	auto handlerPtr = Handlers.find(command)->second;

	return (Handler(handlerPtr))(expression);
}
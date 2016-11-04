#include "stdafx.h"

scriptEngine* scriptEngine::Instance;

scriptEngineResult* Expression(json expression)
{
	auto command = expression.ToObject();

	for (auto item : command) {

		return scriptEngine::Instance->Invoke(item.first, item.second);
	}

	return nullptr;
}

void scriptEngine::Init()
{
	RegisterHandler(Expression);

	numericHandler::Register();
	literalHandler::Register();
	logicalHandler::Register();
	ifHandler::Register();
	announceHandler::Register();
	gameObjectHandler::Register();
}

scriptEngineResult* scriptEngine::Invoke(string command, json expression)
{
	auto handler = Handlers.find(command);

	if (handler == Handlers.end())
	{
		throw "Invalid handler detected";
	}

	auto handlerPtr = handler->second;

	return (Handler(handlerPtr))(expression);
}
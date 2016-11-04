#include "stdafx.h"

scriptEngineResult* If(json expression)
{
	auto command = expression.ToObject();

	auto condition = scriptEngine::Instance->Invoke("Expression", command["Condition"])->LogicalResult;

	if (condition && !command["OnTrue"].is_null())
		return scriptEngine::Instance->Invoke("Expression", command["OnTrue"]);
	
	if(!condition && !command["OnFalse"].is_null())
	{
		return scriptEngine::Instance->Invoke("Expression", command["OnFalse"]);
	}

	return nullptr;
}


void ifHandler::Register()
{
	RegisterHandler(If);
}

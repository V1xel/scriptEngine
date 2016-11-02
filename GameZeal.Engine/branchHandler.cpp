#include "stdafx.h"

scriptEngineResult* Branch(value expression)
{
	auto rez = new scriptEngineResult();
	auto command = expression.ToObject();

	auto condition = scriptEngine::Instance->Invoke("Expression", command[String("Condition")])->LogicalResult;

	if (condition && !command[String("OnTrue")].is_null())
		return scriptEngine::Instance->Invoke("Expression", command[String("OnTrue")]);
	
	if(!condition && !command[String("OnFalse")].is_null())
	{
		return scriptEngine::Instance->Invoke("Expression", command[String("OnFalse")]);
	}

	return nullptr;
}


void branchHandler::Register()
{
	RegisterHandler(Branch);
}

#include "branchHandler.h"
#include "scriptEngine.h"

scriptEngineResult* Branch(json::value expression)
{
	auto rez = new scriptEngineResult();
	auto command = expression.as_object();

	auto condition = scriptEngine::Instance->Invoke("Expression", command[U("Condition")])->LogicalResult;

	if (condition && !command[U("OnTrue")].is_null())
		return scriptEngine::Instance->Invoke("Expression", command[U("OnTrue")]);
	
	if(!condition && !command[U("OnFalse")].is_null())
	{
		return scriptEngine::Instance->Invoke("Expression", command[U("OnFalse")]);
	}

	return nullptr;
}


void branchHandler::Register(scriptEngine* scriptEngine)
{
	typedef scriptEngineResult*(*Handler)(json::value expression);
	scriptEngine->Handlers["Branch"] = (Handler*)Branch;
}

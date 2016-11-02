#include "logicalHandler.h"
#include "scriptEngine.h"

scriptEngineResult* GreaterThan(json::value expression)
{
	auto rez = new scriptEngineResult();
	auto command = expression.as_object();

	auto left = scriptEngine::Instance->Invoke("Expression", command[U("left")])->NumericResult;
	auto right = scriptEngine::Instance->Invoke("Expression", command[U("right")])->NumericResult;
	rez->LogicalResult = left > right;
	
	return rez;
}

scriptEngineResult* NotEqual(json::value expression)
{
	auto rez = new scriptEngineResult();
	auto command = expression.as_object();

	auto left = scriptEngine::Instance->Invoke("Expression", command[U("left")])->NumericResult;
	auto right = scriptEngine::Instance->Invoke("Expression", command[U("right")])->NumericResult;
	rez->LogicalResult = left != right;

	return rez;
}

scriptEngineResult* LowerThan(json::value expression)
{
	auto rez = new scriptEngineResult();
	auto command = expression.as_object();

	auto left = scriptEngine::Instance->Invoke("Expression", command[U("left")])->NumericResult;
	auto right = scriptEngine::Instance->Invoke("Expression", command[U("right")])->NumericResult;
	rez->LogicalResult = left < right;

	return rez;
}

scriptEngineResult* Equal(json::value expression)
{
	auto rez = new scriptEngineResult();
	auto command = expression.as_object();

	auto left = scriptEngine::Instance->Invoke("Expression", command[U("left")])->NumericResult;
	auto right = scriptEngine::Instance->Invoke("Expression", command[U("right")])->NumericResult;
	rez->LogicalResult = left == right;

	return rez;
}

void logicalHandler::Register(scriptEngine* scriptEngine)
{
	typedef scriptEngineResult*(*Handler)(json::value expression);
	scriptEngine->Handlers["GreaterThan"] = (Handler*)GreaterThan;
	scriptEngine->Handlers["NotEqual"] = (Handler*)NotEqual;
	scriptEngine->Handlers["LowerThan"] = (Handler*)LowerThan;
	scriptEngine->Handlers["Equal"] = (Handler*)Equal;
}

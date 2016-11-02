#include "stdafx.h"

scriptEngineResult* GreaterThan(value expression)
{
	auto rez = new scriptEngineResult();
	auto command = expression.ToObject();

	auto left = scriptEngine::Instance->Invoke("Expression", command[String("left")])->NumericResult;
	auto right = scriptEngine::Instance->Invoke("Expression", command[String("right")])->NumericResult;
	rez->LogicalResult = left > right;

	return rez;
}

scriptEngineResult* NotEqual(value expression)
{
	auto rez = new scriptEngineResult();
	auto command = expression.ToObject();

	auto left = scriptEngine::Instance->Invoke("Expression", command[String("left")])->NumericResult;
	auto right = scriptEngine::Instance->Invoke("Expression", command[String("right")])->NumericResult;
	rez->LogicalResult = left != right;

	return rez;
}

scriptEngineResult* LowerThan(value expression)
{
	auto rez = new scriptEngineResult();
	auto command = expression.ToObject();

	auto left = scriptEngine::Instance->Invoke("Expression", command[String("left")])->NumericResult;
	auto right = scriptEngine::Instance->Invoke("Expression", command[String("right")])->NumericResult;
	rez->LogicalResult = left < right;

	return rez;
}

scriptEngineResult* Equal(value expression)
{
	auto rez = new scriptEngineResult();
	auto command = expression.ToObject();

	auto left = scriptEngine::Instance->Invoke("Expression", command[String("left")])->NumericResult;
	auto right = scriptEngine::Instance->Invoke("Expression", command[String("right")])->NumericResult;
	rez->LogicalResult = left == right;

	return rez;
}

void logicalHandler::Register()
{
	RegisterHandler(GreaterThan);
	RegisterHandler(NotEqual);
	RegisterHandler(LowerThan);
	RegisterHandler(Equal);
}

#include "stdafx.h"

scriptEngineResult* Number(json expression)
{
	auto result = new scriptEngineResult();

	result->NumericResult = expression;

	return result;
}

scriptEngineResult* ToNumber(json expression)
{
	scriptEngineResult* valueToConvert = nullptr;

	for (auto value : expression.ToObject())
	{
		valueToConvert = scriptEngine::Instance->Invoke(value.first, value.second);
		break;
	}

	if(valueToConvert->LiteralResult.length() > 0)
	{
		valueToConvert->NumericResult = StringToInteger(valueToConvert->LiteralResult.c_str());

		return valueToConvert;
	}

	return nullptr;
}

void numericHandler::Register()
{
	RegisterHandler(Number);
	RegisterHandler(ToNumber);
}

#include "stdafx.h"

scriptEngineResult* Number(value expression)
{
	auto rez = new scriptEngineResult();
	rez->NumericResult = expression.ToInteger();
	return rez;
}

scriptEngineResult* ToNumber(value expression)
{
	scriptEngineResult* valueToConvert = nullptr;
	for (auto value : expression.ToObject())
	{
		valueToConvert = scriptEngine::Instance->Invoke(Str2UTF8(value.first), value.second);
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

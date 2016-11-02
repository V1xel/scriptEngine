#include "numericHandler.h"
#include "scriptEngine.h"

scriptEngineResult* Number(json::value expression)
{
	auto rez = new scriptEngineResult();
	rez->NumericResult = expression.as_integer();
	return rez;
}

scriptEngineResult* ToNumber(json::value expression)
{
	scriptEngineResult* valueToConvert = nullptr;
	for (auto value : expression.as_object())
	{
		valueToConvert = scriptEngine::Instance->Invoke(to_utf8string(value.first), value.second);
		break;
	}

	if(valueToConvert->LiteralResult.length() > 0)
	{
		valueToConvert->NumericResult = atoi(valueToConvert->LiteralResult.c_str());;

		return valueToConvert;
	}

	return nullptr;
}

void numericHandler::Register(scriptEngine* scriptEngine)
{
	typedef scriptEngineResult*(*Handler)(json::value expression);
	auto v = (Handler*)Number;
	scriptEngine->Handlers["Number"] = v;

	auto v1 = (Handler*)ToNumber;
	scriptEngine->Handlers["ToNumber"] = v1;
}

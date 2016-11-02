#include "stdafx.h"

scriptEngineResult* Announce(value expression)
{
	auto obj = expression.ToObject();
	cout << Str2UTF8(obj[String("EventName")].ToString()+ String(" ")+ obj[String("CallerId")].ToString());

	return nullptr;
}

void announceHandler::Register()
{
	RegisterHandler(Announce);
}

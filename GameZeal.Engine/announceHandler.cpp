#include "stdafx.h"

scriptEngineResult* Announce(json expression)
{
	auto command = expression.ToObject();
	cout << command["EventName"] << " " << command["CallerId"];
	
	return nullptr;
}

void announceHandler::Register()
{
	RegisterHandler(Announce);
}

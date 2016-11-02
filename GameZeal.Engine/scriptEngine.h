#pragma once
#include <map>
#include <cpprest/json.h>
#include "numericHandler.h"
#include "literalHandler.h"
#include "scriptEngineResult.h"


class scriptEngine
{
public:
	static scriptEngine* scriptEngine::Instance;

	void Init();
	scriptEngineResult* Invoke(std::string command, web::json::value value);
	typedef scriptEngineResult*(*Handler)(json::value expression);
	std::map<std::string, Handler*> Handlers;
};


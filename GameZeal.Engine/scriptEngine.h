#ifndef _SCRIPTENGINE
#define _SCRIPTENGINE
#pragma once

#include <map>
#include "stdafx.h"

Delegate scriptEngineResult*(*Handler)(json expression);

class scriptEngine
{
public:
	static scriptEngine* scriptEngine::Instance;

	static void Init();
	scriptEngineResult* Invoke(string command, json value);
	map<string, Handler*> Handlers;
};

#endif
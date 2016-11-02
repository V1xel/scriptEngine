#ifndef _SCRIPTENGINE
#define _SCRIPTENGINE
#pragma once

#include <map>
#include "stdafx.h"

using namespace utility::conversions;

Delegate scriptEngineResult*(*Handler)(value expression);

class scriptEngine
{
public:
	static scriptEngine* scriptEngine::Instance;

	static void Init();
	scriptEngineResult* Invoke(string command, value value);
	map<string, Handler*> Handlers;
};

#endif
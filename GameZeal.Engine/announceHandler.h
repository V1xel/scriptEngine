#pragma once
#include <cpprest/json.h>

using namespace web;
using namespace utility::conversions;

class scriptEngine;
class scriptEngineResult;

class announceHandler
{
public:
	static void Register(scriptEngine* scriptEngine);
};

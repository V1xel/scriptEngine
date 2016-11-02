#pragma once
#include <cpprest/json.h>

using namespace web;
using namespace utility::conversions;


class scriptEngine;
class scriptEngineResult;
class numericHandler 
{
public:
	typedef void* (*NumericFunc)(json::value expression);

	static void Register(scriptEngine* scriptEngine);
};


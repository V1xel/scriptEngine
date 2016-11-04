#ifndef _STDAFX
#define _STDAFX

#pragma once

#include <string>
#include <cmath>
#include <tuple>
#include "../Dependencies/json.hpp"

#define RegisterHandler(n)  \
{ \
	auto handler##n = reinterpret_cast<Handler*>(##n); \
	scriptEngine::Instance->Handlers[#n] = handler##n; \
}

#define Str2UTF8(value) to_utf8string(value)
#define StringToInteger(value) atoi(value)
#define String R
#define ToObject get<json::object_t>
#define ToString get<string>
#define ToInteger get<int>
#define Delegate typedef

using namespace std;
using namespace nlohmann;


#include "scriptEngineResult.h"
#include "scriptEngine.h"

#include "utilities.hpp"

#include "ifHandler.h"
#include "announceHandler.h"
#include "logicalHandler.h"
#include "announceHandler.h"
#include "gameObjectHandler.h"
#include "numericHandler.h"
#include "literalHandler.h"
#include "gameInformationProvider.h"

#endif
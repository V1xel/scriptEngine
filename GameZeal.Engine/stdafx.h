#ifndef _STDAFX
#define _STDAFX

#pragma once

#include <string>
#include <cpprest/json.h>

#define RegisterHandler(n)  \
{ \
	auto handler##n = reinterpret_cast<Handler*>(##n); \
	scriptEngine::Instance->Handlers[#n] = handler##n; \
}

#define Str2UTF8(value) to_utf8string(value)
#define StringToInteger(value) atoi(value)
#define String U
#define ToObject as_object
#define ToString as_string
#define ToInteger as_integer
#define Delegate typedef

using namespace std;
using namespace web::json;

#include "scriptEngineResult.h"
#include "scriptEngine.h"

#include "branchHandler.h"
#include "announceHandler.h"
#include "logicalHandler.h"
#include "branchHandler.h"
#include "announceHandler.h"
#include "gameObjectHandler.h"
#include "numericHandler.h"
#include "literalHandler.h"
#include "gameInformationProvider.h"

#endif
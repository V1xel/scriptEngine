#pragma once
#include <string>
#include <cpprest/json.h>

class scriptEngineResult
{
public:
	int NumericResult;
	std::string LiteralResult;
	bool LogicalResult;
	web::json::value Expression;
};


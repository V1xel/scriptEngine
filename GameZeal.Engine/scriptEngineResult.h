#pragma once
#include <string>
#include <cpprest/json.h>

class scriptEngineResult
{
public:
	enum class ResultType { Literal, Numeric, Logical, Expr };

	int NumericResult;
	std::string LiteralResult;
	bool LogicalResult;
	json::value Expression;
	ResultType Type;
};


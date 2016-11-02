#ifndef _SCRIPT_ENGINERESULT
#define _SCRIPT_ENGINERESULT

#pragma once

#include "stdafx.h"

class scriptEngineResult
{
public:
		enum class ResultType { Literal, Numeric, Logical, Expr };

		int NumericResult;
		string LiteralResult;
		bool LogicalResult;
		value Expression;
		ResultType Type;
};

#endif
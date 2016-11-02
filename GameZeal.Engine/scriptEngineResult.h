#ifndef _SCRIPT_ENGINERESULT
#define _SCRIPT_ENGINERESULT

#pragma once

#include "stdafx.h"

class scriptEngineResult
{
	public:
		int NumericResult;
		string LiteralResult;
		bool LogicalResult;
		value Expression;
};

#endif
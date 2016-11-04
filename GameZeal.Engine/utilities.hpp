#pragma once
#include "stdafx.h"

namespace utilities
{

#ifndef _GZUTILITIES
#define _GZUTILITIES

	static tuple<int, int> GetLeftAndRight(json expression)
	{
		auto command = expression.ToObject();

		auto left = scriptEngine::Instance->Invoke("Expression", command["left"])->NumericResult;
		auto right = scriptEngine::Instance->Invoke("Expression", command["right"])->NumericResult;

		return make_tuple(left, right);
	}

#endif

}
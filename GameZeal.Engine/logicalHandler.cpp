#include "stdafx.h"

using namespace utilities;

scriptEngineResult* GreaterThan(json expression)
{
	auto result = new scriptEngineResult();

	int left, right;
	tie(left, right) = GetLeftAndRight(expression);

	result->LogicalResult = left > right;

	return result;
}

scriptEngineResult* NotEqual(json expression)
{
	auto result = new scriptEngineResult();

	int left, right;
	tie(left, right) = GetLeftAndRight(expression);

	result->LogicalResult = left != right;

	return result;
}

scriptEngineResult* LowerThan(json expression)
{
	auto result = new scriptEngineResult();

	int left, right;
	tie(left, right) = GetLeftAndRight(expression);

	result->LogicalResult = left < right;

	return result;
}

scriptEngineResult* Equal(json expression)
{
	auto result = new scriptEngineResult();

	int left, right;
	tie(left, right) = GetLeftAndRight(expression);

	result->LogicalResult = left == right;

	return result;
}

void logicalHandler::Register()
{
	RegisterHandler(GreaterThan);
	RegisterHandler(NotEqual);
	RegisterHandler(LowerThan);
	RegisterHandler(Equal);
}

#include "stdafx.h"

scriptEngineResult* Literal(json expression)
{
	auto result = new scriptEngineResult();
	result->LiteralResult = expression.ToString();
	return result;
}

scriptEngineResult* ToLiteral(json expression)
{
	auto result = new scriptEngineResult();

	if (expression.is_number_integer())
	{
		result->LiteralResult = to_string(expression.ToInteger());
	}

	if(expression.is_string())
	{
		result->LiteralResult = expression.ToString();
	}
	
	return result;
}

void literalHandler::Register()
{
	RegisterHandler(Literal);
}

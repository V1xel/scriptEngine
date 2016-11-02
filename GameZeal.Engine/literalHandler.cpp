#include "stdafx.h"

scriptEngineResult* Literal(value expression)
{
	auto rez = new scriptEngineResult();
	rez->LiteralResult = Str2UTF8(expression.ToString());
	return rez;
}

scriptEngineResult* ToLiteral(value expression)
{
	auto rez = new scriptEngineResult();
	if (expression.is_integer())
	{
		stringstream ss;
		ss << expression.ToInteger();
		rez->LiteralResult = ss.str();
	}

	if(expression.is_string())
	{
		rez->LiteralResult = Str2UTF8(expression.ToString());
	}
	
	return rez;
}

void literalHandler::Register()
{
	RegisterHandler(Literal);
}

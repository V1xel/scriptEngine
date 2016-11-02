#include "literalHandler.h"
#include "scriptEngine.h"

scriptEngineResult* Literal(json::value expression)
{
	auto rez = new scriptEngineResult();
	rez->LiteralResult = to_utf8string(expression.as_string());
	return rez;
}

scriptEngineResult* ToLiteral(json::value expression)
{
	auto rez = new scriptEngineResult();
	if (expression.is_integer())
	{
		std::stringstream ss;
		ss << expression.as_integer();
		rez->LiteralResult = ss.str();
	}

	if(expression.is_string())
	{
		rez->LiteralResult = to_utf8string(expression.as_string());
	}
	
	return rez;
}

void literalHandler::Register(scriptEngine* scriptEngine)
{
	typedef scriptEngineResult*(*Handler)(json::value expression);
	auto v = (Handler*)Literal;
	scriptEngine->Handlers["Literal"] = v;
}

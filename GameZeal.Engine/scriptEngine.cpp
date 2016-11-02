#include "scriptEngine.h"
#include "logicalHandler.h"
#include "branchHandler.h"


using namespace web;
using namespace utility::conversions;

scriptEngine* scriptEngine::Instance;

void main()
{
	scriptEngine::Instance = new scriptEngine();
	scriptEngine::Instance->Init();

	auto jsonBuilder = json::value::parse(U("{	\"Expression\":{	\"Branch\":{		\"Condition\":{	\"GreaterThan\":{		\"left\":{			\"Number\":55			},			\"right\":{		\"ToNumber\":{			\"Expression\":{		\"Literal\":\"25\"				}}	}	}	},		\"OnTrue\":{	\"Expression\":{	\"Number\":255		}	}	}	}}"));
	auto command = jsonBuilder[U("Expression")].as_object();
	for (auto value : command)
	{
		auto rezz = scriptEngine::Instance->Invoke(to_utf8string(value.first), value.second);

		system("pause");
	}
}

scriptEngineResult* Expression(json::value expression)
{
	json::object command = expression.as_object();
	for (auto value : command)
		return scriptEngine::Instance->Invoke(to_utf8string(value.first), value.second);
}

void scriptEngine::Init()
{
	typedef scriptEngineResult*(*Handler)(json::value expression);
	auto v = (Handler*)Expression;
	scriptEngine::Instance->Handlers["Expression"] = v;

	numericHandler::Register(this);
	literalHandler::Register(this);
	logicalHandler::Register(this);
	branchHandler::Register(this);
}

scriptEngineResult* scriptEngine::Invoke(std::string command, json::value expression)
{
	auto handlerPtr = Handlers.find(command)->second;

	return (Handler(handlerPtr))(expression);
}
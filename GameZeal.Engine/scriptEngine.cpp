#include "stdafx.h"

scriptEngine* scriptEngine::Instance;

void main()
{
	scriptEngine::Instance = new scriptEngine();
	scriptEngine::Instance->Init();

	auto jsonBuilder = value::parse(String("{	\"Expression\":{	\"Branch\":{		\"Condition\":{	\"GreaterThan\":{		\"left\":{			\"Number\":55			},			\"right\":{		\"ToNumber\":{			\"Expression\":{		\"Literal\":\"25\"				}}	}	}	},		\"OnTrue\":{	\"Expression\":{	\"Announce\": {	\"EventName\": \"Comes to the Arena\",	\"CallerId\" : \"1\"}		}	}	}	}}"));
	auto command = jsonBuilder[String("Expression")].ToObject();
	for (auto value : command)
	{
		auto rezz = scriptEngine::Instance->Invoke(Str2UTF8(value.first), value.second);

		system("pause");
	}
}

scriptEngineResult* Expression(value expression)
{
	auto command = expression.ToObject();

	for (auto item : command) {
		return scriptEngine::Instance->Invoke(Str2UTF8(item.first), item.second);
	}

	return nullptr;
}

void scriptEngine::Init()
{
	RegisterHandler(Expression);

	numericHandler::Register();
	literalHandler::Register();
	logicalHandler::Register();
	branchHandler::Register();
	announceHandler::Register();
	gameObjectHandler::Register();
}

scriptEngineResult* scriptEngine::Invoke(string command, value expression)
{
	auto handlerPtr = Handlers.find(command)->second;

	return (Handler(handlerPtr))(expression);
}
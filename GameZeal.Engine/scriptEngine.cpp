#include "stdafx.h"

scriptEngine* scriptEngine::Instance;

void main()
{
	scriptEngine::Instance = new scriptEngine();
	scriptEngine::Instance->Init();

	auto jsonBuilder = json::parse("{	\"Expression\":{	\"If\":{		\"Condition\":{	\"GreaterThan\":{		\"left\":{			\"Number\":55			},			\"right\":{		\"ToNumber\":{			\"Expression\":{		\"Literal\":\"25\"				}}	}	}	},		\"OnTrue\":{	\"Expression\":{	\"SetGameObjectProperty\": { \"Id\":1,   \"PropertyName\": \"Location\",		\"Value\" : {		\"Expression\": {		\"Literal\": \"Arena\"	}	}}		}	}	}	}}");
	auto command = jsonBuilder["Expression"].ToObject();

	for (auto value : command)
	{
		auto result = scriptEngine::Instance->Invoke(value.first, value.second);
		system("pause");
	}
}

scriptEngineResult* Expression(json expression)
{
	auto command = expression.ToObject();

	for (auto item : command) {

		return scriptEngine::Instance->Invoke(item.first, item.second);
	}

	return nullptr;
}

void scriptEngine::Init()
{
	RegisterHandler(Expression);

	numericHandler::Register();
	literalHandler::Register();
	logicalHandler::Register();
	ifHandler::Register();
	announceHandler::Register();
	gameObjectHandler::Register();
}

scriptEngineResult* scriptEngine::Invoke(string command, json expression)
{
	auto handlerPtr = Handlers.find(command)->second;

	return (Handler(handlerPtr))(expression);
}
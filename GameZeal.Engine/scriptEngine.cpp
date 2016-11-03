#include "stdafx.h"

scriptEngine* scriptEngine::Instance;

void main()
{
	scriptEngine::Instance = new scriptEngine();
	scriptEngine::Instance->Init();

	auto jsonBuilder = value::parse(String(
		
		
		"{	\"Expression\":{	\"If\":{		\"Condition\":{	\"GreaterThan\":{		\"left\":{			\"Number\":55			},			\"right\":{		\"ToNumber\":{			\"Expression\":{		\"Literal\":\"25\"				}}	}	}	},		\"OnTrue\":{	\"Expression\":{	\"SetGameObjectProperty\": { \"Id\":1,   \"PropertyName\": \"Location\",		\"Value\" : {		\"Expression\": {		\"Literal\": \"Arena\"	}	}}		}	}	}	}}"));
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
	ifHandler::Register();
	announceHandler::Register();
	gameObjectHandler::Register();
}

scriptEngineResult* scriptEngine::Invoke(string command, value expression)
{
	auto handlerPtr = Handlers.find(command)->second;

	return (Handler(handlerPtr))(expression);
}
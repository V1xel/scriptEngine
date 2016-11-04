#include "stdafx.h"
#include <fstream>

const char* readJsonTestSchemaFile(string path)
{
	ifstream file;
	file.open(path);

	stringstream data;
	data << file.rdbuf();

	string string = data.str();
	return _strdup(string.c_str());
}

void main()
{
	scriptEngine::Instance = new scriptEngine();
	scriptEngine::Instance->Init();

	try
	{

		auto json = readJsonTestSchemaFile("../Schemas/Testing/buff.json");

		auto jsonBuilder = json::parse(json);
		auto command = jsonBuilder["Expression"].ToObject();

		for (auto value : command)
		{
			auto result = scriptEngine::Instance->Invoke(value.first, value.second);
		}
	} catch(...)
	{
		cout << "Internal exception occurs, enable your brains! :(" << endl;
	}

	system("pause");
}

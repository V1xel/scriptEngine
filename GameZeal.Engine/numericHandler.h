#ifndef _NUMERICHANDLER
#define _NUMERICHANDLER
#pragma once

#include "stdafx.h"

class numericHandler 
{
public:
	typedef void* (*NumericFunc)(json expression);

	static void Register();
};

#endif
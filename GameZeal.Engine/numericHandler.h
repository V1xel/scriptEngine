#ifndef _NUMERICHANDLER
#define _NUMERICHANDLER
#pragma once

#include "stdafx.h"

class numericHandler 
{
public:
	typedef void* (*NumericFunc)(value expression);

	static void Register();
};

#endif
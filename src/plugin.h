#pragma once

#include "mw2/iw4mp.h"

class plugin
{
public:
    static void start();
    static void stop();

private:
    static bool s_Running;
    static uint32_t s_CurrentTitleId;
    static uint32_t Update(void *);
	static iw4mp *s_pCurrentTitle;
    static void InitNewTitle(uint32_t title);
};

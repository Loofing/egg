#include "pch.h"
#include "plugin.h"

bool plugin::s_Running = false;
uint32_t plugin::s_CurrentTitleId = 0;
iw4mp *plugin::s_pCurrentTitle = nullptr;

#define IW4_TITLE 0x41560817

void plugin::start()
{
    s_Running = true;
    Memory::ThreadEx(reinterpret_cast<PTHREAD_START_ROUTINE>(Update), nullptr, 2);
}

void plugin::stop()
{
    s_Running = false;
    Sleep(250);
}

uint32_t plugin::Update(void *)
{
    while (s_Running)
    {
        uint32_t newTitleId = Xam::GetCurrentTitleId();

        if (newTitleId != s_CurrentTitleId)
            InitNewTitle(newTitleId);
	}
    return 0;
}

void plugin::InitNewTitle(uint32_t title)
{
	delete s_pCurrentTitle;
    s_pCurrentTitle = nullptr;
    s_CurrentTitleId = title;

	if(title == IW4_TITLE && !strcmp(reinterpret_cast<char *>(0x82001F44), "multiplayer"))
		s_pCurrentTitle = new iw4mp();
}


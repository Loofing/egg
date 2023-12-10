#include "pch.h"
#include "plugin.h"

BOOL APIENTRY DllMain(HANDLE hModule, DWORD dwReason, void *pReserved)
{
    if (dwReason == DLL_PROCESS_ATTACH)
        plugin::start();

    if (dwReason == DLL_PROCESS_DETACH)
        plugin::stop();

    return TRUE;
}

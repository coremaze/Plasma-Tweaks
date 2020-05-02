// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "widget_icon.h"
#include "utils.h"



/*
 This exploits FreeImage's ability to load plugins.
 Any file with the .fip file extension will be loaded
 by FreeImage, and then it will try to call _Init@8.
*/
extern "C" __declspec(dllexport) const char* __stdcall Init(void* var1, void* var2) {
	InitBase();
	widget_icon_initialize();
	return "";
}

extern "C" __declspec(dllexport) BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved )
{
    return TRUE;
}


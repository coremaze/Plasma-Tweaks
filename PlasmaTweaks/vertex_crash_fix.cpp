#include "pch.h"
#include "vertex_crash_fix.h"
#include "utils.h"
#include <windows.h>


void vertex_crash_fix_initialize() {
	// This WILL cause memory leaks.
	// However, it's worth it for now.
	// It seems that when getting rid of the right click menu,
	// It destroys some data which is needed later by vertex stuff.
	// This is nopping out a destructor + free call
	
	// Nvidia drivers seem to be missing at least one null ptr check,
	// so they're more prone to failure because of this.

	// A memory leak is better than just crashing

	char* patch_offset = (char*)BaseOffset(0x179F07);
	int nop_count = 5;
	DWORD dwOldProtection;
	VirtualProtect(patch_offset, nop_count, PAGE_EXECUTE_READWRITE, &dwOldProtection);

	for (int i = 0; i < nop_count; i++) {
		patch_offset[i] = 0x90;
	}

	VirtualProtect(patch_offset, nop_count, dwOldProtection, &dwOldProtection);

}

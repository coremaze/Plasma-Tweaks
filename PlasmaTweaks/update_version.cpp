#include "pch.h"
#include "update_version.h"
#include "utils.h"
#include <windows.h>
#include "version"

// The purpose of this is to operate with the update mechanism.
// Updating the version here will prevent Plasma from thinking it has new updates when it doesn't.

void update_version_initialize() {
	// Instruction + offset to operand
	void* version_locs[] = { BaseOffset(0x689B8 + 6), BaseOffset(0x6ACCC + 6)} ;

	DWORD dwOldProtection;
	for (auto& loc : version_locs) {
		VirtualProtect(loc, 1, PAGE_EXECUTE_READWRITE, &dwOldProtection);
		*(char*)loc = PLASMATWEAKS_VERSION;
		VirtualProtect(loc, 1, dwOldProtection, &dwOldProtection);
	}
}

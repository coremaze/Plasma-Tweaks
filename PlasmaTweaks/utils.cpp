#include "pch.h"
#include "utils.h"

void* BASE;
void InitBase() {
	BASE = GetModuleHandle(NULL);
}

void* Base() {
	return BASE;
}

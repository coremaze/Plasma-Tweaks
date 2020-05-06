#include "pch.h"
#include <windows.h>
#include "utils.h"
#include "allocation.h"

__declspec(noinline) void* operator new(size_t size) {
	return ((void* (*)(size_t))BaseOffset(0x230D84))(size);
}
__declspec(noinline) void* operator new[](size_t size) {
	return ((void* (*)(size_t))BaseOffset(0x230D00))(size);
}

__declspec(noinline) void operator delete(void* ptr) noexcept {
	((void(*)(void*))BaseOffset(0x230D32))(ptr);
}
__declspec(noinline) void operator delete[](void* ptr) noexcept {
	((void(*)(void*))BaseOffset(0x230D32))(ptr);
}
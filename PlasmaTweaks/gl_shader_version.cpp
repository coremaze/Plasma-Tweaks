#include "pch.h"
#include "gl_shader_version.h"
#include "utils.h"
#include <windows.h>
#include <string>

void __stdcall gl_shader_prepend(std::string* shader1, std::string* shader2) {
	std::string prepend("#version 120\n");
	shader1->insert(0, prepend);
	shader2->insert(0, prepend);
	return;
}

void* gl_shader_jmp_back;
void __declspec(naked) gl_shader_version_injection() {
	__asm {
		pushad
		push eax //uncompiled shader 1
		push [ebp+8] //uncompiled shader 2
		call gl_shader_prepend
		popad

		// original code
		mov dword ptr[esi + 4], 0 

		// jmp back
		jmp [gl_shader_jmp_back]
	}
}

void gl_shader_version_initialize() {
	WriteJMP(BaseOffset(0x1A72EA), &gl_shader_version_injection);
	gl_shader_jmp_back = BaseOffset(0x1A72F1);
}
#include "pch.h"
#include "widget_icon.h"
#include "utils.h"

/*
 This is a very messy and bad way of doing things.
 However, I don't plan on making an extensive
 modding API for plasma. As such, these quick
 hacks will work for now.

 The purpose of this patch is to add the widget
 tool icon back onto the toolbar. Since Wollay
 never planned to let people create their own
 GUIs with the Plasma engine, he probably
 commented this out. However, I'd like to have
 access to it. The functionality is still there,
 the icon just needs to be put back.

 In order to do this, I am mostly copying assembly
 code from where the other icons are intiialized.
 The only things I'm changing are the name of the
 tool and the position of the icon.
*/



void* widget_std__wstring__ctor;
void* widget_sub_416D00;
void* widget_sub_419120;
void* widget_sub_418BE0;
void* widget_operator_delete;
void* widget_sub_4B7300;
void* widget_jmp_back;
wchar_t widget_radiobutton3[] = L"radiobutton3";
wchar_t widget_tool_widget[] = L"tool:widget";
wchar_t widget_space[] = L" ";
void* widget_byte_6706E4;

void __declspec(naked) widget_icon_injection() {
	__asm {
		lea eax, [widget_radiobutton3]
		lea ecx, [esp + 0x78]
		call widget_std__wstring__ctor
		lea eax, [widget_tool_widget]
		lea ecx, [esp + 0x5C]
		mov byte ptr[esp + 0x110], 1000 //36 //UNKNOWN PURPOSE
		call widget_std__wstring__ctor
		lea eax, [widget_space]
		lea ecx, [esp + 0x40]
		mov byte ptr [esp + 0x110], 1001 //37 //UNKNOWN PURPOSE
		push 0x23
		push 0x23
		push 490 //0x1C7 //Y coord
		push 0
		lea ecx, [esp + 0x88]
		push ecx
		lea edx, [esp + 0x70]
		push edx
		lea eax, [esp + 0xAC]
		push eax
		lea ecx, [esp + 0x5C]
		mov byte ptr[esp + 0x12C], 1002 //38 //UNKNOWN PURPOSE
		call widget_sub_416D00
		lea edi, [esp + 0x14]
		mov byte ptr[esp + 0x110], 1003 //39 //UNKNOWN PURPOSE
		call widget_sub_419120
		lea esi, [esp + 0x94]
		call widget_sub_418BE0
		cmp[esp + 0x54], 8
		jb section_2

		mov ecx, [esp + 0x40]
		push ecx
		call [widget_operator_delete] //Operator delete
		add esp, 4

	section_2:
		xor esi, esi
		xor edx, edx
		cmp[esp + 0x70], 8
		mov edi, 7
		mov[esp + 0x54], edi
		mov[esp + 0x50], esi
		mov word ptr[esp + 0x40], dx

		jb section_3

		mov eax, [esp + 0x5C]
		push eax
		call [widget_operator_delete] //Operator delete
		add esp, 4

	section_3:
		xor ecx, ecx
		mov byte ptr[esp + 0x110], 8
		cmp[esp + 0x8C], 1
		mov[esp + 0x70], edi
		mov[esp + 0x6C], esi
		mov word ptr[esp + 0x5C], cx
		jb section_4

		mov edx, [esp + 0x78]
		push edx
		call [widget_operator_delete] //Operator delete
		add esp, 4


	section_4:
		//restore original code
		mov eax, widget_byte_6706E4
		lea ecx, [esp + 0x40]
		jmp [widget_jmp_back]
	}
}

void widget_icon_initialize() {
	widget_std__wstring__ctor = BaseOffset(0x3DA0);
	widget_sub_416D00 = BaseOffset(0x16D00);
	widget_sub_419120 = BaseOffset(0x19120);
	widget_sub_418BE0 = BaseOffset(0x18BE0);
	widget_operator_delete = *(void**)BaseOffset(0x2523AC);
	widget_sub_4B7300 = BaseOffset(0xB7300);
	widget_byte_6706E4 = BaseOffset(0x2706E4);

	WriteJMP(BaseOffset(0x1052B6), &widget_icon_injection);

	widget_jmp_back = BaseOffset(0x1052BF);
}
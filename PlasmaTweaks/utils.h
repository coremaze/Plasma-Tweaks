#pragma once

template <typename T1, typename T2>
void* Offset(T1 x1, T2 x2) {
	return (void*)((int)x1 + (int)x2);
}

void InitBase();
void* Base();

template <typename T>
void* BaseOffset(T x1) {
	return Offset(Base(), x1);
}



template <typename T1, typename T2>
void WriteJMP(T1* _location, T2* _function) {
	char* location = (char*)_location;
	char* function = (char*)_function;

	DWORD dwOldProtection;
	VirtualProtect(location, 5, PAGE_EXECUTE_READWRITE, &dwOldProtection);

	location[0] = 0xE9; //jmp
	*((DWORD*)(location + 1)) = (DWORD)((function - location) - 5);

	VirtualProtect(location, 5, dwOldProtection, &dwOldProtection);
}
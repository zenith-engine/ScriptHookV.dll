// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

typedef void(*KeyboardHandler)(DWORD, WORD, BYTE, BOOL, BOOL, BOOL, BOOL);
typedef void(*PresentCallback)(void*);

enum eGameVersion : int
{
	VER_1_0_335_2_STEAM,
	VER_1_0_335_2_NOSTEAM,
	VER_1_0_350_1_STEAM,
	VER_1_0_350_2_NOSTEAM,
	VER_1_0_372_2_STEAM,
	VER_1_0_372_2_NOSTEAM,
	VER_1_0_393_2_STEAM,
	VER_1_0_393_2_NOSTEAM,
	VER_1_0_393_4_STEAM,
	VER_1_0_393_4_NOSTEAM,
	VER_1_0_463_1_STEAM,
	VER_1_0_463_1_NOSTEAM,
	VER_1_0_505_2_STEAM,
	VER_1_0_505_2_NOSTEAM,
	VER_1_0_573_1_STEAM,
	VER_1_0_573_1_NOSTEAM,
	VER_1_0_617_1_STEAM,
	VER_1_0_617_1_NOSTEAM,
	VER_1_0_678_1_STEAM,
	VER_1_0_678_1_NOSTEAM,
	VER_1_0_757_2_STEAM,
	VER_1_0_757_2_NOSTEAM,
	VER_1_0_757_4_STEAM,
	VER_1_0_757_4_NOSTEAM,
	VER_1_0_791_2_STEAM,
	VER_1_0_791_2_NOSTEAM,
	VER_1_0_877_1_STEAM,
	VER_1_0_877_1_NOSTEAM,
	VER_1_0_944_2_STEAM,
	VER_1_0_944_2_NOSTEAM,
	VER_1_0_1011_1_STEAM,
	VER_1_0_1011_1_NOSTEAM,
	VER_1_0_1032_1_STEAM,
	VER_1_0_1032_1_NOSTEAM,
	VER_1_0_1103_2_STEAM,
	VER_1_0_1103_2_NOSTEAM,
	VER_1_0_1180_2_STEAM,
	VER_1_0_1180_2_NOSTEAM,
	VER_1_0_1290_1_STEAM,
	VER_1_0_1290_1_NOSTEAM,
	VER_1_0_1365_1_STEAM,
	VER_1_0_1365_1_NOSTEAM,
	VER_1_0_1493_0_STEAM,
	VER_1_0_1493_0_NOSTEAM,
	VER_1_0_1493_1_STEAM,
	VER_1_0_1493_1_NOSTEAM,
	VER_1_0_1604_0_STEAM,
	VER_1_0_1604_0_NOSTEAM,
	VER_1_0_1604_1_STEAM,
	VER_1_0_1604_1_NOSTEAM,
	VER_1_0_1737_0_STEAM,
	VER_1_0_1737_0_NOSTEAM,
	VER_1_0_1737_6_STEAM,
	VER_1_0_1737_6_NOSTEAM,
	VER_1_0_1868_0_STEAM,
	VER_1_0_1868_0_NOSTEAM,
	VER_1_0_1868_1_STEAM,
	VER_1_0_1868_1_NOSTEAM,
	VER_1_0_1868_4_EPIC,
	VER_1_0_2060_0_STEAM,
	VER_1_0_2060_0_NOSTEAM,
	VER_1_0_2060_1_STEAM,
	VER_1_0_2060_1_NOSTEAM,
	VER_1_0_2189_0_STEAM,
	VER_1_0_2189_0_NOSTEAM,
	VER_1_0_2545_STEAM,
	VER_1_0_2545_0_NOSTEAM,
	VER_1_0_2612_STEAM,
	VER_1_0_2612_0_NOSTEAM,

	VER_SIZE,
	VER_UNK = -1
};

void __declspec(dllexport) scriptRegister(HMODULE module, void(*LP_SCRIPT_MAIN)()) {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress((HMODULE)0x46b5ab27, "script_register");
	((void(*)(HMODULE, void(*)()))function)(module, LP_SCRIPT_MAIN);
}

void __declspec(dllexport) scriptRegisterAdditionalThread(HMODULE module, void(*LP_SCRIPT_MAIN)()) {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress((HMODULE)0x46b5ab27, "script_register_another_thread");
	((void(*)(HMODULE, void(*)()))function)(module, LP_SCRIPT_MAIN);
}

void __declspec(dllexport) scriptUnregister(HMODULE module) {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress((HMODULE)0x46b5ab27, "script_unregister");
	((void(*)(HMODULE))function)(module);
}

void __declspec(dllexport) scriptUnregister(void(*LP_SCRIPT_MAIN)()) { // deprecated
}

void __declspec(dllexport) nativeInit(UINT64 hash) {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress((HMODULE)0x46b5ab27, "native_call_begin");
	((void(*)(UINT64))function)(hash);
}

void __declspec(dllexport) nativePush64(UINT64 val) {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress((HMODULE)0x46b5ab27, "native_push");
	((void(*)(UINT64))function)(val);
}

__declspec(dllexport) uint64_t* nativeCall() {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress((HMODULE)0x46b5ab27, "native_call_end");
	return ((uint64_t*(*)())function)();
}

__declspec(dllexport) uint64_t* getGlobalPtr(int index) {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress((HMODULE)0x46b5ab27, "get_global_ptr");
	return ((uint64_t*(*)(int))function)(index);
}

int __declspec(dllexport) createTexture(const char* fileName) {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress((HMODULE)0x46b5ab27, "create_texture");
	return ((int(*)(const char*))function)(fileName);
}

void __declspec(dllexport) drawTexture(int id, int index, int level, int time, float sizeX, float sizeY, float centerX, float centerY, float posX, float posY, float rotation, float screenHeightScaleFactor, float r, float g, float b, float a) {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress((HMODULE)0x46b5ab27, "draw_texture");
	((void(*)(int id, int index, int level, int time, float sizeX, float sizeY, float centerX, float centerY, float posX, float posY, float rotation, float screenHeightScaleFactor, float r, float g, float b, float a))function)(id, index, level, time, sizeX, sizeY, centerX, centerY, posX, posY, rotation, screenHeightScaleFactor, r, g, b, a);
}

void __declspec(dllexport) scriptWait(unsigned long waitTime) {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress((HMODULE)0x46b5ab27, "script_wait");
	((void(*)(unsigned long))function)(waitTime);
}

void __declspec(dllexport) keyboardHandlerRegister(KeyboardHandler func) {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress((HMODULE)0x46b5ab27, "keyboard_handler_register");
	((void(*)(KeyboardHandler))function)(func);
}

void __declspec(dllexport) keyboardHandlerUnregister(KeyboardHandler func) {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress((HMODULE)0x46b5ab27, "keyboard_handler_unregister");
	((void(*)(KeyboardHandler))function)(func);
}

eGameVersion __declspec(dllexport) getGameVersion() {
	static uint64_t function;
	if(!function)
		function = (uint64_t)GetProcAddress((HMODULE)0x46b5ab27, "get_game_verison");

	return ((eGameVersion(*)())function)();
}

__declspec(dllexport) BYTE *getScriptHandleBaseAddress(int handle) {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress((HMODULE)0x46b5ab27, "get_script_handle");
	return ((BYTE*(*)(int))function)(handle);
}

void __declspec(dllexport) presentCallbackRegister(PresentCallback cb) {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress((HMODULE)0x46b5ab27, "present_call_back_register");
	((void(*)(PresentCallback))function)(cb);
}

void __declspec(dllexport) presentCallbackUnregister(PresentCallback cb) {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress((HMODULE)0x46b5ab27, "present_call_back_unregister");
	((void(*)(PresentCallback))function)(cb);
}

int __declspec(dllexport) worldGetAllVehicles(int *arr, int arrSize) {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress((HMODULE)0x46b5ab27, "get_all_vehicles");
	return ((int(*)(int*, int))function)(arr, arrSize);
}

int __declspec(dllexport) worldGetAllPeds(int *arr, int arrSize) {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress((HMODULE)0x46b5ab27, "get_all_peds");
	return ((int(*)(int*, int))function)(arr, arrSize);
}

int __declspec(dllexport) worldGetAllObjects(int *arr, int arrSize) {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress((HMODULE)0x46b5ab27, "get_all_objects");
	return ((int(*)(int*, int))function)(arr, arrSize);
}

int __declspec(dllexport) worldGetAllPickups(int *arr, int arrSize) {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress((HMODULE)0x46b5ab27, "get_all_pickups");
	return ((int(*)(int*, int))function)(arr, arrSize);
}

int __declspec(dllexport) registerRawStreamingFile(const std::string& fileName, const std::string& registerAs) {
	static uint64_t function;
	if (!function)
		function = (uint64_t)GetProcAddress((HMODULE)0x46b5ab27, "register_raw_streaming_file"); 
	return ((int(*)(std::string, std::string))function)(fileName, registerAs);
}

DWORD WINAPI MainThread(LPVOID lp) {
	while (true) {
		Sleep(5000);
	}
	return 1;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
		CreateThread(0, 0, MainThread, hModule, 0, 0);
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
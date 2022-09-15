///////////////////////////////////////////////
// a small peice of code that can be used to detect a lot of permium cheats like EazyCheat - AimCheat - FullExtremo - Dx etc..
// and we can detect and kick them easily with that way as all of them hooking some directx function to be allowed to draw a menu
// so it's easy for us to catch them and kick them our ;)
// Credits: Ahmed ALi
///////////////////////////////////////////////
#include <windows.h>
#define ENDSCENE	42
DWORD pEndScene;

VOID Initialize()
{
	//D3D Hooks
	DWORD* vtbl;
	// wait for the d3dx dll
	DWORD hD3D = 0;
	do {
		hD3D = (DWORD)GetModuleHandleA("d3d9.dll");
		PAGE_READWRITE;
	} while (!hD3D);
	PAGE_READWRITE;
	DWORD adr = Mem::Pattern(hD3D, 0x128000, (PBYTE)"\xC7\x06\x00\x00\x00\x00\x89\x86\x00\x00\x00\x00\x89\x86", "xx????xx????xx");
	if (adr)
	{
		
		memcpy(&vtbl, (void*)(adr + 2), 4);
		pEndScene = (DWORD)vtbl[ENDSCENE];
	}
}

bool __forceinline IsHooked( BYTE* pbFunction )
{
  //JMP in asm
  if( pbFunction[0] == 0xE9 )
     return true;
  //JMP DWORD PTR DS:[...] // because there is two different ways for jmp in assembly
  if( pbFunction[0] == 0xFF && pbFunction[1] == 0x25 )
     return true;
   return false;
}


//Entry
int main()
{
  //Getting pEndScene address from the game
  Initialize();
  
  if( IsHooked( (BYTE*)&GetTickCount ) )
  {
  
    //Detecting all directX Cheats [EazyCheat - AimCheats - FullExtremo - Dx - DC] and all using the same method
    //Kicking hackers from the game
  }

  
}

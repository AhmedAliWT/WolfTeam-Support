# WolfTeam-Support
Hello Softnyx
I'm Ahmed Ali from Egypt, a c++/C# developer, have a lot of experience in AntiCheats and defence against Game Hacking.
Let's start
first of all, XIGNCode version that so
Softnyx support is too weak to protect the game from hackers.
and after analyzing a lot of cheats I found a lot of ways and methods that they used and we can easily detect it to decrease the number of hackers in the game.
the only thing I need is really a good respond and respect the effort that I'll give to fight against hackers, and we can continue work to detect and kick them as much as possible

Let's start taking every kind of cheaters.

# 1. Free Hacks
- They are using external method to read and write in the memory of Wolfteam.bin
- and to able to read and write externally without dll injection they are disabling a service that protect the game from read/write provided by xigncode
  called "xhunter.sys"
- that service is a kernel mode driver that strip any handle and reject it from read/write memory outside the Wolfteam process and prevent giving access to them
- disabling that is easy for hackers and xigncode doesn't check whether the service is already running or blocked.
- How they disabling "xhunter.sys" ?
- 1. xhunter.sys is located in "C:\Windows" and xigncode running it when loading after login.
- 2. cheat programmers using a code to change the attributes of the file "xhunter.sys" to read only and locked it.
- 3. so when xigncode try to load it, it fails to load it successfully, and the game goes unprotected and can be accessed from any external cheat.
## - Solutions: 
	- 1. there is a way I already coded to check if the service is already running or not, that code can be executed after wolfteam.bin is running so it checks
     	     if the service is not running so there is a hacker stop it from working to bypass game protection so we can kick them from the game.
     	     code link:https://github.com/AhmedAliWT/WolfTeam-Support/blob/main/CheckService.cpp
	- 2. another way is to remove any locked attributes and remove read only attribute from the service file, but cheaters can try to stop the service
	     after running the game so the first method is more effective.

	- 3. Features Detection: this method is check if there is a cheat feature is already ruuning or not like: "Always Head Shot" "God Mode" "No Recoil"
	     "One Hit Kill" etc... even if the cheater try to bypass any of the methods we can use this method to protect the game from the feature that 
	     affects the players. and I have a lot of feature that all cheaters use (almost all) so we can make use of it to block all hackers methods
	
# 2. Paid Hacks
Examples: Cold Hacks - EazyCheat - Aimcheats
after analyzing: these are the hacks that using different ways to cheat as they accessing the game internally by injecting dll in the game so it be hidden
from xigncode protection
- these cheats using directx hooks to draw a menu into the game to allow cheat users to use it and using it for draw ESP Names and other features.
## - Solutions:
  There is alot of solution to kick them out of the game easily and protect the game from that kind of hackers.
1. Detect DirectX Hooks: as I mentioned before these cheats (except coldhacks) is hooking directx Functions to draw their menu into the game memory
	   and I already detects all of them with a code for detect any DirectX Hooks and if there is any DirectX Hooks attached into the game so there is 
	   a cheater that playing into the game.
2. SigScans: we can detect ColdHacks usin SigScans by detecting some data from his cheat and kick him when we found it in the memory, and I already
	   SigScanning for some data and tried to open game with cold hacks and my program detects it easily, and it's very good way and hard for cold hack
	   to get it, and if he get it and update his cheat we can get another data Sigs and more and more so it's very easy to detect him and kick it easily.
3. Function callers: these cheats using some of built-in functions from Lithtech Engine and GameClientShell and Object.lto to do some features.
	   so it's very easy for us to check the caller of these functions and I already have most (if not the all) of these functions and we can check whether
	   the called is from known thread or not as the cheat creating a thread to work on it or hook directx and as I mentioned before that we can detect it.
4. Features Detection: as I already mentioned before in Free Cheats.
5. CheatEngine Detection: Xigncode using FindWindow to detect CheatEngine and it's very weak method to detect as it can be easily bypassed with
	   editing CheatEngine Window name, but I already detect it even if it's edited or modified with data bytes that the game can detect it easily.
6. There is much more methods that I already coded and we can make use of it to protect the game, and I'll be happy to help WolfTeam community 
	   and be a part of helpers to protect them from cheats as much as possible, so if you are welcome to cooperate I'm ready to provide codes and 
	   work to fight against hackers with softnyx developers.

Thank you Wolfteam support and waiting for your reply.	
email: egy.ahmedali@gmail.com

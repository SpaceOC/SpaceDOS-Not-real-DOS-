all:
	windres version.rc -O coff -o version.res
	windres icon.rc -O coff -o icon.res
	windres -F pe-i386 icon.rc -o iconX86.res
	windres -F pe-i386 version.rc -o versionX86.res
	clang++ -std=c++17 -static main.cpp commands.cpp RSP.cpp data.cpp other.cpp time.cpp counters.cpp icon.res version.res -o SpaceDOS.exe
	clang++ -m32 -std=c++17 -static main.cpp commands.cpp RSP.cpp data.cpp other.cpp time.cpp counters.cpp iconX86.res versionX86.res -o SpaceDOSx86.exe
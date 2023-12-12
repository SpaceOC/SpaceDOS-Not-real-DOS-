all:
	windres version.rc -O coff -o version.res
	windres icon.rc -O coff -o icon.res
	g++ -std=c++17 -static main.cpp data.cpp commands.cpp other.cpp time.cpp counters.cpp OOBE.cpp icon.res version.res -o SpaceDOS
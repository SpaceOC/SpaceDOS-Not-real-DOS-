all:
	windres version.rc -O coff -o version.res
	windres icon.rc -O coff -o icon.res
	g++ -std=c++17 -static main.cpp commands.cpp data.cpp other.cpp time.cpp counters.cpp icon.res version.res -o SpaceDOS
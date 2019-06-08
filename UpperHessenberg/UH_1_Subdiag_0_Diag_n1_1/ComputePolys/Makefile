CPP = g++
CPPINCLUDES = -I ../../src/ -I ../../../src/headers/
CPPWARNFLAGS = -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused
CPPFLAGS = -O3 -lstdc++ -std=c++11 

all:
	$(CPP) $(CPPINCLUDES) $(CPPFLAGS) CountCharPoly.cpp -o CountCharPoly

warn:
	$(CPP) $(CPPINCLUDES) $(CPPFLAGS) $(CPPWARNFLAGS) CountCharPoly.cpp -o CountCharPoly

clean:
	rm -f CountCharPoly

cxx=clang++
cxxflags=-Wall -std=c++14 -g
cppflags=-Isrc -Iinclude/math -MMD -MP
ldlibs=-lsfml-graphics -lsfml-system -lsfml-window

main: obj/Animation.o obj/DisjSet.o obj/Generator.o obj/Grid.o obj/K.o obj/main.o obj/PathTracer.o obj/Solver.o
	$(cxx) $(ldlibs) $^ -o $@

obj/%.o: src/%.cpp
	mkdir -p obj;
	g++ $(cppflags) $(cxxflags) -c $< -o $@

clean:
	rm -rf obj
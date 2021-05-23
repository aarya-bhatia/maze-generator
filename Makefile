cxx=clang++
cxxflags=-Wall -std=c++14 -g
cppflags=-Isrc -Isrc/math -MMD -MP
ldlibs=-lsfml-graphics -lsfml-system -lsfml-window
src=$(shell find src -name *.cpp)
objs=$(src:src/%.cpp=obj/%.o)

main: $(objs)
	$(cxx) $(ldlibs) $^ -o $@

obj/%.o: src/%.cpp
	mkdir -p obj;
	g++ $(cppflags) $(cxxflags) -c $< -o $@

info:
	@echo $(objs)

clean:
	rm -rf obj
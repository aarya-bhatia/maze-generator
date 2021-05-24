cxx=clang++
cxxflags=-Wall -std=c++14 -g -o1
incdirs=$(shell find src -type d)
incflags=$(addprefix -I, $(incdirs))
cppflags=$(incflags) -MMD -MP
ldlibs=-lsfml-graphics -lsfml-system -lsfml-window
src=$(shell find src -name *.cpp)
objs=$(src:src/%.cpp=obj/%.o)

main: $(objs)
	$(cxx) $(ldlibs) $^ -o $@

obj/%.o: src/%.cpp
	mkdir -p $(dir $@);
	g++ $(cppflags) $(cxxflags) -c $< -o $@

info:
	@echo $(cppflags)
	@echo $(objs)

clean:
	rm -rf obj
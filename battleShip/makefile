SOURCES := $(wildcard src/*.cpp)
OBJECTS := $(patsubst src/%.cpp, objects/%.o, $(SOURCES))
DEPENDS := $(patsubst src/%.cpp, deps/%.dep, $(SOURCES))

bin/program : ./bin $(OBJECTS)
	@g++ $(OBJECTS) -o $@

./bin :
	@mkdir -p bin

objects/%.o : src/%.cpp
	@g++ -c $< -I./headers -o $@

deps/%.dep : src/%.cpp
	@g++ -MM $< -MT "$@ $(patsubst %.dep, %.o, $@)" -o $@

-include $(DEPENDS)

.PHONY : clean docs
clean :
	@echo "clean up"
	@rm -rf  deps/*.dep objects/*.o bin docs/doxygen/*

docs : 
	@doxygen docs/doxygen_config/config


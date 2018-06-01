SOURCES := $(wildcard ./*.cpp)
OBJECTS := $(patsubst ./%.cpp, ./%.o, $(SOURCES))
DEPENDS := $(patsubst ./%.cpp, ./%.dep, $(SOURCES))
DEPENDS += implementation.dep
IMPLEMENTATION := ../../src/implementation.cpp
HEADERS := -I../../src -I./

test : $(OBJECTS) implementation.o
	@g++ $^ -o $@
	@./test
%.o : %.cpp 
	@g++ -c $< $(HEADERS) -o $@ 

implementation.o : $(IMPLEMENTATION) 
	@g++ -c $< $(HEADERS) -o $@

%.dep : %.cpp
	@g++ -MM $< -MT "$@ $(patsubst %.dep, %.o, $@)" -o $@ $(HEADERS)

implementation.dep : $(IMPLEMENTATION)
	@g++ -MM $< -MT "$@ $(patsubst %.dep, %.o, $@)" -o $@ $(HEADERS)

-include $(DEPENDS)

.PHONY : clean

clean :
	@echo "cleaning up"
	@rm -rf  *.dep *.o test 

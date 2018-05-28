DIR := $(sort $(dir $(wildcard ../tests/*)))
SOURCES := $(shell find $(DIR) -name '*.cpp')
OBJECTS := ${SOURCES:.cpp=.o}
IMPLEMENTS := ../src/implementation.cpp

#dir :
#	@echo $(DIR)
#	@echo $(SOURCES)
#	@echo $(OBJECTS)

$(DIR)%/test : $(DIR)%/*.o $(IMPLEMENTS)
	@echo $@ $^
	@g++ $^ -o $@
	@$@


$(DIR)%/%.o : $(DIR)%/%.cpp
	@g++ -c $< -I../headers -o $@

.PHONY : clean
clean :
	@echo "cleaning tests secondary files"
	@rm -rf ./test_1/*.o ./test_1/test

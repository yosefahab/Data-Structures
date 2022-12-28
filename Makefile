#be sure to use tabs!!
#target: dependent
#	 recepie/rule
	
CXX = clang++
LLDFLAGS ?=
CXXFLAGS = -g --std=c++17 -Wall -Werror -Wextra
# -g enables debug information,
# -Wall turns on all warnings,
# -Werror turns warnings to errors,
# -WExtra turns on extra debug information not provided by -Wall

# match all .cpp files
SOURCES = $(wildcard *.cpp)
# replace .cpp with .o
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = main

all: $(TARGET)
$(TARGET): $(OBJECTS)
	$(CXX) $(LLDFLAGS) $^ -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f *.o *.exe *.out $(TARGET)

# %.c === *.c
# $* matches whatever the % was
# $@	File name of the rule's target
# $%	The target member's name, if the rule's target is an archive
# $<	File name of the first prerequisite
# $^	List of all prerequisites
# $?	List of all prerequisites that are newer than the target
# $*	The "stem" of an implicit or pattern rule
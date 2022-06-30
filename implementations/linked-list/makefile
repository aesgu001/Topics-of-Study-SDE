# Compiler
GCC	= g++

# Compiler flags
CPPFLAGS = -Wall -Werror -Wextra -ansi -pedantic

# Target executables
TARGET = mylinkedlist

# Object files
OBJ = main.o mylinkedlist.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(GCC) $(CPPFLAGS) -o $(TARGET) $(OBJ)

main.o:	mylinkedlist.o main.cpp
	$(GCC) $(CPPFLAGS) -std=c++0x -o main.o -c main.cpp

mylinkedlist.o:	mylinkedlist.h mylinkedlist.cpp
	$(GCC) $(CPPFLAGS) -std=c++0x -o mylinkedlist.o -c mylinkedlist.cpp

clean:
	$(RM) $(TARGET) $(OBJ)
# Compiler
GCC	= g++

# Compiler flags
CPPFLAGS = -Wall -Werror -Wextra -ansi -pedantic

# Target executables
TARGET = myhashtable

# Object files
OBJ = main.o myhashtable.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(GCC) $(CPPFLAGS) -o $(TARGET) $(OBJ)

main.o:	myhashtable.o main.cpp
	$(GCC) $(CPPFLAGS) -o main.o -c main.cpp

myhashtable.o: myhashtable.h myhashtable.cpp
	$(GCC) $(CPPFLAGS) -std=c++0x -o myhashtable.o -c myhashtable.cpp

clean:
	$(RM) $(TARGET) $(OBJ)
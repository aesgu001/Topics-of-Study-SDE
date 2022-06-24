# Compiler
GCC	= g++

# Compiler flags
CPPFLAGS = -Wall -Werror -Wextra -ansi -pedantic

# Target executables
TARGET = myvector

# Object files
OBJ = main.o myvector.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(GCC) $(CPPFLAGS) -o $(TARGET) $(OBJ)

main.o:	myvector.o main.cpp
	$(GCC) $(CPPFLAGS) -o main.o -c main.cpp

myvector.o:	myvector.h myvector.cpp
	$(GCC) $(CPPFLAGS) -std=c++0x -o myvector.o -c myvector.cpp

clean:
	$(RM) $(TARGET) $(OBJ)
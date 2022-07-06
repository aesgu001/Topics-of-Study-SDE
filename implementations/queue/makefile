# Compiler
GCC	= g++

# Compiler flags
CPPFLAGS = -Wall -Werror -Wextra -ansi -pedantic

# Target executables
TARGET = myqueue

# Object files
OBJ = main.o mylinkedqueue.o myarrayqueue.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(GCC) $(CPPFLAGS) -o $(TARGET) $(OBJ)

main.o:	mylinkedqueue.o myarrayqueue.o main.cpp
	$(GCC) $(CPPFLAGS) -o main.o -c main.cpp

mylinkedqueue.o: mylinkedqueue.h mylinkedqueue.cpp
	$(GCC) $(CPPFLAGS) -std=c++0x -o mylinkedqueue.o -c mylinkedqueue.cpp

myarrayqueue.o: myarrayqueue.h myarrayqueue.cpp
	$(GCC) $(CPPFLAGS) -std=c++0x -o myarrayqueue.o -c myarrayqueue.cpp

clean:
	$(RM) $(TARGET) $(OBJ)
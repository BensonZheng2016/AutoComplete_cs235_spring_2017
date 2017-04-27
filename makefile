CC = g++
LFLAGS = -std=c++11
CFLAGS = -c -Wall

SOURCES = main.cpp trieNode.cpp trie.cpp dictionary.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE_NAME = test

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): $(OBJECTS)
	$(CC) -o $(EXECUTABLE_NAME) $(OBJECTS)

.cpp.o:
	$(CC) $(CFLAGS) $(LFLAGS) $< -o $@

clean:
	$(RM) *.o *~ $(EXECUTABLE_NAME)

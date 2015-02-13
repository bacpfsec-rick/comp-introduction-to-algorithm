CC=g++ -std=c++11
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=quicksort.cc
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=run
LIBS = 

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE):$(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *o *~ run

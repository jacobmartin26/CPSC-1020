# Config, just variables
CC=g++
CFLAGS=-Wall -g
LFLAGS=-lm
TARGET=a.out

# Generate source and object lists, also just string variables
C_SRCS := \
	$(wildcard *.cpp)

HDRS := \
	$(wildcard *.h) \

OBJS := $(patsubst %.cpp, bin/%.o, $(wildcard *.cpp))

# default target
all: compile
	@echo "All Done!"

# Link all built objects
compile: $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LFLAGS)

# Catch root directory src files
bin/%.o: %.cpp $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET)
	rm -rf bin

run: compile ClemsonPaw.ppm Disney.ppm
	./$(TARGET) ClemsonPaw.ppm Disney.ppm

which:
	@echo "FOUND SOURCES: ${C_SRCS}"
	@echo "FOUND HEADERS: ${HDRS}"

#What this part does is add essentially an alias that is what the C compiler flags ares
CC=gcc
CFLAGS=-Wall -g
LFLAGS=-lm
TARGET=out


#This part defines C_SRCS as the .c files that we are compiling, this also searches the various levels of directories the .c files we need could be in
C_SRCS	:= \
	$(wildcard *.c) \
	$(wildcard src/*.c) \
	$(wildcard src/**/*.c) \

#This part defines HDRS as the .h files that need to included when compiling our .c files if header files are necessary, searching through different folders to find them in necessary
HDRS	:= \
	$(wildcard *.h) \
        $(wildcard src/*.h) \
        $(wildcard src/**/*.h) \

#This collects our .h, .o and .c source files together
OBJS	:= $(patsubst %.c, bin/%.o, $(wildcard *.c))
OBJS	+= $(filter %.o, $(patsubst src/%.c, bin/%.o, $(C_SRCS)))


#This part just is to test to make sure the program was succesfully compiled
all:	build
			@echo "All Done"


#This is essentially equivalent to the compile command line arguments we use to compile our code
build:	$(OBJS)
			$(CC) $(OBJS) -o $(TARGET) $(LFLAGS)


#This catches all of the root directory src files we need for our code to successfully compile
bin/%.o:	%.c $(HDRS)
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) -c $< -o $@

#This in turn catches all the nested directory files for the code to compile
bin/%.o:        src/%.c $(HDRS)
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) -c $< -o $@

#This removes the .o and bin files from the directory
clean:
			rm -f $(TARGET)
			rm -rf bin

#This creates your executable
run:	build
			./$(TARGET)

#This allows you to check to make sure that each source was succesfully found
which:
			@echo "FOUND SOURCES: ${C_SRC}"
			@echo "FOUND HEADERS: ${HDRS}"
			@echo "TARGET OBJS: ${OBJS}"

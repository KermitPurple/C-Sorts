# Last updated 2020-10-24 by Shane McDonough
CC = g++# the compiler, either gcc or g++ usually
ifeq ($(CC), g++)# if compiler is gcc
	EXTENSION = .cpp# set main file extension to cpp
else#if compiler is not gcc, so probably g++ because those are the only ones I use
	EXTENSION = .c# set main file extension to c
endif
CFLAGS = -c -Wall# -c compile and assemble do not link, -Wall turns warnings on
INCLUDE = -Iinclude# folders to be included, anything following -I is the directory the compiler can now see
LIBS =# libs to be included, anything following -l is a library that is included
OBJECTS = $(patsubst src/%$(EXTENSION),bin/%.o,$(wildcard src/*$(EXTENSION)))# in bin/%.o format, all of the objects to be compiled
# previous line explained:
# patsubst replaces the first arg template with the second arg template on the variable in the third arg
# wildcard gets all the files that comply with its arg
# in this case wildcard returns every file with the main extension in the src directory
# e.g. src/main.cpp src/File1.cpp
# patsub replaces the src and the extension
# e.g. bin/main.o bin/File1/.o

all: bin $(OBJECTS)# compile everything
	$(CC) bin/*.o -o bin/test.exe $(INCLUDE) $(LIBS)
	@echo
	
bin/%.o: src/%$(EXTENSION)# create object file for %
	$(CC) $< $(CFLAGS) -o $@ $(INCLUDE) $(LIBS)

clean:# remove contents of bin
	rm -rf bin

bin:# create folder bin
	mkdir bin

test: all# compile everything then run executible
	bin/test.exe

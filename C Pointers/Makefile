# file: GNUMakefile
#
# Note that this make file uses "-g" to compile and link "debug".
#

# define a target for the application
#
all: example.exe

# define a target to link the application
#
example.exe: example.o
	g++ -g -lm example.o -o example.exe

# define targets to compile the source code
#
example.o: example.cc Makefile
	g++ -g -c example.cc -o example.o

# define a target to clean the directory
#
clean:
	rm -f example.o example.exe

#
# end of file
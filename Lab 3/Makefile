# compiler variable
CC := gcc
# selects all the files that end with .c in src/
SRC := $(wildcard src/*.c)
# replaces the .cpp with .o
OBJ := $(SRC:src/%.c=obj/%.o)
# executable variable
EXE := lab3
# compiler flags
CFLAGS := -Wall -O2 -Iinclude
# add -g flag to CFLAGS to debug

# linker flags
LFLAGS := 
# -Wall will show all warnings that are otherwise suppressed
# -O2 optimizes your code
# -I(header directory) includes all the header files needed for compilation

# first target means that this is the default target
# that will be called when you run "make"
all: $(EXE)

# links all object files to the executable
$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LFLAGS)

# compiles every source code in src/
# into an object file and placed into obj/
obj/%.o: src/%.c | obj
	$(CC) $(CFLAGS) -c $< -o $@
# $< - first subtarget (in this case src/%.c)
# $@ - self (obj/%.o)

# creates obj directory if not yet created
obj:
	mkdir $@
# removes all files and executables
clean:
	@rm $(OBJ) $(EXE)
	@rmdir obj
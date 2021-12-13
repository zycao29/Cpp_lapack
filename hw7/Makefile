###Begin MACROS
CC=g++
LD=g++
LDFLAGS=
CFLAGS=
LIBS= -llapack -lblas -lgfortran
INCLUDE=./
SOURCES=main.cpp
OBJECTS=$(SOURCES:.cc=.o)
EXEC=a.exe

###Begin targets
build: $(EXEC) $(SOURCES)

$(EXEC):$(OBJECTS)
	$(LD) $(LDFLAGS) $(OBJECTS) $(LIBS) -o $@
%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) $< -o $@
clean:
	rm -rf $(OBJECTS)
all:clean build
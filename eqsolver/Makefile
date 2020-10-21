NAME = eqsolver
OUT = BIN
CC = g++

SRCDIR = src
IDIR = include
ODIR = obj
LDIR = lib

LIBS = 

CFLAGS = -I./$(IDIR) -pedantic -Wall -Wextra -Weffc++ 

_SRCS =
SRCS = main.cpp $(patsubst %,$(SRCDIR)/%,$(_SRCS))
_DEPS =
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SRCS) $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJ)
	$(CC) -o $(OUT) $(OBJ) $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
	rm $(OUT)

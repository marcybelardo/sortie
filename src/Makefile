IDIR = ../include
CC = gcc
CFLAGS = -I$(IDIR)

ODIR = obj

_DEPS = merge.h quick.h 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = sortie.o merge.o quick.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

sortie: $(OBJ) 
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~

CC = gcc

BINDIR = ./bin
INCLUDE = ./include
LIBDIR = ./lib
SRCDIR = ./src

CFLAGS = -Wall -I$(INCLUDE) 
LDFLAGS = -L$(LIBDIR)
LDLIBS1 = -lfunc_mtfuji
LDLIBS2 = -ldata 

SRC = $(SRCDIR)/mtfuji.c
OBJ1 = $(SRCDIR)/func_mtfuji.o
LIB1 = $(LIBDIR)/libfunc_mtfuji.a
OBJ2 = $(SRCDIR)/data.o
LIB2 = $(LIBDIR)/libdata.a

TARGET = $(BINDIR)/mtfuji

$(TARGET): $(SRC) $(LIB1) $(LIB2)
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS) $(LDLIBS1) $(LDLIBS2)

$(LIB1): $(OBJ1)
	$(AR) rsv $(LIB1)
$(LIB2): $(OBJ2)
	$(AR) rsv $(LIB2)

.PHONY: tmpclean clean

tmpclean:
	rm -f $(SRCDIR)/*~
clean: tmpclean
	rm -f $(TARGET) $(LIB) $(OBJ)
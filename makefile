.PHONY: all clean
CC=gcc
CFLAGS=-Wall -Wextra
LDFLAGS=-lnetpbm
SRCS=cgr.c cgr_plot.c cgr_aux.c
OBJS=$(SRCS:.c=.o)
EXE=cgr

all: $(SRCS) $(EXE)

$(EXE): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@

.c.o:
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -rf *.o


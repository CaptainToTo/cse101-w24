CC     = gcc
BASICS = -Wall -Wextra -Werror -pedantic -Wstrict-prototypes

.PHONY: all tidy clean spotless save scan

all: release

debug:   CFLAGS = $(BASICS) -gdwarf-4
release: CFLAGS = $(BASICS)

EXE = handle
OBJ = list.o

debug: $(EXE)
release: $(EXE)

$(EXE): $(EXE).o $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

tidy:
	rm -f *.o

clean: tidy
	rm -f $(EXE)

spotless: clean
	rm -f *.txt

scan: clean
	scan-build --use-cc=$(CC) make
CC = gcc
CFLAGS = -Wall -Wformat

ftc: src/main.o src/Question1.o src/Question2.o src/Question3.o src/Question4.o src/Question5.o src/Question6.o src/Question7.o src/Pile.o src/Question9.o src/Question8.o src/perm.o src/MegaMimes.o src/symbolic_link.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c %.h
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	rm -f src/*.o
	rm -f ftc

CC = gcc
CFLAGS = -Wall -Wformat


Question1: src/Question1.o
	$(CC) $(CFLAGS) -o $@ $^ 

 
ftc: src/Question2.o
	$(CC) $(CFLAGS) -o $@ $^ 

%.o: %.c %.h
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	rm -f src/*.o
	rm -f ftc

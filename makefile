CC = gcc
CFLAGS = -Wall -Wformat


Question1: Question1.o
	$(CC) $(CFLAGS) -o $@ $^ 

 
ftc: Question2.o
	$(CC) $(CFLAGS) -o $@ $^ 

%.o: %.c %.h
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	rm -f *.o
	rm -f question2

CC=gcc
CFLAGS=-m32 -g

app: main.c 
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf *~ app

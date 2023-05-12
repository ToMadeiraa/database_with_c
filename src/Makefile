CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: modules_db


modules_db: modules.o levels.o events.o shared.o modules_db.c
	$(CC) $(CFLAGS) -c modules_db.c -o modules_db.o
	$(CC) $(CFLAGS) modules_db.o modules.o levels.o shared.o events.o -o modules_db

shared.o: shared.c
	$(CC) $(CFLAGS) -c shared.c -o shared.o

modules.o: modules.c
	$(CC) $(CFLAGS) -c modules.c -o modules.o

levels.o: levels.c
	$(CC) $(CFLAGS) -c levels.c -o levels.o

events.o: status_events.c
	$(CC) $(CFLAGS) -c status_events.c -o events.o

clean:
	rm -f *.a *.o modules_db

rebuild:
	clean all
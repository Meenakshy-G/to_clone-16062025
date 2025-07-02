CC = gcc
SRC = main.c appTimer/appTimer.c ledStatus/ledStatus.c
OBJECT = release/main.o release/appTimer.o release/ledStatus.o
CFLAGS = -Wall -Werror -IappTimer -IledStatus
DEBUG_OPTIONS = -g -O0 -c
PATH_LED = ledStatus/ledStatus.c
PATH_APPTIMER = appTimer/appTimer.c 

all : create_folder linux rpi 
	$(CC) $(CFLAGS) $(OBJECT) -o release/APPTIMER

create_folder :
	mkdir -p release debug 

linux : $(SRC)
	$(CC) -S $(CFLAGS) main.c -o release/main.s
	$(CC) -S $(CFLAGS) $(PATH_APPTIMER) -o release/appTimer.s
	$(CC) -S $(CFLAGS) $(PATH_LED) -o release/ledStatus.s

	$(CC) -c $(CFLAGS)  main.c -o release/main.o
	$(CC) $(DEBUG_OPTIONS) $(CFLAGS) main.c -o debug/main.o

	$(CC) -c $(PATH_APPTIMER) -o release/appTimer.o
	$(CC) $(DEBUG_OPTIONS) $(PATH_APPTIMER) -o debug/appTimer.o

	$(CC) -c $(PATH_LED) -o release/ledStatus.o
	$(CC) $(DEBUG_OPTIONS) $(PATH_LED) -o debug/ledStatus.o

rpi : $(SRC)
	aarch64-linux-gnu-$(CC) $(CFLAGS) $(SRC) -o release/rpi

clean : 
	rm -f release/* debug/*
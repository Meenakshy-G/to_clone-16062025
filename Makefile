CC = gcc
SRC = main.c appTimer/appTimer.c ledStatus/ledStatus.c
OBJECT = release/main.o release/appTimer.o release/ledStatus.o
CFLAGS = -Wall -Werror -IappTimer -IledStatus
CFLAGS_NOPATH = -Wall -Werror
DEBUG_OPTIONS = -g -c -O0 
PATH_LED = ledStatus/ledStatus.c
PATH_APPTIMER = appTimer/appTimer.c 
FOLDERS = release debug

all : create_folder linux rpi 
	$(CC) $(CFLAGS) $(OBJECT) -o release/APPTIMER

create_folder :
	mkdir $(FOLDERS)

linux : object_files assembly_files debug_files

object_files : 
	$(CC) -c $(CFLAGS)  main.c -o release/main.o
	$(CC) -c $(PATH_APPTIMER) -o release/appTimer.o
	$(CC) -c $(PATH_LED) -o release/ledStatus.o
	

assembly_files :  
	$(CC) -S $(CFLAGS) main.c -o release/main.s
	$(CC) -S $(CFLAGS_NOPATH) $(PATH_APPTIMER) -o release/appTimer.s
	$(CC) -S $(CFLAGS_NOPATH) $(PATH_LED) -o release/ledStatus.s

debug_files :
	$(CC) $(DEBUG_OPTIONS) $(CFLAGS) main.c -o debug/main.o
	$(CC) $(DEBUG_OPTIONS) $(PATH_APPTIMER) -o debug/appTimer.o
	$(CC) $(DEBUG_OPTIONS) $(PATH_LED) -o debug/ledStatus.o

rpi : $(SRC)
	aarch64-linux-gnu-$(CC) $(CFLAGS) $(SRC) -o release/rpi

clean : 
	rm -r $(FOLDERS)
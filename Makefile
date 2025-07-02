CC = gcc
SRC = main.c appTimer/appTimer.c ledStatus/ledStatus.c
ASSEMBLY = release/main.s release/appTimer.s release/ledStatus.s
OBJECT = release/main.o release/appTimer.o release/ledStatus.o
DEBUG = debug/main.o debug/appTimer.o debug/ledStatus.o
CFLAGS = -Wall -Werror -IappTimer -IledStatus
CFLAGS_NOPATH = -Wall -Werror
DEBUG_OPTIONS = -g -c -O0 
PATH_LED = ledStatus/ledStatus.c
PATH_APPTIMER = appTimer/appTimer.c 
FOLDERS = release debug

all : create_folder linux rpi 
	$(CC) $(CFLAGS) $(OBJECT) -o release/APPTIMER

create_folder :
	mkdir -p $(FOLDERS)
	
linux : create_folder object_files assembly_files debug_files

assembly_files : create_folder $(ASSEMBLY)
VPATH = .:appTimer:ledStatus
release/%.s : %.c
	$(CC) -S $(CFLAGS) $^ -o $@

object_files : create_folder $(OBJECT)
release/%.o : %.c
	$(CC) -c $(CFLAGS) $^ -o $@

debug_files : create_folder $(DEBUG)
debug/%.o : %.c
	$(CC) $(DEBUG_OPTIONS) $(CFLAGS) $^ -o $@

rpi : create_folder $(SRC)
	aarch64-linux-gnu-$(CC) $(CFLAGS) $(SRC) -o release/rpi

clean : 
	rm -r $(FOLDERS)
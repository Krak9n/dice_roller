CC = gcc
CFLAGS = -Wall -Wextra -O2 -g -std=gnu99
TARGET = dice-roller

all: $(TARGET)

$(TARGET): src/main.c
	$(CC) $(CFLAGS) -o $(TARGET) src/main.c 

install:
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f dice-roller ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/dice-roller

clean:
	rm -f $(TARGET)

.PHONY: all clean install

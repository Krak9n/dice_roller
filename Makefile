CC = gcc
CFLAGS = -Wall -Wextra -O2
<<<<<<< HEAD
TARGET = dice_roller
=======
TARGET = throw_dice
>>>>>>> a6ae12f (few changes)

all: $(TARGET)

$(TARGET): src/main.c
	$(CC) $(CFLAGS) -o $(TARGET) src/main.c

<<<<<<< HEAD
install: $(TARGET)
	install -m 755 $(TARGET) /usr/local/bin/

uninstall:
	rm -f /usr/local/bin/$(TARGET)
=======
.PHONY: clean
>>>>>>> a6ae12f (few changes)

clean:
	rm -f $(TARGET)

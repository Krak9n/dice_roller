CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = dice_roller

all: $(TARGET)

$(TARGET): src/main.c
	$(CC) $(CFLAGS) -o $(TARGET) src/main.c

install: $(TARGET)
	install -m 755 $(TARGET) /usr/local/bin/

uninstall:
	rm -f /usr/local/bin/$(TARGET)

clean:
	rm -f $(TARGET)

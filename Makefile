CC = gcc
CFLAGS = -Wall -Wextra -O2 -g
TARGET = throw_dice

all: $(TARGET)

$(TARGET): src/main.c
	$(CC) $(CFLAGS) -o $(TARGET) src/main.c 

.PHONY: clean

clean:
	rm -f $(TARGET)

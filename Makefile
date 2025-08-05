CC = gcc
CFLAGS = -Wall -Wextra -O2
LDFLAGS = -lncurses
SRC = main.c
OBJ = $(SRC:.c=.o)
TARGET = pagr

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET)

OBJDIR = obj
CC = gcc
CFLAGS = -Wall -Wextra -O2
LDFLAGS = -lncurses
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c,$(OBJDIR)/%.o,$(SRC))
TARGET = pagr

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR) $(TARGET)

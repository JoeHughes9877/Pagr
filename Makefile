OBJDIR = obj
CC = gcc
CFLAGS = -Wall -Wextra -O2 -Iinclude
LDFLAGS = -lncursesw
SRC = $(wildcard src/*.c) file_formats/txt.c
OBJ = $(patsubst src/%.c,$(OBJDIR)/%.o,$(filter src/%.c,$(SRC))) $(patsubst file_formats/%.c,$(OBJDIR)/%.o,$(filter file_formats/%.c,$(SRC)))
TARGET = pagr

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: file_formats/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR) $(TARGET)

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Files
SRCS = main.c traffic_light.c
OBJS = $(SRCS:.c=.o)

# Output program name
TARGET = traffic_light

# Default rule
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)

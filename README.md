# Get Next Line

## Goals

This project focuses on programming a function, `get_next_line`, that returns a line read from a file descriptor. The implementation involves learning the concept of static variables in C programming.

## Mandatory Part

### Function: get_next_line

- **Prototype:** `char *get_next_line(int fd);`
- **Turn-in Files:** get_next_line.c, get_next_line_utils.c, get_next_line.h
- **Parameters:** `fd` - The file descriptor to read from
- **Return Value:**
  - Read line: correct behavior
  - `NULL`: nothing else to read, or an error occurred
- **External Functions:** read, malloc, free
- **Description:**
  - Returns a line read from a file descriptor.
  - Repeated calls to `get_next_line()` should read the text file pointed to by the file descriptor, one line at a time.
  - The function should return the line that was read.
  - Returns `NULL` if there is nothing else to read or if an error occurred.
  - The returned line should include the terminating `\n` character, except if the end of file was reached and does not end with a `\n` character.
  - The header file `get_next_line.h` must contain at least the prototype of the `get_next_line()` function.
  - Helper functions should be added in the `get_next_line_utils.c` file.
  - Use the `-D BUFFER_SIZE=n` compiler option to define the buffer size for `read()`.

### Note

- The project must compile with and without the `-D BUFFER_SIZE` flag.
- `get_next_line()` has undefined behavior if the file pointed to by the file descriptor changed since the last call whereas `read()` didn't reach the end of the file.
- `get_next_line()` also has undefined behavior when reading a binary file.

## Bonus Part

- Develop `get_next_line()` using only one static variable.
- `get_next_line()` should manage multiple file descriptors simultaneously.

### Bonus Part Files

- get_next_line_bonus.c
- get_next_line_bonus.h
- get_next_line_utils_bonus.c

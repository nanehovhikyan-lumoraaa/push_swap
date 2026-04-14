# Get Next Line

This project has been created as part of the 42 curriculum by <nhovhiky>.

---

## Description 

`get_next_line` is a project at 42 that challenges students to create a function that returns a line read from a file descriptor. In C, reading a file line-by-line is not natively simple due to the way the `read()` function interacts with fixed buffers. This project introduces the critical concept of **static variables** and reinforces careful memory management.

## Project Goal 

- Implement a function `char *get_next_line(int fd)` that returns a single line from a file descriptor.
- Master the use of **static variables** to preserve data between successive function calls.
- Manage heap memory effectively using `malloc` and `free` to ensure no memory leaks occur.
- Ensure the function remains performant regardless of the `BUFFER_SIZE` (from 1 to 1,000,000).
- (Bonus) Manage multiple file descriptors simultaneously without losing track of the reading state for each.

## Instructions 

### Compilation

The project is compiled using `cc` with the `-Wall -Wextra -Werror` flags, along with a mandatory definition for the buffer size:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
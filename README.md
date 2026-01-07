*This project has been created as part of the 42 curriculum by moamhouc.*

# Get Next Line

## Description

The goal of the **get_next_line** project is to implement a C function that reads and returns a single line from a given file descriptor each time it is called.

The function must:

* Handle input of arbitrary length.
* Read efficiently using the `read()` system call.
* Correctly manage memory across multiple calls.

This project strengthens understanding of low-level I/O by requiring direct interaction with file descriptors and careful control of how data is consumed. It emphasizes correct state handling across successive calls so that no input is lost or reread. The use of static variables introduces persistent state management while maintaining strict memory safety.

---

## Compilation

Compile using `cc` with the required flags and define `BUFFER_SIZE` at compile time:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=n get_next_line.c get_next_line_utils.c
```

---

## Usage / Testing

* Call `get_next_line()` with a valid file descriptor (file, standard input, or redirected input).
* Each call returns the next line from the file descriptor, including the terminating `\n` if present.
* The returned line must be freed by the caller to avoid memory leaks.

Example:

```c
char *line;
while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
```

---

## Algorithm Explanation and Justification

### High-Level Flow

```c
get_next_line(fd)
        |
        v
fill_line(static_buffer, fd)
        |
        |-- read(fd, BUFFER_SIZE)
        |-- append to static buffer
        |-- stop when '\n' found or EOF
        v
static buffer contains at least one full line
        |
        v
extract_line(buffer)
        |
        |-- copy characters up to and including '\n'
        v
return extracted line
        |
        v
save_leftovers(buffer)
        |
        |-- keep remaining data after '\n'
        |-- free old buffer
        v
static buffer ready for next call
```

---

### Detailed Steps

1. **Persistent buffer**

   * A static buffer stores unread data between function calls.
   * This ensures that partially read lines are preserved until completed.

2. **Reading from the file descriptor**

   * Data is read in chunks of size `BUFFER_SIZE` using `read()`.
   * Each chunk is appended to the static buffer.
   * Reading stops as soon as a newline character (`\n`) is found or EOF is reached.

3. **Line extraction**

   * Once a newline is present (or EOF), a new string is allocated.
   * Characters are copied from the buffer up to and including the newline.

4. **Leftover management**

   * Any data after the extracted line is preserved in a new buffer.
   * The old buffer is freed to prevent memory leaks.
   * The leftover buffer becomes the static buffer for the next call.

5. **Return value**

   * The extracted line is returned.
   * If there is no more data to read, the function returns `NULL`.

---

## Supporting Functions

The following utility functions are used to ensure clean and safe string manipulation:

* `ft_strlen` – computes string length.
* `ft_strdup` – duplicates a string with proper allocation.
* `ft_strchr` – searches for a character in a string.
* `ft_strjoin` – concatenates two strings into a newly allocated buffer.
* `ft_substr` – extracts a substring from a string.

These functions are designed to:

* Handle `NULL` inputs safely.
* Allocate only what is necessary.
* Avoid memory leaks by freeing temporary buffers when required.

---

## Justification

* The algorithm avoids loading the entire file into memory, making it suitable for files of any size.
* Using a static buffer ensures efficient tracking of leftover data between calls without exposing internal state to the caller.
* Separating reading, extraction, and leftover management improves clarity, maintainability, and testability.
* Memory management is strict and deterministic: every allocation has a clear ownership and a corresponding `free()`.

---

## Resources

* 42 Subject PDF
* Manual pages: `open`, `read`, `close`
* *Handling a File by its Descriptor in C* (codequoi.com)
* File descriptor explanation video (YouTube)
* *Input-Output System Calls in C* (GeeksforGeeks)

---

## AI Usage

AI tools (such as ChatGPT) were used as a reference to better understand concepts related to low-level I/O, static variables, and memory management.

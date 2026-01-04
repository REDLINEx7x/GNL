*This project has been created as part of the 42 curriculum by moamhouc.*

# Get_Next_Line

## Description

The goal of the get_next_line project is to implement a C function that reads and returns a single line from a file descriptor each time it is called. The function must handle input of arbitrary length efficiently and correctly manage memory across multiple calls.
This project strengthens the understanding of low-level I/O behavior by requiring direct interaction with the read() system call and careful control of how data is consumed from a file descriptor. It emphasizes correct file descriptor handling across successive function calls, ensuring that input is neither lost or reread. Additionally, the use of static variables introduces state management concepts, requiring the preservation and manipulation of leftover data between calls while maintaining memory safety.

## instructions

### compilation

Compile using cc with the required flags and define BUFFER_SIZE at compile time:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=n get_next_line.c get_next_line_utils.c
```
### testing

you can call get_next_line() with a valid file descriptor (file, standard input, or redirected input).

Free the returned line after each call to avoid memory leaks.

## algorithm

Here’s a detailed explanation and justification of the **algorithm** in a style suitable for a **42 README**, incorporating your implementation:

---

## Algorithm Explanation and Justification

**Algorithm flow**

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
        |-- copy characters up to '\n' (included)
        v
 return extracted line
        |
        v
 leftovers(buffer)
        |
        |-- keep remaining data after '\n'
        |-- free old buffer
        v
 static buffer ready for next call.


4. **Supporting functions**

   * `ft_strdup`, `ft_strjoin`, `ft_strlen`, `ft_strchr`, and `ft_substr` provide essential string manipulation operations, ensuring safe memory allocation, concatenation, and search functionality.
   * These functions are carefully designed to handle `NULL` inputs and free memory when necessary, which prevents leaks and ensures stability.

**Justification**

* This algorithm avoids reading the entire file into memory, making it suitable for files of any size.
* Using a static buffer allows efficient tracking of leftover data between calls without exposing internal state to the caller.
* The modular design, separating reading, extraction, and leftover management, improves clarity, and testability.
* Memory is managed carefully: every allocation has a corresponding free, and temporary buffers are freed immediately after use.

---

## resources
* 42 Subject PDF.
* manual page for : (open, read, close).
* [Handling a File by its Descriptor in C](https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/)
* [file descriptor explanation](https://youtu.be/rW_NV6rf0rM)
* [Input-output system calls](www.geeksforgeeks.org/c/input-output-system-calls-c-create-open-close-read-write/)

### Ai usage

AI tools, such as ChatGPT, were used as a reference to understand concepts like low-level I/O, static variables, and memory management.

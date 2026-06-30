# libft

A re-implementation of standard C library functions and additional utility functions
not included in the standard library, built from scratch as part of the 42 curriculum.

## Functions

### Part 1 - Libc Functions
| Function | Description |
|----------|-------------|
| ft_isalpha | Tests for alphabetic character |
| ft_isdigit | Tests for decimal digit |
| ft_isalnum | Tests for alphanumeric character |
| ft_isascii | Tests for ASCII character |
| ft_isprint | Tests for printable character |
| ft_memset | Fills memory with a constant byte |
| ft_bzero | Zeroes a byte string |
| ft_memcpy | Copies memory area |
| ft_memmove | Copies memory area (handles overlap) |
| ft_memchr | Locates byte in byte string |
| ft_memcmp | Compares byte strings |
| ft_strlen | Computes string length |
| ft_strchr | Locates character in string |
| ft_strrchr | Locates character in string (reverse) |
| ft_strncmp | Compares strings up to n characters |
| ft_strlcpy | Size-bounded string copy |
| ft_strlcat | Size-bounded string concatenation |
| ft_strnstr | Locates substring in string |
| ft_strdup | Duplicates a string |
| ft_toupper | Converts character to uppercase |
| ft_tolower | Converts character to lowercase |
| ft_atoi | Converts string to integer |
| ft_calloc | Allocates and zeroes memory |

### Part 2 - Additional Functions
| Function | Description |
|----------|-------------|
| ft_substr | Extracts a substring from a string |
| ft_strjoin | Joins two strings into a new one |
| ft_strtrim | Trims characters from both ends of a string |
| ft_split | Splits a string by a delimiter into an array |
| ft_itoa | Converts an integer to a string |
| ft_strmapi | Applies a function to each character, returning a new string |
| ft_striteri | Applies a function to each character in place |
| ft_putchar_fd | Outputs a character to a file descriptor |
| ft_putstr_fd | Outputs a string to a file descriptor |
| ft_putendl_fd | Outputs a string followed by a newline to a file descriptor |
| ft_putnbr_fd | Outputs an integer to a file descriptor |

### Part 3 - Linked List Functions
| Function | Description |
|----------|-------------|
| ft_lstnew | Creates a new list node |
| ft_lstadd_front | Adds a node to the front of the list |
| ft_lstsize | Returns the number of nodes in the list |
| ft_lstlast | Returns the last node of the list |
| ft_lstadd_back | Adds a node to the back of the list |
| ft_lstdelone | Deletes a node without freeing the list |
| ft_lstclear | Deletes and frees the entire list |
| ft_lstiter | Applies a function to each node's content |
| ft_lstmap | Applies a function to each node, returning a new list |

## Usage

```bash
make        # compile the library
make clean  # remove object files
make fclean # remove object files and library
make re     # recompile everything
```

## Resources

- https://cppreference.com/c/header
- https://www.w3schools.com/c/c_ref_stdlib.php
- https://www.geeksforgeeks.org/c/c-long/
- https://www.geeksforgeeks.org/c/constants-in-c/
- https://en.wikipedia.org/wiki/Struct_(C_programming_language)
- https://www.geeksforgeeks.org/c/structures-c/

AI tools (Gemini and Claude) were used to better understand concepts such as data structures, Makefiles, and headers, as well as to clarify errors and misunderstandings. In more challenging cases, the Socratic method was used to guide the reasoning process rather than receive direct answers.

## Author

gustde-s | 42
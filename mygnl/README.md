*This activity has been created as part of the 42 curriculum by alexdos.*

## Description

get_next_line is a C function that reads one line at a time from a file descriptor.

Each call returns the next line, including the \n character, or NULL when there is nothing left to read.

It uses a static variable to retain unread data between calls.

## Instructions

You will compile with cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c get_next_line.h

Then run a.out and write what you want

## Resources

- [Static variables](https://www.geeksforgeeks.org/c/static-variables-in-c/)
- [Youtube](https://https://www.youtube.com/)
- [42 Norm doc](https://github.com/42School/norminette)

## Algorithm

Data is accumulated in a static variable stash between calls, read chunk by chunk until a \n is found.
This approach was chosen because it reads as little as possible at each call, avoids loading the entire file into memory, and correctly handles any BUFFER_SIZE value.

## AI usage

I used AI claude as a learning assistant like i would for a peer that can help me understand new concepts in complement with the documentation
For exemple for the static variables and the buffer usage they are new notions on this project
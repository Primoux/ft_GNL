# get_next_line

Reads a file descriptor one line at a time, returning each line including its trailing newline, then `NULL` at end of file. A 42 Common Core project about buffering and static state.

## Usage

Compile the sources together with your program, choosing the buffer size at compile time:

```bash
cc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

```c
#include "get_next_line.h"

int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);  // the caller owns each line
}
close(fd);
```

## The two versions

| Files | Behaviour |
|---|---|
| `get_next_line.c` + `get_next_line_utils.c` | the mandatory part: one static buffer, a single file descriptor at a time |
| `get_next_line_bonus.c` + `get_next_line_utils_bonus.c` | the bonus: keeps one buffer **per file descriptor**, so several files can be read in parallel without losing their position |

`BUFFER_SIZE` is a compile-time define and the code has to work for any value, from 1 upward.

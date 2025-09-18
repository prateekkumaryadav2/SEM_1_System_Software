<<COMMENT_BLOCK
File descriptors are integer handles used by the operating system to access files and other input/output resources (like pipes, sockets, and devices).

When a process opens a file, the OS returns a file descriptor (an integer, e.g., 0, 1, 2, 3, ...).
Standard file descriptors:
  0: Standard input (stdin)
  1: Standard output (stdout)
  2: Standard error (stderr)
File descriptors are used in system calls (like read(), write(), close()) to identify which file or resource to operate on.

In summary:
A file descriptor is a unique number that represents an open file or I/O resource in a process.
COMMENT_BLOCK
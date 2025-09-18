# chmod +x 1_shell_a.sh
# make the file executable

# to create a fifo pipeline for ipc, allowing processes to communicate by readuing and writing
mkfifo myfifo

# Termminal 1
cat < myfifo
# it will be waiting for any response coming from other side using this pipeline

# Terminal 2
echo "communicating through fifo" > myfifo
# this will pass message through the pipeline

# A FIFO file (also called a named pipe) is a special type of file used for inter-process communication (IPC) in Unix-like systems, including macOS.

# FIFO stands for "First In, First Out."
# It allows processes to communicate by reading and writing data in a queue-like manner.
# You can create a FIFO file using the command:
# Data written to the FIFO by one process can be read by another process.
# Unlike regular files, FIFO files do not store data permanently; they just pass data between processes.
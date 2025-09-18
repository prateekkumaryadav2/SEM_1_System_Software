gcc inflp.c -o inflp
./inflp &
# it then returns the process id and starts running in the background

# ps == proc in linux
ps -j
# Print information associated with the following keywords: user, pid, ppid, pgid, sess, jobc, state, tt, time, and command

kill <pid> 
# or
kill -9 <pid>
# to kill the process
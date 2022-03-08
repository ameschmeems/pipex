# pipex
A 42 school project with the aim of recreating the functionality of piping in the bash shell.

## Details

pipex is made for unix systems. Compile with make and run with "./pipex *input_file_name* *any number of bash commands* *output_file_name*". The behavior duplicates
"< *input_file_name* *command 1* | *command 2* | ... | *command n* > *output_file_name*" in bash.

## Main concepts learned:
* Processes in unix
* Forks
* Pipes

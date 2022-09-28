# pipex
This project aims to deepen your understanding of the two concepts that you already know: Redirections and Pipes. It is an introductory project for the bigger UNIX projects that will appear later on in the cursus.

External functs.:
• open, close, read, write, malloc, free, perror, strerror, access, dup, dup2, execve, exit, fork, pipe, unlink, wait, waitpid
• ft_printf and any equivalent YOU coded


Your program will be executed as follows:
  ./pipex file1 cmd1 cmd2 file2
  
It must take 4 arguments:

• file1 and file2 are file names.

• cmd1 and cmd2 are shell commands with their parameters.


 $> ./pipex infile "ls -l" "wc -l" outfile
 
Should behave like: < infile ls -l | wc -l > outfile

$> ./pipex infile "grep a1" "wc -w" outfile

Should behave like: < infile grep a1 | wc -w > outfile


Your project must comply with the following rules: 

• You have to turn in a Makefile which will compile your source files. It must not relink.

• You have to handle errors thoroughly. In no way your program should quit unex- pectedly (segmentation fault, bus error, double free, and so forth).

• Your program mustn’t have memory leaks.

• If you have any doubt, handle the errors like the shell command:
     < file1 cmd1 | cmd2 > file2
     
     
     You will get extra points if you:

• Handle multiple pipes.

This:
         $> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
         
Should behave like:

         < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
         
• Support « and » when the first parameter is "here_doc". This:

         $> ./pipex here_doc LIMITER cmd cmd1 file
         
Should behave like:
         cmd << LIMITER | cmd1 >> file


Commands Implemented in Shell:

    Internal Commands:

        1.) exit:
                Terminates the shell and exit the program.
        
        2.) echo [OPTION] [Argument]:
                Displays whatever is wrriten after the word echo
                on terminal.
                
                I have implemented following options:
                
                i.) echo -n [Argument]:
                         This will delete the new line after the 
                         printing is completed and will directly
                         next to the last argument print the next
                         prompt of the shell.

                ii.) echo -e [Argument]:
                        This command will take only one argument.
                        After pressing enter it will give another
                        prompt where one needs to enter a single argument
                        and the result will be the concatenation of both
                        the arguments. There is no need to provide a "\" 
                        like the bash shell after the first argument.

        3.) cd [Argument]:
                Allow us to move to any directories or to change our
                path.

                I have implemented two options:

                i.)     -L : Prints path of symbolic link
                ii.)    -P : Prints path of actual link

        4.) history [OPTION] :
                This command will help print all the commands
                executed in the current running process of the Shell.

                I have implemented two options:

                i.)    -c : Clears all the past history of commands.
                ii.)   -d [int] : Clears the line number int of the history.

        5.) pwd:
                 This command will help print the current working
                 directory. This command doesn't have any other options
                 using which one can print.

                 I have implemented two options:

                 i.)     -L : Prints path of symbolic link
                 ii.)    -P : Prints path of actual link

    External Commands:

        1.) ls [OPTION] [Argument]:
                Displays all the files and directories present in
                the current directory.

                I have implemented two options:

                i.) ls -a :
                        This will show all the hidden files in the
                        directory.

                ii.) ls -i :
                        This will show the location index of all
                        the files present in the directory.

        2.) date [OPTION] :
                Displays the current date and time of the system
                at the moment.

                I have implemented two options:

                i.) date -u : 
			            This command will give the date time in the
                        UTC format that is the Greenwich Mean Time
                        format.

                ii.) date -R :
                        This command will print the date and time like
                        "Sat, Sep 26 2020 07:09:45 +0530" rather than
                        "Sat Sep 26 07:09:45 IST 2020".

        3.) mkdir [OPTION] [Argument] :
                Creates the new empty directory in the current path.

                I have implemented two options:

                i) mkdir -v [Argument] :
			            Creates a new directory if not already present
                        and prints the appropriate message.

		        ii) mkdir -m [Argument] :
			            This creates a directory that has the permission
                        to read, write and change the directory.

        4.) rm [OPTION] [Argument] :
                It deletes the file if present in the current directory.

                I have implemented two options:

                i) rm -v [Argument] :
			        Deletes the file if it exists and prints the
                    appropriate message.

		        ii) rm -f [Argument] :
			        Forcefully deletes the file.

        5.) cat [OPTION] [Argument] :
                Helps in reading the files.

                I have implemented two options:

                i.) cat -n:
                        Displays the line number along with the content
                        of the line.

                ii.) cat -E:
                        Highlights the end of the line by the "$" symbol.

Handling of Corner Cases/Errors:

	i)   While putting the path in the execl() command I found that if
             I went to some other directory then commands like mkdir(), rm(),
             ls() etc. will not work, so I handled this error by defining a
             real path for all the files. Therefore by using realpath I was
             able to handle the files properly and avoided the corner 
             case/error.

	ii)  In this shell, many commands like mkdir(), rm() etc require an
             argument, so I have handled this by putting an error statement
             for these commands whenever they are executed without an
             argument prompting the user to put an argument.

        iii) If an argument is entered that is not in the scope of the
             shell than the program says the invalid command or if there
             are too many or too less arguments are there than the program
             says invalid command.

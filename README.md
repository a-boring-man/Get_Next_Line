# Get_Next_Line

A early 42 school project

the goal was to create a function that read a file one line at a time with a buffer size of variable lenght.
The project has for goal to teach use the use of static variable.

Bonus for this project requir us to use only one static variable and to be able to operate on multiple file descriptor at a time.

I set to myself an additionnal challeng of not using a static structure and doing it using only 3 function while of course respecting the 42 norm for function size and number of parameter variable declaration and so on.

my thoughs on this project : i realy like it, by talking to other people i realize that my implementation was indeed unique and allow me to set these extrat rule to myself.

Most people implemented a memcopy to copy what was left inside the buffer to the beguinning of it for the next function call, whereas i change my reading function to remplace read caracter by 0 then skipping all 0 until buffer_size at the beguinning of the call. differente implementation lead to great exchange on the project.

for clarity reason I reorganize my none bonus files into more readable code.
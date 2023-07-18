![](https://github.com/a-boring-man/Get_Next_Line/blob/main/125_score_icon.png)

# Get_Next_Line

An early 42 school project aimed to teach us how to use static variables by creating a function that read lines from a file one line at a time with a variable-length buffer.

## Bonus

The bonus for this project requires us to only use a single static variable and to be able to operate on multiple file descriptors at a time. I set myself the additional challenge of not using a static structure and doing it using only 3 functions, while of course respecting the 42 norm for function size, number of parameter variable declarations, and so on.

## Thoughts and Implementation

I really like this project. After talking to other people, I realized that my implementation was indeed unique and allowed me to set these additional rules for myself.

Most people I spoke with implemented a memcopy to copy the remaining data in the buffer to the beginning of the buffer for the next function call. I changed my reading function to replace read characters with 0s and then skip the necessary number of 0s at the beginning of the call. Even for a small project, different implementations lead to great exchanges.

For clarity's sake, I reorganized my non-bonus files into more readable code.

# What's junity-stack and how to use it
Junity-Stack 1.1, A stack simulator.
Junity-stack is a stack simulation language with a built-in stack of 3590 elements (actually 3600, but I removed 10 for security). (in junity-stack, all elements mean a character).
This version supports 10 instructions
1. <: push an element to the bottom of the stack, which is the next character next to the instruction.
2. \[: push a user input element to the bottom of the stack, and a prompt "input:" will appear
3. >: pop up an element
4. \]: pop up an element and display it on the screen (this character is a single line).
5. -: pop all the elements on the stack (only move the pointer at the top of the stack to the bottom of the stack, and do not delete the elements).
6. =: pop all the elements out of the stack and output them in the way of ']' according to the order of the stack.
7. O: output the next character
8. T: move the stack top pointer to the next number (e.g. T12)
9. @: output all elements from the bottom of the stack to the top of the stack (no line breaks)
10. $: output all elements from top to bottom of stack (no line breaks)Junity stack is a stack simulation language with a built-in stack of 3590 elements (actually 3600, but I removed 10 for security). (in junity stack, all elements are one character).
Written by junity.E-mail:junity@junity.top.
Suggestions, comments and questions are welcome.
# Command helps
Junity-Stack 1.1, A stack simulator.
Usage: jstack \[Path\] \[--help\]
If there are no parameters, it runs in an interactive interface.

Path   : The path to the file to run.
--help : display help information.

Written by junity.E-mail:junity@junity.top.
Suggestions, comments and questions are welcome.

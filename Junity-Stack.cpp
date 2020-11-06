#include<stdio.h>
#include<string.h>
#define ENDLINE putchar('\n')
char stack[3600];
int top = -1;
int tmp;

const char* help = "Junity-Stack 1.1, A stack simulator.\n"
"Usage: jstack [Path] [--help]\n"
"If there are no parameters, it runs in an interactive interface.\n"
"\n"
"Path   : The path to the file to run.\n"
"--help : display help information.\n"
"\n"
"Written by junity.E-mail:junity@junity.top.\n"
"Suggestions, comments and questions are welcome.\n";

const char* document = "Junity-Stack 1.1, A stack simulator.\n"
"Junity-stack is a stack simulation language with a built-in stack of 3590 elements (actually 3600, but I removed 10 for security). (in junity-stack, all elements mean a character).\n"
"This version supports 10 instructions\n"
"1. <: push an element to the bottom of the stack, which is the next character next to the instruction.\n"
"2. [: push a user input element to the bottom of the stack, and a prompt \"input:\" will appear\n"
"3. >: pop up an element\n"
"4. ]: pop up an element and display it on the screen (this character is a single line).\n"
"5. -: pop all the elements on the stack (only move the pointer at the top of the stack to the bottom of the stack, and do not delete the elements).\n"
"6. =: pop all the elements out of the stack and output them in the way of ']' according to the order of the stack.\n"
"7. O: output the next character\n"
"8. T: move the stack top pointer to the next number (e.g. T12)\n"
"9. @: output all elements from the bottom of the stack to the top of the stack (no line breaks)\n"
"10. $: output all elements from top to bottom of stack (no line breaks)Junity stack is a stack simulation language with a built-in stack of 3590 elements (actually 3600, but I removed 10 for security). (in junity stack, all elements are one character).\n"
"Written by junity.E-mail:junity@junity.top.\n"
"Suggestions, comments and questions are welcome.\n";

int isdigit(char ch)
{
    return ch >= '0' && ch <= '9';
}

void push(char data) {
    stack[++top] = data;
}

char pop() {
    if (top >= 0)
        return stack[top--];
    else printf("Out of Stack\n");
}

char getData() {
    char ch;
    printf("Input:");
    scanf("%c", &ch);
    getchar();
    return ch;
}

void RunCode(char* order) {
    int len = strlen(order);
    for (int i = 0; i < len; i++)
        switch (order[i]) {
        case '<':push(order[++i]); break;
        case '[':push(getData()); break;
        case '>':pop(); break;
        case ']':putchar(pop()); ENDLINE; break;
        case '-':top = -1; break;
        case '=':
            printf("All datas in the stack:\n");
            for (int i = top; i >= 0; i--)
                printf("%c\n", stack[i]);
            ENDLINE;
            top = -1;
            break;
        case 'o':putchar(order[++i]); ENDLINE; break;
        case 't':
            tmp = 0;
            while (isdigit(order[++i]))
                tmp = tmp * 10 + order[i] - '0';
            if (tmp - 1 > 3690)
                printf("Index is out of stack!\n");
            else top = tmp - 1;

            break;
        case '@':
            for (int i = 0; i <= top; i++)
                putchar(stack[i]);
            ENDLINE;
            break;
        case '$':
            for (int i = top; i >= 0; i--)
                putchar(stack[i]);
            ENDLINE;
            break;
        default:printf("Error command:%c\n", order[i]); return;
        }
}

int main(int argc, char** argv) {
    if (argc == 1) {
        char command[255];
        printf("Input \"exit\" or Ctrl+C to exit.\n");
        printf("Input command:");
        gets_s(command, 250);
        while (strcmp(command, "exit")) {
            RunCode(command);
            printf("Input command:");
            gets_s(command, 250);
        }
    }
    else {
        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "--help") == 0) {
                printf(help);
            }
            else if (strcmp(argv[i], "--doctment"))printf(document);
            else {
                FILE* fp = fopen(argv[1], "r");
                if (fp == NULL) {
                    printf("Cannot open the file:%s.Please check if the file exists and if you have permission.\n", argv[1]);
                    return 0;
                }
                char command[3600] = "";
                while (fgets(command, 3590, fp) != NULL)
                    RunCode(command);
                fclose(fp);
            }
        }
    }
    printf("\n");
}

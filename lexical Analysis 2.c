#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
// Keywords list
char keywords[10][10] = {"int","char","float","if","else","for","while","return","break","continue"};

int isKeyword(char *str) {
    int i;
    for(i=0; i<10; i++) {
        if(strcmp(keywords[i], str) == 0)
            return 1;
    }
    return 0;
}

int isDelimiter(char ch) {
    return (ch == ' ' || ch == '\t' || ch == '\n' ||
            ch == ';' || ch == ',' || ch == '(' || ch == ')' || ch == '{' || ch == '}');
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' ||
            ch == '/' || ch == '=' || ch == '<' || ch == '>');
}

void lexicalAnalyzer(const char *code) {
    char buffer[MAX];
    int i=0, k=0;
    char c;

    while((c = code[k++]) != '\0') {
        if(isDelimiter(c)) {
            if(i != 0) {
                buffer[i] = '\0';
                if(isKeyword(buffer))
                    printf("%s : Keyword\n", buffer);
                else if(isdigit(buffer[0]))
                    printf("%s : Number\n", buffer);
                else
                    printf("%s : Identifier\n", buffer);
                i=0;
            }
            if(c != ' ' && c != '\n' && c != '\t')
                printf("%c : Delimiter\n", c);
        }
        else if(isOperator(c)) {
            printf("%c : Operator\n", c);
        }
        else {
            buffer[i++] = c;
        }
    }

    }

int main() {
    //Put your input code here directly
    const char code[] = "int a = 5; a = a + 10;";

    printf("Lexical Analysis:\n");
    lexicalAnalyzer(code);

    return 0;
}






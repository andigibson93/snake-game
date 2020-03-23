#include <stdio.h>
#include <ctype.h>

int main() {
FILE* input = stdin;
FILE* output = stdout;
char c;
while((c=getc(input)) != EOF) {
if(!isalpha(c))
continue;
c=toupper(c);
putc(c,output);
}
return 0;
}

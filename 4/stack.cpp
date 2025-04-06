#include <stdio.h>
#include <stdlib.h>

int top = -1;
int stack[100];

void push(int x)
{
      stack[++top] = x;
}

int pop()
{
      top--;
      return stack[top + 1];
}

int main(void)
{
      int a, b;
      char s[100];
      while (scanf("%s", s) != EOF)
      {
            if (s[0] == '+')
            {
                  a = pop();
                  b = pop();
                  push(a + b);
            }
            else if (s[0] == '-')
            {
                  a = pop();
                  b = pop();
                  push(a - b);
            }
            else if (s[0] == '*')
            {
                  a = pop();
                  b = pop();
                  push(a * b);
            }
            else
            {
                  push(atoi(s));
            }
      }
      printf("%d\n", pop());
      return 0;
}
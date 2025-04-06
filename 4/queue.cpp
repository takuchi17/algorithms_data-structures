#include <stdio.h>

#define LEN 100

typedef struct process
{
      char name[100];
      int time;
} Process;

Process queue[100];
int head = 0, tail = 0;

void enqueue(Process p)
{
      queue[tail] = p;
      tail = (tail + 1) % LEN;
}

Process dequeue()
{
      Process p = queue[head];
      head = (head + 1) % LEN;
      return p;
}

int main(void)
{
      // 入力
      int n, q;
      scanf("%d %d", &n, &q);
      for (int i = 0; i < n; i++)
      {
            Process p;
            scanf("%s %d", p.name, &p.time);
            enqueue(p);
      }

      // 処理
      int count = 0;
      while (head != tail)
      {
            Process p = dequeue();
            if (p.time > q)
            {
                  p.time -= q;
                  count += q;
                  enqueue(p);
            }
            else
            {
                  count += p.time;
                  printf("%s %d\n", p.name, count);
            }
      }

      return 0;
}
#include <iostream>
using namespace std;

int main(void)
{

      // 入力
      int N;
      int A[100];
      cin >> N;
      for (int i = 0; i < N; i++)
      {
            cin >> A[i];
      }
      // ソート
      int swCount = 0;
      for (int i = 0; i < N - 1; i++)
      {
            int minJ = i;
            for (int j = i; j < N; j++)
            {
                  if (A[minJ] > A[j])
                  {
                        minJ = j;
                        swCount++;
                  }
            }
            if (i != minJ)
                  swap(A[i], A[minJ]);
      }

      // 出力
      for (int i = 0; i < N; i++)
      {
            cout << A[i];
            if (i != N - 1)
            {
                  cout << " ";
            }
      }
      cout << endl;
      cout << swCount << endl;
      return 0;
}
#include <iostream>
using namespace std;

int main(void)
{
      // 入力
      int A[100], N;
      cin >> N;
      for (int i = 0; i < N; i++)
      {
            cin >> A[i];
      }

      // ソート
      int swCount = 0;
      bool isContinuous = true;

      for (int i = 0; isContinuous; i++)
      {
            isContinuous = false;
            for (int j = N - 1; j > i; j--)
            {
                  if (A[j] < A[j - 1])
                  {
                        swap(A[j], A[j - 1]);
                        isContinuous = true;
                        swCount++;
                  }
            }
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
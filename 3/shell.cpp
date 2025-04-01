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
      int m = 3;
      int g[m] = {4, 3, 1};
      int cnt = 0;
      for (int i = 0; i < m; i++)
      {
            for (int j = g[i]; j < N; j++)
            {
                  int currentEle = A[j];
                  int k = j - g[i];
                  while (k >= 0 && A[k] > currentEle)
                  {
                        A[k + g[i]] = A[k];
                        k -= g[i];
                        cnt++;
                  }
                  A[k + g[i]] = currentEle;
            }
      }

      // 出力
      cout << m << endl;
      for (int i = 0; i < m; i++)
      {
            cout << g[i];
            if (i != m - 1)
            {
                  cout << " ";
            }
      }
      cout << endl;

      for (int i = 0; i < N; i++)
      {
            cout << A[i] << endl;
      }
      return 0;
}
// 入力
// 1 行目にカードの枚数 N が与えられます。 2 行目に N 枚のカードが与えられます。各カードは絵柄と数字のペアを表す２文字であり、隣合うカードは１つの空白で区切られています。

// 出力
// 1 行目に、バブルソートによって整列されたカードを順番に出力してください。隣合うカードは１つの空白で区切ってください。
// 2 行目に、この出力が安定か否か（Stable またはNot stable）を出力してください。
// 3 行目に、選択ソートによって整列されたカードを順番に出力してください。隣合うカードは１つの空白で区切ってください。
// 4 行目に、この出力が安定か否か（Stable またはNot stable）を出力してください。

// 制約
// 1 ≤ N ≤ 36
// 入力例 1
// 5
// H4 C9 S4 D2 C3
// 出力例 1
// D2 C3 H4 S4 C9
// Stable
// D2 C3 S4 H4 C9
// Not stable
#include <iostream>
using namespace std;

struct Card
{
      char suit;
      int value;
};

bool isStable(Card C1[], Card C2[], int N)
{
      for (int i = 0; i < N; i++)
      {
            if (C1[i].suit != C2[i].suit)
            {
                  return false;
            }
      }
      return true;
}

int main(void)
{
      // 入力
      int N;
      Card C1[100], C2[100];
      cin >> N;
      for (int i = 0; i < N; i++)
      {
            cin >> C1[i].suit >> C1[i].value;
            C2[i] = C1[i];
      }

      // バブルソート
      bool isCountinuous = true;
      for (int i = 0; isCountinuous; i++)
      {
            isCountinuous = false;
            for (int j = N - 1; j > i; j--)
            {
                  if (C1[j].value < C1[j - 1].value)
                  {
                        swap(C1[j], C1[j - 1]);
                        isCountinuous = true;
                  }
            }
      }

      // 選択ソート
      for (int i = 0; i < N - 1; i++)
      {
            int minJ = i;
            for (int j = i; j < N; j++)
            {
                  if (C2[minJ].value > C2[j].value)
                        minJ = j;
            }
            if (minJ != i)
            {
                  swap(C2[i], C2[minJ]);
            }
      }

      // バブルソート出力
      for (int i = 0; i < N; i++)
      {
            cout << C1[i].suit << C1[i].value;
            if (i != N - 1)
            {
                  cout << " ";
            }
      }
      cout << endl;
      cout << "Stable" << endl;

      // 選択ソート出力
      for (int i = 0; i < N; i++)
      {
            cout << C2[i].suit << C2[i].value;
            if (i != N - 1)
            {
                  cout << " ";
            }
      }
      cout << endl;
      if (isStable(C1, C2, N))
      {
            cout << "Stable" << endl;
      }
      else
      {
            cout << "Not Stable" << endl;
      }
      return 0;
}
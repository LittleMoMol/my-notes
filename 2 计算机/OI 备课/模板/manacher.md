# P3805 【模板】manacher
## 题目描述
给出一个只由小写英文字符 $\texttt a,\texttt b,\texttt c,\ldots\texttt y,\texttt z$ 组成的字符串 $S$ ,求 $S$ 中最长回文串的长度 。
字符串长度为 $n$。
## 输入格式
一行小写英文字符 $\texttt a,\texttt b,\texttt c,\cdots,\texttt y,\texttt z$ 组成的字符串 $S$。
## 输出格式
一个整数表示答案。
## 输入输出样例 #1
### 输入 #1
```
aaa
```
### 输出 #1
```
3
```
## 说明/提示
$1\le n\le 1.1\times 10^7$。
# 代码
```cpp
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 4e7 + 10;

int p[N];
int n, ans;
char a[N], b[N];

void initiative()
{
    int k = 0;
    b[k ++ ] = '$';
    b[k ++ ] = '#';
    for (int i = 1; i <= n; i ++ )
    {
        b[k ++ ] = a[i];
        b[k ++ ] = '#';
    }
    n = k - 1;
    return;
}

void manacher()
{
    int mr = 0, mid;
    for (int i = 1; i <= n; i ++ )
    {
        if (i <= mr) p[i] = min(mr - i, p[2 * mid - i]);
        else p[i] = 0;
        while (b[i + p[i]] == b[i - p[i]]) p[i] ++ ;
        if (i + p[i] > mr) mr = i + p[i], mid = i;
    }
    return;
}

int main()
{
    scanf("%s", a + 1);
    n = strlen(a + 1);
    initiative();
    manacher();
    for (int i = 1; i <= n; i ++ ) ans = max(ans, p[i]);
    printf("%d\n", ans - 1);
    return 0;
}
```
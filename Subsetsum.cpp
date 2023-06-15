#include <bits/stdc++.h>
using namespace std;

int x[100000];
int n;
bool solve(int target)
{
    set<int> sumcnt;
    sumcnt.insert(0);
    set<int> dummy;
    for (int i = 0; i < n; i++)
    {
        int a = x[i];

        dummy.clear();

        for (auto it = sumcnt.begin(); it != sumcnt.end(); it++)
        {
            int x = *it + a;
            if (x <= target)
                dummy.insert(*it + a);
        }

        for (auto it = dummy.begin(); it != dummy.end(); it++)
        {
            sumcnt.insert(*it);
        }
    }

    int last = *sumcnt.rbegin();

    if (last == target)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    for (int i = 1;i <= 100;i++)
    {
        if (solve(i))
        {
            cout << i << "\n";
           
        }
    }
}

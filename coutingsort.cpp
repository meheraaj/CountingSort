
#include<bits/stdc++.h>
using namespace std;



vector<int> countingsort(vector<int> &a)
{
    int s = a.size();
    int m =  0;
    for(int i =0; i<s; i++)
    {
        m = max(m,a[i]);
    }
    vector<int> countnum(m+1 ,0);
    for(int i =0; i<s; i++)
        countnum[a[i]]++;
    for(int i =1; i<=m; i++)
        countnum[i]+= countnum[i-1];
    vector<int> outputarray(s);
    for(int i = s-1; i>=0; i--)
    {

        outputarray[countnum[a[i]]-1] = a[i];
        countnum[a[i]]--;
    }
    return outputarray;
}


int main()
{

    int n;
    vector<int> arr;
    cin >> n;
    for(int i =0; i<n; i++)
        {
            int x;cin >> x;
        arr.push_back(x);
        }
    vector<int> op = countingsort(arr);

    for(int i =0; i<n; i++)
        cout << op[i] << " ";

    return 0;
}

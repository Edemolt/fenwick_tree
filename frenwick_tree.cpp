#include <bits/stdc++.h>
using namespace std;

class FenwickTree
{
    vector<int> bit;
    int n;

public:
    FenwickTree(int n)
    {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update_util(int ind, int val)
    {
        ind += 1; // one based indexing
        while (ind <= n)
        {
            bit[ind] += val;
            ind += (ind & (-ind)); // updating the index
        }
    }

    void build(vector<int> &arr)
    {
        for (int i = 0; i < n; i++)
        {
            update_util(i, arr[i]);
        }
    }

    void update(vector<int> &arr, int ind, int val)
    {
        int diff = val - arr[ind];
        arr[ind] = val;
        update_util(ind, diff);
    }

    int find_sum(int ind)
    {
        int ans = 0;
        ind += 1;
        while (ind > 0)
        {
            ans += bit[ind];
            ind -= (ind & (-ind));
        }
        return ans;
    }

    int find_range_sum(int l, int r)
    {
        return find_sum(r) - find_sum(l - 1);
    }
};

int main()
{
    int n;
    cin >> n;
    FenwickTree tree(n);
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    tree.build(arr);
    cout << "sum of range -> " << tree.find_range_sum(2, 6) << endl;
    tree.update(arr, 5, 12);
    cout << "sum of range -> " << tree.find_range_sum(5, 9) << endl;
    return 0;
}

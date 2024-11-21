#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
    ofstream textfile("ans2.txt");
// variables
    int n, m;
    cin>>n>>m; 
    vector<pair<long long int, int>> t(n);
    vector<int> x(n), x_final(n);

// inputs
    for(int i=0;i<n;i++)
    {
        cin>>t[i].first;    // save tier into first
        t[i].second = i;    // save arrival time into second
    }


// algorithm
    sort(t.begin(), t.end());   // sort ascending

    for(int i=0;i<m;i++)        // give gifts to the first m person in ascending order
    {
        x[i] = 1;
    }

    for(int j=0;j<n-m;j++)      // assign zero for those with no gifts
    {
        x[m+j] = 0; 
    }

    for(int k=0;k<n;k++)
    {
        x_final[t[k].second] = x[k];    // rearranging back to orignal order based on arrival time
    }

// printing ans
    for(int i=0;i<n;i++)
    {
        textfile<<x_final[i];
        if(i==n-1)
        {

        }
        else textfile<<" ";
    }
    textfile.close();
    return 0;
}
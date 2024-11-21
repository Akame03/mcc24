#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    ofstream textfile("ans1.txt");
    int T;
    cin>>T;
    vector<long long int> n(T), m(T), A(T), B(T);

    for(int i=0;i<T;i++)
    {
        cin>>n[i]>>m[i]>>A[i]>>B[i];
    }

// algorithm

    for(int i=0;i<T;i++)
    {

        if((A[i]==n[i] && B[i]<=m[i]) || (A[i]<=n[i] && B[i]==m[i]) || (B[i]==n[i] && A[i]<=m[i]) || (B[i]<=n[i] && A[i]==m[i]))
        {
            textfile<<"YES\n";
        }
        else textfile<<"NO\n";
    }

    textfile.close();
    return 0;
}
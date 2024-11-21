#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
#define MOD 1000000007
void print(vector<long long int> a){
    for(int j=0;j<a.size();j++)
    {
        cout<<a[j]<<" ";
    }
    cout<<endl;
}

int main()
{
    ofstream textfile ("ans3.txt");

    long long int T;
    cin>>T;
    vector<long long int> power(T);
    vector<pair<long long int, vector<long long int>>> data(T);

    for(long int i=0;i<T;i++)
    {
        cin>>data[i].first;
        data[i].second.resize(data[i].first);
        for(int j=0;j<data[i].first;j++)
        {
            cin>>data[i].second[j];
        }

        sort(data[i].second.begin(), data[i].second.end()); // sort in ascending
    }
    cout<<"Done Data Receiving"<<endl;

#ifdef DEBUG
    cout<<endl<<"_____________Data_______________"<<endl;
    for(int i=0;i<T;i++)
    {
        cout<<data[i].first<<endl;
        for(int j=0;j<data[i].first;j++)
        {
            cout<<data[i].second[j];
            if(j==data[i].first-1) cout<<endl;
            else cout<<" ";
        }
    }
#endif

// algorithm

    for(long int i=0;i<T;i++)
    {
        long long int n = data[i].first;
        if(n!=1){
            for(long int j=0;j<(n-1);j++)
            {
                power[i] = (2*(data[i].second[n-1-j]) + data[i].second[n-2-j])%MOD;

                data[i].second.pop_back();
                data[i].second.pop_back();
                data[i].second.push_back(power[i]);
            }
        }
        else{   // too handle inputs where n = 1
            power[i] = data[i].second[0]%MOD;
        }
        if(i==T-1)
            textfile<<power[i];
            else
            textfile<<power[i]<<endl;
    }

    textfile.close();
    return 0;
}
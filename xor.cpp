#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;
#define MOD 998244353

vector<bool> transformation(vector<bool> &vec)
{
    int new_size = vec.size()*2-1;
    vector<bool> new_vec(new_size);
    new_vec[0] = vec[0]; new_vec[new_size-1] = vec[vec.size()-1];
    for(int i=0;i<new_size;i++)
    {
        if(i%2==0)
        {
            new_vec[i] = vec[i/2];
        }
        else
        {
            new_vec[i] = new_vec[i-1]^vec[(i+1)/2];
        }
    }
    return new_vec;
}

long long int beautify(vector<bool> &vec)
{
    long long int beauty = 0;
    int current_index, next_index;
    for(int i=0;i<vec.size()-1;i++)
    {
        current_index = i;
        next_index = i + 1;
        if(vec[current_index]==vec[next_index]) beauty+=1%MOD;
    }
    return beauty;
}

void print_vec(vector<bool> &vec)
{
    int c = 0;
    for(int i=0;i<vec.size();i++)
    {   
        c++;
        cout<<vec[i];
        if(c%4==0)
        {
            cout<<"_";
        }
    }
    cout<<"\n";
}

vector<bool> strToVec(string &str){
    vector<bool> vec(str.size());
    for(int i=0;i<str.size();i++)
    {
        vec[i] = (bool)((int)(str[i]-48));
    }
    return vec;
}

int main()
{
    int n;  // length of string
    int k;  // number of transformation
    long long int beauty = 0;
    string binary;

    cin>>n>>k;
    cin>>binary;

    auto start = high_resolution_clock::now();
    vector<bool> bin = strToVec(binary);
    vector<bool> ft;    // vector for transformation

    for(int i=2;i<=n;i++)
    {
        printf("Loop %d/%d\n", i-1, n-1);
        for(int j=0;j<n-i+1;j++)
        {
            int distance = i;
            auto start = bin.begin() + j;
            auto end = bin.begin() + distance + j;
            vector<bool> sub_bin(start, end);
            ft = sub_bin;
            for(int l=0;l<k;l++)        // transform k times
            {   
                ft = transformation(ft);
            }
            beauty += beautify(ft);
        }
    }

    cout<<beauty%MOD;
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(end-start);
    cout<<"\nElapsed Time : "<<duration.count()<<"\n";
    return 0;
}

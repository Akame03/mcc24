// Manual Modified-binary search
// Start with 10, 100, 1000........1e9 to find limits. 
// then do binary search

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

void print_vec(vector<int> &vec)
{
    int c = 0;
    cout<<"( ";
    for(int i=0;i<vec.size();i++)
    {   
        c++;
        cout<<vec[i]<<" ";
    }
    cout<<")\n";
}

string print_x(int x)
{
    stack<char> stringStack;
    string Xstr = "";
    while (x > 0) {
        char convertedDigit = x % 10 + '0';
        stringStack.push(convertedDigit);
        x /= 10;
    }

    while (!stringStack.empty()) {
        Xstr += stringStack.top();
        stringStack.pop();
        }

    return Xstr;
}

int main()
{
    int N, M, K;    // N targets to be destroyed, M multiplier, K number of arrows supplied
    long long int X = 71649269; //this is the actual answer for task 2 input
    cin>>N>>M>>K;
    vector<long long> a(N);   // hp of targets
    for(int i=0;i<N;i++)
    {
        cin>>a[i];
    }
    
    while(1){
        cout<<"Your Current Power is "<<print_x(X)<<". Would you like to change it? (=integer or -integer): ";
        long long extra_x;
        cin>>extra_x;
        X = extra_x;

        vector<long long> a_copy = a;
        long long int target_index = 0;

        for(int kk=0;kk<K;kk++) // loop through the arrows
            {
                // check for first occurence of positive number
                vector<long long>::iterator it = find_if(a_copy.begin(), a_copy.end(), [](int num){return num>0;});
                if (it == a_copy.end()) break;
                long long i = it-a_copy.begin();   // saves the index of the first positive number to i;
                for(long long int j=i;j<N;j++)
                {
                    long long int damage = max(0LL, M*X - (j-i)*(j-i));
                    a_copy[j] -= damage;
                }
            }
        bool all_dead = all_of(a_copy.begin(), a_copy.end(), [](long long num){return num<=0;});  //checks if all dead

        cout<<"all_dead = "<<all_dead<<endl;
    }

}
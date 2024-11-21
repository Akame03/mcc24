#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{

    int n;  // total number of pairs
    cin>>n;
    vector<pair<long long int, long long int>> coord(n);    // stores n number of pairs < a, b >
    vector<double> avrg(n);     // stores n number of pairs <average>
    vector<long long int> a, b;

    for(int i=0;i<n;i++)
    {
        cin>>coord[i].first>>coord[i].second;
    }

#ifdef DEBUG
    cout<<"\n______COORD STORED_____\n";
    for(int i=0;i<coord.size();i++)
    {
        cout<<coord[i].first<<" "<<coord[i].second<<endl;
    }
#endif
// compute the average
    cout<<"\n___The Averages___\n";
    for(int i=0;i<n;i++)
    {
        avrg[i] = (double)(coord[i].first + coord[i].second)/2;
        cout<<avrg[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n/2;i++)
    {
        // find highest average - save its index - get the value of a - erase the highest average
        // E takes first
        vector<double>::iterator it_a = max_element(avrg.begin(), avrg.end());
        cout<<"Highest Average for A: "<<*max_element(avrg.begin(), avrg.end())<<endl;
        int index_a = it_a - avrg.begin(); 
        a.push_back(coord[index_a].first); 
        avrg[index_a] = -100000000000000;

        // repeat above process but for b now
        // R takes next
        vector<double>::iterator it_b = max_element(avrg.begin(), avrg.end());
        cout<<"Highest Average for B: "<<*max_element(avrg.begin(), avrg.end())<<endl;
        int index_b = it_b - avrg.begin(); 
        b.push_back(coord[index_b].second); 
        avrg[index_b] = -1000000000000000;
    }


#ifdef DEBUG
    cout<<"\n_____a[]______\n";
    for(int i=0;i<n/2;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n_____b[]______\n";
    for(int i=0;i<n/2;i++)
    {
        cout<<b[i]<<" ";
    }
#endif

#ifdef DEBUG
    cout<<"\n______avrg STORED______\n";
    for(int i=0;i<avrg.size();i++)
    {
        printf("< %d, %d >\n", avrg[i].first, avrg[i].second);
    }
#endif


// get the sum of a, b
    long long int sum_a = 0, sum_b = 0;
    for(int i=0;i<a.size();i++)
    {
        sum_a+=a[i];
        sum_b+=b[i];
    }

    long long int X_Y = sum_a - sum_b;


    cout<<"\n"<<X_Y;
    return 0;
}
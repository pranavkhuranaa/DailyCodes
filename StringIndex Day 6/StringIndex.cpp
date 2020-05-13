#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void OddEven(string s){
    string odd="",even="";

    for(int i=0;i<s.length();i++)
    {
        if(i%2==0)
            even+=s[i];
        else
            odd+=s[i];
    }

    cout<<even<<" "<<odd<<endl;
} 

int main() {

    int n,i;
    cin>>n;
    string s[10];

    for(i=0;i<n;i++)
    {
        cin>>s[i];
        OddEven(s[i]);
    }

/*
    for(i=0;i<n;i++)
    {
        OddEven(s[i]);
    }
*/
    return 0;
}

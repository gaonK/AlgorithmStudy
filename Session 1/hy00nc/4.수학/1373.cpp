#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string s="";
    cin>>s;
    int n=s.size();
    if(n%3==1){
        cout<<s[0];
    }
    if(n%3==2){
        cout<<(s[0]-'0')*2+(s[1]-'0');
    }
    
        for(int i=n%3;i<n;i+=3){
            cout<<(s[i]-'0')*4+(s[i+1]-'0')*2+(s[i+2]-'0');
        }
    
    cout<<'\n';
}
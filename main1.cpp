#include <iostream>

using namespace std;

bool Search(int a[],int n,int x){
    int left=0,right=n-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(a[mid]==x) return true;
        else if(a[mid]<x){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    return false;
}

int main()
{
    int a[]={2,3,4,5,6,7};
    if(Search(a,7,3)==true) cout << "succcess!";
    else cout<< "fail!!";
    return 0;
}

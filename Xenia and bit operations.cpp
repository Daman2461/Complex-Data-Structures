#include<iostream>
#include<vector>
#include<numeric>
#include<math.h>
#include <map>
#define ll long long
using namespace std;


class SegT{
public:
    
    void build (int ind, int low, int high, vector<int>&seg , vector<int>&arr, bool parity){
        if(low == high){
            seg[ind] = arr[low];
            
            
            return;
        }
        
        int mid = low + (high-low)/2;
        build(2*ind + 1, low, mid,seg,arr, !parity );
        build(2*ind + 2, mid+1, high,seg,arr, !parity );
        if(parity )
            seg[ind] = (seg[2*ind+1] | seg[2*ind+2]);
        else
            seg[ind] = (seg[2*ind+1] ^ seg[2*ind+2]);
    }
    
    void update (int ind, int low,int high, int i, int val,vector<int>&seg,bool parity){
        if(low == high){
            seg[ind] = val;
            
            return;
        }
        
        int mid = low + (high-low)/2;
        
        if(i<=mid)update(2*ind+1, low, mid, i, val,seg,!parity);
        else update(2*ind+2, mid+1, high, i, val,seg,!parity);
        
        if(parity )
            seg[ind] = (seg[2*ind+1] | seg[2*ind+2]);
        else
            seg[ind] = (seg[2*ind+1] ^ seg[2*ind+2]);
        
    }
    
    
};
void  solve(){
    int n1,q;
    cin>>n1>>q;
    
    int n=n1;
    n1 = pow(2,n1);
    vector<int> arr1(n1);
    
    
    for(int i =0;i<n1;i++){
        cin>>arr1[i];
    }
    
    vector<int> seg1(4*n1,INT_MAX) ;
    
    SegT obj1 ;
    if(n%2==0)
        obj1.build(0,0,n1-1,seg1,arr1,0);
    else
        obj1.build(0,0,n1-1,seg1,arr1,1);
    
    
    
    while(q--){
        
        int i,val;
        cin>>i>>val;
        i--;
        arr1[i]=val;
        
        if(n%2==0)
            obj1.update(0, 0, n1-1, i, val, seg1,0);
        else if(n%2==1)
            obj1.update(0, 0, n1-1, i, val, seg1,1);
        
        cout<<seg1[0]<<endl;
        
    }
}

int main(){
    
    solve();
}



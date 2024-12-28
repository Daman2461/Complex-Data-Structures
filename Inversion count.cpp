#include<iostream>
#include<vector>
#include<numeric>
#include<math.h>
#include <map>
#define ll long long
using namespace std;
 

class SegT{
public:
    
    void build (int ind, int low, int high, vector<int>&seg , vector<int>&arr){
        if(low == high){
            seg[ind] = arr[low];
            return;
        }
        
        int mid = low + (high-low)/2;
        build(2*ind + 1, low, mid,seg,arr);
        build(2*ind + 2, mid+1, high,seg,arr);
        
        seg[ind] =  (seg[2*ind+1] + seg[2*ind+2]);
        
    }
    
    int query(int ind, int low, int high, vector<int>&seg,int l,int r){
        if(r<low || l>high)return 0;            // no overlap
        
        else if(l<= low && r>=high)return seg[ind];  // full overlap    [l low high r]
        
        else{                                       // partial overlap
            int mid = low + (high-low)/2;
            int left  = query(2*ind+1 , low, mid, seg, l,r);
            int right  = query(2*ind+2 ,  mid+1,high, seg, l,r);
            return    (left + right);
            
        
            }
        
        
    }
    
    void update (int ind, int low,int high, int i, int val,vector<int>&seg){
            if(low == high){
                seg[ind] += val;
                return;
            }
            
            int mid = low + (high-low)/2;
            
            if(i<=mid)update(2*ind+1, low, mid, i, val,seg);
            else update(2*ind+2, mid+1, high, i, val,seg);
            
            seg[ind] =  (seg[2*ind+1] + seg[2*ind+2]);
            
        }
     
    
};
void  solve(){
    
    int q;
    cin>>q;
    
    
    while(q--){
        int n1;
        cin>>n1;
        vector<int> arr1(n1);
        
        int mx=-1;
        for(int i =0;i<n1;i++){
            cin>>arr1[i];
            mx=max(mx, arr1[i]);
        }
        vector<int>freq(mx+1,0);
        
        for(int i =0;i<n1;i++){
            
            freq[arr1[i]]++;
        }
        
        int n = mx+1;
        vector<int> seg1(4*n ,INT_MAX) ;
        
        
        SegT obj1 ;
        
        obj1.build(0,0,n-1,seg1,freq);
        int c=0;
        for(int i=0;i<n1;i++){
           freq[arr1[i]]--;
            obj1.update(0, 0, n-1, arr1[i], -1, seg1);
            
            c+=obj1.query(0, 0, n-1, seg1, 0, arr1[i]-1);
            
        }
        
        cout<<c<<endl;
    }
}

int main(){
    
    solve();
}


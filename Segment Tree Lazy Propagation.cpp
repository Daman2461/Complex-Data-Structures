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
            seg[ind] =arr[low];
            return;
        }
        
        int mid = low + (high-low)/2;
        build(2*ind + 1, low, mid,seg,arr);
        build(2*ind + 2, mid+1, high,seg,arr);
        
        seg[ind] =  (seg[2*ind+1]+ seg[2*ind+2]);
        
    }
    
    
    void update (int ind, int low,int high, int l, int r,int val, vector<int>&seg,vector<int>&lazy){
        
        if(lazy[ind]!=0){
            seg[ind] += lazy[ind] * (high-low+1);
            
            if(low!=high){
                lazy[ind*2+ 1] +=lazy[ind];
                lazy[ind*2+ 2] +=lazy[ind];
            }
            lazy[ind]=0;
        }
        
        
        if(r<low || l>high)return ;            // no overlap
        
        else if(l<= low && r>=high){
            seg[ind] += val * (high-low+1);
            if(low!=high){
                lazy[2*ind+1] +=val;        // full overlap    [l low high r]
                lazy[2*ind+2] +=val;
            }
        }
        
        else{                                       // partial overlap
            int mid = low + (high-low)/2;
            update(2*ind+1 , low, mid, l,r,val, seg, lazy);
            update(2*ind+2 , mid+1,high, l,r,val, seg, lazy);
            seg[ind] =  (seg[2*ind+1]+ seg[2*ind+2]);
        }
        
    }
    
    
};
void  solve(){
    int n1;
    cin>>n1;
    vector<int> arr1(n1);
    
    
    for(int i =0;i<n1;i++){
        cin>>arr1[i];
    }
    
    vector<int> seg(4*n1,0),lazy(4*n1,0);
    
    
    
    
    SegT obj1 ;
    
    obj1.build(0,0,n1-1,seg,arr1);
    
    for(int i=0;i<4*n1;i++){
        cout<<seg[i]<<" ";
    }
    cout<<endl;

    
    int q;
    cin>>q;
    
    while(q--){
        
        int l1,r1,val;
        
        cin>>l1>>r1>>val;
        l1 --;
        r1--;
        
        
        obj1.update(0, 0, n1-1, l1, r1, val, seg, lazy);
        
        
        for(int i=0;i<4*n1;i++){
            cout<<seg[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<4*n1;i++){
            cout<<lazy[i]<<" ";
        }
        
        
        
        
        
    }
}

int main(){
    
    solve();
}


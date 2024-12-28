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
        
        seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);
        
    }
    int query(int ind, int low, int high, vector<int>&seg,int l,int r){
        if(r<low || l>high)return INT_MAX;            // no overlap
        
        else if(l<= low && r>=high)return seg[ind];  // full overlap    [l low high r]
        
        else{                                       // partial overlap
            int mid = low + (high-low)/2;
            int left  = query(2*ind+1 , low, mid, seg, l,r);
            int right  = query(2*ind+2 ,  mid+1,high, seg, l,r);
            return   min(left, right);
            
        
            }
        
        
    }
    
    void update (int ind, int low,int high, int i, int val,vector<int>&seg){
        if(low == high){
            seg[ind] = val;
            return;
        }
        
        int mid = low + (high-low)/2;
        
        if(i<=mid)update(2*ind+1, low, mid, i, val,seg);
        else update(2*ind+2, mid+1, high, i, val,seg);
        
        seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);
        
    }
    
    
};
void  solve(){
    int n1;
    cin>>n1;
    vector<int> arr1(n1);
       

    for(int i =0;i<n1;i++){
        cin>>arr1[i];
    }
    int n2;
    cin>>n2;
    
    vector<int>arr2(n2);
    for(int i =0;i<n2;i++){
           cin>>arr2[i];
       }
    vector<int> seg1(4*n1,INT_MAX),seg2(4*n2,INT_MAX);
   
    
    
   
    SegT obj1,obj2;
    
    obj1.build(0,0,n1-1,seg1,arr1);
    
    
    obj2.build(0,0,n2-1,seg2,arr2);
    
    int q;
    cin>>q;
     
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            
            int l1,r1;
            
            cin>>l1>>r1;
            
            int l2,r2;
            
            cin>>l2>>r2;
            
            int m1 = obj1.query(0, 0, n1-1, seg1, l1, r1);
            int m2 = obj2.query(0, 0, n2-1, seg2, l2, r2);
            int m=  min(m1,m2);
            cout<< m <<endl;
        }
        else {
            int arno,i,val;
            
            cin>>arno>>i>>val;
            if(arno==1){
                arr1[i]=val;
                obj1.update(0, 0, n1-1, i, val, seg1);
                for(int iw =0;iw<n1;iw++){
                    cout<<arr1[iw];
                }
            }
            else{
                arr2[i]=val;
                obj2.update(0, 0, n2-1, i, val, seg2);
                
                for(int iw =0;iw<n2;iw++){
                    cout<<arr2[iw];
                }
                
            }
                
                
        }
    }
    
     
}

int main(){
    
    solve();
}



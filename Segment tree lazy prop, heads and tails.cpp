#include<iostream>
#include<vector>
#include<numeric>
#include<math.h>
#include <map>
#define ll long long
using namespace std;

// 7 1 1 0 0 1 0 1
// 4 2 2 2 0 1 1 1 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
// 3 2 2 6 1 3 5 2 2 6 
// Query Result: 2
// 4 2 2 2 0 1 1 1 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
// 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
// 5 4 1 2 2 0 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
// 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
// Query Result: 3
// 5 4 1 2 2 0 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
// 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
// Program ended with exit code: 0

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
    int query(int ind, int low,int high, int l, int r, vector<int>&seg,vector<int>&lazy){
        
        if(lazy[ind]!=0){
            seg[ind]  = (high-low+1) - seg[ind];
            
            
            if(low!=high){
                lazy[ind*2+ 1] += !lazy[ind*2+ 1];
                lazy[ind*2+ 2] += !lazy[ind*2+ 2];
            }
            lazy[ind]=0;
        }
        
        if(r<low || l>high)return 0;
        
        else if(l<= low && r>=high){
            return seg[ind];
        }
        else{
            int mid = low + (high-low)/2;
            int left =query(2*ind+1 , low, mid, l,r, seg, lazy);
            int right = query(2*ind+2 , mid+1,high, l,r, seg, lazy);
            return  left+right;
        }
        
    }
    
    
    void update (int ind, int low,int high, int l, int r, vector<int>&seg,vector<int>&lazy){
        
        if(lazy[ind]!=0){
            seg[ind]  = (high-low+1) - seg[ind];
            
            
            if(low!=high){
                lazy[ind*2+ 1] += !lazy[ind*2+ 1];
                lazy[ind*2+ 2] += !lazy[ind*2+ 2];
            }
            lazy[ind]=0;
        }
        
        
        if(r<low || l>high)return ;             // no overlap
        
        else if(l<= low && r>=high){
            seg[ind]  = (high-low+1) - seg[ind];
            if(low!=high){
                lazy[ind*2+ 1] += !lazy[ind*2+ 1];
                lazy[ind*2+ 2] += !lazy[ind*2+ 2];
            }
        }
        
        else{                           // partial overlap
            int mid = low + (high-low)/2;
            update(2*ind+1 , low, mid, l,r, seg, lazy);
            update(2*ind+2 , mid+1,high, l,r, seg, lazy);
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
        int type;
        
        
        cin>>type;
        
        if(type==1){
            int l1,r1;
            
            cin>>l1>>r1;
            l1 --;
            r1--;
            
            
            obj1.update(0, 0, n1-1, l1, r1, seg, lazy);
            
            
            for(int i=0;i<4*n1;i++){
                cout<<seg[i]<<" ";
            }
            cout<<endl;
            for(int i=0;i<4*n1;i++){
                cout<<lazy[i]<<" ";
            }
            cout<<endl;
        }
        
        else if(type==2) {
            int l1,r1;
            
            cin>>l1>>r1;
            l1 --;
            r1--;
            
            
            
            
            int result = obj1.query(0, 0, n1 - 1, l1, r1, seg, lazy);
            cout << "Query Result: " << result << endl;
            for(int i=0;i<4*n1;i++){
                cout<<seg[i]<<" ";
            }
            cout<<endl;
            for(int i=0;i<4*n1;i++){
                cout<<lazy[i]<<" ";
            }
            cout<<endl;
        }
        
        
        
        
        
    }
}

int main(){
    
    solve();
}


#include<bits/stdc++.h>
using namespace std::chrono;
using namespace std;

 void play(int arr[][5],int n,int m)
    {     
        for(int gen=0;gen<2;gen++){
          int *out[n];
          for(int i = 0; i < n; i++){
             out[i] = new int[m]; 
          }
          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                out[i][j]=0;
            }
          }
          for(int i=0;i<n;i++){       
            for(int j=0;j<m;j++){
                int count=0; 
                // finding neighbours
                for(int k=i-1;k<i+2 ;k++){
                    for(int l=j-1;l<j+2;l++){
                        if((k==i && l==j)||(k<0 || k>=n)||(l<0 || l>=m )){
                             continue;
                        }
                         if(arr[k][l]==1  ){
                            count=count+1;                       
                        }
    
                    }
                    }
                // making dead cell alive
                if(count==3&&arr[i][j]==0){
                    out[i][j]=1;
                }
                // live cell die due to over population 
                else if(count>3){                
                    out[i][j]=0;
                }
                // will live in next generation
                else if(count<=3 && count>=2 && arr[i][j]==1){
                    out[i][j]=1;
                }
                else{
                    out[i][j]=0;
                }
            }
        }
            
          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               cout<<out[i][j]<<" ";
            }
            cout<<endl;
          }
          cout<<endl;
          
          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[i][j]=out[i][j];
            }
          }
          for (int i = 0; i < n; i++) {
                   delete []out[i];
          }
          delete []out; 
        }
     
      return;
    }
int main(){

    int arr[4][5]={{1,0,1,0,1},
                   {0,1,1,0,1},
                   {1,0,0,1,0},
                   {0,0,1,0,1}};
           for(int i=0;i<4;i++){
            for(int j=0;j<5;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;          
          }
            cout<<endl; 
            auto start = high_resolution_clock::now();
            play(arr,4,5);    
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            cout <<"Total Time consumed is "<< duration.count() << endl;
return 0;
}
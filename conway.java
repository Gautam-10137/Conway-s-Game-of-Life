class conway
{
    public static void play(int [][]arr,int n,int m)
    {     
        
        for(int gen=0;gen<2;gen++){
          int out[][]=new int[n][m];
          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                out[i][j]=0;
            }
          }
          for(int i=0;i<n;i++){       
            for(int j=0;j<m;j++){
                // counting alive neighbours
                int count=0; 
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
                System.out.print(out[i][j] +" ");
            }
            System.out.println();
          }
          System.out.println();
          
          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[i][j]=out[i][j];
            }
          }
         
        }
        return;
    }
    public static void main(String args[])
    {
           int arr[][]={{1,0,1,0,1},
                         {0,1,1,0,1},
                         {1,0,0,1,0},
                         {0,0,1,0,1}};
           for(int i=0;i<4;i++){
            for(int j=0;j<5;j++){
                System.out.print(arr[i][j] +" ");
            }
            System.out.println();          
          }
            System.out.println(); 
            long start=System.currentTimeMillis();
            play(arr,4,5);
            long finish=System.currentTimeMillis();
            long totalsecs=(finish-start);
            System.out.println("total time consumed: "+totalsecs);
    
    }

}




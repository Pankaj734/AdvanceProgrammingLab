#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class dist{
    int i,j,d;
    public :
    
    void dstnc(int x){
        d = x;
    }
    void set(int i, int j){
        this->i = i;
        this->j = j;
    }
    int getI(){
        return i;
    }
    int getJ(){
        return j;
    }
    int getD(){
        return d;
    }
};

void swap(dist* a, dist* b) 
{ 
    dist t = *a; 
    *a = *b; 
    *b = t; 
} 
  

int part(dist arr[], int l, int h) 
{ 
    int p = arr[h].getD();    
    int i = (l - 1);  
    int j;
    for (j = l; j <= h- 1; j++) 
    {  
        if (arr[j].getD() <= p) 
        { 
            i++;    
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[h]); 
    return (i + 1); 
} 
  
void quickSort(dist arr[], int l, int h) 
{ 
    if (l < h) 
    { 
        int i = part(arr, l, h); 
   
        quickSort(arr, l, i - 1); 
        quickSort(arr, i + 1, h); 
    } 
} 

bool midpoint(int x1, int y1, int x2, int y2,int x3, int y3, int x4, int y4){
    double mX1 = (x1+x2)/2;
    double mY1 = (y1+y2)/2;
    double mX2 = (x3+x4)/2;
    double mY2 = (y3+y4)/2;
    
    if(mX1 == mX2 && mY1 == mY2) return true;
    
    return false;
    
}


int main() {
    
    int n;
    cin >> n;
    int points[n][3];
    int i;
    for(i=0; i<n; i++){
        cin>>points[i][0]>>points[i][1];
    }
    
    
    int j,k=0;
    int distance;
    dist arr[(n-1)*n/2];
    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            distance = (points[i][0]-points[j][0])*(points[i][0]-points[j][0])+(points[i][1]-points[j][1])*(points[i][1] - points[j][1]);
            
            arr[k].set(i, j);
            arr[k].dstnc(distance);
            k++;
        }
    }
    
    
    quickSort(arr, 0, k-1);
    
    int area, max=-1;
    int a,b,c,d,e,f,g,h;
    
    for(i=0; i<k-1; i++){
        for(j=i+1; j<k; j++){
            if(arr[i].getD() == arr[j].getD()){
                a = points[arr[i].getI()][0];
                b = points[arr[i].getI()][1];
                c = points[arr[i].getJ()][0];
                d = points[arr[i].getJ()][1];
                e = points[arr[j].getI()][0];
                f = points[arr[j].getI()][1];
                g = points[arr[j].getJ()][0];
                h = points[arr[j].getJ()][1];
                
                if(midpoint(a,b,c,d,e,f,g,h))
                   {
                    
                       area = (arr[i].getD())/2;
                       if(area>max) max=area;
                   }
            }
            else{
                i=j-1;
                break;
            }
            
        }
    }
    
    
    
    if(max<0) cout<<"NO"<<endl;
    else cout<<max<<endl;
    
    return 0;
}
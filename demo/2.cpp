/*Напишите эффективную функцию f_mvsa (int* a,int N) вычисляющую
сколько элементов массива меньше медианы, но больше среднего
арифметического элементов этого массива.*/


#include <iostream>
#include <algorithm>

using namespace std;

void qusort(int* mas, int m, int n) {
    
    int l = m, r = n; 
    int piv = mas[(l+r)/2]; 
    
    while (l <= r){ 
    
        while (mas[l] < piv) 
        l++; 
    
        while (mas[r] > piv) 
        r--; 
    
        if (l <= r ) 
        swap(mas[l++], mas[r--]); 
    } 
    
    if (m < r) qusort(mas, m, r); 
    
    if (n > l) qusort(mas, l, n); 
}


int f_mvsa(int* a, int x){
    
    int kolvo=0;
    double av=0;
    for(int i=0; i<x; i++){
        av+=a[i];
    }
    av/=x;
    
    qusort(a,0, x-1);
    
    if(x%2==1){
        for(int i=x/2-1; i>0; i--){
            if(a[i]>av){
                kolvo++;
            }
        }
    }
    else{
        for(int i=x/2-1; i>0; i--){//4->2, 7->3
            if(a[i]>av){ 
                kolvo++;
            }
        }
    } 
    return kolvo;
}



int main()
{
    int n;
    cout<<"vvedite razmer massiva: ";
    cin>>n;
    int* arr= new int[n];
    for(int i=0; i<n; i++){
        cout<<"enter arr["<<i<<"]: ";
        cin>>arr[i];
    }
    cout<<endl<<"arr: ";
    for(int j=0; j<n; j++){
        cout<<arr[j]<<" ";
    }
    
    cout<<endl<<"kolvo="<<f_mvsa(arr,n);
    
    cout<<endl<<"arr: ";
    for(int j=0; j<n; j++){
        cout<<arr[j]<<" ";
    }
    return 0;
}

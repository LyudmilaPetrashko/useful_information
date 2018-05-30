#include<iostream>
#include<iterator>
#include<vector>
#include<array>

using namespace std;

/*Дан двумерный массив a состоящий из N массивов различной длины.
Каждый из одномерных массивов хранит информацию о своей
длине(количестве элементов) - в нулевом элементе. Напишите функцию
f_avg(int ** a, int N) находящую среднее арифметическое максимальных
простых элементов в одномерных массивах. Функция не должна
использовать обращения к элементам массивов по индексам*/


void print(int** n, int m){
    for(int a=0; a<m; a++){
        for(int b=0; b<n[a][0]; b++){
            cout<<n[a][b]<<" ";
        }
        cout<<endl;
    }
}

bool prime(int p){
    if(p<=1){return false;}
    else{
        for(int i=2;i*i<=p;i++){
		    if(p%i==0){return false;}
        }
        return true;
    }
}

double f_avg( int** arr, int k){
    double avg=0;
    int max=0, kolvo=0;
    for(int** p=arr; p!=arr+k; p++){
        for(int*q=*p+1; q!=*(*p)+*p; q++){
            if((prime(*q)==1) && (*q>max)){
                max=*q;
            }
        }
        if(max!=0) kolvo++;
        avg+=max;
        max=0;
    }
    if(kolvo==0){
        avg=0;
        kolvo=1;
    }
    avg/=kolvo;
    
    return avg;
}


int main(){
    int N, l;
    cout<<"enter the number of arrays in array: ";
    cin>>N;
    int** a= new int* [N];
    for(int i=0; i<N; i++){
        cout<<endl<<"enter size arr["<<i<<"]: ";
        cin>>l;
        a[i]= new int [l];
        a[i][0]=l;
        for(int j=1; j<l; j++){
            cout<<"enter arr["<<i<<"]["<<j<<"]: ";
            cin>>a[i][j];
        }
    }
    cout<<endl<<"print a:"<<endl;
    print(a,N);
    
    cout<<endl<<"avg="<<f_avg(a, N);
    
    return 0;
}

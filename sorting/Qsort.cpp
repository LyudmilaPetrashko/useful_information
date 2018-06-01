void Qsort(int* A, int m, int n) { //time->n*log(n)
    
    /*суть в том, что выбирают опорный элемент pivot и все элементы,
    большие его(значения), перекидывают вправо, а меньшие - влево*/                                    
    
    int l = m, r = n; //левая и правая границы
    int piv = A[(l+r)/2]; //опорный элемент
    
    while (l <= r){ 
    
        while (A[l] < piv) 
        l++; 
    
        while (A[r] > piv) 
        r--; 
    
        if (l <= r ) 
        swap(A[l++], A[r--]); 
    } 
    
    if (m < r) Qsort(A, m, r); 
    
    if (n > l) Qsort(A, l, n); 
}

// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

void count_sort(int a[], int n) {
    int count[3] = {0,0,0};
        
    for (int i = 0; i < n; i++) {
        count[a[i]]++;
    }
    
    int j;
    count[1] += count[0];
    count[2] += count[1];
    
    for (int i = 0; i < count[0]; i++) {
        a[i] = 0;
    }
    
    for (int i = count[0]; i < count[1]; i++) {
        a[i] = 1;
    }
    
    for (int i = count[1]; i < count[2]; i++) {
        a[i] = 2;
    }
}

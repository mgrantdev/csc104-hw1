1. This function takes O(n) because as n gets very large, the function will run at most n times (actually multiple factors less, but we'll simplify to n).

```
void f1(int n)
{
    int i=2;
    while(i < n){
        /* do something that takes O(1) time */
        i = i*i;
    }
}
```

2. This function takes O(n^2) because as n gets very large, the function will run at most i^3 * n times, which we can simplify to n^2.

```
void f2(int n)
{
    for(int i=1; i <= n; i++){
        if( (i % (int)sqrt(n)) == 0){
            for(int k=0; k < pow(i,3); k++) {
              /* do something that takes O(1) time */
            }
        }
    }
}
```

3. The worst case run time is n*n*n which is n^3, so the run time is O(n^3)

```
for(int i=1; i <= n; i++){
  for(int k=1; k <= n; k++){
    if( A[k] == i){
      for(int m=1; m <= n; m=m+m){
        // do something that takes O(1) time
        // Assume the contents of the A[] array are not changed
      }
    }
  }
}
```
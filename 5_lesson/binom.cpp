#include <iostream>

int binom(int,int);

int main(){
    
    int n = 5, k = 3, ans = 0;
    ans = binom(n,k);
    std::cout << "n choose k equals: " << ans << std::endl;
    
}

int binom(int n, int k){
    
    if( n < k)
        return 0;
    if( (n == k) || (k == 0) )
        return 1;
    
    return binom(n-1,k) + binom(n-1,k-1);
    
}
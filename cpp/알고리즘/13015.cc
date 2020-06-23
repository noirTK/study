#include <iostream> 
void main(){
    int n; 
    std::cin >> n; 
    for(int i = 0; i < 2*n-1; ++i){ 
        for(int j = 0; j < (4*n-3-i > 2*n-1+i ? 4*n-3-i : 2*n-1+i); ++j) 
        { 
            if(((i < n and j < 4*n-3-i) or (i >= n and j < 2*n-1+i)) and (((j == i and i < n) or (j == i+2*n-2 and i >= n) or (j == i+n-1) or (i+j == 3*n-3) or (i+j == 4*n-4 and i < n) or (i+j == 2*n-2 and i >= n) or ((i == 0 or i == 2*n-2) and (j < n or (j >= 3*n-3 and j < 4*n-3)))))) std::cout << '*'; 
            else std::cout << ' ';} std::cout << '\n';
        }
}
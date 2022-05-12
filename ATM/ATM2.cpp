#include <iostream> 

int atmFunc(short card, short pin, long reqMoney,  long* pMoney, long* pBalance);


int main() {   
    int result;
    long money; 
    long balance;

    result = atmFunc(0x1234, 0x9999, 10000, &money, &balance); 
    printf("%dyen, %dyen, %dyen", result, money, balance); 

    return 0; 
} 


int atmFunc(short card, short pin, long reqMoney,  long* pMoney, long* pBalance) {
    *pMoney = 10000;
    *pBalance = 40000;
    
    return 0;
}


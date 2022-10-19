#include <iostream>

using namespace std;

long int midSquare(long int seed);
long int moduloDivision(long int seed, long int mod);
long int digitExtraction(long int seed, int* extractDigits, int size);

long int midSquare(long int seed)
{
    return ((seed*seed)/100)%10000;
}
long int moduloDivision(long int seed, long int mod)
{
    return seed%mod;
}
long int digitExtraction(long int seed,int* extractDigits,int size)
{

}

int main(){
    
}


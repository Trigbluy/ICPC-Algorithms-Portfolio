#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define pb push_back

const int MAX_PRIMES=100000000;
 
bitset<MAX_PRIMES+1> nums;        // true for each prime
vector<int> primes;               // list of primes
 
void sieve(int n) {
  nums.set();                     // set all values to true
  nums[0] = nums[1] = false;
  for(int i=2; i<=sqrt(n)+1; i++) // filter out non-primes
    if(nums[i])
      for(int j=i*i; j<n+2; j+=i)	
	nums[j] = false;
 
  for(int i=0; i<nums.size(); i++)
    if(nums[i] == true)	
      primes.push_back(i);
}  
 
int main() {
  sieve(MAX_PRIMES);
 
  return 0;
}
//SOLUTION 1 ------------TLE O(n^2)
class Solution {
public:
    int countPrimes(int n) {
        int count=0;
        bool isPrime=true;
        if(n<=2) return 0; //0 1 2 have 0 primes strictly <n
        for(int i=2;i<n;i++)
        {
            for(int j=2;j<=i/2;j++) //since no number after n/2 divides n without leaving a remainder
            {
                if(i%j ==0 ) isPrime=false;
            }
            if(isPrime==true) count++;
            else isPrime=true;
        }
        return count;
    }
};
//for n=2 and n=3, the control will not even enter the innder for loop since n/2=1 and j is initially true, but by default isPrime is true!





//Sieve Eratosthenes Algorithm     T.C. = O(n*log(log n))
class Solution {
public:
    int countPrimes(int n) {
        vector<bool>prime(n+1,true); //vector of size n+1 (to avoid index -1) and all primes initially

        int count=0;

        prime[0] = prime[1] = false; //0 & 1 are not prime

        for(int i=2;i<n;i++)
        {
            if(prime[i]) count++;

            for(int j=2*i;j<n;j=j+i) //j starting from 2*i and incremented by i ; basically multiples of i
            {
                prime[j] = false; //all multiples of i are not prime
            }
        }

        return count;
    }
};
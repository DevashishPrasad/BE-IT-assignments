#include<iostream>
#include<math.h>

using namespace std;

// find gcd
int gcd(int a, int b) {
   int t;
   while(1) {
      t= a%b;
      if(t==0)
      return b;
      a = b;
      b= t;
   }
}

int main() {

   // ====================================
   // STEP 1 : Two random prime numbers
   // ====================================
   // Choose two prime numbers
   double p = 13;
   double q = 11;
   //calculate n
   double n=p*q;
   double track;
   //calculate phi = euler's totient function
   double phi= (p-1)*(q-1);

   // ====================================   
   // STEP 2 : Derieved number
   // ====================================   
   double e=7;
   //for checking that 1 < e < phi(n) and gcd(e, phi(n)) = 1; i.e., e and phi(n) are coprime.
   while(e<phi) {
      track = gcd(e,phi);
      if(track==1)
         break;
      else
         e++;
   }
   
   // ====================================   
   // STEP 3 : Public Key
   // ====================================   
   // n and e form the public key 

   // ====================================   
   // STEP 4 : Private Key
   // ====================================      
   //choosing d such that it satisfies d*e = 1 mod phi
   double d1=1/e;
   double d=fmod(d1,phi);
   //double d = modf((e-1), phi);
   //double d = (e-1) % phi;
   
   // ====================================   
   // STEP 5 : Perform Encryption
   // ====================================    
   double message = 9;
   double c = pow(message,e); 
   
   // ====================================   
   // STEP 6 : Perform Dencryption
   // ====================================      
   double m = pow(c,d);
   c=fmod(c,n);
   m=fmod(m,n);
   cout<<"PLAIN TEXT = "<<message;
   cout<<"\n"<<"p = "<<p;
   cout<<"\n"<<"q = "<<q;
   cout<<"\n"<<"n = pq = "<<n;
   cout<<"\n"<<"phi = "<<phi;
   cout<<"\n"<<"e = "<<e;
   cout<<"\n"<<"d = "<<d;
   cout<<"\n"<<"ENCRYPTED = "<<c;
   cout<<"\n"<<"DECRYPTED = "<<m;
   return 0;
}

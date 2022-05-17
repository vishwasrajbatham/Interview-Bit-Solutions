//https://www.interviewbit.com/problems/divide-integers/
/*Divide two integers without using multiplication, division and mod operator.

Return the floor of the result of the division.

Example:

5 / 2 = 2
Also, consider if there can be overflow cases. For overflow case, return INT_MAX.

Note: INT_MAX = 2^31 - 1*/
#include<bits/stdc++.h>
using namespace std;
/*
int divide(int A, int B) {
    int n1 = A < 0, n2 = B < 0;
    long long int a = A, b = B;
    a = abs(a);
    b = abs(b);
    double da = log(a);
    double db = log(b);
    long long int ans = exp(da - db);
    if (n1 ^ n2)
        ans = -ans;
    if (ans > INT_MAX || ans < INT_MIN)
        return INT_MAX ;
    return ans;
}
*/
int divide(int a, int b) {
    
   long long n = a, m = b;
   int sign = n < 0 ^ m < 0 ? -1 :1;
   long long q = 0;
   n = abs(n);
   m = abs(m);
   for (long long t = 0, i = 31; i >= 0; i--)
        if (t + (m << i) <= n)
            t += m << i, q |= 1LL << i;

    // assign back the sign
    if (sign < 0) q = -q;

    // check for overflow and return
    return q >= INT_MAX || q < INT_MIN ? INT_MAX : q;
}
/*
30012,250232,53201,3004355,124111
strin=[str(data) for data in input().split(",")]
out=""
temp=""
s=set([])
for i in range(len(strin)):
    j=i+2
    while(j<len(strin)):
        for m in range(0,len(strin[i])):
            s.add(strin[i][m])
        for m in range(0,len(strin[j])):
            s.add(strin[j][m])
        if(len(s)==6):
            out=out+strin[i]
            out=out+strin[j]
            if(temp==""):
                temp=out
            if(temp!=""):
                break

        if(temp!=""):
            break    
        s.clear()
        j=j+1
if(temp==""):
    print(-1)
else:
    print(temp)


QW,RN,KOI,POL,ERT,XCV,ERB,LJH,AS
3
3
31,23,21,11,33,13,12,22,32
CARZ


*/
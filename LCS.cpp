#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

int n,m,a[MAX][MAX];
char s1[MAX],s2[MAX];

void lcs(){
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
            if(i==0 || j==0)            a[i][j]=0;
            else if(s1[i-1]==s2[j-1])   a[i][j]=a[i-1][j-1]+1;
            else                        a[i][j]=max(a[i-1][j],a[i][j-1]);
        }
    }
    
    printf("Length of LCS is %d\n",a[n-1][m-1]);
}

int main(){
    
    cin >> s1 >> s2;
    
    n=strlen(s1);
    m=strlen(s2);
    
    lcs();
    
    return 0;
}
/*
sample input:

abhishekcs
rajakcs

*/

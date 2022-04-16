/*
	祝你有一天能和你重要的人重逢
             =@.                                 
             @@@`                                
            .@@@@^                ..             
            .@@@@@\]]`.      .]@@@@`             
             @@@@@@@@@@@@@@@@@@@@@.              
          ./@@@@@@@@@@@@@@@@@@@@/                
         =@@@@@^,]\@@@@@@[@@@@@^                 
   .]],[[@@@@@@@/O@@@@@\=@\@@@@@^                
    .]/[..@@@@@@@@@@@@@@@@@@@@@@@.               
           ,\@@@@@@@@@@@@@@@@@@/\.               
              .[\@@@@@@@@@@@[..\` ..     .]].    
                  =@@@@@^        ,`     /.  .\   
                  =@@@@@@^             .@@`  =^  
                  =@@@@@@@^              .   =.  
                  \^=@@@@@@\                ,`   
                  =@@@@@@@@@@`             /.    
                  =@@@@@@@@@@@\          ]`      
                  =/@@@@@@@@@@@@\     ./.        
                  =\=@@@@@@@@@@@@@^ ,/           
                  =^.@@@@@@@@@@@@@@@`            
                  =^ @.\@@@@@@@@@@@@             
                ,]@.`@^ .\@@@@@@@@@^             
                ,[`[[[.,\@@@@@@@[[.              
*/

#include<bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long
#define debug(x) cout << #x << " is " << x << endl
#define mkp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define inf 2e18
#define PI 3.1415926535898
#define I i
using namespace std;

const int N = 400005;
const int mod = 1e9+7;

int d[505][505];


signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n+1);
	for(int i =1;i<=n;++i)
		cin >> a[i];
	
	for(int i = 1;i<=n;++i){
		int k =1;
		for(int j = 1; j <= n;++j){
			if(a[j]>=i)
				d[i-1+k][k] = a[j],k++;
		}
	}
	
	
	for(int i = 1;i<=n;++I){
		for(int j = 1;j<=i;++j)
			cout << d[i][j] << " ";
		cout << endl;
	}
		

  
	
    return 0;
}

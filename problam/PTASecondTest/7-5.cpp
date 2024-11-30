#include <bits/stdc++.h>
using namespace std;
bool arr[4][14];
int main(){
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		char c;
		char b;
		cin>>c>>b;
		if(c == 'D'){
			if(b == 'A')arr[0][1] = true;
			else if('2'<= b && b<='9')arr[0][b-'0'] = true;
			else if (b == 'T')arr[0][10] = true;
			else if (b == 'J')arr[0][11] = true;
			else if (b == 'Q')arr[0][12] = true;
			else if (b == 'K')arr[0][13] = true;
		}
		else if(c == 'C'){
			int aa = 1;
			if(b == 'A')arr[aa][1] = true;
			else if('2'<= b && b<='9')arr[aa][b-'0'] = true;
			else if (b == 'T')arr[aa][10] = true;
			else if (b == 'J')arr[aa][11] = true;
			else if (b == 'Q')arr[aa][12] = true;
			else if (b == 'K')arr[aa][13] = true;
		}
		else if(c == 'H'){
			int aa = 2;
			if(b == 'A')arr[aa][1] = true;
			else if('2'<= b && b<='9')arr[aa][b-'0'] = true;
			else if (b == 'T')arr[aa][10] = true;
			else if (b == 'J')arr[aa][11] = true;
			else if (b == 'Q')arr[aa][12] = true;
			else if (b == 'K')arr[aa][13] = true;
		}
		else if(c == 'S'){
			int aa = 3;
			if(b == 'A')arr[aa][1] = true;
			else if('2'<= b && b<='9')arr[aa][b-'0'] = true;
			else if (b == 'T')arr[aa][10] = true;
			else if (b == 'J')arr[aa][11] = true;
			else if (b == 'Q')arr[aa][12] = true;
			else if (b == 'K')arr[aa][13] = true;
		}
	}
	int ans = 0;
	for(int i = 0;i<4;i++){
		for(int j =1;j<=13;j++){
			if(arr[i][j] == false)ans++;
		}
	}
	cout<<ans;
	return 0;
}

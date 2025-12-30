#include<iostream>
#include<vector>

using namespace std ;

vector<int> sav(12);
vector<bool> used(12,false);
int ans = 1e6 ;

void up(vector<int>& sum,int index){
	if(index == 4){
		int MIN = 1e6 ,MAX = -1e6 ;
		for(int& i : sum){
			MIN = min(i,MIN);
			MAX = max(i,MAX);
		}
		ans = min(ans,MAX - MIN);
		return ;
	}
	for(int i = 0 ; i < 12 ; i ++){
		if(used[i]) continue ;
		for(int j = i + 1 ; j < 12 ; j ++){
			if(used[j])continue ;
			for(int k = j + 1 ; k < 12 ; k ++){
				if(used[k]) continue ;
				sum[index] = sav[i] + sav[j] + sav[k];
				used[i] = used[j] = used[k] = true ;
				up(sum,index + 1);
				used[i] = used[j] = used[k] = false ; 
			}
		}
	}
	return ;
}



int main(){
	for(int i = 0 ; i < 12 ; i ++) cin >> sav[i];
	vector<int> sum(4);
	up(sum,0);
	cout << ans << endl ;
	return 0 ;
}
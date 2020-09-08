#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> N;
vector<int> Day;
vector<int> M;

vector<int> score;
vector<pair<long long,long long> > test;

int main(void){

	int B,L,D;
		scanf("%d %d %d",&B,&L,&D);
	vector<bool> valid(B,true);
	vector<vector<int> > lib_book(L);
	for(int i=0;i<B;i++){
		int temp;
		scanf("%d",&temp);

		score.push_back(temp);
	}

	for (int i = 0; i < L; ++i)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);


		N.push_back(a);
		Day.push_back(b);
		M.push_back(c);
		long long t = 0;
		for(int j=0;j<a;j++){
			int temp;
			scanf("%d",&temp);
			lib_book[i].push_back(temp);
			t+=score[temp];
		}
		sort(lib_book[i].begin(),lib_book[i].end());
		reverse(lib_book[i].begin(),lib_book[i].end());
		test.push_back(make_pair(t,i));
	}
//	cout<<" ";
	sort(test.begin(),test.end());

	long long ans = 0;
	long long books_done = 0;
	int last_index = 0;

	for (int i = 0; i < D; ++i)
	{
		

		if(books_done>=B) break;

		for (int j=0;j<last_index;j++)
		{
			int cnt2 = 0;
			for(int k=0;k<N[test[j].second];k++){
				if(valid[lib_book[test[j].second][k]] && cnt2<M[test[j].second]){
					valid[lib_book[test[j].second][k]] = false;
					ans+=score[lib_book[test[j].second][k]];
					books_done++;
					cnt2++;
				}
				if(cnt2>=M[test[j].second]) break;
			}
		}

		Day[test[last_index].second]--;
		if(Day[test[last_index].second] <= 0){
			last_index++;
		}
	}

	cout<<ans<<endl;
  return 0;
}

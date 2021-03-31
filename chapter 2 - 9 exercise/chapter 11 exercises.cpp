#include <iostream>
#include <vector>

int main()
{
	using namespace std;
	vector<int> dp(8, 1);
	for (int i = 0; i < 8; i++)
		cout << dp[i];
	return 0;
	int length = dp.size();
}
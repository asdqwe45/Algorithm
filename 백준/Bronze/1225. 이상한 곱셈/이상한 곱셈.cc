#include <iostream>
#include <string>
using namespace std;


int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	long long result = 0;
	
	for (long long i = 0; i < str1.size(); i++) {
		for(long long j = 0; j < str2.size(); j++){
			result += (int(str1[i])-48) * (int(str2[j])-48);
		}
	}
	cout << result << endl;

	return 0;
}
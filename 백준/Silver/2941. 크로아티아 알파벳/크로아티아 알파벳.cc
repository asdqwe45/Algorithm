#include <iostream>
#include <string>
using namespace std;




int main() {
    
    string str;
    cin >> str;
    int cur = 0;
    int cnt = 0;

    while (cur < str.length()) {
        string temp = str.substr(cur, 2);
        if (temp == "c=") {
            cur += 2;
           
        }
        else if (temp == "c-") {
            cur += 2;

        }
        else if (temp == "d-") {
            cur += 2;

        }
        else if (temp == "lj") {

            cur += 2;
        }
        else if (temp == "nj") {
            cur += 2;

        }
        else if (temp == "s=") {
            cur += 2;

        }
        else if (temp == "z=") {
            cur += 2;

        }
        else {
            temp = str.substr(cur, 3);
            if (temp == "dz=") {
                cur += 3;
            }
            else {
                cur++;
            }
        }
        cnt++;
    }

    cout << cnt << endl;
	
	return 0;
}
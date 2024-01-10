#include <iostream>
#include <string>
using namespace std;




int main() {
    
    string str;
    double db;
    string score;

    double low = 0.0000000f;
    double up = 0.0000000f;

    for (int i = 0; i < 20; i++) {

        cin >> str >> db >> score;

        if (str.size() == 0)
            break;

        if (score == "A+") {
            up += 4.500000f * db;
            low += db;
        }
        else if (score == "A0") {
            up += 4.000000f * db;
            low += db;

        }
        else if (score == "B+") {
            up += 3.500000f * db;
            low += db;

        }
        else if (score == "B0") {
            up += 3.00000f * db;
            low += db;

        }
        else if (score == "C+") {
            up += 2.500000f * db;
            low += db;

        }
        else if (score == "C0") {
            up += 2.000000f * db;
            low += db;

        }
        else if (score == "D+") {
            up += 1.500000f * db;
            low += db;

        }
        else if (score == "D0") {
            up += 1.000000f * db;
            low += db;

        }
        else if (score == "F") {
            low += db;

        }
        
    }

    cout << up/low << endl;
	
	return 0;
}
#include <iostream>
#include <string>

using namespace std;

int pangramCheck(string &);

int main(void)
{
	string sentenceToCheck;

	cout << "Enter the sentence you would like to check if it's a pangram:" << endl;
	getline(cin, sentenceToCheck);
	pangramCheck(sentenceToCheck);

	return 0;
}

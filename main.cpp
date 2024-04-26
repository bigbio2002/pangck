#include <iostream>
#include <string>
#include "pangcheck.h"

using namespace std;

int main()
{
	string sentenceToCheck;

	cout << "Enter the sentence you would like to check if it's a pangram:" << endl;
	getline(cin, sentenceToCheck);
	pangramCheck(sentenceToCheck);

	return 0;
}

#include <iostream>
#include <string>
#include <iomanip>	//for setw()
#include <cstdlib>	//for exit()
#include <cstring>	//for memset()
#include <cctype>	//for islower/isupper

using namespace std;

#define PANGRAM_MAX 128

int pangramCheck(string &sentence)
{
	//longest (sensible) pangram I could find on Google was 51 characters. Perhaps a creative linguist could make one longer, but not too much so.
	//char sentenceChars[PANGRAM_MAX];

	unsigned int letterFreq[26];
	unsigned int totalLetters = 0;
	bool notPerfect = false;
	bool notPangram = false;
	// initialize array-
	memset(letterFreq, 0, sizeof(letterFreq));

	for(string::size_type i = 0; i < sentence.length(); ++i)
	{
		// TODO: change to use ctype isprint() function or similar and
		// add localization so non-engliah pangrams can be checked.

		// only printable ASCII characters, including symbols/punct.
		if(!isprint(sentence[i]))
		{
			cout << "ERROR: This program currently only supports pangrams composed of characters from the English alphabet. Check your input and try again." << endl;
			exit(EXIT_FAILURE);
		}

		// total the frequency of each letter
		if(islower(sentence[i]))
		{
			++letterFreq[(sentence[i]-97)];
		}
		else if(isupper(sentence[i]))
		{
			++letterFreq[(sentence[i]-65)];
		}
	}

	for(int i=0;i<26;i++)
	{
		if(letterFreq[i] == 0 && !notPangram)
		{
			notPangram = true;
		}
		// sum the number of letters for "perfect" determination
		totalLetters += letterFreq[i];

		// must be exaxtly 1 of every letter to be perfect
		if(letterFreq[i] != 1 && !notPerfect)
		{
			notPerfect = true;
		}
	}

	if(!notPerfect)
	{
		cout << "\nYour pangram is PERFRCT!!" << endl;
		exit(EXIT_SUCCESS);
	}
	else if(notPangram)
	{
		cout << "\nYour sentence is NOT a pangram.\n\n";
	}
	else
	{
		cout << "\nYour sentence IS A PANGRAM!!\n\n";
	}

	cout << "Your pangram contains " << totalLetters << " letters:\n\n";
	for(char abc=65;abc<91;abc++)
	{
		cout << "  " << abc;
	}
	cout << "\n";
	for(int i=0;i<26;i++)
	{
		cout << setw(3) << letterFreq[i];
	}
	cout << "\n";

	exit(EXIT_SUCCESS);
}

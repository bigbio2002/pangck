#include <iostream>
#include <string>
#include <cctype>

using namespace std;

#define PANGRAM_MAX 128

int pangramCheck(string &sentence)
{
	//longest (sensible) pangram I could find on Google was 51 characters. Perhaps a creative linguist could make one longer, but not too much so.
	//char sentenceChars[PANGRAM_MAX];

	unsigned int letterFreq[26];
	unsigned int totalLetters = 0;
	bool notPerfect = false;
	// initialize array-
	memset(&letterFreq, 0, 26);

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

		//count frequency of each letter
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
		if(letterFreq[i] == 0)
		{
			cout << "Your sentence is not a pangram." << endl;
			exit(EXIT_SUCCESS);
		}
		// sum the number of letters for "perfect" determination
		totalLetters += letterFreq[i];

		// must be exaxtly 1 of every letter to be perfect
		if(letterFreq[i] != 1)
		{
			notPerfect = true;
		}
	}

	if(!notPerfect)
	{
		cout << "Your pangram is PERFRCT!!" << endl;
		exit(EXIT_SUCCESS);
	}
	else
	{
		cout << "Your pangram contains " << totalLetters << " letters:\n\n";
		for(char abc=65;abc<91;abc++)
		{
			printf("  %c", abc);
		}
		printf("\n");
		for(int i=0;i<26;i++)
		{
			printf(" %2i", letterFreq[i]);
		}
		printf("\n");
	}

	exit(EXIT_SUCCESS);
}

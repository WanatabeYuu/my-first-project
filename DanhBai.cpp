#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;
int threeofkind(int phand[5])
{
	int frequency[13] = { 0 }, keep = 0;

	for (int p = 0; p < 5; p++)
		++frequency[phand[p]];

	for (int p2 = 0; p2 <= 12; p2++)
	{
		if (frequency[p2] == 3)
		{
			keep += 3;
		}
	}
	return keep;
}
	int Twopair(int phand[5])
	{
	int frequency[13] = { 0 }, keep = 0;

	for (int p = 0; p < 5; p++)
		++frequency[phand[p]];
	for (int p2 = 0; p2 <= 12; p2++)
	{
		if (frequency[p2] == 2)
		{
			keep += 2;

		}
	}
	return keep;
}
int fourofkind(int phand[5])
{
	int frequency[13] = { 0 }, keep = 0;

	for (int p = 0; p < 5; p++)
		++frequency[phand[p]];

	for (int p2 = 0; p2 <= 12; p2++)
	{
		if (frequency[p2] == 4)
		{
			keep += 4;
			break;
		}
	}
	return keep;
}
int main()
{
	srand(time(0));
	int deck[52];
	int i;
	string suitnames[4] = { "bich", "co", "chuon", "ro" };
	string ranknames[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

	// create a new deck, with cards in order, but unique
	for (i = 0; i < 52; i++)
	{
		deck[i] = i;
	}

	// shuffle the deck:
	for (i = 0; i < 52; i++)
	{
		// generate a random index to swap with the card at index i.
		int j = rand() % 52;
		int temp = deck[i];
		deck[i] = deck[j];
		deck[j] = temp;
	}


	// print all the cards
	for (i = 0; i < 52; i++)
	{
		int suitnumber = deck[i] / 13; // 0 - 3
		int rank = deck[i] % 13;
		cout << ranknames[rank] << " of " << suitnames[suitnumber] << "\n";
	}

	// Check first 5 cards for an ace
	cout << endl;
	for (i = 0; i < 5; i++)
	{
		int acerank = 0;
		int currentCardRank = deck[i] % 13;
		if (currentCardRank == acerank)
		{
			cout << "Co 1 Ace!" << endl;
		}
	}

	// Get the rank of the first 5 cards
	int R[5]; // = {4, 7, 6, 3, 5}; // rank of the first 5 cards
	int S[5];
	for (i = 0; i < 5; i++)
	{
		R[i] = deck[i] % 13;
		S[i] = deck[i] / 13;
	}

	// Sort the R array
	bool swapped = false;
	do
	{
		// 1 pass of the bubble sort
		swapped = false;
		for (int i = 0; i < 4; i++)
		{
			if (R[i] > R[i + 1])
			{
				int temp = R[i];
				R[i] = R[i + 1];
				R[i + 1] = temp;
				swapped = true;
			}
		}
	} while (swapped == true);

	// print the sorted ranks and suits
	for (i = 0; i < 5; i++)
	{
		cout << ranknames[R[i]]<< " " << suitnames[S[i]] << "\n";
	}

	// Check for a straight:
	if (R[1] == R[0] + 1 && R[2] == R[1] + 1 && R[3] == R[2] + 1 && R[4] == R[3] + 1)
	{
		cout << "Sanh!" << endl;
	}
	else
	{
		cout << "Khong co sanh" << endl;
	}

	// Check first 5 cards for any pair
	if (R[0] == R[1] || R[1] == R[2] || R[2] == R[3] || R[3] == R[4])
	{
		cout << "1 Doi!" << endl;
	}
	else
	{
		cout << "Khong co doi nao" << endl;
	}
	// Check for a Twopair
	if (Twopair(R) == 4)//Only if there are two pairs
	{
		cout << "2 Doi!" <<endl;
	}
	// Check for a flush (all the same suit)
	if (S[0] == S[1] && S[1] == S[2] && S[2] == S[3] && S[3] == S[4])
	{
		cout << "Thung!" << endl;
	}
	else
	{
		cout << "Khong co thung" << endl;
	}

	// Check for straight flush
	if (S[0] == S[1] && S[1] == S[2] && S[2] == S[3] && S[3] == S[4] &&
		R[1] == R[0] + 1 && R[2] == R[1] + 1 && R[3] == R[2] + 1 && R[4] == R[3] + 1)
	{
		cout << "Thung pha sanh! " << endl;
	}
	// Check for 4 of a kind
	if (threeofkind(R) == 3)//if there is three of a kind
	{
		if (fourofkind(R) == 4)
			cout << "Tu Qui!" << endl;
		else
			cout << "Cu lu!" << endl;	// Check for full house
	}

	system("pause");
	return 0;
}
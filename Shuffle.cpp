// --------------------------------------------------------------
// Nicolas Corfmat
// CruzID: ncorfmat
// Assignment: pa5
// --------------------------------------------------------------

#include <iostream>
#include <string>
#include <sstream>

#include "List.h"

using namespace std;

#define MAX_LEN 300;

void shuffle(List& deck) {
	deck.moveFront();

	// CREATE left deck.
	
	List leftSide;
	int left_length = deck.length()/2;

	for (int i = 0; i < left_length; i++) {
		leftSide.insertBefore(deck.moveNext());
	}

	// CREATE right deck.
	
	List rightSide;
	int right_length = deck.length() - left_length;

	for (int i = 0; i < right_length; i++) {
		rightSide.insertBefore(deck.moveNext());
	}

	// CLEAR original deck.

	deck.clear();

	// COMBINE left and right decks in alternating order.

	leftSide.moveFront();
	rightSide.moveFront();

	while (leftSide.length() > 0 || rightSide.length() > 0) {
		if (rightSide.length() > 0) {
			deck.insertBefore(rightSide.moveNext());
			rightSide.eraseBefore();
		}

		if (leftSide.length() > 0) {
			deck.insertBefore(leftSide.moveNext());
			leftSide.eraseBefore();
		}
	}

	deck.moveFront();
}

int main(int argc, char * argv[]) {

	// READ one command line argument.
	
	if (argc != 2) {
		cerr << "Usage: " << argv[0] << " <maximum deck size>" << endl;
		return(EXIT_FAILURE);
	}

	int maxDeckSize = std::stoi(argv[1]);

	std::cout << "deck size\tshuffle count\n";
	std::cout << "------------------------------\n";

	// PERFORM shuffles.

	for (int i = 1; i <= maxDeckSize; i++) {
		List deck;

		// POPULATE deck.
		for (int j = 0; j < i; j++) {
			deck.insertBefore(j);
		}

		// MAKE copy of deck for future purposes.
		List originalDeck = deck;

		int shuffleCount = 0;

		do {
			shuffle(deck);
			shuffleCount++;
		} while (!(deck == originalDeck));

		std::cout << " " << i << "\t\t " << shuffleCount << std::endl;
	}

	return 0;
}

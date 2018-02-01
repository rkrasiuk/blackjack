#include "cards.hpp"	

#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
using namespace std;

int blackjack_add(Card const& lhs, Card const& rhs) {
	auto sum = lhs + rhs;
	if (lhs.rank == ACE || rhs.rank == ACE)
		sum += 10;
	return sum;
}

int main() {
	/*Card c;
	c.rank = ACE;
	c.suit = SPADES;
	Card d{ TWO, HEARTS };
	cout << c << ", " << d << endl;*/

	auto deck = make_standard_deck();

	// shuffle
	//random_shuffle(deck.begin(), deck.end());// uses rand() - deprecated - gone C++ 17
	default_random_engine rengine((unsigned)time(0));
	shuffle(deck.begin(), deck.end(), rengine);

	/*for (auto card : deck)
		cout << card;*/

	// deal three hands
	vector<DeckOfCards> hands(3);
	int constexpr NCARDS_PER_HAND = 2;
	for(int i = 0; i < NCARDS_PER_HAND; ++i)
		for (auto& hand : hands) {
			hand.push_back(deck.back);
			deck.pop_back();
		}

	// sort the hands
	for (auto& hand : hands)
		sort(hand.begin(), hand.end());

	// fint the winner
	for (auto hand : hands) {
		cout << blackjack_add(hand.front(), hand.back()) << " = " << hand.front() << " + " << hand.back() << endl;
	}
}
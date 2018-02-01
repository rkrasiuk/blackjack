#include <iostream>
#include "cards.hpp"
using namespace std;

char const* suits[] = { "Clubs", "Diamonds", "Hearts", "Spades" };
char const* ranks[] = { "", "Ace", "2", "3", "4", "5", "6", "7" "8", "9", "10", "Jack", "Queen", "King" };

ostream& operator << (ostream& os, Card const& card) {
	//if (card.rank == ACE)
	//	os << "Ace";

	//switch (card.rank) {
	//	case ACE : os << "Ace"; break;
	//	case TWO: os << "Two"; break;
	//		// etc.
	//}

	return os << ranks[card.rank] << "-of-" << suits[card.suit];
}

bool operator < (Card const& lhs, Card const& rhs) {
	return lhs.rank < rhs.rank || (lhs.rank == rhs.rank && lhs.suit < rhs.suit);
}

int operator + (Card const& lhs, Card const& rhs) {
	int lhv = lhs.rank >= TEN ? 10 : int(lhs.rank);
	int rhv = rhs.rank >= TEN ? 10 : int(rhs.rank);
	return lhv + rhv;
}

DeckOfCards make_standard_deck() {
	DeckOfCards deck;
	deck.reserve(52);
	for (int suit = CLUBS; suit <= SPADES; ++suit)
		for (int rank = ACE; rank <= KING; ++rank)
			deck.push_back(Card{ CardRank(rank), CardSuit(suit) });
	return deck;
}
#if !defined(GUARD_CARDS_HPP)
#define GUARD_CARDS_HPP

#include <iostream>
#include <vector>

enum CardSuit { CLUBS, DIAMONDS, HEARTS, SPADES };
enum CardRank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};

class Card {
public:
	CardRank rank;
	CardSuit suit;
};

std::ostream& operator << (std::ostream& os, Card const& card);

using DeckOfCards = vector<Card>;
DeckOfCards make_standard_deck();
bool operator < (Card const& lhs, Card const& rhs);
int operator + (Card const& lhs, Card const& rhs);
#endif
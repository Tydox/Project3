#pragma once
#define SPADE L"\u2660"
#define CLUB L"\u2663"
#define HEART L"\u2665"
#define DIAMOND L"\u2666"

class Card {

private:
	char sign;
	int value;

public:
	void setCard(char c, int v);
	void printCard() const;
	char getSign()const;
	int getValue()const;

	friend bool operator>(const Card& lv,const Card& rv){return (lv.value > rv.value);}
	friend bool operator==(const Card& lv,const Card& rv){return (lv.value == rv.value);}
	
#ifdef DEBUG
	~Card();
#endif	
};


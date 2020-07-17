#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(c.value >= 2 && c.value <= VALUE_ACE);
  assert(c.suit >= SPADES && c.suit <= CLUBS);
}

const char * ranking_to_string(hand_ranking_t r) {
  if (r.STRAIGHT_FLUSH) {
    return "Straight Flush";
  } else if (r.FOUR_OF_A_KIND) {
    return "Four of a Kind";
  } else if (r.FULL_HOUSE) {
    return "Full House";
  } else if (r.FLUSH) {
    return "Flush";
  } else if (r.STRAIGHT) {
    return "Straight";
  } else if (r.THREE_OF_A_KIND) {
    return "Three of a Kind";
  } else if (r.TWO_PAIR) {
    return "Two Pair";
  } else if (r.PAIR) {
    return "Pair";
  } else if (r.NOTHING) {
    return "Nothing";
  } else {
  return "error";
  }
}

char value_letter(card_t c) {
  if (c.value == 2) {
    return "2";
  } else if (c.value == 3) {
    return "3";
  } else if (c.value == 4) {
    return "4";
  } else if (c.value == 5) {
    return "5";
  } else if (c.value == 6) {
    return "6";
  } else if (c.value == 7) {
    return "7";
  } else if (c.value == 8) {
    return "8";
  } else if (c.value == 9) {
    return "9";
  } else if (c.value == 10) {
    return "0";
  } else if (c.value == VALUE_JACK) {
    return "J";
  } else if (c.value == VALUE_QUEEN) {
    return "Q";
  } else if (c.value == VALUE_KING) {
    return "K";
  } else if (c.value == VALUE_ACE) {
    return "A";
  } else {
    return "?";
  }
}


char suit_letter(card_t c) {
  if (c.suit == SPADES) {
    return "s";
  } else if (c.suit == HEARTS) {
    return "h";
  } else if (c.suit == DIAMONDS) {
    return "d";
  }else if (c.suit == CLUBS) {
    return "c";
  } else {
    return "?";
  }
  
}

void print_card(card_t c) {
  char value = value_letter(c); //assign value_letter to new char variable
  char suit = suit_letter(c); //assign suit_letter to new char variable
  printf("%c%c", value, suit); //print both chars using newly assigned variables
  return 0; //exit function
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  temp.value = value_let;
  temp.suit = suit_let;
  return temp;

  // if statement to check for valid values
  if (value_letter(value_let) == "?" || suit_letter(suit_let) == "?") {
    printf("Error: Program Quitting");
    exit(EXIT_FAILURE);
  }
}

card_t card_from_num(unsigned c) {
  card_t temp;
  
  assert(c >= 0 && c < 52);
  
  temp.value = c % 13 + 2;
  temp.suit = c / 13;
  return temp;
}

import random
from enum import Enum
from utilities import sgn

# first define some enumerate values
class Action(Enum):
    HITS = 1
    STICKS = 2

class Color(Enum):
    RED = 1
    BLACK = 2

class Card:
    def __init__(self, num, color):
        self.num = num
        self.color = color
    
    def calc_score(self) -> int:
        return self.num if self.color is Color.BLACK else -self.num

class Easy21_environment:
    def draw_card(self):
        # draw a card according to the rule
        card_val = random.randint(1, 10)
        if random.randint(1, 3) == 1:
            card_color = Color.RED
        else:
            card_color = Color.BLACK
        return Card(card_val, card_color)
    
    def draw_black_card(self):
        return Card(random.randint(1, 10), Color.BLACK)
    
    def is_bust(self, score) -> bool:
        return score < 1 or score > 21
    
    def dealer_move(self, first_card) -> int:
        # return the final score of the dealer
        current_score = first_card.calc_score()
        while not self.is_bust(current_score) and current_score < 16:
            new_card = self.draw_card()
            current_score += new_card.calc_score()
        return current_score

    def step(self, state, action):
        # state is a binary tuple: (dealer_first_card, player_score)
        dealer_first_card, player_score = state
        assert(not self.is_bust(player_score))
        if action == Action.HITS:
            new_card = self.draw_card()
            player_score += new_card.calc_score()
            if self.is_bust(player_score):
                return (None, -1)
                # None: termination
            else:
                return ((dealer_first_card, player_score), 0)
        else:
            # sticks
            dealer_score = self.dealer_move(dealer_first_card)
            if self.is_bust(dealer_score):
                return (None, 1)
            else:
                return (None, sgn(player_score - dealer_score))
    
    def start_game(self):
        dealer_first_card = self.draw_black_card()
        player_first_card = self.draw_black_card()
        return (dealer_first_card, player_first_card.calc_score())
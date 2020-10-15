import random
from game_environment import Action

class Q_table:
    def __init__(self, learning_rate = 1.0, exploration_parameter = 0.8, discount_factor = 1):
        self.table = dict()
        self.gamma = discount_factor
        self.alpha = learning_rate
        self.epsilon = exploration_parameter

    def _epsilon(self, num_epsilon):
        # maybe epsilon can change with time
        return self.epsilon
    
    def greedy_q(self, state):
        res = self.table.get((state, Action.HITS), 0)
        if self.table.get((state, Action.STICKS), 0) > res:
            return self.table.get((state, Action.STICKS), 0), Action.STICKS
        else:
            return res, Action.HITS

    def explore(self, state, num_epsilon):
        if random.random() < self._epsilon(num_epsilon):
            # choose an action at random
            return Action(random.randint(1, 2))
        else:
            # choose a greedy action
            return self.greedy_q(state)[1]
        
    def update(self, state, action, reward, next_state):
        # SARS
        old_q = self.table.get((state, action), 0)
        if next_state is not None:
            reward += self.gamma * self.greedy_q(next_state)[0] - old_q
        self.table[(state, action)] = old_q + self.alpha * reward
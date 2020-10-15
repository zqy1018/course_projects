from game_environment import Easy21_environment
from q_learning import Q_table

game = Easy21_environment()
num_episode = 300000
q_table = Q_table()

cnt = [0] * 3

for episode in range(num_episode):
    current_state = game.start_game()
    while current_state is not None:
        action = q_table.explore(current_state, episode)
        next_state, reward = game.step(current_state, action)
        q_table.update(current_state, action, reward, next_state)
        current_state = next_state
    cnt[reward + 1] += 1

print(cnt)
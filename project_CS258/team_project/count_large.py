import subprocess, random

program_name = "improved_heap_sort_2.exe"
total_testcases = 20
test_n = [1000000 + i * 500000 for i in range(1, 9)]
total_time = [0] * len(test_n)

# set these parameters above by yourself

for idx, n in enumerate(test_n):
    for i in range(total_testcases):
        seed = random.randint(1, 4294967295)
        res = subprocess.check_output(program_name + " " + str(n) + " " + str(seed), shell=True)
        res = res.decode('gbk').strip()
        total_time[idx] += int(res)

with open(program_name + "large.txt", "w") as f:
    for idx, n in enumerate(test_n):
        print("For n = " + str(n) + ", average time: " + str(total_time[idx] / total_testcases) + " ns.")
        f.write(str(n) + " " + str(total_time[idx] / total_testcases) + "\n")
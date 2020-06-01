import subprocess, random

program_name = "original_heap_sort.exe"
total_testcases = 20
test_n = [i * 1000 for i in range(1, 100)] + [i * 10000 for i in range(11, 101)]
total_time = [0] * len(test_n)

# set these parameters above by yourself

for idx, n in enumerate(test_n):
    for i in range(total_testcases):
        seed = random.randint(1, 4294967295)
        res = subprocess.check_output(program_name + " " + str(n) + " " + str(seed), shell=True)
        res = res.decode('gbk').strip()
        total_time[idx] += int(res)

with open(program_name + "1.txt", "w") as f:
    for idx, n in enumerate(test_n):
        print("For n = " + str(n) + ", average time: " + str(total_time[idx] / total_testcases) + " ns.")
        f.write(str(n) + " " + str(total_time[idx] / total_testcases) + "\n")
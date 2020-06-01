import matplotlib.pyplot as plt

x = [1000000 + i * 500000 for i in range(1, 9)]
y1, y2 = [], []
with open("original_heap_sort.exelarge.txt", "r") as f:
    for l in f.readlines():
        l = l.strip()
        a, b = l.split()
        y1.append(float(b) / 1e9)

with open("improved_heap_sort_2.exelarge.txt", "r") as f:
    for l in f.readlines():
        l = l.strip()
        a, b = l.split()
        y2.append(float(b) / 1e9)
 
plt.title("Execution Time of Two Implementations of Heapsorts On Large Datasets", fontsize=20)
plt.xlabel("Length of Sequence (n)", fontsize=14)
plt.ylabel("Execution Time (s)", fontsize=14)

plt.plot(x, y1, color="red", label="Original Heapsort")
plt.plot(x, y2, color="orange", label="Fast Heapsort (Rearranged)")
 
plt.legend()
plt.show()
import time

def towerOfHanoi(n, src, temp, dst):
    if n == 1:
        print(f"Move disk 1 from {src} to {dst}")
        return
    
    towerOfHanoi(n - 1, src, dst, temp)
    
    print(f"Move disk {n} from {src} to {dst}")

    towerOfHanoi(n - 1, temp, src, dst)

n = int(input("Enter the number of disks: "))
start = time.time()
towerOfHanoi(n, 'A', 'B', 'C')
end = time.time()
diff = end - start
print(f"The time taken is {diff} seconds")
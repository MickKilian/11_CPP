import sys
import math

def calculate_a1(n):
    result = 0
    for k in range(1, n+1):
        log_val = math.ceil(math.log2(3*k/4))
        result += log_val
    return result

# Vérifier si un argument est passé
if len(sys.argv) != 2:
    print("Usage: python script.py <n>")
    sys.exit(1)

n = int(sys.argv[1])
result = calculate_a1(n)
print("a({}) = {}".format(n, result))

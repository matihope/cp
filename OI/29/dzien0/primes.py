def isPrime(n):
    if n <= 1:
        return False

    i = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += 1
    return True


primes = 0

for i in range(2, 1000000):
    if isPrime(i):
        primes += 1

print(primes)

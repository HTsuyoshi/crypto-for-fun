from sage.all import *

KEY_SIZE = 2^(1024)
print(KEY_SIZE)
OFFSET = 1000

# RSA
def RSA(m: int, e: int, n: int) -> int:
    ring = Integers(n)
    c = ring(m) ** e
    return c

if __name__ == '__main__':

    m = input('Write your message here: ').encode()
    m = int.from_bytes(m, byteorder='little')
    print(f'm as int: {m}')

    p = random_prime(n = KEY_SIZE*OFFSET, lbound = KEY_SIZE)
    q = random_prime(n = KEY_SIZE*OFFSET, lbound = KEY_SIZE)
    print(f'p = {p}, q = {q}')

    n = p * q
    print(f'n = {n}')

    def euler_func(q, p):
        return (q-1) * (p-1)

    phi = euler_func(q, p)
    print(f'phi = (q-1)*(r-1) = {q - 1} x {r - 1} = {phi}\n')

    try:
        d = pow(m, -1, phi)
    except ZeroDivisionError:
        print(f'The message doesn\'t have an inverse')
        exit(1)

    ring = Integers(n)
    p = ring(p)
    print(f'm = {m}, p = {p}, m*p = {p * m} mod {n}\n')

    # Ex 6
    ring = Integers(phi)
    p = pow(m, -1, phi)
    print(f'm = {m}, p = {p}, m*p = {p * m} mod {phi}\n')
    assert p * m == 1

    c = RSA(m, p, n)
    print(f'c = {c}\n')

    # Ex 10
    m = RSA(c , d, n)
    print(f'm = {m}\n')
    assert c == m, f'Inverse doesn\'t match'

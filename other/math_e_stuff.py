

def exp(p: float, precision: int = 100) -> float:
    # calculate e
    e = s = 1
    for i in range(1, precision):
        s *= i
        e += powi(p, i) / s
    return e


def powi(number: float, exponent: int) -> float:
    result = 1
    while exponent > 0:
        if exponent & 1:
            result *= number
        number = number * number
        exponent //= 2
    return result


def root(base: int, number: int) -> float:
    EPS = 1e-12
    left = 0
    right = number
    while abs(left - right) >= EPS:
        mid = (left + right) / 2
        if powi(mid, base) >= number:
            right = mid
        else:
            left = mid
    return left


def calc_pi(rect_size: int):
    # calculate pi
    EPS = 10
    circle_center = rect_size / 2
    counter = 0
    for y in range(rect_size + 1):
        for x in range(rect_size + 1):
            if abs((x - circle_center) ** 2 + (y - circle_center) ** 2) <= circle_center ** 2 + EPS:
                counter += 1
    return counter / (rect_size + 1) ** 2 * 4


def log(number: float, base: int = 10) -> float:
    if base <= 0:
        raise ValueError("Base must be positive")
    if base == 1:
        raise ValueError("Base mustn't be equal to 1")

    return ln(number) / ln(base)


def ln(number: float) -> float:
    if number <= 0:
        raise ValueError("Invalid logarithm argument! Should be > 0")
    left = -1e15
    right = 1e15
    EPS = 1e-14
    while abs(left - right) >= EPS:
        mid = (left + right) / 2
        if exp(mid) >= number:
            right = mid
        else:
            left = mid
    return left


def pow(base: float, exponent: float) -> float:
    if base == 0:
        return 0
    if exponent == 0:
        return 1
    if exponent < 1:
        return 1 / pow(base, -exponent)

    whole_num = powi(base, int(exponent))
    floating = exponent - int(exponent)
    left = 1
    from math import log as mlog
    if floating > 0:
        left = 0
        right = 1e15
        EPS = 1e-15
        while abs(left - right) >= EPS:
            mid = (left + right) / 2
            if log(mid, base) >= floating:
                right = mid
            else:
                left = mid
    return whole_num * left


if __name__ == "__main__":
    print(exp(0))
    print(exp(1))
    print(log(9))
    e = exp(1)
    pi = 3.1415926535
    print(pow(2, pi))

# Power (x, n)

Simply return the pow(x, n) as x\*\*n, but without using iterative approach. Using recursion

# Solution

```cpp
double power(double x, long num) {
    // edge cases
    if (num == 0)
        return 1.0;
    if (num == 1)
        return x;

    // if n is even
    if (num % 2 == 0) {
        return power(x * x, num / 2);
    }
    // if n is odd
    return x * power(x, num - 1);
}
double myPow(double x, int n) {
    long num = (long)n;

    if (num < 0) {
        return (1 / power(x, -1 * num));
    }
    return power(x, num);
}

```

// Fibonacci Number

// Leetcode 509 :: https://leetcode.com/problems/fibonacci-number/

int fib(int n)
{

    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

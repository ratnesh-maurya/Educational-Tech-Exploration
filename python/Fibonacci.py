# LANGUAGE: Python
# AUTHOR: Utkarsh Prajapati
# GITHUB: https://github.com/UtkarshPrajapati

# Fibonacci Series Using Recursion (Not Optimized)
# Time Complexity:- O(2^n) that is exponential
# Space Complexity:- O(N) that is linear

def fib(n):
  if n <=2:
    return n-1
  else:
    return (fib(n - 1) + fib(n - 2))
  
  
  # Driver Code:-
  print("The Fibonacci series is :\n")
  for i in range(10):
    print(fib(i))

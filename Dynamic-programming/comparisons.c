 in this case Recursion function started slowing at 40 and stop 50. Dynamic 
programming performed well and very fast with even large number like 100.
This are reasons why dynamic programming stands out from recursion

In the recursive version, the function repeatedly
recalculates the Fibonacci values for subproblems. For example
when calculating fibonacci(5), it will calculate fibonacci(3) twice, and
fibonacci(2) three times, leading to an exponential number of redundant calculations.

On the other hand, the dynamic programming approach with memoization avoids recomputing
the same values by storing them in a table (memo array in this case). When the function 
encounters a subproblem that has already been solved, it retrieves the precomputed result 
from the table rather than recalculating it. This significantly reduces the number of function 
calls and makes the algorithm more efficient.

In summary, dynamic programming with memoization optimizes the solution by trading off space 
complexity for improved time complexity, making it much faster than naive recursion 
for problems with overlapping subproblems.
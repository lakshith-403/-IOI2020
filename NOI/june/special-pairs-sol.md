[Problem link](https://www.hackerrank.com/contests/noi-2020-jun/challenges/special-pairs-2)

Prerequisites: [Divide and Conquer](https://www.geeksforgeeks.org/divide-and-conquer-algorithm-introduction/) , [Merge sort](https://www.geeksforgeeks.org/merge-sort/)

Statement: You are given an array $A$ of $N$ elements. You have to find number of Special Pairs such that $i < j  (0 \le i , j \le N-1)  A[i] > 2*A[j]$

Here i have used a Divide and Conquer Approach. Basically main problem has been divided in to smaller sub problems recursively until those becomes trivial to solve and finally merging those sub problems to create the main problem.

Let's first see how merging works. Imagine we have two sorted arrays and we already know the answer  for them.
First array is indexed from $l$ to $m$ and Second array is indexed from $m+1$ to $r$. As we already know the answer for each array and there is condition $i<j$ in the statement only possible way to create more pairs is to pair elements in the first array with the elements in the second array. If we could somehow find the number of possible elements form second array for each element in first array, sum of those values is the amount of pairs we can form by merging two arrays.

lets first multiply each element in the second array by two. let $l \le i \le m$ be the index of an element in first array and $l \le j \le r$ be the index of that element if we merge those two arrays in to one sorted array. Then the amount of pairs that can be formed using $i$ can be given as $$(i-l)-(j-l) = i-j$$
**Explanation:**
![expl img](https://i.imgur.com/1A64KMN.png)

##### *(Position of $i$ in the merged array is $j$. so the $i$ in merged array must be $j$. Sorry for the mistake)*

Note that no of blue elements before $i$ in the first array will always end up before $i$ and only some of the red elements end up before $i$ in the merged sorted array. We have to find the latter.
In reference to the given image,
*no of red elements before $j$ = total no of elements before $j$ - blue elements before $i$* = $(j-l) - (i-l) = j-l$

<img src="https://render.githubusercontent.com/render/math?math=(j-l) - (i-l) = j-l = -1">

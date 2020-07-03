[Problem link](https://www.hackerrank.com/contests/noi-2020-jun/challenges/special-pairs-2)

Prerequisites: [Divide and Conquer](https://www.geeksforgeeks.org/divide-and-conquer-algorithm-introduction/) , [Merge sort](https://www.geeksforgeeks.org/merge-sort/)

Statement: You are given an array <img src="https://render.githubusercontent.com/render/math?math=A"> of <img src="https://render.githubusercontent.com/render/math?math=N"> elements. You have to find number of Special Pairs such that <img src="https://render.githubusercontent.com/render/math?math=i < j  (0 \le i , j \le N-1)  A[i] > 2*A[j]">

Here i have used a Divide and Conquer Approach. Basically main problem has been divided in to smaller sub problems recursively until those becomes trivial to solve and finally merging those sub problems to create the main problem.

Let's first see how merging works. Imagine we have two sorted arrays and we already know the answer  for them.
First array is indexed from <img src="https://render.githubusercontent.com/render/math?math=l"> to <img src="https://render.githubusercontent.com/render/math?math=m"> and Second array is indexed from <img src="https://render.githubusercontent.com/render/math?math=m">+1 to <img src="https://render.githubusercontent.com/render/math?math=r">. As we already know the answer for each array and there is condition <img src="https://render.githubusercontent.com/render/math?math=i < j"> in the statement only possible way to create more pairs is to pair elements in the first array with the elements in the second array. If we could somehow find the number of possible elements form second array for each element in first array, sum of those values is the amount of pairs we can form by merging two arrays.

lets first multiply each element in the second array by two. let <img src="https://render.githubusercontent.com/render/math?math=l \le i \le m"> be the index of an element in first array and <img src="https://render.githubusercontent.com/render/math?math=l \le j \le r"> be the index of that element if we merge those two arrays in to one sorted array. Then the amount of pairs that can be formed using <img src="https://render.githubusercontent.com/render/math?math=i"> can be given as 
  
  <img src="https://render.githubusercontent.com/render/math?math=(i-l)-(j-l) = i-j">

**Explanation:**
![expl img](https://i.imgur.com/1A64KMN.png)

##### *(Position of <img src="https://render.githubusercontent.com/render/math?math=i"> in the merged array is <img src="https://render.githubusercontent.com/render/math?math=j">. so the <img src="https://render.githubusercontent.com/render/math?math=j"> in merged array must be <img src="https://render.githubusercontent.com/render/math?math=j">. Sorry for the mistake)*

Note that no of blue elements before <img src="https://render.githubusercontent.com/render/math?math=i"> in the first array will always end up before <img src="https://render.githubusercontent.com/render/math?math=i"> and only some of the red elements end up before <img src="https://render.githubusercontent.com/render/math?math=i"> in the merged sorted array. We have to find the latter.
In reference to the given image,

**no of red elements before <img src="https://render.githubusercontent.com/render/math?math=j"> = total no of elements before <img src="https://render.githubusercontent.com/render/math?math=j"> - blue elements before <img src="https://render.githubusercontent.com/render/math?math=i"> = <img src="https://render.githubusercontent.com/render/math?math=(j-l) - (i-l) = j-l">**

As you can see this merging is the exact merging function in merge sort with an adaptation to our problem. About the Dividing part, We can recursively divide the input array in to two halves in each step until the size becomes 1. As array of size 1 is already sorted, we can start merging. And this is also the exact same thing happening in merge sort. Therefore we can just write a merge sort and add some additional code in the merge function.



pseudo code:
```
Answer = 0
MergeSort(arr[], l,  r)
If r > l
     1. Find the middle point to divide the array into two halves:  
             middle m = (l+r)/2
     2. Call mergeSort for first half:   
             Call mergeSort(arr, l, m)
     3. Call mergeSort for second half:
             Call mergeSort(arr, m+1, r)
     4. Merge the two halves sorted in step 2 and 3:
             Call merge(arr, l, m, r)*
             
merge(arr[],l,m,r)
	1.let L[] = arr[l to m],R[] = arr[m+1 to r], R2[] = arr[m+1 to r]*2
	2.merge L and R2
	3.increment answer by  the calculated value for each element in L
	4.merge L and R and place it on arr 
  ```

## My solution:
```
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


inline void io_setup(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int MAX = 1e6;

ll ans = 0;

struct num{
  int v;
  int lr;
  int p;
};

void merge(num arr[], int l, int m, int r) { 
  int i, j, k; 
  int n1 = m - l + 1; 
  int n2 = r - m; 
  
  num L[n1], R[n2],R2[n2]; 
  
  for (i = 0; i < n1; i++) 
    L[i] = arr[l + i],L[i].lr=-1; 
  for (j = 0; j < n2; j++) 
    R[j] = arr[m + 1 + j],R[j].lr=+1;
  for (j = 0; j < n2; j++) 
    R2[j] = arr[m + 1 + j],R2[j].lr=+1,R2[j].v*=2,R2[j].v++; 

  i = 0; 
  j = 0;
  k = l; 
  
  while (i < n1 && j < n2)
    if (L[i].v < R2[j].v) 
      arr[k++] = L[i++]; 
    else
      arr[k++] = R2[j++]; 

  while (i < n1)
    arr[k++] = L[i++]; 

  while (j < n2)
    arr[k++] = R2[j++];
  
  for(int i=l;i<=r;i++)
    if(arr[i].lr==+1)
      continue;
    else
      ans += i-arr[i].p;
    
  i = 0; 
  j = 0;
  k = l; 
  while (i < n1 && j < n2) 
    if (L[i].v <= R[j].v)
      arr[k++] = L[i++];
    else 
      arr[k++] = R[j++];

  while (i < n1) 
    arr[k++] = L[i++];

  while (j < n2) 
    arr[k++] = R[j++];
  
  for(int i=l;i<=r;i++)
    arr[i].p=i;
} 

void mergeSort(num arr[], int l, int r) { 
  if (l < r) { 
    int m = (l+r)/ 2; 
    mergeSort(arr, l, m); 
    mergeSort(arr, m + 1, r); 
    merge(arr, l, m, r); 
  }
} 

int main(){
  io_setup();
  int n;
  cin >> n;
  struct num arr[n];
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    arr[i] = {a,0,i};
  }
  mergeSort(arr,0,n-1);
  cout << ans << "\n";
  return 0;
}

/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/


```

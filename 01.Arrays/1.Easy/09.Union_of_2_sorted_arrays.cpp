/*
QUESTION:-
Union of two arrays can be defined as the common and distinct elements in the two arrays.
Given two sorted arrays of size n and m respectively, find their union.


Example 1:

Input:
n = 5, arr1[] = {1, 2, 3, 4, 5}
m = 3, arr2 [] = {1, 2, 3}
Output: 1 2 3 4 5
Explanation: Distinct elements including
both the arrays are: 1 2 3 4 5.


Example 2:

Input:
n = 5, arr1[] = {2, 2, 3, 4, 5}
m = 5, arr2[] = {1, 1, 2, 3, 4}
Output: 1 2 3 4 5
Explanation: Distinct elements including
both the arrays are: 1 2 3 4 5.
*/

/*
APPROACH:-
-> Take two pointer i and j where i is for arr1 and j is for arr2 and traverse
-> While travsersing 3 cases arises
    -> arr1[ i ] == arr2[ j ]
        Here we found a common element, so insert only one element in the union.
        Let’s insert arr[i] in union and whenever we insert element we increment pointer while pointer is not equal to the inserted element
    -> arr1[i]<arr2[j]
        Here insert arr[i]
    -> arr1[i]>arr2[j]
        Here insert arr2[j]
-> Now check if elements of any array is left to traverse then traverse that array
*/

// CODE:-
int n=a.size();
    int m=b.size();
    int i=0;
    int j=0;
    vector < int > Union; // Uninon vector
    while (i < n && j < m) {
    if (a[i] <= b[j]) // Case 1 and 2
        {
          if (Union.size() == 0 || Union.back() != a[i])
            Union.push_back(a[i]);
          i++;
        } else // case 3
        {
          if (Union.size() == 0 || Union.back() != b[j])
            Union.push_back(b[j]);
          j++;
        }
    }
      while (i < n) // IF any element left in arr1
        {
            if (Union.back() != a[i])
              Union.push_back(a[i]);
            i++;
          }
          while (j < m) // If any elements left in arr2
          {
            if (Union.back() != b[j])
              Union.push_back(b[j]);
            j++;
          }
  return Union;
}
};
// TIME COMPLEXITY = O(N+M)
// SPACE COMPLEXITY = O(0)




/////////////////BRUTEEEEEEEEEEEEEforceusingset///////////////
class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        int n=a.size();
        int m=b.size();
        set < int > s;
        vector < int > Union;
  
        for(int i=0; i<n;i++){
            s.insert(a[i]);
        }
        for(int i=0; i<m;i++){
            s.insert(b[i]);
        }
        for (auto & it: s)
        Union.push_back(it);
        return Union;
    }
};

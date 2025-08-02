/*
QUESTION:-

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
*/

/*
APPROACH:-
To rotate the array k places to right follow below steps
-> Reverse first n-k elements
-> Reverse last k elements
-> Reverse the entire array

To rotate the array k places to left follow below steps
-> Reverse first k elements
-> Reverse last n-k elements
-> Reverse the entire array
*/

// CODE:-

// RIGHT ROATATE:-
void rightRotate(int arr[], int n, int k)
{
    k = k % n; // to keep k within the range
    reverse(arr, arr + (n - k));
    reverse(arr + (n - k), arr + n);
    reverse(arr, arr + n);
}

// LEFT ROATATE:-
void leftRotate(int arr[], int n, int k)
{
    k = k % n; // to keep k within the range
    reverse(arr, arr + k);
    reverse(arr + k, arr + n);
    reverse(arr, arr + n);
}

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(0)


//////BRUTE APPROACH/////

// left//
    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        if (n == 0) return;
        d = d % n; // In case d > n
        if (d == 0) return;
        vector<int> temp(d);
    
        // Store first d elements
        for (int i = 0; i < d; i++) {
            temp[i] = arr[i];
        }
        // Shift remaining elements to the left
        for (int i = d; i < n; i++) {
            arr[i - d] = arr[i];
        }
        // Put the d elements back at the end
        for (int i = 0; i < d; i++) {
            arr[n - d + i] = temp[i];
        }
    }
};
//RIGHT SWAP///
class Solution {
public:
    // Function to rotate an array by k elements in clockwise (right) direction.
    void rotateArr(vector<int>& arr, int k) {
        int n = arr.size();
        if (n == 0) return;

        k = k % n; // Handle k > n
        if (k == 0) return;

        for (int i = 0; i < k; i++) {
            // Store the last element
            int last = arr[n - 1];

            // Shift all elements one position to the right
            for (int j = n - 1; j > 0; j--) {
                arr[j] = arr[j - 1];
            }

            // Move the last element to the front
            arr[0] = last;
        }
    }
};

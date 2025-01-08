class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // getting the size of array
        int n = arr.size();
        // taking a pivot element 
        int pivot = -1;
        /* iterating through the array from the end to start to find an element
        which is smaller then the rightmost element and taking that index as pivot */
        for(int i =n-2;i>=0;i--){
            if(arr[i]<arr[i+1]){
                pivot = i;
                break;
            }
        }
        // If there is no pivot element than reversing the array and returning it
        if(pivot == -1){
            reverse(arr.begin(),arr.end());
            return;
        }
        // finding the element which is greater than pivot than swapping it with the pivot 
        for(int i =n-1;i>pivot;i--){
            if(arr[i]>arr[pivot]){
                swap(arr[i],arr[pivot]);
                break;
            }
        }
        //Reversing the array from pivot index to end 
        reverse(arr.begin()+pivot+1, arr.end());
    }
};
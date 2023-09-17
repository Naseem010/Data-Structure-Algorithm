class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //      int n1=array1.size();
    //     int n2=array2.size();
    //     vector<int>arr;
    //    int i,j=0;
    //    while(i<n1 && j<n2){
    //        if(array1[i]>array2[j]){
    //            arr.push_back(array2[j]);
    //            j++;
    //    }else if(array1[i]<=array2[j]){
    //        arr.push_back(array1[i]);
    //        i++;
    //    }
    //    }
    //    while(i<n1){
    //        arr.push_back(array1[i]);
    //        i++;
    //    }
    //    while(j<n2){
    //        arr.push_back(array2[j]);
    //        j++;
    //    }
       
    //     int k=arr.size()/2;
    //     if(arr.size()%2!=0){
    //         return double(arr[k]);
    //     }else{
    //         double ans=((arr[k])+(arr[k-1]))/2.0;
    //         return ans;
    //     }
     vector<int>v;
        
        // store the array in the new array
        for(auto num:nums1)   // O(n1)
            v.push_back(num);
        
        for(auto num:nums2)  // O(n2)
            v.push_back(num);
        
        // Sort the array to find the median
        sort(v.begin(),v.end());  // O(nlogn)
        
        // Find the median and Return it
        int n=v.size();  // O(n)
        
        return n%2?v[n/2]:(v[n/2-1]+v[n/2])/2.0;
    }
};
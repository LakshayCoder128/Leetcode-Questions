class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        
//         Brute Force    space => O(N+M)  Time : O((N+M)(log m+n))
        
//         int n1 = nums1.size(), n2 = nums2.size();
//         vector<int> sortedArr;
//         double ans;
//         for (int i = 0; i < n1; i++)
//         {
//             sortedArr.push_back(nums1[i]);
//         }
//         for (int i = 0; i < n2; i++)
//         {
//             sortedArr.push_back(nums2[i]);
//         }
//         sort(sortedArr.begin(), sortedArr.end());

//         if ((n1 + n2) % 2 == 0)
//         {
//             // cout<<"even"<<endl;
//             return float(sortedArr[(n1 + n2 - 1) / 2] + sortedArr[((n1 + n2 - 1) / 2) + 1]) / 2;
//         }
//         else
//         {
//             // cout<<"Odd"<<endl;
//             return float(sortedArr[(n1 + n2) / 2]);
//         }
        
        int i=0,j=0;
        vector<int>a;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] < nums2[j]){
                a.push_back(nums1[i]);
                i++;
            }
            else{
                a.push_back(nums2[j]);
                j++;
            }
        }
        
        for(;i<nums1.size();i++){
            a.push_back(nums1[i]);
        }
        for(;j<nums2.size();j++){
            a.push_back(nums2[j]);
        }
        
        
        if ((nums1.size() + nums2.size()) % 2 == 0)
        {
            
            return float(a[(nums1.size() + nums2.size() - 1) / 2] + a[((nums1.size() + nums2.size() - 1) / 2) + 1]) / 2;
        }
        else
        {
            // cout<<"Odd"<<endl;
            return float(a[(nums1.size() + nums2.size()) / 2]);
        }
    }
};
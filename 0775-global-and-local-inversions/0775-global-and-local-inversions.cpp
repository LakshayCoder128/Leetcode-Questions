class Solution
{
    public:
       	//         int ans = 0;
       	//     vector<int> merge2SortedArrays(vector<int> &l, vector<int> &r)
       	//     {
       	//         int i = 0, j = 0, k = 0;
       	//         int count = 0;
       	//         vector<int> mer(l.size() + r.size());
       	//         while (i < l.size() && j < r.size())
       	//         {
       	//             if (l[i] <= r[j])
       	//             {
       	//                 mer[k++] = l[i++];
       	//             }
       	//             else
       	//             {
       	//                 count += l.size() - i;
       	//                 mer[k++] = r[j++];
       	//             }
       	//         }

       	//         while (i < l.size())
       	//         {
       	//             mer[k++] = l[i++];
       	//         }
       	//         while (j < r.size())
       	//         {
       	//             mer[k++] = r[j++];
       	//         }

       	//         ans += count;
       	//         return mer;
       	//     }
       	//     vector<int> merge_Sort(vector<int> &nums, int lo, int hi)
       	//     {

       	//         if (lo == hi)
       	//         {
       	//             vector<int> a;
       	//             a.push_back(nums[lo]);
       	//             return a;
       	//         }
       	//         int mid = (lo + hi) / 2;
       	//         vector<int> l = merge_Sort(nums, lo, mid);
       	//         vector<int> r = merge_Sort(nums, mid + 1, hi);

       	//         vector<int> merged = merge2SortedArrays(l, r);

       	//         return merged;
       	//     }

       	//     bool isIdealPermutation(vector<int> &nums)
       	//     {
       	//        	// local inversions
       	//         int loc = 0;

       	//         for (int i = 0; i < nums.size() - 1; i++)
       	//             if (nums[i] > nums[i + 1]) loc += 1;
       	//         merge_Sort(nums, 0, nums.size() - 1);

       	//         return ans == loc;
       	//     }

        /*
    All local inversions are global inversions.
If the number of global inversions is equal to the number of local inversions,
it means that all global inversions in permutations are local inversions.
It also means that we can not find A[i] > A[j] with i+2<=j.
In other words, max(A[i])<A[i+2]

In this first solution, I traverse A and keep the current biggest number cmax.
Then I check the condition cmax<A[i+2]
    */
        bool isIdealPermutation(vector<int> &A)
        {
            int cmax = 0, n = A.size();
            for (int i = 0; i < n - 2; ++i)
            {
                cmax = max(cmax, A[i]);
                if (cmax > A[i + 2]) return false;
            }
            return true;
        }
};
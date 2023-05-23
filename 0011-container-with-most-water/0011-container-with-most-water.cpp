class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1;
        int area = 0;
        while(l<r){
            int width = r-l;
            int mh = min(height[l],height[r]);
            area = max(area,width*mh);
            
            if(height[l] < height[r]) l++;
            else if(height[r] < height[l])r--;
            else {l++;r--;}
        }
        return area;
    }
};
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findMountainTop(MountainArray &mountainArr, int left,int right)
    {
        while(left< right)
        {
            int mid = left+(right-left)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1))
            {
                left = mid+1;
            }else{
                right = mid;
            }
        }
        return left;
    }
    int findSortedArr(MountainArray &mountainArr, int left, int right, int target)
    {
        while(left<=right)
        {
            int mid = left+(right - left)/2;
            if(mountainArr.get(mid)==target)
            {
                return mid;
            }else if(mountainArr.get(mid)<target)
            {
                left =mid+1;
            }else{
                right = mid-1;
            }
        }
        return -1;
    }
    int findReserveArr(MountainArray &mountainArr, int left, int right, int target)
    {
        while(left<=right)
        {
            int mid = left+(right - left)/2;
            if(mountainArr.get(mid)==target)
            {
                return mid;
            }else if(mountainArr.get(mid)<target)
            {
                right =mid-1;
            }else{
                left = mid+1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n= mountainArr.length();
        int peak = findMountainTop(mountainArr, 0, n-1);
        if(mountainArr.get(peak)==target)
            return peak;
        int left_res = findSortedArr(mountainArr, 0, peak, target);
        if(left_res!=-1)
        {
            return left_res;
        }
        int right_res = findReserveArr(mountainArr, peak, n-1, target);
        return right_res;
    }
};
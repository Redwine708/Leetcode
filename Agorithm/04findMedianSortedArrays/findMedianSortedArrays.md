# 题目大意
```
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

示例 1：
输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2
示例 2：

输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
示例 3：

输入：nums1 = [0,0], nums2 = [0,0]
输出：0.00000
示例 4：

输入：nums1 = [], nums2 = [1]
输出：1.00000
示例 5：

输入：nums1 = [2], nums2 = []
输出：2.00000
 

提示：

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
 

进阶：你能设计一个时间复杂度为 O(log (m+n)) 的算法解决此问题吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
```
# 解题思路
### 第一种解法
**暴力开第三数组**
把两个数组的元素存进去然后调用排序函数进行排序
再根据数组元素是奇数还是偶数来输出中位数
```
时间复杂度T(n*logn) 调用排序算法复杂度
空间复杂度O(n) 开了一个数组
```

**稍微优化一下**
```
可以在排序中优化一下
因为是给的升序序列，课以依次进行比较然后将较小的数填入新开的序列中
```
```
时间复杂度T(n)
空间复杂度O(1)
```
###第二种解法
**运用数学找到规律,减少肯定不是中位数的数的比较**
```

```
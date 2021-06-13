#The description of the question
```txt
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），
```
#Solution
**f(i) = max {f(i-1) + nums[i],nums[i] }**
We record the maximum of the sub array by
**maxSub = max(maxSub,f(i))**
T(n) = n;
O(n) = n;

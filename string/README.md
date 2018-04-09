## 字符串匹配相关算法

### 朴素字符串匹配


* 朴素字符串匹配算法又称为**暴力匹配算法(Brute Force Algorithm)**,主要特点如下：

1. 没有预处理阶段；

2. 滑动窗口总是后移一位；

3. 对模式中的字符串比较顺序不限定，可以从前到后，也可以从后到前；

4. 匹配阶段需要O((n-m+1)m)的时间复杂度(其中n为文本T的长度，m为模式P的长度)

5. 需要2n次的字符串比较







**For example**

T = "acaabc"; P = "aab",则朴素匹配算法过程如下图

![](https://github.com/Hanseltu/learn-algorithms/blob/master/string/native_match.png)



### Rabin-Karp算法
-------


### 有限自动机算法
-----------




###  Knuth-Morris-Pratt(KMP算法)
-----------
**Knuth-Morris-Pratt**字符串查找算法，简称"KMP"算法。

介绍算法之前，先了解一个概念————最长前缀后缀

如果给定的模式串是:"ABCDABD"，从左至右遍历整个模式串，其各个子串的前缀后缀分别如下表格:



![](https://github.com/Hanseltu/learn-algorithms/blob/master/string/prefix.jpg)



通过找到各个子串的最大公共元素长度，可以得到**next数组表**，此next数组表是KMP的精髓，它可以

`失配时，模式串向右移动的位数为:已匹配字符数-失配字符串的上一位字符所对应的最大长度值`

真的神奇，这样就不用像暴力匹配那样重复比较一样的了，不知道这三位大佬是怎么想出来的。。。



![](https://github.com/Hanseltu/learn-algorithms/blob/master/string/next.jpg)




算法的主要步骤如下：

1. 寻找前缀后缀最长公共元素长度

2. 求next数组

3. 根据next数组进行匹配




#### 具体细节参考[从头到尾彻底理解KMP](https://blog.csdn.net/v_july_v/article/details/7041827)



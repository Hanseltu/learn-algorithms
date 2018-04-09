## 字符串匹配相关算法---(取自《算法导论》)

### 朴素字符串匹配


* 朴素字符串匹配算法又称为**暴力匹配算法(Brute Force Algorithm)**,主要特点如下：

1. 没有预处理阶段；

2. 滑动窗口总是后移一位；

3. 对模式中的字符串比较顺序不限定，可以从前到后，也可以从后到前；

4. 匹配阶段需要O((n-m+1)m)的时间复杂度(其中n为文本T的长度，m为模式P的长度)

5. 需要2n次的字符串比较

For example

T = "acaabc"; P = "aab",则朴素匹配算法过程如下图

![](https://github.com/Hanseltu/learn-algorithms/blob/master/string/native_match.png)



### Rabin-Karp算法

### 有限自动机算法

###  Knuth-Morris-Pratt(KMP算法)



# C++Learn
## 本项目用于[洛谷](https://www.luogu.com.cn/)、[力扣](https://leetcode.cn/)、[CodeForces](https://codeforces.com/)等OJ刷题学习
### 十年oi一场空，不开`long long` 见祖宗
-  注意两个int相乘也可能会爆int，记得乘上`1ll`
- `cin.peek`用于读取下一个输出字符，但是不清除该读入字符。
- `setw`用于控制输出字符宽度，不足的部分用`setfill`函数传入字符补齐。
- `queue`用于定义一个队列，语法结构为`queue <Data Type> name`,`name.pop()`用于出队，`name.front()`用于查看第一个元素.
- `priority_queue<ll, vector<ll>, greater<ll> >`用于定义一个小根堆，top的元素为队列中最小值，也可将负值插入大根堆实现小根堆效果。
### 累了就看看可爱的折纸吧

<img src=".\image\Origami_1.webp" alt="折纸喵~" style="zoom:35%;" /> 

## 部分说明文档
### Test.cpp对拍程序
对拍程序所在目录下至少应存在以下文件:
- Testlib.out
- Code.out

或目录:

- inAndoutFile

其中Testlib.out文件内是正确的数据或以`inAndoutFile\*.*`
起始的一行放置正确文件的相对路径。
而Code.out是程序输出的文件，程序将其与正确的文件逐行匹配，会输出以下几种内容 :

|  类型  |       输出        |
|:----:|:---------------:|
|  AC  |   宝宝好棒，程序输出正确   |
|  WA  |   在t行与正确答案不符    |
| 输出过长 | 程序输出过长，再重新检查一下吧 |
| 输出过短 | 程序输出过短，再重新检查一下吧 |

### GetCodeLine.cpp获取代码行数程序
与需要统计代码行数的文件、文件夹放到同一目录内编译运行程序  
运行后将会输出同一目录下所有不以'.'起始或以".exe"结尾的文件、文件夹，输入其编号即可统计此文件、文件夹中所有文件的有效行数。
注：若误将其他非文本文件的内容纳入统计范围，则会导致输出数据错误。
### 关于GitHub推送失败
在控制台中输入
```
git config --global http.https://github.com.proxy socks5://127.0.0.1:7890
```
注：此port为自己的代理服务器端口

## 联系方式
|  Github   |  *[nhirsama](https://github.com/nhirsama)*   |
| :-------: | :------------------------------------------: |
| **Gitee** | ***[nhirsama](https://gitee.com/nhirsama)*** |
| **Email** |        ***[nhirsama@outlook.com]()***        |

## 所用环境
CLion: [2025.1](https://www.jetbrains.com.cn/clion/whatsnew/)  
C++语言标准: [C23](https://zh.cppreference.com/w/c/23)  
Python解释器: [Python 3.12](https://www.python.org/downloads/release/python-3120/)  

## Git 神！

## 2024年度总结
从十月份接触算法起至2024年12月26日，在"problem"文件夹中编写的代码行数一共为10461行。  
在洛谷OJ中提交368次，Accepted 154题。
其余还零零散散地在其他OJ中通过若干道题。

## 奖项
[2025年郑州邀请赛](https://codeforces.com/gym/105941/standings) 银奖

-------------------------------------

Copyright © 2024-2025 nhirsama. All rights reserved. 


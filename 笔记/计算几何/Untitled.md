![image-20220216140402711](C:\Users\Ruoom\AppData\Roaming\Typora\typora-user-images\image-20220216140402711.png)



sin(x) = $\frac{a}{c}$ 对边:斜边

cos(x) = $\frac{b}{c}$ 邻边:斜边

tan(x) = $\frac{a}{b}$ 对边:邻边



asin



$\pi = acos(-1)$ 

$\pi = acos (-1)$ 

弧度转角度 $角度 = 弧度*180/\pi$

角度转弧度 $弧度 = 角度 * \pi / 180$

### 点

- 坐标$x,y$ 
- 位移: $\begin{cases}x= x+a \\ y= y+b\end{cases}$
- 旋转: $\begin{cases}x = x * cos(k) - y * sin(k) \\y = x * sin(k) + y * cos(k) \end{cases}$

- 相加相减
- 计算角度
- 排序, x优先, y优先, 角度优先.
- 两点间距(欧几里得距离, 曼哈顿距离) 

### 向量

有大小有方向的量

- 怎么求
	- 平面有两点: $A(1,0), B(3,3)$
	- 向量$\overrightarrow{A B} = B-A = (2,3)$    向量$\overrightarrow{B A} = A-B = (-2,-3)$
- 向量的模: 即向量的长度.  写作 $|\overrightarrow{A B}|$
- 向量的**内积**(**点积**) $\mathbf{A} \cdot \mathbf{B}$
	- $\mathbf{A} \cdot \mathbf{B}$值为$x_1 * x_2 + y_1*y_2$ 
	- 几何意义: $\mathbf{A} \cdot \mathbf{B} = |\mathbf{A}|*|\mathbf{B}|*cos\theta $
- 向量的**外积**(**叉积**) $\mathbf{A} \times \mathbf{B}$ 
	-  $|\mathbf{A} \times \mathbf{B}|$值为$x_1*y_2 - x_2*y_1$ 
	- 几何意义$\mathbf{A} \times \mathbf{B} = |\mathbf{A}|*|\mathbf{B}|*sin\theta $

- 点在哪一侧

### 直线

- 表示: 过直线的一个点和一个表示直线方向的向量(点斜式)
	- 点是否在直线上
	- 点在直线上的投影
	- 点与直线的距离

### 圆

- 表示: 圆心, 半径
- 面积: $S = \pi r^2$ 
- 扇形面积: $S' = \frac{\theta}{360}S$
- 点与圆的位置关系:  $\begin{cases}d<r &圆内  \\d=r &圆上\\ d>r&圆外 \end{cases}$ 
- 圆与圆的位置关系: $\begin{cases} d > r_1+r_2 &相离 \\d <= |r_1-r_2| &包含 \\ 否则 &相交\end{cases}$



### 多边形

- 表示: 记录多边形的顶点数n, 并按顺序依次记录每个顶点的坐标.























https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A 找投影点

https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B 找对称点

https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C 两向量的位置关系



~~[Problem - 1047B - Codeforces](https://codeforces.com/problemset/problem/1047/B) 简单的水题 难度橙色~~

~~[Problem - 1030B - Codeforces](https://codeforces.com/problemset/problem/1030/B) 点是否在矩形内 难度黄色~~



[P1652 圆 - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P1652) 曲线绕圆 难度入门

[P1142 轰炸 - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P1142) 覆盖最多点的直线 难度黄色



[Problem - A - Codeforces](https://codeforces.com/contest/140/problem/A) 大圆套小圆 难度黄色

[Problem - B - Codeforces](https://codeforces.com/contest/190/problem/B) 圆与圆的位置关系 难度1800(真的不难)

[Problem - D - Codeforces](https://codeforces.com/contest/600/problem/D) 两圆相交面积 难度蓝色(余弦定理)


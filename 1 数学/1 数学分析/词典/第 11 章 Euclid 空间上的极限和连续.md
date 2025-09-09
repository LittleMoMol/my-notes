# 11 Euclid 空间上的极限和连续
## 11-1 Euclid 空间上的基本定理
### 11-1-1 Euclid 空间上的距离
- **Descartes 乘积集 $\mathbb R^n$**：定义 $n$ 个 $\mathbb R$ 的 **Descartes 乘积集**为 $\mathbb R^n = \mathbb R \times \mathbb R \times \cdots \times \mathbb R = \{(x_1,x_2,\cdots,x_n) \mid x_i\in \mathbb R,\ i=1,2,\cdots,n\}$ 
- **向量**（**点**）、**坐标**：$\mathbb R^n$ 中的元素 $\boldsymbol x = (x_1, x_2, \cdots,  x_n)$ 称为**向量**（或**点**），$x_i$ 称为 $\boldsymbol x$ 的**第 $i$ 个坐标** 
- **零元素 $\boldsymbol 0$**：$\mathbb R^n$ 中的零元素记为 $\boldsymbol 0 = (0,0,\cdots,0)$ 
- **向量空间**：设 $\boldsymbol x = (x_1, x_2, \cdots, x_n),\ \boldsymbol y = (y_1, y_2, \cdots, y_n)$ 为 $\mathbb R^n$ 中任意两个向量，$\lambda$ 为任意实数，定义 $\mathbb R^n$ 中的加法和数乘运算：$\boldsymbol x + \boldsymbol y = (x_1+y_1, x_2+y_2, \cdots, x_n+y_n)$ 和 $\lambda\boldsymbol x = (\lambda x_1, \lambda x_2, \cdots, \lambda x_n)$，那么 $\mathbb R^n$ 就成为**向量空间**
- **内积运算**、**Euclid 空间**：若在向量空间 $\mathbb R^n$ 上引入**内积**运算 $\langle \boldsymbol x, \boldsymbol y \rangle = x_1y_1 + x_2y_2 + \cdots + x_ny_n = \sum\limits_{k=1}^n x_ky_k$，那么它就被称为 **Euclid 空间** 
- **内积运算满足的性质** 
	- **正定性**：$\langle \boldsymbol x, \boldsymbol x \rangle \ge 0$，而 $\langle \boldsymbol x, \boldsymbol x \rangle=0$ 当且仅当 $\boldsymbol x = \boldsymbol 0$ 
	- **对称性**：$\langle \boldsymbol x, \boldsymbol y \rangle = \langle \boldsymbol x, \boldsymbol y \rangle$ 
	- **线性性**：$\langle \lambda \boldsymbol x + \mu \boldsymbol y, \boldsymbol z \rangle = \lambda \langle \boldsymbol x, \boldsymbol z \rangle + \mu \langle \boldsymbol y, \boldsymbol z \rangle$ 
	- **Schwarz 不等式**：$\langle \boldsymbol x, \boldsymbol y \rangle^2 \le \langle \boldsymbol x, \boldsymbol x \rangle \langle \boldsymbol y, \boldsymbol y \rangle$ 
		- *证明过程* 
			有正定性、对称性、线性性可知：对于任意 $\lambda \in \mathbb R$ 都有 $\langle \lambda \boldsymbol x + \boldsymbol y, \lambda \boldsymbol x + \boldsymbol y \rangle = \lambda^2 \langle \boldsymbol x, \boldsymbol x \rangle + 2\lambda \langle \boldsymbol x, \boldsymbol y \rangle + \langle \boldsymbol y, \boldsymbol y\rangle \ge 0$ 
			所以其判别式不大于零，即 $4\langle \boldsymbol x, \boldsymbol y \rangle^2 - 4\langle \boldsymbol x, \boldsymbol x \rangle \langle \boldsymbol y, \boldsymbol y \rangle \le 0$ 
			这就得到了 Schwarz 不等式 $\langle \boldsymbol x, \boldsymbol y \rangle^2 \le \langle \boldsymbol x, \boldsymbol x \rangle \langle \boldsymbol y, \boldsymbol y \rangle$ 
- **距离 $|\boldsymbol x - \boldsymbol y|$**：Euclid 空间 $\mathbb R^n$ 中任意两点 $\boldsymbol x = (x_1, x_2, \cdots, x_n)$ 和 $\boldsymbol y = (y_1, y_2, \cdots, y_n)$ 的**距离**定义为 $|\boldsymbol x - \boldsymbol y| = \sqrt{(x_1-y_1)^2 + (x_2-y_2)^2 + \cdots + (x_n-y_n)^2}$ 
- **Euclid 范数 $\|\boldsymbol x\|$**：称 $\|\boldsymbol x\| = \sqrt{\langle \boldsymbol x, \boldsymbol x \rangle} = \sqrt{\sum\limits_{k=1}^n x_k^2}$ 为 $\boldsymbol x$ 的 **Euclid 范数**，简称**范数** 
	- $\boldsymbol x$ 的范数 $\|\boldsymbol x\|$ 就是 $\boldsymbol x$ 到 $\boldsymbol 0$ 的距离（即 $\boldsymbol x$ 的模长）
- **距离满足的性质** 
	- **正定性**：$|\boldsymbol x - \boldsymbol y| \ge 0$，而 $|\boldsymbol x - \boldsymbol y| = 0$ 当且仅当 $\boldsymbol x = \boldsymbol y$ 
	- **对称性**：$|\boldsymbol x - \boldsymbol y| = |\boldsymbol y - \boldsymbol x|$ 
	- **三角不等式**：$|\boldsymbol x - \boldsymbol z| \le |\boldsymbol x - \boldsymbol y| + |\boldsymbol y - \boldsymbol z|$ 
### 11-1-2 Euclid 空间上的极限
- **邻域 $O(\boldsymbol a, \delta)$**、**中心**、**半径**：设 $\boldsymbol a = (a_1, a_2, \cdots, a_n) \in \mathbb R^n,\ \delta>0$，则点集 $\begin{aligned}O(\boldsymbol a, \delta) =& \{\boldsymbol x\in \mathbb R^n \mid |\boldsymbol x-\boldsymbol a| < \delta\}  \\ =& \left\{ \boldsymbol x\in \mathbb R^n \left| \sqrt{(x_1-a_1)^2 + (x_2-a_2)^2 + \cdots + (x_n-a_n)^2} < \delta\right. \right\}\end{aligned}$ 称为点 $\boldsymbol a$ 的 $\delta$ 邻域，$\boldsymbol a$ 称为这个邻域的**中心**，$\delta$ 称为邻域的**半径** 
	- $O(\boldsymbol a, \delta)$ 在 $\mathbb R$ 上是开区间，在 $\mathbb R^2$ 上是开圆盘，在 $\mathbb R^3$ 上是开球
- **收敛**、**极限**、**发散**：设 $\{\boldsymbol x_k\}$ 是 $\mathbb R^2$ 中的一个点列，若存在定点 $\boldsymbol a \in \mathbb R^n$，对于任意给定的 $\varepsilon>0$，存在正整数 $K$，使得当 $k>K$ 时，$|\boldsymbol x_k-\boldsymbol a| < \varepsilon$（即 $x_k \in O(\boldsymbol a, \varepsilon)$），则称点列 $\{\boldsymbol x_k\}$ **收敛**于 $\boldsymbol a$，记为 $\lim\limits_{k\to\infty} \boldsymbol x_k = \boldsymbol a$，并称 $\boldsymbol a$ 为点列 $\{\boldsymbol x_k\}$ 的**极限**。一个点列不收敛就称其**发散** 
- **定理**：$\lim\limits_{k\to\infty} \boldsymbol x_k = \boldsymbol a$ $\iff$ $\lim\limits_{k\to\infty} x_i^k = a_i\ (i=1,2,\cdots,n)$，其中 $\boldsymbol x_k = (x_1^k, x_2^k, \cdots, x_n^k)\ (k=1,2,\cdots)$，$\boldsymbol a = (a_1, a_2, \cdots, a_n)$ 
	- *证明过程* 
		利用不等式 $|x_j^k - a_j| \le |\boldsymbol x_k - \boldsymbol a| = \sqrt{\sum\limits_{i=1}^n (x_i^k - a_i)^2} \le \sum\limits_{i=1}^n |x_i^k - a_i|\ (j=1,2,\cdots,n)$ 
		**前推后**：由于 $\forall\ \varepsilon>0,\ \exists\ K,\ \forall\ k>K:|\boldsymbol x_k - \boldsymbol a| < \varepsilon$，即 $\sqrt{\sum\limits_{i=1}^n (x_i^k - a_i)^2} < \varepsilon$，故 $|x_j^k - a_j| < \varepsilon\ (j=1,2,\cdots,n)$，故 $\lim\limits_{k\to\infty} x_i^k = \boldsymbol a_i\ (i=1,2,\cdots,n)$ 
		**后推前**：由于 $\forall\ \varepsilon>0,\ \exists\ K,\ \forall\ k>K: |x_i^k - a_i| < \varepsilon\ (i=1,2,\cdots,n)$，故 $\sum\limits_{i=1}^n |x_i^k - a_i| < n\varepsilon$，故 $|\boldsymbol x_k - \boldsymbol a| < n\varepsilon$，故 $\lim\limits_{k\to\infty} \boldsymbol x_k = \boldsymbol a$ 
		证毕！
- **有界集 $S$**：设 $S$ 是 $\mathbb R^n$ 的点集，若存在正数 $M$，使得对于任意 $\boldsymbol x\in S$ 有 $\| \boldsymbol x\| \le M$（即存在正数 $M$，使得 $S \subset O(\boldsymbol 0, M)$）则称 $S$ 为**有界集** 
- **收敛点列的性质** 
	- **唯一性**：收敛点列 $\{\boldsymbol x_k\}$ 的极限是唯一的
	- **有界性**：收敛点列 $\{\boldsymbol x_k\}$ 必定有界
	- **极限的运算法则**仍然在高维成立
### 11-1-3 内点、外点、边界点、孤立点、聚点
- 设 $S$ 是 $\mathbb R^n$ 上的点集，它在 $\mathbb R^n$ 上的补集 $\mathbb R^n \backslash S$ 记为 $S^c$。对于任意 $\boldsymbol x \in \mathbb R^n$，从其邻域与 $S$ 的关系来分，只可能是下列三种情况之一
	- **内点**、**内部**：存在 $\boldsymbol x$ 的一个 $\delta$ 邻域 $O(\boldsymbol x, \delta)$ 完全落在 $S$ 中（此时 $\boldsymbol x$ 必属于 $S$），这时称 $\boldsymbol x$ 是 $S$ 的**内点**。$S$ 的内点全体称为 $S$ 的**内部**，记为 $S^o$ 
	- **外点**：存在 $\boldsymbol x$ 的一个 $\delta$ 邻域 $O(\boldsymbol x, \delta)$ 完全不落在 $S$ 中，这时称 $\boldsymbol x$ 是 $S$ 的**外点** 
	- **边界点**、**边界**：不存在 $\boldsymbol x$ 的具有上述性质的 $\delta$ 邻域，即 $\boldsymbol x$ 的任意 $\delta$ 邻域既包含 $S$ 中的点，又包含不属于 $S$ 的点，那么就称 $\boldsymbol x$ 是 $S$ 的**边界点**。$S$ 的边界点的全体称为 $S$ 的**边界**，记为 $\partial S$ 
		- **注意**：内点必属于 $S$，外点必不属于 $S$（即必属于 $S^c$），但边界点可能属于 $S$，可能不属于 $S$ 
- **孤立点**：若存在 $\boldsymbol x$ 的一个邻域，其中只有 $\boldsymbol x$ 点属于 $S$，则称 $\boldsymbol x$ 是 $S$ 的**孤立点** 
	- 孤立点必是边界点
- **聚点**：若 $\boldsymbol x$ 的任意邻域都含有 $S$ 中的无限个点，则称 $\boldsymbol x$ 是 $S$ 的**聚点**。$S$ 的聚点的全体记为 $S'$ 
	- $S$ 的内点必是 $S$ 的聚点
	- $S$ 的边界点，只要不是 $S$ 的孤立点，也必是 $S$ 的聚点
	- $S$ 的聚点可能属于 $S$，可能不属于 $S$ 
		- **例子**：在 $\mathbb R$ 中，$0$ 是点集 $\left\{ \left. \dfrac 1n \right| n=1,2,\cdots \right\}$ 的聚点，但它不属于这个点集
- **定理**：$\boldsymbol x$ 是点集 $S(\subset \mathbb R^n)$ 的聚点 $\iff$ 存在点列 $\{\boldsymbol x_k\}$ 满足 $\boldsymbol x_k \in S,\ \boldsymbol x_k\not=\boldsymbol x\ (k=1,2,\cdots)$，使得 $\lim\limits_{k\to\infty} \boldsymbol x_k = \boldsymbol x$ 
### 11-1-4 开集、闭集
- **开集**、**闭集**、**闭包**：设 $S$ 是 $\mathbb R^n$ 上的点集，若 $S$ 中的每一个点都是它的内点，则称 $S$ 为**开集**；若 $S$ 中包含了它的所有的聚点，则称 $S$ 为**闭集**。$S$ 与它的聚点全体 $S'$ 的并集称为 $S$ 的闭包，记为 $\overline S$ 
- **$n$ 维开矩形**：容易证明集合 $\{\boldsymbol x \in \mathbb R^n \mid a_i < x_i < b_i,\ i=1,2,\cdots,n\}$ 是开集，称之为 **$n$ 维开矩形** 
- **$n$ 维开球**：容易证明集合 $\left\{\boldsymbol x \in \mathbb R^n \left| \sum\limits_{i=1}^n (x_i-a_i)^2<r^2\right.\right\}$ 是开集，称之为 **$n$ 维开球** 
- **$n$ 维闭矩形**：容易证明集合 $\{\boldsymbol x \in \mathbb R^n \mid a_i \le x_i \le b_i,\ i=1,2,\cdots,n\}$ 是闭集，称之为 **$n$ 维闭矩形** 
- **$n$ 维闭球**：容易证明集合 $\left\{\boldsymbol x \in \mathbb R^n \left| \sum\limits_{i=1}^n (x_i-a_i)^2\le r^2\right.\right\}$ 是闭集，称之为 **$n$ 维闭球** 
- **定理**：$\mathbb R^n$ 上的点集 $S$ 为闭集 $\iff$ $S^c$ 是开集
	- *证明过程* 
		**必要性** 
		若 $S$ 为闭集，由于 $S$ 的一切聚点都属于 $S$，因此，对于任意 $\boldsymbol x \in S^c$，$\boldsymbol x$ 不是 $S$ 的聚点。
		也就是说，存在 $\boldsymbol x$ 的邻域 $O(\boldsymbol x, \delta)$，使得 $O(\boldsymbol x, \delta) \cap S = \varnothing$，即 $O(\boldsymbol x, \delta) \subset S^c$，因此 $S^c$ 是开集
		**充分性** 
		对任意 $\boldsymbol x\in S^c$，由于 $S^c$ 是开集，因此存在 $\boldsymbol x$ 的邻域 $O(\boldsymbol x, \delta)$，使得 $O(\boldsymbol x, \delta) \in S^c$，即 $\boldsymbol x$ 不是 $S$ 的聚点
		所以如果 $S$ 有聚点，它就一定属于 $S$，因此 $S$ 为闭集。
- **定理**：$\mathbb R^n$ 上的点集 $S$ 为开集 $\iff$ $S^c$ 是闭集
- **De Morgan 公式**：设 $\{S_\alpha\}$ 是 $\mathbb R^n$ 中的一组（有限或无限多个）子集，则：
	1. $\left(\bigcup\limits_\alpha S_\alpha\right)^c = \bigcap\limits_\alpha S_\alpha^c$ 
	2. $\left( \bigcap\limits_\alpha S_\alpha \right)^c = \bigcup\limits_\alpha S_\alpha^c$ 
- **性质 1**：任意一组开集 $\{S_\alpha\}$ 的并集 $\bigcup\limits_\alpha S_\alpha$ 是开集
	- *证明过程* 
		设 $\boldsymbol x \in \bigcup\limits_\alpha S_\alpha$，那么存在某个 $\alpha$，使得 $\boldsymbol x \in S_\alpha$ 
		而 $S_\alpha$ 是开集，因此 $\boldsymbol x$ 就是 $S_\alpha$ 的内点，所以也是 $\bigcup\limits_\alpha S_\alpha$ 的内点，这说明 $\bigcup\limits_\alpha S_\alpha$ 是开集
- **性质 2**：任意一组闭集 $\{T_\alpha\}$ 的交集 $\bigcap\limits_\alpha T_\alpha$ 是闭集
	- *证明过程* 
		由 De Morgan 公式可得 $\left( \bigcap\limits_\alpha T_\alpha \right)^c = \bigcup\limits_\alpha T_\alpha^c$ 
		$T_\alpha$ 是闭集，从而 $T_\alpha^c$ 是开集
		由性质 1 可知 $\bigcup\limits_\alpha T_\alpha^c$ 是开集，这说明了 $\bigcap\limits_\alpha T_\alpha$ 的补集是开集，因此它是闭集
- **性质 3**：任意有限个开集 $S_1, S_2, \cdots, S_k$ 的交集 $\bigcap\limits_{i=1}^k S_i$ 是开集
	- *证明过程* 
		设 $\boldsymbol x \in \bigcap\limits_{i=1}^k S_i$，则对每个 $i=1,2,\cdots,k$ 都有 $\boldsymbol x \in S_i$ 
		由于 $S_i$ 是开集，因此存在 $\boldsymbol x$ 的邻域 $O(\boldsymbol x, r_i)$，使得 $O(\boldsymbol x, r_i) \subset S_i$ 
		取 $r=\min\limits_{1\le i\le k}(r_i)$，那么 $O(\boldsymbol x, r) \subset \bigcap\limits_{i=1}^k S_i$，即 $\boldsymbol x$ 是 $\bigcap\limits_{i=1}^k S_i$ 的内点，因此 $\bigcap\limits_{i=1}^k S_i$ 是开集
- **性质 4**：任意有限个闭集 $T_1, T_2, \cdots, T_k$ 的并集 $\bigcup\limits_{i=1}^k T_i$ 是闭集
	- *证明过程* 
		利用 De Morgan 公式和性质 3 就可以证明
### 11-1-5 Euclid 空间上的基本定理
- **直径 $\mathrm{diam}\ S$**：设 $S$ 是 $\mathbb R^n$ 上的点集，则 $\mathrm{diam}\ S = \sup \{|\boldsymbol x - \boldsymbol y| \mid \boldsymbol x, \boldsymbol y \in S\}$ 称为 $S$ 的**直径** 
- **闭矩形套定理**：设 $\Delta_k = [a_k, b_k] \times [c_k, d_k]\ (k=1,2,\cdots)$ 是 $\mathbb R^2$ 上一列闭矩形，如果 $\Delta_{k+1} \subset \Delta_k$（即 $a_k \le a_{k+1} < b_{k+1} \le b_k,\ c_k \le c_{k+1} < d_{k+1} \le d_k\ (k=1,2,\cdots)$）且 $\sqrt{(b_k-a_k)^2 + (d_k - c_k)^2} \to 0\ (k\to\infty)$，则存在唯一的点 $\boldsymbol a = (\xi, \eta)$ 属于 $\bigcap\limits_{k=1}^\infty \Delta_k$，且 $\lim\limits_{k\to\infty} a_k = \lim\limits_{k\to\infty} b_k = \xi,\ \lim\limits_{k\to\infty} c_k = \lim\limits_{k\to\infty} d_k = \eta$ 
	- *证明过程* 
		分别对 $\{[a_k,b_k]\}$ 和 $\{[c_k, d_k]\}$ 运用直线上的**闭区间套定理**即可证明
	- 闭集和依次包含关系是必要的，但集合 $\Delta_k$ 是否是闭矩形并不必要
- **Cantor 闭区间套定理**：设 $\{S_k\}$ 是 $\mathbb R^n$ 上的非空闭集序列，满足 $S_1 \supset S_2 \supset \cdots \supset S_k \supset S_{k+1} \supset \cdots$ 以及 $\lim\limits_{k\to\infty} \mathrm{diam}\ S_k = 0$，则存在唯一点属于 $\bigcap\limits_{k=1}^\infty S_k$ 
	- 该定理是**闭矩形套定理**的更一般的形式
- **Bolzano-Weierstrass 定理**：$\mathbb R^n$ 上的有界点列 $\{\boldsymbol x_k\}$ 中必有收敛子列
	- *证明过程* 
		以二维的情况举例
		先对 $\{\boldsymbol x_k\} = \{(x_k, y_k)\}$ 的第一个分量 $\{x_k\}$ 用一维的 **Bolzano-Weierstrass 定理**，找到其收敛子列 $\{x_{n_k}\}$ 
		在对数列 $\{y_{n_k}\}$ 用一维的 **Bolzano-Weierstrass 定理**，找到其收敛子列 $\{y_{n_{k_m}}\}$，则 $\{(x_{n_{k_m}}, y_{n_{k_m}})\}$ 就是 $\{\boldsymbol x_k\}$ 的收敛子列
	- **推论**：$\mathbb R^n$ 上的有界无限点集至少有一个聚点
- **基本点列**（**Cauchy 点列**）：若 $\mathbb R^n$ 上的点列 $\{\boldsymbol x_k\}$ 满足：对于任意给定的 $\varepsilon>0$，存在正整数 $K$，使得对任意 $k,l>K$ 成立 $|\boldsymbol x_l - \boldsymbol x_k| < \varepsilon$，则称 $\{\boldsymbol x_k\}$ 为**基本点列**（或 **Cauchy 点列**）
- **Cauchy 收敛原理**：$\mathbb R^n$ 上的点列 $\{\boldsymbol x_k\}$ 收敛 $\iff$ $\{\boldsymbol x_k\}$ 为基本点列
	- *证明过程*
		**前推后** 
		设 $\{\boldsymbol x_k\}$ 收敛于 $\boldsymbol a$，则 $\forall\ \varepsilon>0,\ \exists\ K \in \mathbb N^+,\ \forall\ k>K$ 有 $|\boldsymbol x_k - \boldsymbol a| < \dfrac \varepsilon 2$ 
		因此当 $k,l>K$ 时，由三角不等式可知 $|\boldsymbol x_l - \boldsymbol x_k| \le |\boldsymbol x_l - \boldsymbol a| + |\boldsymbol x_k - \boldsymbol a| < \varepsilon$ 
		即 $\{\boldsymbol x_k\}$ 为基本点列
		**后推前** 
		若 $\{\boldsymbol x_k\}$ 为基本点列，记 $\boldsymbol x_k = (x_1^k, x_2^k, \cdots, x_n^k)\ (k=1,2,\cdots)$ 
		则由不等式 $|x_i^l - x_i^k| \le |\boldsymbol x_l - \boldsymbol x_k|\ (i=1,2,\cdots,n)$ 可知对每一个固定的 $i=1,2,\cdots,n$，数列 $\{x_i^k\}$ 是基本数列，因此收敛
		再由定理 $\lim\limits_{k\to\infty} \boldsymbol x_k = \boldsymbol a$ $\iff$ $\lim\limits_{k\to\infty} x_i^k = a_i\ (i=1,2,\cdots,n)$ 可知点列 $\{\boldsymbol x_k\}$ 收敛
- **总结**：数列中从实数的连续性到实数的完备性的 5 个等价定理中，除了**确界存在定理**和**单调有界数列收敛定理**由于涉及点之间的大小关系而在高维空间中不再有意义之外，其余的结论在高维空间中仍然成立
- **开覆盖 $\{U_\alpha\}$**：设 $S$ 为 $\mathbb R^n$ 上的点集，如果 $\mathbb R^n$ 中的一组开集 $\{ U_\alpha\}$ 满足 $\bigcup\limits_{\alpha} U_\alpha \supset S$，那么称 $\{U_\alpha\}$ 为 $S$ 的一个**开覆盖** 
- **紧集**：如果 $S$ 的任意一个开覆盖 $\{U_\alpha\}$ 中总存在一个有限子覆盖，即存在 $\{U_\alpha\}$ 中的有限个开集 $\{U_{\alpha_i}\}_{i=1}^p$ 满足 $\bigcup\limits_{i=1}^p \supset S$，则称 $S$ 为**紧集** 
- **Heine-Borel 定理**：$\mathbb R^n$ 上的点集 $S$ 是紧集 $\iff$ 它是有界闭集
	- *证明过程* 
		只证明 $n=2$ 的情形
		**必要性** 
		设 $S$ 为紧集，*第一步，我们先证明它是有界的* 
		由于 $\{O(\boldsymbol x, 1) \subset \mathbb R^2 \mid \boldsymbol x \in S\}$ 是 $S$ 的一个开覆盖，因为 $S$ 是紧集，因此存在 $S$ 的有限子覆盖，即存在 $\boldsymbol x_1, \boldsymbol x_2, \cdots, \boldsymbol x_p$ 使得 $S \subset \bigcup\limits_{i=1}^p O(\boldsymbol x_i, 1)$ 
		这就说明了 $S$ 是有界集
		*第二步，反证法证明 $S$ 是闭集* 
		设存在 $S$ 的聚点 $\boldsymbol a \not\in S$，构造开集 $U_n = \left\{ \boldsymbol x \left| |\boldsymbol x - \boldsymbol a| > \dfrac 1n \right. \right\}$ 
		则 $\bigcup\limits_{n=1}^\infty U_n = \mathbb R^2 \backslash \{\boldsymbol a\} \supset S$，即 $\{U_n\}$ 是 $S$ 的一个开覆盖
		由聚点定义，存在由无穷多个点组成的点列 $\{\boldsymbol x_k\}\ (\boldsymbol x_k \in S,\ \boldsymbol x_k \not= \boldsymbol a)$ 满足 $\lim\limits_{k\to\infty} \boldsymbol x_k = \boldsymbol a$ 
		由于对任意一个固定的 $m$，$U_m$ 中至多含有 $\{\boldsymbol x_k\}$ 中有限个点（***自己推导***），因此在 $\{\boldsymbol U_n\}$ 中不存在 $S$ 的有限子覆盖，这与 $S$ 是紧集矛盾
		故 $S$ 是闭集
		**充分性** 
		反证法，假设 $S$ 是有界闭集，但不是紧的。那么存在 $S$ 的一个开覆盖 $\{U_\alpha\}$，它不包含 $S$ 的有限子覆盖
		由于 $S$ 为有界点集，那么它必包含在某个 $2$ 维闭正方形 $I_1$ 中
		将 $I_1$ 分成 $4$ 个全等的闭正方形 $I_{11}, I_{12}, I_{13}, I_{14}$，那么至少有一个 $I_{1k}\ (1\le k \le 4)$ 使得 $I_{1k} \cap S$ 不能被 $\{U_\alpha\}$ 中的有限个元素所覆盖，取其为 $I_2$ 
		将 $I_2$ 分成 $4$ 个全等的闭正方形 $I_{21}, I_{22}, I_{23}, I_{24}$，那么至少有一个 $I_{2k}\ (1\le k \le 4)$ 使得 $I_{2k} \cap S$ 不能被 $\{U_\alpha\}$ 中的有限个元素所覆盖，取其为 $I_3$ 
		如此下去就得到一列正方形 $I_1 \supset I_2 \supset I_3 \supset \cdots$ 满足两点：
		第一点：闭集 $I_1 \cap S\ (l=1,2,3,\cdots)$ 不能被 $\{U_\alpha\}$ 中的有限个元素所覆盖
		第二点：$\lim\limits_{l\to\infty} \mathrm{diam}\ (I_l \cap S) = 0$ 
		由 **Cantor 闭区间套定理**可知存在唯一的一点 $\boldsymbol a = (\xi, \eta) \in \bigcap\limits_{l=1}^\infty (I_l \cap S)$ 
		任取包含点 $\boldsymbol a$ 的开集 $U_* \in \{ U_\alpha \}$，只要适当选择 $r$，就有 $O(\boldsymbol a, r) \subset U$ 
		又由于 $\lim\limits_{l\to\infty} \mathrm{diam}\ (I_l \cap S) = 0$，则当 $l$ 充分大时就成立 $I_l \cap S \subset O(\boldsymbol a, r) \subset U_*$ 
		这就导出了矛盾
		证毕！
- **定理**：设 $S$ 是 $\mathbb R^n$ 上的点集，那么以下三个命题等价：
	1. $S$ 是有界闭集
	2. $S$ 是紧集
	3. $S$ 的任一无限子集在 $S$ 中必有聚点
	- *证明过程* 
		定理 1 与 2 等价就是 **Heine-Borel 定理** 
		**1 推 3** 
		设 $S$ 是有界闭集，由 **De Morgan 公式**可知 $S$ 的无限子集必有聚点，而 $S$ 是闭集，因此这个聚点必属于 $S$ 
		因此 $S$ 含有它的全部聚点，即 $S$ 是闭集
		**3 推 1** 
		若 $S$ 的任一无限子集在 $S$ 中都有聚点，则显然 $S$ 中的任一收敛点列 $\{\boldsymbol x_k\}$ 的极限必属于 $S$，因此 $S$ 中存在点列 $\{\boldsymbol x_k\}$ 满足 $\| \boldsymbol x_k \| > k\ (k=1,2,\cdots)$ 
		显然 $\{\boldsymbol x_k\}$ 是无限集，且在 $\mathbb R^n$ 中（因为在 $S$ 中）没有聚点
		这个矛盾表明 $S$ 是有界的
- **Euclid 空间上的基本定理**：Cantor 闭区间套定理、Bolzano-Weierstrass 定理、Cauchy 收敛原理、Heine-Borel 定理称为 Euclid 空间上的基本定理，它们是相互等价的
## 11-2 多元连续函数
### 11-2-1 多元函数
- **$n$ 元函数**、**定义域**、**值域**、**图像**：设 $D$ 是 $\mathbb R^n$ 上的点集，$D$ 到 $\mathbb R$ 的映射 $\begin{aligned} f:& D \to \mathbb R \\ & \boldsymbol x \mapsto z \end{aligned}$ 称为 **$n$ 元函数**，记为 $z = f(\boldsymbol x)$。这时，$D$ 称为 $f$ 的定义域，$f(D) = \{z \in \mathbb R \mid z = f(\boldsymbol x),\ \boldsymbol x \in D\}$ 称为 $f$ 的**值域**，$\Gamma = \{(\boldsymbol x, z) \in \mathbb R^{n+1} \mid z = f(\boldsymbol x),\ \boldsymbol x\in D\}$ 称为 $f$ 的**图像** 
### 11-2-2 多元函数的极限（重极限）
- **收敛**、**$n$ 重极限**：设 $D$ 是 $\mathbb R^n$ 上的开集，$\boldsymbol x_0 = (x_1^0, x_2^0, \cdots, x_n^0) \in D$ 为一定点，$z=f(\boldsymbol x)$ 是定义在 $D\backslash \{\boldsymbol x_0\}$ 上的 $n$ 元函数，$A$ 是一个实数。如果对于任意给定的 $\varepsilon>0$，存在 $\delta>0$，使得当 $\boldsymbol x \in O(\boldsymbol x_0, \delta) \backslash \{\boldsymbol x_0\}$ 时，成立 $|f(\boldsymbol x) - A| < \varepsilon$，则称当 $\boldsymbol x$ 趋于 $\boldsymbol x_0$ 时 $f$ **收敛**，并称 $A$ 为 $f$ 当 $\boldsymbol x$ 趋于 $\boldsymbol x_0$ 时的 **$n$ 重极限**，记为 $\lim\limits_{x\to x_0} f(\boldsymbol x) = A$ 或 $f(\boldsymbol x) \to A\ (\boldsymbol x \to \boldsymbol x_0)$ 或 $\lim\limits_{\substack{x_1\to x_1^0 \\ x_2 \to x_2^0 \\ \cdots \\ x_n \to x_n^0}} f(x_1,x_2, \cdots, x_n) = A$ 
	- 条件 $\boldsymbol x \in O(\boldsymbol x_0, \delta) \backslash \{\boldsymbol x_0\}$ 也可以用 $|x_1 - x_1^0| < \delta,\ |x_2-x_2^0| < \delta,\cdots, |x_n - x_n^0| < \delta\ (\boldsymbol x \not= \boldsymbol x_0)$ 代替
### 11-2-3 累次极限
- **二次极限**：设 $D$ 是 $\mathbb R^n$ 上的开集，$(x_0, y_0) \in D$ 为一定点，$z=f(x,y)$ 为定义在 $D \backslash \{(x_0, y_0)\}$ 上的二元函数。如果对于每个固定的 $y\not=y_0$，极限 $\lim\limits_{x\to x_0} f(x,y)$ 存在，并且极限 $\lim\limits_{y\to y_0} \lim\limits_{x\to x_0} f(x, y)$ 存在，那么称此极限值为函数 $f(x,y)$ 在点 $(x_0,y_0)$ 的**先对 $x$ 后对 $y$ 的二次极限** 
	- 同理可定义**先对 $y$ 后对 $x$ 的二次极限** $\lim\limits_{x\to x_0} \lim\limits_{y\to y_0} f(x,y)$ 
	- 累次极限存在与重极限存在的关系很复杂
		- 二次极限存在不能保证二重极限存在。如：$f(x, y) = \dfrac{xy}{x^2+y^2},\ (x,y)\not=(0,0)$，$f(x,y) = \dfrac{(y^2-x)^2}{y^4+x^2},\ (x,y)\not=(0,0)$ 
		- 二重极限存在不能保证二次极限存在。如：$f(x,y) = \begin{cases} (x^2+y^2)\sin\dfrac 1x \cos \dfrac 1y & x\not=0 \text{ 且 } y\not=0 \\ 0 & x=0 \text{ 或 } y = 0 \end{cases}$ 的二重极限存在，但两个二次极限都不存在。再如：$f(x,y) = \begin{cases} y\sin \dfrac 1x & x\not= 0 \text{ 且 } y\not=0 \\ 0 & x=0 \text{ 或 } y=0 \end{cases}$ 的二重极限存在，但两个二次极限中有一个不存在
		- 一个二次极限存在不能保证另一个二次极限也存在
		- 即使两个二次极限都存在，也不一定相等
	- **两个极限运算不一定可以交换次序** 
- **定理**：若二元函数 $f(x, y)$ 在 $(x_0, y_0)$ 点存在二重极限 $\lim\limits_{(x, y) \to (x_0, y_0)} f(x, y) = A$，且当 $x\not= x_0$ 时存在极限 $\lim\limits_{y\to y_0} f(x, y) = \varphi(x)$，那么 $f(x, y)$ 在 $(x_0, y_0)$ 点的先对 $y$ 后对 $x$ 的二次极限存在且与二重极限相等，即 $\lim\limits_{x\to x_0} \lim\limits_{y\to y_0} f(x, y) = \lim\limits_{x\to x_0} \varphi(x) = \lim\limits_{(x,y)\to(x_0,y_0)} f(x,y) = A$ 
	- *证明过程* 
		只需证明 $\lim\limits_{x\to x_0} \varphi(x) = A$ 即可
		对于任意给定的 $\varepsilon>0$，由于 $\lim\limits_{(x,y)\to(x_0,y_0)} f(x,y) = A$，所以存在 $\delta >0$，使得当 $0<\sqrt{(x-x_0)^2 + (y-y_0)^2} < \delta$ 时有 $|f(x,y) - A| < \dfrac \varepsilon 2$ 
		于是对每个满足 $0<|x-x_0|<\delta$ 的 $x$，令 $y\to y_0$ 得到 $|\varphi(x) - A| = \lim\limits_{y\to y_0} |f(x,y) - A| \le \dfrac \varepsilon 2 < \varepsilon$ 
		即 $\forall\ \varepsilon>0,\ \exists\ \delta > 0,\ \forall\ x(0<|x-x_0|<\delta)$ 都有 $|\varphi(x) - A| < \varepsilon$ 
		故 $\lim\limits_{x\to x_0} \varphi(x) = A$ 
	- 同理有**定理**：若二元函数 $f(x, y)$ 在 $(x_0, y_0)$ 点存在二重极限 $\lim\limits_{(x, y) \to (x_0, y_0)} f(x, y) = A$，且当 $y\not= y_0$ 时存在极限 $\lim\limits_{x\to x_0} f(x, y) = \psi(y)$，那么 $f(x, y)$ 在 $(x_0, y_0)$ 点的先对 $x$ 后对 $y$ 的二次极限存在且与二重极限相等，即 $\lim\limits_{y\to y_0} \lim\limits_{x\to x_0} f(x, y) = \lim\limits_{y\to y_0} \psi(y) = \lim\limits_{(x,y)\to(x_0,y_0)} f(x,y) = A$ 
	- **推论**：若函数 $f(x, y)$ 的二重极限及两个二次极限都存在，则三者必相等，即 $\lim\limits_{y\to y_0} \lim\limits_{x\to x_0} f(x,y) = \lim\limits_{x\to x_0} \lim\limits_{y\to y_0} f(x,y) = \lim\limits_{(x,y)\to (x_0,y_0)} f(x,y)$，此时**极限运算可以交换次序** 
### 11-2-4 多元函数的连续性
- **连续**：设 $D$ 是 $\mathbb R^n$ 上的开集，$z=f(\boldsymbol x)$ 是定义在 $D$ 上的函数，$\boldsymbol x_0\in D$ 为一定点，如果 $\lim\limits_{x\to x_0} f(\boldsymbol x) = f(x_0)$，则称函数 $f$ 在点 $\boldsymbol x_0$ **连续** 
	- **$\varepsilon-\delta$ 语言版本**：$\forall\ \varepsilon>0,\ \exists\ \delta>0,\ \forall\ \boldsymbol x \in O(\boldsymbol x_0, \delta)$ 有 $|f(\boldsymbol x) - f(\boldsymbol x_0)| < \varepsilon$，则称函数 $f$ 在点 $\boldsymbol x_0$ **连续** 
- **连续函数**：如果函数 $f$ 在 $D$ 上每一点连续，就称 $f$ 在 $D$ 上连续，或称 $f$ 是 $D$ 上的**连续函数** 
	- 一元连续函数的和差积商及复合函数性质可平行地推广到多元连续函数
### 11-2-5 向量值函数
- **$n$ 元 $m$ 维向量值函数**（**多元函数组**）、**定义域**、**值域**：设 $D$ 是 $\mathbb R^n$ 上的点集，$D$ 到 $\mathbb R^m$ 的映射 $\begin{aligned} f:D & \to \mathbb R^m \\ \boldsymbol x = (x_1, x_2, \cdots, x_n) & \mapsto \boldsymbol z = (z_1, z_2, \cdots, z_n) \end{aligned}$ 称为 **$n$ 元 $m$ 维向量值函数**（或称**多元函数组**），记为 $\boldsymbol z = f(\boldsymbol x)$。$D$ 称为 $\boldsymbol f$ 的**定义域**，$\boldsymbol f(D) = \{ \boldsymbol z \in \mathbb R^m \mid \boldsymbol z = f(\boldsymbol x),\ \boldsymbol x \in D \}$ 称为 $\boldsymbol f$ 的**值域** 
	- 多元函数是 $m=1$ 的特殊情形
	- **坐标函数**（**分量函数**）：显然，每个 $z_i\ (i=1,2,\cdots,m)$ 都是 $\boldsymbol x$ 的函数 $z_i = f_i(\boldsymbol x)$，它称为 $\boldsymbol f$ 的第 $i$ 个**坐标函数**（或**分量函数**），于是 $\boldsymbol f$ 可以表达为分量形式 $\begin{cases} z_1 = f_1(\boldsymbol x) \\ z_2 = f_2(\boldsymbol x) \\ \cdots \\ z_m = f_m(\boldsymbol x) \end{cases}\ (\boldsymbol x\in D)$，因此 $\boldsymbol f$ 又可表示为 $\boldsymbol f = (f_1, f_2, \cdots, f_m)$ 
- **极限**、**收敛**：设 $D$ 是 $\mathbb R^n$ 上的开集，$\boldsymbol x_0 \in D$ 为一定点，$\boldsymbol f: D\backslash \{\boldsymbol x_0\} \to \mathbb R^m$ 是映射（向量值函数），$\boldsymbol A$ 是一个 $m$ 维向量。若 $\forall\ \varepsilon>0,\ \exists\ \delta>0,\ \forall\ \boldsymbol x \in O(\boldsymbol x_0, \delta) \backslash \{\boldsymbol x_0\}$ 成立 $|\boldsymbol f(\boldsymbol x) - \boldsymbol A| < \varepsilon$（即 $\boldsymbol f(\boldsymbol x) \in O(\boldsymbol A, \varepsilon)$），则称 $\boldsymbol A$ 为当 $\boldsymbol x$ 趋于 $\boldsymbol x_0$ 时 $\boldsymbol f$ 的**极限**，并称当 $\boldsymbol x$ 趋于 $\boldsymbol x_0$ 时 $\boldsymbol f$ **收敛**，记为 $\lim\limits_{x\to x_0} \boldsymbol f(\boldsymbol x) = \boldsymbol A$ 或 $\boldsymbol f(\boldsymbol x) \to \boldsymbol A\ (\boldsymbol x \to \boldsymbol x_0)$ 
- **连续**：设 $D$ 上 $\mathbb R^n$ 上的开集，$\boldsymbol x_0 \in D$ 为一定点。$\boldsymbol f: D \to \mathbb R^m$ 是映射（向量值函数）。如果 $\boldsymbol f$ 满足 $\lim\limits_{\boldsymbol x \to \boldsymbol x_0} \boldsymbol f(\boldsymbol x) = \boldsymbol f(\boldsymbol x_0)$，那么称 $\boldsymbol f$ 在 $\boldsymbol x_0$ 点连续
	- **$\varepsilon-\delta$ 语言版本**：若 $\forall\ \varepsilon>0,\ \exists\ \delta>0,\ \forall\ \boldsymbol x \in O(x_0, \delta)$ 时成立 $|\boldsymbol f(\boldsymbol x) - \boldsymbol f(\boldsymbol x_0)| < \varepsilon$（即 $\boldsymbol f(\boldsymbol x) \in O(\boldsymbol f(\boldsymbol x_0), \varepsilon)$），则称 $\boldsymbol f$ 在点 $x_0$ **连续** 
- **连续映射**：如果映射 $\boldsymbol f$ 在 $D$ 上每一点都连续，就称 $\boldsymbol f$ 在 $D$ 上连续，这时称映射 $\boldsymbol f$ 为 $D$ 上的**连续映射** 
- **定理**：设 $D$ 是 $\mathbb R^n$ 上的开集，$\boldsymbol x_0 \in D$ 为一定点。那么映射 $\boldsymbol f: D\to \mathbb R^m$ 在 $\boldsymbol x_0$ 点连续 $\iff$ 函数 $f_1, f_2, \cdots, f_m$ 在 $\boldsymbol x_0$ 点连续
	- *证明过程* 
		定理证明可由不等式：
		$$
		\begin{aligned}
		|f_j(\boldsymbol x) - f_j(\boldsymbol x_0)| \le & |\boldsymbol f(\boldsymbol x) - \boldsymbol f(\boldsymbol x_0)| \\
		= & \sqrt{\sum_{i=1}^m(f_i(\boldsymbol x) - f_i(\boldsymbol x_0))^2} \\
		\le & \sum_{i=1}^m |f_i(\boldsymbol x) - f_i(\boldsymbol x_0)|\ (j=1,2,\cdots,m)
		\end{aligned}
		$$
		直接得到
	- 映射（向量值函数）的连续性可以归结到它的坐标函数的连续性上去
- **复合映射**：设 $\Omega$ 是 $\mathbb R^k$ 上的开集，$D$ 为 $\mathbb R^n$ 上的开集。$\boldsymbol g: D \to \mathbb R^k$ 与 $\boldsymbol f: \Omega \to \mathbb R^m$ 为映射。并且 $\boldsymbol g$ 的值域 $\boldsymbol g(D)$ 满足 $\boldsymbol g(D) \subset \Omega$，则可以定义**复合映射** $\begin{aligned} \boldsymbol f \circ \boldsymbol g: D & \to \mathbb R^m \\ \boldsymbol u & \mapsto \boldsymbol f(\boldsymbol g(\boldsymbol u)) \end{aligned}$ 
- **定理**：如果 $\boldsymbol g$ 在 $D$ 上连续，$\boldsymbol f$ 在 $\Omega$ 上连续，且 $\boldsymbol g(D) \subset \Omega$，那么复合映射 $\boldsymbol f \circ \boldsymbol g$ 在 $D$ 上连续
## 11-3 连续函数的性质
### 11-3-1 紧集上的连续映射
- **连续**：设点集 $K\subset \mathbb R^n$，$\boldsymbol f: K \to \mathbb R^m$ 为映射（向量值函数），$\boldsymbol x_0 \in K$。如果 $\forall\ \varepsilon>0,\ \exists\ \delta>0,\ \forall\ \boldsymbol x\in O(\boldsymbol x_0, \delta) \cap K$ 成立 $|\boldsymbol f(\boldsymbol x) - \boldsymbol f(\boldsymbol x_0)| < \varepsilon$（即 $\boldsymbol f(\boldsymbol x) \in O(\boldsymbol f(\boldsymbol x_0), \varepsilon)$），则称 $\boldsymbol f$ 在点 $\boldsymbol x_0$ **连续** 
- **连续映射**：如果映射 $\boldsymbol f$ 在 $K$ 上每一点连续，就称 $\boldsymbol f$ 在 $K$ 上连续，或称映射 $\boldsymbol f$ 为 $K$ 上的**连续映射** 
- **定理**：连续映射将紧集映射成紧集
	- *证明过程* 
		设 $K$ 是 $\mathbb R^n$ 中紧集，$\boldsymbol f: K \to \mathbb R^m$ 为连续映射
		要证明 $K$ 的像集 $\boldsymbol f(K) = \{\boldsymbol y \in \mathbb R^m \mid \boldsymbol y = \boldsymbol f(\boldsymbol x),\ \boldsymbol x \in K \}$ 是紧集，只需证明 $\boldsymbol f(K)$ 中的任意一个无限点集必有聚点属于 $\boldsymbol f(K)$ 就可以
		又因为每一个无限点集都有可列无限点集，即点列形式的子集，所以只要证明 $\boldsymbol f(K)$ 的任意一个点列必有聚点属于 $\boldsymbol f(K)$ 即可
		设 $\{\boldsymbol y_k\}$ 为 $\boldsymbol f(K)$ 的任意一个点列，对于每个 $\boldsymbol y_k$，任取一个满足 $\boldsymbol f(\boldsymbol x_k) = \boldsymbol y_k$ 的 $\boldsymbol x_k \in K\ (k=1,2,\cdots)$，则 $\{\boldsymbol x_k\}$ 为紧集 $K$ 中的点列，它必有聚点属于 $K$ 
		即存在 $\{\boldsymbol x_k\}$ 的子列 $\{\boldsymbol x_{k_l}\}$ 满足 $\lim\limits_{l\to\infty} \boldsymbol x_{k_l} = \boldsymbol a \in K$ 
		由 $\boldsymbol f$ 在 $\boldsymbol a$ 点的连续性得 $\lim\limits_{l\to\infty} \boldsymbol y_{k_l} = \lim\limits_{l\to\infty} \boldsymbol f(\boldsymbol x_{k_l}) = \boldsymbol f(\boldsymbol a)$ 
		即 $\boldsymbol f(\boldsymbol a)$ 是 $\{\boldsymbol y_k\}$ 得一个聚点，它显然属于 $\boldsymbol f(K)$，因此 $\boldsymbol f(K)$ 是紧集
- **有界性定理**：设 $K$ 是 $\mathbb R^n$ 中紧集，$f$ 是 $K$ 上的连续函数，则 $f$ 在 $K$ 上有界
- **最值定理**：设 $K$ 是 $\mathbb R^n$ 中紧集，$f$ 是 $K$ 上的连续函数，则 $f$ 在 $K$ 上必能取到最大值和最小值，即存在 $\boldsymbol\xi_1, \boldsymbol\xi_2 \in K$，使对一切 $\boldsymbol x\in K$ 成立 $f(\boldsymbol\xi_1) \le f(\boldsymbol x) \le f(\boldsymbol \xi_2)$ 
- **一致连续**：设 $K$ 是 $\mathbb R^n$ 中点集，$\boldsymbol f: K \to \mathbb R^n$ 为映射。如果 $\forall\ \varepsilon>0,\ \exists\ \delta>0,\ \forall\ \boldsymbol x',\boldsymbol x''\in K(|\boldsymbol x' - \boldsymbol x''| < \delta)$ 成立 $|\boldsymbol f(\boldsymbol x') - \boldsymbol f(\boldsymbol x'')| < \varepsilon$，则称 $\boldsymbol f$ 在 $K$ 上**一致连续** 
	- 一致连续的映射一定是连续的
	- 连续的映射不一定是一致连续的
- **一致连续定理**：设 $K$ 是 $\mathbb R^n$ 中紧集，$\boldsymbol f: K \to \mathbb R^m$ 为连续映射，则 $f$ 在 $K$ 上一致连续
	- *证明过程* 
		对于任意给定的 $\varepsilon>0$，由于 $\boldsymbol f$ 在 $K$ 上连续，因此：
		$\forall\ \boldsymbol a \in K,\ \exists \delta_a > 0,\ \forall\ \boldsymbol x \in O(\boldsymbol a, \delta_a) \cap K$ 有 $|\boldsymbol f(\boldsymbol x) - \boldsymbol f(\boldsymbol a)| < \dfrac \varepsilon 2$ 
		显然开集族 $\left\{ O\left( \boldsymbol a, \dfrac{\delta_a}{2} \right),\ \boldsymbol a \in K \right\}$ 是 $K$ 的一个开覆盖
		由于 $K$ 是紧集，因此存在其中有限个开集 $O\left( \boldsymbol a_1, \dfrac{\delta_{a_1}}{2} \right),\ O\left( \boldsymbol a_2, \dfrac{\delta_{a_2}}{2} \right),\cdots, O\left( \boldsymbol a_p, \dfrac{\delta_{a_p}}{2} \right)$ 覆盖了 $K$ 
		记 $\delta = \dfrac 12 \min\limits_{1\le j\le p} \{\delta_{a_j}\}$，那么对于 $K$ 中满足 $|\boldsymbol x' - \boldsymbol x''| < \delta$ 的任意 $\boldsymbol x'$ 和 $\boldsymbol x''$，不失一般性，设 $\boldsymbol x' \in O\left( \boldsymbol a_1, \dfrac{\delta_{a_t}}{2} \right)\ (1\le t\le p)$，则有：$|\boldsymbol x'' - \boldsymbol a_t| \le |\boldsymbol x'' - \boldsymbol x'| + |\boldsymbol x' - \boldsymbol a_t| < \dfrac 12 \delta_{a_t} + \dfrac 12 \delta_{a_t} = \delta_{a_t}$ 
		于是成立 $|\boldsymbol f(\boldsymbol x'') - \boldsymbol f(\boldsymbol a_t)| < \dfrac \varepsilon 2$ 
		因此 $|\boldsymbol f(\boldsymbol x') - \boldsymbol f(\boldsymbol x'')| \le |\boldsymbol f(\boldsymbol x'') - \boldsymbol f(\boldsymbol a_t)| + |\boldsymbol f(\boldsymbol x') - \boldsymbol f(\boldsymbol a_t)| < \dfrac \varepsilon 2 + \dfrac \varepsilon 2 = \varepsilon$ 
		由定义，$\boldsymbol f$ 在 $K$ 上一致连续
		证毕！
### 11-3-2 连通集与连通集上的连续映射
- **道路**、**起点**、**终点**：设 $S$ 是 $\mathbb R^n$ 中的点集，若连续映射 $\boldsymbol\gamma:[0,1] \to \mathbb R^n$ 的值域全部落在 $S$ 中，即满足 $\boldsymbol\gamma([0,1]) \subset S$，则称  $\boldsymbol\gamma$ 为 $S$ 中的**道路**，$\boldsymbol\gamma(0)$ 与 $\boldsymbol\gamma(1)$ 分别为道路的**起点**与**终点** 
- **连通的**（**连通集**）：若 $S$ 中的任意两点 $\boldsymbol x, \boldsymbol y$ 之间，都存在 $S$ 中以 $\boldsymbol x$ 为起点，$\boldsymbol y$ 为终点的道路，则称 $S$ 为**连通的**（或**道路连通的**），也称 $S$ 为**连通集** 
	- $\mathbb R$ 上的连通子集为区间，且 $\mathbb R$ 上的连通子集为紧集 $\iff$ 它是闭区间
- **区域**（**开区域**）、**闭区域**：连通的开集称为**区域***（或称**开区域**）。区域的闭包称为**闭区域** 
- **定理**：连续映射将连通集映射成连通集
	- *证明过程* 
		设 $D$ 是 $\mathbb R^n$ 中的连通集，$\boldsymbol f: D\to \mathbb R^m$ 为连续映射，先证明 $\boldsymbol f$ 的像集 $\boldsymbol f(D) = \{ \boldsymbol y \in \mathbb R^m \mid \boldsymbol y = \boldsymbol f(\boldsymbol x),\ \boldsymbol x \in D \}$ 是连通集
		对任意 $\boldsymbol f(\boldsymbol x), \boldsymbol f(\boldsymbol y) \in \boldsymbol f(D)\ (\boldsymbol x, \boldsymbol y \in D)$，由于 $D$ 的连通性，可知存在连续映射 $\boldsymbol\gamma:[0,1] \to D \subset \mathbb R^n$ 使得 $\boldsymbol\gamma(0) = \boldsymbol x,\ \boldsymbol\gamma(1) = \boldsymbol y$ 
		于是对于连续映射 $\boldsymbol f \circ \boldsymbol \gamma$ 来说，有 $\boldsymbol f(\boldsymbol\gamma([0,1])) \subset \boldsymbol f(D)$ 且 $\boldsymbol f(\boldsymbol\gamma(0)) = \boldsymbol f(\boldsymbol x)$ 且 $\boldsymbol f(\boldsymbol\gamma(1)) = \boldsymbol f(\boldsymbol y)$ 
		故 $\boldsymbol f \circ \boldsymbol\gamma$ 是 $\boldsymbol f(D)$ 中以 $\boldsymbol f(\boldsymbol x)$ 为起点，以 $\boldsymbol f(\boldsymbol y)$ 为终点的道路
		由 $\boldsymbol f(\boldsymbol x), \boldsymbol f(\boldsymbol y)$ 的任意性可知 $f(D)$ 是连通的
		证毕！
	- **推论**：连续函数将连通的紧集映射成闭区间
- **中间值定理**：设 $K$ 为 $\mathbb R^n$ 中连通的紧集，$f$ 是 $K$ 上的连续函数，则 $f$ 可取到它在 $K$ 上的最小值 $m$ 与最大值 $M$ 之间的一切值。换言之，$f$ 的值域是闭区间 $[m,M]$ 
# 5 无约束问题算法 (III)
## 5-0 前言
- 前面介绍的 Newton 法和拟 Newton 算法具有较快的收敛速度，但算法需要储存矩阵 $B_k$，因而在求解大规模问题时会遇到困难。
- 最速下降法具有存储量少的特点，但该算法收敛速度慢。
- 本章介绍求解无约束问题 $\min f(x),\ (x \in \mathbb{R}^n)$ 的共轭梯度法。
	- 该算法具有存储量少且收敛速度较快的特点。
	- 为了了解算法的思想，我们先介绍求解凸二次函数极小值问题的共轭梯度法。
## 5-1 二次函数极小化问题的共轭方向法
- *问题提出*：考察二次函数极小化问题 $\min f(x) = \dfrac{1}{2} x^T Q x + q^T x$，其中 $Q \in \mathbb{R}^{n \times n}$ 对称正定，$q \in \mathbb{R}^n$。先引入向量组共轭的概念。  
- **相互共轭**：设 $A \in \mathbb{R}^{n \times n}$ 对称正定，$d^{(1)}, d^{(2)}, \cdots, d^{(m)}$ 是 $\mathbb{R}^n$ 中非零向量。若对 $i, j = 1, 2, \cdots, m$，有 $d^{(i)T} A d^{(j)} = 0,\ (i \neq j)$，则称向量组 $d^{(1)}, d^{(2)}, \cdots, d^{(m)}$ 关于矩阵 $A$ **相互共轭** 
	- 由共轭向量组的定义易知，若 $A = I$ 是单位矩阵，则向量组的共轭性等价于正交性。
	- 一般地，令 $p^{(i)} = A^{1/2} d^{(i)} \ (i = 1, 2, \cdots, m)$，则向量组 $d^{(1)}, d^{(2)}, \cdots, d^{(m)}$ 关于矩阵 $A$ 相互共轭等价于向量组 $p^{(i)} \ (i = 1, 2, \cdots, m)$ 相互正交。因此，共轭是正交概念的推广。
- **定理 5.1.1**：设 $A \in \mathbb{R}^{n \times n}$ 对称正定，非零向量组 $d^{(1)}, d^{(2)}, \cdots, d^{(m)} \in \mathbb{R}^n$ 关于矩阵 $A$ 相互共轭，则 $d^{(1)}, d^{(2)}, \cdots, d^{(m)}$ 线性无关。
	- *证明过程* 
		设 $\sum\limits_{i=1}^{m} \alpha_i d^{(i)} = 0$，由共轭性得 $0 = \left( \sum\limits_{i=1}^{m} \alpha_i d^{(i)} \right)^T A \left( \sum\limits_{i=1}^{m} \alpha_i d^{(i)} \right) = \sum\limits_{i=1}^{m} \alpha_i^2 d^{(i)T} A d^{(i)}$ 
		但 $d^{(i)} \neq 0$ 且 $A$ 对称正定，因此 $\alpha_i = 0,\ (i = 1, 2, \cdots, m)$ 
		即 $d^{(1)}, d^{(2)}, \cdots, d^{(m)}$ 线性无关。证毕！
	- 该定理表明：共轭向量组线性无关
	- 该定理表明：若非零向量组 $d^{(1)}, d^{(2)}, \cdots, d^{(m)} \in \mathbb{R}^n$ 关于对称正定矩阵 $A$ 相互共轭，则必有 $m \leq n$ 
- 求解二次函数极小值问题 $\min f(x) = \dfrac{1}{2} x^T Q x + q^T x$ 的共轭方向法的*思想* 
	从某个初始点 $x^{(0)}$ 出发，依次沿关于 $Q$ 相互共轭的 $n$ 个方向 $d^{(i)} \ (i = 0, 1, \cdots, n-1)$ 进行精确线性搜索
	即令 $x^{(k+1)} = x^{(k)} + \alpha_k d^{(k)},\ (k = 0, 1, \cdots, n-1)$，其中 $\alpha_k$ 是下面问题的解：$f(x^{(k)} + \alpha_k d^{(k)}) = \min\limits_{\alpha \in \mathbb{R}} f(x^{(k)} + \alpha d^{(k)})$ 
	*注意*：由于 $d^{(k)}$ 可能不是函数 $f$ 在 $x^{(k)}$ 处的下降方向，因此，上面的精确线性搜索在整个实数轴上进行。
- **定理 5.1.2** (**子空间扩展定理**)：设函数 $f$ 由 $\min f(x) = \dfrac{1}{2} x^T Q x + q^T x$ 给出，非零向量组 $d^{(0)}, d^{(1)}, \cdots, d^{(n-1)}$ 关于矩阵 $Q$ 相互共轭，点 $x^{(0)} \in \mathbb{R}^n$ 任意。设迭代格式 $x^{(k+1)} = x^{(k)} + \alpha_k d^{(k)},\ (k = 0, 1, \cdots, n-1)$ 中的步长 $\alpha_k$ 由精确线性搜索 $f(x^{(k)} + \alpha_k d^{(k)}) = \min\limits_{\alpha \in \mathbb{R}} f(x^{(k)} + \alpha d^{(k)})$ 确定，即 $\alpha_k$ 满足 $f(x^{(k)} + \alpha_k d^{(k)}) = \min\limits_{\alpha \in \mathbb{R}} f(x^{(k)} + \alpha d^{(k)})$，则 $x^{(k+1)}$ 是 $f$ 在线性流形 $S_k = \left\{ x = x^{(0)} + \sum\limits_{i=0}^{k} \beta_i d^{(i)} \mid \beta_i \in \mathbb{R}, \ i = 0, 1, \cdots, k \right\}$ 中的极小值点。特别地，$x^{(n)} = x^* = -Q^{-1} q$ 是问题 $\min f(x) = \dfrac{1}{2} x^T Q x + q^T x$ 的唯一全局最优解。
	- *证明过程* 
		由于 $d^{(0)}, d^{(1)}, \cdots, d^{(n-1)}$ 线性无关，故有 $S_{n-1} = \mathbb{R}^n$ 
		因此，只需证明 $x^{(k+1)}$ 是 $f$ 在线性流形 $S_k$ 中的极小值点。
		显然有 $x^{(k+1)} = x^{(k)} + \alpha_k d^{(k)} = \cdots = x^{(0)} + \sum\limits_{i=0}^{k} \alpha_i d^{(i)} \in S_k$ 
		对任何 $x \in S_k$，存在 $\beta_i \in \mathbb{R} \ (i = 0,1,\cdots,k)$，使得 $x = x^{(0)} + \sum\limits_{i=0}^{k} \beta_i d^{(i)}$ 
		由 Taylor 展开得
		$$
		\begin{align*}
		f(x) &= f(x^{(k+1)}) + \nabla f(x^{(k+1)})^T (x - x^{(k+1)}) + \frac{1}{2}(x - x^{(k+1)})^T Q (x - x^{(k+1)}) \\
		&\geqslant f(x^{(k+1)}) + \nabla f(x^{(k+1)})^T (x - x^{(k+1)}) \\
		&= f(x^{(k+1)}) + \sum_{i=0}^{k} (\beta_i - \alpha_i) \nabla f(x^{(k+1)})^\top d^{(i)}
		\end{align*}
		$$
		而且，当 $x \neq x^{(k+1)}$ 时，上面的不等式为严格不等式。
		因此，只需证明 $\nabla f(x^{(k+1)})^\top d^{(i)} = 0,\ (\forall\ i = 0,1,\cdots,k)$ 
		注意到对二次函数有 $\nabla f(x) - \nabla f(y) = Q(x - y),\ (\forall\ x, y \in \mathbb{R}^n)$ 
		利用共轭性条件和精确线性搜索条件可得，对任何 $i \leqslant k$，
		$$
		\begin{aligned}
		d^{(i)T} \nabla f(x^{(k+1)}) &= d^{(i)T} \big[ (\nabla f(x^{(k+1)}) - \nabla f(x^{(k)})) + \cdots + (\nabla f(x^{(i+2)}) - \nabla f(x^{(i+1)})) + \nabla f(x^{(i+1)}) \big] \\
		&= \sum_{j=i+1}^{k} d^{(i)T} \big[ \nabla f(x^{(j+1)}) - \nabla f(x^{(j)}) \big] \\
		&= \sum_{j=i+1}^{k} d^{(i)T} Q (x^{(j+1)} - x^{(j)}) \\
		&= \sum_{j=i+1}^{k} \alpha_j d^{(i)T} Q d^{(j)} = 0
		\end{aligned}
		$$
		因此 $\nabla f(x^{(k+1)})^\top d^{(i)} = 0,\ (\forall\ i = 0,1,\cdots,k)$ 成立，从而定理得证！
	- 该定理说明，由共轭方向法产生的 $x^{(n)}$ 是问题 $\min f(x) = \dfrac{1}{2} x^T Q x + q^T x$ 的唯一解。
	- 该定理说明：采用精确线性搜索的共轭方向法求解严格凸二次函数极小值问题 $\min f(x) = \dfrac{1}{2} x^T Q x + q^T x$ 时可经过有限步达到问题的最优解。因此，共轭方向法具有二次终止性。
	- 共轭方向可用类似于 Gram-Schmidt 正交化过程产生。
- **算法 5.1** (**Gram-Schmidt 共轭化过程**)
	- *第 0 步*：给定线性无关向量组 $p^{(0)}, p^{(1)}, \cdots, p^{(n-1)} \in \mathbb{R}^n$。令 $d^{(0)} = p^{(0)}$，$k := 0$ 
	- *第 1 步*：计算 $d^{(k+1)} = p^{(k+1)} - \sum\limits_{j=0}^{k} \dfrac{d^{(j)T} Q p^{(k+1)}}{d^{(j)T} Q d^{(j)}} d^{(j)}$ 
	- *第 2 步*：若 $k = n - 2$，则停止。否则，令 $k := k + 1$，转*第 1 步* 
- **定理 5.1.3**：设矩阵 $Q \in \mathbb{R}^{n \times n}$ 对称正定且向量组 $p^{(0)}, p^{(1)}, \cdots, p^{(n-1)} \in \mathbb{R}^n$ 线性无关。则**算法 5.1** 产生的 $\{d^{(j)}\}_{j=0}^{n-1}$ 关于矩阵 $Q$ 相互共轭，即 $d^{(i)T} Q d^{(j)} = 0,\ (\forall\ i \neq j, \, i, j = 0, 1, \cdots, n-1)$ 
	- *证明过程* 
		我们用归纳法证明：对所有 $0 < k \leqslant n-1$，$d^{(i)T} Q d^{(k)} = 0,\ (\forall\ i < k)$ 
		当 $k=1$ 时，由 $d^{(k+1)} = p^{(k+1)} - \sum\limits_{j=0}^{k} \dfrac{d^{(j)T} Q p^{(k+1)}}{d^{(j)T} Q d^{(j)}} d^{(j)}$ 得 $d^{(0)T} Q d^{(1)} = d^{(0)T} Q p^{(1)} - \dfrac{d^{(0)T} Q p^{(1)}}{d^{(0)T} Q d^{(0)}} d^{(0)T} Q d^{(0)} = 0$ 
		设 $d^{(i)T} Q d^{(k)} = 0,\ (\forall\ i < k)$ 对 $\leqslant m$ 成立，即 $d^{(i)T} Q d^{(j)} = 0,\ (\forall\ i < j, \, j \leqslant m)$ 
		我们证明 $d^{(i)T} Q d^{(m+1)} = 0,\ (\forall\ i \leqslant m)$ 
		利用 $d^{(k+1)} = p^{(k+1)} - \sum\limits_{j=0}^{k} \dfrac{d^{(j)T} Q p^{(k+1)}}{d^{(j)T} Q d^{(j)}} d^{(j)}$，对任意 $i \leqslant m$，由归纳假设得
		$$
		\begin{aligned}
		d^{(i)T} Q d^{(m+1)} &= d^{(i)T} Q p^{(m+1)} - \sum_{j=0}^{m} \frac{d^{(j)T} Q p^{(m+1)}}{d^{(j)T} Q d^{(j)}} d^{(i)T} Q d^{(j)} \\
		&= d^{(i)T} Q p^{(m+1)} - \frac{d^{(i)T} Q p^{(m+1)}}{d^{(i)T} Q d^{(i)}} d^{(i)T} Q d^{(i)} = 0
		\end{aligned}
		$$
		即 $d^{(i)T} Q d^{(k)} = 0,\ (\forall\ i < k)$ 对 $k = m + 1$ 成立
		由归纳原理，定理得证！
	- 该定理说明：**算法 5.1** 产生的方向序列 $\{d^{(j)}\}_{j=0}^{n-1}$ 关于矩阵 $Q$ 相互共轭
- **定理 5.1.4**：采用精确线性搜索的 Broyden 族算法用于求解凸二次函数极小化问题 $\min f(x) = \dfrac{1}{2} x^T Q x + q^T x$ 时具有如下性质：$B_{i+1} s^{(j)} = y^{(j)} = Q s^{(j)},\ (j \leqslant i, \, i = 0, 1, \cdots, n-1)$，$s^{(i)T} Q s^{(j)} = 0,\ (j < i, \, i = 1, 2, \cdots, n-1)$，特别地，$B_n = Q,\ x^{(n)} = x^* = -Q^{-1} q$ 
	- *证明过程* 
		由**定理 4.2.1**，采用精确线性搜索的 Broyden 族算法产生相同的点列，故不同算法产生的搜索方向平行。因此我们只需证明等式 $B_{i+1} s^{(j)} = y^{(j)} = Q s^{(j)},\ (j \leqslant i, \, i = 0, 1, \cdots, n-1)$ 和 $s^{(i)T} Q s^{(j)} = 0,\ (j < i, \, i = 1, 2, \cdots, n-1)$ 对 BFGS 算法成立
		由拟 Newton 方程以及 $y^{(j)}$ 的定义可得：对任何 $j = 0, 1, \cdots, n-1$，$B_{i+1} s^{(j)} = y^{(j)} = \nabla f(x^{(j+1)}) - \nabla f(x^{(j)}) = Q(x^{(j+1)} - x^{(j)}) = Q s^{(j)}$ 
		而且由精确线性搜索得：对任何 $i = 0, 1, \cdots, n-1$，$s^{(i+1)T} Q s^{(i)} = s^{(i+1)T} y^{(i)} = s^{(i+1)T} B_{i+1} s^{(i)} = -\alpha_{i+1} \alpha_i \nabla f(x^{(i+1)})^T d^{(i)} = 0\quad (temp)$ 
		下面，我们用归纳法证明 $B_{i+1} s^{(j)} = y^{(j)} = Q s^{(j)} \quad (1)$ 和 $s^{(i)T} Q s^{(j)} = 0 \quad (2)$ 对 BFGS 算法成立
		先证明 $(1)$ 对 $i = 0$ 和 $i = 1$ 成立，以及 $(2)$ 对 $i = 1$ 成立。
		事实上，$(temp)$ 包含了 $(2)$ 对 $i = 1$ 成立。
		由拟 Newton 方程 $B_{k+1} s^{(k)} = y^{(k)}$ 知，结论 $(1)$ 对 $i = 0$ 成立。
		而且当 $i = 1$ 时，有 $B_2 s^{(1)} = y^{(1)}$。又由 BFGS 公式 $B_{k+1} = B_k - \dfrac{B_k s^{(k)} s^{(k)\mathrm{T}} B_k}{s^{(k)\mathrm{T}} B_k s^{(k)}} + \dfrac{y^{(k)} y^{(k)\mathrm{T}}}{y^{(k)\mathrm{T}} s^{(k)}}$ 以及 $(temp)$ 得
		$$
		\begin{aligned}
		B_2 s^{(0)} &= B_1 s^{(0)} - \frac{B_1 s^{(1)}(s^{(1)T} B_1 s^{(0)})}{s^{(1)T} B_1 s^{(1)}} + \frac{y^{(1)}(y^{(1)T} s^{(0)})}{y^{(1)T} s^{(1)}} \\
		&= y^{(0)} - \frac{B_1 s^{(1)}(s^{(1)T} Q s^{(0)})}{s^{(1)T} B_1 s^{(1)}} + \frac{y^{(1)}(s^{(1)T} Q s^{(0)})}{y^{(1)T} s^{(1)}} = y^{(0)}
		\end{aligned}
		$$
		上面证明了 $(1)$ 对 $i = 0$ 和 $i = 1$ 成立，以及 $(2)$ 对 $i = 1$ 成立
		设 $(1)$ 和 $(2)$ 对 $i$ 成立，我们证明 $(1)$ 和 $(2)$ 对 $i + 1$ 也成立。
		由 $(temp)$ 知 $s^{(i+1)T} Q s^{(i)} = 0$。而当 $j = 0, 1, \cdots, i - 1$ 时，
		$$
		\begin{aligned}
		s^{(i+1)T} Q s^{(j)} &= s^{(i+1)T} B_{i+1} s^{(j)} = -\alpha_{i+1} \nabla f(x^{(i+1)})^T s^{(j)} \\
		&= -\alpha_{i+1} \left[ y^{(i)} + y^{(i-1)} + \cdots + y^{(j+1)} + \nabla f(x^{(i+1)}) \right]^T s^{(j)} \\
		&= -\alpha_{i+1} \left[ Q s^{(i)} + Q s^{(i-1)} + \cdots + Q s^{(j+1)} + \nabla f(x^{(i+1)}
		\right]^T s^{(j)} = 0
		\end{aligned}
		$$
		因此，$(2)$ 对 $i + 1$ 成立
		下面证明 $(1)$ 对 $i + 1$ 也成立，即 $B_{i+2} s^{(j)} = y^{(j)} = Q s^{(j)},\ (j = 0, 1, \cdots, i + 1)$ 
		当 $j = i + 1$ 时，上式由拟 Newton 方程 $B_{k+1} s^{(k)} = y^{(k)}$ 直接得到。
		当 $j \leqslant i$ 时，由归纳假设得
		$$
		\begin{aligned}
		B_{i+2} s^{(j)} &= B_{i+1} s^{(j)} - \frac{B_{i+1} s^{(i+1)}(s^{(i+1)T} B_{i+1} s^{(j)})}{s^{(i+1)T} B_{i+1} s^{(i+1)}} + \frac{y^{(i+1)}(y^{(i+1)T} s^{(j)})}{y^{(i+1)T} s^{(i+1)}} \\
		&= B_{i+1} s^{(j)} - \frac{B_{i+1} s^{(i+1)}(s^{(i+1)T} Q s^{(j)})}{s^{(i+1)T} B_{i+1} s^{(i+1)}} + \frac{y^{(i+1)}(s^{(i+1)T} Q s^{(j)})}{y^{(i+1)T} s^{(i+1)}} \\
		&= B_{i+1} s^{(j)} = y^{(j)} = Q s^{(j)}
		\end{aligned}
		$$
		即 $(1)$ 对 $i + 1$ 成立。
		由于 $s^{(i)} \ (i = 0, 1, \cdots, n - 1)$ 关于 $Q$ 相互共轭，故线性无关。
		因此，在 $(1)$ 中令 $i = n - 1$ 即得 $Q = B_n$。
		注意到 $s^{(i)} = \alpha_i d^{(i)}$，因此 $(2)$ 等价于 $d^{(i)T} Q d^{(j)} = 0,\ (j = 0, 1, \cdots, i - 1)$，即向量组 $d^{(i)} \ (i = 0, 1, \cdots, n - 1)$ 关于 $Q$ 相互共轭。
		从而，$x^{(n)}$ 可看成是由共轭方向法经 $n$ 步精确线性搜索产生。
		因此，结论 $x^{(n)} = x^*$ 可由**定理 5.1.2** 直接得到。
		证毕！
	- 该定理表明：采用精确线性搜索的 Broyden 族算法用于求解问题 $\min f(x) = \dfrac{1}{2} x^T Q x + q^T x$ 时产生的方向 $\{d^{(k)}\}_{k=0}^{n-1}$ 关于矩阵 $Q$ 相互共轭。因此，算法具有二次终止性。
## 5-2 非线性共轭梯度法
- **非线性共轭梯度法**：求解一般无约束问题 $\min f(x),\ (x \in \mathbb{R}^n)$ 的**非线性共轭梯度法**是在求解二次函数极小值问题的共轭梯度法的基础上发展起来的。
- *非线性共轭梯度法的理论基础* 
	非线性共轭梯度法利用负梯度方向 $-\nabla f(x^{(k)})$ 与算法的前一个方向的线性组合作为第 $k$ 次迭代的搜索方向，且取初始方向为 $-\nabla f(x^{(0)})$，即 $d^{(k)} = \begin{cases}  -\nabla f(x^{(0)}), & \text{若 } k = 0, \\ -\nabla f(x^{(k)}) + \beta_k d^{(k-1)}, & \text{若 } k \geqslant 1  \end{cases}$，其中参数 $\beta_k$ 的确定使得算法用于求解问题 $\min f(x) = \dfrac{1}{2} x^T Q x + q^T x$ 时，$d^{(k)}$ 与 $d^{(k-1)}$ 关于 $Q$ 相互共轭。
	下面导出参数 $\beta_k$ 的计算公式。
	设 $f$ 是由 $\min f(x) = \dfrac{1}{2} x^T Q x + q^T x$ 定义的二次函数，点列 $\{x^{(k)}\}$ 由下面的迭代格式确定：$x^{(k+1)} = x^{(k)} + \alpha_k d^{(k)},\ (k = 0, 1, \cdots)$ 
	其中 $\alpha_k$ 由精确线性搜索得到，即 $\alpha_k = -\dfrac{\nabla f(x^{(k)})^T d^{(k)}}{d^{(k)T} Q d^{(k)}}$ 
	注意到 $\nabla f(x^{(k)}) - \nabla f(x^{(k-1)}) = Q(x^{(k)} - x^{(k-1)}) = \alpha_{k-1} Q d^{(k-1)}$ 
	由 $d^{(k)} = \begin{cases}  -\nabla f(x^{(0)}), & \text{若 } k = 0, \\ -\nabla f(x^{(k)}) + \beta_k d^{(k-1)}, & \text{若 } k \geqslant 1  \end{cases}$ 以及 $d^{(k-1)T} Q d^{(k-1)} = 0$ 可得 $\beta_k = \dfrac{\nabla f(x^{(k)})^T Q d^{(k-1)}}{d^{(k-1)T} Q d^{(k-1)}} = \dfrac{\nabla f(x^{(k)})^T [\nabla f(x^{(k)}) - \nabla f(x^{(k-1)})]}{d^{(k-1)T} [\nabla f(x^{(k)}) - \nabla f(x^{(k-1)})]}$ 
	上面的公式由 Hestenes-Stiefel 提出。我们记上面的 $\beta_k$ 为 $\beta_k^{\text{HS}}$，即 $\beta_k^{\text{HS}} = \dfrac{\nabla f(x^{(k)})^T [\nabla f(x^{(k)}) - \nabla f(x^{(k-1)})]}{d^{(k-1)T} [\nabla f(x^{(k)}) - \nabla f(x^{(k-1)})]},\ (k = 1, 2, \cdots)$ 
	在此基础上，我们给出共轭梯度法的计算步骤如下
- **算法 5.2** (**非线性共轭梯度法——HS算法**)
	- *第 1 步*：取初始点 $x^{(0)} \in \mathbb{R}^n$，$d^{(0)} = -\nabla f(x^{(0)})$，精度 $\varepsilon > 0$，令 $k := 0$ 
	- *第 2 步*：若 $\|\nabla f(x^{(k)})\| \leqslant \varepsilon$，则算法终止，得问题的解 $x^{(k)}$。否则，转*第 3 步* 
	- *第 3 步*：由线性搜索确定步长 $\alpha_k$ 
	- *第 4 步*：令 $x^{(k+1)} = x^{(k)} + \alpha_k d^{(k)}$ 
	- *第 5 步*：由 $d^{(k)} = \begin{cases}  -\nabla f(x^{(0)}), & \text{若 } k = 0 \\ -\nabla f(x^{(k)}) + \beta_k d^{(k-1)}, & \text{若 } k \geqslant 1  \end{cases}$ 确定 $d^{(k+1)}$，其中 $\beta_k = \beta_k^{\text{HS}}$。令 $k := k + 1$，转*第 2 步* 
- *注意*：当 HS 算法用于求解严格凸二次函数极小化问题时具有有限步终止性

事实上，下面的定理表明，当用于严格凸二次函数极小化问题的求解时，HS 算法产生的方向关于目标函数的Hessian矩阵相互共轭。
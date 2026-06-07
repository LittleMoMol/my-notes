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
- **定理 5.2.1**：设 $\{ x^{(k)}\}$ 表示由采用精确线性搜索的 HS 算法求解问题 $\min f(x) = \dfrac{1}{2} x^T Q x + q^T x$ 产生的点列。则向量组 $\{d^{(i)}\}_{i=0}^{n-1}$ 关于 $Q$ 相互共轭。而且，对任何 $k\le n$，有 $\nabla f(x^{(k)})^T d^{(j)} = 0,\ \nabla f(x^{(k)})^T \nabla f(x^{(j)}) = 0,\ (\forall\ j<k)$ 
	- *证明过程* 
		对 $k$ 用归纳法。$k = 1$ 时，由 $\beta_k^{\text{HS}}$ 和 $d^{(0)}$ 的定义及线性搜索条件，定理成立。
		设定理对 $k$ 成立，即 $d^{(i)} \ (i = 0, 1, \cdots, k)$ 关于 $Q$ 相互共轭且 $\nabla f(x^{(k)})^T d^{(j)} = 0,\ \nabla f(x^{(k)})^T \nabla f(x^{(j)}) = 0,\ (\forall\ j<k)$ 对 $k$ 成立。下证定理对 $k + 1$ 成立，即 $d^{(i)} \ (i = 0, 1, \cdots, k + 1)$ 关于 $Q$ 相互共轭且 $\nabla f(x^{(k)})^T d^{(j)} = 0,\ \nabla f(x^{(k)})^T \nabla f(x^{(j)}) = 0,\ (\forall\ j<k)$ 对 $k + 1$ 成立
		由于 $d^{(i)} \ (i = 0, 1, \cdots, k)$ 关于 $Q$ 相互共轭，类似于定理 5.1.2 中 $\nabla f(x^{(k+1)})^\top d^{(i)} = 0,\ (\forall\ i = 0,1,\cdots,k)$ 可以证明 $\nabla f(x^{(k)})^T d^{(j)} = 0,\ (\forall\ j<k)$ 对 $k + 1$ 成立。
		由此及 $d^{(k)} = \begin{cases}  -\nabla f(x^{(0)}), & \text{若 } k = 0 \\ -\nabla f(x^{(k)}) + \beta_k d^{(k-1)}, & \text{若 } k \geqslant 1  \end{cases}$ 得，对任意 $j \leqslant k$，$\nabla f(x^{(k+1)})^T \nabla f(x^{(j)}) = \nabla f(x^{(k+1)})^T (-d^{(j)} + \beta_j^{\text{HS}} d^{(j-1)}) = 0$ 
		即 $\nabla f(x^{(k)})^T \nabla f(x^{(j)}) = 0,\ (\forall\ j<k)$ 对 $k + 1$ 成立
		由 $\beta_k^{\text{HS}}$ 的取法易知 $d^{(k+1)}$ 和 $d^{(k)}$ 关于 $Q$ 相互共轭，而且对任意 $j \leqslant k - 1$ 有
		$$
		\begin{aligned}
		d^{(k+1)T} Q d^{(j)} &= -\nabla f(x^{(k+1)})^T Q d^{(j)} + \beta_{k+1} d^{(k+1)T} Q d^{(j)} \\
		&= -\nabla f(x^{(k+1)})^T Q d^{(j)} \\
		&= -\alpha_j^{-1} \nabla f(x^{(k+1)})^T [\nabla f(x^{(j+1)}) - \nabla f(x^{(j)})] = 0
		\end{aligned}
		$$
		即 $d^{(i)} \ (i = 0, 1, \cdots, k + 1)$ 关于 $Q$ 相互共轭。
		由归纳原理，定理的结论成立。证毕！
	- 该定理表明：当用于严格凸二次函数极小化问题的求解时，HS 算法产生的方向关于目标函数的 Hessian 矩阵相互共轭。
	- 从该定理不难看出，采用精确线性搜索时，下面各公式中的参数值对二次函数是相等的：
		$$
		\begin{aligned}
		& \beta_k = \beta_k^{\text{HS}} \triangleq \dfrac{\nabla f(x^{(k)})^T \left[ \nabla f(x^{(k)}) - \nabla f(x^{(k-1)}) \right]}{d^{(k-1)T} \left[ \nabla f(x^{(k)}) - \nabla f(x^{(k-1)}) \right]}, \quad & Hestenes-Stiefel (1952) \\
		& \beta_k = \beta_k^{\text{FR}} \triangleq \dfrac{\left\| \nabla f(x^{(k)}) \right\|^2}{\left\| \nabla f(x^{(k-1)}) \right\|^2}, \quad & Fletcher-Reeves (1964) \\
		& \beta_k = \beta_k^{\text{PRP}} \triangleq \dfrac{\nabla f(x^{(k)})^T \left[ \nabla f(x^{(k)}) - \nabla f(x^{(k-1)}) \right]}{\left\| \nabla f(x^{(k-1)}) \right\|^2}, \quad & Polak-Ribière-Polyak (1969) \\
		& \beta_k = \beta_k^{\text{CD}} \triangleq -\dfrac{\left\| \nabla f(x^{(k)}) \right\|^2}{d^{(k-1)T} \nabla f(x^{(k-1)})}, \quad & Fletcher (1987) \\
		& \beta_k = \beta_k^{\text{DY}} \triangleq \dfrac{\left\| \nabla f(x^{(k)}) \right\|^2}{d^{(k-1)T} \left[ \nabla f(x^{(k)}) - \nabla f(x^{(k-1)}) \right]} \quad & Dai-Yuan (1995)
		\end{aligned}
		$$
- **FR 算法**、**PRP 算法**、**CD 算法**、**DY 算法**：若将**算法 5.2** 的*第 5 步*中的 $\beta_k = \beta_k^{\text{HS}}$ 改为 $\beta_k = \beta_k^{\text{FR}}$ 或 $\beta_k = \beta_k^{\text{PRP}}$ 或 $\beta_k = \beta_k^{\text{CD}}$ 或 $\beta_k = \beta_k^{\text{DY}}$，我们称相应的算法为 **FR 算法**、**PRP 算法**、**CD 算法**和 **DY 算法** 
	- 由**定理 5.2.1** 知，当用于求解凸二次函数极小化问题 $\min f(x) = \dfrac{1}{2} x^T Q x + q^T x$ 时，若采用精确线性搜索，则 FR 算法、PRP 算法、HS 算法、CD 算法以及 DY 算法等价
- **定理5.2.2**：采用精确线性搜索的**算法 5.2** 用于求解凸二次函数极小化问题 $\min f(x) = \dfrac{1}{2} x^T Q x + q^T x$ 时具有如下性质：
	(1) 算法产生的方向 $\{d^{(k)}\}_{k=0}^{n-1}$ 关于矩阵 $Q$ 相互共轭。
	(2) 若矩阵 $Q$ 只有 $r$ 个不同的特征值，则算法最多经过 $r$ 次迭代达到问题的最优解。
	(3) 设 $\lambda_{\max}$ 和 $\lambda_{\min}$ 是矩阵 $Q$ 的最大特征值和最小特征值，$\kappa = \lambda_{\max} / \lambda_{\min}$。则 $\| x^{(k)} - x^* \|_Q \leqslant 2 \left( \dfrac{\sqrt{\kappa} - 1}{\sqrt{\kappa} + 1} \right)^k \| x^{(0)} - x^* \|_Q$，其中 $\| x \|_Q = (x^T Q x)^{1/2}$ 
---
- 下面介绍非线性共轭梯度法的全局收敛性。为此，我们作如下假设。
- *假设条件* 
	(1) 水平集 $\Omega = \{ x \in \mathbb{R}^n \mid f(x) \leqslant f(x^{(0)}) \}$ 有界。  
	(2) 存在 $\Omega$ 的某个邻域 $N$，使得 $f$ 在该邻域上连续可微且 $\nabla f$ 满足 Lipschitz 条件，即存在常数 $L > 0$ 使得 $\| \nabla f(x) - \nabla f(y) \| \leqslant L \| x - y \|,\ (\forall\ x, y \in N)$ 
- **定理 5.2.3**：设*假设条件*成立，则采用精确线性搜索的 FR 算法产生的点列 $\{ x^{(k)} \}$ 满足 $\lim\limits_{k \to \infty} \inf \| \nabla f(x^{(k)}) \| = 0$ 
	- *证明过程* 
		由精确线性搜索的条件得 $\nabla f(x^{(k)})^T d^{(k-1)} = 0, \ (\forall k \geqslant 1)$ 
		从而，由 $d^{(k)} = \begin{cases}  -\nabla f(x^{(0)}), & \text{若 } k = 0 \\ -\nabla f(x^{(k)}) + \beta_k d^{(k-1)}, & \text{若 } k \geqslant 1  \end{cases}$ 得 $\nabla f(x^{(k)})^T d^{(k)} = - \| \nabla f(x^{(k)}) \|^2 < 0$ 
		即 $d^{(k)}$ 是 $f$ 在 $x^{(k)}$ 处的下降方向，而且 $\| d^{(k+1)} \|^2 = \| \nabla f(x^{(k+1)}) \|^2 + \beta_{k+1}^2 \| d^{(k)} \|^2 = \| \nabla f(x^{(k+1)}) \|^2 + \dfrac{\| \nabla f(x^{(k+1)}) \|^4}{\| \nabla f(x^{(k)}) \|^4} \| d^{(k)} \|^2$ 
		两端同除以 $\| \nabla f(x^{(k+1)}) \|^4$ 得
		$$
		\begin{aligned}
		\dfrac{\| d^{(k+1)} \|^2}{\| \nabla f(x^{(k+1)}) \|^4} &= \dfrac{1}{\| \nabla f(x^{(k+1)}) \|^2} + \dfrac{\| d^{(k)} \|^2}{\| \nabla f(x^{(k+1)}) \|^4} \\
		&= \dfrac{1}{\| \nabla f(x^{(k+1)}) \|^2} + \dfrac{1}{\| \nabla f(x^{(k)}) \|^2} + \dfrac{\| d^{(k-1)} \|^2}{\| \nabla f(x^{(k)}) \|^4} \\
		&\vdots \\
		&= \sum_{i=1}^{k+1} \dfrac{1}{\| \nabla f(x^{(i)}) \|^2} + \dfrac{\| d^{(0)} \|^2}{\| \nabla f(x^{(0)}) \|^4} = \sum_{i=0}^{k+1} \dfrac{1}{\| \nabla f(x^{(i)}) \|^2}
		\end{aligned}
		$$
		令 $\theta_k$ 表示 $d^{(k)}$ 与 $-\nabla f(x^{(k)})$ 间的夹角。
		由 $\nabla f(x^{(k)})^T d^{(k)} = - \| \nabla f(x^{(k)}) \|^2 < 0$ 可得 $\cos \theta_k = \dfrac{-\nabla f(x^{(k)})^T d^{(k)}}{\| \nabla f(x^{(k)}) \| \| d^{(k)} \|} = \dfrac{\| \nabla f(x^{(k)}) \|}{\| d^{(k)} \|}$ 
		上式代入 $\dfrac{\| d^{(k+1)} \|^2}{\| \nabla f(x^{(k+1)}) \|^4} = \sum\limits_{i=0}^{k+1} \dfrac{1}{\| \nabla f(x^{(i)}) \|^2}$ 得 $\dfrac{1}{\| \nabla f(x^{(k+1)}) \|^2 \cos^2 \theta_{k+1}} = \sum\limits_{i=0}^{k+1} \dfrac{1}{\| \nabla f(x^{(i)}) \|^2}$ 
		若 $\lim\limits_{k \to \infty} \inf \| \nabla f(x^{(k)}) \| = 0$ 不成立，则存在常数 $\eta > 0$ 使得 $\|\nabla f(x^{(k)})\| \geqslant \eta, (\forall\ k)$ 
		由上式得 $\dfrac{1}{\|\nabla f(x^{(k+1)})\|^2 \cos^2 \theta_{k+1}} \leqslant \eta^{-2}(k + 2)$，或等价地 $\|\nabla f(x^{(k+1)})\|^2 \cos^2 \theta_{k+1} \geqslant \dfrac{\eta^2}{k + 2}$ 
		因此 $\sum\limits_{k=0}^{\infty} \|\nabla f(x^{(k+1)})\|^2 \cos^2 \theta_{k+1} = +\infty$
		这与**定理 2.4.1** 矛盾．从而式 $\lim\limits_{k \to \infty} \inf \| \nabla f(x^{(k)}) \| = 0$ 成立，证毕  ！
	- 该定理为：采用精确线性搜索的 FR 算法的全局收敛性定理
- **定理 5.2.4**：设*假设条件*成立，且由采用精确线性搜索的 PRP 算法产生的点列 $\{x^{(k)}\}$ 满足 $\{x^{(k+1)} - x^{(k)}\} \to 0$，则 $\lim\limits_{k \to \infty} \inf \|\nabla f(x^{(k)})\| = 0$ 
	- 类似于上面的定理，可以建立采用精确线性搜索的 PRP 算法的全局收敛性定理，如上。
	- 当 $f$ 是一致凸函数时，上面定理中的条件 $\{x^{(k+1)} - x^{(k)}\} \to 0$ 可以去掉，即下面的定理成立
- **定理 5.2.5**：设函数 $f$ 是连续可微的一致凸函数且 $\nabla f$ Lipschitz 连续．则由采用精确线性搜索的 PRP 算法产生的点列 $\{x^{(k)}\}$ 满足 $\lim\limits_{k \to \infty} \inf \|\nabla f(x^{(k)})\| = 0$ 
---
- 下面介绍采用非精确线性搜索时 FR 算法的收敛性
- *前置分析* 
	注意到当采用精确线性搜索时，我们有 $\nabla f(x^{(k)})^T d^{(k-1)} = 0$ 
	因此，由 $d^{(k)} = \begin{cases}  -\nabla f(x^{(0)}), & \text{若 } k = 0 \\ -\nabla f(x^{(k)}) + \beta_k d^{(k-1)}, & \text{若 } k \geqslant 1  \end{cases}$ 知 $\nabla f(x^{(k)})^\top d^{(k)} = -\|\nabla f(x^{(k)})\|^2 < 0$ 
	此时，$d^{(k)}$ 是 $f$ 在 $x^{(k)}$ 处的下降方向，相应的算法为下降算法。
	当采用非精确线性搜索时，$\nabla f(x^{(k)})^T d^{(k)} = -\|\nabla f(x^{(k)})\|^2 + \beta_k \nabla f(x^{(k)})^T d^{(k-1)}$ 
	由于 $\nabla f(x^{(k)})^\top d^{(k-1)}$ 非零，此时 $d^{(k)}$ 可能不是 $f$ 在 $x^{(k)}$ 处的下降方向。
	下面的引理表明，采用强 Wolfe 线性搜索的 FR 算法也具有下降性。
- **引理 5.2.1**：设 $\{x^{(k)}\}$ 由 FR 算法产生，其中步长 $\alpha_k$ 满足强 Wolfe 线性搜索条件 $\begin{cases} f(x^{(k)} + \alpha_k d^{(k)}) \le f(x^{(k)}) + \sigma_1 \alpha_k \nabla f(x^{(k)}) d^{(k)} \\ | \nabla f(x^{(k)} + \alpha_k d^{(k)})^T d^{(k)} | \le \sigma_2 |\nabla f(x^{(k)})^T d^{(k)} | \end{cases}$ 且 $\sigma_2 \in (0, 1/2)$。则对所有的 $k$，有 $\dfrac{1 - 2\sigma_2 + \sigma_2^{k+1}}{1 - \sigma_2} \leqslant \dfrac{-\nabla f(x^{(k)})^T d^{(k)}}{\|\nabla f(x^{(k)})\|^2} \leqslant \dfrac{1 - \sigma_2^{k+1}}{1 - \sigma_2}$ 
	- *证明过程* 
		我们对 $k$ 用归纳法证明引理
		当 $k = 0$ 时，由于 $d^{(0)} = -\nabla f(x^{(0)})$，因此 $\dfrac{1 - 2\sigma_2 + \sigma_2^{k+1}}{1 - \sigma_2} \leqslant \dfrac{-\nabla f(x^{(k)})^T d^{(k)}}{\|\nabla f(x^{(k)})\|^2} \leqslant \dfrac{1 - \sigma_2^{k+1}}{1 - \sigma_2}$ 显然成立
		设 $\dfrac{1 - 2\sigma_2 + \sigma_2^{k+1}}{1 - \sigma_2} \leqslant \dfrac{-\nabla f(x^{(k)})^T d^{(k)}}{\|\nabla f(x^{(k)})\|^2} \leqslant \dfrac{1 - \sigma_2^{k+1}}{1 - \sigma_2}$ 对 $k - 1$ 成立
		由 $d^{(k)} = \begin{cases}  -\nabla f(x^{(0)}), & \text{若 } k = 0, \\ -\nabla f(x^{(k)}) + \beta_k d^{(k-1)}, & \text{若 } k \geqslant 1  \end{cases}$ 以及 $\beta_k$ 的定义得 $\dfrac{-\nabla f(x^{(k)})^T d^{(k)}}{\|\nabla f(x^{(k)})\|^2} = 1 + \dfrac{-\nabla f(x^{(k)})^T d^{(k-1)}}{\|\nabla f(x^{(k-1)})\|^2}$ 
		由归纳假设以及 $\begin{cases} f(x^{(k)} + \alpha_k d^{(k)}) \le f(x^{(k)}) + \sigma_1 \alpha_k \nabla f(x^{(k)}) d^{(k)} \\ | \nabla f(x^{(k)} + \alpha_k d^{(k)})^T d^{(k)} | \le \sigma_2 |\nabla f(x^{(k)})^T d^{(k)} | \end{cases}$ 得 $\dfrac{-\nabla f(x^{(k)})^T d^{(k)}}{\|\nabla f(x^{(k)})\|^2} \leqslant 1 + \sigma_2 \dfrac{-\nabla f(x^{(k-1)})^T d^{(k-1)}}{\|\nabla f(x^{(k-1)})\|^2} \leqslant 1 + \sigma_2 \dfrac{1 - \sigma_2^k}{1 - \sigma_2} = \dfrac{1 - \sigma_2^{k+1}}{1 - \sigma_2}$ 
		同理，$\dfrac{-\nabla f(x^{(k)})^T d^{(k)}}{\|\nabla f(x^{(k)})\|^2} \geqslant 1 - \sigma_2 \dfrac{-\nabla f(x^{(k-1)})^T d^{(k-1)}}{\|\nabla f(x^{(k-1)})\|^2} \geqslant 1 - \sigma_2 \dfrac{1 - \sigma_2^k}{1 - \sigma_2} = \dfrac{1 - 2\sigma_2 + \sigma_2^{k+1}}{1 - \sigma_2}$ 
		由归纳原理，$\dfrac{1 - 2\sigma_2 + \sigma_2^{k+1}}{1 - \sigma_2} \leqslant \dfrac{-\nabla f(x^{(k)})^T d^{(k)}}{\|\nabla f(x^{(k)})\|^2} \leqslant \dfrac{1 - \sigma_2^{k+1}}{1 - \sigma_2}$ 成立
		证毕！
	- 该引理说明：采用强 Wolfe 型线性搜索的 FR 算法产生的方向是 $f$ 在 $x^{(k)}$ 处的下降方向
- **定理 5.2.6**：设*假设条件*成立，则采用强 Wolfe 型线性搜索 $\begin{cases} f(x^{(k)} + \alpha_k d^{(k)}) \le f(x^{(k)}) + \sigma_1 \alpha_k \nabla f(x^{(k)}) d^{(k)} \\ | \nabla f(x^{(k)} + \alpha_k d^{(k)})^T d^{(k)} | \le \sigma_2 |\nabla f(x^{(k)})^T d^{(k)} | \end{cases}$ ($\sigma_2 < 1/2$) 的 FR 算法产生的点列 $\{x^{(k)}\}$ 满足 $\lim\limits_{k \to \infty} \inf \|\nabla f(x^{(k)})\| = 0$ 
	- *证明过程* 
		令 $\theta_k$ 表示 $d^{(k)}$ 与 $-\nabla f(x^{(k)})$ 间的夹角。
		由 $\dfrac{1 - 2\sigma_2 + \sigma_2^{k+1}}{1 - \sigma_2} \leqslant \dfrac{-\nabla f(x^{(k)})^T d^{(k)}}{\|\nabla f(x^{(k)})\|^2} \leqslant \dfrac{1 - \sigma_2^{k+1}}{1 - \sigma_2}$ 得  
		$$
		\begin{aligned}
		\|\nabla f(x^{(k)})\| \|d^{(k)}\| \cos \theta_k =& -\nabla f(x^{(k)})^T d^{(k)} \geqslant \frac{1 - 2\sigma_2 + \sigma_2^{k+1}}{1 - \sigma_2} \|\nabla f(x^{(k)})\|^2 \\ 
		\geqslant & \frac{1 - 2\sigma_2}{1 - \sigma_2} \|\nabla f(x^{(k)})\|^2 \triangleq \mu \|\nabla f(x^{(k)})\|^2
		\end{aligned}
		$$
		因此 $\|d^{(k)}\| \cos \theta_k \geqslant \mu \|\nabla f(x^{(k)})\|$ 
		再由 $d^{(k)} = \begin{cases}  -\nabla f(x^{(0)}), & \text{若 } k = 0 \\ -\nabla f(x^{(k)}) + \beta_k d^{(k-1)}, & \text{若 } k \geqslant 1  \end{cases}$，$\begin{cases} f(x^{(k)} + \alpha_k d^{(k)}) \le f(x^{(k)}) + \sigma_1 \alpha_k \nabla f(x^{(k)}) d^{(k)} \\ | \nabla f(x^{(k)} + \alpha_k d^{(k)})^T d^{(k)} | \le \sigma_2 |\nabla f(x^{(k)})^T d^{(k)} | \end{cases}$ 和 $\dfrac{1 - 2\sigma_2 + \sigma_2^{k+1}}{1 - \sigma_2} \leqslant \dfrac{-\nabla f(x^{(k)})^T d^{(k)}}{\|\nabla f(x^{(k)})\|^2} \leqslant \dfrac{1 - \sigma_2^{k+1}}{1 - \sigma_2}$ 得
		$$
		\begin{aligned}
		\|d^{(k+1)}\|^2 &= \|\nabla f(x^{(k+1)})\|^2 - 2\beta_{k+1}^{\text{FR}} \nabla f(x^{(k+1)})^\text{T} d^{(k)} + (\beta_{k+1}^{\text{FR}})^2 \|d^{(k)}\|^2 \\
		&\leqslant \|\nabla f(x^{(k+1)})\|^2 + 2\beta_{k+1}^{\text{FR}} |\nabla f(x^{(k+1)})^\text{T} d^{(k)}| + (\beta_{k+1}^{\text{FR}})^2 \|d^{(k)}\|^2 \\
		&\leqslant \|\nabla f(x^{(k+1)})\|^2 + 2\beta_{k+1}^{\text{FR}} \sigma_2 \|\nabla f(x^{(k)})\|^\text{T} d^{(k)} + (\beta_{k+1}^{\text{FR}})^2 \|d^{(k)}\|^2 \\
		&= \|\nabla f(x^{(k+1)})\|^2 - 2\beta_{k+1}^{\text{FR}} \sigma_2 \nabla f(x^{(k)})^\text{T} d^{(k)} + (\beta_{k+1}^{\text{FR}})^2 \|d^{(k)}\|^2 \\
		&\leqslant \|\nabla f(x^{(k+1)})\|^2 + 2\beta_{k+1}^{\text{FR}} \frac{\sigma_2}{1 - \sigma_2} \|\nabla f(x^{(k)})\|^2 + (\beta_{k+1}^{\text{FR}})^2 \|d^{(k)}\|^2 \\
		&= \|\nabla f(x^{(k+1)})\|^2 + 2\frac{\sigma_2}{1 - \sigma_2} \|\nabla f(x^{(k+1)})\|^2 + \frac{\|\nabla f(x^{(k+1)})\|^4}{\|\nabla f(x^{(k)})\|^4} \|d^{(k)}\|^2 \\
		&= \frac{1 + \sigma_2}{1 - \sigma_2} \|\nabla f(x^{(k+1)})\|^2 + \frac{\|\nabla f(x^{(k+1)})\|^4}{\|\nabla f(x^{(k)})\|^4} \|d^{(k)}\|^2
		\end{aligned}
		$$
		上式两端同除以 $\|\nabla f(x^{(k+1)})\|^4$ 得
		$$
		\begin{aligned}
		\dfrac{\|d^{(k+1)}\|^2}{\|\nabla f(x^{(k+1)})\|^4} \leqslant& \dfrac{1 + \sigma_2}{1 - \sigma_2} \cdot \dfrac{1}{\|\nabla f(x^{(k+1)})\|^2} + \dfrac{\|d^{(k)}\|^2}{\|\nabla f(x^{(k)})\|^4} \\
		\leqslant& \frac{\|d^{(0)}\|^2}{\|\nabla f(x^{(0)})\|^4} + \frac{1 + \sigma_2}{1 - \sigma_2} \sum_{i=1}^{k+1} \frac{1}{\|\nabla f(x^{(i)})\|^2} \\
		\leqslant& \frac{1 + \sigma_2}{1 - \sigma_2} \sum_{i=0}^{k+1} \frac{1}{\|\nabla f(x^{(i)})\|^2}
		\end{aligned}	
		$$
		利用 $\|d^{(k)}\| \cos \theta_k \geqslant \mu \|\nabla f(x^{(k)})\|$，类似于**定理 5.2.3** 的证明可得式 $\lim\limits_{k \to \infty} \inf \|\nabla f(x^{(k)})\| = 0$ 
		证毕！
	- 该定理建立了采用强 Wolfe 型线性搜索的 FR 算法的全局收敛性。  
## 5-3 下降共轭梯度法
### 5-3-0 前言
上一节介绍的非线性共轭梯度法的下降性依赖于算法所采用的线性搜索。
特别地，当采用 Armijo 型线性搜索时，共轭梯度法的下降性得不到保证。
本节，我们介绍几个具有下降性的共轭梯度法。
### 5-3-1 修正 FR (MFR) 算法  
- **修正 FR (MFR) 算法**的*基本过程* 
	设 $x^{(k)}$ 是当前迭代点，MFR 算法中 $d^{(k)}$ 由下面的方式确定：  
	$$
	d^{(k)} = 
	\begin{cases} 
	-\nabla f(x^{(0)}), & \text{若 } k = 0 \\[6pt]
	-(1 + \theta_k)\nabla f(x^{(k)}) + \beta_k^{\text{FR}} d^{(k-1)}, & \text{若 } k \geqslant 1 
	\end{cases}
	$$
	其中，$\beta_k^{\text{FR}}$ 由 FR 算法确定，$\theta_k = \dfrac{\nabla f(x^{(k)})^\text{T} d^{(k-1)}}{\|\nabla f(x^{(k)})\|^2} \beta_k^{\text{FR}} = \dfrac{\nabla f(x^{(k)})^\text{T} d^{(k-1)}}{\|\nabla f(x^{(k-1)})\|^2}$ 
	MFR 算法与 FR 算法的区别在于系数 $\theta_k$ 
	若 $\theta_k = 0$，则 MFR 算法与 FR 算法一致
	特别地，若采用精确线性搜索，则 $\theta_k = 0$，此时 MFR 算法与 FR 算法是同一算法
- **定理 5.3.1**：设函数 $f: \mathbb{R}^n \to \mathbb{R}$ 连续可微，则对任何 $k \geqslant 0$，由式 $d^{(k)} = \begin{cases} -\nabla f(x^{(0)}), & \text{若 } k = 0 \\ -(1 + \theta_k)\nabla f(x^{(k)}) + \beta_k^{\text{FR}} d^{(k-1)}, & \text{若 } k \geqslant 1 \end{cases}$ 确定的方向 $d^{(k)}$ 具有如下性质：  
	(1) $d^{(k)}$ 是函数 $f$ 在 $x^{(k)}$ 处的充分下降方向，而且 $\nabla f(x^{(k)})^\text{T} d^{(k)} = -\|\nabla f(x^{(k)})\|^2$ 
	(2) 若采用精确线性搜索，则 $\theta_k = 0$，此时 MFR 算法还原为 FR 算法。特别地，MFR 算法具有二次终止性
	- 该定理表明：由 MFR 算法产生的方向 $d^{(k)}$ 是函数 $f$ 在 $x^{(k)}$ 处的充分下降方向
	- 由于 $d^{(k)}$ 是函数 $f$ 在 $x^{(k)}$ 处的下降方向，因此下面的不等式对所有充分小的 $\alpha_k > 0$ 均成立：$f(x^{(k)} + \alpha_k d^{(k)}) \leqslant f(x^{(k)}) + \sigma_1 \alpha_k \nabla f(x^{(k)})^\text{T} d^{(k)} - \sigma_2 \alpha_k \|d^{(k)}\|^2$，其中 $\sigma_1 \in (0,1)$，$\sigma_2 > 0$ 为常数。
- **修正的 Armijo 型线性搜索条件**：不等式 $f(x^{(k)} + \alpha_k d^{(k)}) \leqslant f(x^{(k)}) + \sigma_1 \alpha_k \nabla f(x^{(k)})^\text{T} d^{(k)} - \sigma_2 \alpha_k \|d^{(k)}\|^2$ 与 Armijo 型线性搜索条件 $f(x^{(k)} + \alpha_k d^{(k)}) \leqslant f(x^{(k)}) + \sigma_1 \alpha_k \nabla f(x^{(k)})^{\mathrm{T}} d^{(k)}$ 的形式相似，称为**修正的 Armijo 型线性搜索条件** 
	- 满足 $f(x^{(k)} + \alpha_k d^{(k)}) \leqslant f(x^{(k)}) + \sigma_1 \alpha_k \nabla f(x^{(k)})^\text{T} d^{(k)} - \sigma_2 \alpha_k \|d^{(k)}\|^2$ 的步长 $\alpha_k$ 可采用与 Armijo 型线性搜索类似的**算法 2.3** 确定，即：给定 $\rho \in (0,1)$，令 $\alpha_k$ 是 $\{\rho^i \mid i = 0,1,\cdots\}$ 中使得 $f(x^{(k)} + \alpha_k d^{(k)}) \leqslant f(x^{(k)}) + \sigma_1 \alpha_k \nabla f(x^{(k)})^\text{T} d^{(k)} - \sigma_2 \alpha_k \|d^{(k)}\|^2$ 成立的最大者
---
- 下面我们分析 MFR 算法的全局收敛性
- *假设条件* 
	(1) 水平集 $\Omega = \{ x \in \mathbb{R}^n \mid f(x) \leqslant f(x^{(0)}) \}$ 有界。  
	(2) 存在 $\Omega$ 的某个邻域 $N$，使得 $f$ 在该邻域上连续可微且 $\nabla f$ 满足 Lipschitz 条件，即存在常数 $L > 0$ 使得 $\| \nabla f(x) - \nabla f(y) \| \leqslant L \| x - y \|,\ (\forall\ x, y \in N)$ 
- 由*假设条件*容易得到，存在正数 $\gamma_1 > 0$ 使得 $\|\nabla f(x)\| \leqslant \gamma_1,\ (\forall\ x \in \Omega)$，而且由 $\nabla f(x^{(k)})^\text{T} d^{(k)} = -\|\nabla f(x^{(k)})\|^2$ 可得 $\|\nabla f(x^{(k)})\|^2 = -\nabla f(x^{(k)})^\text{T} d^{(k)} \leqslant \|\nabla f(x^{(k)})\| \cdot \|d^{(k)}\|$，因此 $\|\nabla f(x^{(k)})\| \leqslant \|d^{(k)}\|$ 
- **引理 5.3.1**：设*假设条件*成立，则存在常数 $c_1 > 0$，使得下面的不等式成立：$\alpha_k \geqslant c_1 \dfrac{\|\nabla f(x^{(k)})\|^2}{\|d^{(k)}\|^2},\ (\forall\ k \geqslant 0)$，$\sum\limits_{k \geqslant 0} \alpha_k^2 \|d^{(k)}\|^2 < \infty,\ \sum\limits_{k \geqslant 0} \alpha_k \|\nabla f(x^{(k)})\|^2 = -\sum\limits_{k \geqslant 0} \alpha_k \nabla f(x^{(k)})^\text{T} d^{(k)} < \infty$。特别地，我们有 $\lim\limits_{k \to \infty} \alpha_k \|d^{(k)}\| = 0,\ \lim\limits_{k \to \infty} \alpha_k \|\nabla f(x^{(k)})\|^2 = 0$ 
	- *证明过程* 
		不等式 $\sum\limits_{k \geqslant 0} \alpha_k^2 \|d^{(k)}\|^2 < \infty,\ \sum\limits_{k \geqslant 0} \alpha_k \|\nabla f(x^{(k)})\|^2 = -\sum\limits_{k \geqslant 0} \alpha_k \nabla f(x^{(k)})^\text{T} d^{(k)} < \infty$ 可由 $f(x^{(k)} + \alpha_k d^{(k)}) \leqslant f(x^{(k)}) + \sigma_1 \alpha_k \nabla f(x^{(k)})^\text{T} d^{(k)} - \sigma_2 \alpha_k \|d^{(k)}\|^2$ 及*假设条件*直接推得
		$\lim\limits_{k \to \infty} \alpha_k \|d^{(k)}\| = 0,\ \lim\limits_{k \to \infty} \alpha_k \|\nabla f(x^{(k)})\|^2 = 0$ 是 $\sum\limits_{k \geqslant 0} \alpha_k^2 \|d^{(k)}\|^2 < \infty,\ \sum\limits_{k \geqslant 0} \alpha_k \|\nabla f(x^{(k)})\|^2 = -\sum\limits_{k \geqslant 0} \alpha_k \nabla f(x^{(k)})^\text{T} d^{(k)} < \infty$ 的直接推论。
		下面我们分两种情形证明 $\alpha_k \geqslant c_1 \dfrac{\|\nabla f(x^{(k)})\|^2}{\|d^{(k)}\|^2},\ (\forall\ k \geqslant 0)$ 成立。  
		*情形 1* 
		当 $\alpha_k = 1$，由于 $\|\nabla f(x^{(k)})\| \leqslant \|d^{(k)}\|$，令 $c_1 = 1$，则 $\alpha_k \geqslant c_1 \dfrac{\|\nabla f(x^{(k)})\|^2}{\|d^{(k)}\|^2},\ (\forall\ k \geqslant 0)$ 成立等式
		*情形 2* 
		当 $\alpha_k < 1$，则 $\rho^{-1}\alpha_k$ 不满足不等式 $f(x^{(k)} + \alpha_k d^{(k)}) \leqslant f(x^{(k)}) + \sigma_1 \alpha_k \nabla f(x^{(k)})^\text{T} d^{(k)} - \sigma_2 \alpha_k \|d^{(k)}\|^2$ 
		这意味着下面的不等式成立：$f(x^{(k)} + \rho^{-1}\alpha_k d^{(k)}) - f(x^{(k)}) > \sigma_1 \alpha_k \rho^{-1} \nabla f(x^{(k)})^\text{T} d^{(k)} - \sigma_2 \rho^{-2} \alpha_k^2 \|d^{(k)}\|^2$ 
		由中值定理及 Lipschitz 条件 $\| \nabla f(x) - \nabla f(y) \| \leqslant L \| x - y \|,\ (\forall\ x, y \in N)$，存在 $t_k \in (0,1)$ 使得  
		$$
		\begin{aligned}
		&f(x^{(k)} + \rho^{-1}\alpha_k d^{(k)}) - f(x^{(k)}) \\
		=& \rho^{-1}\alpha_k \nabla f(x^{(k)} + t_k \rho^{-1}\alpha_k d^{(k)})^\text{T} d^{(k)} \\
		=& \rho^{-1}\alpha_k \nabla f(x^{(k)})^\text{T} d^{(k)} + \rho^{-1}\alpha_k \left[ \nabla f(x^{(k)} + t_k \rho^{-1}\alpha_k d^{(k)}) - \nabla f(x^{(k)}) \right]^\text{T} d^{(k)} \\
		\leqslant& \rho^{-1}\alpha_k \nabla f(x^{(k)})^\text{T} d^{(k)} + L \rho^{-2} \alpha_k^2 \|d^{(k)}\|^2
		\end{aligned}
		$$
		将最后一个不等式代入 $f(x^{(k)} + \rho^{-1}\alpha_k d^{(k)}) - f(x^{(k)}) > \sigma_1 \alpha_k \rho^{-1} \nabla f(x^{(k)})^\text{T} d^{(k)} - \sigma_2 \rho^{-2} \alpha_k^2 \|d^{(k)}\|^2$，我们得到 $\alpha_k > \dfrac{(1 - \sigma_1)\rho \|\nabla f(x^{(k)})\|^2}{(L + \sigma_2)\|d^{(k)}\|^2}$ 
		令 $c_1 = \min\left\{ 1, \frac{1 - \sigma_1}{L + \sigma_2} \rho \right\}$，我们得到不等式 $\alpha_k \geqslant c_1 \dfrac{\|\nabla f(x^{(k)})\|^2}{\|d^{(k)}\|^2},\ (\forall\ k \geqslant 0)$ 
		证毕！
- **定理 5.3.2**：设**定理 5.2.2** 的条件成立，则采用线性搜索 $f(x^{(k)} + \alpha_k d^{(k)}) \leqslant f(x^{(k)}) + \sigma_1 \alpha_k \nabla f(x^{(k)})^\text{T} d^{(k)} - \sigma_2 \alpha_k \|d^{(k)}\|^2$ 的 MFR 算法产生的 $\{x^{(k)}\}$ 满足 $\lim\limits_{k \to \infty} \inf \|\nabla f(x^{(k)})\| = 0$ 
	- *证明过程* 
		为方便起见，我们简记 $\beta_k^{\text{FR}}$ 为 $\beta_k$ 
		由 $d^{(k)} = \begin{cases} -\nabla f(x^{(0)}), & \text{若 } k = 0 \\ -(1 + \theta_k)\nabla f(x^{(k)}) + \beta_k^{\text{FR}} d^{(k-1)}, & \text{若 } k \geqslant 1 \end{cases}$，我们有 $\beta_k d^{(k-1)} = d^{(k)} + (1 + \theta_k) \nabla f(x^{(k)})$ 
		上式两端取范数，利用 $\nabla f(x^{(k)})^\text{T} d^{(k)} = -\|\nabla f(x^{(k)})\|^2$ 得 
		$$
		\begin{aligned}
		\|d^{(k)}\|^2 &= \beta_k^2 \|d^{(k-1)}\|^2 - 2(1 + \theta_k) d^{(k)\text{T}} \nabla f(x^{(k)}) - (1 + \theta_k)^2 \|\nabla f(x^{(k)})\|^2 \\ 
		&= \beta_k^2 \|d^{(k-1)}\|^2 + \left[ 2(1 + \theta_k) - (1 + \theta_k)^2 \right] \|\nabla f(x^{(k)})\|^2 \\ 
		&= \beta_k^2 \|d^{(k-1)}\|^2 + (1 - \theta_k^2) \|\nabla f(x^{(k)})\|^2 \\ &\leqslant \beta_k^2 \|d^{(k-1)}\|^2 + \|\nabla f(x^{(k)})\|^2
		\end{aligned}
		$$
		类似于**定理 5.2.3** 的证明可得 $\lim\limits_{k \to \infty} \inf \|\nabla f(x^{(k)})\| = 0$，证毕！
	- 该定理给出了 MFR 方法的全局收敛性
### 5-3-2 一种三项共轭梯度法——修正 PRP (MPRP) 算法
- **修正 PRP (MPRP) 算法**的*基本思想* 
	MPRP算法中 $d^{(k)}$ 由下面的方式确定：
	$$
	d^{(k)} = 
	\begin{cases} 
	-\nabla f(x^{(0)}), & \text{若 } k = 0 \\
	-\nabla f(x^{(k)}) +\beta_k^{\text{PRP}} d^{(k-1)} - \theta_k y^{(k-1)}, & \text{若 } k \geqslant 1 
	\end{cases}
	$$
	其中，$\beta_k^{\text{PRP}}$ 由 PRP 算法确定，$y^{(k-1)} = \nabla f(x^{(k)}) - \nabla f(x^{(k-1)})$，$\theta_k = \dfrac{\nabla f(x^{(k)})^\text{T} d^{(k-1)}}{\nabla f(x^{(k)})^\text{T} y^{(k-1)}} \beta_k^{\text{PRP}} = \dfrac{\nabla f(x^{(k)})^\text{T} d^{(k-1)}}{\|\nabla f(x^{(k-1)})\|^2}$ 
	修正 PRP 算法与 PRP 算法的区别在于表达式中的第三项。
	若 $\theta_k = 0$，则 MFR 算法与 FR 算法一致。
	特别地，若采用精确线性搜索，则 $\theta_k = 0$，此时 MPRP 算法与 PRP 算法是同一算法。  
- **定理 5.3.3**：设函数 $f: \mathbb{R}^n \to \mathbb{R}$ 连续可微，则对任何 $k \geqslant 0$，由 $d^{(k)} = \begin{cases} -\nabla f(x^{(0)}), & \text{若 } k = 0 \\ -\nabla f(x^{(k)}) +\beta_k^{\text{PRP}} d^{(k-1)} - \theta_k y^{(k-1)}, & \text{若 } k  \geqslant 1 \end{cases}$ 确定的方向 $d^{(k)}$ 具有如下性质：
	(1) $d^{(k)}$ 是函数 $f$ 在 $x^{(k)}$ 处的充分下降方向，而且 $\nabla f(x^{(k)})^\text{T} d^{(k)} = -\|\nabla f(x^{(k)})\|^2$ 
	(2) 若采用精确线性搜索，则 $\theta_k = 0$，此时 MPRP 算法还原为 PRP 算法。特别地，MPRP 算法具有二次终止性。  
	- 该定理表明：由 MPRP 算法产生的方向 $d^{(k)}$ 具有 MFR 算法产生的方向同样的性质
- *假设条件* 
	(1) 水平集 $\Omega = \{ x \in \mathbb{R}^n \mid f(x) \leqslant f(x^{(0)}) \}$ 有界。  
	(2) 存在 $\Omega$ 的某个邻域 $N$，使得 $f$ 在该邻域上连续可微且 $\nabla f$ 满足 Lipschitz 条件，即存在常数 $L > 0$ 使得 $\| \nabla f(x) - \nabla f(y) \| \leqslant L \| x - y \|,\ (\forall\ x, y \in N)$ 
- **定理 5.3.4**：设*假设条件*成立，则采用线性搜索 $f(x^{(k)} + \alpha_k d^{(k)}) \leqslant f(x^{(k)}) + \sigma_1 \alpha_k \nabla f(x^{(k)})^\text{T} d^{(k)} - \sigma_2 \alpha_k \|d^{(k)}\|^2$ 的 MPRP 算法产生的 $\{x^{(k)}\}$ 满足 $\lim\limits_{k \to \infty} \inf \|\nabla f(x^{(k)})\| = 0$ 
	- 该定理为 MPRP 算法的收敛性定理
### 5-3-3 CG_Descent 算法
- **CG_Descent 算法**的*基本思想* 
	CG_Descent算法中 $d^{(k)}$ 由下面的方式确定：  
	$$
	d^{(k)} = 
	\begin{cases} 
	-\nabla f(x^{(0)}), & \text{若 } k = 0 \\
	-\nabla f(x^{(k)}) + \beta_k^{\text{HZ}^+} d^{(k-1)}, & \text{若 } k \geqslant 1 
	\end{cases}
	$$
	其中 $\beta_k^{\text{HZ}^+} = \max\{\beta_k^{\text{HZ}}, \eta_k\},\ \eta_k = \dfrac{-1}{\|d^{(k-1)}\| \min\{\eta, \|\nabla f(x^{(k-1)})\|\}}$ 
	其中 $\eta > 0$ 是常数，$s^{(k-1)} = x^{(k)} - x^{(k-1)}$，$\beta_k^{\text{HZ}} = \dfrac{1}{d^{(k-1)\text{T}} y^{(k-1)}} \left( y^{(k-1)} - 2 \dfrac{\|y^{(k-1)}\|^2}{s^{(k-1)\text{T}} y^{(k-1)}} s^{(k-1)} \right)^{\text{T}} \nabla f(x^{(k)})$ 
	容易看出，若采用精确线性搜索，则 $\beta_k^{\text{HZ}} = \beta_k^{\text{HS}}$ 
- **定理 5.3.5**：设函数 $f: \mathbb{R}^n \to \mathbb{R}$ 连续可微，则对任何 $k \geqslant 0$，由 $d^{(k)} = \begin{cases} -\nabla f(x^{(0)}), & \text{若 } k = 0 \\ -\nabla f(x^{(k)}) + \beta_k^{\text{HZ}^+} d^{(k-1)}, & \text{若 } k \geqslant 1 \end{cases}$ 确定的方向 $d^{(k)}$ 满足 $\nabla f(x^{(k)})^\text{T} d^{(k)} \leqslant - \dfrac{7}{8} \|\nabla f(x^{(k)})\|^2$ 
	- 该定理表明：不论采用何种线性搜索，由 $d^{(k)} = \begin{cases} -\nabla f(x^{(0)}), & \text{若 } k = 0 \\ -\nabla f(x^{(k)}) + \beta_k^{\text{HZ}^+} d^{(k-1)}, & \text{若 } k \geqslant 1 \end{cases}$ 产生的方向 $d^{(k)}$ 是函数 $f$ 在 $x^{(k)}$ 处的一个下降方向
	- *证明过程* 
		不等式 $\nabla f(x^{(k)})^\text{T} d^{(k)} \leqslant - \dfrac{7}{8} \|\nabla f(x^{(k)})\|^2$ 对 $k=0$ 显然成立
		对 $k \geqslant 1$，我们有 $\nabla f(x^{(k)})^\text{T} d^{(k)} = -\|\nabla f(x^{(k)})\|^2 + \beta_k^{\text{HZ}^+} \nabla f(x^{(k)})^\text{T} d^{(k-1)}$ 
		若 $\nabla f(x^{(k)})^\text{T} d^{(k-1)} \geqslant 0$ 且 $\beta_k^{\text{HZ}^+} = \eta_k < 0$，则由上式不难得到 $\nabla f(x^{(k)})^\text{T} d^{(k)} \leqslant -\|\nabla f(x^{(k)})\|^2$，此时 $\nabla f(x^{(k)})^\text{T} d^{(k)} \leqslant - \dfrac{7}{8} \|\nabla f(x^{(k)})\|^2$ 成立
		若 $\nabla f(x^{(k)})^\text{T} d^{(k-1)} \geqslant 0$ 且 $\beta_k^{\text{HZ}^+} = \beta_k^{\text{HZ}}$，我们有 $\nabla f(x^{(k)})^\text{T} d^{(k)} = -\|\nabla f(x^{(k)})\|^2 + \beta_k^{\text{HZ}} \nabla f(x^{(k)})^\text{T} d^{(k-1)}$ 
		若 $\nabla f(x^{(k)})^\text{T} d^{(k-1)} < 0$，注意到 $\beta_k^{\text{HZ}^+} \geqslant \beta_k^{\text{HZ}}$，我们有 $\nabla f(x^{(k)})^\text{T} d^{(k)} \leqslant -\|\nabla f(x^{(k)})\|^2 + \beta_k^{\text{HZ}} \nabla f(x^{(k)})^\text{T} d^{(k-1)}$ 
		因此，我们只需证明 $-\|\nabla f(x^{(k)})\|^2 + \beta_k^{\text{HZ}} \nabla f(x^{(k)})^\text{T} d^{(k-1)} \leqslant - \dfrac{7}{8} \|\nabla f(x^{(k)})\|^2$ 
		或等价地 $\beta_k^{\text{HZ}} \nabla f(x^{(k)})^\text{T} d^{(k-1)} \leqslant \dfrac{1}{8} \|\nabla f(x^{(k)})\|^2$ 
		由 $\beta_k^{\text{HZ}}$ 的定义以及不等式 $u^\text{T} v \leqslant \dfrac{1}{2}\left(\|u\|^2 + \|v\|^2\right)$ 
		可得
		$$
		\begin{aligned}
		&\beta_k^{\text{HZ}} \nabla f(x^{(k)})^\text{T} d^{(k-1)} \\
		=& \frac{\nabla f(x^{(k)})^\text{T} \left( y^{(k-1)} - 2 \frac{\|y^{(k-1)}\|^2}{d^{(k-1)\text{T}} y^{(k-1)}} d^{(k-1)} \right)}{d^{(k-1)\text{T}} y^{(k-1)}} \nabla f(x^{(k)})^\text{T} d^{(k-1)} \\
		=& \frac{\nabla f(x^{(k)})^\text{T} y^{(k-1)} \left( d^{(k-1)\text{T}} y^{(k-1)} \right) \nabla f(x^{(k)})^\text{T} d^{(k-1)}}{\left( d^{(k-1)\text{T}} y^{(k-1)} \right)^2} - 2 \frac{\|y^{(k-1)}\|^2 \left( \nabla f(x^{(k)})^\text{T} d^{(k-1)} \right)^2}{\left( d^{(k-1)\text{T}} y^{(k-1)} \right)^2} \\
		=& \frac{[\frac{1}{2} \left( d^{(k-1)\text{T}} y^{(k-1)} \right) \nabla f(x^{(k)})]^\text{T} \left[ 2 \left( \nabla f(x^{(k)})^\text{T} d^{(k-1)} \right) y^{(k-1)} \right]}{\left( d^{(k-1)\text{T}} y^{(k-1)} \right)^2} - 2 \frac{\|y^{(k-1)}\|^2 \left( \nabla f(x^{(k)})^\text{T} d^{(k-1)} \right)^2}{\left( d^{(k-1)\text{T}} y^{(k-1)} \right)^2} \\
		\leqslant& \frac{1}{8} \|\nabla f(x^{(k)})\|^2
		\end{aligned}
		$$
		即 $\beta_k^{\text{HZ}^+} \nabla f(x^{(k)})^\text{T} d^{(k-1)} \leqslant \dfrac{1}{8} \|\nabla f(x^{(k)})\|^2$ 成立。  
		证毕！
- **定理 5.3.6**：设*假设条件*成立，则采用 Wolfe-Powell 型线性搜索的 CG_Descent 算法产生的点列 $\{x^{(k)}\}$ 满足   $\lim\limits_{k \to \infty} \inf \|\nabla f(x^{(k)})\| = 0$ 
	- 该定理为 CG_Descent算法的收敛性定理
## 5-4 共轭梯度法的收敛速度
- 本节介绍采用精确线性搜索的 PRP 共轭梯度法的收敛速度估计
- *假设条件*：设函数 $f: \mathbb{R}^n \to \mathbb{R}$ 二次连续可微，由 PRP 共轭梯度法产生的点列 $\{x^{(k)}\}$ 收敛于 $x^*$ 且 $\nabla f(x^*) = 0$，$\nabla^2 f(x^*)$ 正定。
- **定理 5.4.1**：设*假设条件*成立，则存在常数 $b > 0$，$r \in (0,1)$ 使得当 $k$ 充分大时，采用精确线性搜索的 PRP 算法产生的点列 $\{x^{(k)}\}$ 满足 $\|x^{(k+1)} - x^*\| \leqslant b r^k$ 
	- *证明过程* 
		由*假设条件*，存在 $x^*$ 的邻域 $U(x^*)$ 和常数 $M \geqslant m > 0$ 使得 $m\|d\|^2 \leqslant d^T \nabla^2 f(x) d \leqslant M\|d\|^2,\ (\forall\ x \in U(x^*),\ \forall\ d \in \mathbb{R}^n)$ 
		利用中值定理，对任何 $k$，我们有 $\displaystyle \nabla f(x^{(k)}) - \nabla f(x^{(k-1)}) = \int_0^1 \nabla^2 f(x^{(k-1)} + \tau s^{(k-1)}) d\tau \cdot s^{(k-1)} \triangleq A_{k-1} s^{(k-1)}$，其中 $s^{(k-1)} = x^{(k)} - x^{(k-1)} = \alpha_{k-1} d^{(k-1)}$ 
		由此及精确线性搜索条件得
		$$
		\begin{aligned}
		\|\nabla f(x^{(k-1)})\|^2 &= -\nabla f(x^{(k-1)})^T d^{(k-1)} \\
		&= [\nabla f(x^{(k)}) - \nabla f(x^{(k-1)})]^T d^{(k-1)} \\
		&= \alpha_{k-1} d^{(k-1)T} A_{k-1} d^{(k-1)}
		\end{aligned}
		$$
		因此，当 $k$ 充分大时，我们有 $\|\nabla f(x^{(k-1)})\|^2 \geqslant m \alpha_{k-1} \|d^{(k-1)}\|^2$ 
		由 $\beta_k$ 的定义不难推得存在常数 $C > 0$ 使得 $|\beta_k^{\text{PRP}}| \leqslant C \dfrac{\|\nabla f(x^{(k)})\|}{\|d^{(k-1)}\|}$ 
		利用 $d^{(k)}$ 的定义可得 $\|d^{(k)}\| \leqslant \|\nabla f(x^{(k)})\| + |\beta_k^{\text{PRP}}| \|d^{(k-1)}\| \leqslant (1 + C)\|\nabla f(x^{(k)})\|$ 
		令 $\theta_k$ 表示 $d^{(k)}$ 与 $-\nabla f(x^{(k)})$ 间的夹角，则有 $\cos \theta_k = \dfrac{-\nabla f(x^{(k)})^\text{T} d^{(k)}}{\|\nabla f(x^{(k)})\| \|d^{(k)}\|} = \dfrac{\|\nabla f(x^{(k)})\|}{\|d^{(k)}\|} \geqslant (1 + C)^{-1}$ 
		于是，由**定理 2.5.1** 可知该定理成立！证毕！
	- 该定理为关于 PRP 算法的线性收敛性定理
	- 该定理表明了 PRP 算法至少具有线性收敛速度
- *算法改进思路* 
	为了进一步研究共轭梯度法的收敛速度，我们对算法做适当改进。
	由前面的介绍我们知道共轭梯度法具有二次终止性，即用于求解严格凸二次函数极小化问题时算法经有限次 (最多 $n$ 次) 迭代后终止于问题的最优解。
	由于一般的非线性函数 $f$ 在任何点的附近均可以用二次函数近似，因此我们可以粗略地认为，共轭梯度法经过连续 $n$ 次迭代后产生的点是 $f$ 的某个二次近似函数的一个近似解。
	基于这种观察，我们可设计重新开始共轭梯度法，即算法每经过 $n$ 次迭代后，将当前迭代点作为新的初始点重新开始共轭梯度法。
	算法的具体步骤如下
- **算法 5.3** (**$n$ 步重新开始共轭梯度法**)  
	- *第 1 步*：取初始点 $x^{(0)} \in \mathbb{R}^n$，$d^{(0)} = -\nabla f(x^{(0)})$，精度 $\varepsilon > 0$，令 $k := 0$ 
	- *第 2 步*：若 $\|\nabla f(x^{(k)})\| \leqslant \varepsilon$，则算法终止，得问题的解 $x^{(k)}$。否则，转*第 3 步* 
	- *第 3 步*：由线性搜索确定步长 $\alpha_k$ 
	- *第 4 步*：令 $x^{(k+1)} = x^{(k)} + \alpha_k d^{(k)}$ 
	- *第 5 步*：由某个共轭梯度法确定 $d^{(k+1)}$ 
	- *第 6 步*：若 $k < n$，令 $k := k + 1$，转*第 2 步*；若 $k = n$，令 $x^{(0)} := x^{(k)}$，$k := 0$，转*第 1 步* 
- *注*：类似于**定理 5.2.3** 的证明，我们可以建立 $n$ 步重新开始的 FR 算法的全局收敛性定理
- **定理 5.4.2**：设 $f: \mathbb{R}^n \to \mathbb{R}$ 是三次连续可微的一致凸函数，$\{x^{(k)}\}$ 是由采用精确线性搜索的 $n$ 步重新开始的 PRP 共轭梯度法产生的点列，则存在常数 $C > 0$ 使得 $\lim\limits_{k \to \infty} \sup \dfrac{\|x^{(k+n)} - x^*\|}{\|x^{(k)} - x^*\|^2} \leqslant C$，其中 $x^*$ 是 $f$ 的唯一极小值点。
	- 该定理描述了关于 $n$ 步重新开始共轭梯度法的收敛速度

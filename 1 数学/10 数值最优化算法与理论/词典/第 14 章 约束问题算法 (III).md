# 14 约束问题算法 (III)
## 14-0 前言
本章将求解无约束最优化问题的 Newton 法和拟 Newton 法推广到求解约束最优化问题
$$
\begin{aligned}
\min \quad & f(x) \\
\text{s.t.} \quad & g_i(x) \geqslant 0, \quad (i \in I = \{1, 2, \cdots, m_1\}) \\
& h_j(x) = 0, \quad (j \in E = \{m_1 + 1, m_1 + 2, \cdots, m\})
\end{aligned} \tag{question}
$$
假设 $f, g_i, h_j \, (i \in I, j \in E)$ 二次连续可微，记 $g_I(x) = (g_1(x), g_2(x), \cdots, g_{m_1}(x))^\mathrm{T}$，$h_E(x) = (h_{m_1+1}(x), h_{m_1+2}(x), \cdots, h_m(x))^\mathrm{T}$ 
## 14-1 局部序列二次规划算法
### 14-1-1 等式约束优化的 Lagrange-Newton 法
- **等式约束优化**的**Lagrange-Newton 法**的*理论基础*、**K-K-T 点**、**Lagrange 函数** 
	考虑等式约束最优化问题
	$$
	\begin{aligned}
	\min \quad & f(x) \\
	\text{s.t.} \quad & h_j(x) = 0, \quad j \in E = \{1, 2, \cdots, m\}
	\end{aligned} \tag{q1}
	$$
	记 $A(x) = h_E'(x)$ 为约束函数在 $x$ 点的 Jacobi 矩阵。
	设 $x^*$ 是问题 $(q1)$ 的解，并设 $A(x^*)$ 行满秩。则由约束优化的最优性条件，存在 $\lambda^* \in \mathbb{R}^m$ 使得 $(x^*, \lambda^*)$ 满足如下非线性方程 (称为问题 $(q1)$ 的 **K-K-T 点**)：$F(x, \lambda) \triangleq \begin{pmatrix} \nabla_x L(x, \lambda) \\ h_E(x) \end{pmatrix} = \begin{pmatrix} \nabla f(x) - A(x)^\mathrm{T} \lambda \\ h_E(x) \end{pmatrix} = 0$，其中 $L(x, \lambda) = f(x) - \lambda^\mathrm{T} h_E(x)$ 称为问题 $(q1)$ 的 **Lagrange 函数** 
	上面的分析表明：等式约束最优化问题 $(q1)$ 的 K-K-T 点为方程 $F(x,\lambda)=0$ 的解。因此，我们建立求解 $F(x,\lambda)=0$ 的牛顿迭代算法。
	记 $W(x, \lambda) = \nabla_x^2 L(x, \lambda)$，则函数 $F(x, \lambda)$ 的 Jacobi 矩阵为 $\begin{pmatrix} W(x, \lambda) & -A(x)^\mathrm{T} \\ A(x) & 0 \end{pmatrix}$ 
	由非线性方程的牛顿计算式 $F'(x^{(k)}) d + F(x^{(k)}) = 0$ 直接导出解 $F(x,\lambda)$ 的 Newton 迭代格式为：
	$\begin{pmatrix} x^{(k+1)} \\ \lambda^{(k+1)} \end{pmatrix} = \begin{pmatrix} x^{(k)} \\ \lambda^{(k)} \end{pmatrix} + \begin{pmatrix} d_x^{(k)} \\ d_\lambda^{(k)} \end{pmatrix} \quad (t1)$ 
	其中 $(d_x^{(k)}, d_\lambda^{(k)})$ 是线性方程组 $\begin{pmatrix} W(x^{(k)}, \lambda^{(k)}) & -A(x^{(k)})^\mathrm{T} \\ A(x^{(k)}) & 0 \end{pmatrix} \begin{pmatrix} d_x \\ d_\lambda \end{pmatrix} = - \begin{pmatrix} \nabla f(x^{(k)}) - A(x^{(k)})^\mathrm{T} \lambda^{(k)} \\ h_E(x^{(k)}) \end{pmatrix} \quad (t2)$ 的解。
	我们称由 $(t1), (t2)$ 建立的求解约束最优化问题 $(q1)$ 的算法为 **Lagrange-Newton法** 
- **定理14.1.1**：设 $f$ 和 $h_E$ 在 $x^*$ 的某邻域内三次连续可微，$A(x^*)$ 行满秩，而且在 $x^*$ 处二阶充分条件满足。则当 $(x^{(0)}, \lambda^{(0)})$ 充分靠近 $(x^*, \lambda^*)$ 时必有 $x^{(k)} \to x^*$，$\lambda^{(k)} \to \lambda^*$，且 $\left\| \begin{pmatrix} x^{(k+1)} - x^* \\ \lambda^{(k+1)} - \lambda^* \end{pmatrix} \right\| = O\left( \left\| \begin{pmatrix} x^{(k)} - x^* \\ \lambda^{(k)} - \lambda^* \end{pmatrix} \right\|^2 \right)$ 
	- *证明过程* 
		$\{x^{(k)}, \lambda^{(k)}\}$ 实际上由 Newton 法产生。
		由于 $A(x^*)$ 行满秩且二阶充分条件成立，由**定理 11.1.1** 知，矩阵 $\begin{pmatrix} W(x^*, \lambda^*) & -A(x^*)^\mathrm{T} \\ A(x^*) & 0 \end{pmatrix}$ 非奇异。
		从而，利用**定理 8.1.1** 可直接得到定理的结论。证毕！
	- 该定理为 Lagrange-Newton 法的收敛性定理
### 14-1-2 局部 SQP 算法
- **等式约束优化**的**序列 (SQP) 二次规划算法**的*理论基础*、**QP 子问题** 
	上节介绍的 Lagrange-Newton 法不易直接用于求解不等式约束优化问题。为此，我们导出 Lagrange-Newton 法的另一种计算方式。
	由约束最优化的 K-K-T 条件可推出，Lagrange-Newton 迭代式 $(t1), (t2)$ 计算的 $d^{(k)}$ 等价于解下面二次规划问题
	$$
	\begin{aligned}
	\min \quad & q_k(d) = \frac{1}{2} d^\mathrm{T} W(x^{(k)}, \lambda^{(k)}) d + \nabla_x L(x^{(k)}, \lambda^{(k)})^\mathrm{T} d \\
	\text{s.t.} \quad & A(x^{(k)}) d + h_E(x^{(k)}) = 0
	\end{aligned} \tag{q2}
	$$
	优化问题 $(q2)$ 可进一步化简。
	对问题 $(q2)$ 的任何可行点 $d$ 有 $\nabla_x L(x^{(k)}, \lambda^{(k)})^\mathrm{T} d = \nabla f(x^{(k)})^\mathrm{T} d - \lambda^{(k)\mathrm{T}} A(x^{(k)}) d = \nabla f(x^{(k)})^\mathrm{T} d + \lambda^{(k)\mathrm{T}} h_E(x^{(k)})$ 
	因此，问题 $(q2)$ 等价于如下的二次规划问题
	$$
	\begin{aligned}
	\min \quad & q_k(d) = \frac{1}{2} d^\mathrm{T} W(x^{(k)}, \lambda^{(k)}) d + \nabla f(x^{(k)})^\mathrm{T} d \\
	\text{s.t.} \quad & A(x^{(k)}) d + h_E(x^{(k)}) = 0
	\end{aligned} \tag{q3}
	$$
	直接计算得到问题 $(q3)$ 的 K-K-T 条件：$\begin{pmatrix} W(x^{(k)}, \lambda^{(k)}) & -A(x^{(k)})^\mathrm{T} \\ A(x^{(k)}) & 0 \end{pmatrix} \begin{pmatrix} d \\ \lambda^+ \end{pmatrix} = - \begin{pmatrix} \nabla f(x^{(k)}) \\ h_E(x^{(k)}) \end{pmatrix}\quad(t3)$
	比较 $(t1), (q2), (t3)$，不难发现，求解非线性方程组 $F(x,\lambda)=0$ 的 Lagrange-Newton 法可等价地叙述为：求二次规划问题 $(q3)$ 的 K-K-T 点 $(d^{(k)}, \lambda^{(k+1)})$，令 $x^{(k+1)} = x^{(k)} + d^{(k)}$，由此产生迭代序列 $\{(x^{(k)}, \lambda^{(k)})\}$。
	通过求解 $(q3)$ 产生迭代序列的方法称为解等式约束优化的**序列二次规划 (SQP) 算法**，称 $(q3)$ 为 **QP 子问题** 
- **一般约束优化问题**的**局部 Newton-SQP 算法**的*理论基础*、**严格互补松弛条件**、**局部 SQP 算法**
	类似于如上等式约束优化问题 $(q1)$ 的序列二次规划算法，我们可构造求解一般约束优化问题 $(question)$ 的序列二次规划算法。
	在当前点 $(x^{(k)}, \lambda^{(k)})$ 处，构造如下二次规划子问题：  
	$$
	\begin{aligned}
	\min \quad & q_k(d) = \frac{1}{2} d^\mathrm{T} W_k d + \nabla f(x^{(k)})^\mathrm{T} d \\
	\text{s.t.} \quad & \nabla g_{I}(x^{(k)})^\mathrm{T} d + g_{I}(x^{(k)}) \geqslant 0 \\
	& \nabla h_{E}(x^{(k)})^\mathrm{T} d + h_{E}(x^{(k)}) = 0
	\end{aligned} \tag{q4}
	$$
	解上面二次规划子问题得解 $d^{(k)}$ 及对应的乘子 $\lambda^{(k+1)}$，并产生新的迭代点 $(x^{(k+1)}, \lambda^{(k+1)})$，其中 $x^{(k+1)} = x^{(k)} + d^{(k)}$，子问题 $(q4)$ 是问题 $(question)$ 的近似二次规划。
	我们称上面的算法为求解约束问题 $(question)$ 的**局部 Newton-序列二次规划算法** (简称为**局部 Newton-SQP 算法**)
	对含有不等式约束的最优化问题 $(question)$ 的 K-K-T 点 $(x^*, \lambda^*)$，若对所有 $i \in I$，均有 $(\lambda_i^*)^2 + g_i(x^*)^2 \neq 0$，则称在该点处满足**严格互补松弛条件**。
	可以证明若在问题 $(question)$ 的解 $x^*$ 处 LICQ 成立，对应的 Lagrange 函数的 Hessian 矩阵 $W(x^*, \lambda^*)$ 在 $A(x^*)$ 的零空间上正定，且严格互补松弛条件成立，则当 $(x^{(k)}, \lambda^{(k)})$ 充分靠近 $(x^*, \lambda^*)$ 时，子问题 $(q4)$ 的有效集与 $(question)$ 的有效集一致，即问题 $(q4)$ 在 $(x^*, \lambda^*)$ 的邻域等价于某个等式约束问题。
	类似于求解无约束最优化问题的拟 Newton 法，可在 Newton-SQP 算法中用对称正定矩阵 $B_k$ 近似 $W(x^{(k)},\lambda^{(k)})$，由此建立下面二次规划子问题
	$$
	\begin{aligned}
	\min \quad & q_k(d) = \frac{1}{2}d^T B_k d + \nabla f(x^{(k)})^T d \\
	\text{s.t.} \quad & \nabla g_I(x^{(k)})^T d + g_I(x^{(k)}) \geq 0 \\
	& \nabla h_E(x^{(k)})^T d + h_E(x^{(k)}) = 0
	\end{aligned} \tag{q5}
	$$
	求解约束问题 $(q5)$ 的**局部 SQP 算法**的计算步骤如下
- **算法14.1** (局部 SQP 算法)
	- *第 0 步*：取初始点对 $(x^{(0)},\lambda^{(0)})$，对称正定阵 $B_0$，令 $k := 0$ 
	- *第 1 步*：若 $(x^{(k)},\lambda^{(k)})$ 满足约束问题 $\begin{aligned} \min \quad & q_k(d) = \frac{1}{2}d^T B_k d + \nabla f(x^{(k)})^T d \\ \text{s.t.} \quad & \nabla g_I(x^{(k)})^T d + g_I(x^{(k)}) \geq 0 \\ & \nabla h_E(x^{(k)})^T d + h_E(x^{(k)}) = 0 \end{aligned}$ 的 K-K-T 条件，则停止计算得解 $x^{(k)}$；否则转*第 2 步* 
	- *第 2 步*：解 SQP 子问题 $\begin{aligned} \min \quad & q_k(d) = \frac{1}{2} d^\mathrm{T} W_k d + \nabla f(x^{(k)})^\mathrm{T} d \\ \text{s.t.} \quad & \nabla g_{I}(x^{(k)})^\mathrm{T} d + g_{I}(x^{(k)}) \geqslant 0 \\ & \nabla h_{E}(x^{(k)})^\mathrm{T} d + h_{E}(x^{(k)}) = 0 \end{aligned} \tag{q4}$ 或 $\begin{aligned} \min \quad & q_k(d) = \frac{1}{2}d^T B_k d + \nabla f(x^{(k)})^T d \\ \text{s.t.} \quad & \nabla g_I(x^{(k)})^T d + g_I(x^{(k)}) \geq 0 \\ & \nabla h_E(x^{(k)})^T d + h_E(x^{(k)}) = 0 \end{aligned}$ 得解 $(d^{(k)},\lambda^{(k+1)})$ 
	- *第 3 步*：令 $x^{(k+1)} = x^{(k)} + d^{(k)}$，若采用 SQP 子问题 $\begin{aligned} \min \quad & q_k(d) = \frac{1}{2} d^\mathrm{T} W_k d + \nabla f(x^{(k)})^\mathrm{T} d \\ \text{s.t.} \quad & \nabla g_{I}(x^{(k)})^\mathrm{T} d + g_{I}(x^{(k)}) \geqslant 0 \\ & \nabla h_{E}(x^{(k)})^\mathrm{T} d + h_{E}(x^{(k)}) = 0 \end{aligned} \tag{q4}$，则令 $k := k + 1$ 转*第 1 步*；否则转*第 4 步* 
	- *第 4 步*：用适当的拟 Newton 法修正 $B_k$ 得 $B_{k+1}$，令 $k := k + 1$ 转*第 1 步* 
### 14-1-3 QP 子问题
- 该节考虑**局部 SQP 算法 14.1** 中的子问题 $(q5)$ 
- *具体过程*
	求解 QP 子问题的两个相关问题是矩阵 $B_k$ 的修正方式和子问题的相容性 (或称可行性)
	*第 1 部分*：对于 $B_k$ 的修正
	一方面，$B_k$ 应为 Lagrange 函数 Hessian 矩阵的近似。
	另一方面我们希望 $B_k$ 保持对称正定性，使得相应的 QP 子问题是一个严格凸二次规划问题。
	类似于求解无约束问题的拟Newton法，令
	$$
	\begin{aligned}
	s^{(k)} &= x^{(k+1)} - x^{(k)}, \quad y^{(k)} = \nabla_x L(x^{(k+1)}, \lambda^{(k+1)}) - \nabla_x L(x^{(k)}, \lambda^{(k+1)}) \\
	&\approx W(x^{(k+1)}, \lambda^{(k+1)}) s^{(k)}
	\end{aligned}
	$$
	然后利用 BFGS 修正公式 $B_{k+1} = B_k - \dfrac{B_k s^{(k)} s^{(k)\mathrm{T}} B_k}{s^{(k)\mathrm{T}} B_k s^{(k)}} + \dfrac{y^{(k)} y^{(k)\mathrm{T}}}{y^{(k)\mathrm{T}} s^{(k)}}$ 计算 $B_{k+1}$ 
	与无约束问题不同的是这种修正不能保证条件 $y^{(k)T} s^{(k)} > 0$ 成立。因此，$B_k$ 对称正定不能保证 $B_{k+1}$ 的正定性。
	为了克服此困难，Powell 利用 $y^{(k)}$ 和 $s^{(k)}$ 的一个凸组合代替 $y^{(k)}$，记为 $\bar{y}^{(k)} =  \begin{cases} y^{(k)}, & \text{如果 } y^{(k)T} s^{(k)} \geq 0.2 s^{(k)T} B_k s^{(k)} \\ \theta_k y^{(k)} + (1 - \theta_k) B_k s^{(k)}, & \text{其他} \end{cases}$，其中 $\theta_k = \dfrac{0.8 s^{(k)T} B_k s^{(k)}}{s^{(k)T} B_k s^{(k)} - y^{(k)T} s^{(k)}}$ 
	修正后的BFGS计算式为 $B_{k+1} = B_k - \dfrac{B_k s^{(k)} s^{(k)T} B_k}{s^{(k)T} B_k s^{(k)}} + \dfrac{\bar{y}^{(k)} \bar{y}^{(k)T}}{\bar{y}^{(k)T} s^{(k)}}$ 
	容易验证，若 $B_k$ 对称正定，则 $\bar{y}^{(k)T} s^{(k)} > 0$，从而 $B_{k+1}$ 正定。我们称这种修正方法为**截断 BFGS 修正** 
	*第 2 部分*：QP 子问题的相容性
	如果初始点取得不恰当，即使原问题可行，也可导致子问题不相容。
	例如：对于约束 $\begin{cases} g_1(x) = -x + 1 \geq 0 \\ g_2(x) = x^2 \geq 0 \end{cases}$，在点 $x=3$ 处，其线性化约束 $\begin{cases} -2 - d \geq 0 \\ 9 + 6d \geq 0 \end{cases}$ 不相容。
	Powell 提出的方法较好地解决了这一问题。
	引进辅助变量 $\xi$，首先解一个线性规划问题
	$$
	\begin{aligned}
	\max \quad & \xi \\
	\text{s.t.} \quad & \nabla g_i(x^{(k)})^T d + \xi g_i(x^{(k)}) \geq 0, \quad (i \in V_k = \{i \in I \mid g_i(x^{(k)}) < 0\}) \\
	& \nabla g_i(x^{(k)})^T d + g_i(x^{(k)}) \geq 0, \quad (i \in S_k = \{i \in I \mid g_i(x^{(k)}) \geq 0\}) \\
	& \nabla h_j(x^{(k)})^T d + \xi h_j(x^{(k)}) = 0, \quad (j \in E) \\
	& 0 \leq \xi \leq 1
	\end{aligned} \tag{temp}
	$$
	因 $\xi=0, d=0$ 为该线性规划问题的可行点，故 $(temp)$ 的最优解总是存在的，记为 $\bar{\xi}$。
	显然有 $0 \leq \bar{\xi} \leq 1$，且原子问题 $(q5)$ 相容 $\iff$ $\bar{\xi} = 1$ 
	若 $\bar{\xi} = 0$ 或很小，则改变初始点重新开始。若 $\bar{\xi} > 0$，我们将子问题 $(q5)$ 中的约束条件用 $(temp)$ 中的约束条件代替，即 SQP 子问题取为
	$$
	\begin{aligned}
	\min \quad & q_k(d) = \frac{1}{2} d^T B_k d + \nabla f(x^{(k)})^T d \\
	\text{s.t.} \quad & \nabla g_i(x^{(k)})^T d + \xi g_i(x^{(k)}) \geq 0, \quad (i \in V_k = \{i \in I \mid g_i(x^{(k)}) < 0\}) \\
	& \nabla g_i(x^{(k)})^T d + g_i(x^{(k)}) \geq 0, \quad (i \in S_k = \{i \in I \mid g_i(x^{(k)}) \geq 0\}) \\
	& \nabla h_j(x^{(k)})^T d + \xi h_j(x^{(k)}) = 0, \quad (j \in E)
	\end{aligned} \tag{q6}
	$$
	其中 $\xi$ 取为 $(0, \bar{\xi}]$ 中的一个定值。  
- *例子* 
	我们考察约束 $\begin{cases} g_1(x) = -x + 1 \geq 0 \\ g_2(x) = x^2 \geq 0 \end{cases}$，在点 $x=3$ 处建立的式 $(temp)$ 为如下线性规划：  
	$$
	\begin{aligned}
	\max \quad & \xi \\
	\text{s.t.} \quad & -d - 2\xi \geq 0 \\
	& 6d + 9 \geq 0 \\
	& 0 \leq \xi \leq 1
	\end{aligned}
	$$
	其最优解为 $\bar{\xi} = 3/4$。若取 $\xi = 1/2$，则 $\xi \in (0, \bar{\xi}]$，且对应的 SQP 子问题 $(q6)$ 相容。  
### 14-1-4 局部 SQP 算法的超线性收敛性
- *假设条件* 
	(1) $f(x),\ g_I(x),\ h_E(x)$ 二次连续可微
	(2) $\hat{x}^{(k)} \to x^*\ (k \to \infty)$，且 $x^*$ 为问题 $(question)$ 的 K-K-T 点
	(3) 在 $x^*$ 处 LICQ 成立，即向量组 $\nabla g_i(x^*),\ \nabla h_j(x^*),\ (i \in I(x^*),\ j \in E)$ 线性无关
	(4) 在 $x^*$ 点处二阶充分条件成立
	(5) 当 $x^{(k)}$ 充分靠近 $x^*$ 时，子问题 $\begin{aligned} \min \quad & q_k(d) = \frac{1}{2}d^T B_k d + \nabla f(x^{(k)})^T d \\ \text{s.t.} \quad & \nabla g_I(x^{(k)})^T d + g_I(x^{(k)}) \geq 0 \\ & \nabla h_E(x^{(k)})^T d + h_E(x^{(k)}) = 0 \end{aligned}\ (q5)$ 的解 $d^{(k)}$ 也是如下等式约束二次规划问题的解：$\begin{aligned} \min \quad & \nabla f(x^{(k)})^\mathrm{T} d + \frac{1}{2} d^\mathrm{T} B_k d \\ \text{s.t.} \quad & \nabla g_i(x^{(k)})^\mathrm{T} d + g_i(x^{(k)}) = 0, \quad (i \in I(x^*)) \\ & \nabla h_j(x^{(k)})^\mathrm{T} d + h_j(x^{(k)}) = 0, \quad (j \in E) \end{aligned}$ 
- **定理 14.1.2**：设*假设条件*成立，则 $\{x^{(k)}\}$ 超线性收敛的充要条件为 $\lim\limits_{k \to \infty} \dfrac{\left\| P_k \left[ B_k - W(x^*, \lambda^*) \right] d^{(k)} \right\|}{\left\| d^{(k)} \right\|} = 0$，其中 $P_k$ 是到 $A(x^{(k)})^\mathrm{T} = \left( \nabla g_{I(x^{(k)})}(x^{(k)})^\mathrm{T},\, \nabla h_E(x^{(k)})^\mathrm{T} \right)$ 零空间上的投影算子 $P_k = I - A(x^{(k)})^\mathrm{T} \left[ A(x^{(k)}) A(x^{(k)})^\mathrm{T} \right]^{-1} A(x^{(k)})$ 
	- 该定理建立了 $d^{(k)}$ 是超线性收敛步的等价条件
## 14-2 全局 SQP算法
- **效益函数**：全局化方法需要选择一个函数作为算法下降性的检测，以便在线搜索算法中控制搜索步长以及在信赖域算法中调节信赖域半径。我们称这种函数为**效益函数** 
	- 在求解无约束问题的算法中，自然的选择是目标函数本身
- **$l_1$ 精确罚函数**、**罚因子**：在约束最优化中，需建立一种既含目标函数信息又包含约束条件信息的函数。SQP 算法中常用的一类效益函数为 **$l_1$ 精确罚函数**，定义为 $\begin{aligned} \Phi_1(x, \mu) &= f(x) + \mu \left\| \min\{g_I(x), 0\} \right\|_1 + \left\| h_E(x) \right\|_1 \\ &= f(x) + \mu \sum_{i \in I} \left| \min\{g_i(x), 0\} \right| + \sum_{j \in E} \left| h_j(x) \right| \end{aligned}$，其中 $\mu$ 称为**罚因子** 
- **引理 14.2.1** 
	设 $(d^{(k)}, \lambda^{(k+1)})$ 是子问题 $(q5)$ 的解。则 $l_1$ 罚函数 $\Phi_1(x^{(k)}, \mu)$ 沿 $d^{(k)}$ 方向的方向导数满足
	$$
	\begin{aligned}
	& D(\Phi_1(x^{(k)}, \mu); d^{(k)}) \\
	\leqslant & - (d^{(k)})^\mathrm{T} B_k d^{(k)} - \mu \left[ \left\| \min\{g_I(x^{(k)}), 0\} \right\|_1 + \left\| h_E(x^{(k)}) \right\|_1 \right] \\
	&- (\lambda_I^{(k+1)})^\mathrm{T} g_I(x^{(k)})  - (\lambda_E^{(k+1)})^\mathrm{T} h_E(x^{(k)})
	\end{aligned}
	$$
	进一步，若 $(d^{(k)})^\mathrm{T} B_k d^{(k)} > 0$ 且 $\mu \geqslant \left\| \lambda^{(k+1)} \right\|_\infty$，则 $d^{(k)}$ 是 $l_1$ 精确罚函数在 $x^{(k)}$ 处的下降方向。
	- *证明过程* 
		利用中值定理得，对任何 $t > 0$, $(i \in I)$ 有
		$$
		\begin{aligned}
		&\min\{g_i(x^{(k)} + t d^{(k)}), 0\} = \min\{g_i(x^{(k)}) + t \nabla g_i(x^{(k)})^\mathrm{T} d^{(k)}, 0\} + o(t) \\
		=& \min\{(1 - t)g_i(x^{(k)}) + t(g_i(x^{(k)}) + \nabla g_i(x^{(k)})^\mathrm{T} d^{(k)}), 0\} + o(t) \\
		\geqslant& (1 - t) \min\{g_i(x^{(k)}), 0\} + t \min\{g_i(x^{(k)}) + \nabla g_i(x^{(k)})^\mathrm{T} d^{(k)}, 0\} + o(t) \\
		=& (1 - t) \min\{g_i(x^{(k)}), 0\} + o(t)
		\end{aligned}
		$$
		同理，对任何 $t > 0$, $(j \in E)$ 有 $h_j(x^{(k)} + t d^{(k)}) = h_j(x^{(k)}) + t \nabla h_j(x^{(k)})^\mathrm{T} d^{(k)} + o(t) = (1 - t) h_j(x^{(k)}) + o(t)$ 
		因此
		$$
		\begin{aligned}
		&\|\min\{g_I(x^{(k)} + t d^{(k)}), 0\}\|_1 - \|\min\{g_I(x^{(k)}), 0\}\|_1 + \|h_E(x^{(k)} + t d^{(k)})\|_1 - \|h_E(x^{(k)})\|_1 \\
		=& \sum_{i \in I} \left( |\min\{g_i(x^{(k)} + t d^{(k)}), 0\}| - |\min\{g_i(x^{(k)}), 0\}| \right) \\
		&+ \sum_{j \in E} \left( |h_j(x^{(k)} + t d^{(k)})| - |h_j(x^{(k)})| \right) \\
		=& \sum_{i \in I} \left( -\min\{g_i(x^{(k)} + t d^{(k)}), 0\} + \min\{g_i(x^{(k)}), 0\} \right) \\
		&+ \sum_{j \in E} \left( |(1 - t)h_j(x^{(k)})| - |h_j(x^{(k)})| \right) + o(t) \\
		\leqslant& t \left( \sum_{i \in I} \min\{g_i(x^{(k)}), 0\} - \sum_{j \in E} |h_j(x^{(k)})| \right) + o(t) \\
		=& -t \left( \|\min\{g_I(x^{(k)}), 0\}\|_1 + \|h_E(x^{(k)})\|_1 \right) + o(t)
		\end{aligned}
		$$
		故得
		$$
		\begin{aligned}
		&D(\Phi_1(x^{(k)}, \mu); d^{(k)}) \\
		=& \lim_{t \to 0^+} \frac{\Phi_1(x^{(k)} + t d^{(k)}, \mu) - \Phi_1(x^{(k)}, \mu)}{t} \\
		=& \nabla f(x^{(k)})^\mathrm{T} d^{(k)} + \mu \lim_{t \to 0^+} t^{-1} \left( \|\min\{g_I(x^{(k)} + t d^{(k)}), 0\}\|_1 \right. \\
		&- \|\min\{g_I(x^{(k)}), 0\}\|_1 + \|h_E(x^{(k)} + t d^{(k)})\|_1 - \|h_E(x^{(k)})\|_1 \bigg) \\
		\leqslant & \nabla f(x^{(k)})^\mathrm{T} d^{(k)} - \mu \left( \|\min\{g_I(x^{(k)}), 0\}\|_1 + \|h_E(x^{(k)})\|_1 \right)
		\end{aligned}
		\tag{temp}
		$$
		再利用 $(q5)$ 的 K-K-T 条件得
		$$
		\begin{aligned}
		\nabla f(x^{(k)})^\mathrm{T} d^{(k)} &= - (d^{(k)})^\mathrm{T} B_k d^{(k)} + (\lambda_I^{(k+1)})^\mathrm{T} \nabla g_I(x^{(k)})^\mathrm{T} d^{(k)} + (\lambda_E^{(k+1)})^\mathrm{T} \nabla h_E(x^{(k)})^\mathrm{T} d^{(k)} \\
		\lambda_i^{(k+1)} &\geqslant 0, \quad \lambda_i^{(k+1)} \left[ (\nabla g_i(x^{(k)})^\mathrm{T} d^{(k)} + g_i(x^{(k)}) \right] = 0, \quad (i \in I)
		\end{aligned}
		$$
		由于 $d^{(k)}$ 满足 $(q5)$，故上面两式包含了 $\nabla f(x^{(k)})^\mathrm{T} d^{(k)} = - (d^{(k)})^\mathrm{T} B_k d^{(k)} - (\lambda_I^{(k+1)})^\mathrm{T} g_I(x^{(k)}) - (\lambda_E^{(k+1)})^\mathrm{T} h_E(x^{(k)})$ 
		上式代入到 $(temp)$ 即得结论
		$$
		\begin{aligned}
		& D(\Phi_1(x^{(k)}, \mu); d^{(k)}) \\
		\leqslant & - (d^{(k)})^\mathrm{T} B_k d^{(k)} - \mu \left[ \left\| \min\{g_I(x^{(k)}), 0\} \right\|_1 + \left\| h_E(x^{(k)}) \right\|_1 \right] \\
		&- (\lambda_I^{(k+1)})^\mathrm{T} g_I(x^{(k)})  - (\lambda_E^{(k+1)})^\mathrm{T} h_E(x^{(k)})
		\end{aligned} \tag{temp'}
		$$
		注意到 $\lambda_i^{(k+1)} \geqslant 0 \, (\forall i \in I)$，因此
		$$
		\begin{aligned}
		&- (\lambda_I^{(k+1)})^\mathrm{T} g_I(x^{(k)}) - (\lambda_E^{(k+1)})^\mathrm{T} h_E(x^{(k)}) \\
		&= - \sum_{i \in I} \lambda_i^{(k+1)} g_i(x^{(k)}) - \sum_{j \in E} \lambda_j^{(k+1)} h_j(x^{(k)}) \\
		&\leqslant \sum_{i \in I} \lambda_i^{(k+1)} \left| \min\{g_i(x^{(k)}), 0\} \right| + \sum_{j \in E} \left| \lambda_j^{(k+1)} \right| \left| h_j(x^{(k)}) \right| \\
		&\leqslant \left\| \lambda^{(k+1)} \right\|_\infty \left( \left\| \min\{g_I(x^{(k)}), 0\} \right\|_1 + \left\| h_E(x^{(k)}) \right\|_1 \right)
		\end{aligned}
		$$
		上式代入 $(temp')$ 即得
		$$
		\begin{aligned}
		&D(\Phi_1(x^{(k)}, \mu); d^{(k)}) \\
		\leqslant & - (d^{(k)})^\mathrm{T} B_k d^{(k)} - (\mu - \|\lambda^{(k+1)}\|_\infty) \left( \|\min\{g_I(x^{(k)}), 0\}\|_1 + \|h_E(x^{(k)})\|_1 \right)
		\end{aligned}
		$$
		从而引理成立。证毕！
	- 该引理说明：当罚参数满足一定条件时，子问题 $(q5)$ 的解 $d^{(k)}$ 是 $l_1$ 罚函数的下降方向。
	- 由该引理我们建立求解问题 $(question)$ 的全局 SQP 算法如下
- **算法 14.2** (**线性搜索 SQP 算法**)
	- *第 0 步*：选取参数 $\mu > 0$, $\delta > 0$, $\epsilon > 0$。取初始点 $x^{(0)} \in \mathbb{R}^n$，初始对称正定阵 $B_0$。令 $k := 0$ 
	- *第 1 步*：解子问题 $\begin{aligned} \min \quad & q_k(d) = \frac{1}{2}d^T B_k d + \nabla f(x^{(k)})^T d \\ \text{s.t.} \quad & \nabla g_I(x^{(k)})^T d + g_I(x^{(k)}) \geq 0 \\ & \nabla h_E(x^{(k)})^T d + h_E(x^{(k)}) = 0 \end{aligned}$ 得解 $(d^{(k)}, \lambda^{(k+1)})$。若 $d^{(k)}$ 满足 $\|d^{(k)}\| \leqslant \epsilon$，则停止计算，得解 $x^{(k)}$。否则转*第 2 步* 
	- *第 2 步*：确定 $\alpha_k \in [0, \delta]$，使得 $\Phi_1(x^{(k)} + \alpha_k d^{(k)}, \mu) \leqslant \min\limits_{0 \leqslant \alpha \leqslant \delta} \Phi_1(x^{(k)} + \alpha d^{(k)}, \mu) + \varepsilon_k$，其中 $\varepsilon_k$ 满足 $\sum\limits_{k=0}^{\infty} \varepsilon_k < +\infty$ 
	- *第 3 步*：令 $x^{(k+1)} = x^{(k)} + \alpha_k d^{(k)}$ 
	- *第 4 步*：用适当的拟 Newton 修正公式修正 $B_k$ 得 $B_{k+1}$，使得 $B_{k+1}$ 对称正定。令 $k := k + 1$ 转*第 1 步* 
- **定理 14.2.1**：设 $f$ 和 $g_I, h_E$ 连续可微，且存在常数 $\bar{m}, \bar{M} > 0$，使得 $\bar{m}\|d\|^2 \leqslant d^T B_k d \leqslant \bar{M}\|d\|^2$ 对一切 $k$ 和 $d \in \mathbb{R}^n$ 都成立。再设子问题 $(q5)$ 有解，且 $\mu \geqslant \|\lambda^{(k)}\|_\infty$。则由**算法 14.2** 产生的点列 $\{x^{(k)}\}$ 或者终止于问题 $(question)$ 的 K-K-T 点，或者其聚点是问题 $(question)$ 的 K-K-T 点
	- 该定理为**算法 14.2** 的全局收敛定理 
	- 该定理中的要求满足条件 $\mu \geqslant \|\lambda^{(k)}\|_\infty$ 
- *注意*：在实际计算时，很难选取适当的 $\mu$ 使得 $\mu\ge \| \lambda^{(k)} \|_\infty$ 成立。为了提高算法的实用性，我们可在不同的迭代步 $k$ 采用不同的 $\mu$ 值。
	- 例如，可按下面的方式选取 $\mu$：
		令 $\Phi(x, \mu^{(k)}) = f(x) + \sum\limits_{i \in I} \mu_i^{(k)} |\min\{g_i(x), 0\}| + \sum\limits_{j \in E} |\mu_j^{(k)} h_j(x)|$ 
		对 $i \in I \cup E$，任意取 $\mu_i^{(0)}$ 
		对 $k \geqslant 1$，取 $\mu_i^{(k)} = \max\left\{|\lambda_i^{(k)}|, \dfrac{1}{2}[\mu_i^{(k-1)} + |\lambda_i^{(k)}|]\right\}, \ (i \in I \cup E)$ 
		然后，在**算法 14.2** 中，用上面的 $\Phi(x, \mu^{(k)})$ 取代 $\Phi_1(x, \mu)$ 
- **算法 14.2** 中，*第 2 步*的近似精确线性搜索计算量较大。实际计算时常采用如下非精确线性搜索 $\Phi_1(x^{(k)} + \alpha_k d^{(k)}, \mu^{(k)}) \leqslant \Phi_1(x^{(k)}, \mu^{(k)}) + \beta \alpha_k D(\Phi_1(x^{(k)}, \mu^{(k)}); d^{(k)})$ 确定步长 $\alpha_k$，其中 $\beta \in (0,1)$ 
## 14-3 信赖域 SQP 算法
### 14-3-0 前言
- **信赖域算法**：本节介绍 SQP 算法全局收敛的另一种方法——**信赖域算法** 
- *前置分析*、**信赖域 SQP 子问题** 
	为了简化问题，我们只考虑等式约束最优化
	$$
	\begin{aligned}
	\min \quad & f(x) \\
	\text{s.t.} \quad & h_j(x) = 0, \quad j \in E = \{1, 2, \cdots, m\}
	\end{aligned} \tag{q1}
	$$
	记 $h(x) = h_E(x)$ 
	根据信赖域算法的思想，我们在 SQP 子问题 $(q5)$ 中增加信赖域约束。
	因此，在点 $x^{(k)}$ 处，对给定的信赖域半径 $\Delta_k$，包括信赖域约束的 SQP 子问题为 (简称**信赖域 SQP 子问题**)：
	$$
	\begin{aligned}
	& \min \quad \frac{1}{2} d^T B_k d + \nabla f(x^{(k)})^T d \\
	& \text{s.t.} \quad A(x^{(k)}) d + h(x^{(k)}) = 0 \\
	& \qquad \ \|d\| \leqslant \Delta_k
	\end{aligned}
	\tag{q6}
	$$
	其中 $A(x) = h'(x)$ 表示 $h$ 在 $x$ 处的 Jacobi 矩阵
### 14-3-1 信赖域 SQP 子问题
#### 14-3-1-0 面临的缺陷
对给定的 $\Delta_k$，子问题 $(q6)$ 可能不相容 (即可行域可能是空集)，如下图所示。
![[Pasted image 20260421085958.png|350]]
虽然可增大 $\Delta_k$ 的值以保证子问题的相容性，但这样将破坏信赖域算法中半径的调节功能 (即保证近似模型与实际模型的一致性)。
为了保证子问题的相容性，我们可对子问题进行适当修改。
修改子问题的一种合适的方法是在每个迭代步不要求子问题的等式约束精确满足，而按照逐步提高相容性直到在极限点满足可行性条件。
基于这种近似相容的思想，常用的克服信赖域子问题不相容的方法有如下四种。
#### 14-3-1-1 移位法
将子问题 $(q6)$ 的线性等式约束替换为 $A(x^{(k)}) d + \theta_k h(x^{(k)}) = 0$，其中 $\theta_k \in (0,1]$ 是一个参数。
如果 $\theta_k$ 充分小，则 $(q6)$ 中的两约束是相容的。
这种转换在几何上表示将子问题中约束的可行域往原点方向压缩，如下图所示
![[Pasted image 20260421090034.png|350]]
为使变换后的子问题与原问题的解尽量一致：
一方面，我们应当选取 $\theta_k$ 尽可能靠近 1
另一方面，为了使子问题能有一定的自由度，我们不能让 $\theta_k$ 过大。
一种直接选取 $\theta_k$ 的方法是利用 **Gauss-Newton 步**。
记问题 $\min\limits_{d \in \mathbb{R}^n} \| A(x^{(k)}) d + h(x^{(k)}) \|$ 的最小范数解为 Gauss-Newton 步 $d_k^{GN}$，$\theta_k$ 的选取要求满足 $\delta \Delta_k \le \theta_k \| d_k^{GN} \| \le \Delta_k$，其中 $\delta \in (0,1)$ 是给定常数。
上式中右不等式要求变换后的子问题有可行点，左不等式要求 $\theta_k$ 不要太小。
例如，可取 $\theta_k =  \begin{cases} 1, & \text{如果 } 2\|d_k^{\text{GN}}\| \leqslant \Delta_k \\ \dfrac{1}{2}\Delta_k / \|d_k^{\text{GN}}\|, & \text{否则} \end{cases}$ 
#### 14-3-1-2 两球约束法
另一种使子问题相容的方法是将子问题 $(q6)$ 用下面的问题替换：
$$
\begin{aligned}
& \min \quad \frac{1}{2} d^T B_k d + \nabla f(x^{(k)})^T d \\
& \text{s.t.} \quad \|A(x^{(k)}) d + h(x^{(k)})\|^2 \leqslant \xi_k \\
& \qquad \ \|d\|^2 \leqslant \Delta_k^2
\end{aligned}
$$
其中 $\xi_k$ 是保证上述问题相容的参数。
在 Powell-Yuan 的研究中，$\xi_k$ 的选取需满足：$\min\limits_{\|d\| \leqslant b_1\Delta_k} \|A(x^{(k)})d + h(x^{(k)})\|^2 \leqslant \xi_k \leqslant \min\limits_{\|d\| \leqslant b_2\Delta_k} \|A(x^{(k)})d + h(x^{(k)})\|^2$，其中 $b_1, b_2$ 是满足 $0 < b_2 \leqslant b_1 < 1$ 的常数
#### 14-3-1-3 罚函数法
考虑一般约束最优化问题 $(question)$ 
基于精确 $l_1$ 罚函数：$\Phi_1(x, \mu) = f(x) + \mu \left[ \|\min\{g_I(x), 0\}\|_1 + \|h_E(x)\|_1 \right]$ 
我们可构造子问题为：
$$
\begin{aligned}
\min \quad & \frac{1}{2} d^T B_k d + \nabla f(x^{(k)})^T d + \mu_k \left[ \|\nabla g_I(x^{(k)})^T d + \min\{g_I(x^{(k)}), 0\}\|_1 \right. \\
& \left. + \|\nabla h_E(x^{(k)})^T d + h_E(x^{(k)})\|_1 \right] \\
\text{s.t.} \quad & \|d\| \leqslant \Delta_k
\end{aligned}
$$
此方法适用于一般等式和不等式约束最优化问题，并放松 $A(x^{(k)})$ 线性无关的假设。
但此方法对罚因子的选取比较敏感，且因 $l_1$ 罚函数的不可微性导致局部收敛性分析中的 Maratos 效应
#### 14-3-1-4 方向分解法
在点 $x^{(k)}$ 处将信赖域试探步 $d^{(k)}$ 分解成两个分量：切分量 $d_k^t$ 和法分量 $d_k^n$，即 $d^{(k)} = d_k^n + d_k^t$ (见下图)
![[Pasted image 20260421091309.png|350]]
法分量 $d_k^n$ 由下式确定
$$
\begin{aligned}
\min_{d^n \in \mathbb R^n} \quad & \| A(x^{(k)})d^n + h(x^{(k)}) \|^2 \\
\text{s.t.} \quad & \|d^n \| \leqslant \tau\Delta_k
\end{aligned} \tag{temp1}
$$
其中 $\tau \in (0,1)$ 是给定的常数，法分量的作用是要求约束的可行性
记 $Z_k \in \mathbb{R}^{n \times m}$ 是由 $A(x^{(k)})$ 零空间的正交基所形成的矩阵。
设切分量为 $d_k^t = Z_k \bar{d}_k$，当法分量确定后，由 $d^{(k)}$ 的计算模式，子问题 $(q6)$ 可化成：
$$
\begin{aligned}
\min_{\bar{d}^t \in \mathbb{R}^m} \quad & \left[ Z_k^T \left( B_k d_k^n + \nabla f(x^{(k)}) \right) \right]^T \bar{d}^t + \frac{1}{2} (\bar{d}^t)^T Z_k^T B_k Z_k \bar{d}^t \\
\text{s.t.} \quad & \| Z_k \bar{d}^t \|^2 \leqslant \Delta_k^2 - \| d_k^n \|^2
\end{aligned} \tag{temp2}
$$
由此确定切向分量，从而确定信赖域 SQP 子问题的解 $d^{(k)}$ 
在上述方法中，确定 $\bar{d}_k^t$ 是一个低维的子问题，且两个子问题 $(temp1), (temp2)$ 为无约束优化的信赖子问题，可方便地用第 6 章的方法求解。此方法较好地处理了信赖域 SQP 子问题的相容性。
### 14-3-2 信赖域 SQP 算法
- **Fletcher 精确罚函数** 
	- *定义* 
		记优化问题 $(q1)$ 的 Lagrange 函数为 $L(x, \lambda) = f(x) - \lambda^T h(x)$ 
		令 $\Phi(x, \lambda; \mu) = f(x) - \lambda^T h(x) + \dfrac{1}{2} \mu \| h(x) \|^2$，其中 $\mu$ 是罚因子，$\lambda = \lambda(x)$ 是下面最小二乘问题的解：$\min \| \nabla f(x) - A(x)^T \lambda \|$ 
		在 $A(x)$ 行满秩的条件下，不难推得上面问题的解为 $\lambda(x) = \left[ A(x) A(x)^T \right]^{-1} A(x) \nabla f(x)$ 
		称由 $\Phi(x, \lambda; \mu) = f(x) - \lambda^T h(x) + \dfrac{1}{2} \mu \| h(x) \|^2$ 定义的函数 $\Phi$ 为 **Fletcher 精确罚函数**
	- Fletcher 精确罚函数是可微的。
- **等式约束优化**的**信赖域 SQP 法**的*理论基础* 
	类似于第 6 章求解无约束最优化的信赖域算法，在求出信赖域子问题的解后，需要检验子问题解的可接受性，并调节下次迭代的信赖域半径。设信赖域子问题的解为 $d^{(k)}$ 
	定义实际下降量和预估下降量分别为：$Ared_k = \Phi(x^{(k)}, \lambda^{(k)}; \mu_k) - \Phi(x^{(k)} + d^{(k)}, \lambda^{(k+1)}; \mu_k)$ 和 $Pred_k = -u_k + \mu_k v_k$ 
	其中：
	$$
	\begin{aligned}
	u_k =& \nabla_x L(x^{(k)}, \lambda^{(k)})^T d^{(k)} + \frac{1}{2} (d^{(k)})^T B_k d^{(k)} + (\lambda^{(k+1)} - \lambda^{(k)})^T \left[ A(x^{(k)}) d^{(k)} + h(x^{(k)}) \right] \\
	v_k =& \| h(x^{(k)}) \|^2 - \| A(x^{(k)}) d^{(k)} + h(x^{(k)}) \|^2
	\end{aligned}
	$$
	罚参数 $\mu_k$ 的调节可按如下方式进行：
	取 $\mu_{-1} = 1$ 和充分小的常数 $\beta > 0$，在点 $x^{(k)}$ 处计算出试探步 $d^{(k)}$ 后，由 $\mu_{k-1}$ 计算 $\mu_k$：
	$$
	\mu_k = 
	\begin{cases} 
	\mu_{k-1}, & \text{若 } Pred_k \geqslant \dfrac{\mu_{k-1} v_k}{2} \\[6pt]
	\dfrac{2 v_k}{\mu_{k-1}} + \beta, & \text{其他}
	\end{cases}
	$$
	可以证明，按上式调节的 $\mu_k$ 满足关系式 $Pred_k \equiv Pred_k(d^{(k)}; \mu_k) \geqslant \dfrac{\mu_k}{2} \left[ \| h(x^{(k)}) \|^2 - \| A(x^{(k)}) d^{(k)} + h(x^{(k)}) \|^2 \right]$ 
	采用方向分解方法求解等式约束优化问题 $(q2)$ 的信赖域 SQP 算法如下
- **算法 14.3** (**信赖域 SQP 算法**)
	- *第 0 步* (**初始化**)：选取常数 $\Delta_{\min} > 0$，$\Delta_{\max} > 0$，$\Delta_{\min} \leqslant \Delta_0 \leqslant \Delta_{\max}$，$\alpha_1, \tau \in (0,1) < 1$，$\alpha_2 > 1$，$0 < \eta_1 < \eta_2 < 1$，$\varepsilon > 0$，$\beta > 0$，$\mu_{-1} = 1$。取初始对 $(x^{(0)}, \lambda^{(0)})$，初始矩阵 $B_0$。计算 $Z_0$。令 $k := 0$ 
	- *第 1 步* (停止测试)：若 $\left\| Z_k^T  \nabla f(x^{(k)}) \right\| + \left\| h(x^{(k)}) \right\| \leqslant \varepsilon$，终止算法，得解 $x^{(k)}$；否则转*第 2 步* 
	- *第 2 步* (**计算试探步**)：解信赖域子问题 $\begin{aligned} \min_{d^n \in \mathbb R^n} \quad & \| A(x^{(k)})d^n + h(x^{(k)}) \|^2 \\ \text{s.t.} \quad & \|d^n \| \leqslant \tau\Delta_k \end{aligned}$ 和 $\begin{aligned} \min_{\bar{d}^t \in \mathbb{R}^m} \quad & \left[ Z_k^T \left( B_k d_k^n + \nabla f(x^{(k)}) \right) \right]^T \bar{d}^t + \frac{1}{2} (\bar{d}^t)^T Z_k^T B_k Z_k \bar{d}^t \\ \text{s.t.} \quad & \| Z_k \bar{d}^t \|^2 \leqslant \Delta_k^2 - \| d_k^n \|^2 \end{aligned}$ 得解 $d^{(k)} = d_k^n + Z_k \bar{d}_k$ 
	- *第 3 步* (**修正乘子 $\lambda$**)：在 $x^{(k)} + d^{(k)}$ 处用最小二乘估计 $\lambda(x) = \left[ A(x) A(x)^T \right]^{-1} A(x) \nabla f(x)$ 计算 $\lambda^{(k+1)}$，并计算 $\Delta \lambda = \lambda^{(k+1)} - \lambda^{(k)}$ 
	- *第 4 步* (**修正罚参数 $\mu$**)：用公式 $\mu_k = \begin{cases} \mu_{k-1}, & \text{若 } Pred_k \geqslant \dfrac{\mu_{k-1} v_k}{2} \\ \dfrac{2 v_k}{\mu_{k-1}} + \beta, & \text{其他} \end{cases}$ 计算 $\mu_k$ 
	- *第 5 步* (**测试试探步的可接受性**)：由 $Ared_k = \Phi(x^{(k)}, \lambda^{(k)}; \mu_k) - \Phi(x^{(k)} + d^{(k)}, \lambda^{(k+1)}; \mu_k)$ 和 $Pred_k = -u_k + \mu_k v_k$ 计算 $Ared_k, Pred_k$ 和 $r_k = \dfrac{Ared_k}{Pred_k}$ 
		- 若 $r_k < \eta_1$，拒绝试探步 $d^{(k)}$，取 $\Delta_k = \alpha_1 \|d^{(k)}\|$ 返回*第 2 步* 
		- 若 $\eta_1 \leqslant r_k$，接受试探步，设 $x^{(k+1)} = x^{(k)} + d^{(k)}$。且若 $r_k \leqslant \eta_2$ 时，令 $\Delta_{k+1} := \max\{\Delta_k, \Delta_{\min}\}$；否则 $\Delta_{k+1} := \min\{\Delta_{\max}, \max\{\Delta_{\min}, \alpha_2 \Delta_k\}\}$ 
	- *第 6 步*：用适当的方式修正 $B_k$ 得 $B_{k+1}$。令 $k := k + 1$ 转*第 1 步* 
	- *注 1*：上面算法中的步1给出的终止准则等价于 $x^{(k)}$ 是问题 $(q1)$ 的 K-K-T 点
	- *注 2*：算法中的*第 5 步*包括试探步可接受的判断和信赖域半径的调节，其中 $r_k$ 描述了近似模型与原问题一致性程度。当 $r_k < \eta_1$，信赖域 SQP 子问题的解被拒绝，需缩小信赖半径重新解子问题，否则接受子问题的解，并根据 $r_k$ 的值确定保持或放大下次迭代计算的信赖域半径
- *假设条件* 
	(1) 存在凸集 $\Omega \subseteq \mathbb{R}^n$ 使 $\{x^{(k)}\}$ 和 $\{x^{(k)} + d^{(k)}\}$ 都在 $\Omega$ 内
	(2) 对所有 $x \in \Omega$，$\operatorname{rank}(A(x^{(k)})) = m$ 
	(3) 对 $x \in \Omega$，$f(x), \nabla f(x), \nabla^2 f(x), h(x), A(x), [A(x)A(x)^\mathrm{T}]^{-1}, Z(x), \nabla^2 h(x)$ 一致有界
	(4) $B_k$ 一致有界
- **定理14.3.1** 设*假设条件*均满足，则当 $\varepsilon > 0$ 时**算法 14.3** 必有限步迭代终止于问题 $(q1)$ 的 K-K-T 点或产生无穷点列 $\{x^{(k)}\}$ 满足 $\lim\limits_{k \to \infty} \inf \left\| Z_k^\mathrm{T} \nabla f(x^{(k)}) \right\| + \left\| h(x^{(k)}) \right\| = 0$ 
	- 该定理为**算法 14.3** 的全局收敛定理
## 14-4 Maratos 效应及改进策略
- **Maratos 效应** 
	定理 14.1.2 和定理 14.2.1 分别给出了局部 SQP 算法的超线性条件和线性搜索 SQP 算法 14.2 的全局收敛性条件。
	由此可知，若全局 SQP 算法中单位步长可以接受 (即 $\alpha_k = 1$)，则全局 SQP 算法具有超线性收敛性。
	然而，在许多情况下，算法 14.2 不能保证单位步长被接受，从而不能保证算法的超线性收敛性。
	此现象首先由 Maratos 指出，故称为 **Maratos 效应** 
- 具有 Maratos 效应的*例子* 
	Powell 给出如下问题：
	$$
	\begin{aligned}
	\min \quad & f(x) = -x_1 + 2(x_1^2 + x_2^2 - 1) \\
	\text{s.t.} \quad & x_1^2 + x_2^2 - 1 = 0
	\end{aligned}
	$$
	此问题的最优解为 $x^* = (1, 0)^\mathrm{T}$，且在最优解处 Lagrange 乘子和 Lagrange 函数的 Hessian 矩阵分别为 $\lambda^* = \dfrac{1}{2}$ 和 $W(x^*, \lambda^*) = I$ 
	用 SQP 算法求解 (取 $B_k = I$) 时，$x^{(k)} = (\cos\theta_k, \sin\theta_k)^\mathrm{T}$ 
	显然，当 $x^{(k)} \to x^*$ 时有 $\cos\theta_k \to 1$ 
	直接计算有 $f(x^{(k)}) = -\cos\theta_k,\ \nabla f(x^{(k)}) = (4\cos\theta_k - 1, 4\sin\theta_k)^\mathrm{T},\ A(x^{(k)}) = (2\cos\theta_k, 2\sin\theta_k)$ 
	不难推出此例的 SQP 子问题的解为 $d^{(k)} = (\sin^2\theta_k, -\sin\theta_k\cos\theta_k)^\mathrm{T}$ 
	由于 $x^{(k)} + d^{(k)} = (\cos\theta_k + \sin^2\theta_k, \sin\theta_k(1 - \cos\theta_k))^\mathrm{T}$，有 $\dfrac{\|x^{(k)} + d^{(k)} - x^*\|}{\|x^{(k)} - x^*\|^2} = \dfrac{1}{2}$，此式说明 $d^{(k)}$ 是超线性收敛步。
	若取效益函数为 $l_1$ 罚函数 $\Phi_1(x, \mu) = f(x) + \mu \|h(x)\|_1$，其中 $\mu \geqslant 0$ 
	此时由于 $x^{(k)}$ 的可行性有 $\Phi_1(x^{(k)}, \mu) = -\cos\theta_k$，$\Phi_1(x^{(k)} + \alpha d^{(k)}, \mu) = -\cos\theta_k - \alpha \sin^2\theta_k + (2 + \mu)\alpha^2 \sin^2\theta_k$ 
	要使效益函数单调下降，即 $\Phi_1(x^{(k)} + \alpha d^{(k)}, \mu) < \Phi_1(x^{(k)}, \mu)$，$\alpha$ 须满足 $\alpha < \dfrac{1}{2 + \mu}$ 
	因此，不论 $x^{(k)}$ 多么靠近 $x^*$，单位步长不可能取到，从而算法不具有超线性收敛性。  
- 克服 Maratos 效应通常有三类方法
### 14-4-1 Watchdog 技术  
- **Watchdog 算法**的*理论基础*
	此方法是一种非单调技术。算法按“标准型搜索”与“松弛搜索”进行。
	在“标准型搜索”中要求 $\Phi(x^{(k+1)}, \mu) < \Phi(x^{(k)}, \mu)$ 
	而在另一些迭代中进行“松弛搜索”，如简单取步长 $\alpha_k = 1$ 
	“松弛搜索”计算的前提是在某次迭代中产生的点比所求迭代点中最好点处效益函数有“足够的”下降 (所谓“最好点”，即效益函数值在此点最小)，则下次迭代用“松弛搜索”，也即松弛搜索的起点是所求的点中“最好”的点。
	具体判断何时进行“松弛搜索”由下面分析确定：
	设算法中所用的效益函数为 $l_1$ 罚函数 $\Phi_1(x, \mu) = f(x) + \mu \left[ \| \min\{g_I(x), 0\} \|_1 + \| h_E(x) \|_1 \right]$ 
	定义 $\Phi_1(x, \mu)$ 在 $x^{(k)}$ 的近似函数为
	$$
	\begin{aligned}
	\Phi_1^{(k)}(x, \mu) =& f(x^{(k)}) + \nabla f(x^{(k)})^\mathrm{T} (x - x^{(k)}) + \frac{1}{2} (x - x^{(k)})^\mathrm{T} B_k (x - x^{(k)}) \\
	&+ \mu \left[ \| \min\{ \nabla g_I(x^{(k)})^\mathrm{T} (x - x^{(k)}) + g_I(x^{(k)}), 0 \} \|_1 \right. \\
	&+ \left. \| \nabla h_E(x^{(k)})^\mathrm{T} (x - x^{(k)}) + h_E(x^{(k)}) \|_1 \right]
	\end{aligned}
	$$
	设 $l \leqslant k$ 是至第 $k$ 次迭代“最好”的，即 $\Phi_1(x^{(l)}, \mu) = \min_{1 \leqslant i \leqslant k} \Phi_1(x^{(i)}, \mu)$ 
	由于 $x^{(l)}$ 是“最好”点，步长可选择 $\alpha_l = 1$，直接计算可得
	$$
	\begin{aligned}
	&\Phi_1(x^{(l)}, \mu) - \Phi_1^{(l)}(x^{(l+1)}, \mu) \\
	=& - \nabla f(x^{(l)})^\mathrm{T} d^{(l)} - \frac{1}{2} (d^{(l)})^\mathrm{T} B_l d^{(l)} + \mu \left[ \| \min\{ g_I(x^{(l)}), 0 \} \|_1 + \| h_E(x^{(l)}) \|_1 \right] > 0
	\end{aligned}
	$$
	若 $x^{(k+1)} = x^{(k)} + \alpha_k d^{(k)}$ 满足 $\Phi_1(x^{(k+1)}, \mu) \leqslant \Phi_1(x^{(l)}, \mu) - \beta\left[\Phi_1(x^{(l)}, \mu) - \Phi_1^{(l)}(x^{(l+1)}, \mu)\right]$，其中 $\beta \in (0, 1/2)$，则下次搜索方式取为“松弛搜索”。在一次松弛搜索后，接着进行标准搜索。
	由于标准型搜索要求效益函数的下降性，因此标准搜索后的点比松弛型搜索的终点要好，但不一定比已求得的“最好”点好，经过几次标准型搜索后，可求得比原“最好”点更好的点。
	一般我们设松弛型搜索后的标准搜索最多进行 $t$ 次 (如取 $t = 5$)，若 $t$ 次后我们仍找不到比已有“最好”点更好的点，说明“松弛搜索”是不恰当的，要再次回到该次松弛搜索的起点重新进行标准搜索。
	这样最多作 $t + 2$ 次迭代，我们总可找到比原来“最好”点更好的点。因此算法总体仍是下降的。
	数值 $t$ 用来控制算法从弯路上返回，这也即 Watchdog 名称的由来
	Watchdog 算法结构如下
- **算法 14.4** (**Watchdog 算法**)
	- *第 1 步*：取初始点 $x^{(0)}$，正整数 $t$，$\beta \in (0, 1/2)$，取搜索模式为标准型，令 $k := 0$，$l := 0$ 
	- *第 2 步*：解 SQP 子问题 $\begin{aligned} \min \quad & q_k(d) = \frac{1}{2}d^T B_k d + \nabla f(x^{(k)})^T d \\ \text{s.t.} \quad & \nabla g_I(x^{(k)})^T d + g_I(x^{(k)}) \geq 0 \\ & \nabla h_E(x^{(k)})^T d + h_E(x^{(k)}) = 0 \end{aligned}$ 得搜索方向 $d^{(k)}$，并利用线性搜索类型 (标准型或松弛型) 求得搜索步长 $\alpha_k > 0$，令 $x^{(k+1)} = x^{(k)} + \alpha_k d^{(k)}$ 
	- *第 3 步*：若 $\Phi_1(x^{(k+1)}, \mu)$ 满足松弛搜索条件 $\Phi_1(x^{(k+1)}, \mu) \leqslant \Phi_1(x^{(l)}, \mu) - \beta\left[\Phi_1(x^{(l)}, \mu) - \Phi_1^{(l)}(x^{(l+1)}, \mu)\right]$，则下次搜索为松弛型，否则为标准型
	- *第 4 步*：若 $\Phi_1(x^{(k+1)}, \mu) \leqslant \Phi_1(x^{(l)}, \mu)$，则令 $l := k + 1$ 
	- *第 5 步*：若 $k < l + t$，则转*第 6 步*；否则 $x^{(k+1)} := x^{(l)}$；$l := k + 1$ 
	- *第 6 步*：如果需要迭代，则 $k := l + 1$ 转*第 2 步* 
	- *理论上可证*：若 $d^{(k)}$ 是超线性收敛步，则用 Watchdog 技术的 SQP 算法不仅具有全局收敛性，而且保证局部超线性收敛性
### 14-4-2 二阶校正步技巧  
二阶校正步是指在 $x^{(k)}$ 处求得 SQP 子问题的解 $d^{(k)}$ 后，对 $d^{(k)}$ 进行二阶修正
即求 $\hat{d}^{(k)}$ 使得 $\|\hat{d}^{(k)}\| = O(\|d^{(k)}\|^2), \ \Phi(x^{(k)} + d^{(k)} + \hat{d}^{(k)}) < \Phi(x^{(k)})$ 
显然，$\hat{d}^{(k)} + d^{(k)}$ 仍是一超线性收敛步。  
设 $\hat{d}^{(k)}$ 为如下二次规划问题
$$
\begin{aligned}
\min \quad & \nabla f(x^{(k)})^\mathrm{T} (d^{(k)} + d) + \frac{1}{2} (d^{(k)} + d)^\mathrm{T} B_k (d^{(k)} + d) \\
\text{s.t.} \quad & \nabla g_i(x^{(k)})^\mathrm{T} d + g_i(x^{(k)} + d^{(k)}) \geqslant 0, \quad (i \in I) \\
& \nabla h_j(x^{(k)})^\mathrm{T} d + h_j(x^{(k)} + d^{(k)}) = 0, \quad (j \in E)
\end{aligned}
$$
的解。
可以证明，在一定的条件下，$\hat{d}^{(k)}$ 满足 $\|\hat{d}^{(k)}\| = O(\|d^{(k)}\|^2), \ \Phi(x^{(k)} + d^{(k)} + \hat{d}^{(k)}) < \Phi(x^{(k)})$，故 $d^{(k)} + \hat{d}^{(k)}$ 为可接受的超线性收敛步。
### 14-4-3 采用光滑效益函数  
引起 Maratos 效应是因为非光滑的效益函数，有效的处理方法之一是用光滑的效益函数。
如果 $P(x)$ 是一光滑函数，它在点 $x^*$ 处达到最小且 $\nabla^2 P(x^*)$ 对称正定，则存在正数 $m$ 和 $M$，使得当 $x$ 充分接近 $x^*$ 时，$m\|x - x^*\|^2 \leqslant P(x) - P(x^*) \leqslant M\|x - x^*\|^2$ 
于是，只要 $d^{(k)}$ 是一超线性收敛步，则当 $k$ 充分大时，  
$$\begin{aligned}
P(x^{(k)} + d^{(k)}) &\leqslant P(x^*) + M\|x^{(k)} + d^{(k)} - x^*\|^2 \\
&\leqslant P(x^{(k)}) - m\|x^{(k)} - x^*\|^2 \left(1 - \frac{M\|x^{(k)} + d^{(k)} - x^*\|^2}{m\|x^{(k)} - x^*\|^2}\right) \leqslant P(x^{(k)})
\end{aligned}$$  
$d^{(k)}$ 为可接受的超线性收敛步。  
例如，对于等式约束问题，我们可用 Fletcher 精确罚函数 $\Phi(x, \lambda; \mu) = f(x) - \lambda^T h(x) + \dfrac{1}{2} \mu \| h(x) \|^2$ 作为效益函数。由于函数 $\varPhi$ 的光滑性，可避免 Maratos 效应

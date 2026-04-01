# 4 无约束问题算法 (II)
## 4-0 前言
- 本章介绍求解无约束问题 $\min f(x),\ (x\in \mathbb R^n)$ 的拟 Newton 法
- 假设 $f:\mathbb R^n \to \mathbb R$ 连续可微
## 4-1 拟Newton法及其性质
### 4-1-0 前言
- 上一章介绍的 Newton 法具有二次收敛性。但当 $\nabla^2 f(x^{(k)})$ 不正定时，算法产生的方向不能保证是 $f$ 在 $x^{(k)}$ 处的下降方向。特别地，当 $\nabla^2 f(x^{(k)})$ 奇异时，子问题 $\nabla^2 f(x^{(k)}) d + \nabla f(x^{(k)}) = 0$ 可能无解，即 Newton 方向可能不存在
- 修正 Newton 法可克服 Newton 法的上述困难。但在修正 Newton 法中，参数 $\nu_k > 0$ 的选取十分重要。若参数 $\nu_k$ 过小，则相应的修正 Newton 方向仍不能保证是 $f$ 在 $x^{(k)}$ 处的下降方向；参数 $\nu_k$ 太大，则会影响收敛速度。
- 此外，Newton 法及其修正形式都需要计算函数 $f$ 的二阶导数
- 下面介绍的拟 Newton 法可克服 Newton 法的上述缺陷，而且算法在一定的条件下具有较快的收敛速度——超线性收敛速度
- *拟 Newton 法的基本思想* 
	是在 Newton 法的子问题 $\nabla^2 f(x^{(k)}) d + \nabla f(x^{(k)}) = 0$ 中用 $\nabla^2 f(x^{(k)})$ 的某个近似矩阵 $B_k$ 取代 $\nabla^2 f(x^{(k)})$ 
	矩阵 $B_k$ 应具有如下三个特点：
	(1) 在某种意义下有 $B_k \approx \nabla^2 f(x^{(k)})$，使相应的算法产生的方向 (称为**拟 Newton 方向**) 是 Newton 方向的近似，以保证算法具有较快的收敛速度
	(2) 对所有的 $k$，$B_k$ 对称正定，从而使得算法产生的方向是函数 $f$ 在 $x^{(k)}$ 处的下降方向
	(3) 矩阵 $B_k$ 容易计算
	下面介绍具有这三个特点的 $B_k$ 的构造
### 4-1-1 拟 Newton 方程与Dennis-Moré条件  
- **拟 Newton 方程** (**割线方程**)
	- *定义* 
		假设 $f$ 二次连续可微，利用多元函数 Taylor 展开得如下近似式：$\nabla f(x^{(k)}) \approx \nabla f(x^{(k+1)}) - \nabla^2 f(x^{(k+1)})(x^{(k+1)} - x^{(k)})$。
		因此，使 $B_k$ 近似于 $\nabla^2 f(x^{(k)})$ 的一种合理的取法是：用 $B_{k+1}$ 取代 $\nabla^2 f(x^{(k+1)})$ 时，上面的近似式成立等式
		即 $B_{k+1}$ 满足方程 $B_{k+1} s^{(k)} = y^{(k)}$，其中 $s^{(k)} = x^{(k+1)} - x^{(k)},\ y^{(k)} = \nabla f(x^{(k+1)}) - \nabla f(x^{(k)})$ 
		方程 $B_{k+1} s^{(k)} = y^{(k)}$ 称为**拟 Newton 方程**或**割线方程** 
	- 若令 $H_{k+1} = B_{k+1}^{-1}$，则拟 Newton 方程 $B_{k+1} s^{(k)} = y^{(k)}$ 可等价地写成 $H_{k+1} y^{(k)} = s^{(k)}$ 
	- 注意到 $s^{(k)} = x^{(k+1)} - x^{(k)} = \alpha_k d^{(k)}$，拟 Newton 方程 $B_{k+1} s^{(k)} = y^{(k)}$ 表明矩阵 $B_{k+1}$ 与 $\nabla^2 f(x^{(k+1)})$ 沿方向 $d^{(k)}$ 近似相等。因而，拟 Newton 方向是 Newton 方向在某种意义上的一个近似。
- 下面的定理说明，当 $B_k$ 满足一定的条件时，拟 Newton 法具有超线性收敛性
- **定理 4.1.1**：设函数 $f: \mathbb{R}^n \to \mathbb{R}$ 二次连续可微，考察如下迭代过程 $x^{(k+1)} = x^{(k)} + d^{(k)},\ (k = 0,1,\cdots)$，其中 $d^{(k)}$ 是线性方程组 $B_k d + \nabla f(x^{(k)}) = 0$ 的解。设 $\{x^{(k)}\}$ 收敛于 $x^*$ 且 $\nabla f(x^*) = 0$，$\nabla^2 f(x^*)$ 正定。则 $\{x^{(k)}\}$ 超线性收敛当且仅当 $\lim\limits_{k \to \infty} \dfrac{\|(B_k - \nabla^2 f(x^*)) d^{(k)}\|}{\|d^{(k)}\|} = 0$ 
	- *证明过程* 
		由于 $\{x^{(k)}\} \to x^*$，因此 $\lim\limits_{k \to \infty} \dfrac{\|(B_k - \nabla^2 f(x^*)) d^{(k)}\|}{\|d^{(k)}\|} = 0$ 等价于 $\lim\limits_{k \to \infty} \dfrac{\|(B_k - \nabla^2 f(x^*)) d^{(k)}\|}{\|d^{(k)}\|} = 0$ 
		注意到 $B_k d^{(k)} = -\nabla f(x^{(k)})$ 
		上式等价于 $\lim\limits_{k \to \infty} \dfrac{\|\nabla f(x^{(k)}) + \nabla^2 f(x^*) d^{(k)}\|}{\|d^{(k)}\|} = 0$ 
		因此，若 $\lim\limits_{k \to \infty} \dfrac{\|(B_k - \nabla^2 f(x^*)) d^{(k)}\|}{\|d^{(k)}\|} = 0$ 成立，由**定理 2.5.2** 即得 $\{x^{(k)}\}$ 的超线性收敛性
		反之，设 $\{x^{(k)}\}$ 超线性收敛于 $x^*$，即 $\lim\limits_{k \to \infty} \dfrac{\|x^{(k+1)} - x^*\|}{\|x^{(k)} - x^*\|} = 0$ 
		由于 $x^{(k+1)} = x^{(k)} + d^{(k)}$，因此 $\lim\limits_{k \to \infty} \dfrac{\|x^{(k+1)} - x^*\|}{\|x^{(k)} - x^*\|} = 0$ 包含了 $\lim\limits_{k \to \infty} \dfrac{\|x^{(k)} - x^*\|}{\|d^{(k)}\|} = 1$ 
		利用方程组 $B_k d + \nabla f(x^{(k)}) = 0$ 得
		$$
		\begin{aligned}
		\|(B_k - \nabla^2 f(x^*)) d^{(k)}\| &= \|\nabla f(x^{(k)}) + \nabla^2 f(x^*) d^{(k)}\| \\
		&\leq \|\nabla f(x^{(k)}) - \nabla f(x^*) - \nabla^2 f(x^*) (x^{(k)} - x^*)\| \\
		&\quad + \|\nabla^2 f(x^*) (x^{(k+1)} - x^*)\|.
		\end{aligned}
		$$
		利用 $f$ 的二次连续可微性，并由上式及 $\lim\limits_{k \to \infty} \dfrac{\|x^{(k)} - x^*\|}{\|d^{(k)}\|} = 1$，不难推得 $\lim\limits_{k \to \infty} \dfrac{\|(B_k - \nabla^2 f(x^*)) d^{(k)}\|}{\|d^{(k)}\|} = 0$，证毕！
- **Dennis-More 条件**：注意到 $s^{(k)} = x^{(k+1)} - x^{(k)} = d^{(k)}$，条件 $\lim\limits_{k \to \infty} \dfrac{\|(B_k - \nabla^2 f(x^*)) d^{(k)}\|}{\|d^{(k)}\|} = 0$ 可等价地写成 $\lim\limits_{k \to \infty} \dfrac{\|(B_k - \nabla^2 f(x^*)) s^{(k)}\|}{\|s^{(k)}\|} = 0$，这两个式子都可以称为 **Dennis-More 条件** 
- 当 $n > 1$ 时，满足拟 Newton 方程 $B_{k+1} s^{(k)} = y^{(k)}$ 的矩阵 $B_{k+1}$ 有很多。确定 $B_{k+1}$ 的原则之一是使其在计算上容易实现。已有的拟 Newton 法通过对 $B_k$ 进行低秩修正产生 $B_{k+1}$，即令 $B_{k+1} = B_k + \Delta_k$，其中矩阵 $\Delta_k$ 是秩为 1 或 2 的矩阵。
- 下面给出几种常用的拟 Newton 修正公式。
### 4-1-2 对称秩1 (SR1) 修正公式

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
### 4-1-2 对称秩 1 (SR1) 修正公式
在式 $B_{k+1} = B_k + \Delta_k$ 中取 $\Delta_k$ 为秩 1 的对称矩阵，即令 $\Delta_k = \beta_k u^{(k)} u^{(k)\mathrm{T}}$，其中 $\beta_k \in \mathbb{R},\ u^{(k)} \in \mathbb{R}^n$ 
由拟 Newton 方程 $B_{k+1} s^{(k)} = y^{(k)}$ 得 $(B_k + \beta_k u^{(k)} u^{(k)\mathrm{T}}) s^{(k)} = y^{(k)}$，即有 $\beta_k (u^{(k)\mathrm{T}} s^{(k)}) u^{(k)} = y^{(k)} - B_k s^{(k)}$ 
上式说明，向量 $u^{(k)}$ 平行于 $y^{(k)} - B_k s^{(k)}$，即存在 $\gamma_k$，使得 $u^{(k)} = \gamma_k (y^{(k)} - B_k s^{(k)})$，故 $\Delta_k = \beta_k \gamma_k^2 (y^{(k)} - B_k s^{(k)}) (y^{(k)} - B_k s^{(k)})^\mathrm{T}$ 
从而，由式 $\beta_k (u^{(k)\mathrm{T}} s^{(k)}) u^{(k)} = y^{(k)} - B_k s^{(k)}$ 得 $[\beta_k \gamma_k^2 (y^{(k)} - B_k s^{(k)})^\mathrm{T} s^{(k)} - 1] (y^{(k)} - B_k s^{(k)}) = 0$ 
若 $(y^{(k)} - B_k s^{(k)})^\mathrm{T} s^{(k)} \neq 0$，则有 $\beta_k \gamma_k^2 = \dfrac{1}{(y^{(k)} - B_k s^{(k)})^\mathrm{T} s^{(k)}}, \ \Delta_k = \dfrac{(y^{(k)} - B_k s^{(k)}) (y^{(k)} - B_k s^{(k)})^\mathrm{T}}{(y^{(k)} - B_k s^{(k)})^\mathrm{T} s^{(k)}}$ 
故得如下**对称秩 1 修正公式**：$B_{k+1} = B_k + \dfrac{(y^{(k)} - B_k s^{(k)}) (y^{(k)} - B_k s^{(k)})^\mathrm{T}}{(y^{(k)} - B_k s^{(k)})^\mathrm{T} s^{(k)}}$ 
类似地，利用割线方程 $H_{k+1} y^{(k)} = s^{(k)}$，对 $H_k$ 进行对称秩 1 修正可得如下关于 $H_k$ 的**对称秩 1 修正公式**：$H_{k+1} = H_k + \dfrac{(s^{(k)} - H_k y^{(k)}) (s^{(k)} - H_k y^{(k)})^\mathrm{T}}{(s^{(k)} - H_k y^{(k)})^\mathrm{T} y^{(k)}}$ 
### 4-1-3 BFGS 修正公式与 BFGS 算法
- **BFGS (Broyden-Fletcher-Goldfarb-Shanno) 修正公式** 
	在 $B_{k+1} = B_k + \Delta_k$ 中取 $\Delta_k$ 为秩为 2 的对称矩阵，即令 $\Delta_k = a_k u^{(k)} u^{(k)\mathrm{T}} + b_k v^{(k)} v^{(k)\mathrm{T}}$，其中 $a_k, b_k$ 是待定实数，$u^{(k)}, v^{(k)} \in \mathbb{R}^n$ 是待定向量
	由拟 Newton 方程 $B_{k+1} s^{(k)} = y^{(k)}$ 得 $B_k s^{(k)} + a_k (u^{(k)\mathrm{T}} s^{(k)}) u^{(k)} + b_k (v^{(k)\mathrm{T}} s^{(k)}) v^{(k)} = y^{(k)}$ 
	或等价地，$a_k (u^{(k)\mathrm{T}} s^{(k)}) u^{(k)} + b_k (v^{(k)\mathrm{T}} s^{(k)}) v^{(k)} = y^{(k)} - B_k s^{(k)}$ 
	不难发现，满足上式的向量 $u^{(k)}$ 和 $v^{(k)}$ 不唯一。
	取 $u^{(k)}, v^{(k)}$ 分别平行于 $B_k s^{(k)}$ 和 $y^{(k)}$，即令 $u^{(k)} = \beta_k B_k s^{(k)},\ v^{(k)} = \gamma_k y^{(k)}$，其中 $\beta_k$ 与 $\gamma_k$ 是待定参数
	我们有 $\Delta_k = a_k \beta_k^2 B_k s^{(k)} s^{(k)\mathrm{T}} B_k + b_k \gamma_k^2 y^{(k)} y^{(k)\mathrm{T}}$ 
	由 $a_k (u^{(k)\mathrm{T}} s^{(k)}) u^{(k)} + b_k (v^{(k)\mathrm{T}} s^{(k)}) v^{(k)} = y^{(k)} - B_k s^{(k)}$ 得 $[a_k \beta_k^2 (s^{(k)\mathrm{T}} B_k s^{(k)}) + 1] B_k s^{(k)} + [b_k \gamma_k^2 (y^{(k)\mathrm{T}} s^{(k)}) - 1] y^{(k)} = 0$ 
	若向量 $y^{(k)}$ 与 $B_k s^{(k)}$ 不平行，则有 $a_k \beta_k^2 = -\dfrac{1}{s^{(k)\mathrm{T}} B_k s^{(k)}},\ b_k \gamma_k^2 = \dfrac{1}{y^{(k)\mathrm{T}} s^{(k)}}$ 
	从而 $\Delta_k = -\dfrac{B_k s^{(k)} s^{(k)\mathrm{T}} B_k}{s^{(k)\mathrm{T}} B_k s^{(k)}} + \dfrac{y^{(k)} y^{(k)\mathrm{T}}}{y^{(k)\mathrm{T}} s^{(k)}}$ 
	故得如下秩 2 修正公式：$B_{k+1} = B_k - \dfrac{B_k s^{(k)} s^{(k)\mathrm{T}} B_k}{s^{(k)\mathrm{T}} B_k s^{(k)}} + \dfrac{y^{(k)} y^{(k)\mathrm{T}}}{y^{(k)\mathrm{T}} s^{(k)}}$ 
	公式 $B_{k+1} = B_k - \dfrac{B_k s^{(k)} s^{(k)\mathrm{T}} B_k}{s^{(k)\mathrm{T}} B_k s^{(k)}} + \dfrac{y^{(k)} y^{(k)\mathrm{T}}}{y^{(k)\mathrm{T}} s^{(k)}}$ 称为 **BFGS (Broyden-Fletcher-Goldfarb-Shanno) 修正公式**。显然，若 $B_k$ 对称，则 $B_{k+1}$ 也对称。
---
- 下面给出 BFGS 修正公式的一些性质
- **命题 4.1.1**：设 $B_k$ 对称正定，$B_{k+1}$ 由 BFGS 修正公式确定，则当且仅当 $y^{(k)\mathrm{T}} s^{(k)} > 0$ 时，$B_{k+1}$ 对称正定。
	- *证明过程* 
		注意到 $y^{(k)\mathrm{T}} s^{(k)} = s^{(k)\mathrm{T}} B_{k+1} s^{(k)}$，若 $B_{k+1}$ 正定，则显然有 $y^{(k)\mathrm{T}} s^{(k)} > 0$ 
		下设 $y^{(k)\mathrm{T}} s^{(k)} > 0$ 且 $B_k$ 对称正定，我们证明对任何 $d \in \mathbb{R}^n$ 且 $d \neq 0$，有 $d^{\mathrm{T}} B_{k+1} d > 0$ 
		由公式 $B_{k+1} = B_k - \dfrac{B_k s^{(k)} s^{(k)\mathrm{T}} B_k}{s^{(k)\mathrm{T}} B_k s^{(k)}} + \dfrac{y^{(k)} y^{(k)\mathrm{T}}}{y^{(k)\mathrm{T}} s^{(k)}}$ 得 $d^{\mathrm{T}} B_{k+1} d = d^{\mathrm{T}} B_k d - \dfrac{(d^{\mathrm{T}} B_k s^{(k)})^2}{s^{(k)\mathrm{T}} B_k s^{(k)}} + \dfrac{(d^{\mathrm{T}} y^{(k)})^2}{y^{(k)\mathrm{T}} s^{(k)}} \quad (t1)$ 
		由 $B_k$ 的对称正定性，存在对称正定矩阵 $B_k^{1/2}$ 使得 $B_k = B_k^{1/2} B_k^{1/2}$ 
		利用 Cauchy-Schwarz 不等式：$|a^\mathrm{T} b| \leqslant \|a\| \|b\| \ (\forall\ a, b \in \mathbb{R}^n)$ 得 $(d^\mathrm{T} B_k s^{(k)})^2 = \left[ (B_k^{1/2} d)^\mathrm{T} (B_k^{1/2} s^{(k)}) \right]^2 \leqslant \| B_k^{1/2} d \|^2 \| B_k^{1/2} s^{(k)} \|^2 = (d^\mathrm{T} B_k d)(s^{(k)\mathrm{T}} B_k s^{(k)}) \quad (t2)$ 
		上面的不等式成立等式的充要条件是存在数 $\lambda_k \neq 0$ 使得 $B_k^{1/2} d = \lambda_k B_k^{1/2} s^{(k)}$，即 $d = \lambda_k s^{(k)}$ 
		因此，若不等式 $(t2)$ 为严格不等式，则由 $(t1)$ 得 $d^\mathrm{T} B_{k+1} d > d^\mathrm{T} B_k d - d^\mathrm{T} B_k d + \dfrac{(d^\mathrm{T} y^{(k)})^2}{y^{(k)\mathrm{T}} s^{(k)}} = \dfrac{(d^\mathrm{T} y^{(k)})^2}{y^{(k)\mathrm{T}} s^{(k)}} \geqslant 0$ 
		若不等式 $(t2)$ 中等式成立，即有 $\lambda_k \neq 0$，使得 $d = \lambda_k s^{(k)}$，则由不等式 $(t1)$ 和等式 $(t2)$ 得 $d^\mathrm{T} B_{k+1} d \geqslant \dfrac{(d^\mathrm{T} y^{(k)})^2}{y^{(k)\mathrm{T}} s^{(k)}} = \lambda_k^2 y^{(k)\mathrm{T}} s^{(k)} > 0$ 
		总之，$d^\mathrm{T} B_{k+1} d > 0, \ \forall d \in \mathbb{R}^n, \ d \neq 0$，即 $B_{k+1}$ 对称正定。证毕！
	- 上面的命题表明：若初始矩阵 $B_0$ 对称正定，且在迭代时保证 $y^{(k)\mathrm{T}} s^{(k)} > 0 \ (\forall\ k \geqslant 0)$，则由修正公式 $B_{k+1} = B_k - \dfrac{B_k s^{(k)} s^{(k)\mathrm{T}} B_k}{s^{(k)\mathrm{T}} B_k s^{(k)}} + \dfrac{y^{(k)} y^{(k)\mathrm{T}}}{y^{(k)\mathrm{T}} s^{(k)}}$ 产生的矩阵序列 $\{B_k\}$ 是对称正定矩阵序列。从而，对所有的 $k$，方程组 $B_k d + \nabla f(x^{(k)}) = 0$ 有唯一解 $d^{(k)}$。而且，由**定理 2.1.1** 知，$d^{(k)}$ 是 $f$ 在 $x^{(k)}$ 处的下降方向。
- **命题 4.1.2**：设 $d^{(k)}$ 满足 $\nabla f(x^{(k)})^\mathrm{T} d^{(k)} < 0$。若下面的条件之一成立，则 $y^{(k)\mathrm{T}} s^{(k)} > 0, \ (\forall k \geqslant 0)$ 
	(1) 算法中采用精确线性搜索或 Wolfe-Powell 型线性搜索。
	(2) 函数 $f$ 二次连续可微且对每个 $x \in \mathbb{R}^n,\ \nabla^2 f(x)$ 正定。
	- *证明过程* 
		*第 1 步*：证明条件 (1) 满足时结论成立
		对于精确线性搜索，我们有 $\nabla f(x^{(k+1)})^\mathrm{T} d^{(k)} = 0$ 
		因此 $y^{(k)\mathrm{T}} s^{(k)} = \alpha_k \left[ \nabla f(x^{(k+1)}) - \nabla f(x^{(k)}) \right]^\mathrm{T} d^{(k)} = -\alpha_k \nabla f(x^{(k)})^\mathrm{T} d^{(k)} > 0$ 
		若采用 Wolfe-Powell 型线性搜索，则由 $\begin{cases} f(x^{(k)} + \alpha_k d^{(k)}) \leqslant f(x^{(k)}) + \sigma_1 \alpha_k \nabla f(x^{(k)})^{\mathrm{T}} d^{(k)} \\ \nabla f(x^{(k)} + \alpha_k d^{(k)})^{\mathrm{T}} d^{(k)} \geqslant \sigma_2 \nabla f(x^{(k)})^{\mathrm{T}} d^{(k)} \end{cases}$ 中的第二个不等式得 $y^{(k)\mathrm{T}} s^{(k)} = \alpha_k \left[ \nabla f(x^{(k+1)}) - \nabla f(x^{(k)}) \right]^\mathrm{T} d^{(k)} \geqslant -(1 - \sigma_2) \alpha_k \nabla f(x^{(k)})^\mathrm{T} d^{(k)} > 0$ 
		*第 2 步*：证明条件 (2) 满足时结论成立
		若 $f$ 二次连续可微且对所有的 $x \in \mathbb{R}^n$，$\nabla^2 f(x)$ 正定，则由中值定理有 $y^{(k)\mathrm{T}} s^{(k)} = s^{(k)\mathrm{T}} \left[ \int_0^1 \nabla^2 f\left( x^{(k)} + \tau s^{(k)} \right) d\tau \right] s^{(k)} > 0$ 
		综上证毕！
	- 该命题给出了保证 $y^{(k)\mathrm{T}} s^{(k)} > 0 \ (\forall k \geqslant 0)$ 的条件。
	- 上面的命题表明，若在 BFGS 算法中采用精确线性搜索或 Wolfe-Powell 型线性搜索，只要 $B_0$ 对称正定，则由算法产生的矩阵序列 $\{ B_k \}$ 是对称正定矩阵序列。而且，当 BFGS 算法用于求解一致凸函数的极小值问题时，只要 $B_0$ 对称正定，不论采用何种线性搜索，算法产生的矩阵序列 $\{ B_k \}$ 是对称正定矩阵序列。
---
- **算法 4.1** (**BFGS 算法**)
	- *第 1 步*：取初始点 $x^{(0)} \in \mathbb{R}^n$，初始对称正定矩阵 $B_0 \in \mathbb{R}^{n \times n}$，精度 $\varepsilon > 0$，令 $k := 0$ 
	- *第 2 步*：若 $\|\nabla f(x^{(k)})\| \leqslant \varepsilon$，则算法终止，得问题的解 $x^{(k)}$ 
	- *第 3 步*：解线性方程组 $B_k d + \nabla f(x^{(k)}) = 0$ 得解 $d^{(k)}$ 
	- *第 4 步*：由线性搜索确定步长 $\alpha_k$ 
	- *第 5 步*：令 $x^{(k+1)} = x^{(k)} + \alpha_k d^{(k)}$。若 $\|\nabla f(x^{(k+1)})\| \leqslant \varepsilon$，则得解 $x^{(k+1)}$。否则，由 BFGS 修正公式 $B_{k+1} = B_k - \dfrac{B_k s^{(k)} s^{(k)\mathrm{T}} B_k}{s^{(k)\mathrm{T}} B_k s^{(k)}} + \dfrac{y^{(k)} y^{(k)\mathrm{T}}}{y^{(k)\mathrm{T}} s^{(k)}}$  确定 $B_{k+1}$ 
	- *第 6 步*：令 $k := k + 1$，转*第 3 步* 
- *算法 4.1 注释*：若在**算法 4.1** 的*第 4 步* 中采用 Armijo 型线性搜索，由于不能保证 $y^{(k)\mathrm{T}} s^{(k)} > 0$，此时，$B_k$ 的正定性不能由线性搜索保证。为了保证采用 Armijo 型线性搜索时矩阵 $B_k$ 的对称正定性，可采用如下的修正方式：$B_{k+1} = \begin{cases} B_k - \dfrac{B_k s^{(k)} s^{(k)\mathrm{T}} B_k}{s^{(k)\mathrm{T}} B_k s^{(k)}} + \dfrac{y^{(k)} y^{(k)\mathrm{T}}}{y^{(k)\mathrm{T}} s^{(k)}}, & \text{若 } y^{(k)\mathrm{T}} s^{(k)} > 0 \\ B_k, & \text{若 } y^{(k)\mathrm{T}} s^{(k)} \leqslant 0 \end{cases}$，不难看出，只要 $B_0$ 对称正定，上述修正方式可保证矩阵序列 $\{ B_k \}$ 为对称正定矩阵序列。
- *补充* 
	利用**定理 1.2.8** 中 **Sherman-Morrison 公式** $(A + uv^{\mathrm{T}})^{-1} = A^{-1} - \dfrac{A^{-1} uv^{\mathrm{T}} A^{-1}}{1 + v^{\mathrm{T}} A^{-1} u}$，不难导出 BFGS 修正公式的逆修正公式如下：
	$$
	\begin{aligned}
	H_{k+1} =& \left( I - \frac{s^{(k)} y^{(k)\mathrm{T}}}{y^{(k)\mathrm{T}} s^{(k)}} \right) H_k \left( I - \frac{s^{(k)} y^{(k)\mathrm{T}}}{y^{(k)\mathrm{T}} s^{(k)}} \right)^{\mathrm{T}} + \frac{s^{(k)} s^{(k)\mathrm{T}}}{y^{(k)\mathrm{T}} s^{(k)}} \\
	=& H_k + \frac{(s^{(k)} - H_k y^{(k)}) s^{(k)\mathrm{T}} + s^{(k)} (s^{(k)} - H_k y^{(k)})^{\mathrm{T}}}{y^{(k)\mathrm{T}} s^{(k)}} \\
	&- \frac{(s^{(k)} - H_k y^{(k)})^{\mathrm{T}} y^{(k)}}{(y^{(k)\mathrm{T}} s^{(k)})^2} s^{(k)} s^{(k)\mathrm{T}}
	\end{aligned} \tag{BFGS-1}
	$$
	其中 $H_k = B_k^{-1},\ H_{k+1} = B_{k+1}^{-1}$ 
### 4-1-4 Broyden 族算法及其性质
- **DFP (Davidon-Fletcher-Powell) 公式**：秩 2 修正拟 Newton 法中另一个著名的修正公式是 **DFP (Davidon-Fletcher-Powell) 公式** 
	- 其修正公式如下：
		$$
		\begin{aligned}
		B_{k+1} &= \left( I - \frac{y^{(k)} s^{(k)\mathrm{T}}}{y^{(k)\mathrm{T}} s^{(k)}} \right) B_k \left( I - \frac{y^{(k)} s^{(k)\mathrm{T}}}{y^{(k)\mathrm{T}} s^{(k)}} \right)^{\mathrm{T}} + \frac{y^{(k)} y^{(k)\mathrm{T}}}{y^{(k)\mathrm{T}} s^{(k)}} \\
		&= B_k + \frac{(y^{(k)} - B_k s^{(k)}) y^{(k)\mathrm{T}} + y^{(k)} (y^{(k)} - B_k s^{(k)})^{\mathrm{T}}}{y^{(k)\mathrm{T}} s^{(k)}} - \frac{(y^{(k)} - B_k s^{(k)})^{\mathrm{T}} s^{(k)}}{(y^{(k)\mathrm{T}} s^{(k)})^2} y^{(k)} y^{(k)\mathrm{T}}
		\end{aligned} \tag{DFP}
		$$
	- 其逆修正公式为 $H_{k+1} = H_k - \dfrac{H_k y^{(k)} y^{(k)\mathrm{T}} H_k}{y^{(k)\mathrm{T}} H_k y^{(k)}} + \dfrac{s^{(k)} s^{(k)\mathrm{T}}}{y^{(k)\mathrm{T}} s^{(k)}}$ 
- **DFP 算法**：若将**算法 4.1** 中*第 5 步*的修正公式用 DFP 公式 $(DFP)$ 替换，则相应的算法称为 **DFP 算法**，其步骤与 BFGS 算法类似，不再重复
	- 比较 BFGS 修正公式 $B_{k+1} = B_k - \dfrac{B_k s^{(k)} s^{(k)\mathrm{T}} B_k}{s^{(k)\mathrm{T}} B_k s^{(k)}} + \dfrac{y^{(k)} y^{(k)\mathrm{T}}}{y^{(k)\mathrm{T}} s^{(k)}}$ 与 DFP 修正公式 $(DFP)$ 以及它们的逆修正公式 $(BFGS-1)$ 与 $H_{k+1} = H_k - \dfrac{H_k y^{(k)} y^{(k)\mathrm{T}} H_k}{y^{(k)\mathrm{T}} H_k y^{(k)}} + \dfrac{s^{(k)} s^{(k)\mathrm{T}}}{y^{(k)\mathrm{T}} s^{(k)}}$，不难发现，两者之间有下面的关系：$B_{k+1} \longleftrightarrow H_{k+1},\ B_k \longleftrightarrow H_k,\ s^{(k)} \longleftrightarrow y^{(k)}$ 
	- **对偶关系**：BFGS 修正公式与 DFP 修正公式间的上述关系称为**对偶关系** 
- **Broyden 族修正公式**、**Broyden 族算法**：BFGS 公式与 DFP 公式的加权线性组合构成一类修正公式：$B_{k+1}^{\phi_k} = \phi_k B_{k+1}^{\mathrm{BFGS}} + (1 - \phi_k) B_{k+1}^{\mathrm{DFP}}$、$H_{k+1}^{\phi_k} = \phi_k H_{k+1}^{\mathrm{BFGS}} + (1 - \phi_k) H_{k+1}^{\mathrm{DFP}}$，其中 $B_{k+1}^{\text{BFGS}}$、$B_{k+1}^{\text{DFP}}$、$H_{k+1}^{\text{BFGS}}$ 和 $H_{k+1}^{\text{DFP}}$ 分别由 BFGS 公式和 DFP 公式确定，$\phi_k$ 为参数。这两个修正公式称为 **Broyden 族修正公式**。相应的拟 Newton 法称为 **Broyden 族算法**
- **命题 4.1.3**：设 $B_k$ 对称正定，$B_{k+1}^{\phi_k}$ 由Broyden族修正公式 $B_{k+1}^{\phi_k} = \phi_k B_{k+1}^{\mathrm{BFGS}} + (1 - \phi_k) B_{k+1}^{\mathrm{DFP}}$ 或 $H_{k+1}^{\phi_k} = \phi_k H_{k+1}^{\mathrm{BFGS}} + (1 - \phi_k) H_{k+1}^{\mathrm{DFP}}$ 确定且 $\phi_k \in [0,1]$。则当且仅当 $y^{(k)\mathrm{T}} s^{(k)} > 0$ 时，$B_{k+1}^{\phi_k}$ 对称正定
- **定理 4.1.2**：设 $\{x^{(k)}\}$ 和 $\{z^{(k)}\}$ 分别是由 Broyden 族算法求解问题 $\min f(x),\ (x\in \mathbb R^n)$ 和 $\min F(z) = f(Az + a),\ (z \in \mathbb{R}^n)$ 产生的点列，其中 $z^{(0)},B_0^z$ 满足 $x^{(0)} = Az^{(0)} + a,\ B_0^x = A^{-\mathrm{T}} B_0^z A^{-1}$。若取 $\alpha_k^x = \alpha_k^z$，则 $x^{(k)} = A z^{(k)} + a,\ B_k^x = A^{-\mathrm{T}} B_k^z A^{-1},\ (k = 0,1,\cdots)$ 
	- *证明过程* 
		设 $A \in \mathbb{R}^{n \times n}$ 非奇异，$a \in \mathbb{R}^n$。作仿射变换 $x = Az + a$ 
		考察求解如下无约束问题 $\min F(z) = f(Az + a),\ (z \in \mathbb{R}^n)$ 的 Broyden 族算法。
		记 $\{x^{(k)}\}$ 和 $\{z^{(k)}\}$ 分别表示求解问题 $\min f(x),\ (x\in \mathbb R^n)$ 和 $\min F(z) = f(Az + a),\ (z \in \mathbb{R}^n)$ 的 Broyden 族算法产生的点列，$\{B_k^x\}$ 和 $\{B_k^z\}$ 分别表示算法产生的矩阵序列。
		若令 $x^{(0)} = Az^{(0)} + a,\ B_0^x = A^{-\mathrm{T}} B_0^z A^{-1}$，注意到 $\nabla F(z^{(0)}) = A^{\mathrm{T}} \nabla f(x^{(0)})$，解相应的子问题 $B_0^x d + \nabla f(x^{(0)}) = 0,\ B_0^z d + \nabla F(z^{(0)}) = 0$ 可得 $d_x^{(0)} = A d_z^{(0)}$ 
		令 $\alpha_k^x$ 和 $\alpha_k^z$ 分别表示求解问题 $\min f(x),\ (x\in \mathbb R^n)$ 和 $\min F(z) = f(Az + a),\ (z \in \mathbb{R}^n)$ 的 Broyden 族算法产生的步长。则 $x^{(1)} = x^{(0)} + \alpha_0^x d_x^{(0)} = A(z^{(0)} + \alpha_0^z d_z^{(0)}) + a$ 
		因此，若取 $\alpha_0^z = \alpha_0^x$，则 $z^{(1)} = z^{(0)} + \alpha_0^z d_z^{(0)} = z^{(0)} + \alpha_0^x d_z^{(0)}$ 
		由此可得 $s_x^{(0)} = A s_z^{(0)},\ y_x^{(0)} = A^{\mathrm{T}} y_z^{(0)}$ 
		在此基础上，不难证明 $B_1^x = A^{-\mathrm{T}} B_1^z A^{-1}$ 
		利用归纳法，重复上述过程，可以证明：对所有 $k \geqslant 0$，若取 $\alpha_k^x = \alpha_k^z$，则有 $x^{(k)} = A z^{(k)} + a, \ B_k^x = A^{-\mathrm{T}} B_k^z A^{-1}$  
		证毕！
	- 该定理展示了 Broyden 族算法还具有的一个有用的性质——**仿射不变性** 
- **定理 4.1.3**：设 $\{x^{(k)}\}$ 和 $\{z^{(k)}\}$ 分别是由 Broyden 族算法求解问题 $\min f(x),\ (x\in \mathbb R^n)$ 和 $\min F(z) = f(Az + a),\ (z \in \mathbb{R}^n)$ 产生的点列，其中 $z^{(0)},\ B_0^z$ 满足 $x^{(0)} = Az^{(0)} + a,\ B_0^x = A^{-\mathrm{T}} B_0^z A^{-1}$。若 $x^{(k)} = A z^{(k)} + a\ (\forall k = 0,1,\cdots)$，则 $\alpha_k^x = \alpha_k^z,\ B_k^x = A^{-\mathrm{T}} B_k^z A^{-1},\ (k = 0,1,\cdots)$ 
	- 该定理为**定理 4.1.2** 的另一种描述
- **仿射不变性**：由**定理 4.1.2** 或**定理 4.1.3** 给出的性质称为**仿射不变性**
## 4-2 拟 Newton 法的收敛性理论  
- 本节介绍拟 Newton 法的收敛性理论。首先我们指出，线性搜索对算法的收敛性有影响。采用不同线性搜索的拟 Newton 法的收敛性质也不相同
- *假设条件*：函数 $f: \mathbb{R}^n \to \mathbb{R}$ 二次连续可微。且水平集 $\Omega(x^{(0)}) = \{ x \in \mathbb{R}^n \mid f(x) \leqslant f(x^{(0)}) \}$ 是有界凸集且函数 $f$ 在 $\Omega(x^{(0)})$ 上是一致凸函数。
	- 故存在正常数 $m \leqslant M$，使得 $m \|d\|^2 \leqslant d^{\mathrm{T}} \nabla^2 f(x) d \leqslant M \|d\|^2,\ (\forall\ x \in \Omega(x^{(0)}),\ d \in \mathbb{R}^n)$ 
- **引理 4.2.1**：设**假设 4.2.1**成立，则序列 $\left\{ \dfrac{\|y^{(k)}\|}{\|s^{(k)}\|} \right\},\ \left\{ \dfrac{\|s^{(k)}\|}{\|y^{(k)}\|} \right\},\ \left\{ \dfrac{y^{(k)\mathrm{T}} s^{(k)}}{\|s^{(k)}\|^2} \right\},\ \left\{ \dfrac{y^{(k)\mathrm{T}} s^{(k)}}{\|y^{(k)}\|^2} \right\},\ \left\{ \dfrac{\|y^{(k)}\|^2}{y^{(k)\mathrm{T}} s^{(k)}} \right\}$ 都是有界序列
	- *证明过程* 
		利用中值定理有 $\displaystyle y^{(k)} = \nabla f(x^{(k+1)}) - \nabla f(x^{(k)}) = \left[ \int_0^1 \nabla^2 f(x^{(k)} + \tau s^{(k)}) d\tau \right] s^{(k)} \triangleq \bar{G}_k s^{(k)}$ 
		注意到在 $\Omega(x^{(0)})$ 是凸集，对任何 $\tau \in [0,1]$，$x^{(k)} + \tau s^{(k)} = (1 - \tau)x^{(k)} + \tau x^{(k+1)} \in \Omega(x^{(0)})$ 
		由*假设条件*中的第二个条件知，矩阵 $\bar{G}_k$ 一致正定。
		故存在正常数 $m_1 \leqslant M_1$ 使得 $m_1 \|s^{(k)}\| \leqslant \|y^{(k)}\| \leqslant M_1 \|s^{(k)}\|,\ m_1 \|s^{(k)}\|^2 \leqslant y^{(k)\mathrm{T}} s^{(k)} \leqslant M_1 \|s^{(k)}\|^2$ 
		利用上面的不等式不难证明引理的结论，证毕！
- **定理 4.2.1**：设 $f: \mathbb{R}^n \to \mathbb{R}$ 连续可微，水平集 $\Omega(x^{(0)})$ 有界，设 $B_0$ 对称正定，则采用精确线性搜索的 Broyden 族算法 $(\phi_k \in [0,1])$ 产生的点列 $\{x^{(k)}\}$ 与 $\phi_k$ 无关
	- 该定理考察了采用精确线性搜索的拟 Newton 法的收敛性
	- 该定理表明：从同一初始点和同一初始对称正定矩阵出发，采用精确线性搜索的 Broyden 族算法 $(\phi_k \in [0,1])$ 中的所有算法产生相同的点列。因此，只要其中的算法之一收敛，则 Broyden 族算法中的任何一个算法都收敛
- **定理 4.2.2**：设*假设条件*成立，则采用精确线性搜索或 Wolfe - Powell 型线性搜索的 BFGS 算法产生的点列 $\{x^{(k)}\}$ 收敛于问题 $\min f(x),\ (x\in \mathbb R^n)$ 的唯一极小点值 $x^*$ 
	- 该定理为 Broyden 族算法中的 BFGS 算法 ($\phi_k = 1$) 的全局收敛性定理
	- 为证明定理 4.2.2，我们先证明几个引理。
- **引理 4.2.2**：设*假设条件*成立，则存在常数 $C > 0$ 使得 $\mathrm{tr}(B_k) \leqslant C k, \ (\forall\ k \geqslant 0)$，$\dfrac{1}{k + 1} \sum\limits_{i=0}^k \dfrac{\|B_i s^{(i)}\|^2}{s^{(i)\mathrm{T}} B_i s^{(i)}} \leqslant C,\ (\forall\ k \geqslant 0)$，其中 $\mathrm{tr}(A)$ 表示矩阵 $A$ 的迹
	- *证明过程* 
		设 $C_1 > 0$ 是**引理 4.2.1** 中序列的上界。在 $B_{k+1} = B_k - \dfrac{B_k s^{(k)} s^{(k)\mathrm{T}} B_k}{s^{(k)\mathrm{T}} B_k s^{(k)}} + \dfrac{y^{(k)} y^{(k)\mathrm{T}}}{y^{(k)\mathrm{T}} s^{(k)}}$ 两端求矩阵的迹得  
		$$
		\begin{aligned}
		\mathrm{tr}(B_{k + 1}) &= \mathrm{tr}(B_k) - \frac{\|B_k s^{(k)}\|^2}{s^{(k)\mathrm{T}} B_k s^{(k)}} + \frac{\|y^{(k)}\|^2}{y^{(k)\mathrm{T}} s^{(k)}} \\
		&\leqslant \mathrm{tr}(B_k) - \frac{\|B_k s^{(k)}\|^2}{s^{(k)\mathrm{T}} B_k s^{(k)}} + C_1 \\
		&\vdots \\
		&\leqslant \mathrm{tr}(B_0) - \sum_{i=0}^k \frac{\|B_i s^{(i)}\|^2}{s^{(i)\mathrm{T}} B_i s^{(i)}} + C_1(k + 1)
		\end{aligned}
		$$
		令 $C = \mathrm{tr}(B_0) + C_1$，则得 $\mathrm{tr}(B_k) \leqslant C k, \ (\forall\ k \geqslant 0)$，而且由 $B_{k + 1}$ 的对称正定性，$\mathrm{tr}(B_{k + 1}) > 0$ 
		故得 $\dfrac{1}{k + 1} \sum\limits_{i=0}^k \dfrac{\|B_i s^{(i)}\|^2}{s^{(i)\mathrm{T}} B_i s^{(i)}} \leqslant \mathrm{tr}(B_0) + C_1 = C, \ (\forall\ k \geqslant 0)$ 
		因此 $\dfrac{1}{k + 1} \sum\limits_{i=0}^k \dfrac{\|B_i s^{(i)}\|^2}{s^{(i)\mathrm{T}} B_i s^{(i)}} \leqslant C,\ (\forall\ k \geqslant 0)$ 也成立，证毕！
- **引理 4.2.3**：设*假设条件*成立，点列 $\{x^{(k)}\}$ 由采用精确线性搜索或 Wolfe-Powell 型线性搜索的 BFGS 算法产生，则存在常数 $C_2 > 0$，使得 $\|d^{(k)}\| \leqslant C_2 \alpha_k^{-1} \|\nabla f(x^{(k)})\| \cos\theta_k$，其中 $\theta_k$ 表示 $d^{(k)}$ 与 $-\nabla f(x^{(k)})$ 间的夹角。而且，存在常数 $\alpha > 0$，使得算法产生的步长 $\alpha_k$ 满足 $\prod\limits_{i=0}^k \alpha_i \geqslant \alpha^{k+1},\ (\forall\ k \geqslant 0)$ 
	- *证明过程* 
		*第 1 步*：先证明 $\|d^{(k)}\| \leqslant C_2 \alpha_k^{-1} \|\nabla f(x^{(k)})\| \cos\theta_k$ 
		由*假设条件*中第二点，存在常数 $m_2 > 0$，使得 $y^{(k)\mathrm{T}} s^{(k)} \geqslant m_2 \|s^{(k)}\|^2,\ (\forall k \geqslant 0)$ 
		若采用精确线性搜索，我们有
		$$
		\begin{aligned}
		m_2 \|s^{(k)}\|^2 &\leqslant y^{(k)\mathrm{T}} s^{(k)} = \left[ \nabla f(x^{(k+1)}) - \nabla f(x^{(k)}) \right]^{\mathrm{T}} s^{(k)} \\
		&= -\nabla f(x^{(k)})^{\mathrm{T}} s^{(k)} = \|\nabla f(x^{(k)})\| \|s^{(k)}\| \cos\theta_k
		\end{aligned}
		$$
		此式包含了式 $\|d^{(k)}\| \leqslant C_2 \alpha_k^{-1} \|\nabla f(x^{(k)})\| \cos\theta_k$ 
		若采用 Wolfe-Powell 型线性搜索，利用 Taylor 展开得  
		$$
		\begin{aligned}
		f(x^{(k+1)}) &= f(x^{(k)}) + \nabla f(x^{(k)})^{\mathrm{T}} s^{(k)} + \frac{1}{2} s^{(k)\mathrm{T}} \nabla^2 f\bigl(x^{(k)} + \mu_k s^{(k)}\bigr) s^{(k)} \\
		&\geqslant f(x^{(k)}) + \nabla f(x^{(k)})^{\mathrm{T}} s^{(k)} + \frac{1}{2} m_1 \|s^{(k)}\|^2
		\end{aligned}
		$$
		其中，$\mu_k \in (0,1)$ 
		上式代入 $\begin{cases} f(x^{(k)} + \alpha_k d^{(k)}) \leqslant f(x^{(k)}) + \sigma_1 \alpha_k \nabla f(x^{(k)})^{\mathrm{T}} d^{(k)} \\ \nabla f(x^{(k)} + \alpha_k d^{(k)})^{\mathrm{T}} d^{(k)} \geqslant \sigma_2 \nabla f(x^{(k)})^{\mathrm{T}} d^{(k)} \end{cases}$ 的第一个不等式得 $\dfrac{1}{2} m_1 \|s^{(k)}\|^2 \leqslant -\bigl(1 - \sigma_1\bigr) \nabla f(x^{(k)})^{\mathrm{T}} s^{(k)} = \bigl(1 - \sigma_1\bigr) \|\nabla f(x^{(k)})\| \, \|s^{(k)}\| \cos\theta_k$，由此亦得 $\|d^{(k)}\| \leqslant C_2 \alpha_k^{-1} \|\nabla f(x^{(k)})\| \cos\theta_k$  
		*第 2 步*：再证明式 $\prod\limits_{i=0}^k \alpha_i \geqslant \alpha^{k+1},\ (\forall\ k \geqslant 0)$ 
		在 $B_{k+1} = B_k - \dfrac{B_k s^{(k)} s^{(k)\mathrm{T}} B_k}{s^{(k)\mathrm{T}} B_k s^{(k)}} + \dfrac{y^{(k)} y^{(k)\mathrm{T}}}{y^{(k)\mathrm{T}} s^{(k)}}$ 两端取行列式，利用公式 $\det(I + u_{1} v_{1}^{\mathrm{T}} + u_{2} v_{2}^{\mathrm{T}}) = (1 + u_{1}^{\mathrm{T}} v_{1})(1 + u_{2}^{\mathrm{T}} v_{2}) - (u_{1}^{\mathrm{T}} v_{2})(v_{1}^{\mathrm{T}} u_{2})$ 得 $\det(B_{k+1}) = \det(B_k) \cdot \dfrac{y^{(k)\mathrm{T}} s^{(k)}}{s^{(k)\mathrm{T}} B_k s^{(k)}} = \det(B_0) \prod\limits_{i=0}^k \dfrac{y^{(i)\mathrm{T}} s^{(i)}}{s^{(i)\mathrm{T}} B_i s^{(i)}}$ 
		若采用精确线性搜索，我们有 $y^{(k)\mathrm{T}} s^{(k)} = \bigl[\nabla f(x^{(k+1)}) - \nabla f(x^{(k)})\bigr]^{\mathrm{T}} s^{(k)} = -\nabla f(x^{(k)})^{\mathrm{T}} s^{(k)} = \alpha_k^{-1} s^{(k)\mathrm{T}} B_k s^{(k)}$ 
		若采用 Wolfe-Powell 型线性搜索，由 $\begin{cases} f(x^{(k)} + \alpha_k d^{(k)}) \leqslant f(x^{(k)}) + \sigma_1 \alpha_k \nabla f(x^{(k)})^{\mathrm{T}} d^{(k)} \\ \nabla f(x^{(k)} + \alpha_k d^{(k)})^{\mathrm{T}} d^{(k)} \geqslant \sigma_2 \nabla f(x^{(k)})^{\mathrm{T}} d^{(k)} \end{cases}$ 中的第二个不等式得  
		$$
		\begin{aligned}
		y^{(k)\mathrm{T}} s^{(k)} &= \bigl[\nabla f(x^{(k+1)}) - \nabla f(x^{(k)})\bigr]^{\mathrm{T}} s^{(k)} \geqslant -\bigl(1 - \sigma_2\bigr) \nabla f(x^{(k)})^{\mathrm{T}} s^{(k)} \\
		&= \bigl(1 - \sigma_2\bigr) \alpha_k^{-1} s^{(k)\mathrm{T}} B_k s^{(k)}
		\end{aligned}
		$$
		总之，存在常数 $\beta > 0$，使得 $y^{(k)\mathrm{T}} s^{(k)} \geqslant \beta \alpha_k^{-1} s^{(k)\mathrm{T}} B_k s^{(k)}$ 
		将上式代入到 $\det(B_{k+1}) = \det(B_k) \cdot \dfrac{y^{(k)\mathrm{T}} s^{(k)}}{s^{(k)\mathrm{T}} B_k s^{(k)}} = \det(B_0) \prod\limits_{i=0}^k \dfrac{y^{(i)\mathrm{T}} s^{(i)}}{s^{(i)\mathrm{T}} B_i s^{(i)}}$ 得 $\det(B_{k+1}) \geqslant \det(B_0) \beta^{k+1} \prod_{i=0}^k \alpha_i^{-1}$ 
		另一方面，由行列式的性质及 $\mathrm{tr}(B_k) \leqslant C k, \ (\forall\ k \geqslant 0)$ 知 $\det(B_{k+1}) \leqslant \left[ \dfrac{1}{n} \mathrm{tr}(B_{k+1}) \right]^n \leqslant \left[ \dfrac{C(k+1)}{n} \right]^n$ 
		因此，存在常数 $\beta_1 > 0$，使得 $\det(B_{k+1}) \leqslant \beta_1^{k+1}$ 
		由此及 $\det(B_{k+1}) \geqslant \det(B_0) \beta^{k+1} \prod_{i=0}^k \alpha_i^{-1}$ 得 $\prod\limits_{i=0}^k \alpha_i \geqslant \det(B_0) \bigl( \beta \beta_1^{-1} \bigr)^{k+1}$ 
		不难看出，上式包含了 $\prod\limits_{i=0}^k \alpha_i \geqslant \alpha^{k+1},\ (\forall\ k \geqslant 0)$，证毕！
- *定理 4.2.2 的证明* 
	先证明$\lim\limits_{k \to \infty}\inf \bigl\| \nabla f(x^{(k)}) \bigr\| = 0$ 
	由 $\dfrac{1}{k + 1} \sum\limits_{i=0}^k \dfrac{\|B_i s^{(i)}\|^2}{s^{(i)\mathrm{T}} B_i s^{(i)}} \leqslant C,\ (\forall\ k \geqslant 0)$ 及几何不等式得：对任何 $k \geqslant 0$，$\prod\limits_{i=0}^{k} \left( \dfrac{\| B_i s^{(i)} \|^2}{s^{(i)\mathrm{T}} B_i s^{(i)}} \right)^{\frac{1}{k+1}} \leqslant \dfrac{1}{k+1} \sum\limits_{i=0}^{k} \dfrac{\| B_i s^{(i)} \|^2}{s^{(i)\mathrm{T}} B_i s^{(i)}} \leqslant C$ 
	记 $\theta_k$ 为 $d^{(k)}$ 与 $-\nabla f(x^{(k)})$ 的夹角
	由上面的不等式可得 $C^{-(k+1)} \leqslant \prod\limits_{i=0}^{k} \dfrac{s^{(i)\mathrm{T}} B_i s^{(i)}}{\| B_i s^{(i)} \|^2} = \prod\limits_{i=0}^{k} \dfrac{-\nabla f(x^{(i)})\mathrm{T} d^{(i)}}{\| \nabla f(x^{(i)}) \|^2} = \prod\limits_{i=0}^{k} \dfrac{\| d^{(i)} \| \cos \theta_i}{\| \nabla f(x^{(i)}) \|} \leqslant \prod\limits_{i=0}^{k} \dfrac{C_2 \cos^2 \theta_i}{\alpha_i}$ 
	其中最后一个不等式由 $\|d^{(k)}\| \leqslant C_2 \alpha_k^{-1} \|\nabla f(x^{(k)})\| \cos\theta_k$ 得到。
	从而，由 $\prod\limits_{i=0}^k \alpha_i \geqslant \alpha^{k+1},\ (\forall\ k \geqslant 0)$ 及上式得 $\prod\limits_{i=0}^{k} \cos^2 \theta_i \geqslant (\alpha C^{-1} C_2^{-1})^{k+1}$，即**定理 2.4.4** 中的不等式 $\prod\limits_{i=0}^{k-1} \cos \theta_i \geqslant \eta^k$ 成立
	于是，由**定理 2.4.4** 得 $\lim\limits_{k \to \infty}\inf \bigl\| \nabla f(x^{(k)}) \bigr\| = 0$ 
	进而，由第二章习题知 $\{x^{(k)}\}$ 收敛于 $f$ 的唯一最小值点。证毕！
---
- **定理 4.2.3**：设**定理 4.2.2** 中的条件成立，则采用精确搜索线性搜索 Broyden 族算法 ($\phi_k \in [0,1]$) 产生的点列 $\{x^{(k)}\}$ 收敛于 $\min f(x),\ (x\in \mathbb R^n)$ 在 $\Omega(x^{(0)})$ 上的唯一极小值点
	- 该定理为：由**定理 4.2.1** 和**定理 4.2.2** 直接建立采用精确线性搜索的 Broyden 族算法的全局收敛性定理
- **定理 4.2.4**：设*假设条件*成立，则采用 Wolfe-Powell 型线性搜索的 Broyden 族算法 ($\phi_k \in (0,1]$) 产生的点列 $\{x^{(k)}\}$ 收敛于问题 $\min f(x),\ (x\in \mathbb R^n)$ 在 $\Omega(x^{(0)})$ 上的唯一极小值点。
	- 该定理为：对采用 Wolfe-Powell 型线性搜索的 Broyden 族算法的收敛性定理。
	- 上面的全局收敛性定理中的条件可放宽为 $f$ 是凸函数，相应的定理如下。
- **定理 4.2.5**：设 $f$ 是二次连续可微的凸函数，$f$ 在水平集 $\Omega(x^{(0)})$ 上有界，且存在常数 $M > 0$，使得 $\|\nabla^2 f(x)\| \leqslant M,\ (\forall\ x \in \Omega(x^{(0)}))$，则采用 Wolfe-Powell 型线性搜索的 Broyden 族算法当 $\phi_k \in (0,1]$ 时产生的点列 $\{x^{(k)}\}$ 满足 $\lim\limits_{k \to \infty} \inf \|\nabla f(x^{(k)})\| = 0$ 
---
- *注意*：上面的关于拟 Newton 法的全局收敛性定理只考虑采用精确线性搜索或 Wolfe-Powell 型线性搜索的算法。
- *缺陷*：如前所述，若采用Armijo型线性搜索，当 $\nabla^2 f(x)$ 不正定时，算法不能保证 $y^{(k)\mathrm{T}} s^{(k)} > 0$。此时，BFGS 法或 Broyden 族算法产生的矩阵 $B_{k+1}$ 不一定对称正定，因而，相应的拟 Newton 方向可能不是 $f$ 在 $x^{(k)}$ 处的下降方向。
- *修正形式*：为了克服缺陷，可采用如下的修正形式：$B_{k+1} = \begin{cases} B_k - \dfrac{B_k s^{(k)} s^{(k)\mathrm{T}} B_k}{s^{(k)\mathrm{T}} B_k s^{(k)}} + \dfrac{y^{(k)} y^{(k)\mathrm{T}}}{y^{(k)\mathrm{T}} s^{(k)}}, & \text{若 } y^{(k)\mathrm{T}} s^{(k)} > 0 \\ B_k, & \text{若 } y^{(k)\mathrm{T}} s^{(k)} \leqslant 0  \end{cases}$ 
- **定理 4.2.6**：设*假设条件*成立，则采用 Armijo 型线性搜索的 BFGS 算法产生的点列 $\{x^{(k)}\}$ 收敛于问题 $\min f(x),\ (x\in \mathbb R^n)$ 的唯一极小值点 $x^*$ 
	- 类似于**定理 4.2.2** 的证明，该定理建立了采用 Armijo 型线性搜索的 BFGS 算法的全局收敛性定理。
- **定理 4.2.7**：设*假设条件*成立，并设函数 $f$ 的 Hessian 阵 $\nabla^2 f$ 在 $x^*$ 处 Hölder 连续，即存在 $x^*$ 的一个邻域 $U(x^*)$ 以及正常数 $\nu, H$，使得不等式 $\|\nabla^2 f(x) - \nabla^2 f(x^*)\| \leqslant H\|x - x^*\|^\nu$ 对所有 $x \in U(x^*)$ 成立。则由采用 Armijo 型线性搜索或 Wolfe-Powell 型线性搜索的 Broyden 族算法 ($\phi_k \in (0,1]$) 产生的点列 $\{x^{(k)}\}$ 超线性收敛于 $x^*$。而且，当 $k$ 充分大时，$\alpha_k = 1$ 
	- 该定理为：Broyden 族算法的超线性收敛性定理
## 4-3 拟 Newton 法的修正形式
- *缺陷*：上一节中介绍的 BFGS 算法以及 Broyden 族算法的全局收敛性要求目标函数 $f$ 是凸函数。当用于非凸函数极小值问题求解时，有例子说明，采用精确线性搜索或 Wolfe-Powell 搜索的 BFGS 算法不收敛。
- **MBFGS 算法**、**CBFGS 算法**：为了克服 BFGS 算法的这种缺陷，本节，我们介绍**修正的 BFGS 算法**——**MBFGS (Modified BFGS) 算法**以及**保守 BFGS 修正算法**——**CBFGS (Cautious BFGS) 算法** 
- 我们将简要介绍相应的算法及其收敛性质
- *为什么要修正* 
	由于**Newton 法的收敛性定理** (**定理 3.2.2**) 要求 $f$ 是凸函数。因此，作为其近似算法——**拟 Newton 法**的全局收敛性也要求函数 $f$ 是凸的。
	另一方面，在修正 Newton **算法 3.3** 的全局收敛性定理 (**定理 3.2.4**) 中，不必要求 $f$ 是凸函数。
	基于上述观察，我们考虑对拟 Newton 算法进行修改，使其是修正 Newton 法的近似算法。
- *前置分析* 
	设 $f$ 二次连续可微。注意到 $\nabla^2 f(x^{(k+1)})$ 满足 $\nabla^2 f(x^{(k+1)})(x^{(k+1)} - x^{(k)}) \approx \nabla f(x^{(k+1)}) - \nabla f(x^{(k)}) \triangleq \gamma^{(k)}$ 
	令 $\bar{G}_{k+1} = \nabla^2 f(x^{(k+1)}) + \nu_k I$，其中 $I \in \mathbb{R}^{n \times n}$ 是单位矩阵，$\nu_k > 0$ 
	当 $\nu_k$ 充分小时，有 $\bar{G}_{k+1} \approx \nabla^2 f(x^{(k+1)})$ 
	易知，$\bar{G}_{k+1}$ 满足如下近似关系：$\bar{G}_{k+1}(x^{(k+1)} - x^{(k)}) = [\nabla^2 f(x^{(k+1)}) + \nu_k I](x^{(k+1)} - x^{(k)}) \approx \gamma^{(k)} + \nu_k (x^{(k+1)} - x^{(k)})$ 
	令 $s^{(k)} = x^{(k+1)} - x^{(k)}$，$y^{(k)} = \gamma^{(k)} + \nu_k s^{(k)}$，则得如下近似关系：$\bar{G}_{k+1} s^{(k)} \approx y^{(k)}$ 
	对拟 Newton 法进行修正的一种合理的方式是令 $B_{k+1}$ 作为 $\bar{G}_{k+1}$ 的一种近似，使得上面的近似式成立等式，即 $B_{k+1} s^{(k)} = y^{(k)}$ 
	我们先考虑修正的 BFGS 算法——MBFGS 算法，其修正公式如下：$B_{k+1} = B_k - \dfrac{B_k s^{(k)} s^{(k)\mathrm{T}} B_k}{s^{(k)\mathrm{T}} B_k s^{(k)}} + \dfrac{y^{(k)} y^{(k)\mathrm{T}}}{y^{(k)\mathrm{T}} s^{(k)}}$ 
	其中，$s^{(k)} = x^{(k+1)} - x^{(k)}$，$y^{(k)} = \gamma^{(k)} + \nu_k s^{(k)} = \nabla f(x^{(k+1)}) - \nabla f(x^{(k)}) + \nu_k (x^{(k+1)} - x^{(k)})$ 
	不难发现，MBFGS 修正公式与标准的 BFGS 修正公式的唯一区别在于 $y^{(k)}$ 的定义。若 $\nu_k = 0$，则修正的 BFGS 公式与标准 BFGS 公式完全一致。  
	在修正的 BFGS 算法中，参数 $\nu_k$ 的确定十分重要。
	由**定理 3.2.4**，若 $\nu_k$ 满足 $\nu_k \leqslant C\|\nabla f(x^{(k)})\|$，则相应的修正 Newton 算法具有二次收敛速度。
	因此，作为修正 Newton 算法的近似算法，修正的 BFGS 算法中的参数 $\nu_k$ 也应满足 $\nu_k \leqslant C\|\nabla f(x^{(k)})\|$ 
	确定 $\nu_k$ 的另一个原则是使得算法产生的矩阵序列 $\{B_k\}$ 具有对称正定性。
	由**命题 4.1.1** 后的说明知，若采用精确线性搜索或 Wolfe-Powell 型线性搜索，则只要 $B_k$ 对称正定，就可保证 $B_{k+1}$ 对称正定。
	但精确线性搜索或 Wolfe-Powell 型线性搜索的计算量较大。若采用计算量较小的 Armijo 型线性搜索，则 $B_{k+1}$ 的正定性不能保证。
	为了保证 $B_{k+1}$ 的对称正定性，我们可以通过对参数 $\nu_k$ 的调整，使得 $y^{(k)\mathrm{T}} s^{(k)} > 0,\ (\forall k \ge 0)$ 
	满足上式的 $\nu_k$ 的取法有许多，例如，$\nu_k$ 可由下式确定：$\nu_k = C t_k \|\nabla f(x^{(k)})\|^\mu, \ t_k = 1 + \max\left\{ -\dfrac{\gamma^{(k)\mathrm{T}} s^{(k)}}{\|s^{(k)}\|^2}, 0 \right\} C^{-1} \|\nabla f(x^{(k)})\|^{-\mu}$ 
	其中，$\mu > 0$ 和 $C > 0$ 是常数。
	此时，我们有
	$$
	\begin{aligned}
	y^{(k)\mathrm{T}} s^{(k)} &= \gamma^{(k)\mathrm{T}} s^{(k)} + C t_k \|\nabla f(x^{(k)})\|^\mu \|s^{(k)}\|^2 \\
	&= C \|\nabla f(x^{(k)})\|^\mu \|s^{(k)}\|^2 + \gamma^{(k)\mathrm{T}} s^{(k)} + \|s^{(k)}\|^2 \max\left\{ -\frac{\gamma^{(k)\mathrm{T}} s^{(k)}}{\|s^{(k)}\|^2}, 0 \right\} \\
	&\ge C \|\nabla f(x^{(k)})\|^\mu \|s^{(k)}\|^2
	\end{aligned}
	$$
	在上面的基础上，利用**命题 4.1.1** 可得如下定理。
- **定理 4.3.1**：设 $\{B_k\}$ 由修正 BFGS 公式 $B_{k+1} = B_k - \dfrac{B_k s^{(k)} s^{(k)\mathrm{T}} B_k}{s^{(k)\mathrm{T}} B_k s^{(k)}} + \dfrac{y^{(k)} y^{(k)\mathrm{T}}}{y^{(k)\mathrm{T}} s^{(k)}}$ 产生，其中 $\nu_k$ 由 $\nu_k = C t_k \|\nabla f(x^{(k)})\|^\mu, \ t_k = 1 + \max\left\{ -\dfrac{\gamma^{(k)\mathrm{T}} s^{(k)}}{\|s^{(k)}\|^2}, 0 \right\} C^{-1} \|\nabla f(x^{(k)})\|^{-\mu}$ 确定。若 $B_0$ 对称正定，则对所有 $k \geqslant 0$，矩阵 $B_k$ 对称正定。
	- 值得注意的是，上面的定理与算法的线性搜索以及函数 $f$ 的凸性无关。
- **MBFGS 算法**：若将**算法 4.1** 中*第 5 步*的修正方式改为 MBFGS 公式 $B_{k+1} = B_k - \dfrac{B_k s^{(k)} s^{(k)\mathrm{T}} B_k}{s^{(k)\mathrm{T}} B_k s^{(k)}} + \dfrac{y^{(k)} y^{(k)\mathrm{T}}}{y^{(k)\mathrm{T}} s^{(k)}}$，则相应的算法称为 **MBFGS 算法** 
- **定理 4.3.2**：设水平集 $\Omega(x^{(0)}) = \{x \in \mathbb{R}^n \mid f(x) \leqslant f(x^{(0)})\}$ 有界。$D$ 是包含了 $\Omega(x^{(0)})$ 的某个有界闭凸集。函数 $f$ 在 $D$ 上连续可微且其梯度 $\nabla f$ Lipschitz 连续。则采用精确线性搜索或 Armijo 型或 Wolfe-Powell 型线性搜索的 MBFGS 算法产生的点列 $\{x^{(k)}\}$ 满足 $\lim\limits_{k \to \infty} \inf \|\nabla f(x^{(k)})\| = 0$ 
	- 该定理为 MBFGS 算法的全局收敛性定理
- **定理 4.3.3** 
	设下列条件成立  
	(1) 由 MBFGS 算法产生的点列 $\{x^{(k)}\}$ 收敛于 $x^*$ 
	(2) 函数 $f$ 在 $x^*$ 的某邻域内二次连续可微且 $\nabla f(x^*) = 0$，$\nabla^2 f(x^*)$ 对称正定
	(3) 函数 $f$ 的 Hessian 矩阵 $\nabla^2 f$ 在 $x^*$ 处 Hölder 连续
	则采用 Armijo 型或 Wolfe-Powell 型线性搜索的 MBFGS 算法产生的点列 $\{x^{(k)}\}$ 超线性收敛于 $x^*$。而且，当 $k$ 充分大时，$\alpha_k = 1$ 
	- 该定理为 MBFGS 算法的超线性收敛性定理如下
- *MBFGS 算法的优缺点*：该算法用于求解非凸函数极小值问题时也具有全局收敛性。而且，$\{B_k\}$ 的对称正定性与算法的线性搜索以及目标函数的凸性无关。但该算法破坏了 BFGS 算法的仿射不变性质，即**定理 4.1.2** 的结论对 MBFGS 算法不成立
- **保守 BFGS 修正**：为了克服 MBFGS 算法的这一缺陷，同时，保持算法对求解非凸函数极小值问题的全局收敛性及其超线性收敛速度，可采用**保守 BFGS 修正**——**CBFGS (Cautious BFGS) 修正方式** 
	- CBFGS 修正方式如下：$B_{k+1} = \begin{cases} B_k - \dfrac{B_k s^{(k)} s^{(k)\mathrm{T}} B_k}{s^{(k)\mathrm{T}} B_k s^{(k)}} + \dfrac{y^{(k)} y^{(k)\mathrm{T}}}{y^{(k)\mathrm{T}} s^{(k)}}, & \text{若 } \dfrac{y^{(k)\mathrm{T}} s^{(k)}}{\|s^{(k)}\|^2} > \delta \|\nabla f(x^{(k)})\|^\mu \\ B_k, & \text{若 } \dfrac{y^{(k)\mathrm{T}} s^{(k)}}{\|s^{(k)}\|^2} \leqslant \delta \|\nabla f(x^{(k)})\|^\mu  \end{cases}$，其中 $\delta > 0,\ \mu > 0$ 是常数，$s^{(k)} = x^{(k+1)} - x^{(k)}$，$y^{(k)} = \nabla f(x^{(k+1)}) - \nabla f(x^{(k)})$ 
	- *注意*：比较 $B_{k+1} = \begin{cases} B_k - \dfrac{B_k s^{(k)} s^{(k)\mathrm{T}} B_k}{s^{(k)\mathrm{T}} B_k s^{(k)}} + \dfrac{y^{(k)} y^{(k)\mathrm{T}}}{y^{(k)\mathrm{T}} s^{(k)}}, & \text{若 } \dfrac{y^{(k)\mathrm{T}} s^{(k)}}{\|s^{(k)}\|^2} > \delta \|\nabla f(x^{(k)})\|^\mu \\ B_k, & \text{若 } \dfrac{y^{(k)\mathrm{T}} s^{(k)}}{\|s^{(k)}\|^2} \leqslant \delta \|\nabla f(x^{(k)})\|^\mu  \end{cases}$ 与 $B_{k+1} = \begin{cases} B_k - \dfrac{B_k s^{(k)} s^{(k)\mathrm{T}} B_k}{s^{(k)\mathrm{T}} B_k s^{(k)}} + \dfrac{y^{(k)} y^{(k)\mathrm{T}}}{y^{(k)\mathrm{T}} s^{(k)}}, & \text{若 } y^{(k)\mathrm{T}} s^{(k)} > 0 \\ B_k, & \text{若 } y^{(k)\mathrm{T}} s^{(k)} \leqslant 0  \end{cases}$ 不难看出，两者在形式上类似，但 CBFGS 公式较 $B_{k+1} = \begin{cases} B_k - \dfrac{B_k s^{(k)} s^{(k)\mathrm{T}} B_k}{s^{(k)\mathrm{T}} B_k s^{(k)}} + \dfrac{y^{(k)} y^{(k)\mathrm{T}}}{y^{(k)\mathrm{T}} s^{(k)}}, & \text{若 } y^{(k)\mathrm{T}} s^{(k)} > 0 \\ B_k, & \text{若 } y^{(k)\mathrm{T}} s^{(k)} \leqslant 0  \end{cases}$ 公式保守。
	- *进一步分析* 
		容易看出，若 $B_0$ 对称正定，则由 CBFGS 公式产生的矩阵序列 $\{B_k\}$ 满足 $y^{(k)\mathrm{T}} s^{(k)} > 0$。因此，对所有 $k \geqslant 0$，矩阵 $B_k$ 对称正定。该性质与算法的线性搜索以及函数 $f$ 的凸性无关。
		此外，若不等式 $\dfrac{y^{(k)\mathrm{T}} s^{(k)}}{\|s^{(k)}\|^2} > \delta \|\nabla f(x^{(k)})\|^\mu$ 成立，则算法还原为标准的 BFGS 算法。因而，算法的仿射不变性成立。
		事实上由后面的**定理 4.3.5** 可以看出，在一定的条件下，当 $k$ 充分大时，CBFGS 算法还原为标准的 BFGS 算法。
- **CBFGS 算法**：若将**算法 4.1** 中*第 5 步*的修正方式改为 CBFGS 公式 $B_{k+1} = \begin{cases} B_k - \dfrac{B_k s^{(k)} s^{(k)\mathrm{T}} B_k}{s^{(k)\mathrm{T}} B_k s^{(k)}} + \dfrac{y^{(k)} y^{(k)\mathrm{T}}}{y^{(k)\mathrm{T}} s^{(k)}}, & \text{若 } \dfrac{y^{(k)\mathrm{T}} s^{(k)}}{\|s^{(k)}\|^2} > \delta \|\nabla f(x^{(k)})\|^\mu \\ B_k, & \text{若 } \dfrac{y^{(k)\mathrm{T}} s^{(k)}}{\|s^{(k)}\|^2} \leqslant \delta \|\nabla f(x^{(k)})\|^\mu  \end{cases}$，则相应的算法称为 **CBFGS 算法** 
- **定理 4.3.4**：设**定理 4.3.2** 的条件成立。则采用精确线性搜索或 Armijo 型或 Wolfe-Powell 型线性搜索的 CBFGS 算法产生的点列 $\{x^{(k)}\}$ 满足 $\lim\limits_{k \to \infty} \inf \|\nabla f(x^{(k)})\| = 0$ 
	- 该定理为 CBFGS 算法的全局收敛性定理
- **定理 4.3.5**：设**定理 4.3.3** 的条件成立，则采用 Armijo 型或 Wolfe-Powell 型线性搜索的 CBFGS 算法产生的点列 $\{x^{(k)}\}$ 超线性收敛于$x^*$。此外，当 $k$ 充分大时，$\alpha_k = 1$，而且，算法还原为标准的 BFGS 算法，即不等式 $y^{(k)\mathrm{T}} s^{(k)} > \delta \|\nabla f(x^{(k)})\|^\mu \|s^{(k)}\|^2$ 对充分大的 $k$ 均成立。
	- 该定理为 CBFGS 算法的超线性收敛性定理
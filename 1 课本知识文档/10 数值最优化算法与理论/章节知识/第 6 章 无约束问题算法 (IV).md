# 6 无约束问题算法 (IV)
本章我们介绍求解无约束问题
- **线性搜索型算法**：前面几章求解无约束问题几类算法的共同点是基于方向和步长确定迭代点列 $\{x(k)\}$，即在当前点 $x(k)$ 处，首先按照某种方式确定一个下降方向 $d^{(k)}$ (如最速下降方向，牛顿方向等)，然后从 $x(k)$ 出发，沿方向 $d(k)$ 进行线性搜索确定步长 $\alpha_k$，得到下一个迭代点 $x(k+1) = x(k) +\alpha_kd(k)$，我们称这类方法为**线性搜索型算法** 
- **信赖域算法**：本章我们介绍求解无约束问题 $\min f(x),\ (x\in\mathbb R^n)$ 的另一类算法——**信赖域算法** 
- *信赖域算法的基本思想*：在当前迭代点 $x^(k)$ 的附近用一个简单函数近似目标函数 $f$，用该近似函数在 $x(k)$ 的某个邻域内的极小值点作为下一个迭代点。
	- 与线性搜索型算法比较，信赖域算法在每次迭代同时确定搜索方向和步长。
## 6-1 信赖域算法的基本结构
- 由于信赖域方法用 $f$的某个近似函数在 $x(k)$ 邻域的极小值点作为下一个迭代点，因此，设计信赖域算法需要考虑如下相关问题：
	1. 目标函数 $f$ 的 (简单) 近似形式
	2. 点 $x(k)$ 的邻域 (称为**信赖域**) 大小的确定
	3. 函数值序列的下降性检测
	4. 近似问题 (称为**信赖域子问题**) 的求解
- *算法理论基础*、**信赖域**、**信赖域半径**、**信赖域子问题** 
	下面针对这四个问题分析，并建立信赖域算法的基本结构。
	考虑到一般非线性函数在任何点的邻域内都可以用二次函数近似，而且二次函数的极小值问题相对容易求解。
	因此，在信赖域算法中，通常我们采用二次函数作为目标函数 $f$ 的近似，用该二次函数在 $x^{(k)}$ 某邻域内的极小值点作为下一个迭代点，即 $x^{(k+1)}$ 为下面问题的解：  
	$$
	\begin{aligned}
	\min \quad & f(x^{(k)}) + \nabla f(x^{(k)})^\text{T}(x - x^{(k)}) + \frac{1}{2}(x - x^{(k)})^\text{T} B_k (x - x^{(k)}) \\
	\text{s.t.} \quad & \|x - x^{(k)}\| \leqslant \Delta_k
	\end{aligned}
	$$
	其中 $B_k \in \mathbb{R}^{n \times n}$ 是 $f$ 在 $x^{(k)}$ 处的 Hessian 矩阵或其近似，参数 $\Delta_k > 0$ 控制 $x^{(k)}$ 的邻域大小。
	若令 $d = x - x^{(k)}$，则上面的问题可改写为如下等价的二次函数极小值问题：
	$$
	\begin{aligned}
	\min \quad & f(x^{(k)}) + \nabla f(x^{(k)})^\text{T} d + \frac{1}{2} d^\text{T} B_k d \triangleq q_k(d) \\
	\text{s.t.} \quad & \|d\| \leqslant \Delta_k
	\end{aligned} \tag{question}
	$$
	设 $d^{(k)}$ 是问题 $(question)$ 的解，则下一个迭代点为 $x^{(k+1)} = x^{(k)} + d^{(k)}$ 
	问题 $(question)$ 中的可行域 $D = \{ d \in \mathbb{R}^n \mid \|d\| \leqslant \Delta_k \}$ 称为**信赖域**，参数 $\Delta_k > 0$ 称为**信赖域半径**，问题 $(question)$ 称为**信赖域子问题**，其中范数可任意选取。在本章中，如无特别说明，我们采用 Euclid 范数。  
	信赖域子问题 $(question)$ 是仅有一个不等式约束的二次函数极小化问题。我们将在 6-4 中介绍求解该子问题的常用算法。  
	由函数的二阶 Taylor 展开知，当 $\Delta_k$ 充分小时，二次函数 $q$ 在信赖域 $D$ 中是 $f$ 的一个很好的近似。
	另一方面，当 $f$ 本身是一个二次函数或近似于二次函数时，$q$ 可能在某一个较大的范围内也是 $f$ 的一个很好的近似。
	如何确定信赖域半径是信赖域算法的一个重要环节：一方面，我们希望在 $D$ 中 $q$ 与 $f$ 的近似程度好，另一方面，我们希望信赖域尽可能的大。
	为了合理地确定信赖域半径，我们定义 $\Delta f_k$ 为 $f$ 在第 $k$ 步的**实际下降量**，即 $\Delta f_k = f(x^{(k)}) - f(x^{(k)} + d^{(k)})$，其中 $d^{(k)}$ 是信赖域子问题 $(question)$ 的解。
	令 $\Delta q_k$ 为对应的**预测下降量**，即 $\Delta q_k = f(x^{(k)}) - q_k(d^{(k)})$ 
	定义比值 $r_k = \dfrac{\Delta f_k}{\Delta q_k}$ 
	注意到 $r_k$ 从某种角度反映了二次函数 $q_k(d^{(k)})$ 与目标函数 $f(x^{(k)} + d^{(k)})$ 的近似程度。
	若 $r_k$ 接近于 1，则可以认为二次函数 $q_k(d^{(k)})$ 在信赖域 $D$ 上与目标函数 $f(x^{(k)} + d^{(k)})$ 的近似程度很好。
	反之，若 $r_k$ 离 1 较远，我们认为 $q_k(d^{(k)})$ 在信赖域 $D$ 上与目标函数 $f(x^{(k)} + d^{(k)})$ 的近似程度不好。
	基于上述观察，我们可用 $r_k$ 与 1 的近似程度作为对信赖域半径是否合适的准则。即，可通过如下方式调整信赖域半径。
	给定常数 $\eta, \eta_1, \eta_2 \in (0,1)$ 满足 $\eta < \eta_1 < \eta_2$ (一般地，$\eta$ 接近于或等于 0，$\eta_2$ 接近于 1，如 $\eta_2 = 3/4$ 等)
	若 $r_k \geqslant \eta_2$，我们可认为 $q$ 在 $D$ 中是 $f$ 的一个很好的近似，或者说得到一个非常成功的迭代点 $x^{(k+1)} = x^{(k)} + d^{(k)}$。此时，$q$ 有可能在一个更大一点的区域内也是 $f$ 的一个很好的近似，因此，我们可将信赖域的半径扩大，即令 $\Delta_{k+1} > \Delta_k$。
	若 $\eta_1 < r_k < \eta_2$，即 $q$ 在 $D$ 中是 $f$ 的一个好的近似，或者说得到一个好的迭代点 $x^{(k+1)} = x^{(k)} + d^{(k)}$。此时可保持信赖域半径不变，即令 $\Delta_{k+1} = \Delta_k$ (为了在下一次迭代得到一个更成功的点，也可减少信赖域半径，即令 $\Delta_{k+1} < \Delta_k$) 
	若 $r_k \leqslant \eta$，即 $q$ 在 $D$ 中是 $f$ 的近似程度不好，或者说 $x^{(k)} + d^{(k)}$ 是一个不成功的迭代点，说明信赖域半径过大，此时需减少信赖域半径，即令 $\Delta_{k+1} < \Delta_k$ 
	在上面的基础上，我们给出求解 $\min f(x),\ (x\in\mathbb R^n)$ 的信赖域算法如下。
- **算法 6.1** (**信赖域算法**)
	- *第 0 步* (**初始化**)：取初始点 $x^{(0)} \in \mathbb{R}^n$，$\bar{\Delta} > 0$，$\Delta_0 \in (0, \bar{\Delta})$，$\eta \in \left[0, \dfrac{1}{4}\right)$，精度 $\varepsilon > 0$，令 $k := 0$ 
	- *第 1 步* (**收敛性检测**)：若 $\|\nabla f(x^{(k)})\| \leqslant \varepsilon$，则算法终止，得问题的解 $x^{(k)}$，否则转*第 2 步* 
	- *第 2 步* (**子问题求解**)：解信赖域子问题 $\begin{aligned} \min \quad & f(x^{(k)}) + \nabla f(x^{(k)})^\text{T} d + \frac{1}{2} d^\text{T} B_k d \triangleq q_k(d) \\ \text{s.t.} \quad & \|d\| \leqslant \Delta_k \end{aligned}$ 得 $d^{(k)}$ 
	- *第 3 步* (**信赖域修正**)：由 $\Delta f_k = f(x^{(k)}) - f(x^{(k)} + d^{(k)})$、$\Delta q_k = f(x^{(k)}) - q_k(d^{(k)})$ 和 $r_k = \dfrac{\Delta f_k}{\Delta q_k}$ 计算 $r_k$ 
		- 若 $r_k > \dfrac{3}{4}$，则令 $\Delta_{k+1} = \min\{2\Delta_k, \bar{\Delta}\}$ (模型很好，放大信赖域)
		- 若 $r_k < \dfrac{1}{4}$，则令 $\Delta_{k+1} = \frac{1}{2}\Delta_k$ (模型较差，缩小信赖域)
		- 若 $\dfrac{1}{4} \leqslant r_k \leqslant \dfrac{3}{4}$，则令 $\Delta_{k+1} = \Delta_k$ (尚可，保持)
	- *第 4 步* (**可接受检测**)：若 $r_k \leqslant \eta$，令 $x^{(k+1)} = x^{(k)}$，$k := k+1$，转*第 2 步*；否则令 $x^{(k+1)} = x^{(k)} + d^{(k)}$，$k := k+1$，转*第 1 步* 
- *算法 6.1 注释* 
	1. **算法 6.1** 的*第 3 步*中的常数 $\dfrac{1}{4}, \dfrac{3}{4}, 2$ 是根据经验选取的。实际计算时，可根据问题对它们进行调整。  
	2. 由于子问题 $\min f(x),\ (x\in\mathbb R^n)$ 的可行域有界，因此**算法 6.1**的*第 2 步*中的 $d^{(k)}$ 存在。
- **定理 6.1.1**：设 $d^{(k)}$ 是问题 $\begin{aligned} \min \quad & f(x^{(k)}) + \nabla f(x^{(k)})^\text{T} d + \frac{1}{2} d^\text{T} B_k d \triangleq q_k(d) \\ \text{s.t.} \quad & \|d\| \leqslant \Delta_d \end{aligned} \quad (temp)$ 的解，若 $\nabla f(x^{(k)}) \neq 0$，则 $\Delta q_k(d^{(k)}) = f(x^{(k)}) - q_k(d^{(k)}) > 0$ 
	- *证明过程* 
		注意到 $d = 0$ 是子问题 $(temp)$ 的可行点，因此 $q_k(d^{(k)}) \leqslant q_k(0) = f(x^{(k)})$，即 $\Delta q_k(d^{(k)}) \geqslant 0$ 
		若 $\Delta q_k(d^{(k)}) = 0$，即 $q_k(d^{(k)}) = f(x^{(k)}) = q_k(0)$，故 $0$ 是子问题 $(temp)$ 的最优解。
		但 $0$ 是可行域的内点，因此 $\nabla q_k(0) = 0$，即 $\nabla f(x^{(k)}) = 0$ 
		这与 $\nabla f(x^{(k)}) \neq 0$ 矛盾，故 $\Delta q_k(d^{(k)}) > 0$，证毕！
	- 该定理说明：若 $x^{(k)}$ 不是问题 $\min f(x),\ (x\in\mathbb R^n)$ 的稳定点，则预估下降量 $\Delta q_k(d^{(k)}) > 0$。因此，算法是适定的。
- **推论 6.1.1**：设 $\{x^{(k)}\}$ 由**算法 6.1**产生，则序列 $\{f(x^{(k)})\}$ 单调非增
	- *证明过程* 
		事实上，对任意 $k$，若 $r_k \leqslant \eta$，则 $x^{(k+1)} = x^{(k)}$，此时有 $f(x^{(k+1)}) = f(x^{(k)})$ 
		若 $r_k > \eta$，由**定理 6.1.1** 以及 $r_k$ 的定义有 $f(x^{(k)}) - f(x^{(k+1)}) = f(x^{(k)}) - f(x^{(k)} + d^{(k)}) \geqslant \eta \Delta q_k(d^{(k)}) > 0$，因此 $f(x^{(k+1)}) < f(x^{(k)})$ 
		综上，序列 $\{f(x^{(k)})\}$ 单调非增，证毕！
## 6-2 信赖域算法的收敛性
- **柯西 (Cauchy) 点**：为了分析信赖域算法的收敛性，我们引入在迭代点 $x^{(k)}$ 处的**柯西 (Cauchy) 点** $p_k^c$：$p_k^c = -\tau_k \dfrac{\Delta_k}{\|\nabla f(x^{(k)})\|} \nabla f(x^{(k)})$，其中 $\tau_k = \begin{cases} 1, & \text{如果 } \nabla f(x^{(k)})^\mathrm{T} B_k \nabla f(x^{(k)}) \leqslant 0 \\ \min\left\{ \dfrac{\|\nabla f(x^{(k)})\|^3}{\Delta_k \nabla f(x^{(k)})^\mathrm{T} B_k \nabla f(x^{(k)})}, 1 \right\}, & \text{其他} \end{cases}$ 
	- 不难验证 $\|p_k^\mathrm{c}\| = \tau_k \Delta_k \leqslant \Delta_k$。因此，柯西点 $p_k^\mathrm{c}$ 在信赖域子问题的约束区域内，它平行于 $f$ 在 $x^{(k)}$ 处的最速下降方向。
- **引理 6.2.1**：柯西点 $p_k^\mathrm{c}$ 满足 $f(x^{(k)}) - q_k(p_k^\mathrm{c}) \geqslant \dfrac{1}{2}\|\nabla f(x^{(k)})\| \min \left\{ \Delta_k, \dfrac{\|\nabla f(x^{(k)})\|}{\|B_k\|} \right\}$ 
	- *证明过程* 
		首先考虑 $\nabla f(x^{(k)})^\mathrm{T} B_k \nabla f(x^{(k)}) \leqslant 0$ 的情况。
		此时有 $\tau_k = 1$ 且  
		$$
		\begin{aligned}
		f(x^{(k)}) - q_k(p_k^\mathrm{c}) =& \dfrac{\Delta_k}{\|\nabla f(x^{(k)})\|} \|\nabla f(x^{(k)})\|^2 - \dfrac{\Delta_k^2}{2\|\nabla f(x^{(k)})\|^2} \nabla f(x^{(k)})^\mathrm{T} B_k \nabla f(x^{(k)}) \\
		\geqslant& \Delta_k \|\nabla f(x^{(k)})\| \geqslant \|\nabla f(x^{(k)})\| \min \left\{ \Delta_k, \dfrac{\|\nabla f(x^{(k)})\|}{\|B_k\|} \right\}
		\end{aligned}
		$$
		故 $f(x^{(k)}) - q_k(p_k^\mathrm{c}) \geqslant \dfrac{1}{2}\|\nabla f(x^{(k)})\| \min \left\{ \Delta_k, \dfrac{\|\nabla f(x^{(k)})\|}{\|B_k\|} \right\}$ 成立
		再考虑 $\nabla f(x^{(k)})^\mathrm{T} B_k \nabla f(x^{(k)}) > 0$ 的情况。
		若 $\dfrac{\|\nabla f(x^{(k)})\|^3}{\Delta_k \nabla f(x^{(k)})^\mathrm{T} B_k \nabla f(x^{(k)})} \leqslant 1$，则 $\tau_k = \|\nabla f(x^{(k)})\|^3 / [\Delta_k \nabla f(x^{(k)})^\mathrm{T} B_k \nabla f(x^{(k)})]$，且
		$$
		\begin{aligned}
		f(x^{(k)}) - q_k(p_k^c) =& \dfrac{1}{2} \dfrac{\|\nabla f(x^{(k)})\|^4}{\nabla f(x^{(k)})^\mathrm{T} B_k \nabla f(x^{(k)})} \geqslant \dfrac{1}{2} \dfrac{\|\nabla f(x^{(k)})\|^2}{\|B_k\|} \\
		\geqslant & \dfrac{1}{2} \|\nabla f(x^{(k)})\| \min \left\{ \Delta_k, \dfrac{\|\nabla f(x^{(k)})\|}{\|B_k\|} \right\}
		\end{aligned}
		$$
		即式 $f(x^{(k)}) - q_k(p_k^\mathrm{c}) \geqslant \dfrac{1}{2}\|\nabla f(x^{(k)})\| \min \left\{ \Delta_k, \dfrac{\|\nabla f(x^{(k)})\|}{\|B_k\|} \right\}$ 成立。
		若式 $\dfrac{\|\nabla f(x^{(k)})\|^3}{\Delta_k \nabla f(x^{(k)})^\mathrm{T} B_k \nabla f(x^{(k)})} \leqslant 1$ 不成立，则 $\tau_k = 1$ 且 $\nabla f(x^{(k)})^\mathrm{T} B_k \nabla f(x^{(k)}) < \dfrac{\|\nabla f(x^{(k)})\|^3}{\Delta_k}$ 
		因此
		$$
		\begin{aligned}
		f(x^{(k)}) - q_k(p_k^c) =& \dfrac{\Delta_k}{\|\nabla f(x^{(k)})\|} \|\nabla f(x^{(k)})\|^2 - \dfrac{1}{2} \dfrac{\Delta_k^2}{\|\nabla f(x^{(k)})\|^2} \nabla f(x^{(k)})^\mathrm{T} B_k \nabla f(x^{(k)}) \\
		\geqslant& \Delta_k \|\nabla f(x^{(k)})\| - \dfrac{1}{2} \dfrac{\Delta_k^2}{\|\nabla f(x^{(k)})\|^2} \dfrac{\|\nabla f(x^{(k)})\|^3}{\Delta_k} \\ 
		\geqslant& \dfrac{1}{2} \|\nabla f(x^{(k)})\| \min \left\{ \Delta_k, \dfrac{\|\nabla f(x^{(k)})\|}{\|B_k\|} \right\}
		\end{aligned}
		$$
		即 $f(x^{(k)}) - q_k(p_k^\mathrm{c}) \geqslant \dfrac{1}{2}\|\nabla f(x^{(k)})\| \min \left\{ \Delta_k, \dfrac{\|\nabla f(x^{(k)})\|}{\|B_k\|} \right\}$ 也成立
		综上证毕！
	- 该引理给出了柯西点的一个重要性质
- **推论 6.2.1**：设 $d^{(k)}$ 是信赖域子问题 $\begin{aligned} \min \quad & f(x^{(k)}) + \nabla f(x^{(k)})^\text{T} d + \frac{1}{2} d^\text{T} B_k d \triangleq q_k(d) \\ \text{s.t.} \quad & \|d\| \leqslant \Delta_d \end{aligned}$ 的解，则 $f(x^{(k)}) - q_k(d^{(k)}) \geqslant \dfrac{1}{2} \|\nabla f(x^{(k)})\| \min\left\{ \Delta_k, \dfrac{\|\nabla f(x^{(k)})\|}{\|B_k\|} \right\}$ 
	- *证明过程* 
		注意到柯西点是子问题的可行点，若 $d^{(k)}$ 是子问题的解，则有 $q_k(p_k^c) \geqslant q_k(d^{(k)})$ 
		因此，由上面的引理可直接得该推论
- **定理 6.2.1**：设函数 $f$ 连续可微有下界，且存在常数 $\beta > 0$，使得不等式 $\|B_k\| \leqslant \beta$ 对所有 $k \geqslant 0$ 均成立。若在**算法 6.1** 中取 $\eta = 0$，则 $\lim\limits_{k \to \infty} \inf \|\nabla f(x^{(k)})\| = 0$ 
	- *证明过程* 
		由 $r_k$ 的定义有 $|r_k - 1| = \left| \dfrac{q_k(d^{(k)}) - f(x^{(k)} + d^{(k)})}{f(x^{(k)}) - q_k(d^{(k)})} \right|$ 
		又由中值定理可得
		$$
		\begin{aligned}
		&|q_k(d^{(k)}) - f(x^{(k)} + d^{(k)})| \\
		=& \left| \frac{1}{2} {d^{(k)}}^\mathrm{T} B_k d^{(k)} - \int_0^1 [\nabla f(x^{(k)} + t d^{(k)}) - \nabla f(x^{(k)})]^\mathrm{T} d^{(k)} \, \mathrm{d}t \right| \\
		\leqslant& \frac{\beta}{2} \|d^{(k)}\|^2 + \|d^{(k)}\| \int_0^1 \|\nabla f(x^{(k)} + t d^{(k)}) - \nabla f(x^{(k)})\| \, \mathrm{d}t \\
		\triangleq& \frac{\beta}{2} \|d^{(k)}\|^2 + C(d^{(k)}) \|d^{(k)}\|
		\end{aligned}
		$$
		此处 $C(d^{(k)})$ 满足 $\lim\limits_{d \to 0} \dfrac{C(d)}{\|d\|} = 0$ 
		反设 $\lim\limits_{k \to \infty} \inf \|\nabla f(x^{(k)})\| = 0$ 不成立，则存在 $\varepsilon > 0$，使得对所有 $k \geqslant 0$ 有 $\|\nabla f(x^{(k)})\| \geqslant \varepsilon$ 
		由式 $f(x^{(k)}) - q_k(d^{(k)}) \geqslant \dfrac{1}{2} \|\nabla f(x^{(k)})\| \min\left\{ \Delta_k, \dfrac{\|\nabla f(x^{(k)})\|}{\|B_k\|} \right\}$ 和 $B_k$ 的有界性，对所有 $k \geqslant 0$ 有 $f(x^{(k)}) - q_k(d^{(k)}) \geqslant \dfrac{1}{2} \|\nabla f(x^{(k)})\| \min\left\{ \Delta_k, \dfrac{\|\nabla f(x^{(k)})\|}{\|B_k\|} \right\} \geqslant \dfrac{1}{2} \varepsilon \min\left\{ \Delta_k, \dfrac{\varepsilon}{\beta} \right\}$ 
		上式结合 $|q_k(d^{(k)}) - f(x^{(k)} + d^{(k)})| \le \dfrac{\beta}{2} \|d^{(k)}\|^2 + C(d^{(k)}) \|d^{(k)}\|$ 及 $d^{(k)}$ 的信赖域限制可得 $|r_k - 1| \leqslant \dfrac{\Delta_k [\beta \Delta_k + 2C(d^{(k)})]}{\varepsilon \min(\Delta_k, \varepsilon/\beta)}$ 
		由 $C(d^{(k)})$ 的性质知，存在 $\tilde{\Delta} \in (0, \tilde{\Delta})$，当 $\Delta_k \leqslant \min\{\tilde{\Delta}, \varepsilon \beta^{-1}\}$ 时有 $\beta \Delta_k + 2C(d^{(k)}) \leqslant \dfrac{\varepsilon}{4}$ 
		由此及式 $|r_k - 1| \leqslant \dfrac{\Delta_k [\beta \Delta_k + 2C(d^{(k)})]}{\varepsilon \min(\Delta_k, \varepsilon/\beta)}$ 推得 $|r_k - 1| \leqslant \dfrac{\varepsilon \Delta_k / 4}{\varepsilon \Delta_k} = \dfrac{1}{4}$，因此 $r_k > 3/4$ 
		由**算法 6.1** 知信赖半径 $\Delta_k$ 减少只可能发生在 $\Delta_k \geqslant \min\{\tilde{\Delta}, \varepsilon \beta^{-1}\}$ 
		因此，$\Delta_k \geqslant \dfrac{1}{4} \min\{\tilde{\Delta}, \varepsilon \beta^{-1}\} \ (\forall\ k \geqslant 0)$ 
		若有一个无限指标集 $K$ 使得 $r_k \geqslant \dfrac{1}{4},\ k \in K$，则由式 $f(x^{(k)}) - q_k(d^{(k)}) \geqslant \dfrac{1}{2} \|\nabla f(x^{(k)})\| \min\left\{ \Delta_k, \dfrac{\|\nabla f(x^{(k)})\|}{\|B_k\|} \right\} \geqslant \dfrac{1}{2} \varepsilon \min\left\{ \Delta_k, \dfrac{\varepsilon}{\beta} \right\}$ 和**算法 6.1** 中*步 3*，对 $k \in K,\ k \geqslant k_0$，我们导出 $f(x^{(k)}) - f(x^{(k+1)}) = f(x^{(k)}) - f(x^{(k)} + d^{(k)}) \geqslant \dfrac{1}{4} [f(x^{(k)}) - q_k(d^{(k)})] \geqslant \dfrac{1}{8} \varepsilon \min(\Delta_k, \varepsilon/\beta)$ 
		因 $\{f(x^{(k)})\}$ 单调非增有下界，上式隐含着 $\lim\limits_{k \in K, k \to \infty} \Delta_k = 0$，与式 $\Delta_k \geqslant \dfrac{1}{4} \min\{\tilde{\Delta}, \varepsilon \beta^{-1}\} \ (\forall\ k \geqslant 0)$ 矛盾。
		因此，对所有充分大的 $k$，必有 $r_k < 1/4$ 
		另一方面，由**算法 6.1** 中*第 3 步*，当 $r_k < 1/4$ 时，$\Delta_k$ 按 $1/2$ 比率缩小，故有 $\lim\limits_{k \to \infty} \Delta_k = 0$，与式 $\Delta_k \geqslant \dfrac{1}{4} \min\{\tilde{\Delta}, \varepsilon \beta^{-1}\} \ (\forall\ k \geqslant 0)$ 矛盾
		因此假设条件 $\|\nabla f(x^{(k)})\| \geqslant \varepsilon$ 不成立，即 $\lim\limits_{k \to \infty} \inf \|\nabla f(x^{(k)})\| = 0$ 成立。
		证毕！
	- 该定理为：$\eta = 0$ 时算法 6.1 的收敛性定理。
- **定理 6.2.2**：设**定理 6.2.1** 的条件满足且 $\nabla f$ Lipschitz 连续。若在**算法 6.1** 中取 $\eta > 0$，则 $\lim\limits_{k \to \infty} \|\nabla f(x^{(k)})\| = 0$ 
	- 该定理为：$\eta > 0$ 时算法 6.1 的收敛性定理。
- **定理 6.2.3** 
	(1) 设 $f \in C^2$ 有下界，且由 Newton 型信赖域算法产生的点列 $\{x^{(k)}\}$ 有界，则存在 $\{x^{(k)}\}$ 的聚点 $x^*$ 满足优化问题 $\min f(x),\ (x\in\mathbb R^n)$ 的一阶必要条件和二阶必要条件。
	(2) 若再假设在 $x^*$ 处 $f$ 的 Hessian 矩阵正定，则 $\lim\limits_{k \to \infty} r_k = 1,\ \lim\limits_{k \to \infty} x^{(k)} = x^*,\ \inf \Delta_k > 0$。而且，当 $k$ 充分大时，$\|d^{(k)}\| < \Delta_k$。此外，$\{x^{(k)}\}$ 的超线性收敛到 $x^*$ 
	(3) 若进一步假设 $\nabla^2 f$ 在 $x^*$ 处 Lipschitz 连续，则 $\{x^{(k)}\}$ 的收敛速度是二阶的。
	- 该定理给出了 Newton 型信赖域算法 (即在**算法 6.1** 中取 $B_k = \nabla^2 f(x^{(k)})$) 的收敛速度估计。
## 6-3 信赖域—线性搜索型算法
- *信赖域算法的优点*：信赖域算法的一个重要特点是其鲁棒性。而且，信赖域子问题一定有解。
- *信赖域算法的缺点*：在每次迭代时信赖域算法可能需要求解多次子问题才能获得成功迭代点。由于信赖域子问题是一个约束问题，求解相对复杂。另一方面，线性搜索型算法无需多次求解子问题即可产生一个使得目标函数下降的点。
- **信赖域—线性搜索型算法**：为了保持信赖域算法的优点，同时减少计算量，可采用信赖域和线性搜索型算法相结合的方式，即**信赖域—线性搜索型算法**求解 $\min f(x),\ (x\in\mathbb R^n)$ 
- **信赖域—线性搜索型算法**的*基本思想*
	在当前迭代点 $x^{(k)}$ 处，求解信赖域子问题 $\begin{aligned} \min \quad & f(x^{(k)}) + \nabla f(x^{(k)})^\text{T} d + \frac{1}{2} d^\text{T} B_k d \triangleq q_k(d) \\ \text{s.t.} \quad & \|d\| \leqslant \Delta_k \end{aligned}$ 得方向 $d^{(k)}$ 
	然后利用线性搜索确定步长 $\alpha_k$，并令 $x^{(k+1)} = x^{(k)} + \alpha_k d^{(k)}$ 
	下**引理 6.3.1** 说明信赖域子问题 $\begin{aligned} \min \quad & f(x^{(k)}) + \nabla f(x^{(k)})^\text{T} d + \frac{1}{2} d^\text{T} B_k d \triangleq q_k(d) \\ \text{s.t.} \quad & \|d\| \leqslant \Delta_k \end{aligned}$ 的解是 $f$ 在 $x^{(k)}$ 处的一个下降方向
- **引理 6.3.1**：设 $f$ 连续可微，则信赖域子问题 $\begin{aligned} \min \quad & f(x^{(k)}) + \nabla f(x^{(k)})^\text{T} d + \frac{1}{2} d^\text{T} B_k d \triangleq q_k(d) \\ \text{s.t.} \quad & \|d\| \leqslant \Delta_k \end{aligned}$ 的解 $d^{(k)}$ 满足 $\nabla f(x^{(k)})^\mathrm{T} d^{(k)} \leqslant -\dfrac{1}{2} \|\nabla f(x^{(k)})\| \min\left\{ \Delta_k, \dfrac{\|\nabla f(x^{(k)})\|}{2\|B_k\|} \right\}$ 
- **算法 6.2** (**信赖域—线性搜索组合算法**)
	- *第 0 步* (**初始化**)：取初始点 $x^{(0)} \in \mathbb{R}^n$，$\Delta_0 > 0$，$\eta \in (0,1)$，选取常数 $0 < c_2 < c_3 < 1 < c_1$，$\rho \in (0,1)$；令 $k := 0$ 
	- *第 1 步* (**收敛性检测**)：若 $\|\nabla f(x^{(k)})\| \leqslant \varepsilon$，则算法终止，得问题的解 $x^{(k)}$ 
	- *第 2 步* (**子问题求解**)：解信赖域子问题 $\begin{aligned} \min \quad & f(x^{(k)}) + \nabla f(x^{(k)})^\text{T} d + \frac{1}{2} d^\text{T} B_k d \triangleq q_k(d) \\ \text{s.t.} \quad & \|d\| \leqslant \Delta_k \end{aligned}$ 得解 $d^{(k)}$ 
	- *第 3 步* (**下降测试和线性搜索**)：若 $f(x^{(k)} + d^{(k)}) < f(x^{(k)})$，令 $x^{(k+1)} = x^{(k)} + d^{(k)}$，转*第 4 步*。否则，令 $\alpha_k$ 是 $\{\rho^i \mid i = 0,1,\cdots\}$ 中使得 $f(x^{(k)} + \rho^i d^{(k)}) < f(x^{(k)})$ 成立的最大者。令 $x^{(k+1)} = x^{(k)} + \alpha_k d^{(k)}$，取 $\Delta_{k+1} \in \{\|x^{(k+1)} - x^{(k)}\|, c_3 \Delta_k\}$，转*第 5 步* 
	- *第 4 步* (**信赖域修正**)：计算 $r_k = \dfrac{f(x^{(k)}) - f(x^{(k+1)})}{f(x^{(k)}) - q_k(d^{(k)})}$，若 $r_k > \eta$ 且 $\|d^{(k)}\| < \Delta_k$，令 $\Delta_{k+1} = \Delta_k$。否则定义 $\Delta_{k+1} = \begin{cases} [c_2 \|d^{(k)}\|,  c_3 \Delta_k], & \text{若 } r_k < \eta \\ [\Delta_k, c_1 \Delta_k], & \text{若 } r_k > \eta \text{ 且 } \|d^{(k)}\| = \Delta_k \end{cases}$ 
	- *第 5 步* (**循环**)：确定 $B_{k+1}$，令 $k := k + 1$，转*第 1 步* 
- *算法 6.2 注释*：*第 2 步*的子问题可采用非精确求解，其近似解 $d^{(k)}$ 满足：存在正常数 $\tau > 0$，使得 $q_k(0) - q_k(d^{(k)}) \geqslant \tau \|\nabla f(x^{(k)})\| \min\left\{ \Delta_k, \dfrac{\|\nabla f(x^{(k)})\|}{\|B_k\|} \right\}$ 和 $\nabla f(x^{(k)})^\mathrm{T} d^{(k)} \leqslant -\tau \|\nabla f(x^{(k)})\| \min\left\{ \Delta_k, \dfrac{\|\nabla f(x^{(k)})\|}{\|B_k\|} \right\}$ 
- **定理 6.3.1**：设函数 $f$ 二次连续可微且 $\|\nabla^2 f(x)\|$ 有界。若**算法 6.2** 产生的点列有界，且 $B_k$ 满足 $\sum\limits_{k=1}^{\infty} \dfrac{1}{1 + \max\limits_{1 \leqslant i \leqslant k} \|B_i\|} = \infty$，则有 $\lim\limits_{k \to \infty} \inf \|\nabla f(x^{(k)})\| = 0$ 
	- 该定理给出**算法 6.2** 的全局收敛性
## 6-4 信赖域子问题的求解
### 6-4-0 前言
- 信赖域算法中子问题的求解是算法实现的关键。
- 子问题 $\begin{aligned} \min \quad & f(x^{(k)}) + \nabla f(x^{(k)})^\text{T} d + \frac{1}{2} d^\text{T} B_k d \triangleq q_k(d) \\ \text{s.t.} \quad & \|d\| \leqslant \Delta_d \end{aligned}$  是一个目标为二次函数的约束优化问题。当采用 $\|\cdot\|_\infty$ 范数时，可利用第 11 章介绍的有效集算法求解。
- 下面介绍采用 Euclid 范数时，精确求解与非精确求解子问题 $\begin{aligned} \min \quad & f(x^{(k)}) + \nabla f(x^{(k)})^\text{T} d + \frac{1}{2} d^\text{T} B_k d \triangleq q_k(d) \\ \text{s.t.} \quad & \|d\| \leqslant \Delta_d \end{aligned}$ 的特殊算法。
- 为方便起见，省略迭代指标，用 $x \in \mathbb{R}^n$ 表示当前迭代点，此时信赖域子问题为
	$$
	\begin{aligned}
	\min \quad & f(x) + \nabla f(x)^\mathrm{T} d + \frac{1}{2} d^\mathrm{T} B d \triangleq q(d) \\
	\text{s.t.} \quad & \|d\| \leqslant \Delta
	\end{aligned} \tag{question}
	$$
### 6-4-1 精确求解方法
- 不难发现，若 $B$ 正定且 $\bar{d} \triangleq -B^{-1} \nabla f(x)$ 满足 $\|\bar{d}\| \leqslant \Delta$，即无约束问题 $\min f(x) + \nabla f(x)^\mathrm{T} d + \dfrac{1}{2} d^\mathrm{T} B d$ 的解是问题 $(question)$ 的可行点，则 $\bar{d}$ 是问题 $(question)$ 的解
- **定理 6.4.1**：$d^*$ 是子问题 $(question)$ 的全局最优解当且仅当 $d^*$ 可行，存在常数 $\lambda^* \geqslant 0$ 满足 $B + \lambda^* I$ 半正定，且有 $\begin{cases} (B + \lambda^* I) d^* = -\nabla f(x) \\ \lambda^* (\Delta - \|d^*\|) = 0 \end{cases}$ 
	- 该定理给出了：一般情况下子问题 $(question)$ 的解的相关结论，其证明留作练习。
	- 该定理给出了信赖域子问题 $(question)$ 解的一个等价性条件。
- **子问题的精确解法**的*理论基础* 
	利用**定理 6.4.1**，我们可构造求解子问题算法。
	设矩阵 $B + \lambda^* I$ 正定，若线性方程组 $B d + \nabla f(x) = 0$ 的解 $\bar{d}$ 满足 $\|\bar{d}\| \leqslant \Delta$，则 $d^* = \bar{d}$。此情形对应于 $\lambda^* = 0$ 且 $B$ 正定。否则，必有 $\lambda^* > 0$。
	此时求解信赖域子问题 $(question)$ 等价于解如下方程组
	$$
	\begin{cases}
	(B + \lambda I) d = -\nabla f(x) \\
	\|d\| = \Delta
	\end{cases}
	$$
	取 $\lambda > 0$ 充分大使得 $B + \lambda I$ 正定，由式 $\begin{cases} (B + \lambda I) d = -\nabla f(x) \\ \|d\| = \Delta \end{cases}$ 可知：
	求 $(question)$ 的解可通过解如下关于 $\lambda$ 的一元非线性方程 $\phi_1(\lambda) = \|(B + \lambda I)^{-1} \nabla f(x)\| - \Delta = 0$ 得到解 $\lambda^*$，然后由 $(B + \lambda I) d = -\nabla f(x)$ 得子问题的解 $d^* = d(\lambda^*) = -(B + \lambda^* I)^{-1} \nabla f(x)$ 
	基于非线性方程 $\phi_1(\lambda) = \|(B + \lambda I)^{-1} \nabla f(x)\| - \Delta = 0$ 求信赖域子问题的方法称为**子问题的精确解法** 
	利用矩阵的对角化分解可知，$\phi_1(\lambda)$ 是一非线性程度高的系统。为了简化方程的计算，定义 $\phi_2(\lambda) = \dfrac{1}{\Delta} - \dfrac{1}{\|d(\lambda)\|}$ 
	$\phi_2(\lambda)$ 近似为线性方程系统，且方程组 $\phi_1(\lambda) = \|(B + \lambda I)^{-1} \nabla f(x)\| - \Delta = 0$ 等价于方程 $\phi_2(\lambda) = 0$ 
	该方程系统可应用牛顿迭代法建立其迭代计算式为 $\lambda_{l+1} = \lambda_l - \dfrac{\phi_2(\lambda_l)}{\phi_2'(\lambda_l)} = \lambda_l + \left( \dfrac{\|d_l\|}{\|q_l\|} \right)^2 \left( \dfrac{\|d_l\| - \Delta}{\Delta} \right)$ 
	根据如上分析可建立信赖域子问题精确求解的计算步骤如下
- **算法 6.3** (**信赖域子问题的精确算法**)
	- *第 0 步*：给定 $\lambda_0 > 0$，$\Delta > 0$。令 $l := 0$ 
	- *第 1 步*：若 $\lambda_l$ 是问题 $\phi_2(\lambda) = \dfrac{1}{\Delta} - \dfrac{1}{\|d(\lambda)\|}$ 的解，则解线性问题 $\begin{cases} (B + \lambda I) d = -\nabla f(x) \\ \|d\| = \Delta \end{cases}$ 得解 $d^{(l)}$。否则，转*第 2 步* 
	- *第 2 步*：作 Cholesky 分解 $B + \lambda^{(l)} I = R^\mathrm{T} R$。解方程组 $R^\mathrm{T} R d_l = -\nabla f(x),\ R^\mathrm{T} q_l = d_l$，得解 $d_l, q_l$ 
	- *第 3 步*：$\lambda_{l+1} = \lambda_l + \left( \dfrac{\|d_l\|}{\|q_l\|} \right)^2 \left( \dfrac{\|d_l\| - \Delta}{\Delta} \right)$ 
	- *第 4 步*：令 $l := l + 1$，转*第 1 步* 
- *算法 6.3 注*：上面的算法只适合于矩阵 $B + \lambda^* I$ 正定时的情况。当 $B + \lambda^* I$ 非正定时，子问题 $(question)$ 的求解较为复杂。
### 6-4-2 折线方法 (Dogleg Method)
- *前置分析* 
	上小节介绍的信赖域子问题精确求解计算量较大，而且当 $B + \lambda^* I$ 非正定时，子问题 $(question)$ 的求解较为复杂。
	另一方面，从**定理 6.2.1** 的证明可见，**算法 6.1** 全局收敛的关键是柯西下降性条件 $f(x^{(k)}) - q_k(p_k^\mathrm{c}) \geqslant \dfrac{1}{2}\|\nabla f(x^{(k)})\| \min \left\{ \Delta_k, \dfrac{\|\nabla f(x^{(k)})\|}{\|B_k\|} \right\}$ 
	此条件为保证算法的全局收敛性提供了非精确解的一个标准。
	因此，我们可以考虑非精确求解子问题 $\begin{aligned} \min \quad & f(x^{(k)}) + \nabla f(x^{(k)})^\text{T} d + \frac{1}{2} d^\text{T} B_k d \triangleq q_k(d) \\ \text{s.t.} \quad & \|d\| \leqslant \Delta_d \end{aligned}$，获得其近似解 $d^{(k)}$ 满足部分柯西下降量
	即求 $d^{(k)} \in D$ 使得对某个 $c \in (0,1]$，$f(x^{(k)}) - f(x^{(k)} + d^{(k)}) \geqslant c \left[ f(x^{(k)}) - f(x^{(k)} + p_k^C) \right]$，其中 $p_k^C$ 为由式 $p_k^c = -\tau_k \dfrac{\Delta_k}{\|\nabla f(x^{(k)})\|} \nabla f(x^{(k)})$ 定义的柯西点
- **折线方法** 
	下面我们介绍非精确求解信赖域子问题的**折线方法** 
	由信赖域子问题 $(question)$ 知其解 $d^*$ 是信赖域半径 $\Delta$ 的函数，记为 $d^*(\Delta)$，几何上为一条曲线，称其为**最优解曲线**，见下图
	![[Pasted image 20260409221113.png|350]]
	折线法的思想是用一条折线代替精确解曲线 $d^*(\Delta)$ 
	为了构造合适的折线，首先分析子问题解的特性
	若 $B$ 正定且 $\| -B^{-1} \nabla f(x) \| \leqslant \Delta$，则 $(question)$ 的精确解为 $d^*(\Delta) = -B^{-1} \nabla f(x) \triangleq d^B$ 
	否则，我们可作如下分析：
	当 $\Delta$ 很小时，信赖域子问题中目标函数的二次项的作用不大。
	因此，可用函数 $f(x)$ 的一次（线性）近似，此时在约束 $\|d\| \leqslant \Delta$ 下，子问题的近似解为 $d^*(\Delta) \approx -\Delta \dfrac{\nabla f(x)}{\|\nabla f(x)\|}$。
	这显示可采用最速下降方向作为解曲线的近似。
	基于最速下降方向的考虑和省略信赖域约束，我们取子问题解的形式为 $d = -\tau \nabla f(x)$。
	通过目标函数极小化可确定子问题沿最速下降方向的解为 $d^U = -\dfrac{\nabla f(x)^\mathrm{T} \nabla f(x)}{\nabla f(x)^\mathrm{T} B \nabla f(x)} \nabla f(x)$ 
	另一方面，为了得到收敛性能更好的搜索方向，我们可选择牛顿方向 $d^B$ 
	由两方向 $d^U$ 和 $d^B$ 可分段构造折线搜索方向 (见上图)
	记由上图方式构造出的折线为 $\tilde{d}(\tau)$，数学上的定义式为
	$$
	\tilde{d}(\tau) = \begin{cases} 
	\tau d^U, & 0 \leqslant \tau \leqslant 1 \\
	d^U + (\tau - 1)(d^B - d^U), & 1 \leqslant \tau \leqslant 2 
	\end{cases}
	$$
	上式说明当 $\tau$ 较小时方向选用最速下降方向 $d^U$，否则取 $d^U$ 和 $d^B$ 的组合方向。
	沿如上构造的折线方向 $\tilde{d}(\tau)$，在信赖域约束下求子问题 $(question)$ 的解。
	理论上可证明 $\tilde{d}(\tau) = \begin{cases} \tau d^U, & 0 \leqslant \tau \leqslant 1 \\d^U + (\tau - 1)(d^B - d^U), & 1 \leqslant \tau \leqslant 2 \end{cases}$ 构造的折线具有如下性质。
- **引理 6.4.1**：设 $B$ 对称正定，则  
	(1) $\|\tilde{d}(\tau)\|$ 关于 $\tau$ 为单调增函数。  
	(2) $q[\tilde{d}(\tau)]$ 关于 $\tau$ 为单调减函数。  
	- 该引理说明，当沿 $\tilde{d}(\tau)$ 求子问题的极小点时，解在信赖域边界上达到，即 $\tau$ 满足 $\|d^U + (\tau - 1)(d^B - d^U)\|^2 = \Delta^2$，上式为关于 $\tau$ 的二次代数方程，求解此方程可得到折线法的解。
	- 性质 (2) 说明按折线方向所求出的近似解满足下降性条件 $f(x^{(k)}) - f(x^{(k)} + d^{(k)}) \geqslant c \left[ f(x^{(k)}) - f(x^{(k)} + p_k^C) \right]$，从而可保证信赖域算法的全局收敛性。
### 6-4-3 截断共轭梯度法
- 前面介绍的精确方法和折线近似方法能保证信赖域算法的全局收敛性，然而实际计算过程中涉及以 $B$ 或 $B + \lambda I$ 为系数阵的线性方程组的求解。当 $B \in \mathbb{R}^{n \times n}$ 的维数较高时，这些方法可导致计算上的高消费。
- **截断共轭梯度法**：本小节介绍非精确求解子问题的另一种方法——**截断共轭梯度法** 
	- 它可用于求解大规模信赖域子问题。
	- 该算法是解线性方程组共轭梯度法的一种变形，其计算步骤如下：
- **算法 6.4** (**截断共轭梯度法**)
	- *第 0 步*：给定 $\varepsilon > 0$。设 $d_0 = 0$，$r_0 = \nabla f(x)$，$p_0 = -r_0$。令 $j := 0$ 
	- *第 1 步*：若 $\|r_j\| \leqslant \varepsilon$，取 $d = d_j$ 为问题 (6.24) 的解，算法终止。否则，转*第 2 步* 
	- *第 2 步*：若 $p_j^\mathrm{T} B p_j \leqslant 0$，确定 $\tau \geqslant 0$ 使得 $d = d_j + \tau p_j$ 满足 $\|d\| = \Delta$，$d$ 作为子问题的近似解，停止计算。否则，计算 $\alpha_j = \dfrac{r_j^\mathrm{T} r_j}{p_j^\mathrm{T} B p_j},\ d_{j+1} = d_j + \alpha_j p_j$ 
	- *第 3 步*：若 $\|d_{j+1}\| \geqslant \Delta$，确定 $\tau \geqslant 0$ 使得 $d = d_j + \tau p_j$ 满足 $\|d\| = \Delta$，取 $d$ 为子问题的近似解，停止计算。否则设 $r_{j+1} = r_j + \alpha_j B p_j$ 
	- *第 4 步*：若 $\|r_{j+1}\| < \varepsilon \|r_0\|$，设 $d = d_{j+1}$ 为子问题的近似解，停止计算；否则设 $\beta_{j+1} = \dfrac{r_{j+1}^\mathrm{T} r_{j+1}}{r_j^\mathrm{T} r_j},\ p_{j+1} = r_{j+1} + \beta_{j+1} p_j$ 
	- *第 5 步*：设 $j := j + 1$，转*第 1 步* 
- 与传统的共轭梯度方法比较，截断共轭梯度法增加了两个出口，其一是搜索方向 $p_j$ 为零方向或沿 $B$ 的负曲率方向时 (*第 2 步*)；其二是 $d_{j+1}$ 破坏了信赖域约束时 (*第 3 步*)。两种情况下近似解均在约束的边界上达到。  
- 保证信赖域算法收敛的条件是信赖域子问题 $(question)$ 的近似解满足条件 $f(x^{(k)}) - f(x^{(k)} + d^{(k)}) \geqslant c \left[ f(x^{(k)}) - f(x^{(k)} + p_k^C) \right]$ 
- 从**算法 6.4** *步 2* 对 $j=0$ 直接计算有 $d_1 = \begin{cases} -\dfrac{\Delta}{\|\nabla f(x)\|} \nabla f(x), & \text{若 } p_0^\mathrm{T} B p_0 \leqslant 0 \\ -\dfrac{r_0^\mathrm{T} r_0}{p_0^\mathrm{T} B p_0} p_0 = -\dfrac{\nabla f(x)^\mathrm{T} \nabla f(x)}{\nabla f(x)^\mathrm{T} B \nabla f(x)} \nabla f(x), & \text{其他} \end{cases}$ 
	- 上式表示 $d_1$ 为精确的柯西点，则 $d_1$ 满足子问题近似解的条件 $f(x^{(k)}) - f(x^{(k)} + d^{(k)}) \geqslant c \left[ f(x^{(k)}) - f(x^{(k)} + p_k^C) \right]$ 
	- 另一方面，共轭梯度法具有逐步减少 $q(d)$ 值的性质，因此，**算法 6.4** 所求子问题的近似解满足信赖域算法的收敛性要求。
# 16 Fourier 级数
## 16-1 函数 Fourier 级数展开
### 16-1-1 绪论
- **三角级数**：形如 $\dfrac{a_0}2 + \sum\limits_{n=1}^\infty (a_n\cos nx + b_n\sin nx)$ 的函数项级数称为三角级数，其中 $a_0,a_n, b_n,\ (n=1,2,\cdots)$ 为常数
- **Fourier 级数**：在有限区间上用三角级数表示一般函数 $f(x)$，这个过程即为把 $f(x)$ 展开成所谓的 **Fourier 级数** 
- **Fourier 级数展开的优点**：与 Taylor 展开相比，Fourier 展开对于 $f(x)$ 的要求要宽容得多，并且它的部分和在整个区间都与 $f(x)$ 吻合得较为理想，因此 Fourier 级数是比 Taylor 级数更有力、适用性更广的工具
- 本章只介绍有关 Fourier 级数的一些基本知识，大致包括三个方面
	1. 如何将一个给定的函数 $f(x)$ 展开为 Fourier 级数（称为 **Fourier 展开**）
	2. Fourier 级数的收敛条件
	3. Fourier 级数的性质及某些相关问题
### 16-1-2 周期为 $2\pi$ 的函数的 Fourier 展开
- **前置 1**：设 $f(x)$ 在 $[-\pi, \pi]$ 上 Riemann 可积或在反常积分意义下绝对可积（简称“可积或绝对可积”），然后按 $f(x)$ 在 $[-\pi, \pi)$ 上的值周期延拓到 $(-\infty, +\infty)$，即 $f(x)$ 是定义在整个实数范围上的以 $2\pi$ 为周期的周期函数
- **前置 2**：Fourier 展开的基础是三角函数的正交性：可以证明函数族 $\{1,\sin x, \cos x, \sin 2x, \cos 2x, \cdots, \sin nx, \cos nx, \cdots \}$ 是任意一个长度为 $2\pi$ 的区间上的正交函数列，即 $\begin{aligned} & \int_{-\pi}^{\pi}\cos mx \cos nx \mathrm dx = \int_{-\pi}^{\pi} \sin mx \sin nx \mathrm dx = \pi \cdot \delta_{m,n},\ m,n\in\mathbb N^+ \\ &\int_{-\pi}^\pi \cos mx \cdot \sin nx \mathrm dx = 0,\ m=0,1,2,\cdots,n\in\mathbb N^+ \\ &\int_{-\pi}^\pi 1 \cdot \cos mx \mathrm dx = 2\pi \cdot \delta_{m,0},\ m=0,1,2,\cdots \end{aligned}$，其中 $\delta_{m,n} = \begin{cases} 1 & m=n \\ 0 & m\not= n \end{cases}$  
- **问题**：**假定** $f(x)$ 可以表示成形式为 $f(x) = \dfrac{a_0}2 + \sum\limits_{n=1}^\infty (a_n\cos nx + b_n\sin nx)$ 的级数，即**假定**等式右边的三角级数收敛于 $f(x)$，如何来确定三角级数中的系数 $a_n$ 和 $b_n$？
	- 两边同乘以 $\cos mx\ (m=0,1,2,3,\cdots)$，然后对等式两边在 $[-\pi, \pi]$ 上积分，假定等式右边的三角级数可以逐项积分，并利用上述三角函数的正交性，可知：
		$$
		\begin{aligned}
		& \int_{-\pi}^\pi f(x)\cos mx\mathrm dx = \int_{-\pi}^\pi \left[ \dfrac{a_0}2 + \sum_{n=1}^\infty (a_n\cos nx + b_n\sin nx) \right] \cos mx \mathrm dx \\
		=& \dfrac{a_0}2 \int_{-\pi}^\pi \cos mx\mathrm dx + \sum_{n=1}^\infty a_n \int_{-\pi}^\pi \cos nx \cos mx \mathrm dx + \sum_{n=1}^\infty b_n \int_{-\pi}^\pi \sin nx \cos mx \mathrm dx \\
		=& a_0\pi \delta_{m,0} + \sum_{n=1}^\infty a_n\pi \delta_{m,n} = a_m\pi
		\end{aligned}
		$$
	- 从而得到（将下标 $m$ 改写为 $n$）$\displaystyle a_n = \dfrac 1\pi \int_{-\pi}^\pi f(x)\cos nx\mathrm dx,\ (n=0,1,2,\cdots)$ 
	- 将等式两边同时乘以 $\sin mx\ (m=1,2,\cdots)$ 后在 $[-\pi, \pi]$ 上积分，同理可得到 $\displaystyle b_n = \dfrac 1\pi \int_{-\pi}^\pi f(x)\sin nx\mathrm dx,\ (n=1,2,\cdots)$ 
- **Euler-Fourier 公式**：$\displaystyle a_n = \dfrac 1\pi \int_{-\pi}^\pi f(x)\cos nx\mathrm dx,\ (n=0,1,2,\cdots)$ 和 $\displaystyle b_n = \dfrac 1\pi \int_{-\pi}^\pi f(x)\sin nx\mathrm dx,\ (n=1,2,\cdots)$ 称为 **Euler-Fourier 公式** 
	- 我们将三角级数的常数项写成 $\dfrac{a_0}2$ 而不是 $a_0$，就是为了使系数 $a_n(n=0,1,2,\cdots)$ 有上述统一的表达式
- **Fourier 级数**、**Fourier 系数**：设周期为 $2\pi$ 的函数 $f(x)$ 在 $[-\pi, \pi]$ 上可积或绝对可积，则利用 Euler-Fourier 公式就可求出系数 $a_n,b_n$，并记 $f(x) \sim \dfrac{a_0}2 + \sum_{n=1}^\infty (a_n\cos nx + b_n\sin nx)$，右端的三角级数称为 $f(x)$ 的 **Fourier 级数**，相应的 $a_n$ 和 $b_n$ 称为 $f(x)$ 的 **Fourier 系数** 
	- **注意**：目前在 $f(x)$ 和它的 Fourier 级数之间不能用等号而只能用 “$\sim$”，因为我们不知道右端的三角级数是否收敛；即使收敛，也不知道它是否收敛到 $f(x)$ 本身
- **Fourier 级数的部分和**：$S_m(x) = \dfrac{a_0}2 + \sum\limits_{n=1}^m (a_n \cos nx + b_n\sin nx)$ 就是 $f(x)$ 的 **Fourier 级数的部分和** 
### 16-1-3 正弦级数和余弦级数
- **正弦级数**：若 $f(x)$ 是奇函数，则 $\displaystyle a_n=0,\ b_n = \dfrac 2 \pi \int_0^\pi f(x)\sin nx\mathrm dx,\ (n=1,2,\cdots)$，此时相应的 Fourier 级数为 $f(x)\sim \sum\limits_{n=1}^\infty b_n \sin nx$，形如 $\sum\limits_{n=1}^\infty b_n\sin nx$ 的三角级数称为**正弦级数** 
- **余弦级数**：若 $f(x)$ 是偶函数，则 $\displaystyle b_n=0,\ a_n = \dfrac 2 \pi \int_0^\pi f(x)\cos nx\mathrm dx,\ (n=1,2,\cdots)$，此时相应的 Fourier 级数为 $f(x)\sim \dfrac{a_0}2 + \sum\limits_{n=1}^\infty a_n \cos nx$，形如 $\dfrac{a_0}2 + \sum\limits_{n=1}^\infty a_n\cos nx$ 的三角级数称为**余弦级数** 
### 16-1-4 任意周期的函数的 Fourier 展开
- 如果 $f(x)$ 的周期为 $2T$，作变换 $x=\dfrac T\pi t$，则 $\varphi(t) = f\left(\dfrac T\pi t\right) = f(x)$ 是定义在 $(-\infty, +\infty)$ 上的周期为 $2\pi$ 的函数
- 利用前面的结果，有 $\varphi(t) \sim \dfrac{a_0}2 + \sum\limits_{n=1}^\infty (a_n\cos nt + b_n\sin nt)$ 
- 代回变量，就有 $f(x)\sim \dfrac{a_0}2 + \sum\limits_{n=1}^\infty \left( a_n\cos \dfrac{n\pi}T x + b_n\sin\dfrac{n\pi}T x \right)$ 
- 相应的 Fourier 系数为 $\begin{aligned} & a_n = \dfrac 1\pi \int_{-\pi}^\pi \varphi(t)\cos nt\mathrm dt = \dfrac 1T \int_{-T}^T f(x)\cos \dfrac{n\pi}T x\mathrm dx,\ (n=0,1,2,\cdots) \\ & b_n = \dfrac 1\pi \int_{-\pi}^\pi \varphi(t)\sin nt\mathrm dt = \dfrac 1T \int_{-T}^T f(x)\sin \dfrac{n\pi}T x \mathrm dx,\ (n=1,2,\cdots) \end{aligned}$ 
## 16-2 Fourier 级数的收敛判别法
### 16-2-1 Dirichlet 积分
- **Dirichlet 积分** 
	将 Euler-Fourier 公式 $\displaystyle a_n = \dfrac 1\pi \int_{-\pi}^\pi f(x)\cos nx\mathrm dx,\ (n=0,1,2,\cdots)$ 和 $\displaystyle b_n = \dfrac 1\pi \int_{-\pi}^\pi f(x)\sin nx\mathrm dx,\ (n=1,2,\cdots)$ 代入 $S_m(x)$，则：
	$$
	\begin{aligned}
	S_m(x) =& \dfrac 1{2\pi} \int_{-\pi}^\pi f(t)\mathrm dt + \dfrac 1\pi \sum_{n=1}^m \left[ \left( \int_{-\pi}^\pi f(t)\cos nt\mathrm dt \right) \cos nx + \left( \int_{-\pi}^\pi f(t)\sin nt\mathrm dt \right) \sin nx \right] \\
	=& \dfrac 1\pi \int_{-\pi}^\pi f(t) \left[ \dfrac 12 + \sum_{n=1}^m (\cos nt\cos nx + \sin nt\sin nx) \right] \mathrm dt \\
	=& \dfrac 1\pi \int_{-\pi}^\pi f(t)\left[ \dfrac 12 + \sum_{n=1}^m \cos n(t-x) \right]\mathrm dt
	\end{aligned}
	$$
	当 $\theta\not=0$ 时，由三角函数的积化和差公式，有 $\dfrac 12 + \sum\limits_{n=1}^m \cos n\theta = \dfrac{\sin\dfrac{2m+1}2\theta}{2\sin\dfrac\theta 2}$ 
	而当 $\theta=0$ 时，若将右端理解为当 $\theta\to0$ 时的极限值，则等式依然成立
	因此，上式对任意 $\theta\in[-\pi, \pi]$ 都是正确的，于是：
	$$
	\begin{aligned}
	S_m(x) = & \dfrac 1\pi \int_{-\pi}^\pi f(t) \dfrac{\sin\dfrac{2m+1}2(t-x)}{2\sin\dfrac{t-x}2}\mathrm dt \quad (\text{作代换 }t-x=u) \\
	=& \dfrac 1\pi \int_{-\pi-x}^{\pi-x} f(x,u) \dfrac{\sin\dfrac{2m+1}2 u}{2\sin \dfrac u2}\mathrm du = \dfrac 1\pi \int_{-\pi}^\pi f(x+u)\dfrac{\sin\dfrac{2m+1}2u}{2\sin\dfrac u2} \mathrm du
	\end{aligned}
	$$
	注：最后一个等式利用了“周期函数在任何一个长度等于其周期的区间上的积分值相等”的性质
	这样，就把部分和转化成了积分形式，这个积分称为 **Dirichlet 积分**，是研究 Fourier 级数敛散性的重要工具。
- **Dirichlet 积分的惯用形式** 
	将积分区间 $[-\pi, \pi]$ 分成 $[-\pi,0]$ 和 $[0,\pi]$，稍加整理，就得到了 **Dirichlet 积分的惯用形式** $\displaystyle S_m(x) = \dfrac 1\pi \int_0^\pi [f(x+u)+f(x-u)] \dfrac{\sin\dfrac{2m+1}2u}{2\sin\dfrac u2}\mathrm du$ 
	由三角函数关系式，有 $\displaystyle \dfrac 2\pi \int_0^\pi \dfrac{\sin\dfrac{2m+1}2u}{2\sin\dfrac u2}\mathrm du = \dfrac 2\pi \int_0^\pi \left( \dfrac 12 + \sum_{n=1}^m \cos nu \right)\mathrm du = 1$ 
	因此，对任意给定的函数 $\sigma(x)$ 有 $\displaystyle S_m(x) - \sigma(x) =  \dfrac 1\pi \int_0^\pi [f(x+u) + f(x-u) - 2\sigma(x)] \dfrac{\dfrac{2m+1}2u}{2\sin\dfrac u2}\mathrm du$ 
	若记 $\varphi_\sigma(u,x) = f(x+u) + f(x-u) - 2\sigma(x)$，则 $f(x)$ 的 Fourier 级数是否收敛于某个 $\sigma(x)$ 就等价于极限 $\displaystyle \lim_{m\to\infty} \int_0^\pi \varphi_\sigma(u,x) \dfrac{\sin\dfrac{2m+1}2u}{2\sin\dfrac u2} \mathrm du$ 是否存在且等于 $0$ 
### 16-2-2 Riemann 引理及其推论
- **Riemann 引理**：设函数 $\psi(x)$ 在 $[a,b]$ 上可积或绝对可积，则成立 $\displaystyle \lim_{p\to+\infty} \int_a^b \psi(x)\sin px\mathrm dx = \lim_{p\to+\infty} \int_a^b \psi(x)\cos px\mathrm dx = 0$ 
	- *证明过程* 
		**先考虑 $\psi(x)$ 有界的情况**，这时 $\psi(x)$ Riemann 可积
		对于任意给定的 $\varepsilon>0$，存在一种划分 $a=x_0<x_1<x_2<\cdots<x_n=b$ 满足 $\sum\limits_{i=1}^n \omega_i\Delta x_i < \dfrac \varepsilon 2$，这里 $\Delta x_i = x_i - x_{i-1}$，$\omega_i$ 是 $\psi(x)$ 在 $[x_{i-1}, x_i]$ 中的振幅
		对于这种固定的划分，记 $m_i$ 是 $\psi(x)$ 在 $[x_{i-1}, x_i]$ 中的下确界，并取实数 $P=\dfrac 4\varepsilon \left( \sum\limits_{i=1}^n |m_i| \right) > 0$，则当 $p>P$ 时，有 $\dfrac 2p \left(\sum\limits_{i=1}^n |m_i| \right) < \dfrac \varepsilon 2$ 
		于是，对于任意给定的 $\varepsilon>0$，存在实数 $P>0$，当 $p>P$ 时，有：
		$$
		\begin{aligned}
		& \left| \int_a^b \psi(x)\sin px\mathrm dx \right| = \left| \sum_{i=1}^n \int_{x_{i-1}}^{x_i} \psi(x)\sin px\mathrm dx \right| \\
		=& \left| \sum_{i=1}^n \int_{x_{i-1}}^{x_i} (\psi(x) - m_i)\sin px\mathrm dx + \sum_{i=1}^n m_i \int_{x_{i-1}}^{x_i} \sin px\mathrm dx \right| \\
		\le & \sum_{i=1}^n \int_{x_{i-1}}^{x_i} |\psi(x) - m_i| \cdot |\sin px|\mathrm dx + \sum_{i=1}^n |m_i| \left| \int_{x_{i-1}}^{x_i} \sin px\mathrm dx \right| \\
		\le & \sum_{i=1}^n \int_{x_{i-1}}^{x_i} |\psi(x) - m_i|\mathrm dx + \dfrac 2p \left( \sum_{i=1}^n |m_i| \right) \\
		\le & \sum_{i=1}^n \omega_i \Delta x_i + \dfrac 2p \left(\sum_{i=1}^n |m_i|\right) < \varepsilon
		\end{aligned}
		$$
		**再考虑 $\psi(x)$ 无界的情况**，这时 $\psi(x)$ 绝对可积
		不妨假设 $b$ 是 $\psi(x)$ 的唯一奇点，由无界函数反常积分绝对收敛的定义，对于任意给定的 $\varepsilon>0$，存在 $\delta>0$，当 $\eta<\delta$ 时，成立 $\displaystyle \int_{b-\eta}^b |\psi(x)|\mathrm dx < \dfrac \varepsilon 2$ 
		固定 $\eta$，则 $\psi(x)$ 在 $[a,b-\eta]$ 上 Riemann 可积，应用上面的结论，存在实数 $P>0$，当 $p>P$ 时，$\displaystyle \left| \int_a^{b-\eta} \psi(x)\sin px\mathrm dx \right| < \dfrac \varepsilon 2$，因此：
		$$
		\begin{aligned}
		\left| \int_a^b \psi(x)\sin px\mathrm dx \right| \le & \left| \int_a^{b-\eta} \psi(x)\sin px\mathrm dx \right| + \int_{b-\eta}^b |\psi(x)\sin px|\mathrm dx \\
		\le & \left| \int_a^{b-\eta} \psi(x)\sin px\mathrm dx \right| + \int_{b-\eta}^b |\psi(x)|\mathrm dx < \varepsilon
		\end{aligned}
		$$
		所以无论对哪一种情况，都有 $\displaystyle \lim_{p\to+\infty} \int_a^b \psi(x)\sin px\mathrm dx = 0$ 
		同理可证 $\displaystyle\lim_{p\to+\infty} \int_a^b \psi(x)\cos px \mathrm dx = 0$，证毕！
- **局部性定理**：可积或绝对可积函数 $f(x)$ 的 Fourier 级数在 $x$ 点是否收敛只与 $f(x)$ 在 $(x-\delta, x+\delta)$ 的性质有关，这里 $\delta$ 是任意小的正常数
	- *证明过程* 
		由于对任意给定的 $\delta>0$，$\dfrac{f(x+u)+f(x-u)}{2\sin\dfrac u2}$ 关于 $u$ 在 $[\delta,\pi]$ 可积或绝对可积，由 Riemann 引理可知 $\displaystyle \lim_{m\to\infty} \int_\delta^\pi [f(x+u)+f(x-u)] \dfrac{\sin\dfrac{2m+1}2u}{2\sin\dfrac u2}\mathrm du = 0$ 
		因此，若将 $S_m(x)$ 的表达式中积分区间分成 $[0,\delta]$ 和 $[\delta, \pi]$ 两部分，则当 $m\to\infty$ 时，$S_m(x)$ 的敛散性显然只与 $\displaystyle \dfrac 1\pi \int_0^\delta [f(x+u)+f(x-u)] \dfrac{\sin\dfrac{2m+1}2u}{2\sin\dfrac u2}\mathrm du$ 有关，而这个积分只涉及 $f(x)$ 在 $(x-\delta, x+\delta)$ 的性质
- **推论**：设函数 $\psi(u)$ 在 $[0,\delta]$ 上可积或绝对可积，则成立 $\displaystyle \lim_{m\to\infty} \int_0^\delta \psi(u) \dfrac{\sin\dfrac{2m+1}2u}{2\sin\dfrac u2}\mathrm du = \lim_{m\to\infty} \int_0^\delta \psi(u) \dfrac{\sin\dfrac{2m+1}2u}{u}\mathrm du$ 
	- *证明过程* 
		令 $g(u) = \begin{cases} \dfrac 1{2\sin \dfrac u2} - \dfrac 1u & u>0 \\ 0 & u=0 \end{cases}$，容易验证 $g(u)$ 是 $[0,\delta]$ 上的连续函数
		由 Riemann 引理，当 $m\to\infty$ 时，有 $\displaystyle \int_0^\delta \psi(u)f \left( \dfrac 1{2\sin\dfrac u2} - \dfrac 1u \right)\sin \left( m + \dfrac 12 \right)u\mathrm du = \int_0^\delta \psi(u)g(u)\sin\left(m+\dfrac 12\right)u\mathrm du\to 0$ 
### 16-2-3 Fourier 级数的收敛判别法
- **Dini 条件**：对 $x\in[-\pi, \pi]$，只要存在某个 $\delta>0$ 使 $\dfrac{\varphi_\sigma(u,x)}u = \dfrac{f(x+u)+f(x-u)-2\sigma(x)}u$ 关于 $u$ 在 $[0,\delta]$ 上可积或绝对可积，则称满足了 **Dini 条件** 
	- 若函数 $f(x)$ 在 $x$ 点满足 Dini 条件，则 $f(x)$ 的 Fourier 级数在 $x$ 点必定收敛于 $\sigma(x)$ 
		- *证明过程* 
			若满足 Dini 条件，则由 Riemann 引理可知：对点 $x$，能找到适当的 $\sigma(x)$，使得对于充分小的定数 $\delta>0$，有 $\displaystyle \lim_{m\to\infty} \int_0^\delta \dfrac{\varphi_\sigma(u,x)}{u} \cdot \sin \dfrac{2m+1}2 u\mathrm du = 0$ 
			再由推论可知，$f(x)$ 的 Fourier 级数在 $x$ 点必定收敛于 $\sigma(x)$ 
- **探索 Fourier 级数收敛性的一把钥匙** 
	假设 $x$ 是 $f(x)$ 的连续点或第一类不连续点，而上述积分的极限存在与否只涉及 $\dfrac{\varphi_\sigma(u,x)}u$ 当 $u\to0$ 时的性质
	显然，要满足 Dini 条件首先必须有 $\lim\limits_{u\to 0} [f(x+u)+f(x-u)-2\sigma(x)]=0$，即必须有 $\sigma(x) = \dfrac{f(x+)+f(x-)}2$（显然当 $f(x)$ 在点 $x$ 连续时，有 $\sigma(x) = f(x)$）
	于是问题最终化为研究使得 $\displaystyle \lim_{p\to+\infty} \int_0^\delta \left[ f(x+u) + f(x-u) - 2 \dfrac{f(x+)+f(x-)}2 \right] \dfrac{\sin pu}u \mathrm du = 0$ 成立的条件——这时探索 Fourier 级数收敛性的一把钥匙
- **分段单调**：设函数 $f$ 在 $[a,b]$（或 $(a,b)$）上有定义，如果在 $[a,b]$（或 $(a,b)$）上存在有限个点 $a=x_0<x_1<x_2<\cdots<x_N=b$ 使得 $f$ 在每个区间 $(x_{i-1}, x_i)\ (i=1,2,\cdots,N)$ 上是单调函数，则称 $f$ 在 $[a,b]$（或 $(a,b)$）上**分段单调** 
- **Holder 条件**：设点 $x$ 是函数 $f(x)$ 的连续点或第一类不连续点，若对于充分小的正整数 $\delta$，存在常数 $L>0$ 和 $\alpha \in (0,1]$，使得成立 $|f(x\pm u) - f(x\pm)| < Lu^\alpha\ (0<u<\delta)$，则称 $f(x)$ 在点 $x$ 处满足指数为 $\alpha \in (0,1]$ 的 **Holder 条件** 
	- **Lipschitz 条件**：当 $\alpha=1$ 时 Holder 条件也成为 **Lipschitz 条件** 
- **Dirichlet 引理**：设函数 $\psi(u)$ 在 $[0,\delta]$ 上单调，则成立 $\displaystyle \lim_{p\to+\infty} \int_0^\delta \dfrac{\psi(u) - \psi(0+)}u \sin pu \mathrm du = 0$ 
	- *证明过程* 
		不妨设 $\psi(x)$ 单调增加，于是对于任意给定的 $\varepsilon>0$，存在 $\eta\in(0,\delta)$，当 $u\in (0,\eta]$ 时，$0\le \psi(u) - \psi(0+)<\varepsilon$ 
		将积分分成两部分：
		$$
		\begin{aligned}
		&\int_0^\delta \dfrac{\psi(u) - \psi(0+)}u\sin pu\mathrm du \\
		=& \int_0^\eta \dfrac{\psi(u) - \psi(0+)}u \sin pu\mathrm du + \int_\eta^\delta \dfrac{\psi(u) - \psi(0+)}u \sin pu\mathrm du
		\end{aligned}
		$$
		对于等式右边第一项，由积分第二中值定理，存在 $\xi\in [0, \eta]$，使得：
		$$
		\begin{aligned}
		& \left|\int_0^\eta \dfrac{\psi(u) - \psi(0+)}u \sin pu\mathrm du\right| \\
		=& [\psi(\eta) - \psi(0+)] \cdot \left| \int_\xi^\eta \dfrac{\sin pu}u \mathrm du \right| \\
		<& \left| \int_\xi^\eta \dfrac{\sin pu}u \mathrm du \right| \cdot \varepsilon = \left| \int_{p\xi}^{p\eta} \dfrac{\sin u}u \mathrm du \right| \cdot \varepsilon
		\end{aligned}
		$$
		利用含参变量积分中已经得到的结论：$\displaystyle \int_0^{+\infty} \dfrac{\sin x}x \mathrm dx = \dfrac \pi 2$ 
		可知存在与 $p$ 无关的常数 $K$，使得 $\displaystyle \left| \int_{p\xi}^{pq} \dfrac{\sin u}u \mathrm du \right| < K$，即 $\displaystyle \left| \int_0^\eta \dfrac{\psi(u) - \psi(0+)}u \sin pu\mathrm du \right| < K\varepsilon$ 
		而对于右边的第二项，由于 $\dfrac{\psi(u) - \psi(0+)}u$ 在 $[\eta, \delta]$ 上显然是可积或绝对可积的
		由 Riemann 引理，存在常数 $P>0$，当 $p>P$ 时，有 $\displaystyle \left| \int_\eta^\delta [\psi(u) - \psi(0+)] \dfrac{\sin pu}u \mathrm du \right| < \varepsilon$ 
		综合上述两项估计，即知结论成立
	- Dirichlet 引理也经常表达为等价形式 $\displaystyle \lim_{p\to+\infty} \int_0^\delta \psi(u) \dfrac{\sin pu}u \mathrm du = \dfrac \pi 2 \psi(0+)$ 
	- 如果 $\psi(u)$ 时分段单调有界函数，Dirichlet 引理依然成立
- **Dirichlet-Jordan 判别法**：设函数 $f(x)$ 在 $[-\pi, \pi]$ 上可积或绝对可积，且 $f(x)$ 在点 $x$ 的某个邻域 $O(x,\delta)$ 上是分段单调有界函数，则 $f(x)$ 的 Fourier 级数在点 $x$ 处收敛于 $\dfrac{f(x+)+f(x-)}2$ 
	- *证明过程* 
		由 **Dirichlet 引理**可知 $\begin{aligned} \lim_{p\to+\infty} \int_0^\delta \dfrac{f(x+u) - f(x+)}u \sin pu \mathrm du = 0 \\ \lim_{p\to+\infty} \int_0^\delta \dfrac{f(x-u) - f(x-)}u \sin pu \mathrm du = 0 \\  \end{aligned}$ 
		两式相加，既有 $\displaystyle \lim_{p\to+\infty} \int_0^\delta \left[ f(x+u) + f(x-u) - 2\dfrac{f(x+)+f(x-)}2 \right] \dfrac{\sin pu}u\mathrm du = 0$，证毕！
- **Dini-Lipschitz 判别法**：设函数 $f(x)$ 在 $[-\pi, \pi]$ 上可积或绝对可积，且 $f(x)$ 在点 $x$ 处满足指数为 $\alpha\in (0,1]$ 的 Holder 条件，则 $f(x)$ 的 Fourier 级数在点 $x$ 处收敛于 $\dfrac{f(x+)+f(x-)}2$ 
	- *证明过程* 
		在 $(0,\delta)$ 上有 $\dfrac{|f(x\pm u) - f(x\pm)|}u < \dfrac{L}{u^{1-\alpha}}\ (0<\alpha\le 1)$ 
		所以 $\dfrac{\varphi_\alpha(u,x)}u = \dfrac{f(x+u)-f(x+)}u + \dfrac{f(x-u)-f(x-)}u$ 在 $[0,\delta]$ 可积或绝对可积
		由 Riemann 引理，$\displaystyle \lim_{p\to+\infty} \int_0^\delta \left[ f(x+u) + f(x-u) - 2\dfrac{f(x+)+f(x-)}2 \right]\dfrac{\sin pu}u \mathrm du = 0$，证毕！
	- 由于“可导”强于“满足 Lipschitz 条件”，且易于验证，因此实际中往往使用如下推论。
- **推论**：若 $f(x)$ 在 $[-\pi, \pi]$ 上可积或绝对可积，在点 $x$ 处两个单侧导数 $f_+'(x)$ 和 $f_-'(x)$ 都存在，或更进一步，只要得到两个拟单侧导数 $\lim\limits_{h\to0+} \dfrac{f(x\pm h) - f(x\pm)}h$ 存在，则 $f(x)$ 的 Fourier 级数在点 $x$ 处收敛于 $\dfrac{f(x+)+f(x-)}2$ 
- **注意**：Dirichlet-Jordan 判别法和 Dini-Lipschitz 判别法都是 Fourier 级数收敛的充分条件，直至今天，还没有找到一个判别 Fourier 级数敛散性的充要条件。
- **应用**：Dirichlet-Jordan 判别法和 Dini-Lipschitz 判别法告诉我们，若收敛条件满足，则 $f(x)$ 的 Fourier 级数在连续点收敛于函数值本身，而在第一类不连续点收敛于它左右极限的算术平均值
	- 对于连续的周期函数 $f(x)$，应将 $f(x)$ 与它的（收敛的）Fourier 级数间的“$\sim$”改为“$=$”
	- 若周期函数 $f$ 含有第一类不连续点，那么展成 Fourier 级数后，要对这些点予以特殊说明
## 16-3 Fourier 级数的性质
### 16-3-1 Fourier 级数的分析性质
- 假定：$f(x)$ 的周期为 $2\pi$ 
- **定理**：设 $f(x)$ 在 $[-\pi, \pi]$ 上可积或绝对可积，则对于 $f(x)$ 的 Fourier 系数 $a_n$ 与 $b_n$，有 $\lim\limits_{n\to\infty} a_n = 0,\ \lim\limits_{n\to\infty} b_n = 0$ 
- **Fourier 级数的逐项积分定理**：设 $f(x)$ 在 $[-\pi, \pi]$ 上可积或绝对可积，$f(x) \sim \dfrac{a_0}2 + \sum\limits_{n=1}^\infty (a_n\cos nx + b_n\sin nx)$，则 $f(x)$ 的 Fourier 级数可以逐项积分，即对于任意 $c,x\in [-\pi, \pi]$ 有 $\displaystyle \int_c^x f(t)\mathrm dt = \int_c^x \dfrac{a_0}2 \mathrm dt + \sum_{n=1}^\infty \int_c^x (a_n\cos nt + b_n \sin nt)\mathrm dt$ 
	- *证明过程* 
		由于尚未具备足够的数学工具，这里仅对 $f(x)$ 在 $[-\pi, \pi]$ 上只有有限个第一类不连续点的情况加以证明
		考虑函数 $\displaystyle F(x) = \int_c^x \left[f(t) - \dfrac{a_0}2 \right] \mathrm dt$，则 $F(x)$ 是周期为 $2\pi$ 的连续函数，且在 $f(x)$ 的连续点成立 $F'(x) = f(x) - \dfrac{a_0}2$，而在 $f(x)$ 的第一类不连续点，$F(x)$ 的两个单侧导数 $F_{\pm}'(x) = f(x\pm) - \dfrac{a_0}2$ 都存在
		由 Dini-Lipschitz 判别法的推论，$F(x)$ 可展开为收敛的 Fourier 级数 $F(x) = \dfrac{A_0}2 + \sum\limits_{n=1}^\infty (A_n\cos nx + B_n \sin nx)$ 
		利用分部积分法，即有：
		$$
		\begin{aligned}
		A_n = & \dfrac 1\pi \int_{-\pi}^\pi F(x)\cos nx \mathrm dx = \dfrac 1\pi \left. \left[ \dfrac{\sin nx}n F(x) \right] \right|_{-\pi}^\pi - \dfrac 1{n\pi}\int_{-\pi}^\pi F'(x)\sin nx \mathrm dx \\
		= & -\dfrac 1{n\pi} \int_{-\pi}^\pi \left[ f(x) - \dfrac{a_0}2 \right]\sin nx\mathrm dx = - \dfrac{b_n}n
		\end{aligned}
		$$
		类似可知 $B_n = \dfrac{a_n}n$ 
		于是 $F(x) = \dfrac{A_0}2 + \sum\limits_{n=1}^\infty \left( -\dfrac{b_n}n \cdot nx + \dfrac{a_n}n \sin nx \right)$ 
		令 $x=c$，有 $0 = \dfrac{A_0}2 + \sum\limits_{n=1}^\infty \left( -\dfrac{b_n}n \cos nc + \dfrac{a_n}n \sin nc \right)$ 
		两式相减并整理，得到：
		$$
		\begin{aligned}
		F(x) = & \int_c^x \left[ f(t) - \dfrac{a_0}2 \right] \mathrm dt = \sum_{n=1}^\infty \left( a_n \dfrac{\sin nx - \sin nc} + b_n \dfrac{-\cos nx + \cos nc}n \right) \\
		= & \sum_{n=1}^\infty \int_c^x (a_n\cos nt + b_n\sin nt)\mathrm dt
		\end{aligned}
		$$
	- 关于逐项积分，Fourier 级数有非常好的性质
	- **注意**：只要 $f(x)$ 可以展成 Fourier 级数 $\dfrac{a_0}2 + \sum\limits_{n=1}^\infty(a_n\cos nx + b_n\sin nx)$，哪怕这个级数并不表示 $f(x)$，甚至根本不收敛，它的逐项积分级数也一定能收敛于 $f(x)$ 的积分
	- **推论**：$\dfrac{a_0}2 + \sum\limits_{n=1}^\infty(a_n\cos nx + b_n\sin nx)$ 是某个在 $[-\pi, \pi]$ 上可积或绝对可积函数的 Fourier 级数的必要条件是 $\sum\limits_{n=1}^\infty \dfrac{b_n}n$ 收敛
		- **注意**：因此，并不是随便拿来一个收敛的三角级数就能说它一定是某个函数的 Fourier 级数的。
		- **例子**：如三角级数 $\sum\limits_{n=2}^\infty \dfrac{\sin nx}{\ln n}$，由 Dirichlet 判别法可知它是点点收敛的，但由于 $\sum\limits_{n=2}^\infty \dfrac 1{n\ln n}$ 发散，它不可能是某个可积或绝对可积函数的 Fourier 级数
- **Fourier 级数的逐项微分定理**：设 $f(x)$ 在 $[-\pi, \pi]$ 上连续，$f(x) \sim \dfrac{a_0}2 + \sum\limits_{n=1}^\infty(a_n\cos nx + b_n\sin nx)$，$f(-\pi) = f(\pi)$，且除了有限个点外 $f(x)$ 可导。进一步假设 $f'(x)$ 在 $[-\pi, \pi]$ 上可积或绝对可积（注意：$f'(x)$ 在有限个点可能无定义，但这并不影响其可积性），则 $f'(x)$ 的 Fourier 级数可由 $f(x)$ 的 Fourier 级数逐项微分得到，即 $f'(x) \sim \dfrac{\mathrm d}{\mathrm dx} \left( \dfrac{a_0}2 \right) + \sum\limits_{n=1}^\infty \dfrac{\mathrm d}{\mathrm dx}(a_n\cos nx + b_n\sin nx) = \sum\limits_{n=1}^\infty (-a_n n \sin nx + b_n n \cos nx)$ 
	- *证明过程* 
		由所给条件，此时 $f'(x)$ 可展开为 Fourier 级数，记 $f'(x)$ 的 Fourier 系数为 $a_n', b_n'$，则有：
		$$
		\begin{aligned}
		a_0' = & \dfrac 1\pi \int_{-\pi}^\pi f'(x)\mathrm dx = \dfrac 1\pi[f(\pi) - f(-\pi)] = 0 \\ 
		a_n' = & \dfrac 1\pi \int_{-\pi}^\pi f'(x)\cos nx\mathrm dx \\
		= & \left.\dfrac{f(x)\cos nx}\pi\right|_{-\pi}^\pi+ \dfrac n\pi \int_{-\pi}^\pi f(x)\sin nx\mathrm dx = nb_n & \quad(n=1,2,\cdots) \\
		b_n' = & \dfrac 1\pi \int_{-\pi}^\pi f'(x)\sin nx\mathrm dx = -na_n & \quad (n=1,2,\cdots)
		\end{aligned}
		$$
		于是 $f'(x)\sim \sum\limits_{n=1}^\infty (-a_n n\sin nx + b_n n\cos nx)$ 
	- Fourier 级数逐项微分的结果远没有逐项积分那么好了。一般来说，Fourier 级数是不能逐项积分的，除非加上特别的条件
### 16-3-2 Fourier 级数的逼近性质
- **最佳平方逼近元素**：设 $S$ 是一个定义了内积运算 $(\cdot, \cdot)$ 的线性空间，令 $S$ 中的范数为 $\| \cdot \| = \sqrt{(\cdot, \cdot)}$。$T$ 是 $S$ 的一个 $n$ 维子空间，记 $T$ 的一组正交基为 $\varphi_1, \varphi_2, \cdots, \varphi_n$，即 $T = \mathrm{span}\{\varphi_1, \varphi_2, \cdots, \varphi_n\}$。若对于 $x\in S$，有 $x_T = c_1\varphi_1 + c_2\varphi_2 + \cdots + c_n\varphi_n \in T$ 使得 $\| x-x_T \| = \min\limits_{y\in T} \| x-y \|$，则称 $x_T$ 是 $x$ 在 $T$ 中的**最佳平方逼近元素** 
- **引理**：在上述假定下，有下面 3 条结论成立
	(1) 对于任意 $x\in S$，$x$ 在 $T$ 中的最佳平方逼近元素 $x_T$ 存在且唯一
	(2) $x_T\in T$ 是 $x$ 在 $T$ 中的最佳平方逼近元素 $\iff$ $x-x_T\perp T$（即 $(x-x_T, \varphi_k) = 0,\ (k=1,2,\cdots,n)$）$\iff$ $x_T$ 的组合系数 $c_k = \dfrac{(x,\varphi_k)}{(\varphi_k,\varphi_k)},\ (k=1,2,\cdots,n)$ 
	(3) 最佳平方逼近的余项满足估计式 $\| x-x_T \|^2 = \|x\|^2 - \|x_T\|^2 = \|x\|^2 - \sum\limits_{k=1}^n c_k^2 \| \varphi_k \|^2$ 
	- *证明过程* 
		**对于 (1) 和 (3)** 
		令 $c_k = \dfrac{(x,\varphi_k)}{(\varphi_k, \varphi_k)}$，则对于任意的 $y=d_1\varphi_1 + d_2\varphi_2 + \cdots + d_n\varphi_n \in T$，利用 $(\varphi_j, \varphi_k) = 0\ (j\not=k)$ 得到：
		$$
		\begin{aligned}
		\| x-y\|^2 = & \left(x - \sum_{k=1}^n d_k\varphi_k, x - \sum_{k=1}^n d_k\varphi_k \right) \\
		= & (x,x) - 2\sum_{k=1}^n d_k(x,\varphi_k) + \sum_{k=1}^n d_k^2(\varphi_k, \varphi_k) \\
		= & \| x \|^2 - 2\sum_{k=1}^n c_kd_k \| \varphi_k \|^2 + \sum_{k=1}^n d_k^2 \| \varphi_k \|^2 \\
		= & \| x \|^2 - \sum_{k=1}^n c_k^2 \|\varphi_k\|^2 + \sum_{k=1}^n (c_k-d_k)^2 \|\varphi_k\|^2
		\end{aligned}
		$$
		于是，当且仅当 $d_k=c_k\ (k=1,2,\cdots,n)$ 时，$\| x-y\|$ 达到最小值
		因此取 $x_T = \sum\limits_{k=1}^n c_k\varphi_k$，则 $\|x-x_T\| = \min\limits_{y\in T} \|x-y\|$，且 $\| x-x_T\|^2 = \|x \|^2 - \sum\limits_{k=1}^n c_k^2 \| \varphi_k \|^2 = \| x \|^2 - \| x_T \|^2$，证毕！
		**对于 (2)** 
		对于每个 $k=1,2,\cdots,n$，$x$ 在 $T$ 中的最佳平方逼近元素 $x_T = \sum\limits_{k=1}^n c_k\varphi_k$ 满足：
		$$
		\begin{aligned}
		(x-x_T, \varphi_k) = & \left(x - \sum_{j=1}^n c_j\varphi_j, \varphi_k \right) = (x-\varphi_k) - \sum_{j=1}^n c_j(\varphi_j, \varphi_k) \\
		= & c_k \| \varphi_k \|^2 - c_k\|\varphi_k\|^2 = 0
		\end{aligned}
		$$
		反之，若 $y=d_1\varphi_1 + d_2\varphi_2 + \cdots + d_n\varphi_n \in T$ 满足 $(x-y, \varphi_k) = 0,\ (k=1,2,\cdots,n)$ 
		那么 $0=(x,\varphi_k) - (y,\varphi_k) = (x,\varphi_k) - \left( \sum\limits_{j=1}^n d_j\varphi_j, \varphi_k \right) = (x,\varphi_k) - d_k(\varphi_k, \varphi_k),\ (k=1,2,\cdots,n)$ 
		因此 $d_k = \dfrac{(x,\varphi_k)}{(\varphi_k, \varphi_k)} = c_k$，即 $y=x_T$，证毕！
- **$n$ 阶三角多项式**：即为 $\dfrac{A_0}2 + \sum\limits_{k=1}^n (A_k\cos kx + B_k\sin kx)$ 
- 定义 $S$、可积或平方可积、$S$ 的内积和范数、$T$：现在，具体地取  为 $[-\pi, \pi]$ 上 Riemann 可积或在反常积分意义下平方可积（简称为“**可积或平方可积**”）的函数 $f(x)$ 全体；$S$ 中的内积 $(\cdot, \cdot)$ 和范数 $\| \cdot \|$ 定义为 $\displaystyle (f,g) = \dfrac 1\pi \int_{-\pi}^\pi f(x)g(x)\mathrm dx$ 和 $\| f\| = \sqrt{(f,f)}$。$T$ 为 $n$ 阶三角多项式 $\dfrac{A_0}2 + \sum\limits_{k=1}^n (A_k\cos kx + B_k\sin kx)$ 的全体，利用前面已经得到的正交性，可将 $T$ 表示为 $T = \mathrm{span} \{1, \cos x, \sin x, \cos 2x, \sin 2x, \cdots, \cos nx, \sin nx\}$ 
	- 故有 $\|1\|^2=2$ 和 $\|\cos kx\|^2 = \|\sin kx \|^2 = 1,\ (k=1,2,\cdots,n)$ 
	- 由 Fourier 系数的 Euler-Fourier 公式，得到 $\begin{aligned} &(f, \cos kx) = \dfrac 1\pi \int_{-\pi}^\pi f(x)\cos kx \mathrm dx = a_k,\ (k=0,1,2,\cdots,n) \\ &(f, \sin kx) = \dfrac 1\pi \int_{-\pi}^\pi f(x)\sin kx \mathrm dx = b_k,\ (k=1,2,\cdots,n)  \end{aligned}$ 
- **Fourier 级数的平方逼近性质**：设 $f(x)$ 在 $[-\pi, \pi]$ 上可积或平方可积，则 $f(x)$ 在 $T$ 中的最佳平方逼近元素恰为 $f(x)$ 的 Fourier 级数的部分和函数 $S_n(x) = \dfrac{a_0}2 + \sum\limits_{k=1}^n (a_k\cos kx + b_k\sin kx)$，逼近的余项为 $\displaystyle \| f - S_n\|^2 = \dfrac 1\pi \int_{-\pi}^\pi f^2(x)\mathrm dx - \left[ \dfrac{a_0^2}2 + \sum_{k=1}^n (a_k^2 + b_k^2) \right]$ 
- **Bessel 不等式**：设 $f(x)$ 在 $[-\pi, \pi]$ 上可积或平方可积，则 $f(x)$ 的 Fourier 系数满足不等式 $\displaystyle \dfrac{a_0^2}2 + \sum_{k=1}^\infty (a_k^2 + b_k^2) \le \dfrac 1\pi \int_{-\pi}^\pi f^2(x)\mathrm dx$ 
	- *证明过程* 
		因为 $\| f-S_n\|^2\ge 0$，在余项中令 $n\to\infty$ 即证
	- 这表明 Fourier 系数的平方组成了一个收敛的级数
- **Parseval 等式**（**能量恒等式**）：设 $f(x)$ 在 $[-\pi, \pi]$ 上可积或平方可积，则成立等式 $\displaystyle \dfrac{a_0^2}2 + \sum_{k=1}^\infty(a_k^2+b_k^2) = \dfrac 1\pi \int_{-\pi}^\pi f^2(x)\mathrm dx$ 
- **平方收敛**：若函数序列 $\{\psi_n(x)\}$ 满足 $\lim\limits_{n\to\infty} \| f(x) - \psi_n(x)\|^2 = 0$，这里 $f(x)$ 是某一个固定函数，则称 $\{\psi_n(x)\}$ 按范数 $\| \cdot \|$ **平方收敛于** $f(x)$，简称 $\psi_n(x)$ **平方收敛于** $f(x)$ 
- **Fourier 级数的平方收敛性质**：设 $f(x)$ 在 $[-\pi, \pi]$ 上可积或平方可积，则 $f(x)$ 的 Fourier 级数的部分和函数序列平方收敛于 $f(x)$ 
	- *证明过程* 
		由 Parseval 等式 $\displaystyle \lim_{n\to\infty} \| f - S_n \|^2 = \dfrac 1\pi \int_{-\pi}^\pi f^2(x)\mathrm dx - \left[ \dfrac{a_0^2}2 + \sum_{k=1}^\infty (a_k^2 + b_k^2) \right] = 0$，证毕！
- **Weierstrass 第二逼近定理**：对周期为 $2\pi$ 的任意一个连续函数 $f(x)$，都存在三角多项式序列 $\left\{ \psi_n(x) = \dfrac{A_0}2 + \sum_{k=1}^n (A_k\cos kx + B_k \sin kx) \right\}$ 使得 $\{\psi_n(x)\}$ 一致收敛于 $f(x)$ 
### 16-3-3 等周问题
- **等周问题**：在平面上周长相等的所有简单闭曲线中，怎样的曲线所围图形的面积最大？这就是著名的**等周问题** 
- **Wirtinger 引理**：设 $f(x)$ 在 $[-\pi, \pi]$ 上连续，$f(-\pi) = f(\pi)$，$\displaystyle \int_{-\pi}^\pi f(x)\mathrm dx = 0$，且除了有限个点外 $f(x)$ 可导，但在不可导的点，$f(x)$ 的单侧导数存在。进一步假设，$f(x)$ 的导数 $f'(x)$ 在 $[-\pi, \pi]$ 上可积或平方可积，则 $\displaystyle \int_{-\pi}^\pi f^2(x)\mathrm dx \le \int_{-\pi}^\pi f'^2(x)\mathrm dx$，等号成立当且仅当 $f(x) = a\cos x + b\sin x\ (a,b\text{ 为常数})$ 
	- *证明过程* 
		可知 $f(x)$ 的 Fourier 级数在 $[-\pi, \pi]$ 上点点收敛于 $f(x)$ 
		由于 $\displaystyle a_0 = \dfrac 1\pi \int_{-\pi}^\pi f(x)\mathrm dx = 0$，所以 $f(x) = \sum\limits_{n=1}^\infty(a_n\cos nx + b_n\sin nx),\ x\in[-\pi, \pi]$ 
		进一步，由 **Fourier 级数的逐项微分定理**可知 $f'(x) \sim \sum\limits_{n=1}^\infty (-a_n n\sin nx + b_n n\cos nx)$ 
		于是，由 **Parseval 等式**得到：$\begin{aligned} &\dfrac 1\pi \int_{-\pi}^\pi f^2(x)\mathrm dx = \sum_{k=1}^\infty (a_k^2 + b_k^2) \\ & \dfrac 1\pi \int_{-\pi}^\pi f'^2(x)\mathrm dx = \sum_{k=1}^\infty n^2(a_k^2+b_k^2) \end{aligned}$ 及 $\displaystyle \int_{-\pi}^\pi f'^2(x)\mathrm dx - \int_{-\pi}^\pi f^2(x)\mathrm dx = \pi \sum_{k=2}^\infty (n^2-1)(a_k^2 + b_k^2)$ 
		上式说明 $\displaystyle \int_{-\pi}^\pi f'^2(x)\mathrm dx - \int_{-\pi}^\pi f^2(x)\mathrm dx \ge 0$，并且等号成立当且仅当 $a_n=0, b_n=0\ (n=2,3,\cdots)$，即 $f(x) = a_1\cos x + b_1\sin x$，证毕！
- **定理**：平面上具有定长的所有简单闭曲线中，圆周所围的面积最大。换言之，若 $L$ 是平面上简单闭曲线 $C$ 的长度，$A$ 是曲线 $C$ 所围图形的面积，则 $A\le \dfrac{L^2}{4\pi}$，且等号成立时，$C$ 必须是圆周。
	- *证明过程* 
		仅限于对平面上分段光滑的简单闭曲线讨论此问题
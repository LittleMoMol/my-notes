# 定义
Riemann 函数 $R(x) = \begin{cases} \dfrac 1p & x = \dfrac{p}{q} (p\in \mathbb N^+,\ q\in \mathbb Z  - \{0\},\ \gcd(p,q)=1) \\ 1 & x=0 \\ 0 & x\text{ 为无理数} \end{cases}$ 
# 性质
- Riemann 函数在 $[0,1]$ 上可积
	- *证明过程* 
		由 $R(x)$ 的定义和有理数是可列集，对任意给定的 $\varepsilon>0$，在 $[0,1]$ 上使得 $R(x)>\varepsilon$ 的点至多有有限个，不妨设共有 $k$ 个，记这 $k$ 个点为 $0 = P_1' < P_2' < \cdots < P_k' = 1$ 
		作 $[0,1]$ 上的划分 $0=x_0<x_1<x_2<\cdots<x_{2k-1}=1$，满足：
		$P_1'\in[x_0,x_1),\ x_1-x_0<\varepsilon$ 
		$P_2'\in(x_2,x_3),\ x_3-x_2<\varepsilon$ 
		……
		$P_{k-1}'\in(x_{2k-4},x_{2k-3}),\ x_{2k-3}-x_{2k-4}<\varepsilon$ 
		$P_k'\in(x_{2k-2},x_{2k-1}],\ x_{2k-1}-x_{2k-2}<\varepsilon$ 
		由于 $\sum\limits_{i=1}^{2k-1} = \omega_i\Delta x_i = \underbrace{\sum\limits_{j=0}^{k-1}\omega_{2j+1}\Delta x_{2j+1}}_{\text{奇项}} + \underbrace{\sum\limits_{j=1}^{k-1} \omega_{2j}\Delta x_{2j}}_{\text{偶项}}$，且有：
		对于奇项：$\Delta x_{2j+1} = x_{2j+1} - x_{2j}<\varepsilon,\ \omega_{2j+1}\le 1$ 
		对于偶项：$\Delta x_{2j} = x_{2j} - x_{2j-1} \le \varepsilon, \sum\limits_{j=1}^{k-1} \Delta x_{2j} < 1$ 
		故 $\begin{aligned} \sum\limits_{i=1}^{2k-1} &= \omega_i\Delta x_i = \underbrace{\sum\limits_{j=0}^{k-1}\omega_{2j+1}\Delta x_{2j+1}}_{\text{奇项}} + \underbrace{\sum\limits_{j=1}^{k-1} \omega_{2j}\Delta x_{2j}}_{\text{偶项}} \\  &< k \cdot 1 \cdot \varepsilon + 1 \cdot \varepsilon = (k+1)\varepsilon \end{aligned}$ 
		故 Riemann 函数可积
- 
		
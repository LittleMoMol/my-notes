# 定义
Dirichlet 函数 $D(x) = \begin{cases} 1 & x\text{ 为有理数} \\ 0 & x\text{ 为无理数} \end{cases}$ 
# 性质
- Dirichlet 函数在 $[0,1]$ 上不可积
	- *证明过程* 
		由有理数、无理数在实数域上的稠密性可知，不管如何分割，每个小区间 $[x_{i-1}, x_i]$ 上的振幅恒有 $\omega_i = 1$ 
		于是 $\lim\limits_{\lambda\to 0}\sum\limits_{i=1}^n\omega_i\Delta x_i = \lim\limits_{\lambda\to 0}\sum\limits_{i=1}^n \Delta x_i = 1\not= 0$，故 Dirichlet 函数不是 Riemann 可积的
# 5 解析函数得洛朗 (Laurent) 展式与孤立奇点
在前一章我们已经看出，用泰勒级数来表示圆形区域内的解析函数是很方便的。但是对于有些特殊函数，如贝塞尔 (Bessel) 函数，以圆心为奇点，就不能在奇点邻域内表示成泰勒级数。为此，本章将建立 (挖去奇点 $a$ 的) 圆环 $r<|z-a|<R$ ($r\geqslant 0,R\leqslant +\infty$，当 $r=0$ 时为去心圆 $0<|z-a|<R$) 内解析函数的级数表示，并以它为工具去研究解析函数在孤立奇点邻域内的性质。
## 5-1 解析函数的洛朗展式
### 5-1-1 双边幂级数
- **双边幂级数** 
	考虑两个级数
	$$
	\begin{aligned}
	& c_{0}+c_{1}(z-a)+c_{2}(z-a)^{2}+\cdots\quad (t1) \\
	& \dfrac{c_{-1}}{z-a}+\dfrac{c_{-2}}{(z-a)^{2}}+\cdots\quad (t2)
	\end{aligned}
	$$
	前者是幂级数，故它在收敛圆 $|z-a|<R\ (0<R\leqslant +\infty)$ 内表示一解析函数 $f_{1}(z)$。
	对第二个级数作代换 $\zeta=\dfrac{1}{z-a}$，则它成为一个幂级数 $c_{-1}\zeta+c_{-2}\zeta^{2}+\cdots$ 
	设它的收敛区域为 $|\zeta|<\dfrac{1}{r}\left(0<\dfrac{1}{r}\leqslant +\infty\right)$，换回到原来的变数 $z$，即知 $(t2)$ 在 $|z-a|>r\ (0\leqslant r<+\infty)$ 内表示一解析函数 $f_{2}(z)$。
	当且仅当 $r<R$ 时，$(t1)$ 及 $(t2)$ 有公共的收敛区域即圆环 $H:r<|z-a|<R$。这时，我们称级数 $(t1)$ 与 $(t2)$ 之和为**双边幂级数**，可以表示为 $\sum\limits_{n=-\infty}^{\infty}c_{n}(z-a)^{n}$ 
- 由以上讨论及定理 4.11 和定理 4.14 得
- **定理 5.1**：
	设双边幂级数 $\sum\limits_{n=-\infty}^{\infty}c_{n}(z-a)^{n}$ 的收敛圆环为 $H:r<|z-a|<R\ (r\geqslant 0,R\leqslant +\infty)$，则
	(1) $\sum\limits_{n=-\infty}^{\infty}c_{n}(z-a)^{n}$ 在 $H$ 内绝对收敛且内闭一致收敛于 $f(z)=f_{1}(z)+f_{2}(z)$ 
	(2) 函数 $f(z)$ 在 $H$ 内解析。
	(3) 函数 $f(z)=\sum\limits_{n=-\infty}^{\infty}c_{n}(z-a)^{n}$ 在 $H$ 内可逐项求导 $p$ 次 $(p=1,2,\cdots)$。
	(4) 函数 $f(z)$ 可沿 $H$ 内曲线 $C$ 逐项积分。
	- *注*：定理 5.1 对应于定理 4.14。
### 5-1-2 解析函数的洛朗展式
- 前面指出了双边幂级数在其收敛圆环内表示一解析函数，反过来有
- **定理 5.2** (**洛朗定理**)：在圆环 $H:r<|z-a|<R\ (r\geqslant 0,R\leqslant +\infty)$ 内解析的函数 $f(z)$ 必可展成双边幂级数 $f(z)=\sum\limits_{n=-\infty}^{\infty}c_{n}(z-a)^{n}$，其中 $\displaystyle c_{n}=\dfrac{1}{2\pi \mathrm{i}}\int_{\Gamma}\dfrac{f(\zeta)}{(\zeta-a)^{n+1}}\,\mathrm{d}\zeta\ (n=0,\pm 1,\pm 2,\cdots)$，$\Gamma$ 为圆周 $|\zeta-a|=\rho\ (r<\rho<R)$，并且展式是惟一的 (即 $f(z)$ 及圆环 $H$ 惟一地决定了系数 $c_{n}$)。
	- *注*：定理 5.2 对应于定理 4.15 (泰勒定理)。
	- *证明过程* 
		设 $z$ 为 $H$ 内任意取定的点，总可以找到含于 $H$ 内的两个圆周
		$$
		\begin{aligned}
		&\Gamma_{1}:|\zeta-a|=\rho_{1} \\
		&\Gamma_{2}:|\zeta-a|=\rho_{2}
		\end{aligned}
		$$
		使得 $z$ 含在圆环 $\rho_{1}<|z-a|<\rho_{2}$ 内 (图 5.1)。
		![[Pasted image 20260901224829.png|175]]
		因为函数 $f(z)$ 在闭圆环 $\rho_{1}\leqslant |z-a|\leqslant \rho_{2}$ 上解析，由柯西积分公式有
		$$f(z)=\dfrac{1}{2\pi \mathrm{i}}\int_{\Gamma_{2}}\dfrac{f(\zeta)}{\zeta-z}\,\mathrm{d}\zeta-\dfrac{1}{2\pi \mathrm{i}}\int_{\Gamma_{1}}\dfrac{f(\zeta)}{\zeta-z}\,\mathrm{d}\zeta,$$
		或写成
		$$f(z)=\dfrac{1}{2\pi \mathrm{i}}\int_{\Gamma_{2}}\dfrac{f(\zeta)}{\zeta-z}\,\mathrm{d}\zeta+\dfrac{1}{2\pi \mathrm{i}}\int_{\Gamma_{1}}\dfrac{f(\zeta)}{z-\zeta}\,\mathrm{d}\zeta \tag{t1}$$
		我们将上式中的两个积分表示为含有 $z-a$ 的 (正或负) 幂次的级数。
		对于第一个积分，只要照抄泰勒定理 4.15 证明中的相应部分，就得
		$$
		\begin{aligned}
		& \dfrac{1}{2\pi \mathrm{i}}\int_{\Gamma_{2}}\dfrac{f(\zeta)}{\zeta-z}\,\mathrm{d}\zeta=\sum_{n=0}^{\infty}c_{n}(z-a)^{n} \quad(t2) \\
		& c_{n}=\dfrac{1}{2\pi \mathrm{i}}\int_{\Gamma_{2}}\dfrac{f(\zeta)}{(\zeta-a)^{n+1}}\,\mathrm{d}\zeta \ (n=0,1,2,\cdots) \quad (t3)
		\end{aligned}
		$$
		类似地，考虑 $(t1)$ 中的第二个积分 $\displaystyle \dfrac{1}{2\pi \mathrm{i}}\int_{\Gamma_{1}}\dfrac{f(\zeta)}{z-\zeta}\,\mathrm{d}\zeta$，我们有 $\dfrac{f(\zeta)}{z-\zeta}=\dfrac{f(\zeta)}{(z-a)-(\zeta-a)}=\dfrac{f(\zeta)}{z-a}\cdot\dfrac{1}{1-\dfrac{\zeta-a}{z-a}}$ 
		当 $\zeta\in\Gamma_{1}$ 时，$\left|\dfrac{\zeta-a}{z-a}\right|=\dfrac{\rho_{1}}{|z-a|}<1$，于是上式可以展成一致收敛的级数 $\dfrac{f(\zeta)}{z-\zeta}=\dfrac{f(\zeta)}{z-a}\sum\limits_{n=1}^{\infty}\left(\dfrac{\zeta-a}{z-a}\right)^{n-1}$ 
		沿 $\Gamma_{1}$ 逐项积分，再以 $\dfrac{1}{2\pi \mathrm{i}}$ 乘两端即得
		$$
		\begin{aligned}
		& \dfrac{1}{2\pi \mathrm{i}}\int_{\Gamma_{1}}\dfrac{f(\zeta)}{z-\zeta}\,\mathrm{d}\zeta=\sum_{n=1}^{\infty}\dfrac{c_{-n}}{(z-a)^{n}} \quad (t4) \\
		& c_{-n}=\dfrac{1}{2\pi \mathrm{i}}\int_{\Gamma_{1}}\dfrac{f(\zeta)}{(\zeta-a)^{-n+1}}\,\mathrm{d}\zeta\ (n=1,2,\cdots) \quad (t5)
		\end{aligned}
		$$
		由 $(t1),(t2),(t4)$ 即得
		$$f(z)=\sum_{n=0}^{\infty}c_{n}(z-a)^{n}+\sum_{n=1}^{\infty}\dfrac{c_{-n}}{(z-a)^{n}}=\sum_{n=-\infty}^{\infty}c_{n}(z-a)^{n}$$
		回过头来考察系数 $(t3)$ 及 $(t5)$，由复周线的柯西积分定理，对任意圆周 $\Gamma:|z-a|=\rho\ (r<\rho<R)$，有
		$$\begin{aligned}
		c_{n}&=\dfrac{1}{2\pi \mathrm{i}}\int_{\Gamma_{2}}\dfrac{f(\zeta)}{(\zeta-a)^{n+1}}\,\mathrm{d}\zeta \\
		&=\dfrac{1}{2\pi \mathrm{i}}\int_{\Gamma}\dfrac{f(\zeta)}{(\zeta-a)^{n+1}}\,\mathrm{d}\zeta \quad (n=0,1,2,\cdots),\\
		c_{-n}&=\dfrac{1}{2\pi \mathrm{i}}\int_{\Gamma_{1}}\dfrac{f(\zeta)}{(\zeta-a)^{-n+1}}\,\mathrm{d}\zeta \\
		&=\dfrac{1}{2\pi \mathrm{i}}\int_{\Gamma}\dfrac{f(\zeta)}{(\zeta-a)^{-n+1}}\,\mathrm{d}\zeta \quad (n=1,2,\cdots),
		\end{aligned}$$
		于是系数可统一表示成 $\displaystyle c_{n}=\dfrac{1}{2\pi \mathrm{i}}\int_{\Gamma}\dfrac{f(\zeta)}{(\zeta-a)^{n+1}}\,\mathrm{d}\zeta\ (n=0,\pm 1,\pm 2,\cdots)$。
		因为系数 $c_{n}$ 与我们所取的 $z$ 根本无关，故在圆环 $H$ 内 $f(z)=\sum\limits_{n=-\infty}^{\infty}c_{n}(z-a)^{n}$ 成立。
		最后证明展式的惟一性。
		设 $f(z)$ 在圆环 $H$ 内又可展成下式：$f(z)=\sum\limits_{n=-\infty}^{\infty}c_{n}'(z-a)^{n}$ 
		由定理 5.1 知，它在圆周 $\Gamma:|z-a|=\rho$（$r<\rho<R$）上一致收敛。乘沿 $\Gamma$ 上的有界函数 $\dfrac{1}{(z-a)^{m+1}}$，仍然一致收敛，故可逐项积分得
		$$\int_{\Gamma}\dfrac{f(\zeta)}{(\zeta-a)^{m+1}}\,\mathrm{d}\zeta=\sum_{n=-\infty}^{\infty}c_{n}'\int_{\Gamma}(\zeta-a)^{n-m-1}\,\mathrm{d}\zeta,$$
		由例 3.2 即知等号右端级数中 $n=m$ 那一项积分为 $2\pi \mathrm{i}$，其余各项为零，于是
		$$c_{m}'=\dfrac{1}{2\pi \mathrm{i}}\int_{\Gamma}\dfrac{f(\zeta)}{(\zeta-a)^{m+1}}\,\mathrm{d}\zeta \quad (m=0,\pm 1,\pm 2,\cdots),$$
		比较即知 $c_{n}'=c_{n}\ (n=0,\pm 1,\pm 2,\cdots)$。
- **洛朗展式**、**洛朗系数**、**洛朗级数**：$f(z)=\sum\limits_{n=-\infty}^{\infty}c_{n}(z-a)^{n}$ 称为函数 $f(z)$ 在点 $a$ 的**洛朗展式**，$\displaystyle c_{n}=\dfrac{1}{2\pi \mathrm{i}}\int_{\Gamma}\dfrac{f(\zeta)}{(\zeta-a)^{n+1}}\,\mathrm{d}\zeta\ (n=0,\pm 1,\pm 2,\cdots)$ 称为其**洛朗系数**，而 $f(z)=\sum\limits_{n=-\infty}^{\infty}c_{n}(z-a)^{n}$ 等号右边的级数则称为**洛朗级数**。
- 证明了洛朗展式的惟一性后，我们就可以采用一些常用的更简便的方法去求一些初等函数在指定圆环内的洛朗展开式 (如例 5.1 至例 5.5)，只有在个别的情况下，才直接采用公式 $\displaystyle c_{n}=\dfrac{1}{2\pi \mathrm{i}}\int_{\Gamma}\dfrac{f(\zeta)}{(\zeta-a)^{n+1}}\,\mathrm{d}\zeta\ (n=0,\pm 1,\pm 2,\cdots)$ 求洛朗系数的方法 (如例 5.6)。
### 5-1-3 洛朗级数与泰勒级数的关系
当已给函数 $f(z)$ 在点 $a$ 处解析时，圆心在 $a$，半径等于由 $a$ 到函数 $f(z)$ 的最近奇点的距离的那个圆可以看成圆环的特殊情形，在其中就可作出洛朗级数展开式。根据柯西积分定理，由公式 $\displaystyle c_{n}=\dfrac{1}{2\pi \mathrm{i}}\int_{\Gamma}\dfrac{f(\zeta)}{(\zeta-a)^{n+1}}\,\mathrm{d}\zeta\ (n=0,\pm 1,\pm 2,\cdots)$ 可以看出，这个展式的所有系数 $c_{-n}\ (n=1,2,\cdots)$ 都等于零。在此情形下，计算洛朗级数的系数公式与泰勒级数的系数公式（积分形式）无异，所以洛朗级数就转化为泰勒级数。因此，泰勒级数是洛朗级数的特殊情形。

- *例 5.1* 
	函数 $f(z)=\dfrac{1}{(z-1)(z-2)}$ 
	在 $z$ 平面上只有两个奇点：$z=1$ 及 $z=2$。因此 $z$ 平面被分成如下三个不相交的 $f(z)$ 的解析区域：
	(1) 圆 $|z|<1$ 
	(2) 圆环 $1<|z|<2$ 
	(3) 圆环：$2<|z|<+\infty$ 
	试分别在此三个区域内求 $f(z)$ 的展式。
	*解* 
	首先将函数 $f(z)$ 分解成部分分式 $f(z) = \dfrac{1}{z-2} - \dfrac{1}{z-1}$ 
	(1) 在圆 $|z|<1$ 内，因 $|z|<1<2$，即 $\left|\dfrac{z}{2}\right|<1$，利用公式 $\dfrac 1{1-u} = \sum\limits_{n=0}^\infty u^n\ (|u|<1)$ 得
	$$f(z)=\frac{1}{1-z}-\frac{1}{2\left(1-\dfrac{z}{2}\right)}=\sum_{n=0}^{\infty}\left(1-\frac{1}{2^{n+1}}\right)z^{n},$$
	此即 $f(z)$ 在圆 $|z|<1$ 内的泰勒展式。
	(2) 在圆环 $1<|z|<2$ 内，即有 $\left|\dfrac{1}{z}\right|<1$，$\left|\dfrac{z}{2}\right|<1$。
	$$\begin{aligned}
	f(z)&=-\frac{1}{2}\cdot\frac{1}{1-\dfrac{z}{2}}-\frac{1}{z}\cdot\frac{1}{1-\dfrac{1}{z}}=-\frac{1}{2}\sum_{n=0}^{\infty}\frac{z^{n}}{2^{n}}-\frac{1}{z}\sum_{n=1}^{\infty}\frac{1}{z^{n-1}}\\
	&=-\sum_{n=0}^{\infty}\frac{z^{n}}{2^{n+1}}-\sum_{n=1}^{\infty}\frac{1}{z^{n}}.
	\end{aligned}$$
	(3) 在圆环 $2<|z|<+\infty$ 内，$\left|\dfrac{1}{z}\right|<1$，$\left|\dfrac{2}{z}\right|<1$，故
	$$\begin{aligned}
	f(z)&=\frac{1}{z}\cdot\frac{1}{1-\dfrac{2}{z}}-\frac{1}{z}\cdot\frac{1}{1-\dfrac{1}{z}}\\
	&=\frac{1}{z}\sum_{n=0}^{\infty}\frac{2^{n}}{z^{n}}-\frac{1}{z}\sum_{n=0}^{\infty}\frac{1}{z^{n}}=\sum_{n=2}^{\infty}\frac{2^{n-1}-1}{z^{n}}.
	\end{aligned}$$
	本例中圆环域的中心 $z=0$ 是各负幂项的奇点，但却不是函数 $f(z)=\dfrac{1}{(z-1)(z-2)}$ 的奇点。
	*说明*：
	(1) 函数 $f(z)$ 在以 $a$ 为中心的圆环域内的洛朗级数中尽管含有 $z-a$ 的负幂项，而且 $a$ 又是这些项的奇点，但是 $a$ 可能是函数 $f(z)$ 的奇点也可能不是 $f(z)$ 的奇点。
	(2) 给定了函数 $f(z)$ 与复平面内的一点 $a$ 以后，函数在各个不同的圆环域中有不同的洛朗展式 (包括泰勒展式作为它的特例)。
### 5-1-4 解析函数在孤立奇点邻域内的洛朗展式
- **孤立奇点**：如果函数 $f(z)$ 在点 $a$ 的某一去心邻域 $K\setminus\{a\}:0<|z-a|<R$ (即除去圆心 $a$ 的某圆) 内解析，点 $a$ 是 $f(z)$ 的奇点，则称 $a$ 为 $f(z)$ 的一个**孤立奇点**。
	- *注*、**单值性孤立奇点**、**多值性孤立奇点** (**支点**)
		因函数 $f(z)$ 在 $K\setminus\{a\}$ 内是单值的，故也称 $a$ 为 $f(z)$ 的**单值性孤立奇点**；
		如以后遇到 $f(z)$ 在 $K\setminus\{a\}$ 内是多值的，则称 $a$ 为 $f(z)$ 的**多值性孤立奇点**，即**支点** (由于在支点的邻域内函数能由一支变到另一支，故函数在支点邻域内缺少单值性。因而它以最简单的方式破坏了函数的解析性。因此支点也是函数的奇点)。
		以后如无特别声明，提到孤立奇点总指单值性孤立奇点。
		当然，以后也会遇到非孤立奇点。
- 如果 $a$ 为函数 $f(z)$ 的一个孤立奇点，则必存在正数 $R$，使得 $f(z)$ 在点 $a$ 的去心邻域 $K\setminus\{a\}:0<|z-a|<R$ 内可展成洛朗级数。常用展开方法：
	(1) **直接展开法** 
	利用洛朗定理的公式计算系数 $c_{n}$：$\displaystyle c_{n}=\frac{1}{2\pi \mathrm{i}}\int_{\Gamma}\frac{f(\zeta)}{(\zeta-a)^{n+1}}\,\mathrm{d}\zeta\ (n=0,\pm 1,\pm 2,\cdots)$ 
	然后写出洛朗展式 $f(z)=\sum\limits_{n=-\infty}^{\infty}c_{n}(z-a)^{n}$。
	缺点：计算往往很麻烦。
	(2) **间接展开法** 
	根据正、负幂项组成的级数的惟一性，可用代数运算、变量代换，并利用已知的泰勒展式去求所需要的洛朗展式。优点：简捷、快速。
- *例 5.2*：求函数 $f(z)=\dfrac{1}{(z-1)(z-3)^{2}}$ 分别在 (1) $0<|z-1|<2$；(2) $2<|z-1|<+\infty$ 内的洛朗展式。
	- *解* 
		(1) 当 $0<|z-1|<2$ 时，$\left|\dfrac{z-1}{2}\right|<1$，故
		$$\frac{1}{z-3}=-\frac{1}{2}\cdot\frac{1}{1-\dfrac{z-1}{2}}=-\frac{1}{2}\sum_{n=0}^{\infty}\left(\frac{z-1}{2}\right)^{n}=-\sum_{n=0}^{\infty}\frac{(z-1)^{n}}{2^{n+1}}.$$
		而
		$$\frac{1}{(z-3)^{2}}=-\left(\frac{1}{z-3}\right)'=\sum_{n=1}^{\infty}\frac{n(z-1)^{n-1}}{2^{n+1}},$$
		所以
		$$\begin{aligned}
		f(z)&=\frac{1}{(z-1)(z-3)^{2}}=\frac{1}{z-1}\sum_{n=1}^{\infty}\frac{n(z-1)^{n-1}}{2^{n+1}}\\
		&=\sum_{n=1}^{\infty}\frac{n(z-1)^{n-2}}{2^{n+1}}.
		\end{aligned}$$
		(2) 当 $2<|z-1|<+\infty$ 时，$\left|\dfrac{2}{z-1}\right|<1$，所以
		$$\frac{1}{z-3}=\frac{1}{z-1}\cdot\frac{1}{1-\dfrac{2}{z-1}}=\sum_{n=0}^{\infty}\frac{2^{n}}{(z-1)^{n+1}}$$
		而
		$$\frac{1}{(z-3)^{2}}=-\left(\frac{1}{z-3}\right)'=\sum_{n=0}^{\infty}\frac{(n+1)2^{n}}{(z-1)^{n+2}},$$
		所以
		$$\begin{aligned}
		f(z)&=\frac{1}{(z-1)(z-3)^{2}}=\frac{1}{z-1}\sum_{n=0}^{\infty}\frac{(n+1)2^{n}}{(z-1)^{n+2}}\\
		&=\sum_{n=0}^{\infty}\frac{(n+1)2^{n}}{(z-1)^{n+3}}.
		\end{aligned}$$
- *例 5.3*：$\dfrac{\sin z}{z}$ 在 $z$ 平面上只有奇点 $z=0$，在其去心邻域 $0<|z|<+\infty$ 内有洛朗展式 $\dfrac{\sin z}{z} = \sum\limits_{n=0}^{\infty} \dfrac{(-1)^{n}z^{2n}}{(2n+1)!} = 1 - \dfrac{z^{2}}{3!} + \cdots$ 
- *例 5.4*：$e^{z}+e^{\frac{1}{z}}$ 在 $z$ 平面上只有奇点 $z=0$，在其去心邻域 $0<|z|<+\infty$ 内有洛朗展式 $e^{z}+e^{\frac{1}{z}} = 2 + \sum\limits_{n=1}^{\infty} \dfrac{z^{n}}{n!} + \sum\limits_{n=1}^{\infty} \dfrac{1}{n!}\cdot \dfrac{1}{z^{n}}$ 
- 由以上各例已可看出，在求一些初等函数的洛朗展式时，一般并不是按照公式 $\displaystyle c_{n}=\dfrac{1}{2\pi \mathrm{i}}\int_{\Gamma}\dfrac{f(\zeta)}{(\zeta-a)^{n+1}}\,\mathrm{d}\zeta\ (n=0,\pm 1,\pm 2,\cdots)$ 去计算洛朗系数，主要是利用已知的幂级数展式去求所需要的洛朗展式。下面我们再举两例。
- *例 5.5*：$\sin\dfrac{z}{z-1}$ 在 $z$ 平面上只有奇点 $z=1$，且在去心邻域 $0<|z-1|<+\infty$ 内可展成洛朗级数。
	- *解* 
		$$
		\begin{aligned}
		\sin\dfrac{z}{z-1} =& \sin\left(1+\dfrac{1}{z-1}\right)=\sin 1\cos\dfrac{1}{z-1}+\cos 1\sin\dfrac{1}{z-1} \\
		=& \sin 1\left[1-\frac{1}{2!(z-1)^{2}}+\cdots+(-1)^{n}\frac{1}{(2n)!(z-1)^{2n}}+\cdots\right]+\\
		&\cos 1\left[\frac{1}{z-1}-\frac{1}{3!(z-1)^{3}}+\cdots+(-1)^{n}\frac{1}{(2n+1)!(z-1)^{2n+1}}+\cdots\right]\\
		=& \sin 1+\frac{\cos 1}{z-1}-\frac{\sin 1}{2!(z-1)^{2}}-\frac{\cos 1}{3!(z-1)^{3}}+\cdots+ \\
		& (-1)^{n}\frac{\sin 1}{(2n)!(z-1)^{2n}}+(-1)^{n}\frac{\cos 1}{(2n+1)!(z-1)^{2n+1}}+\cdots
		\end{aligned}
		$$
- *例 5.6*：试证 $\cosh\left(z + \dfrac{1}{z} \right) = c_{0} + \sum\limits_{n=1}^{\infty} c_{n} (z^{n}+z^{-n})$，其中 $\displaystyle c_{n} = \dfrac{1}{2\pi} \int_{0}^{2\pi}\cos n\varphi\cosh(2\cos\varphi)\,\mathrm{d}\varphi$ 
	- *证*
		因 $w=z+\dfrac{1}{z}$ 在 $z$ 平面上只有 $z=0$ 一个奇点。而 $\cosh w = \dfrac{1}{2}(e^{w}+e^{-w})$ 在 $w$ 平面上解析，故 $\cosh\left(z+\dfrac{1}{z}\right)$ 在 $z$ 平面上也只有一个奇点 $z=0$。即它在去心邻域 $0<|z|<+\infty$ 内解析。
		由洛朗定理得
		$$
		\begin{aligned}
		& \cosh\left(z+\frac{1}{z}\right)=\sum_{n=-\infty}^{\infty}c_{n}z^{n} \\
		& c_{n}=\frac{1}{2\pi\mathrm{i}}\int_{\Gamma_{\rho}}\frac{\cosh(z+z^{-1})}{z^{n+1}}\,\mathrm{d}z
		\end{aligned}
		$$
		$\Gamma_{\rho}$ 表示任意圆周 $|z|=\rho>0$。
		取 $\rho=1$，则沿圆周 $\Gamma_{\rho}:z=e^{\mathrm{i}\varphi},0\leqslant\varphi\leqslant 2\pi$，有
		$$\begin{aligned}
		c_{n}&=\frac{1}{2\pi}\int_{0}^{2\pi}\cosh(e^{\mathrm{i}\varphi}+e^{-\mathrm{i}\varphi})e^{-n\mathrm{i}\varphi}\,\mathrm{d}\varphi\\
		&=\frac{1}{2\pi}\int_{0}^{2\pi}\cosh(2\cos\varphi)\cos n\varphi\,\mathrm{d}\varphi-\frac{\mathrm{i}}{2\pi}\int_{0}^{2\pi}\cosh(2\cos\varphi)\sin n\varphi\,\mathrm{d}\varphi.
		\end{aligned}$$
		命 $\varphi=2\pi-\theta$，则可知等号右边第二个积分为零。故
		$$
		\begin{aligned}
		& c_{n}=\frac{1}{2\pi}\int_{0}^{2\pi}\cosh(2\cos\varphi)\cos n\varphi\,\mathrm{d}\varphi \\
		& c_{n}=c_{-n} \ (n=1,2,\cdots)
		\end{aligned}
		$$
		所以
		$$\cosh\left(z+\frac{1}{z}\right)=c_{0}+\sum_{n=1}^{\infty}c_{n}(z^{n}+z^{-n}).$$
## 5-2 解析函数的孤立奇点
孤立奇点是解析函数的奇点中最简单最重要的一种类型。以解析函数的洛朗展式为工具，我们能够在孤立奇点的去心邻域内充分研究一个解析函数的性质。
### 5-2-1 孤立奇点的三种类型
- **正则部分**、**主要部分** 
	已经说过，如 $a$ 为函数 $f(z)$ 的孤立奇点，则 $f(z)$ 在 $a$ 点的某去心邻域 $K\setminus\{a\}$ 内可以展成洛朗级数 $f(z)=\sum\limits_{n=-\infty}^{\infty}c_{n}(z-a)^{n}$ 
	我们称非负幂部分 $\sum\limits_{n=0}^{\infty}c_{n}(z-a)^{n}$ 为 $f(z)$ 在点 $a$ 的**正则部分**，而称负幂部分 $\sum\limits_{n=1}^{\infty}c_{-n}(z-a)^{-n}$ 为 $f(z)$ 在点 $a$ 的**主要部分**。
	这是因为实际上非负幂部分表示在点 $a$ 的邻域 $K:|z-a|<R$ 内的解析函数，故函数 $f(z)$ 在点 $a$ 的奇异性完全体现在洛朗级数的负幂部分上。
- **可去奇点**、**$m$ 阶极点**、**单极点**、**本质奇点** 
	设 $a$ 为函数 $f(z)$ 的孤立奇点。
	(1) 如果 $f(z)$ 在点 $a$ 的主要部分为零，则称 $a$ 为 $f(z)$ 的可去奇点 (见例 5.3)。
	(2) 如果 $f(z)$ 在点 $a$ 的主要部分为有限多项，设为
	$$\frac{c_{-m}}{(z-a)^{m}}+\frac{c_{-(m-1)}}{(z-a)^{m-1}}+\cdots+\frac{c_{-1}}{z-a}\quad(c_{-m}\neq 0),$$
	则称 $a$ 为 $f(z)$ 的 **$m$ 阶极点** (见例 5.2)。一阶极点也称为**单极点**。
	(3) 如果 $f(z)$ 在点 $a$ 的主要部分有无限多项，则称 $a$ 为 $f(z)$ 的**本质奇点** (见例 5.4 及例 5.5)。

以下我们分别讨论三类孤立奇点的特征。
### 5-2-2 可去奇点
- *可去奇点的由来* 
	如果 $a$ 为函数 $f(z)$ 的可去奇点，则有 $f(z)=c_{0}+c_{1}(z-a)+c_{2}(z-a)^{2}+\cdots\ (0<|z-a|<R)$，上式等号右边表示圆 $K:|z-a|<R$ 内的解析函数。
	如果命 $f(a)=c_{0}$，则 $f(z)$ 在圆 $K$ 内与一个解析函数重合。也就是说，我们将 $f(z)$ 在点 $a$ 的值加以适当定义，则点 $a$ 就是 $f(z)$ 的解析点。这就是我们称 $a$ 为 $f(z)$ 的可去奇点的由来。
	例如，当我们约定 $\left.\dfrac{\sin z}{z}\right|_{z=0}=1$ 时，$\dfrac{\sin z}{z}$ 在 $z=0$ 就解析了。
- **定理 5.3** 
	如果 $a$ 为函数 $f(z)$ 的孤立奇点，则下列三条是等价的。因此，它们中的任何一条都是可去奇点的特征。
	(1) $f(z)$ 在点 $a$ 的主要部分为零。
	(2) $\lim\limits_{z\to a}f(z)=b\,(\neq\infty)$。
	(3) $f(z)$ 在点 $a$ 的某去心邻域内有界。
	- *证明过程* 
		只要证明 (1) 推出 (2)，(2) 推出 (3)，(3) 推出 (1) 就行了。
		*(1) 推出 (2)* 
		由 (1) 知 $f(z)=c_{0}+c_{1}(z-a)+c_{2}(z-a)^{2}+\cdots\ (0<|z-a|<R)$，于是 $\lim\limits_{z\to a} f(z) = c_{0}\, (\neq\infty)$ 
		*(2) 推出 (3)*：即例 1.31。
		*(3) 推出 (1)* 
		设 $f(z)$ 在点 $a$ 的某去心邻域 $K\setminus\{a\}$ 内以 $M$ 为界。考虑 $f(z)$ 在点 $a$ 的主要部分 $\dfrac{c_{-1}}{z-a} + \dfrac{c_{-2}}{(z-a)^{2}} + \cdots + \dfrac{c_{-n}}{(z-a)^{n}} + \cdots$，$\displaystyle c_{-n}=\frac{1}{2\pi\mathrm{i}}\int_{\Gamma}\frac{f(\zeta)}{(\zeta-a)^{-n+1}}\,\mathrm{d}\zeta\quad(n=1,2,3,\cdots)$ 
		而 $\Gamma$ 为全含于 $K$ 内的圆周 $|\zeta-a|=\rho$，$\rho$ 可以充分小。于是由
		$$\begin{aligned}|c_{-n}|&=\left|\frac{1}{2\pi\mathrm{i}}\int_{\Gamma}\frac{f(\zeta)}{(\zeta-a)^{-n+1}}\,\mathrm{d}\zeta\right|\\&\leqslant\frac{1}{2\pi}\cdot\frac{M}{\rho^{-n+1}}2\pi\rho=M\rho^{n}\end{aligned}$$
		即知当 $n=1,2,\cdots$ 时，$c_{-n}=0$。即是说，$f(z)$ 在点 $a$ 的主要部分为零。
- *例 5.7*：说明 $z=0$ 为 $\dfrac{e^{z}-1}{z}$ 的可去奇点。
	- *解* 
		$$\begin{aligned}\frac{e^{z}-1}{z}&=\frac{1}{z}\left(1+z+\frac{1}{2!}z^{2}+\cdots+\frac{1}{n!}z^{n}+\cdots-1\right)\\&=1+\frac{1}{2!}z+\cdots+\frac{1}{n!}z^{n-1}+\cdots,\quad 0<|z|<+\infty\end{aligned}$$
		无负幂项 (主要部分为零)。所以 $z=0$ 为 $\dfrac{e^{z}-1}{z}$ 的可去奇点。
		另解：因为 $\lim\limits_{z\to 0}\dfrac{e^{z}-1}{z}=\lim\limits_{z\to 0}e^{z}=1$，所以 $z=0$ 为 $\dfrac{e^{z}-1}{z}$ 的可去奇点。
### 5-2-3 施瓦茨 (Schwarz) 引理
- *施瓦茨 (Schwarz) 引理* 
	如果函数 $f(z)$ 在单位圆 $|z|<1$ 内解析，并且满足条件 $f(0)=0,\ |f(z)|<1\ (|z|<1)$，则在单位圆 $|z|<1$ 内恒有 $|f(z)|\leqslant|z|$ 且有 $|f'(0)|\leqslant 1$ 
	如果上式等号成立，或在圆 $|z|<1$ 内一点 $z_{0}\neq 0$ 处前一式等号成立，则 (当且仅当) $f(z)=\mathrm{e}^{\mathrm{i}\alpha}z\ (|z|<1)$，其中 $\alpha$ 为一实常数。
	- *证明过程* 
		设 $f(z)=c_{1}z+c_{2}z^{2}+\cdots\ (|z|<1)$，令 $\varphi(z) = \dfrac{f(z)}{z}=c_{1}+c_{2}z+\cdots\ (z\neq 0)$ 
		定义 $\varphi(0)=c_{1}=f'(0)$，则 $\varphi(z)$ 在 $|z|<1$ 内解析。
		考虑 $\varphi(z)$ 在单位圆 $|z|<1$ 内任一点 $z_{0}$ 处的值，如果 $r$ 满足条件 $|z_{0}|<r<1$，根据最大模原理，有 $|\varphi(z_{0})| \leqslant \max\limits_{|z|=r} |\varphi(z)| = \max\limits_{|z|=r} \left| \dfrac{f(z)}{z} \right| \leqslant \dfrac{1}{r}$ 
		令 $r\to 1$ 即得 $|\varphi(z_{0})|\leqslant 1$，于是 $|f'(0)|=|\varphi(0)|\leqslant 1$，且当 $z_{0}\neq 0$ 时，有 $|\varphi(z_{0})| = \left| \dfrac{f(z_{0})}{z_{0}}\right|\leqslant 1$，即 $|f(z_{0})|\leqslant|z_{0}|$ 
		如果这些关系式中，有一个取等号，这就意味着在单位圆 $|z|<1$ 内的某一点 $z_{0}$，模数 $|\varphi(z)|$ 达到最大值，这只有 $\varphi(z)\equiv$ 常数 $\mathrm{e}^{\mathrm{i}\alpha}$ ($\alpha$ 为实数) 时才可能，此即 $f(z)\equiv\mathrm{e}^{\mathrm{i}\alpha}z$ 
	- 从几何上看，施瓦茨引理表明：任一解析变换 $w=f(z)$，$f(0)=0$，当它把单位圆变到一个单位圆内的区域 $\Delta$ 上去时，圆内任一点 $z\neq 0$ 的像都比 $z$ 本身距坐标原点为近。而如果有一个点的像与这个点本身距坐标原点有相同距离的话，则 $\Delta$ 就与单位圆相同，变换就仅仅是一个旋转 (图 5.2)。
		![[Pasted image 20260902115920.png|375]]
	- *注*：施瓦茨引理有如下一个简单改进：
		我们保留假设条件不变。如果原点是函数 $f(z)$ 的 $\lambda$ 阶零点，就可以考虑函数 $\dfrac{f(z)}{z^{\lambda}}$，与刚才的情形一样，我们由此可以得到 $|f(z)|\leqslant|z|^{\lambda}$，并且只有当 $f(z)=\mathrm{e}^{\mathrm{i}\alpha}z^{\lambda}\ (\alpha\text{ 为实数})$ 时，等号才成立。
		这样，在这个特殊情形之下，函数的模就有了一个比前面公式中更小的界限。
### 5-2-4 极点
- **定理 5.4**：
	如果函数 $f(z)$ 以点 $a$ 为孤立奇点，则下列三条是等价的。因此，它们中的任何一条都是 $m$ 阶极点的特征。
	(1) $f(z)$ 在点 $a$ 的主要部分为 $\dfrac{c_{-m}}{(z-a)^{m}} + \cdots + \dfrac{c_{-1}}{z-a}\ (c_{-m}\neq 0)$ 
	(2) $f(z)$ 在点 $a$ 的某去心邻域内能表示成 $f(z) = \dfrac{\lambda(z)}{(z-a)^{m}}$，其中 $\lambda(z)$ 在点 $a$ 的邻域内解析，且 $\lambda(a)\neq 0$。
	(3) $g(z)=\dfrac{1}{f(z)}$ 以点 $a$ 为 $m$ 阶零点 (可去奇点要当作解析点看，只要令 $g(a)=0$)。
	*注*：(3) 表明：$f(z)$ 以点 $a$ 为 $m$ 阶极点 $\iff$ $\dfrac{1}{f(z)}$ 以点 $a$ 为 $m$ 阶零点
	- *证明过程* 
		*(1) 推出 (2)* 
		若 (1) 为真，则在点 $a$ 的某去心邻域内有
		$$\begin{aligned}f(z)&=\frac{c_{-m}}{(z-a)^{m}}+\frac{c_{-(m-1)}}{(z-a)^{m-1}}+\cdots+\frac{c_{-1}}{z-a}+c_{0}+c_{1}(z-a)+\cdots\\&=\frac{c_{-m}+c_{-(m-1)}(z-a)+\cdots}{(z-a)^{m}}=\frac{\lambda(z)}{(z-a)^{m}},\end{aligned}$$
		其中 $\lambda(z)$ 显然在点 $a$ 的邻域内解析，且 $\lambda(a)=c_{-m}\neq 0$。
		*(2) 推出 (3)* 
		若（2）为真，则在点 $a$ 的某去心邻域内有 $g(z) = \dfrac{1}{f(z)} = \dfrac{(z-a)^{m}}{\lambda(z)}$，其中 $\dfrac{1}{\lambda(z)}$ 在点 $a$ 的某邻域内解析，且 $\dfrac{1}{\lambda(a)}\neq 0$ (由例 1.32)。
		因此，$a$ 为 $g(z)$ 的可去奇点，作为解析点来看，只要令 $g(a)=0$，$a$ 就为 $g(z)$ 的 $m$ 阶零点。
		*(3) 推出 (1)* 
		如果 $g(z)=\dfrac{1}{f(z)}$ 以点 $a$ 为 $m$ 阶零点，则在点 $a$ 的某邻域内 $g(z)=(z-a)^{m}\varphi(z)$，其中 $\varphi(z)$ 在此邻域内解析，且 $\varphi(a)\neq 0$。这样一来，$f(z)=\dfrac{1}{(z-a)^{m}} \cdot \dfrac{1}{\varphi(z)}$。
		因 $\dfrac{1}{\varphi(z)}$ 在点 $a$ 的某邻域内解析 (由例 1.32)，如在此邻域内令 $\dfrac{1}{\varphi(z)}=c_{-m}+c_{-(m-1)}(z-a)+\cdots$ 为其泰勒展式，则 $f(z)$ 在点 $a$ 的主要部分就是
		$$\frac{c_{-m}}{(z-a)^{m}}+\frac{c_{-(m-1)}}{(z-a)^{m-1}}+\cdots+\frac{c_{-1}}{z-a}\ \left(c_{-m}=\frac{1}{\varphi(a)}\neq 0\right).$$
- **定理 5.5** 函数 $f(z)$ 的孤立奇点 $a$ 为极点的充要条件是 $\lim\limits_{z\to a}f(z)=\infty$ 
	- *证明过程* 
		函数 $f(z)$ 以 $a$ 为极点的充要条件是 $\dfrac{1}{f(z)}$ 以 $a$ 为零点 (定理 5.4 (3))，由此知定理为真。
	- 该定理也能说明极点的特征，其缺点是不能指明极点的阶。
- *例 5.8*：函数 $f(z) = \dfrac{5z+1}{(z-1)(2z+1)^{2}}$ 以 $z=1$ 为一阶极点，$z=-\dfrac{1}{2}$ 为二阶极点 (由定理 5.4 (3))。
- *例 5.9*：函数 $\dfrac{1}{\sin z}$ 有哪些奇点？如果它是极点，指出其阶。
	- *解* 
		函数的奇点是使 $\sin z=0$ 的点，这些奇点是 $z=k\pi\ (k=0,\pm 1,\pm 2,\cdots)$，是孤立奇点。因为 $(\sin z)'|_{z=k\pi}=\cos z|_{z=k\pi}=(-1)^{k}\neq 0$，所以 $z=k\pi$ 是 $\sin z$ 的一阶零点，即 $\dfrac{1}{\sin z}$ 的一阶极点。
### 5-2-5 本质奇点
- **定理 5.6**：函数 $f(z)$ 的孤立奇点 $a$ 为本质奇点的充要条件是 $\lim\limits_{z\to a} f(z) \neq \begin{cases}b\text{(有限数)},\\\infty,\end{cases}\text{ 即 }\lim\limits_{z\to a} f(z) \text{不存在}$ 
	- *证明过程* 
		这可由定理 5.3 (2) 及定理 5.5 得到证明。
- **定理 5.7**：若 $z=a$ 为函数 $f(z)$ 的一本质奇点，且在点 $a$ 的充分小去心邻域内不为零，则 $z=a$ 亦必为 $\dfrac{1}{f(z)}$ 的本质奇点。
	- *证明过程* 
		令 $\varphi(z)=\dfrac{1}{f(z)}$。由假设，$z=a$ 必为 $\varphi(z)$ 的孤立奇点。
		若 $z=a$ 为 $\varphi(z)$ 的可去奇点 (解析点)，则 $z=a$ 必为 $f(z)$ 的可去奇点或极点，此与假设矛盾；
		若 $z=a$ 为 $\varphi(z)$ 的极点，则 $z=a$ 必为 $f(z)$ 的可去奇点 (零点)，亦与假设矛盾。
		故 $z=a$ 必为 $\varphi(z)$ 的本质奇点。
- *例 5.10* 
	$z=0$ 为 $\mathrm{e}^{\frac{1}{z}}$ 的本质奇点，因为
	$$\mathrm{e}^{\frac{1}{z}}=1+\frac{1}{z}+\frac{1}{2!z^{2}}+\cdots+\frac{1}{n!z^{n}}+\cdots\ (0<|z|<+\infty).$$ 由定理 5.7，我们可以断定 $z=0$ 亦为 $\mathrm{e}^{-\frac{1}{z}}$ 的本质奇点。在上式中将 $z$ 改为 $-z$，也可看出这一点。
- *注*：就本书所遇到的奇点情况来看，可以列表如下：
	![[Pasted image 20260902121402.png|300]]
### 5-2-6 皮卡 (Picard) 定理
- **定理 5.8**：如果 $a$ 为函数 $f(z)$ 的本质奇点，则对于任何常数 $A$，不管它是有限数还是无穷，都有一个收敛于 $a$ 的点列 $\{z_{n}\}$，使得 $\lim\limits_{z_{n}\to a}f(z_{n})=A$ 
	- 魏尔斯特拉斯 1876 年给出该定理，描述出解析函数在本质奇点邻域内的特性。
	- 换句话说，在本质奇点的无论怎样小的去心邻域内，函数 $f(z)$ 可以取任意接近于预先给定的任何数值 (有限的或无穷的)。
	- *证明过程* 
		(1) 在 $A=\infty$ 的情形，定理是正确的。因为函数 $f(z)$ 的模在 $a$ 的任何去心邻域内都是无界的。否则，$a$ 必为 $f(z)$ 的可去奇点。
		(2) 现在设 $A\neq\infty$。
		可能有这种情形发生，在点 $a$ 的任意小的去心邻域内有这样一点 $z$ 存在，使 $f(z)=A$。在这种情形下，定理已经得证。
		因此，我们可以假定，在点 $a$ 的充分小的去心邻域 $K\setminus\{a\}$ 内 $f(z)\neq A$。这样，由定理 5.7，函数 $\varphi(z) = \dfrac{1}{f(z)-A}$ 在 $K\setminus\{a\}$ 内解析，且以 $a$ 为本质奇点 (因 $a$ 为 $f(z)$ 的本质奇点)。
		根据前面 (1) 段的结果，必定有一个趋向 $a$ 的点列 $\{z_{n}\}$ 存在，使得 $\lim\limits_{z_{n}\to a}\varphi(z_{n})=\infty$，由此推出 $\lim\limits_{z_{n}\to a}f(z_{n})=A$
	- *思考题*：试描述这个魏尔斯特拉斯定理的几何意义。
	- 我们用两个例子来说明这个定理。
- *例 5.11* 
	对于 $f(z)=\sin\dfrac{1}{z}$，这里原点是 $f(z)$ 的本质奇点。
	事实上，当 $z\to 0$ 时，$\sin\dfrac{1}{z}$ 不趋于任何 (有限的或无穷的) 极限。只要考察 $z$ 取实数值就可以发现这一点。
	如果 $A=\infty$，则可设 $z_{n}=\dfrac{\mathrm{i}}{n}$，即 $\dfrac{1}{z_{n}}=-\mathrm{i}n$，我们得：$n\to\infty$ 时 $\sin\dfrac{1}{z_{n}}=-\mathrm{i}\sinh n\to\infty$ 
	现在设 $A\neq\infty$。为了得到如魏尔斯特拉斯定理中所说的点列 $\{z_{n}\}$，我们解方程 $\sin \dfrac{1}{z}=A$ 得 $\dfrac{1}{z} = \arcsin A = \dfrac{1}{\mathrm{i}}\operatorname{Ln} (\mathrm{i}A+\sqrt{1-A^{2}})$，于是 $z_{k} = \dfrac{\mathrm{i}}{\ln(\mathrm{i}A+\sqrt{1-A^{2}})+2k\pi\mathrm{i}}\ (k=0,\pm 1,\pm 2,\cdots)$ 
	若取 $z_{n} = \dfrac{\mathrm{i}}{\ln(\mathrm{i}A+\sqrt{1-A^{2}}) + 2n\pi\mathrm{i}}$，并使 $n=1,2,\cdots$，我们得到点列 $z_{n}\to 0$，并满足条件 $f(z_{n})=A\ (n=1,2,\cdots)$ 
	因此 $\lim\limits_{n\to\infty}f(z_{n})=A$ 
- *思考题*：$z=0$ 是否为 $\dfrac{1}{\sin\dfrac{1}{z}}$ 的本质奇点？
- *例 5.12* 
	$f(z)=\mathrm{e}^{\frac{1}{z}}$ 
	这里，原点是 $f(z)$ 的本质奇点 (见例 5.10)。
	设 $A=\infty$，取 $z_{n}=\dfrac{1}{n}$，我们有 $f(z_{n})=\mathrm{e}^{n}\to\infty\ (\text{当 }n\to\infty\text{时})$ 
	就是说，当 $A=\infty$ 时，点列 $\left\{\dfrac{1}{n}\right\}$ 适合魏尔斯特拉斯定理中的论断。
	现在设 $A=0$，若令 $z_{n}=-\dfrac{1}{n}$，我们有 $f(z_{n})=\mathrm{e}^{-n}\to 0\ (\text{当 }n\to\infty\text{时})$，就是说，定理的论断在此情形也得到证实。
	最后，设 $A\neq 0,A\neq\infty$。这里极易由解方程 $\mathrm{e}^{\frac{1}{z}}=A$ 来取相应的点 $z_{n}$。我们得 $\dfrac{1}{z}=\operatorname{Ln}A$，于是 $z_{k}=\dfrac{1}{\ln A+2k\pi\mathrm{i}}\ (k=0,\pm 1,\pm 2,\cdots)$ 
	若取 $z_{n} = \dfrac{1}{\ln A+2n\pi\mathrm{i}}\ (n=1,2,\cdots)$，我们就有收敛于零且满足条件 $f(z_{n})=A$ 的点列 $\{z_{n}\}$。于是 $\lim\limits_{n\to\infty}f(z_{n})=A$ 
- 在例 5.11 与例 5.12 中，我们看到，除了个别的例外 (前例中的 $A=\infty$，后例中的 $A=\infty$，$A=0$)，不但有点列 $\{z_{n}\}$ 满足极限等式 $\lim\limits_{z_{n}\to a}f(z_{n})=A$，而且还有点列 $\{z_{n}\}$ 满足准确等式 $f(z_{n})=A\ (n=1,2,\cdots)$。在一般情况下，也有类似的结果。下面的定理是皮卡于 1879 年给出的。
- **定理 5.9** (**皮卡 (大) 定理**)：如果 $a$ 为函数 $f(z)$ 的本质奇点，则对于每一个 $A\neq\infty$，除掉可能一个值 $A=A_{0}$ 外，必有趋于 $a$ 的无限点列 $\{z_{n}\}$，使 $f(z_{n})=A\ (n=1,2,\cdots)$。
	- 必须指出，皮卡定理较之魏尔斯特拉斯定理更普遍并且更深刻。但它只是函数值分布理论的早期结果之一。
	- 皮卡证明的方法虽然很短，但却利用了一种称为椭圆模函数的性质这种较高深的数学工具。后人虽有多种浅近的证明方法，但都非常繁复。本书限于篇幅，不加证明。
	- 从皮卡定理出发，近代在这个方面还有许多深刻的研究，这些都是属于解析函数的值的分布理论范围，这里就不深入讨论了。
## 5-3 解析函数在无穷远点的性质
- 上一节讨论的是函数的孤立奇点为有限的情形。由于函数 $f(z)$ 在点 $\infty$ 总是无意义的，所以点 $\infty$ 总是 $f(z)$ 的奇点。
- **孤立奇点**：设函数 $f(z)$ 在无穷远点的（去心）邻域 $N\setminus\{\infty\}:+\infty>|z|>r\geqslant 0$ 内解析，则称点 $\infty$ 为 $f(z)$ 的一个**孤立奇点**。
- *孤立奇点的一些性质* 
	设点 $\infty$ 为 $f(z)$ 的孤立奇点，利用变换 $z'=\dfrac{1}{z}$，于是 $\varphi(z') = f \left( \dfrac{1}{z'}\right)=f(z)$ 在去心邻域 $K\setminus\{0\}:0<|z'|<\dfrac{1}{r}$ (如 $r=0$，规定 $\dfrac{1}{r}=+\infty$) 内解析。$z'=0$ 就为 $\varphi(z')$ 的一孤立奇点。
	我们还看出：
	(1) 对应于扩充 $z$ 平面上无穷远点的去心邻域 $N\setminus\{\infty\}$，有扩充 $z'$ 平面上原点的去心邻域。
	(2) 在对应的点 $z$ 与 $z'$ 上，函数 $f(z)$ 与 $\varphi(z')$ 的值相等。
	(3) $\lim\limits_{z\to\infty}f(z)=\lim\limits_{z'\to 0}\varphi(z')$，或两个极限都不存在。
	从这里，我们很自然地根据 $\varphi(z')$ 在原点的状态来规定函数 $f(z)$ 在无穷远点的状态。见下面定义。
- **可去奇点** (**解析点**)、**$m$ 阶极点**、**本质奇点**：若 $z'=0$ 为 $\varphi(z')$ 的可去奇点 (解析点)、$m$ 阶极点或本质奇点，则我们相应地称 $z=\infty$ 为 $f(z)$ 的可去奇点 (解析点)、$m$ 阶极点或**本质奇点**。
	- *注*：虽然我们可以定义 $f(\infty)$，但在无穷远点处没有定义差商，因此我们没有定义 $f(z)$ 在无穷远点处的可微性。但由上面定义可见，所谓 $f(z)$ 在点 $\infty$ 解析，就是指点 $\infty$ 为 $f(z)$ 的可去奇点，且定义 $f(\infty)=\lim\limits_{z\to\infty}f(z)$。

设在去心邻域 $K\setminus\{0\}:0<|z'|<\dfrac{1}{r}$ 内将 $\varphi(z')$ 展成洛朗级数：$\varphi(z') = \sum\limits_{n=-\infty}^{\infty}c_{n}z'^{n}$ 
令 $z'=\dfrac{1}{z}$，并根据 $\varphi(z') = f \left( \dfrac{1}{z'}\right)=f(z)$，则有 $f(z) = \sum\limits_{n=-\infty}^{\infty}b_{n}z^{n}$，其中 $b_{n}=c_{-n}\ (n=0,\pm 1,\pm 2,\cdots)$。

$f(z) = \sum\limits_{n=-\infty}^{\infty}b_{n}z^{n}$ 为 $f(z)$ 在无穷远点的去心邻域 $N\setminus\{\infty\}:0\leqslant r<|z|<+\infty$ 内的洛朗展式。
对应 $\varphi(z')$ 在 $z'=0$ 的主要部分，我们称 $\sum\limits_{n=1}^{\infty}b_{n}z^{n}$ 为 $f(z)$ 在 $z=\infty$ 的主要部分。
*注*：我们来观察这样一个特例：设函数 $f(z)$ 在 $\mathbf{C}_{\infty}$ 上只有奇点 $z=0$ 和 $z=\infty$，则可设
$$f(z)=a_{0}+\frac{a_{1}}{z}+\cdots+\frac{a_{n}}{z^{n}}+\cdots+b_{1}z+b_{2}z^{2}+\cdots+b_{n}z^{n}+\cdots\quad(0<|z|<+\infty),$$
这样就把函数 $f(z)-a_{0}$ 一分为二：$\sum\limits_{n=1}^{\infty}\dfrac{a_{n}}{z^{n}}$ 及 $\sum\limits_{n=1}^{\infty}b_{n}z^{n}$。在 $z=0$ 的去心邻域 $0<|z|<+\infty$ 内，前者是主要部分，起主导作用，$f(z)$ 的性质主要由前者所规定，而后者则是次要的。
但是当 $|z|$ 逐渐变大，趋向 $+\infty$ 时，主要部分和非主要部分就互相转化。在 $z=\infty$ 的去心邻域 $0<|z|<+\infty$ 内，后者是主要部分，起主导作用，决定 $f(z)$ 的性质，而前者却变为次要的。
由上述定义及性质 (1)，(2)，(3) 等，我们易得

- **定理 5.3'** (**对应于定理 5.3**)：函数 $f(z)$ 的孤立奇点 $z=\infty$ 为可去奇点的充要条件是下列三条中的任何一条成立：
	(1) $f(z)$ 在 $z=\infty$ 的主要部分为零。
	(2) $\lim\limits_{z\to\infty}f(z)=b\ (\neq\infty)$。
	(3) $f(z)$ 在 $z=\infty$ 的某去心邻域 $N\setminus\{\infty\}$ 内有界。
- **定理 5.4'** (**对应于定理 5.4**)：函数 $f(z)$ 的孤立奇点 $z=\infty$ 为 $m$ 阶极点的充要条件是下列三条中的任何一条成立：
	(1) $f(z)$ 在 $z=\infty$ 的主要部分为 $b_{1}z+b_{2}z^{2}+\cdots+b_{m}z^{m}\ (b_{m}\neq 0)$ 
	(2) $f(z)$ 在 $z=\infty$ 的某去心邻域 $N\setminus\{\infty\}$ 内能表示成 $f(z)=z^{m}\mu(z)$，其中 $\mu(z)$ 在 $z=\infty$ 的邻域 $N$ 内解析，且 $\mu(\infty)\neq 0$。
	(3) $g(z)=\dfrac{1}{f(z)}$ 以 $z=\infty$ 为 $m$ 阶零点 (只要令 $g(\infty)=0$)。
- *例 5.13* 
	由 $f(z)=\dfrac{1}{(z-1)(z-2)}$ 在 $2<|z|<+\infty$ 内的洛朗展式 (见例 5.1(3))，知它以 $z=\infty$ 为可去奇点，并且作为解析点来看是二阶零点 (只要让 $f(\infty)=0$)。
	又 $g(z) = \dfrac{1}{f(z)}=(z-1)(z-2)=z^{2}\left(1 - \dfrac{1}{z}\right) \left(1-\dfrac{2}{z} \right)$ 以 $z=\infty$ 为二阶极点。
	这里 $\mu(z)=\left(1-\dfrac{1}{z}\right) \left(1-\dfrac{2}{z}\right),\ \mu(\infty)=1\neq 0$ 
- **定理 5.5'** (**对应于定理 5.5**)：函数 $f(z)$ 的孤立奇点 $\infty$ 为极点的充要条件是 $\lim\limits_{z\to\infty}f(z)=\infty$ 
- **定理 5.6'** (**对应于定理 5.6**)：函数 $f(z)$ 的孤立奇点 $\infty$ 为本质奇点的充要条件是下列两条中的任何一条成立：
	(1) $f(z)$ 在 $z=\infty$ 的主要部分有无穷多项正幂不等于零。
	(2) $\lim\limits_{z\to\infty}f(z)$ 不存在 (即当 $z$ 趋向于 $\infty$ 时，$f(z)$ 不趋向于任何 (有限或无穷) 极限)。
	- *注*：定理 5.7，定理 5.8 及定理 5.9 对 $z=\infty$ 是 $f(z)$ 的本质奇点也真。
- *例 5.14*：函数 $f(z)=\dfrac{(z^{2}-1)(z-2)^{3}}{(\sin\pi z)^{3}}$ 在扩充复平面内有些什么类型的奇点？若是极点，指出其阶。
	- *解* 
		分母的零点为函数的奇点，而 $\sin\pi z$ 的零点为
		$$
		\begin{aligned}
		& z=n\quad (n=0,\pm 1,\pm 2,\cdots) \\
		& (\sin\pi z)'|_{z=n}=\pi\cos n\pi=(-1)^{n}\pi\neq 0
		\end{aligned}
		$$
		所以这些点都是 $\sin\pi z$ 的一阶零点，故这些点中除 $-1,1,2$ 外，都是 $f(z)$ 的三阶极点。因 $z^{2}-1=(z-1)(z+1)$ 以 $1$ 与 $-1$ 为一阶零点，所以 $1$ 与 $-1$ 是 $f(z)$ 的二阶极点。
		当 $z=2$ 时，因为
		$$\lim_{z\to 2}f(z)=\lim_{z\to 2}\frac{(z^{2}-1)(z-2)^{3}}{(\sin\pi z)^{3}}=\frac{3}{\pi^{3}},$$
		于是 $z=2$ 是 $f(z)$ 的可去奇点。
		当 $z=\infty$ 时，设 $t=\dfrac{1}{z}$，$f\left(\dfrac{1}{t}\right)=\dfrac{(1-t^{2})(1-2t)^{3}}{t^{5}\sin^{3}\dfrac{\pi}{t}}$，$t=0$，$t_{n}=\dfrac{1}{n}$ 使分母为零，$t_{n}=\dfrac{1}{n}$ 为 $f\left(\dfrac{1}{t}\right)$ 的极点，当 $n\to\infty$ 时，$t_{n}=\dfrac{1}{n}\to 0$，故 $t=0$ 不是 $f(z)$ 的孤立奇点，所以 $z=\infty$ 不是 $f(z)$ 的孤立奇点 (不能展成洛朗级数)。
- 下面我们再举几个其他类型的例子。
- *例 5.15*：将多值解析函数 $\operatorname{Ln}\dfrac{z-a}{z-b}$ 的各分支在无穷远点的某去心邻域内展成洛朗级数。
	- *解* 
		无穷远点不是 $\operatorname{Ln}\dfrac{z-a}{z-b}$ 的支点，故能在点 $\infty$ 的邻域 $|z|>\max\{|a|,|b|\}$ 内分出单值解析分支。且在此去心邻域内，各支均能展成洛朗级数。
		现在第 $k$ 支 $\ln \dfrac{z-a}{z-b}=\ln\frac{1-\dfrac{a}{z}}{1-\dfrac{b}{z}} = \ln\left(1-\dfrac{a}{z}\right) - \ln\left(1-\dfrac{b}{z}\right) + 2k \pi \mathrm{i}$，其中 $\ln\left(1-\dfrac{a}{z}\right)$ 及 $\ln\left(1-\dfrac{b}{z}\right)$ 均表示主值支。
		由 $[\ln(1+z)]_0 = z - \dfrac{z^2}{2} + \dfrac{z^3}{3} - \cdots + (-1)^{n-1}\dfrac{z^n}n + \cdots\ (|z| < 1)$ 即得
		$$\begin{aligned}
		\ln\frac{z-a}{z-b}&=2k\pi\mathrm{i}-\sum_{n=1}^{\infty}\frac{1}{n}\left(\frac{a}{z}\right)^{n}+\sum_{n=1}^{\infty}\frac{1}{n}\left(\frac{b}{z}\right)^{n} \\
		&=2k\pi\mathrm{i}+\sum_{n=1}^{\infty}\frac{b^{n}-a^{n}}{n}\cdot\frac{1}{z^{n}}\quad(k=0,\pm 1,\pm 2,\cdots).
		\end{aligned}$$
		由此可见，$z=\infty$ 实为各单值解析分支的单值性孤立奇点——可去奇点。
- *例 5.16*：在点 $z=\infty$ 的去心邻域内将函数 $f(z)=\mathrm{e}^{\frac{z}{z+2}}$ 展成洛朗级数。
	- *解* 
		令 $z=\dfrac{1}{\zeta}$，则得 $f\left(\frac{1}{\zeta}\right)=\mathrm{e}^{\frac{\frac{1}{\zeta}}{\frac{1}{\zeta}+2}}=\mathrm{e}^{\frac{1}{1+2\zeta}}$ 
		而点 $\zeta=0$ 是此函数的解析点。将此函数简记为 $\varphi(\zeta)$，就得
		$$
		\begin{aligned}
		& \varphi'(\zeta)=-\frac{2}{(1+2\zeta)^{2}}\mathrm{e}^{\frac{1}{1+2\zeta}} \\
		& \varphi''(\zeta)=\mathrm{e}^{\frac{1}{1+2\zeta}}\left[\frac{8}{(1+2\zeta)^{3}}+\frac{4}{(1+2\zeta)^{4}}\right]
		\end{aligned}
		$$
		等等。于是 $\varphi(0)=\mathrm{e}$，$\varphi'(0)=-2\mathrm{e}$，$\varphi''(0)=12\mathrm{e}$，等等。
		由此得 $\varphi(\zeta)=\mathrm{e}(1-2\zeta+6\zeta^{2}+\cdots)$，所以 $\mathrm{e}^{\frac{z}{z+2}} = \mathrm{e}\left(1 - \dfrac{2}{z} + \dfrac{6}{z^{2}} + \cdots \right) \ (2<|z|<+\infty)$ 
		这里 $z=\infty$ 是 $f(z)$ 的可去奇点，如令 $f(\infty)=\mathrm{e}$，则化为解析点。
- *例 5.17*：求出函数 $\dfrac{\tan(z-1)}{z-1}$ 的奇点 (包括无穷远点)，并确定其类别。
	- *解* 
		$\dfrac{\tan(z-1)}{z-1} = \dfrac{\sin(z-1)}{(z-1)\cos(z-1)}$ 以 $z=1$ 为可去奇点；
		$z_{k}=1+\dfrac{2k+1}{2}\pi$，$k=0,\pm 1,\pm 2,\cdots$ 为一阶极点；
		$z=\infty$ 为这些极点的聚点，是个非孤立奇点。
- *例 5.18* 问函数 $\sec\dfrac{1}{z-1}$ 在 $z=1$ 的去心邻域内能否展成洛朗级数？
	- *解* 
		因 $z=1$ 为函数 $\sec\dfrac{1}{z-1}=\dfrac{1}{\cos\dfrac{1}{z-1}}$ 的非孤立奇点 (注意：$\sec\dfrac{1}{z-1}$ 的奇点除 $z=1$ 外，还有奇点 $z_{k} = \dfrac{1}{\left(k+\dfrac{1}{2}\right)\pi}+1,\ k=0,\pm 1,\pm 2,\cdots$ 以 $z=1$ 为聚点）。故此函数在 $z=1$ 的去心邻域内不能展开为洛朗级数。
- *例 5.19*：若函数 $f(z)$ 在 $0<|z-a|<R$ 内解析，且不恒为零；又若 $f(z)$ 有一列异于 $a$ 但却以 $a$ 为聚点的零点。试证 $a$ 必为 $f(z)$ 的本质奇点。
	- *证* 
		$z=a$ 必是 $f(z)$ 的孤立奇点且不能是可去奇点。否则 $f(z)$ 于 $|z-a|<R$ 内解析（令 $f(a)=0$）且以 $a$ 为非孤立的零点。由推论 4.20 必有 $f(z)$ 恒为零，这与假设矛盾。
		其次，$z=a$ 也不能是 $f(z)$ 的极点。否则，对任给 $M>0$，有 $\delta>0$，使当 $0<|z-a|<\delta$ 时，$|f(z)|>M$，也与假设矛盾。
		故 $z=a$ 必为 $f(z)$ 的本质奇点。
- *注*：在本节最后，我们把第一章 §4 定义过的无穷远点邻域的概念推广如下，以方便应用：
	无穷远点邻域正好对应着以北极点 $N$ 为心的一个球盖，在复平面 $\mathbf{C}_{\infty}$ 上就是任何一个圆周的外部 (包含点 $\infty$)。
	确切地说，$N(\infty):r<|z-a|$ 就称为以 $z=a$ 为中心的 $z=\infty$ 的邻域 (包含点 $\infty$)；$N(\infty)\setminus\{\infty\}:r<|z-a|<+\infty$ 就称为以 $z=a$ 为中心的 $z=\infty$ 的去心邻域。
	当 $a=0$ 时，这就是 1-4 定义过的情形。
	设函数 $f(z)$ 在 $\mathbf{C}_{\infty}$ 上只有奇点 $z=a$ 和 $z=\infty$，则其洛朗展式可设为
	$$
	\begin{aligned}
	f(z)=& a_{0}+\frac{a_{1}}{z-a}+\cdots+\frac{a_{n}}{(z-a)^{n}}+\cdots+b_{1}(z-a)+b_{2}(z-a)^{2}+\cdots+ \\
	& b_{n}(z-a)^{n}+\cdots\ (r<|z-a|<+\infty)
	\end{aligned}
	$$
## 5-4 整函数与亚纯函数的概念
根据解析函数的孤立奇点特征，便可以区分出两种最简单的解析函数族。
### 5-4-1 整函数
- **整函数**：在第三章我们已经定义过，在整个 $z$ 平面上解析的函数 $f(z)$ 称为**整函数**。
- **定理 5.10**、**超越整函数** 
	若 $f(z)$ 为一整函数，则
	(1) $z=\infty$ 为 $f(z)$ 的可去奇点的充要条件为：$f(z)=$ 常数 $c_{0}$ 
	(2) $z=\infty$ 为 $f(z)$ 的 $m$ 阶极点的充要条件为：$f(z)$ 是一个 $m$ 次多项式 $c_{0}+c_{1}z+\cdots+c_{m}z^{m}\ (c_{m}\neq 0)$。
	(3) $z=\infty$ 为 $f(z)$ 的本质奇点的充要条件为：展式 $f(z) = \sum\limits_{n=0}^{\infty} c_{n}z^{n} \ (0\leqslant|z|<+\infty)$ 有无穷多个 $c_{n}$ 不等于零 (我们称这样的 $f(z)$ 为**超越整函数**)
	- 由此可见，整函数族按惟一奇点 $z=\infty$ 的不同类型而被分成了三类 (常数也可以看作是多项式的特例)。
	- *例如*：$\mathrm{e}^{z}$，$\sin z$ 及 $\cos z$ 都是超越整函数。
	- *证明过程* 
		设 $f(z)$ 为一整函数，则 $f(z)$ 只以 $z=\infty$ 为孤立奇点，且可设 $f(z) = \sum\limits_{n=0}^{\infty} c_{n}z^{n} \ (0\leqslant|z|<+\infty)$，于是显然有该定理
### 5-4-2 亚纯函数
- **亚纯函数**：在 $z$ 平面上除极点外无其他类型奇点的单值解析函数称为**亚纯函数**。
	- 亚纯函数族是较整函数族更一般的函数族。
- **定理 5.11**：一函数 $f(z)$ 为有理函数的充要条件为：$f(z)$ 在扩充 $z$ 平面上除极点外没有其他类型的奇点。
	- *证明过程* 
		*必要性*　
		设有理函数 $f(z)=\dfrac{P(z)}{Q(z)}$，其中 $P(z)$ 与 $Q(z)$ 分别为 $z$ 的 $m$ 次与 $n$ 次多项式，且彼此互质，则
		(1) 当 $m>n$ 时，$z=\infty$ 必为 $f(z)$ 的 $m-n$ 阶极点。
		(2) 当 $m\leqslant n$ 时，$z=\infty$ 必为 $f(z)$ 的可去奇点，只要置 $f(\infty) = \lim\limits_{z\to\infty} \dfrac{P(z)}{Q(z)}$，$z=\infty$ 就是 $f(z)$ 的解析点。
		(3) $Q(z)$ 的零点必为 $f(z)$ 的极点。
		*充分性* 
		若 $f(z)$ 在扩充 $z$ 平面上除极点外无其他类型的奇点，则这些极点的个数只能是有限个。因若不然，这些极点在扩充 $z$ 平面上的聚点就是 $f(z)$ 的非孤立奇点。与假设矛盾。
		今令 $f(z)$ 在 $z$ 平面上的极点为 $z_{1},z_{2},\cdots,z_{n}$，其阶分别为 $\lambda_{1},\lambda_{2},\cdots,\lambda_{n}$，则函数 $g(z)=(z-z_{1})^{\lambda_{1}}(z-z_{2})^{\lambda_{2}}\cdots(z-z_{n})^{\lambda_{n}}f(z)$ 至多以 $z=\infty$ 为极点，而在 $z$ 平面上解析。故 $g(z)$ 必为一多项式 (或常数)。即必有 $f(z)$ 为有理函数。
	- 由此可见，每一有理函数都是亚纯函数。
- **超越亚纯函数**：非有理函数的亚纯函数称为**超越亚纯函数**。
- *例 5.20*：$\dfrac{1}{\mathrm{e}^{z}-1}$ 是一个超越亚纯函数，因为它有无穷多个极点：$z=2k\pi\mathrm{i} \ (k=0,\pm 1,\pm 2,\cdots)$，其聚点 $z=\infty$ 是一个非孤立奇点。故此函数不可能是一有理函数。
- 整函数也看成是亚纯函数的一种特例。
- *注*：可去奇点既然可以除去后成为解析点，在定义及定理的条件中，一般就都不提到它。
- *例 5.21*：试证 $f(z)$ 是小叶整函数的充要条件为 $f(z)=az+b\ (a\neq 0)$ 
	- *证*　
		*充分性*　
		由于函数 $w=f(z)=az+b\ (a\neq 0)$ 及其反函数 $z = \dfrac{1}{a}(w-b)$ 都是单值整函数 (一次多项式)，所以 $f(z)=az+b\ (a\neq 0)$ 是单叶整函数。
		*必要性*　
		设 $f(z)$ 是单叶整函数。由定理 5.10，整函数分三类：
		(1) $f(z)$ 为常数，这与单叶性假设矛盾。
		(2) $f(z)$ 为超越整函数，$f(z)=c_{0}+c_{1}z+\cdots+c_{n}z^{n}+\cdots\ (0\leqslant|z|<+\infty)$ 
		它的惟一奇点是本质奇点 $z=\infty$，再由皮卡大定理，对每个 $A\neq\infty$，除掉可能的一个值 $A=A_{0}$ 外，必有趋于 $\infty$ 的无限点列 $\{z_{n}\}$，使 $f(z_{n})=A\ (n=1,2,\cdots)$，这也与 $f(z)$ 的单叶性假设矛盾。
		(3) $f(z)$ 为一多项式，$f(z)=c_{0}+c_{1}z+\cdots+c_{n}z^{n}\ (c_{n}\neq 0)$ 
		对每个 $A\neq\infty$，由代数学基本定理，$f(z)=A$ 必有且只有 $n$ 个根 (是几重根就算作几个根)，但由 $f(z)$ 的单叶性假设，必有 $n=1$，即必有 $f(z) = c_{0} + c_{1} z \ (c_{1}\neq 0)$，也可写成 $f(z)=az+b\ (a\neq 0)$ 
## 5-5 平面向量场——解析函数的应用（二）
### 5-5-1 奇点的流体力学意义
在 3-5 中已经知道，流体在区域 $D$ 内作无源、漏的无旋流动时，对应复势 $f(z)$ 是 $D$ 内的解析函数 (可能是多值的)。现在我们举两个例子来说明某些奇点具有的流体力学意义。

- *例 5.22*：考察复势为 $f(z)=\dfrac{N}{2\pi}\ln z$ 的流动 ($N$ 为非零实数)。
	- *解* 
		我们知道 $f(z)=\dfrac{N}{2\pi}\ln z$ 对应的流动在 $0<|z|<+\infty$ 内是无源、漏的并且是无旋的。现在我们来看看原点及 $\infty$ (作为 $\ln z$ 的支点) 有什么性质。
		令 $z=re^{i\theta}$，易知其势函数及流函数分别为 $\varphi(r,\theta) = \dfrac{N}{2\pi}\ln r,\ \psi(r,\theta) = \dfrac{N}{2\pi} \theta$ 

为了确定原点、$\infty$ 及 $N$ 的物理意义，考察沿圆周 $C:r=$ 常数的环量及流量。
$$\Gamma_{C}+\mathrm{i}N_{C}=\int_{C}f'(z)\mathrm{d}z=\frac{N}{2\pi}\int_{C}\frac{\mathrm{d}z}{z}=\mathrm{i}N$$
故 $\Gamma_{C}=0,N_{C}=N$。即对于任意的同心圆周 $r=$ 常数，均有相同的流量流过。
这恰好说明，每单位时间内有 $|N|$ 这样多的流量自原点涌出 $(N>0)$ 到点 $\infty$ 漏掉或自点 $\infty$ 涌出 $(N<0)$ 到原点漏掉。即原点就是一个源 $(N>0)$ 或漏 $(N<0)$。
对应的，$\infty$ 就算作一个漏 $(N>0)$ 或源 $(N<0)$。而称 $|N|$ 为**源 (漏) 强** (图 5.3)。
![[Pasted image 20260902162000.png|275]]
故势线是同心圆周 $r=$ 常数，流线是过原点的射线 $\theta=$ 常数，且此流动的复速度 $\overline{v(z)}=f'(z)=\dfrac{N}{2\pi z}$，以 $z=0$ 为一阶极点，以 $z=\infty$ 为一阶零点 (只要令 $v(\infty)=0$)。

- **例 5.23**：考察复势 $f(z)=\dfrac{1}{z}$ 的流动情况。
	- *解* 
		我们首先指出，$\dfrac{1}{z}$ 以 $z=0$ 为一阶极点，以 $z=\infty$ 为可去奇点 (一阶零点，只要令 $f(\infty)=0$)，它在 $0<|z|<+\infty$ 内是无源 (漏) 并且是无旋的。
		其次，容易算得势函数及流函数分别为
		$$\varphi(x,y)=\frac{x}{x^{2}+y^{2}},\quad \psi(x,y)=\frac{-y}{x^{2}+y^{2}},$$
		故势线及流线是经过原点且互为正交的圆周 (图 5.4)。
		![[Pasted image 20260902162237.png|175]]
		设 $C$ 是不过原点但包围原点的周线，则
		$$\Gamma_{C}+\mathrm{i}N_{C}=\int_{C}f'(z)\mathrm{d}z=-\int_{C}\frac{\mathrm{d}z}{z^{2}}=0.$$
		这种流动，可以想象为在原点处有充分多的流体以无限大的速度涌出，同时又以无限大的速度被漏掉。原点称为**重源**或称为**偶极子**，它是强度相同的一个源及一个漏无限接近而它们的强度无限增大时的极限情形。
### 5-5-2 在电场中的应用举例
在平面电场中，**电通** $\varphi$ 和**电位** $\psi$ 都是调和函数，即它们都满足拉普拉斯方程，而且**电力线** (相当于势线) $\varphi=k_{1}$ 和**等位线** (相当于流线) $\psi=k_{2}$ 互相正交。这种性质正好和一个解析函数的实部和虚部所具有的性质相符合。
因此，在研究平面电场时，常将电场的电通 $\varphi$ (相当于势函数) 和电位 $\psi$ (相当于流函数) 分别看作一个解析函数的实部和虚部，而将它们合为一个解析函数进行研究。
这种由电通作实部，电位作虚部组成的解析函数 $f(z)=\varphi(x,y)+\mathrm{i}\psi(x,y)$ 称为电场的**复电位** (相当于复势)。
如果不是利用解析函数作为研究电场的工具，则研究电场的电通和电位是孤立进行的，看不出它们之间的联系，在研究过程中也无一定的方法可循。
如果使用解析函数，则这些缺点都可以克服，而且计算起来亦较简单。
反过来，如果知道了一个平面电场的复电位，则通过对复电位的实部和虚部的研究，便可得出电场的分布情况。
*注*：静电场的势函数一定是单值函数。

- *例 5.24*：已知一电场的电力线方程为 $\arctan\dfrac{y}{x+b}-\arctan\dfrac{y}{x-b}=k_{1}$ 试求其等位线方程和复电位。
	- *解* 
		设复电位 $f(z)=\varphi+\mathrm{i}\psi$，则 $\varphi(x,y) = \arctan\dfrac{y}{x+b} - \arctan\dfrac{y}{x-b}$ 
		根据 C.-R.方程，$\psi_{y} = \varphi_{x} = \dfrac{-y}{(x+b)^{2}+y^{2}} + \dfrac{y}{(x-b)^{2}+y^{2}}$ 
		两边对 $y$ 积分，得
		$$
		\begin{aligned}
		\psi(x,y)&=\int\left[\frac{y}{(x-b)^{2}+y^{2}}-\frac{y}{(x+b)^{2}+y^{2}}\right]\mathrm{d}y\\
		&=\frac{1}{2}\ln[(x-b)^{2}+y^{2}]-\frac{1}{2}\ln[(x+b)^{2}+y^{2}]+\lambda(x).
		\end{aligned}
		$$
		又 $\psi_{x}=-\varphi_{y}$，而
		$$
		\begin{aligned}
		& \psi_{x}=\frac{x-b}{(x-b)^{2}+y^{2}}-\frac{x+b}{(x+b)^{2}+y^{2}}+\lambda'(x) \\
		& \varphi_{y}=\frac{x+b}{(x+b)^{2}+y^{2}}-\frac{x-b}{(x-b)^{2}+y^{2}}
		\end{aligned}
		$$
		故 $\lambda'(x)=0$，即 $\lambda(x)=\lambda$ 为一常数。
		于是得等位线方程为 $\dfrac{1}{2}\ln[(x-b)^{2}+y^{2}] - \dfrac{1}{2} \ln[(x+b)^{2}+y^{2}] + \lambda = \lambda_{1}$ 或 $\ln\sqrt{\dfrac{(x-b)^{2}+y^{2}}{(x+b)^{2}+y^{2}}}=k_{2}\ (k_{2}=\lambda_{1}-\lambda)$ 
		复电位为 $f(z)=\left(\arctan\dfrac{y}{x+b}-\arctan\dfrac{y}{x-b}\right)+\mathrm{i}\ln\sqrt{\dfrac{(x-b)^{2}+y^{2}}{(x+b)^{2}+y^{2}}}$ 或 $f(z)=\mathrm{i}\ln\left(\dfrac{z-b}{z+b}\right)$ 
		这是双曲线传输线所产生的电场 (图 5.5)。$f(z)$ 的支点 $-b$ 及 $b$ 就是这个电场的正、负电荷位置。
		![[Pasted image 20260902162726.png|400]]

通过上面的讨论，我们知道，利用解析函数对电场进行研究是十分理想的，它可将对电场的电位和电通的研究联系起来，克服了分别研究的复杂手续，而且使问题得到了简化。但找出这样的解析函数是极不容易的。因此，一般是将问题反转过来，不是根据电场去找解析函数，而是先研究一些不同的解析函数，找出它们所表示的电场图形，再由这些电场的图形推出带电导体的形状。如此积累了一些电场图形与解析函数之间的关系，再由这些已知的关系，推出新电场的复电位函数。即使现有导体的形状为已知的关系所不具备，也可选用近似的形状，把所得的解析函数用于现有的情况，较无根据的猜测，总要好些。下面就介绍一个由解析函数所表示的电场。
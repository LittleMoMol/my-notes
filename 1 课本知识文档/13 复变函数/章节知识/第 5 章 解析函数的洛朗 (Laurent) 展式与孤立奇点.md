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

### 1. 孤立奇点的三种类型

已经说过，如 $a$ 为函数 $f(z)$ 的孤立奇点，则 $f(z)$ 在 $a$ 点的某去心邻域 $K\setminus\{a\}$ 内可以展成洛朗级数
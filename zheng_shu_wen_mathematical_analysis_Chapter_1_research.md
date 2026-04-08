# 集合与映射
## 1 集合
1. **集合的概念** 
   集合是具有某种特定性质的具体或抽象的对象汇集成的总体，对象称为元素。常用大写字母（A, B, S, T）表示集合，小写字母（a, b, x, y）表示元素。属于记作 $x \in S$，不属于记作 $y \notin S$ 或 $y \bar{\in} S$。
2. **常用数集** 
	- 正整数集：$N^{+}$ 
	- 整数集：$Z$ 
	- 有理数集：$Q$ 
	- 实数集：$R$ 
3. **集合的表示方法**
	- 枚举法：将元素逐一列出，例如 $A=\{a, b, c, d\}$。
	- 描述法：通过元素的公共属性表示，例如 $S=\{x \mid x \text{ 具有性质 } P\}$。
4. **空集**
	不含任何元素的集合称为空集，记作 $\varnothing$。
5. **子集与真子集**
	- 若 $S$ 的所有元素都属于 $T$，则 $S$ 是 $T$ 的子集，记作 $S \subset T$。
	- 若 $S \subset T$ 且存在 $x \in T$ 但 $x \notin S$，则 $S$ 是 $T$ 的真子集。
6. **集合相等**
	若 $S \subset T$ 且 $T \subset S$，则 $S=T$。
7. **区间**
	实数集 $R$ 的常见子集（以 $a, b \in R$，$a<b$ 为例）：
	- 开区间：$(a, b) = \{x \mid a<x<b\}$
	- 闭区间：$[a, b] = \{x \mid a \leqslant x \leqslant b\}$
	- 半开半闭区间：$(a, b] = \{x \mid a<x \leqslant b\}$，$[a, b) = \{x \mid a \leqslant x<b\}$
	- 无限区间：$(a, +\infty)$，$[a, +\infty)$，$(-\infty, b)$，$(-\infty, b]$，$(-\infty, +\infty)$。
8. **集合的基本运算**
	- 并集：$S \cup T = \{x \mid x \in S \text{ 或者 } x \in T\}$
	- 交集：$S \cap T = \{x \mid x \in S \text{ 并且 } x \in T\}$
	- 差集：$S \backslash T = \{x \mid x \in S \text{ 并且 } x \notin T\}$
	- 补集：设 $S \subset X$，$S$ 关于 $X$ 的补集 $S_X^C = X \backslash S$。在不混淆时可简记为 $S^C$。
9. **集合运算的性质**
	- 交换律：$A \cup B = B \cup A$，$A \cap B = B \cap A$
	- 结合律：$A \cup (B \cup D) = (A \cup B) \cup D$，$A \cap (B \cap D) = (A \cap B) \cap D$
	- 分配律：$A \cap (B \cup D) = (A \cap B) \cup (A \cap D)$，$A \cup (B \cap D) = (A \cup B) \cap (A \cup D)$
	- 对偶律（De Morgan公式）：$(A \cup B)^C = A^C \cap B^C$，$(A \cap B)^C = A^C \cup B^C$
10. **有限集与无限集**
    - 由有限个元素组成的集合称为有限集。
    - 不是有限集的集合称为无限集。
    - 若一个无限集的元素可以按某种规律排成一个序列 $\{a_1, a_2, \cdots, a_n, \cdots\}$，则称其为可列集（或可数集）。
11. **可列集的性质**
    - 整数集 $Z$ 是可列集。
    - **定理 1.1.1**：可列个可列集之并也是可列集。
    - **定理 1.1.2**：有理数集 $Q$ 是可列集。
12. **Descartes乘积集合**
    设 $A$ 与 $B$ 是两个集合，有序对 $(x, y)$（其中 $x \in A$, $y \in B$）全体组成的集合称为 $A$ 与 $B$ 的 Descartes乘积集合，记作 $A \times B = \{(x, y) \mid x \in A \text{ 并且 } y \in B\}$。特别地，$R \times R$（记作 $R^2$）对应平面直角坐标系下的点集。
## 2 映射与函数
1. **映射的定义**
	设 $X, Y$ 是两个集合，若按照某种规则 $f$，使得对 $X$ 中的每一个元素 $x$，都能找到 $Y$ 中唯一确定的元素 $y$ 与之对应，则称 $f$ 是集合 $X$ 到集合 $Y$ 的一个映射，记作 $f: X \rightarrow Y$，$x \mapsto y = f(x)$。其中 $y$ 称为 $x$ 的像，$x$ 称为 $y$ 的一个逆像（或原像）。$D_f = X$ 称为定义域，$R_f = \{y \mid y = f(x), x \in X\}$ 称为值域。
2. **构成映射的三要素**
	定义域 $D_f = X$；值域所在集合 $Y$（满足 $R_f \subset Y$）；对应规则 $f$。
3. **映射的类型**
	- **单射**：若对 $X$ 中任意两个不同元素 $x_1 \neq x_2$，有 $f(x_1) \neq f(x_2)$。
	- **满射**：若 $R_f = Y$。
	- **双射（一一对应）**：既是单射又是满射。
4. **逆映射**
	若映射 $f: X \rightarrow Y$ 是单射，则存在逆映射 $f^{-1}: R_f \rightarrow X$，满足 $y \mapsto x$（其中 $f(x) = y$）。$f^{-1}$ 是 $R_f$ 到 $X$ 上的双射。
5. **复合映射**
	设有映射 $g: X \rightarrow U_1$，$f: U_2 \rightarrow Y$，若 $R_g \subset U_2 = D_f$，则可定义复合映射 $f \circ g: X \rightarrow Y$，$x \mapsto y = f(g(x))$。
6. **一元实函数**
	当 $X \subset R$，$Y = R$ 时，映射 $f: X \rightarrow R$，$x \mapsto y = f(x)$ 称为一元实函数，简称函数。记作 $y = f(x), x \in X$。
7. **基本初等函数**
	常数函数、幂函数 $y = x^\alpha$、指数函数 $y = a^x$、对数函数 $y = \log_a x$、三角函数（如 $\sin x, \cos x$）、反三角函数（如 $\arcsin x, \arctan x$）。
8. **初等函数**
	由基本初等函数经过有限次四则运算与复合运算所产生的函数。其自然定义域是自变量最大取值范围。
9. **函数的其他表示法**
	- **分段表示**：函数在不同区间用不同表达式定义。
	- **隐式表示**：通过方程 $F(x, y) = 0$ 确定 $y$ 与 $x$ 的函数关系。
	- **参数表示**：通过引入参数 $t$，建立 $x = x(t)$, $y = y(t)$，$t \in [a, b]$ 来确定 $y$ 与 $x$ 的函数关系。
10. **函数的简单特性**
	 - **有界性**：若存在常数 $M, m$，使 $\forall x \in D$，有 $m \leqslant f(x) \leqslant M$，则称 $f$ 在 $D$ 有界。等价定义为：$\exists M>0$，使 $\forall x \in D$，有 $|f(x)| \leqslant M$。
	 - **单调性**：
        - 单调增加：若对 $\forall x_1, x_2 \in D$，当 $x_1 < x_2$ 时，$f(x_1) \leqslant f(x_2)$。
        - 严格单调增加：若 $x_1 < x_2$ 时，$f(x_1) < f(x_2)$。
        - 单调减少和严格单调减少类似定义。
    - **奇偶性**：设 $D$ 关于原点对称。
        - 偶函数：若 $\forall x \in D$，有 $f(-x) = f(x)$。
        - 奇函数：若 $\forall x \in D$，有 $f(-x) = -f(x)$。
    - **周期性**：若存在常数 $T > 0$，使 $\forall x \in D$，有 $f(x+T) = f(x)$，则称 $f$ 是周期函数，$T$ 为其周期。若存在满足条件的最小 $T$，则称 $T$ 为最小周期。
11. **两个常用不等式**
	 - **三角不等式**：对于任意实数 $a$ 和 $b$，有 $||a| - |b|| \leqslant |a+b| \leqslant |a| + |b|$。
	 - **平均值不等式**：对任意 $n$ 个正数 $a_1, a_2, \cdots, a_n$，有 $\frac{a_1 + a_2 + \cdots + a_n}{n} \geqslant \sqrt[n]{a_1 a_2 \cdots a_n} \geqslant \frac{n}{\frac{1}{a_1} + \frac{1}{a_2} + \cdots + \frac{1}{a_n}}$。等号当且仅当所有 $a_i$ 相等时成立。其中 $\frac{a_1+\cdots+a_n}{n}$ 为算术平均值，$\sqrt[n]{a_1 \cdots a_n}$ 为几何平均值，$\frac{n}{\frac{1}{a_1}+\cdots+\frac{1}{a_n}}$ 为调和平均值。
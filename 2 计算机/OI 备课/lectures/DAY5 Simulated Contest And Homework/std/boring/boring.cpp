#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long LL;
const LL N = 1e5 + 10;

LL n, Q, sum1, sum2, sum3;
struct warma
{
	LL l, r;
	LL s1; //存 al ~ ar
	LL s2; //存 al*i ~ ar*i
	LL s3; //存 al*i*i ~ ar*i*i
	LL s4; //存 i 的和，build 的时候可以预处理出来
	LL s5; //存 i*i 的和，build 的时候可以预处理出来
	LL tag;
} tr[N << 2];

LL read()
{
	LL s = 0, w = 1;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-') w = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		s = s * 10 + c - '0';
		c = getchar();
	}
	return s * w;
}

LL gcd(LL a, LL b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

void pushup(LL idx)
{
	tr[idx].s1 = tr[idx << 1].s1 + tr[idx << 1 | 1].s1;
	tr[idx].s2 = tr[idx << 1].s2 + tr[idx << 1 | 1].s2;
	tr[idx].s3 = tr[idx << 1].s3 + tr[idx << 1 | 1].s3;
	return;
}

void eval(warma &t, LL val)
{
	t.s1 += (t.r - t.l + 1) * val;
	t.s2 += val * t.s4;
	t.s3 += val * t.s5;
	t.tag += val;
	return;
}

void pushdown(LL idx)
{
	if (tr[idx].tag)
	{
		eval(tr[idx << 1], tr[idx].tag);
		eval(tr[idx << 1 | 1], tr[idx].tag);
		tr[idx].tag = 0;
	}
	return;
}

void build(LL idx, LL L, LL R)
{
	if (L == R) tr[idx] = {L, R, 0, 0, 0, L, L * L, 0};
	else
	{
		tr[idx] = {L, R, 0, 0, 0, 0, 0, 0};
		LL mid = L + R >> 1;
		build(idx << 1, L, mid);
		build(idx << 1 | 1, mid + 1, R);
		pushup(idx);
		tr[idx].s4 = tr[idx << 1].s4 + tr[idx << 1 | 1].s4;
		tr[idx].s5 = tr[idx << 1].s5 + tr[idx << 1 | 1].s5;
	}
	return;
}

void modify(LL idx, LL L, LL R, LL val)
{
	if (L <= tr[idx].l && tr[idx].r <= R) eval(tr[idx], val);
	else
	{
		pushdown(idx);
		LL mid = tr[idx].l + tr[idx].r >> 1;
		if (L <= mid) modify(idx << 1, L, R, val);
		if (R > mid) modify(idx << 1 | 1, L, R, val);
		pushup(idx);
	}
	return;
}

void query(LL idx, LL L, LL R)
{
	if (L <= tr[idx].l && tr[idx].r <= R)
	{
		sum1 += tr[idx].s1;
		sum2 += tr[idx].s2;
		sum3 += tr[idx].s3;
	}
	else
	{
		pushdown(idx);
		LL mid = tr[idx].l + tr[idx].r >> 1;
		if (L <= mid) query(idx << 1, L, R);
		if (R > mid) query(idx << 1 | 1, L, R);
	}
	return;
}

int main ()
{
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	n = read(), Q = read();
	build(1, 1, n);
	while (Q -- )
	{
		char op[5];
		scanf("%s", op);
		if (op[0] == 'C')
		{
			LL l = read(), r = read() - 1, v = read();
			modify(1, l, r, v);
		}
		else
		{
			LL l = read(), r = read() - 1;
			sum1 = sum2 = sum3 = 0; //1 为 al ~ ar; 2 为 al*i ~ ar*i； 3 为 al*i*i ~ ar*i*i
			query(1, l, r);
			LL fz = (l + r) * sum2 + (r - l - l * r + 1) * sum1 - sum3;
			LL fm = (r - l + 2) * (r - l + 1) / 2;
			LL d = gcd(fz, fm);
			fz /= d, fm /= d;
			printf("%lld/%lld\n", fz, fm);
		}
	}
	return 0;
}

// 读入直接传入str 然后pre
namespace Hash {
    using a2 = array<LL, 2>;
    std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    size_t len;  // 字符串长度
	// 传入字符串直接传入下标从0开始就行 后面处理下标从1开始
    string str;
    const LL MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
	const LL base1 = rng() % MOD1, base2 = rng() % MOD2;
	LL ha1[N], ha2[N];  // 正着的哈希值
	LL rha1[N], rha2[N];  // 反着的哈希值
	LL pow1[N], pow2[N];  // base1和base2的乘方

	void init() {  // 预处理pow1[]、pow2[]
		pow1[0] = pow2[0] = 1;
		for (int i = 1; i < N; i++) {
			pow1[i] = pow1[i - 1] * base1 % MOD1;
			pow2[i] = pow2[i - 1] * base2 % MOD2;
		}
	}

	void pre() {  // 预处理ha1[]、ha2[]
        len = str.size();
		for (int i = 1; i <= len; i++) {
			ha1[i] = (ha1[i - 1] * base1 + str[i - 1]) % MOD1;
			ha2[i] = (ha2[i - 1] * base2 + str[i - 1]) % MOD2;
			rha1[i] = (rha1[i - 1] * base1 + str[len - i]) % MOD1;
			rha2[i] = (rha2[i - 1] * base2 + str[len - i]) % MOD2;
		}
	}

	a2 get_hash(int l, int r) { 
        a2 res; // 求子串str[l...r]正着的哈希值
		res[0] = ((ha1[r] - ha1[l - 1] * pow1[r - l + 1]) % MOD1 + MOD1) % MOD1;
		res[1] = ((ha2[r] - ha2[l - 1] * pow2[r - l + 1]) % MOD2 + MOD2) % MOD2;
		return res;
	}

	a2 get_rhash(int l, int r) {
        a2 res; // 求子串str[l...r]反着的哈希值
		res[0] = ((rha1[len - l + 1] - rha1[len - r] * pow1[r - l + 1]) % MOD1 + MOD1) % MOD1;
		res[1] = ((rha2[len - l + 1] - rha2[len - r] * pow2[r - l + 1]) % MOD2 + MOD2) % MOD2;
		return res;
	}

	bool IsPalindrome(int l, int r) {  // 判断子串str[l...r]是否是回文串
		return get_hash(l, r) == get_rhash(l, r);
	}

	bool IsSame(int l, int r, int _l, int _r) {
		return get_hash(l, r) == get_hash(_l, _r);
	}

	a2 add(a2 a, a2 b) {
		LL res1 = (a[0] + b[0]) % MOD1;
		LL res2 = (a[1] + b[1]) % MOD2;
		return a2{res1, res2};
	}

	a2 mul(a2& a, int k) {  // a *= base的k次方
		LL res1 = a[0] * pow1[k] % MOD1;
		LL res2 = a[1] * pow2[k] % MOD2;
		return a2{res1, res2};
	}
};

#include <bits/stdc++.h>
using namespace std;

#define MAXN 100100
#define MAXLOG 21

int n, log_n;
char s[MAXN];

int sa[MAXN], c[MAXLOG][MAXN];

// Ordena os sufixos ciclicamente
// (https://cp-algorithms.com/string/suffix-array.html)
void sort_cyclic_shifts() {
	const int alphabet = 256;
	vector<int> cnt(max(alphabet, n), 0);
	for (int i = 0; i < n; i++)
		cnt[s[i]]++;
	for (int i = 1; i < alphabet; i++)
		cnt[i] += cnt[i - 1];
	for (int i = 0; i < n; i++)
		sa[--cnt[s[i]]] = i;
	c[0][sa[0]] = 0;
	int classes = 1;
	for (int i = 1; i < n; i++) {
		if (s[sa[i]] != s[sa[i - 1]])
			classes++;
		c[0][sa[i]] = classes - 1;
	}
	vector<int> pn(n);
	int h;
	for (h = 0; (1 << h) < n; h++) {
		for (int i = 0; i < n; i++) {
			pn[i] = sa[i] - (1 << h) ;
			if (pn[i] < 0)
				pn[i] += n;
		}
		fill(cnt.begin(), cnt.begin() + classes, 0);
		for (int i = 0; i < n; i++)
			cnt[c[h][pn[i]]]++;
		for (int i = 1; i < classes; i++)
			cnt[i] += cnt[i - 1];
		for (int i = n - 1; i >= 0; i--)
			sa[--cnt[c[h][pn[i]]]] = pn[i];
		c[h + 1][sa[0]] = 0;
		classes = 1;
		for (int i = 1; i < n; i++) {
			pair<int, int> cur = {c[h][sa[i]], c[h][(sa[i] + (1 << h)) % n]};
			pair<int, int> prev = {c[h][sa[i - 1]], c[h][(sa[i - 1] + (1 << h)) % n]};
			if (cur != prev)
				++classes;
			c[h + 1][sa[i]] = classes - 1;
		}
	}
	log_n = h;
}

// Constroi vetor de sufixo no vetor sa (posicoes de 0 a n-1)
void suffix_array_construction() {
	n = strlen(s);
	s[n] = '$';
	n++;
	sort_cyclic_shifts();
	n--;
	// Removendo o sufixo "$"
	for (int i = 0 ; i < n ; i++) swap(sa[i], sa[i + 1]);
	s[n] = '\0';
}

// Longest common prefix entre sufixos i e j
int lcp(int i, int j) {
	int ans = 0, maxp = max(i, j);
	for (int k = log_n; k >= 0; k--) {
		if ((1 << k) + maxp <= n && c[k][i] == c[k][j]) {
			ans += 1 << k;
			i += 1 << k;
			j += 1 << k;
		}
	}
	return ans;
}

// Compara substring de tamanho l nos sufixos i e j
// Retorna sinal de "Si - Sj"
// -1 -> Si < Sj
//  0 -> Si == Sj
//  1 -> Si > Sj
bool comp_substrings(int i, int j, int l)
{
	int k;
	for (k = 0 ; (1 << (k + 1)) <= l ; k++); // Pode ser precomputado para evitar O(logN)
	pair<int, int> a = {c[k][i], c[k][(i + l - (1 << k)) % n]};
	pair<int, int> b = {c[k][j], c[k][(j + l - (1 << k)) % n]};
	return a == b ? 0 : a < b ? -1 : 1;
}

int m;
char pat[MAXN];

bool comp_pat(int i, int j)
{
	return strncmp(i < 0 ? pat : s + i, j < 0 ? pat : s + j, m) < 0;
}

// Conta quantas vezes a string p aparece em s
int count_pattern()
{
	return upper_bound(sa, sa + n, -1, comp_pat)
	       - lower_bound(sa, sa + n, -1, comp_pat);
}

int main()
{
	scanf("%s", s);
	suffix_array_construction();
	for (int i = 0 ; i < n ; i++)
	{
		printf("%3d: %s\n", sa[i], s + sa[i]);
		if (i + 1 < n)
		{
			printf("lcp: %d\n", lcp(sa[i], sa[i + 1]));
		}
	}

	scanf("%s", pat);
	m = strlen(pat);
	printf("\n\"%s\" aparece %d vezes\n", pat, count_pattern());

	return 0;
}
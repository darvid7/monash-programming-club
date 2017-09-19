#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

// Suffix array construction with Longest Common Prefix.
// Does not include the empty suffix.
// lcp[i] is the longest common prefix between strings at sarray[i - 1] and sarray[i].
// lcp[0] = 0
struct suffix_array {
    // Attributes.
    int n;
    string str;
    vi sarray;
    vi lcp;

    // r = rank.
    // sa = suffix array.

    // Methods.
    void bucket(vi& a, vi& b, vi& r, int n, int K, int off=0) {
        vi c(K + 1, 0);
        for (int i = 0; i < n; i++) {
            c[r[a[i] + off]]++;
        }
        for (int i = 0, sum=0; i <= K; i++) {
            int t = c[i];
            c[i] = sum;
            sum += t;
        }
        for (int i = 0; i < n; i++) {
            b[c[r[a[i] + off ]]++] = a[i];
        }
    }

    // TODO: ask darcy how to write it out the long way.
    // Constructor.
    // Create suffix array.
    //                      inits your variables       calls method ot build array.
    suffix_array(string s): n(s.size()), str(move(s)) { build_array();};

    // Build array O(n log n).
    void build_array() {
        sarray.assign(n, 0);
        vi r(2*n, 0);
        vi sa(2*n);
        vi tmp(2*n);
        if (n <= 1) {
            return;
        }

        for (int i = 0; i < n; i++) {
            r[i] = (int) str[i] - CHAR_MIN + 1;
            sa[i] = i;
        }

        for (int k = 1; k < n; k *= 2) {
            bucket(sa, tmp, r, n, max(n, 256), k);
            bucket(tmp, sa, r, n, max(n, 256), 0);
            tmp[sa[0]] = 1;
            for (int i = 1; i < n; i++) {
                tmp[sa[i]] = tmp[sa[i - 1]];
                if ((r[sa[i]] != r[sa[i - 1]]) || (r[sa[i] + k] != r[sa[i - 1] + k])) {
                    tmp[sa[i]]++;
                }
            }
            copy(tmp.begin(), tmp.begin() + n, r.begin());
        }
        copy(sa.begin(), sa.begin() + n, sarray.begin());
    }

    struct Comp {
        const string& s;
        int m;
        int j;

        Comp(const string& str, int m, int j): s(str), m(m), j(j) {}

        bool operator()(int i, const string& p) const { return s.compare(i,m,p,j,m) < 0; }
        bool operator()(const string& p, int i) const { return s.compare(i,m,p,j,m) > 0; }
    };

    // Returns
    pair<vector<int>::iterator,std::vector<int>::iterator> find(const string& pat, int j=0) {
        return equal_range(sarray.begin(), sarray.end(), pat, Comp(str,pat.size(),j));
    }

    /*
    pair<int, int> find(const string& pat, int j=0) {
        auto p = equal_range(sarray.begin(), sarray.end(), pat, Comp(str,pat.size(),j));
        pair<int, int> res = {p.first-sarray.begin(), p.second -sarray.begin()};
        return res;
    }
    */

int main() {
    suffix_array my_suffix_array("hello a");
    cout << "Suffix array string: " << my_suffix_array.str << endl;
    cout << "Suffix array:" << endl;
    for (int num : my_suffix_array.sarray) {
        cout << num << " ";
    }
    cout << endl;

    string my_pattern = "hell";
    string my_pattern_not_in_sa = "bob";

    //cout << "find(hell): " << my_suffix_array.find(my_pattern) << endl;
    //cout << "find(bob): " << my_suffix_array.find(my_pattern_not_in_sa) << endl;

    // string: hello a
    // index:  0123456
    // sa:     [5, 6, 1, 0, 2, 3, 4]
    // This means the smallest suffix starts at index 5.
    // The second smallest sustring starts at index 6 ad so forth.
    // Correct as the space is the smallest character followed by a.

    // cout << "LCP array:" << endl;
    // for (int num : my_suffix_array.lcp) {
    //     cout << num << " ";
    // }
    // cout << endl;

    // DOES


}

# C++STL

## table of contents

| Function | Description | Time Complexity | Header |
| ---- | ---- | ---- | ---- |
| [gcd](#gcd) | 最大公約数 | O(log n) | `<numeric>` |
| [swap](#swap) | 値の交換 | O(1) | `<algorithm>` |
| [rand](#rand) | 乱数生成 | - | `<cstdlib>` |
| [clock](#clock) | 実行時間計測 | - | `<ctime>` |
| [string](#string) | 文字列操作 | - | `<string>` |
| [assert](#assert) | 条件チェック | - | `<cassert>` |
| [count](#count) | 要素数カウント | O(n) | `<algorithm>` |
| [find](#find) | 要素検索 | O(n) | `<algorithm>` |
| [next_permutation](#next_permutation) | 次の順列 | O(n) | `<algorithm>` |
| [__builtin_popcount](#__builtin_popcount) | ビット数 | O(1) | - |
| [bitset](#bitset) | ビット管理 | O(1) | `<bitset>` |
| [reverse](#reverse) | 反転 | O(n) | `<algorithm>` |
| [lower_bound](#lower_bound) | 二分探索（以上） | O(log n) | `<algorithm>` |
| [upper_bound](#upper_bound) | 二分探索（より大きい） | O(log n) | `<algorithm>` |
| [binary_search](#binary_search) | 存在判定 | O(log n) | `<algorithm>` |
| [substr](#substr) | 部分文字列 | O(n) | `<string>` |
| [sort](#sort) | ソート | O(n log n) | `<algorithm>` |
| [abs](#abs) | 絶対値 | O(1) | `<cmath>` |
| [unique](#unique) | 重複削除 | O(n) | `<algorithm>` |
| [erase](#erase) | 削除 | O(n) | `<vector>` |
| [queue](#queue) | FIFO | O(1) | `<queue>` |
| [deque](#deque) | 両端キュー | O(1) | `<deque>` |
| [stack](#stack) | LIFO | O(1) | `<stack>` |
| [priority_queue](#priority_queue) | 優先度付きキュー | O(log n) | `<queue>` |
| [set](#set) | 自動ソート集合 | O(log n) | `<set>` |
| [map](#map) | キー付き辞書 | O(log n) | `<map>` |
| [unordered_set](#unordered_set) | 高速集合 | O(1) avg | `<unordered_set>` |
| [unordered_map](#unordered_map) | 高速辞書 | O(1) avg | `<unordered_map>` |
| [pair](#pair) | 2値 | O(1) | `<utility>` |
| [tuple](#tuple) | 複数値 | O(1) | `<tuple>` |

## explanation

---

### gcd

#### Required Header
#include \<numeric\>

#### Usage
```cpp
int g = std::gcd(a, b);
```

#### Time Complexity
O(log(min(a, b)))

#### Notes
- C++17以降はstd::gcd推奨

---

### swap

#### Required Header
#include \<algorithm\>

#### Usage
```cpp
swap(a, b);
```

#### Time Complexity
O(1)

---

### rand

#### Required Header
#include <cstdlib>

#### Usage
```cpp
int x = rand();
```

#### Notes
- 乱数の質は低い（競プロではあまり使わない）

---

### clock

#### Required Header
#include \<ctime\>

#### Usage
```cpp
clock_t t = clock();
```

#### Notes
- 実行時間測定用（提出では不要）

---

### string

#### Required Header
#include \<string\>

#### Usage
```cpp
string s = "abc";
```

---

### assert

#### Required Header
#include \<cassert\>

#### Usage
```cpp
assert(x > 0);
```

#### Notes
- デバッグ用

---

### count

#### Required Header
#include \<algorithm\>

#### Usage
```cpp
count(v.begin(), v.end(), x);
```

#### Time Complexity
O(n)

---

### find

#### Required Header
#include \<algorithm\>

#### Usage
```cpp
find(v.begin(), v.end(), x);
```

#### Time Complexity
O(n)

---

### next_permutation

#### Required Header
#include \<algorithm\>

#### Usage
```cpp
next_permutation(v.begin(), v.end());
```

#### Time Complexity
O(n)

#### Notes
- ソート済みから使う

---

### __builtin_popcount

#### Usage
```cpp
__builtin_popcount(x);
__builtin_popcountll(x);
```

#### Time Complexity
O(1)

---

### bitset

#### Required Header
#include \<bitset\>

#### Usage
```cpp
bitset<8> b(10);
```

---

### reverse

#### Required Header
#include \<algorithm\>

#### Usage
```cpp
reverse(v.begin(), v.end());
```

#### Time Complexity
O(n)

---

### lower_bound

#### Required Header
#include \<algorithm\>

#### Usage
```cpp
auto it = lower_bound(v.begin(), v.end(), x);
```

#### Time Complexity
O(log n)

#### Notes
- ソート済み前提
- 「x以上の最初の位置」

---

### upper_bound

#### Required Header
#include \<algorithm\>

#### Usage
```cpp
auto it = upper_bound(v.begin(), v.end(), x);
```

#### Time Complexity
O(log n)

#### Notes
- 「xより大きい最初の位置」

---

### binary_search

#### Required Header
#include \<algorithm\>

#### Usage
```cpp
binary_search(v.begin(), v.end(), x);
```

#### Time Complexity
O(log n)

---

### substr

#### Required Header
#include \<string\>

#### Usage
```cpp
s.substr(pos, len);
```

#### Time Complexity
O(n)

---

### sort

#### Required Header
#include \<algorithm\>

#### Usage
```cpp
sort(v.begin(), v.end());
```

#### Time Complexity
O(n log n)

---

### abs

#### Required Header
#include \<cmath\>

#### Usage
```cpp
abs(x);
```

#### Time Complexity
O(1)

---

### unique

#### Required Header
#include \<algorithm\>

#### Usage
```cpp
v.erase(unique(v.begin(), v.end()), v.end());
```

#### Time Complexity
O(n)

#### Notes
- ソートしてから使う

---

### erase

#### Required Header
#include \<vector\>

#### Usage
```cpp
v.erase(v.begin());
```

#### Time Complexity
O(n)

---

### queue

#### Required Header
#include \<queue\>

#### Usage
```cpp
queue<int> q;
q.push(1);
q.pop();
```

#### Time Complexity
O(1)

---

### deque

#### Required Header
#include \<deque\>

#### Usage
```cpp
deque<int> dq;
dq.push_front(1);
dq.push_back(2);
```

#### Time Complexity
O(1)

---

### stack

#### Required Header
#include \<stack\>

#### Usage
```cpp
stack<int> st;
st.push(1);
st.pop();
```

#### Time Complexity
O(1)

---

### priority_queue

#### Required Header
#include \<queue\>

#### Usage
```cpp
priority_queue<int> pq;
```

#### Time Complexity
push/pop: O(log n)

#### Notes
- デフォルトは最大ヒープ

---

### set

#### Required Header
#include \<set\>

#### Usage
```cpp
set<int> st;
st.insert(1);
```

#### Time Complexity
O(log n)

---

### map

#### Required Header
#include \<map\>

#### Usage
```cpp
map<int, int> mp;
mp[1] = 10;
```

#### Time Complexity
O(log n)

---

### unordered_set

#### Required Header
#include \<unordered_set\>

#### Usage
```cpp
unordered_set<int> st;
```

#### Time Complexity
O(1) average

---

### unordered_map

#### Required Header
#include \<unordered_map\>

#### Usage
```cpp
unordered_map<int, int> mp;
```

#### Time Complexity
O(1) average

---

### pair

#### Required Header
#include \<utility\>

#### Usage
```cpp
pair<int, int> p = {1, 2};
```

#### Time Complexity
O(1)

---

### tuple

#### Required Header
#include \<tuple\>

#### Usage
```cpp
tuple<int, int, int> t;
```

#### Time Complexity
O(1)

# Refer

- [レッドコーダーが教える、競プロ・AtCoder上達のガイドライン【中級編：目指せ水色コーダー！】- 2-2-1. 標準ライブラリを使えるようになる！](https://qiita.com/e869120/items/eb50fdaece12be418faa#2-2-1-%E6%A8%99%E6%BA%96%E3%83%A9%E3%82%A4%E3%83%96%E3%83%A9%E3%83%AA%E3%82%92%E4%BD%BF%E3%81%88%E3%82%8B%E3%82%88%E3%81%AB%E3%81%AA%E3%82%8B)

- [厳選！C++ アルゴリズム実装に使える 25 の STL 機能【前編】](https://qiita.com/e869120/items/518297c6816adb67f9a5#3-8-%E6%99%82%E9%96%93%E8%A8%88%E6%B8%AC-clock)

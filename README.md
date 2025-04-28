---

# Counting Sort in C++

This project implements the **Counting Sort** algorithm in **C++**.  
Counting Sort is a non-comparison-based sorting technique ideal for sorting integers within a known and limited range.

---

## 📋 Features

- Sorts a list of non-negative integers efficiently.
- **Faster than comparison-based sorts** when maximum value is reasonable.
- **Stable sort** (preserves order of equal elements).
- Time complexity depends on both the number of elements and the maximum value.

---

## 🚀 How Counting Sort Works

Counting Sort works by:
1. **Counting** how many times each value appears.
2. **Building a prefix sum** of counts to find final positions.
3. **Placing elements** in the correct position based on counts.

Unlike typical sorting algorithms, **it does not compare elements**.

---

## 📈 Time Complexity Comparison

| Algorithm         | Best Case   | Average Case | Worst Case  | Space Complexity | Stable? | Type                   |
|-------------------|-------------|--------------|-------------|------------------|---------|------------------------|
| **Bubble Sort**    | O(n)        | O(n²)         | O(n²)       | O(1)             | Yes     | Comparison-based       |
| **Selection Sort** | O(n²)       | O(n²)         | O(n²)       | O(1)             | No      | Comparison-based       |
| **Insertion Sort** | O(n)        | O(n²)         | O(n²)       | O(1)             | Yes     | Comparison-based       |
| **Merge Sort**     | O(n log n)  | O(n log n)    | O(n log n)  | O(n)             | Yes     | Comparison-based       |
| **Quick Sort**     | O(n log n)  | O(n log n)    | O(n²)       | O(log n)         | No      | Comparison-based       |
| **Counting Sort**  | O(n + k)    | O(n + k)      | O(n + k)    | O(k + n)         | Yes     | Non-comparison-based   |

---
### 🔵 Key Observations:
- **Counting Sort is faster than O(n log n) sorting algorithms** when `k` (max value) is small compared to `n`.
- If `k ≈ n`, then Counting Sort behaves almost **linear O(n)**.
- **Comparison-based sorting algorithms (like Merge Sort, QuickSort)** cannot go faster than O(n log n) — due to a proven lower bound.

---

## ⚡ When to Use Counting Sort

✅ Use Counting Sort when:
- You are sorting **only integers**.
- Maximum element value (`k`) is **not too large** (e.g., \( k \leq 10^6 \)).
- Memory usage (O(k)) is acceptable.

🚫 Avoid Counting Sort when:
- Numbers have a **huge range** (e.g., max value \(10^9\)).
- Sorting floating point numbers or very large numbers.
- Memory is highly constrained.

---

## 📥 How to Run

1. Clone the repository or copy the code.
2. Compile using:
   ```bash
   g++ -o countingsort countingsort.cpp
   ```
3. Execute:
   ```bash
   ./countingsort
   ```
4. Provide input:
   - First line: Number of elements (`n`)
   - Next line: `n` integers

---

## 🧩 Example

**Input:**
```
5
4 2 2 8 3
```
**Output:**
```
2 2 3 4 8
```

---

## 🛠 Code Overview

<details>
<summary>Click to view full C++ code</summary>

```cpp
#include<bits/stdc++.h>
using namespace std;

vector<int> countingsort(vector<int> &a)
{
    if (a.empty()) return {};

    int s = a.size();
    int m = 0;
    for(int i = 0; i < s; i++)
    {
        m = max(m, a[i]);
    }

    vector<int> countnum(m+1, 0);
    for(int i = 0; i < s; i++)
        countnum[a[i]]++;

    for(int i = 1; i <= m; i++)
        countnum[i] += countnum[i-1];

    vector<int> outputarray(s);
    for(int i = s-1; i >= 0; i--)
    {
        outputarray[countnum[a[i]]-1] = a[i];
        countnum[a[i]]--;
    }
    return outputarray;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    vector<int> op = countingsort(arr);

    for(int i = 0; i < n; i++)
        cout << op[i] << " ";

    return 0;
}
```

</details>

---

## 📚 Fun Fact: Why Comparison Sorts Can't Beat O(n log n)

There’s a **mathematical proof**: any algorithm based **only on comparisons** must take at least O(n log n) comparisons in the worst case.  
Counting Sort avoids this by **not comparing** — it uses counting instead, thus bypassing the O(n log n) lower bound.

---

## 📄 License

This project is licensed under the [MIT License](LICENSE).

---

# 🎯 Conclusion

- **Counting Sort** is extremely fast for **small-range integers** — almost linear time.
- It's **faster than any comparison-based sort** when conditions are right.
- But be careful about **huge ranges** and **high memory** use!

---


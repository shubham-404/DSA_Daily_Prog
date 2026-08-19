# Infix to Postfix Conversion

Convert a given **infix expression** into its **postfix (Reverse Polish Notation)** form using a stack.

**Example**

```
Infix   : a+b*(c^d-e)^(f+g*h)-i
Postfix : abcd^e-fgh*+^*+i-
```

---

## Approach (Stack-Based)

1. **Operands (A–Z, a–z, 0–9)**

   * Directly append to the output string.

2. **Opening Parenthesis `(`**

   * Push onto the stack.

3. **Closing Parenthesis `)`**

   * Pop operators from the stack and append to output until `(` is found.
   * Pop and discard the `(`.

4. **Operators (`+ - * / % ^`)**

   * While the stack is not empty:

     * Pop operators with **higher precedence**
     * Pop operators with **equal precedence only if the current operator is left-associative**
   * Push the current operator onto the stack.

5. **End of Expression**

   * Pop all remaining operators from the stack to the output.

---

## Operator Rules

| Operator | Precedence | Associativity         |
| -------- | ---------- | --------------------- |
| `^`      | Highest    | **Right-associative** |
| `* / %`  | Medium     | Left-associative      |
| `+ -`    | Lowest     | Left-associative      |

---

##  Key Mistakes to Avoid (Important!)

###  Mistake 1: Treating `^` as Left-Associative

* `^` is **right-associative**
* **Do NOT pop operators of equal precedence when current operator is `^`**

❌ Wrong:

```cpp
priority[ch] <= priority[st.top()]
```

 Correct logic:

```cpp
priority[ch] < priority[st.top()] ||
(priority[ch] == priority[st.top()] && ch != '^')
```

---

### ❌ Mistake 2: Giving `'('` a Precedence Value

* `'('` should **never** be compared using precedence
* It must act only as a **stack delimiter**

❌ Wrong:

```cpp
{'(', 2}
```

 Correct:

* Do **not** include `'('` in the precedence map
* Always stop popping when `st.top() == '('`

---

## 🧪 Common Edge Case to Test

```
Input  : a^b^c
Output : abc^^
```

If this fails, your associativity logic is wrong.

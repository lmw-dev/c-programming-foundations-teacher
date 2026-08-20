# 第09讲 — 掌控C语言的“文本魔法”（字符数组、字符串本质与string.h库）

> **对应章节**：第6章(下) 字符数组与字符串高级处理  
> **对应课件**：《C语言程序设计》第09讲 PPT逐页文稿与教学设计（共20页·双书融合深度优化版）  
> **融合教材**：
> - 《C程序设计（第五版）》· 谭浩强 著（空字符 `'\0'` 哨兵原理、“烫烫烫”乱码深度解剖、凯撒加密）
> - 《C语言程序设计（第3版）》· 何钦铭 颜晖 主编（字符数组连续内存映像、`<string.h>` 四大金刚标准库实战、单词个数统计）
> - 湖南大学《程序设计》课件（`gets()` 缓冲区溢出历史漏洞、`fgets()` 现代工业级安全规范）  
> **课时设置**：4课时（180分钟）理实一体化大课  
> **核心指标**：达成**“懂本质（识哨兵）、能防错（避乱码）、会工具（用库函数）、能实战（写算法）”**的四维能力指标。

---

## 📂 代码资产与目录结构

```
lessons/L09_strings/
├── README.md                                # 本讲教学说明与全景导学指南
├── lecture-demo/                            # 课堂演示代码（教师现场讲解与演示）
│   ├── 9.1_string_len_copy.c                # 字符串内存剖析与安全复制：strlen vs sizeof、手写安全strcpy与'\0'防溢出 (PPT 第6, 7, 13, 14页)
│   └── 9.2_caesar_cipher.c                  # 凯撒密码环形加密器：字符逐位扫描、(c - 'a' + 3) % 26 模运算环形回绕、对称解密验证 (PPT 第18页)
├── starter/                                 # 学生起步模板（上机骨架与 TODO 指引）
│   ├── task1_string_len_copy_starter.c      # 任务1：字符串长度与安全复制模板 (PPT 第13~14页)
│   ├── task2_caesar_cipher_starter.c        # 任务2：凯撒加密与解密模板 (PPT 第18页)
│   └── task3_word_counter_starter.c         # 任务3：FSM 单词个数统计模板 (PPT 第17页)
├── exercises/                               # 当堂练习与评测
│   ├── exercises_09.md                      # 字符 vs 字符串正误判断、strlen vs sizeof 深度打表、strcmp 返回值预测、同伴黑盒测试单、小测 (PPT 第6, 13, 15, 16, 19, 20页)
│   └── exercise_fix_string_errors.c         # 专升本经典改错：漏给'\0'预留空间烫烫烫乱码、字符串直接赋值或双等号比较、gets无界溢出排雷 (PPT 第8, 11, 12, 15页)
└── solutions/                               # 教师参考答案（教师私有，不公开）
    ├── 9.3_word_counter.c                   # 任务3/实操2参考答案：有限状态机(FSM)统计单词数、fgets工业级防线与去尾部换行 (PPT 第11, 17页)
    └── exercises_09_answers.md              # 评测标准答案与专升本深度考点解析
```

---

## 🗺️ 代码资产与 PPT 页码映射

| 序号 | 资产源文件 | 对应 PPT 页码 | 教学定位 | 核心考点 / 技能点 |
|:---:|:---|:---:|:---|:---|
| 1 | [`9.1_string_len_copy.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L09_strings/lecture-demo/9.1_string_len_copy.c) | 第6, 7, 13, 14页 | 课上精讲：字符串内存与安全复制 | 单字符 `'A'` (1B) vs 字符串 `"A"` (2B)、`strlen` (数货) vs `sizeof` (量盒子)、手写带边界检查安全复制与显式 `'\0'` 封口 |
| 2 | [`9.2_caesar_cipher.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L09_strings/lecture-demo/9.2_caesar_cipher.c) | 第18页 | 密码学实战：凯撒密码 | 字符逐位扫描、`(c - 'a' + offset) % 26 + 'a'` 模运算环形回绕、对称加解密验证 |
| 3 | [`9.3_word_counter.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L09_strings/solutions/9.3_word_counter.c) | 第11, 17页 | 文本流解析：有限状态机与安全输入 | 彻底废弃 `gets()`，`fgets()` 工业级安全防线、`in_word` 状态突变 (0->1) 统计单词、多重空格鲁棒解析 |
| 4 | [`exercise_fix_string_errors.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L09_strings/exercises/exercise_fix_string_errors.c) | 第8, 11, 12, 15页 | 专升本经典改错：字符串四大雷区 | 漏给 `'\0'` 预留空间引发“烫烫烫”乱码、直接赋值或双等号比较地址、`strcat` 缓冲区空间不足 |

---

## 🏫 教学实施精细化指引

### 1. 单字符 `'A'` vs 字符串 `"A"` 物理真相（PPT 第6页）
```text
      字符 'A':                 字符串 "A":
   ┌──────────────┐           ┌──────────────┬──────────────┐
   │   65 (char)  │           │   65 (char)  │   0 ('\0')   │
   └──────────────┘           └──────────────┴──────────────┘
       占 1 字节                     占 2 字节 (物理真相)
```

### 2. `strlen` vs `sizeof` 对决（口诀：数货 vs 量盒子）（PPT 第13页）
- **`sizeof`**：C语言运算符，编译期计算，量的是**整个大箱子（数组）在内存中占用的物理总字节数**；
- **`strlen`**：库函数，运行期顺着内存一格格扫描，直到遇到 `'\0'` 踩刹车，数的是**有效字符个数**（不含 `'\0'`）。

### 3. `<string.h>` “四大金刚”底层时序（PPT 第12~16页）
- **`strlen(s)`**：遇 `'\0'` 停，返回字符数；
- **`strcpy(dest, src)`**：物理覆盖复制，`dest` 空间必须 $\ge \text{strlen}(src)+1$；
- **`strcat(dest, src)`**：定位 `dest` 的首个 `'\0'`，从该处开始覆盖拼接并在最后追加新的 `'\0'`；
- **`strcmp(s1, s2)`**：自左向右逐字符 PK ASCII 码值，$s1 < s2$ 返回负数，$s1 == s2$ 返回 0，$s1 > s2$ 返回正数。

### 4. 凯撒密码环形回绕数学机理（PPT 第18页）
$$\text{encrypted} = (c - \text{'a'} + \text{shift}) \pmod{26} + \text{'a'}$$
- 将 `'z'` (25) 加上 3 变成 28，$28 \pmod{26} = 2$，对应字母 `'c'`，实现优雅环形回绕。

---

## ⏱️ 4课时（180分钟）一体化课堂落地时间分配

| 课时 | 时长 | 教学环节 | 核心任务与对应 PPT |
|:---:|:---:|:---|:---|
| **第1课时** | 45 min | 字符数组本质与 '\0' 哨兵 | PPT 第1~8页：单字符 vs 字符串、物理内存映像、双引号文本魔法、"烫烫烫" 乱码现场解剖 |
| **第2课时** | 45 min | 字符串输入输出与安全防线 | PPT 第9~11页：`printf` / `puts` 规范、`scanf("%s")` 空格截断、彻底废弃 `gets()` 与 `fgets()` 工业级防线 |
| **第3课时** | 45 min | `<string.h>` 四大金刚精讲 | PPT 第12~16页：`strlen` vs `sizeof` 生死对决、`strcpy` 覆盖搬家、`strcat` 尾部合体、`strcmp` 字典序 PK |
| **第4课时** | 45 min | 算法实战：状态机与凯撒密码 | PPT 第17~20页：`9.3_word_counter` FSM 统计、`9.2_caesar_cipher` 上机实操、同伴极限黑盒测试、离堂小测 |

---

## 📊 代码资产状态

| 资产类别 | 包含文件 | 当前状态 | 备注 |
|:---|:---|:---:|:---|
| **课堂演示代码** | `9.1_string_len_copy.c`, `9.2_caesar_cipher.c` | **已定稿** | 2 份演示源文件全量通过编译测试 |
| **起步模板** | `task1_string_len_copy_starter.c`, `task2_caesar_cipher_starter.c`, `task3_word_counter_starter.c` | **已定稿** | 3 份上机任务骨架 |
| **当堂练习** | `exercises_09.md`, `exercise_fix_string_errors.c` | **已定稿** | 1 份测评题单 + 1 份改错实操 |
| **参考答案** | `9.3_word_counter.c`, `exercises_09_answers.md` | **已定稿** | 1 份代码答案 + 1 份题目解析 |

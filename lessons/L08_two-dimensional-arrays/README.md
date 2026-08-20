# 第08讲 — 升维思考：玩转矩阵与文本（二维数组、字符数组与阶段回收1）⭐

> **对应章节**：第6章(下) 二维数组与字符数组 + 前半学期阶段综合回收  
> **对应课件**：《C语言程序设计》第08讲 PPT逐页文稿与教学设计（共20页·双书融合深度优化版）  
> **融合教材**：
> - 《C程序设计（第五版）》· 谭浩强 著（二维数组行优先连续线性存放、矩阵转置、打擂台求最值与坐标）
> - 《C语言程序设计（第3版）》· 何钦铭 颜晖 主编（多小队工资表矩阵、字符数组初始化双重人格、回文字符串双指针向心判定）
> - 湖南大学《程序设计》课件（丢失 `'\0'` 哨兵引发“烫烫烫”内存乱码、阶段知识大串联）  
> **课时设置**：4课时（180分钟）理实一体化大课（阶段回收节点 1）  
> **核心指标**：达成**“能声明（知定义）、懂物理（知存储）、会计算（通算法）、识结束（破标志）、能实操（会调试）”**的五维能力指标。

---

## 📂 代码资产与目录结构

```
lessons/L08_two-dimensional-arrays/
├── README.md                                # 本讲教学说明与全景导学指南（阶段回收节点 1）
├── lecture-demo/                            # 课堂演示代码（教师现场讲解与演示）
│   ├── 8.1_matrix_transpose.c               # 物理内存连续性验证与矩阵转置：打印%p证明Row-Major Order、b[j][i]=a[i][j] (PPT 第5, 8页)
│   └── 8.2_matrix_max.c                     # 矩阵打擂台求最值与坐标：双重循环、max_row/max_col 坐标锁定器 (PPT 第9~10页)
├── starter/                                 # 学生起步模板（上机骨架与 TODO 指引）
│   ├── task1_matrix_transpose_starter.c     # 任务1：矩阵转置模板 (PPT 第8页)
│   ├── task2_matrix_max_starter.c           # 任务2：二维矩阵打擂台与坐标锁定模板 (PPT 第9~10页)
│   └── task3_palindrome_starter.c           # 任务3：双指针向心逼近回文判定模板 (PPT 第17~18页)
├── exercises/                               # 当堂练习与评测
│   ├── exercises_08.md                      # 二维定义正误判断、内存偏移公式计算、字符数组vs字符串字节对决、阶段自查表、小测 (PPT 第4, 6, 7, 11, 13, 15, 19, 20页)
│   └── exercise_fix_matrix_string_errors.c  # 专升本阶段大排雷：省略第二维报错、行列边界张冠李戴越界、字符数组漏'\0'烫烫烫乱码 (PPT 第6, 11, 15页)
└── solutions/                               # 教师参考答案（教师私有，不公开）
    ├── 8.3_palindrome_check.c               # 任务3/实操1参考答案：回文字符串两向逼近判定、'\0'原理剖析与安全输入 (PPT 第17~19页)
    └── exercises_08_answers.md              # 评测标准答案与专升本深度考点解析
```

---

## 🗺️ 代码资产与 PPT 页码映射

| 序号 | 资产源文件 | 对应 PPT 页码 | 教学定位 | 核心考点 / 技能点 |
|:---:|:---|:---:|:---|:---|
| 1 | [`8.1_matrix_transpose.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L08_two-dimensional-arrays/lecture-demo/8.1_matrix_transpose.c) | 第5, 8页 | 课上精讲：内存真相与转置 | 打印 `%p` 证明行优先线性连续存储 (Row-Major Order)、第二维不可省略原理、`b[j][i]=a[i][j]` 矩阵转置 |
| 2 | [`8.2_matrix_max.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L08_two-dimensional-arrays/lecture-demo/8.2_matrix_max.c) | 第9~10页 | 算法演进：二维打擂台 | 二维空间最值检索、`max_row`/`max_col` 坐标锚点锁定、初始擂主必须为 `matrix[0][0]` 杜绝全负数漏洞 |
| 3 | [`8.3_palindrome_check.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L08_two-dimensional-arrays/solutions/8.3_palindrome_check.c) | 第17~19页 | 阶段大综合：文本与回文 | 字符数组与 `'\0'` 结束符物理机制、`scanf("%99s")` 防缓冲区溢出、双指针向心对碰判定算法 |
| 4 | [`exercise_fix_matrix_string_errors.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L08_two-dimensional-arrays/exercises/exercise_fix_matrix_string_errors.c) | 第6, 11, 15页 | 阶段大排雷：三大经典漏洞 | 二维省略第二维报错、双重循环行列边界张冠李戴、字符数组漏 `'\0'` 引发“烫烫烫”内存乱码 |

---

## 🏫 教学实施精细化指引

### 1. 二维数组按行连续线性存放（Row-Major Order）（PPT 第5页）
```text
 a[3][4] 在计算机内存底层的物理映像（完全线性连续）：
 ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
 │a[0][0]│a[0][1]│a[0][2]│a[0][3]│a[1][0]│a[1][1]│a[1][2]│a[1][3]│a[2][0]│a[2][1]│a[2][2]│a[2][3]│
 └───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘
 └────────── 第 0 行 ───────────┘└────────── 第 1 行 ───────────┘└────────── 第 2 行 ───────────┘
```
- **寻址公式**：$\text{Address}(a[i][j]) = \text{Base} + (i \times \text{Columns} + j) \times \text{sizeof(type)}$。
- **列数不可省**：定义时必须指定第二维列数，否则编译器无法计算每行的跨度步长。

### 2. 字符数组 vs 字符串（PPT 第13~15页）
| 形式 | 物理字节数 | 内存末尾状态 | printf("%s") 表现 |
|:---|:---:|:---|:---|
| `char s1[5] = "China";` | 5 字节 | **无 `'\0'` 空间**（被关在门外） | 冲出边界在栈内存裸奔，输出“烫烫烫”乱码 |
| `char s2[6] = "China";` | 6 字节 | **末尾包含 `'\0'` 哨兵** | 正常遇到 `'\0'` 刹车，安全输出 `China` |

### 3. 双指针向心对碰回文判定算法（PPT 第17~18页）
- **首指针 $i=0$，尾指针 $j=\text{length}-1$**；
- 循环条件：`while (i < j)`；
- 只要 `str[i] != str[j]`，立即 `is_palindrome = 0; break;` 提前制动。

---

## ⏱️ 4课时（180分钟）一体化课堂落地时间分配

| 课时 | 时长 | 教学环节 | 核心任务与对应 PPT |
|:---:|:---:|:---|:---|
| **第1课时** | 45 min | 二维数组诞生与行优先线性存储 | PPT 第1~7页：多小队工资表模型、二维定义天条、按行线性物理内存 (%p)、初始化四姿势、下标越界排雷 |
| **第2课时** | 45 min | 矩阵转置与打擂台双维坐标锁定 | PPT 第8~11页：`8.1_matrix_transpose.c` 演示、`8.2_matrix_max.c` 擂台坐标锚点锁定、行列张冠李戴避坑 |
| **第3课时** | 45 min | 字符数组、'\0' 哨兵与烫烫烫乱码 | PPT 第12~16页：字符数组物理 ASCII、字符串结束符 `'\0'` 刹车片、"烫烫烫" 乱码成因、scanf vs gets |
| **第4课时** | 45 min | 阶段综合实战：回文判定与阶段测试 | PPT 第17~20页：`8.3_palindrome_check` 上机、同伴极限黑盒测试、阶段自查、离堂小测、前半学期回收小结 |

---

## 📊 代码资产状态

| 资产类别 | 包含文件 | 当前状态 | 备注 |
|:---|:---|:---:|:---|
| **课堂演示代码** | `8.1_matrix_transpose.c`, `8.2_matrix_max.c` | **已定稿** | 2 份演示源文件全量通过编译测试 |
| **起步模板** | `task1_matrix_transpose_starter.c`, `task2_matrix_max_starter.c`, `task3_palindrome_starter.c` | **已定稿** | 3 份上机任务骨架 |
| **当堂练习** | `exercises_08.md`, `exercise_fix_matrix_string_errors.c` | **已定稿** | 1 份测评题单 + 1 份改错实操 |
| **参考答案** | `8.3_palindrome_check.c`, `exercises_08_answers.md` | **已定稿** | 1 份代码答案 + 1 份题目解析 |

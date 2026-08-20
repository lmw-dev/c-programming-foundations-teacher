# 第13讲 — 驾驭连续内存的高速轨道（指针与数组、字符串及综合应用）

> **对应章节**：第8章 善于利用指针（8.3 指针与一维数组/二维数组、8.4 指针与字符串）  
> **对应课件**：《C语言程序设计》第13讲 PPT逐页文稿与教学设计（共20页·双书融合工程实践版）  
> **融合教材**：
> - 《C程序设计（第五版）》· 谭浩强 著（二维数组行指针与列指针基类型本质区别、时序运算符结合性）
> - 《C语言程序设计（第3版）》· 何钦铭 颜晖 主编（指针双向碰头原地逆序、字符指针电码加密、`fgets` 安全防线）
> - 湖南大学《程序设计》课件（四大剑客等价矩阵、指针移动法最高运行效率、Row-Major 线性长蛇阵）
> - 北京石油化工学院《C语言程序设计》课件（行指针双解引用推导、字符指针只读常量区物理边界）  
> **课时设置**：4课时（180分钟）理实一体化大课  
> **核心指标**：达成**“能说清（物理映像）、能读懂（时序对决）、能写出（指针指针化）、能测试（黑盒对抗）”**的四维能力指标。

---

## 📂 代码资产与目录结构

```
lessons/L13_pointers-and-arrays/
├── README.md                                # 本讲教学说明与全景导学指南
├── lecture-demo/                            # 课堂演示代码（教师现场讲解与演示）
│   ├── 13.1_array_reverse_ptr.c             # 双指针向心原地逆序：纯指针算术、丢弃下标[i]、步长自适应 (PPT 第4, 5, 6, 16页)
│   └── 13.2_matrix_ptr_walking.c            # 二维行/列指针自适应步长实测：Row-Major线性内存、col_ptr步长4B vs row_ptr步长16B (PPT 第9, 10, 11, 12页)
├── starter/                                 # 学生起步模板（上机骨架与 TODO 指引）
│   ├── task1_array_reverse_ptr_starter.c    # 任务1：双指针向心逆序模板 (PPT 第16页)
│   ├── task2_matrix_walker_starter.c        # 任务2：行指针与列指针遍历模板 (PPT 第11, 12页)
│   └── task3_string_cipher_starter.c        # 任务3：字符指针电码加密器模板 (PPT 第17, 18页)
├── exercises/                               # 当堂练习与评测
│   ├── exercises_13.md                      # 数组名找茬、运算符时序对决计算、二维行/列指针寻址抢答、同伴测试、小测 (PPT 第4, 7, 8, 11, 12, 13, 19, 20页)
│   └── exercise_fix_pointer_array_errors.c  # 专升本经典改错：常量数组名自增报错、字符指针未分配栈空间scanf、只读常量区改写段错误 (PPT 第4, 13, 14页)
└── solutions/                               # 教师参考答案（教师私有，不公开）
    ├── 13.3_string_cipher.c                 # 任务3/实操参考答案：基于字符指针滑动扫描的电码加密器 (fgets防溢出 + '\0'哨兵扫描) (PPT 第13, 14, 17, 18页)
    └── exercises_13_answers.md              # 评测标准答案与专升本深度考点解析
```

---

## 🗺️ 代码资产与 PPT 页码映射

| 序号 | 资产源文件 | 对应 PPT 页码 | 教学定位 | 核心考点 / 技能点 |
|:---:|:---|:---:|:---|:---|
| 1 | [`13.1_array_reverse_ptr.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L13_pointers-and-arrays/lecture-demo/13.1_array_reverse_ptr.c) | 第4, 5, 6, 16页 | 课上精讲：指针算术与向心原地逆序 | 数组名作为地址常量、指针加法步长自适应（`arr + size - 1` 物理偏移 `(size-1)*4` 字节）、双指针对向碰头原地对调 |
| 2 | [`13.2_matrix_ptr_walking.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L13_pointers-and-arrays/lecture-demo/13.2_matrix_ptr_walking.c) | 第9, 10, 11, 12页 | 深度解密：二维数组行/列指针步长对决 | Row-Major 行优先连续线性平铺、列指针 `col_ptr+1` 步长 4B vs 行指针 `row_ptr+1` 步长 16B、四种多维寻址等价式 |
| 3 | [`13.3_string_cipher.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L13_pointers-and-arrays/solutions/13.3_string_cipher.c) | 第13, 14, 17, 18页 | 工业实战：字符指针滑动扫描电码加密 | 栈区字符数组（可读写） vs 只读常量区（写保护闪退）、`fgets` 缓冲区安全防线、`\0` 隐形结束哨兵扫描 |
| 4 | [`exercise_fix_pointer_array_errors.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L13_pointers-and-arrays/exercises/exercise_fix_pointer_array_errors.c) | 第4, 13, 14页 | 专升本经典改错：指针与数组三大地雷 | 数组名常量执行 `a++` 报错、未分配栈空间的字符指针传入 `scanf` 导致崩溃、字符串常量区强行改写段错误 |

---

## 🏫 教学实施精细化指引

### 1. 元素引用的“四大剑客等价矩阵”（PPT 第6页）
$$\text{a}[i] \iff *(a + i) \iff *(p + i) \iff p[i]$$
- **效率优势**：指针自增移动法 `for (p=a; p<a+N; p++)` 免去了 CPU 乘法器计算物理偏移，运行效率最高！

### 2. 运算符时序大对决三剑客（PPT 第7页）
1. `*p++`（或 `*(p++)`）：后置自增，**先取 `*p` 旧值使用，后指针 `p` 物理向右滑动 1 个步长**；
2. `*(++p)`：前置自增，**指针 `p` 先向右滑动 1 个步长，后解引用取新值**；
3. `(*p)++`：圆括号最高优先级，**指针 `p` 位置绝对不动，所指内存格子里面的数值自增 1**。

### 3. 二维数组行指针 vs 列指针（PPT 第10页）
```text
  行指针 (a+1): 指向一整行，步长为 4 * sizeof(int) = 16 字节
  列指针 *(a+1): 指向第1行第0列单元素，步长为 1 * sizeof(int) = 4 字节
  💡 数值上 a+1 == *(a+1) (首地址相同)，但基类型不同、步长不同！
```

---

## ⏱️ 4课时（180分钟）一体化课堂落地时间分配

| 课时 | 时长 | 教学环节 | 核心任务与对应 PPT |
|:---:|:---:|:---|:---|
| **第1课时** | 45 min | 数组名物理真相与指针算术自适应 | PPT 第1~6页：数组名地址常量、指针加减步长自适应计算、四大剑客等价矩阵、三种遍历效率对比 |
| **第2课时** | 45 min | 运算符时序大对决与二维长蛇阵解密 | PPT 第7~12页：`*p++` vs `*(++p)` vs `(*p)++` 时序拆解、Row-Major 线性内存、行指针 vs 列指针抢答 |
| **第3课时** | 45 min | 字符指针、只读常量区与安全防线 | PPT 第13~15页：栈区可写 vs 常量区只读、野字符指针 `scanf` 闪退大血案、`fgets` 工业防线、指针数组 |
| **第4课时** | 45 min | 上机工坊：双指针逆序与电码加密器 | PPT 第16~20页：`13.1_array_reverse_ptr`、`13.3_string_cipher` 纯指针扫描、同伴极限对抗、离堂小测 |

---

## 📊 代码资产状态

| 资产类别 | 包含文件 | 当前状态 | 备注 |
|:---|:---|:---:|:---|
| **课堂演示代码** | `13.1_array_reverse_ptr.c`, `13.2_matrix_ptr_walking.c` | **已定稿** | 2 份演示源文件全量通过编译测试 |
| **起步模板** | `task1_array_reverse_ptr_starter.c`, `task2_matrix_walker_starter.c`, `task3_string_cipher_starter.c` | **已定稿** | 3 份上机任务骨架 |
| **当堂练习** | `exercises_13.md`, `exercise_fix_pointer_array_errors.c` | **已定稿** | 1 份测评题单 + 1 份改错实操 |
| **参考答案** | `13.3_string_cipher.c`, `exercises_13_answers.md` | **已定稿** | 1 份代码答案 + 1 份题目解析 |

# 第02讲 — 探秘C语言的“数据收纳盒”：标识符、常量、变量与基本数据类型

> **对应章节**：第2章(上) 标识符、常量与变量、基本数据类型  
> **对应课件**：《C语言程序设计》第02讲 PPT逐页文稿与教学设计（共19页·双书融合深度优化版）  
> **融合教材**：
> - 《C程序设计（第五版）》· 谭浩强 著（底层机制：内存补码、常变量与截断警告）
> - 《C语言程序设计（第3版）》· 何钦铭 颜晖 主编（任务驱动：“先声明，后使用”法则）
> - 湖南大学《程序设计》课件（八/十六进制常量陷阱与物理映像）  
> **课时设置**：4课时（180分钟）理实一体化课堂  
> **核心指标**：达成**“能起名（识规则）、能划分（识常变）、能分类（识类型）、能测量（用 sizeof）”**的四维学习指标。

---

## 📂 代码资产与目录结构

```
lessons/L02_data-types/
├── README.md                                # 本讲教学说明与导学指南（本文件）
├── lecture-demo/                            # 课堂演示代码（教师现场讲解与演示）
│   ├── 2.1_ghost_value.c                    # 幽灵垃圾值与内存复用机理 (PPT 第11页)
│   └── 2.2_ascii_mask.c                     # ASCII 码“面具实验”与 char 本质 (PPT 第16页)
├── starter/                                 # 学生起步模板（上机骨架与 TODO 指引）
│   ├── task1_sizeof_ruler_starter.c         # 任务1：sizeof 内存量地尺探秘模板 (PPT 第17~18页)
│   └── task2_price_calc_starter.c           # 任务2：字母转换与符号常量价格计算器 (PPT 第8、19页)
├── exercises/                               # 当堂练习与评测
│   ├── exercises_02.md                      # 名字找茬、避坑演练与离堂小测题单 (PPT 第6、12、19页)
│   └── exercise_identifier_check.c          # 经典标识符与变量语法辨析排雷
└── solutions/                               # 教师参考答案（教师私有，不公开）
    ├── 2.3_sizeof_ruler.c                   # 任务1参考答案：sizeof 物理量地尺 (PPT 第18页)
    ├── 2.4_uppercase_swap.c                 # 任务2参考答案：大写转小写与苹果计算器 (PPT 第19页)
    └── exercises_02_answers.md              # 评测标准答案与专升本深度考点解析
```

---

## 🗺️ 代码资产与 PPT 页码映射

| 序号 | 资产源文件 | 对应 PPT 页码 | 教学定位 | 核心考点 / 技能点 |
|:---:|:---|:---:|:---|:---|
| 1 | [`2.1_ghost_value.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L02_data-types/lecture-demo/2.1_ghost_value.c) | 第11页 | 课上精讲：内存复用与初始化 | 局部变量未初始化残留值、`volatile` 读取、赋初值必要性 |
| 2 | [`2.2_ascii_mask.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L02_data-types/lecture-demo/2.2_ascii_mask.c) | 第16页 | 课上精讲：字符型的本质 | `char` 1 字节整数本质、`%c` vs `%d` 视角、ASCII 码映射、字符加法 |
| 3 | [`task1_sizeof_ruler_starter.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L02_data-types/starter/task1_sizeof_ruler_starter.c)<br>[`2.3_sizeof_ruler.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L02_data-types/solutions/2.3_sizeof_ruler.c) | 第17~18页 | 上机实操：sizeof 量地尺 | `sizeof` 运算符、测量变量与类型字节数、平台与编译器尺寸差异 |
| 4 | [`task2_price_calc_starter.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L02_data-types/starter/task2_price_calc_starter.c)<br>[`2.4_uppercase_swap.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L02_data-types/solutions/2.4_uppercase_swap.c) | 第8、19页 | 课后挑战：字符运算与符号常量 | 大小写 ASCII 偏移（+32）、`#define` 符号常量、`scanf` 与 `%.2f` 输出 |

---

## 🏫 教学实施精细化指引

### 1. 标识符命名的“四大天条”（PPT 第5~6页）
- **法条 1**：组成成分——只能由**字母（A-Z, a-z）、数字（0-9）和下划线（_）**组成。
- **法条 2**：开头限制——**首字符必须为字母或下划线**，绝对不能以数字开头！
- **法条 3**：大小写敏感——C 语言严格区分大小写（`score` 与 `Score` 是两个完全不同的变量）。
- **法条 4**：关键字避让——绝对不能使用 C 语言保留的 32 个关键字（如 `int`、`char`、`return`）。
- **行业素养**：提倡“见名知意”，推荐使用蛇形命名法 `student_age` 或小驼峰 `studentAge`，严禁拼音英文混用。

### 2. 变量的本质：内存“收纳盒”物理映像（PPT 第9~10页）
```text
            变量在计算机内存中的物理映像:
 ┌─────────────────────────────────────────────────────────┐
 │ 内存地址: 0x002BF7A0  (物理空间的门牌号)                 │
 ├─────────────────────────────────────────────────────────┤
 │ 存储空间: 00000000 00000000 00000000 00001010 (占4字节)   │
 ├─────────────────────────────────────────────────────────┤
 │ 编码/格式: 二进制补码 (存储格式: 定点整型)               │
 ├─────────────────────────────────────────────────────────┤
 │ 变量名标签: score                                       │
 └─────────────────────────────────────────────────────────┘
```
- **核心法则**：**“先声明，后使用”**！告诉编译器在内存中划定空间大小与编码规则。

### 3. 经典避坑与排雷对照表（PPT 第12、15、16页）

| 错误模式 | 典型错误代码 | 报错现象 / 风险 | 正确规范写法 |
|:---|:---|:---|:---|
| **连等声明赋初值** | `int a = b = c = 3;` | 编译报错：`b`、`c` 未声明 | `int a, b, c; a = b = c = 3;` |
| **同名重复定义** | `int x = 1; float x = 2.0;` | 编译报错：重定义符号 | 重命名区分类型：`int x_int; float x_float;` |
| **未初始化读垃圾值** | `int score; printf("%d", score);` | 输出随机负数（幽灵垃圾值） | 声明即初始化：`int score = 0;` |
| **双精度截断警告** | `float pi = 3.14159;` | 警告：`truncation from 'double' to 'float'` | 显式添加单精度后缀：`float pi = 3.14159f;` |
| **字符与字符串混淆** | `char ch = "A";` | 编译报错：类型不匹配（双引号占2字节） | 单引号代表字符：`char ch = 'A';` |

---

## ⏱️ 4课时（180分钟）一体化课堂落地时间分配

| 课时 | 时长 | 教学环节 | 核心任务与对应 PPT |
|:---:|:---:|:---|:---|
| **第1课时** | 45 min | 标识符天条与找茬对决 | PPT 第1~7页：复习导入、标识符四大天条、名字找茬 PK、行业命名规范 |
| **第2课时** | 45 min | 常量变量与内存收纳盒 | PPT 第8~12页：符号常量与常变量、内存物理映像、先声明后使用、`2.1_ghost_value.c` 演示 |
| **第3课时** | 45 min | 四大基本类型与物理底层 | PPT 第13~16页：`int` 补码与溢出、`float` 科学记数法、`2.2_ascii_mask.c` 字符面具实验 |
| **第4课时** | 45 min | sizeof 量地尺实战与小测 | PPT 第17~19页：学生上机完成 `2.3_sizeof_ruler`、当堂离堂小测、布置课后挑战 `2.4` |

---

## 📊 代码资产状态

| 资产类别 | 包含文件 | 当前状态 | 备注 |
|:---|:---|:---:|:---|
| **课堂演示代码** | `2.1_ghost_value.c`, `2.2_ascii_mask.c` | **已定稿** | 2 份演示源文件全量通过编译测试 |
| **起步模板** | `task1_sizeof_ruler_starter.c`, `task2_price_calc_starter.c` | **已定稿** | 2 份上机任务骨架 |
| **当堂练习** | `exercises_02.md`, `exercise_identifier_check.c` | **已定稿** | 1 份题单 + 1 份改错实操 |
| **参考答案** | `2.3_sizeof_ruler.c`, `2.4_uppercase_swap.c`, `exercises_02_answers.md` | **已定稿** | 2 份代码答案 + 1 份解析 |

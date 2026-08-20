# 第11讲 — 批量数据传递与变量的“生老病死”（数组参数、作用域、static与预处理）

> **对应章节**：第7章(下) 数组作为函数参数、变量存储类别 + 第9章 编译预处理  
> **对应课件**：《C语言程序设计》第11讲 PPT逐页文稿与教学设计（共20页·双书融合深度优化版）  
> **融合教材**：
> - 《C程序设计（第五版）》· 谭浩强 著（数组地址共享映像、静态/动态存储区物理模型、宏无脑文本自动展开）
> - 《C语言程序设计（第3版）》· 何钦铭 颜晖 主编（数组参数逆序存放、`static` 状态追踪、条件编译调试技巧）
> - 北京石油化工学院《C语言程序设计》课件（带参宏多重嵌套纯文本展开解密算法）
> - 湖南大学《程序设计》课件（数组名退化为指针定理、头文件防重定义保护网）  
> **课时设置**：4课时（180分钟）理实一体化大课  
> **核心指标**：达成**“能说清（懂本质）、能画出（识结界）、能避坑（防高频）、能测试（筑防线）”**的四维能力指标。

---

## 📂 代码资产与目录结构

```
lessons/L11_function-parameters-and-scope/
├── README.md                                # 本讲教学说明与全景导学指南
├── lecture-demo/                            # 课堂演示代码（教师现场讲解与演示）
│   ├── 11.1_array_reverse.c                 # 数组传参物理机制：首地址传递、sizeof(arr)退化验证、双指针原地逆序 (PPT 第4, 5, 18页)
│   └── 11.2_macro_trap.c                    # 编译预处理宏替换陷阱：无脑纯文本替换、SQUARE_BAD vs SQUARE_GOOD (PPT 第13, 14, 15页)
├── starter/                                 # 学生起步模板（上机骨架与 TODO 指引）
│   ├── task1_array_reverse_starter.c        # 任务1：数组传参与原地逆序模板 (PPT 第18页)
│   ├── task2_macro_trap_starter.c           # 任务2：带参宏防坑模板 (PPT 第14页)
│   └── task3_static_tracker_starter.c       # 任务3：基于 static 的日志追踪器模板 (PPT 第10, 19页)
├── exercises/                               # 当堂练习与评测
│   ├── exercises_11.md                      # 数组传参找茬、static打表追踪表、宏分步文本展开推演、同伴测试、小测 (PPT 第6, 7, 10, 12, 14, 15, 20页)
│   └── exercise_fix_param_macro_errors.c    # 专升本经典改错：二维形参省略列数、宏漏括号优先级夺权、auto局部变量计数失效 (PPT 第6, 10, 14页)
└── solutions/                               # 教师参考答案（教师私有，不公开）
    ├── 11.3_static_tracker.c                # 任务3/实操2参考答案：基于 static 静态局部变量的登录安全监控与警报系统 (PPT 第10, 11, 19页)
    └── exercises_11_answers.md              # 评测标准答案与专升本深度考点解析
```

---

## 🗺️ 代码资产与 PPT 页码映射

| 序号 | 资产源文件 | 对应 PPT 页码 | 教学定位 | 核心考点 / 技能点 |
|:---:|:---|:---:|:---|:---|
| 1 | [`11.1_array_reverse.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L11_function-parameters-and-scope/lecture-demo/11.1_array_reverse.c) | 第4, 5, 18页 | 课上精讲：数组传参本质与原地逆序 | 数组名自动退化为首元素指针、`sizeof(arr)` 退化为 8B/4B、实参形参共享内存原地换血、成对法则传 `size` |
| 2 | [`11.2_macro_trap.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L11_function-parameters-and-scope/lecture-demo/11.2_macro_trap.c) | 第13, 14, 15页 | 预处理机制：宏替换陷阱与防御 | 预处理纯文本无脑替换本质、`SQUARE_BAD(a+b)` 展开为 $a+b \times a+b$ 陷阱、带参宏双重括号黄金防错法则 |
| 3 | [`11.3_static_tracker.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L11_function-parameters-and-scope/solutions/11.3_static_tracker.c) | 第10, 11, 19页 | 工业实战：静态局部变量状态持久化 | `static` 静态局部变量只初始化一次、存储在静态数据区、跨函数调用状态保留、代替易污染全局变量 |
| 4 | [`exercise_fix_param_macro_errors.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L11_function-parameters-and-scope/exercises/exercise_fix_param_macro_errors.c) | 第6, 10, 14页 | 专升本经典改错：数组参数与宏三大陷阱 | 二维数组形参漏列数报错、宏末尾加分号灾难、宏无括号优先级错乱、`auto` 变量每次归零 |

---

## 🏫 教学实施精细化指引

### 1. 数组作为函数参数的物理共享模型（PPT 第4~5页）
```text
 实参数组 a (在 main 中)
 ┌──────────────┬──────────────┬──────────────┐
 │    a[0]      │    a[1]      │    a[2]      │  ---> 起始物理地址: 1000
 └──────────────┴──────────────┴──────────────┘
       ▲
       │  (通过首地址 1000 强行绑定，共占同一段物理内存单元！)
       ▼
 形参数组 arr (在 reverse_array 中)
 ┌──────────────┬──────────────┬──────────────┐
 │   arr[0]     │   arr[1]     │   arr[2]     │  ---> 接收的地址指针: 1000
 └──────────────┴──────────────┴──────────────┘
```
- **`sizeof` 陷阱**：主函数 `sizeof(numbers)` 是 40 字节，而子函数 `sizeof(arr)` 退化为指针大小（8 字节或 4 字节）。
- **成对法则**：传递数组名时，必须附带一个表示长度的 `int size` 参数。

### 2. 编译预处理宏定义的“双重圆括号黄金法则”（PPT 第14页）
- **法则 1**：每个形参必须带圆括号，如 `(x)`、`(y)`；
- **法则 2**：宏表达式整体必须带圆括号，如 `((x) * (y))`。

---

## ⏱️ 4课时（180分钟）一体化课堂落地时间分配

| 课时 | 时长 | 教学环节 | 核心任务与对应 PPT |
|:---:|:---:|:---|:---|
| **第1课时** | 45 min | 数组作为函数参数的物理真相 | PPT 第1~7页：双书换血死局与破局、首地址传递共享内存、形参数组伪装者、二维列数不可省天条 |
| **第2课时** | 45 min | 内存三区划分与 static 三重人格 | PPT 第8~12页：作用域结界、静态区vs栈区、`static` 局部变量单次初始化续命、Trace Table 打表跟踪 |
| **第3课时** | 45 min | 编译预处理、带参宏与夺命括号 | PPT 第13~17页：纯文本无脑替换本质、宏优先级陷阱、北石化分步宏展开、`#include` 路径、条件编译断路器 |
| **第4课时** | 45 min | 上机实操：原地逆序与安全追踪器 | PPT 第18~20页：`11.1_array_reverse` 上机、`11.3_static_tracker` 状态监控、同伴黑盒测试、离堂小测 |

---

## 📊 代码资产状态

| 资产类别 | 包含文件 | 当前状态 | 备注 |
|:---|:---|:---:|:---|
| **课堂演示代码** | `11.1_array_reverse.c`, `11.2_macro_trap.c` | **已定稿** | 2 份演示源文件全量通过编译测试 |
| **起步模板** | `task1_array_reverse_starter.c`, `task2_macro_trap_starter.c`, `task3_static_tracker_starter.c` | **已定稿** | 3 份上机任务骨架 |
| **当堂练习** | `exercises_11.md`, `exercise_fix_param_macro_errors.c` | **已定稿** | 1 份测评题单 + 1 份改错实操 |
| **参考答案** | `11.3_static_tracker.c`, `exercises_11_answers.md` | **已定稿** | 1 份代码答案 + 1 份题目解析 |

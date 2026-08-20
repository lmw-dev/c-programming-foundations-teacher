# 第03讲 — 程序底层的“算术链条”与“顺序执行”：运算符、混合运算、短路求值与顺序程序设计

> **对应章节**：第2章(下) 运算符与表达式 + 第3章 顺序结构程序设计(完成)  
> **对应课件**：《C语言程序设计》第03讲 PPT逐页文稿与教学设计（共20页·理实一体深度融合版）  
> **融合教材**：
> - 《C程序设计（第五版）》· 谭浩强 著（IPO 模式、自增自减物理流向与复合赋值）
> - 《C语言程序设计（第3版）》· 何钦铭 颜晖 主编（温度转换、两数计算器与利息计算等趣味项目驱动）
> - 湖南大学《程序设计》课件（自动类型提升流向、短路求值电路模型与运算符优先级排雷）  
> **课时设置**：4课时（180分钟）理实一体化课堂  
> **核心指标**：达成**“能计算（识天条）、能看透（识类型）、能避坑（识自增）、能设计（构顺序）”**的四维学习指标。

---

## 📂 代码资产与目录结构

```
lessons/L03_sequential-programming/
├── README.md                                # 本讲教学说明与导学指南（本文件）
├── lecture-demo/                            # 课堂演示代码（教师现场讲解与演示）
│   ├── 3.1_temp_convert.c                   # 华氏转摄氏：5/9整除截断地雷 vs 5.0/9正解对比 (PPT 第14页)
│   └── 3.2_calculator.c                     # 两数多功能计算器：精确商强转与带符号取模 (PPT 第16页)
├── starter/                                 # 学生起步模板（上机骨架与 TODO 指引）
│   ├── task1_temp_convert_starter.c         # 任务1：华氏转摄氏与整除避坑模板 (PPT 第14页)
│   ├── task2_calculator_starter.c           # 任务2：两数多功能计算器模板 (PPT 第16页)
│   └── task3_bank_interest_starter.c        # 任务3：银行复利与数学库 pow() 模板 (PPT 第19页)
├── exercises/                               # 当堂练习与评测
│   ├── exercises_03.md                      # 天条速算、短路推演、同伴互评测试单、离堂小测 (PPT 第4, 6, 8, 17, 18页)
│   └── exercise_fix_scanf_errors.c          # 专升本经典改错：漏写&、5/9截断与 double 格式符排雷
└── solutions/                               # 教师参考答案（教师私有，不公开）
    ├── 3.3_bank_interest.c                  # 课后挑战参考答案：银行复利计算器与 math.h pow() (PPT 第19页)
    └── exercises_03_answers.md              # 评测标准答案与专升本深度考点解析
```

---

## 🗺️ 代码资产与 PPT 页码映射

| 序号 | 资产源文件 | 对应 PPT 页码 | 教学定位 | 核心考点 / 技能点 |
|:---:|:---|:---:|:---|:---|
| 1 | [`3.1_temp_convert.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L03_sequential-programming/lecture-demo/3.1_temp_convert.c) | 第14~15页 | 课上精讲：除法截断与 scanf 排雷 | `5/9` 截断为 0 原理、`5.0f/9.0f` 隐式提升、`scanf` 取地址符 `&` 内存机理 |
| 2 | [`3.2_calculator.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L03_sequential-programming/lecture-demo/3.2_calculator.c) | 第16~17页 | 当堂任务：两数多功能计算器 | 5 大算术运算、`(double)` 强制类型转换求精确商、带符号取模天条 |
| 3 | [`3.3_bank_interest.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L03_sequential-programming/solutions/3.3_bank_interest.c) | 第19页 | 课后挑战：银行复利计算器 | `<math.h>` 幂函数 `pow()`、`double` 与 `%lf` 高精度金融计算、Linux 下 `-lm` 链接常识 |
| 4 | [`exercise_fix_scanf_errors.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L03_sequential-programming/exercises/exercise_fix_scanf_errors.c) | 第14~15页 | 升本改错：输入输出与精度排雷 | `scanf` 缺 `&` 闪退排查、圆面积计算公式、`double` 占位符匹配 |

---

## 🏫 教学实施精细化指引

### 1. 核心算术天条（PPT 第4页）
- **除法天条 (`/`)**：
  - 整数除整数 $\rightarrow$ 结果必为整数（直接舍弃小数，如 `5 / 2 = 2`）。
  - 只要一侧为浮点数 $\rightarrow$ 自动提升为浮点除法（如 `5.0 / 2 = 2.5`）。
- **取模天条 (`%`)**：
  - 操作数必须为纯整数（`12.5 % 3` ❌ 编译报错）。
  - **余数的正负号严格与被除数（前数）一致**（例：`-5 % 3 = -2`，`5 % -3 = 2`）。

### 2. 逻辑短路电路模型（PPT 第8页）
- **`a && b` (逻辑与短路)**：若左边 `a` 为假 (0)，右边 `b` **彻底不执行**。
- **`a || b` (逻辑或短路)**：若左边 `a` 为真 (非0)，右边 `b` **彻底不执行**。
- **经典翻车案例**：`c = a++ && (b = 3);`（当 $a=0$ 时，`b=3` 被短路忽略，`b` 保持原值）。

### 3. `scanf` 中 `&` 的物理内存本质（PPT 第13、15页）
```text
  【printf】 ───> 只需要把盒子里的内容(值)拿走复制 ───> 打印到屏幕
  【scanf】  ───> 必须拿着门牌号(&a 地址运算符) ────> 找到内存盒子并把键盘敲入的数据塞进去
```
- **警示**：若写 `scanf("%d", age);` 漏了 `&`，`scanf` 会将 `age` 中的未初始化**幽灵垃圾值**误认作内存地址强行写入，引发操作系统**段错误（Segmentation Fault）闪退**！

---

## ⏱️ 4课时（180分钟）一体化课堂落地时间分配

| 课时 | 时长 | 教学环节 | 核心任务与对应 PPT |
|:---:|:---:|:---|:---|
| **第1课时** | 45 min | 算术运算符与类型提升 | PPT 第1~5页：复习导入、除法与取模天条、混合类型自动提升流向图 |
| **第2课时** | 45 min | 自增自减、关系与逻辑短路 | PPT 第6~11页：`++i` 与 `i++` 内存流向、数学连写陷阱、短路求值电路模型、强转马甲 |
| **第3课时** | 45 min | 顺序结构与输入输出排雷 | PPT 第12~15页：IPO 模型、`printf` 与 `scanf` 双向奔赴、`3.1_temp_convert.c` 演示 |
| **第4课时** | 45 min | 计算器实战、互评与小测 | PPT 第16~20页：上机完成 `3.2_calculator`、同伴黑盒测试、离堂小测、布置作业 `3.3` |

---

## 📊 代码资产状态

| 资产类别 | 包含文件 | 当前状态 | 备注 |
|:---|:---|:---:|:---|
| **课堂演示代码** | `3.1_temp_convert.c`, `3.2_calculator.c` | **已定稿** | 2 份演示源文件全量通过编译测试 |
| **起步模板** | `task1_temp_convert_starter.c`, `task2_calculator_starter.c`, `task3_bank_interest_starter.c` | **已定稿** | 3 份上机任务骨架 |
| **当堂练习** | `exercises_03.md`, `exercise_fix_scanf_errors.c` | **已定稿** | 1 份测评题单 + 1 份改错实操 |
| **参考答案** | `3.3_bank_interest.c`, `exercises_03_answers.md` | **已定稿** | 1 份代码答案 + 1 份题目解析 |

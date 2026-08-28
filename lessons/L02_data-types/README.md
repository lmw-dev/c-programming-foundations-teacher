# 第02讲 — 探秘C语言的“数据收纳盒”：标识符、常量、变量与基本数据类型

> **对应章节**：第2章 标识符、常量与变量、基本数据类型与输入输出初识  
> **对应课件**：《C语言程序设计》第02讲 PPT逐页文稿与教学设计（共24页·四课时理实一体大满贯终极版）  
> **融合教材**：
> - 《C程序设计（第五版）》· 谭浩强 著（底层机制：内存补码、常变量与 double 隐式截断警告）
> - 《C语言程序设计（第3版）》· 何钦铭 颜晖 主编（任务驱动：“先声明，后使用”法则）
> - 湖南大学《程序设计》课件（八/十六进制常量陷阱与物理内存映像）  
> **课时设置**：4课时（180分钟）理实一体化课堂（2课时理论精讲 + 2课时上机实操工坊）  
> **核心指标**：达成**“能起名（识规则）、能划分（识常变）、能分类（识类型）、能测量（用 sizeof）”**的四维学习指标。

---

## 📂 代码资产与目录结构

```text
lessons/L02_data-types/
├── README.md                                     # 本讲教学说明与全景导学指南（本文件）
├── lecture-demo/                                 # 课堂演示代码（教师现场讲解与演示）
│   ├── menu_runner.c                             # ⭐ Visual Studio 专属一键全案交互运行器（零冲突，强烈推荐）
│   ├── 2.1_ghost_value.c                         # PPT 第11、20页：幽灵垃圾值与内存复用机理
│   ├── 2.2_int_overflow.c                        # ⭐ PPT 第15页：20000+20000 整型溢出与 (long) 强转提升
│   ├── 2.3_float_precision.c                     # ⭐ PPT 第16、22页：浮点数“近视眼”精度显微镜 (%.16f)
│   ├── 2.4_ascii_mask_caesar.c                   # ⭐ PPT 第17、21页：凯撒密码单字偏移与 ASCII 进制密电
│   ├── 2.5_sizeof_ruler.c                        # PPT 第18、19页：sizeof 内存物理量地尺标准演示
│   └── 2.6_supermarket_cashier.c                 # ⭐ PPT 第23页：爱心小超市符号常量智能收银结算单
├── starter/                                      # 学生起步模板（5 大递进式上机探究任务）
│   ├── task1_sizeof_ruler_starter.c              # 探究一：sizeof 寻找你电脑上的收纳盒规格
│   ├── task2_ghost_value_starter.c               # 探究二：捕捉幽灵垃圾值与安全赋初值
│   ├── task3_caesar_cipher_starter.c             # 探究三：凯撒密码单字偏移与 ASCII 密电还原
│   ├── task4_float_precision_starter.c           # 探究四：浮点数精度显微镜与物理误差分析
│   └── task5_supermarket_cashier_starter.c       # 探究五：爱心小超市符号常量智能收银结算单
├── exercises/                                    # 当堂练习与评测
│   ├── exercises_02.md                           # 名字找茬PK、避坑改错、溢出辨析与离堂小测
│   └── exercise_identifier_check.c               # 经典标识符与变量语法辨析排雷
└── solutions/                                    # 教师参考答案（教师私有，不公开）
    ├── task1_sizeof_ruler_solution.c             # 探究一参考答案
    ├── task2_ghost_value_solution.c              # 探究二参考答案
    ├── task3_caesar_cipher_solution.c            # 探究三参考答案
    ├── task4_float_precision_solution.c          # 探究四参考答案
    ├── task5_supermarket_cashier_solution.c      # 探究五参考答案
    ├── homework_02_solution.c                    # ⭐ PPT 第24页课后作业：黑客字母转换彩蛋
    └── exercises_02_answers.md                   # 评测标准答案与详细考点解析
```

---

## 🗺️ 代码资产与 24 页 PPT 映射表

| 序号 | 资产源文件 | 对应 PPT 页码 | 教学定位 | 核心考点 / 技能点 |
|:---:|:---|:---:|:---|:---|
| ⭐ | [`menu_runner.c`](lecture-demo/menu_runner.c) | 全讲综合 | VS 一键式全案交互运行器 | 单项目零冲突，数字菜单随意调度 6 大演示案例 |
| 1 | [`2.1_ghost_value.c`](lecture-demo/2.1_ghost_value.c) | 第11、20页 | 课上精讲：内存复用与初始化 | 局部变量未初始化残留值、VS `C4700` 拦截、赋初值必要性 |
| 2 | [`2.2_int_overflow.c`](lecture-demo/2.2_int_overflow.c) | 第15页 | 课上深挖：整型值域与溢出 | 20000+20000 在 16 位系统溢出为 `-25536`、`(long)` 强制类型转换 |
| 3 | [`2.3_float_precision.c`](lecture-demo/2.3_float_precision.c) | 第16、22页 | 课上精讲：浮点精度显微镜 | `float`（7位）与 `double`（15位）精度极限、`%.16f` 观察物理截断误差 |
| 4 | [`2.4_ascii_mask_caesar.c`](lecture-demo/2.4_ascii_mask_caesar.c) | 第17、21页 | 课上精讲：字符双重人格 | `'\101'`/`'\x41'` 进制密电、`char` 1 字节整数本质、`raw_char+3` 凯撒偏移 |
| 5 | [`2.5_sizeof_ruler.c`](lecture-demo/2.5_sizeof_ruler.c) | 第18、19页 | 课上精讲：sizeof 物理量地尺 | `sizeof` 运算符语法、测量变量与类型字节数、平台与编译器尺寸差异 |
| 6 | [`2.6_supermarket_cashier.c`](lecture-demo/2.6_supermarket_cashier.c) | 第23页 | 实操大合战：小超市收银单 | `#define` 符号常量一改全改、`scanf` 动态读入、`\t` 与 `%.2f` 对齐小票 |
| 7 | [`homework_02_solution.c`](solutions/homework_02_solution.c) | 第24页 | 课后作业：黑客字母转换彩蛋 | 大写字母 `'A'` 通过 `+32` 物理算术转换为小写 `'a'` |

---

## 🛠️ Visual Studio 专属极简演示与避坑指南

### 1. 🌟【极简演示 SOP】使用 `menu_runner.c` 一键演示全讲所有案例（零冲突，强烈推荐）

如果您使用的是 Visual Studio，为了避免在同一个项目下放置多个 `.c` 文件导致 `main` 函数重定义报错，**最丝滑、最省心的演示方式是使用综合运行器**：

```text
Visual Studio 项目: 【L02_DemoRunner】
└── 📁 源文件
    └── 📄 menu_runner.c  <--- ⭐ 整个项目只需添加这 1 个文件！
```

#### 📌 操作步骤：
1. 在 Visual Studio 中新建一个空的控制台应用程序（如 `L02_DataTypes`）；
2. 在右侧 **解决方案资源管理器 $\rightarrow$ 源文件** 中，**【只需添加 `lecture-demo/menu_runner.c` 这一个文件】**；
3. 直接按下 **`Ctrl + F5`**（开始执行不调试）；
4. 终端会立即弹出精美的数字交互菜单，输入 `1~6` 即可随意挑选执行 2.1 ~ 2.6 全部核心案例，演示完毕后按回车键即可返回主菜单！

---

### 2. 🚨【MSVC 安全检查排雷】`error C4996: 'scanf' may be unsafe`

- **已全量内置**：本仓库所有 `.c` 源文件顶部均已标配 `#define _CRT_SECURE_NO_WARNINGS`，在 VS 下直接按 `Ctrl + F5` 即可零告警、零拦截秒级生成运行！

---

### 3. 🎯【学生单题练习 SOP】同一个项目多个 `.c` 文件如何切换？

- **首选技巧【从生成中排除（Excluded From Build）】**：
  右键当前不运行的文件 $\rightarrow$ 选择 **属性** $\rightarrow$ 将 **【从生成中排除】** 改为 **【是 (Yes)】** $\rightarrow$ 确定。按 `Ctrl + F5` 即可单独编译运行目标文件！

---

## ⏱️ 4课时（180分钟）一体化课堂落地时间分配

| 课时 | 时长 | 教学环节 | 核心任务与对应 PPT |
|:---:|:---:|:---|:---|
| **第1课时** | 45 min | **标识符天条与找茬对决** | 课程封面与复习导入（PPT 1~3） + 标识符概念与四大天条（PPT 4~6） + 行业命名规范与找茬 PK（PPT 7） |
| **第2课时** | 45 min | **常量变量与内存收纳盒** | 常量与常变量（PPT 8） + 变量内存物理映像与先声明后使用（PPT 9~10） + 幽灵垃圾值与避坑指南（PPT 11~12） |
| **第3课时** | 45 min | **四大类型物理底层深挖** | 四大基本类型总览（PPT 13） + `int` 补码与 20000+20000 溢出（PPT 14~15） + `float/double` 精度与科学记数（PPT 16） + `char` 双重人格与密电（PPT 17） + `sizeof` 量地尺（PPT 18） |
| **第4课时** | 45 min | **机房 5 大实操工坊与测评** | 探究一至五实操编码（PPT 19~23） + 离堂小测、总结与课后作业布置（PPT 24） |

# 第03讲 — 程序底层的“算术链条”与“顺序执行”：运算符、表达式与顺序结构

> **对应章节**：第3章 最简单的C程序设计——顺序程序设计  
> **对应课件**：《C语言程序设计》第03讲 PPT逐页文稿与教学设计（共30页·四课时大满贯理实一体版）  
> **融合教材**：
> - 《C程序设计（第五版）》· 谭浩强 著（底层机制：IPO 模式、自增自减物理内存流向、多重存款利息计算）
> - 《C语言程序设计（第3版）》· 何钦铭 颜晖 主编（任务驱动：温度转换、三位数逆序器、海伦公式）
> - 湖南大学《程序设计》课件（自动类型提升、短路求值电路模型及运算符优先级排雷）  
> **课时设置**：4课时（180分钟）理实一体化课堂（2课时理论精讲 + 2课时上机实操大满贯工坊）  
> **核心指标**：达成**“能计算（识天条）、能看透（识类型）、能避坑（识自增）、能设计（构顺序）”**的四维学习指标。

---

## 📂 代码资产与目录结构

```text
lessons/L03_sequential-programming/
├── README.md                                     # 本讲教学说明与全景导学指南（本文件）
├── lecture-demo/                                 # 课堂演示代码（教师现场讲解与演示）
│   ├── menu_runner.c                             # ⭐ Visual Studio 专属一键全案交互运行器（零冲突，强烈推荐）
│   ├── 3.1_temp_convert.c                        # PPT 第19页：华氏转摄氏度与 5/9 截断排雷
│   ├── 3.2_calculator.c                          # PPT 第4、11页：两数多功能计算器与精确商
│   ├── 3.3_short_circuit_and_inc.c               # ⭐ PPT 第6、8页：自增自减与短路求值电路模型
│   ├── 3.4_bank_interest_three_ways.c            # ⭐ PPT 第21页：谭版例3.2 多重存款利息计算器三种方式对比
│   └── 3.5_char_io_pipeline.c                    # ⭐ PPT 第17页：putchar 与 getchar 字符流管道与大写转小写
├── starter/                                      # 学生起步模板（5 大上机大满贯工坊任务）
│   ├── task1_circle_starter.c                    # 任务一：圆之几何学计算器 (谭版 3.7 改编)
│   ├── task2_loan_starter.c                      # 任务二：购房还贷月数预算师 (谭版 3.3)
│   ├── task3_reverse_starter.c                   # 任务三：三位整数剥洋葱逆序器 (何版经典)
│   ├── task4_cipher_starter.c                    # 任务四：神秘的凯撒谍报密码机 (谭版 3.6)
│   └── task5_triangle_starter.c                  # 任务五：三角形面积测量仪 (海伦公式)
├── exercises/                                    # 当堂练习与评测
│   ├── exercises_03.md                           # 天条速算、内存推演、同伴互评与离堂小测题单
│   └── exercise_fix_scanf_errors.c               # scanf 地址符 & 与整除截断经典排雷实操
└── solutions/                                    # 教师参考答案（教师私有，不公开）
    ├── task1_circle_solution.c                   # 任务一参考答案
    ├── task2_loan_solution.c                     # 任务二参考答案
    ├── task3_reverse_solution.c                  # 任务三参考答案
    ├── task4_cipher_solution.c                   # 任务四参考答案
    ├── task5_triangle_solution.c                 # 任务五参考答案
    └── exercises_03_answers.md                   # 评测标准答案与详细考点解析
```

---

## 🗺️ 代码资产与 30 页 PPT 映射表

| 序号 | 资产源文件 | 对应 PPT 页码 | 教学定位 | 核心考点 / 技能点 |
|:---:|:---|:---:|:---|:---|
| ⭐ | [`menu_runner.c`](lecture-demo/menu_runner.c) | 全讲综合 | VS 一键式全案交互运行器 | 单项目零冲突，数字菜单随意调度 5 大核心演示案例 |
| 1 | [`3.1_temp_convert.c`](lecture-demo/3.1_temp_convert.c) | 第19页 | 课上精讲：整除截断排雷 | `5 / 9` 截断为 0 冻结现象、`5.0 / 9` 浮点隐式提升 |
| 2 | [`3.2_calculator.c`](lecture-demo/3.2_calculator.c) | 第4、11页 | 课上精讲：算术与取模 | 五大算术运算符、取模符号只看被除数、`(double)` 强转求精确商 |
| 3 | [`3.3_short_circuit_and_inc.c`](lecture-demo/3.3_short_circuit_and_inc.c) | 第6、8页 | 课上深挖：自增与短路 | 前置 `++i` vs 后置 `i++` 内存动作、`a++ && (b = 3)` 短路电路模型 |
| 4 | [`3.4_bank_interest_three_ways.c`](lecture-demo/3.4_bank_interest_three_ways.c) | 第21页 | 课上精讲：IPO 与复利 | 谭版例 3.2 活期/一年定期/两次半年转存三种方式对比、`%.5f` 输出 |
| 5 | [`3.5_char_io_pipeline.c`](lecture-demo/3.5_char_io_pipeline.c) | 第17页 | 课上精讲：字符流管道 | `putchar(66)` 整型输出、`getchar()` 单字符读取、大写转小写 `+32` |
| 6 | [`task1_circle_starter.c`](starter/task1_circle_starter.c) | 第22页 | 实操大满贯·任务一 | `#define PI`、圆周长面积、圆球表面积/体积、圆柱体积、避坑 `4.0/3` |
| 7 | [`task2_loan_starter.c`](starter/task2_loan_starter.c) | 第23页 | 实操大满贯·任务二 | `<math.h>`、对数公式 `log10()`、向上取整 `ceil()` 算实际月数 |
| 8 | [`task3_reverse_starter.c`](starter/task3_reverse_starter.c) | 第24页 | 实操大满贯·任务三 | 三位数数码拆解（`/ 100`, `% 10`, `(/ 10) % 10`）、求和与逆序拼接 |
| 9 | [`task4_cipher_starter.c`](starter/task4_cipher_starter.c) | 第25页 | 实操大满贯·任务四 | 凯撒密码平移 `+4`、`putchar` 与 `printf("%c")` 双管道同台验证 |
| 10 | [`task5_triangle_starter.c`](starter/task5_triangle_starter.c) | 第26页 | 实操大满贯·任务五 | 海伦公式求面积、`<math.h>` 中 `sqrt()`、半周长 `s=(a+b+c)/2.0` 排雷 |

---

## 🛠️ Visual Studio 专属极简演示与避坑指南

### 1. 🌟【极简演示 SOP】使用 `menu_runner.c` 一键演示全讲所有案例（零冲突，强烈推荐）

如果您使用的是 Visual Studio，为了避免在同一个项目下放置多个 `.c` 文件导致 `main` 函数重定义报错，**最丝滑、最省心的演示方式是使用综合运行器**：

```text
Visual Studio 项目: 【L03_DemoRunner】
└── 📁 源文件
    └── 📄 menu_runner.c  <--- ⭐ 整个项目只需添加这 1 个文件！
```

#### 📌 操作步骤：
1. 在 Visual Studio 中新建一个空的控制台应用程序（如 `L03_Sequential`）；
2. 在右侧 **解决方案资源管理器 $\rightarrow$ 源文件** 中，**【只需添加 `lecture-demo/menu_runner.c` 这一个文件】**；
3. 直接按下 **`Ctrl + F5`**（开始执行不调试）；
4. 终端会立即弹出精美的数字交互菜单，输入 `1~5` 即可随意挑选执行 3.1 ~ 3.5 全部核心理论案例，演示完毕后按回车键即可返回主菜单！

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
| **第1课时** | 45 min | **算术链条与运算符物理底层** | 课程封面与复习导入（PPT 1~3） + 除法与取余天条（PPT 4） + 自动类型提升机制（PPT 5） + 自增自减内存动作（PPT 6） + 关系/逻辑短路/条件/逗号运算符（PPT 7~10） |
| **第2课时** | 45 min | **C语句体系与IPO输入输出** | 强转临时马甲（PPT 11） + C语句五大分类（PPT 12） + 复合赋值与赋初值（PPT 13） + 顺序结构与IPO（PPT 14） + printf/scanf控制符与高倍显微（PPT 15~16） + putchar/getchar与华氏转摄氏/多重利息（PPT 17~21） |
| **第3课时** | 45 min | **机房实操大满贯·任务一至三** | 任务一：圆与圆柱几何学计算器（PPT 22） + 任务二：购房还贷月数预算师（PPT 23） + 任务三：三位数剥洋葱逆序器（PPT 24） |
| **第4课时** | 45 min | **机房实操大满贯·任务四至五与测评** | 任务四：凯撒谍报密码机（PPT 25） + 任务五：三角形面积测量仪（PPT 26） + 同伴互评与离堂小测（PPT 27~28） + 课后作业布置（PPT 29） |

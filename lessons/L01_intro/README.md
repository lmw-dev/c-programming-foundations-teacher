# 第01讲 — 认识C程序：C语言概述、程序结构、开发流程与屏幕输出

> **对应章节**：第1章 C语言概述 + 第3章 顺序结构程序设计(起步)  
> **对应课件**：《C语言程序设计基础》第01讲 PPT逐页文稿（共18页）  
> **课时设置**：4课时（180分钟）理实一体化课堂  
> **教学目标**：让专升本/职校零基础学生达成**“能说清、能看懂、能写出、能运行”**的四维学习指标。

---

## 📂 代码资产与目录结构

```
lessons/L01_intro/
├── README.md                                # 本讲教学说明与导学指南（本文件）
├── lecture-demo/                            # 课堂演示代码（教师现场讲解与演示）
│   ├── 1.1_hello_world.c                    # 最简标准C结构逐行剖析 (PPT 第5~6页)
│   ├── 1.2_multi_line_output.c              # 多行输出与 \n 换行符机制 (PPT 第7~8页)
│   ├── 1.3_student_card.c                   # 三行“我的程序名片”标准案例 (PPT 第12~13页)
│   └── 1.4_error_playground.c               # 5大高频报错排雷游乐场 (PPT 第11页)
├── starter/                                 # 学生起步模板（上机骨架与 TODO 指引）
│   ├── task1_hello_starter.c                # 任务1：运行 Hello, C!
│   ├── task2_student_card_starter.c         # 任务2：个人名片骨架填空
│   └── task3_goal_card_starter.c            # 任务3：个性化学习目标与格式对齐
├── exercises/                               # 当堂练习与评测
│   ├── exercises_01.md                      # 快速判断、互评标准卡与离堂小测
│   └── exercise_fix_errors.c                # 升本常考题型：经典语法改错练习
└── solutions/                               # 教师参考答案（教师私有，不公开）
    ├── task1_hello_solution.c               # 任务1参考答案
    ├── task2_student_card_solution.c        # 任务2参考答案
    ├── task3_goal_card_solution.c           # 任务3参考答案
    ├── homework_01_solution.c               # PPT 第18页课后作业：不少于4行自我介绍
    └── exercises_01_answers.md              # 评测标准答案与详细考点解析
```

---

## 🗺️ 代码资产与 PPT 页码映射

| 序号 | 源文件名 | 对应 PPT 页码 | 教学定位 | 核心考点 / 技能点 |
|:---:|:---|:---:|:---|:---|
| 1 | [`1.1_hello_world.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L01_intro/lecture-demo/1.1_hello_world.c) | 第5~6页 | 课上精讲：最简标准C程序结构 | 预处理指令、`main(void)` 入口、`printf`、`return 0`、分号 `;` |
| 2 | [`1.2_multi_line_output.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L01_intro/lecture-demo/1.2_multi_line_output.c) | 第7~8页 | 课上精讲：多行输出与转义换行 | 顺序执行逻辑、`\n` 换行符与 `/n` 错误辨析 |
| 3 | [`1.3_student_card.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L01_intro/lecture-demo/1.3_student_card.c) | 第12~13页 | 课上案例：三行“我的程序名片” | 多语句组合排版、格式化输出、学习目标设定 |
| 4 | [`1.4_error_playground.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L01_intro/lecture-demo/1.4_error_playground.c) | 第11页 | 纠错示范：常见错误初步辨析 | 漏分号、中文标点、`mian` 入口拼写、双引号未闭合 |

---

## 🏫 教学实施精细化指引

### 1. 案例精析：最简标准 C 结构（PPT 第5~6页）
- **核心源码**：[`1.1_hello_world.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L01_intro/lecture-demo/1.1_hello_world.c)
- **场景导入**（PPT 第2页）：日常手机、游戏里的程序，如何从代码变成屏幕上的结果？从最小的 C 程序开始走通“编辑—编译—运行—检查”。
- **经典“建筑模型”板书**：
  - `#include <stdio.h>` $\rightarrow$ **“拉外援 / 拿工具箱”**（引入标准输入输出库，否则不认识 `printf`）。
  - `int main(void)` $\rightarrow$ **“进大门”**（程序的唯一入口，C 程序永远从 `main` 开始执行）。
  - `{ ... }` $\rightarrow$ **“砌围墙”**（函数体的大括号，限定程序执行的代码块范围）。
  - `printf("...");` $\rightarrow$ **“大喇叭”**（向屏幕广播双引号内的文字内容）。
  - `\n` $\rightarrow$ **“敲回车”**（换行转义字符，将光标移至下一行首）。
  - `;` $\rightarrow$ **“打句号”**（C 语句的法定结束标志，每句话说完必须以英文半角分号结句）。
  - `return 0;` $\rightarrow$ **“安全到家”**（向操作系统汇报：程序正常执行完毕，无异常）。

### 2. 案例精析：多行输出与转义换行（PPT 第7~8页）
- **核心源码**：[`1.2_multi_line_output.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L01_intro/lecture-demo/1.2_multi_line_output.c)
- **顺序执行思维**：C 程序是单向自动扶梯，自上而下严格按顺序逐行执行。
- **`\n` 换行符的机制对比**：
  - 不带 `\n`：`printf("Hello"); printf("World");` $\rightarrow$ 输出 `HelloWorld`（挤在同一行）。
  - 带 `\n`：`printf("Hello\n"); printf("World\n");` $\rightarrow$ 分两行输出。
- **快速选择互动（PPT 第8页）**：
  - 提问：“下面哪一项能换行？A. `/n`  B. `\n`  C. `n`”
  - 重点强调按键位置与斜杠方向：“**反斜杠向后倒 `\`（回车键上方），正斜杠向前倾 `/`（除号/问号键）**”。

### 3. 上机任务组织：规范格式个人信息名卡（PPT 第12~15页）
- **核心源码**：[`1.3_student_card.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L01_intro/lecture-demo/1.3_student_card.c)
- **实操任务**：在机房打开集成开发环境（Visual Studio 或 Dev-C++），新建源文件 `1.3_student_card.c`，编写并运行一个格式规范的个人信息名卡。
- **目标效果展示**：
  ```text
  ==================================
  *  姓名(Name)  : 张三            *
  *  班级(Class) : 职校数控2601班  *
  *  学号(ID)    : 20260811001     *
  *  座右铭      : 用代码改变世界！*
  ==================================
  ```
- **任务分层下达**：
  - **任务 1**：在 IDE 中输入并运行 `Hello, C!`。
  - **任务 2**：编写带边框格式规范的个人名卡（将姓名、班级、学号替换为真实信息，并挑战右侧边框垂直对齐）。
  - **任务 3**：改写座右铭为自己的个性化奋斗目标（如“每天敲100行代码，冲刺专升本！”）。
- **四项自查清单（PPT 第15页）**：
  - $\square$ 文件后缀确认为 `.c`（非 `.cpp` 或 `.txt`）
  - $\square$ `main`、花括号 `{}`、分号 `;` 齐全完整
  - $\square$ `printf` 中的双引号为英文半角 `""`
  - $\square$ 控制台输出的名卡边框整齐对齐，信息完整

### 4. 常见错误辨析与排雷（PPT 第11页）
- **核心源码**：[`1.4_error_playground.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L01_intro/lecture-demo/1.4_error_playground.c)

| 错误类型 | 典型错误代码 | 编译器经典报错提示 | 排查与修复方法 |
|:---|:---|:---|:---|
| **漏写英文分号** | `printf("...")` 缺少末尾 `;` | `error: expected ';' before 'return'` | 定位到报错行的上一行，在末尾补上英文 `;` |
| **混用中文标点** | `printf("...");；`（中文分号） | `error: stray '\357'` 或 `未知字符` | 切换输入法为英文半角状态，重新敲入 `;` 或 `""` |
| **主函数拼写错误**| `int mian(void)` | `undefined reference to 'main'` | 检查程序入口名，将 `mian` 改正为 `main` |
| **转义符方向写反**| `printf("第一行/n第二行\n");` | 无编译报错，控制台直接打印 `/n` | 将正斜杠 `/` 替换为反斜杠 `\` |
| **双引号不闭合** | `printf("缺少右引号);` | `error: missing terminating '"' character` | 补齐成对的英文双引号 `""` |

---

## ⏱️ 4课时（180分钟）一体化课堂落地时间分配

| 课时 | 时长 | 教学环节 | 核心任务与对应 PPT |
|:---:|:---:|:---|:---|
| **第1课时** | 45 min | 认知导入与语法精讲 | PPT 第1~7页：C 语言应用背景、`1.1_hello_world.c` 逐行拆解与“建筑模型”板书 |
| **第2课时** | 45 min | 上机初体验与运行全流程 | PPT 第8~10页：在 IDE 中新建 `.c` 文件，首次完成“编辑—编译—运行—检查”全闭环 |
| **第3课时** | 45 min | 案例实操与个性化名片 | PPT 第12~15页：讲解 `1.2` 与 `1.3`，学生独立完成三行名片并改写个性化学习目标 |
| **第4课时** | 45 min | 报错排雷、同伴互评与离堂小测 | PPT 第11、16~18页：演示 `1.4` 报错排雷，开展同伴互评，完成离堂 3 题小测与作业布置 |

---

## 📊 代码资产状态

| 资产类别 | 包含文件 | 当前状态 | 备注 |
|:---|:---|:---:|:---|
| **课堂演示代码** | `1.1_hello_world.c`, `1.2_multi_line_output.c`, `1.3_student_card.c`, `1.4_error_playground.c` | **已定稿** | 4 份演示源文件全量通过编译验证 |
| **起步模板** | `task1_hello_starter.c`, `task2_student_card_starter.c`, `task3_goal_card_starter.c` | **已定稿** | 3 份上机任务骨架 |
| **当堂练习** | `exercises_01.md`, `exercise_fix_errors.c` | **已定稿** | 1 份测评题单 + 1 份改错练习 |
| **参考答案** | `task1`~`task3_solution.c`, `homework_01_solution.c`, `exercises_01_answers.md` | **已定稿** | 4 份代码答案 + 1 份题目解析 |

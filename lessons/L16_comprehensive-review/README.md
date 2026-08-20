# 第16讲 — 全课程综合复习与升本题型训练（⭐阶段大回收3）

> **对应章节**：全书综合复习（第1~10章核心考点大串联、专升本冲刺、期末实战通关）  
> **对应课件**：《C语言程序设计》第16讲 PPT逐页文稿与教学设计（共20页·专升本冲刺版）  
> **融合教材**：
> - 《C程序设计（第五版）》· 谭浩强 著（全书知识树状图、单向链表、动态内存分配）
> - 《C语言程序设计（第3版）》· 何钦铭 颜晖 主编（指针与函数综合、static生命期、文件流读写）
> - 湖南大学《程序设计》课件（共用体共享首地址、带参宏纯文本无脑替换、逻辑短路空气开关）
> - 北京石油化工学院《C语言程序设计》课件（补码爆仓与溢出机理、二维数组行优先平铺）  
> **阶段回收**：**⭐阶段大回收节点3**（覆盖全课程16讲所有核心理论与编程能力大检阅）  
> **课时设置**：4课时（180分钟）理实一体化收官大课。

---

## 📂 代码资产与目录结构

```
lessons/L16_comprehensive-review/
├── README.md                                # 本讲教学说明与全景导学指南（阶段大回收3）
├── lecture-demo/                            # 课堂演示代码（教师现场讲解与排雷诊断）
│   ├── 16.1_exam_traps.c                    # 五位一体考点大找茬：溢出、短路、指针时序、共用体覆盖、宏替换 (PPT 第3, 4, 8, 14, 17页)
│   └── 16.2_static_and_scope.c              # static与作用域生命期：重名遮蔽、数据段不释放不重置 (PPT 第11, 13页)
├── starter/                                 # 学生起步模板（上机骨架与 TODO 指引）
│   ├── task1_exam_traps_starter.c           # 任务1：高频考点排雷模板 (PPT 第3, 4, 8页)
│   ├── task2_static_and_scope_starter.c     # 任务2：作用域与静态变量模板 (PPT 第11, 13页)
│   └── task3_bachelor_rush_starter.c        # 任务3：单链表降序构建与落盘模板 (PPT 第15, 16, 18, 19, 20页)
├── exercises/                               # 当堂练习与评测
│   ├── exercises_16.md                      # 全课程综合测评题单：单选(10)+读程序(3)+改错(2)+编程大题(2) (PPT 第1~20页)
│   └── exercise_fix_exam_traps.c            # 专升本经典改错：宏括号、只读常量区改写、结构体局部交换错位 (PPT 第4, 8, 10, 15, 17页)
└── solutions/                               # 教师参考答案（教师私有，不公开）
    ├── 16.3_bachelor_rush.c                 # 任务3/压轴大题参考答案：单链表按成绩降序动态构建与文件持久化落盘 (PPT 第15, 16, 18, 19, 20页)
    └── exercises_16_answers.md              # 测评标准答案与专升本深度考点解析
```

---

## 🗺️ 代码资产与 PPT 页码映射

| 序号 | 资产源文件 | 对应 PPT 页码 | 教学定位 | 核心考点 / 技能点 |
|:---:|:---|:---:|:---|:---|
| 1 | [`16.1_exam_traps.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L16_comprehensive-review/lecture-demo/16.1_exam_traps.c) | 第3, 4, 8, 14, 17页 | 考点精讲：五大高频面具考点排雷 | 补码溢出、逻辑短路空气开关、`*p++` 时序、共用体内存覆盖、无括号宏替换 |
| 2 | [`16.2_static_and_scope.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L16_comprehensive-review/lecture-demo/16.2_static_and_scope.c) | 第11, 13页 | 核心剖析：作用域与生命期 | 全局/局部重名遮蔽、`static` 局部变量“不释放、不重置”、块作用域隔离 |
| 3 | [`16.3_bachelor_rush.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L16_comprehensive-review/solutions/16.3_bachelor_rush.c) | 第15, 16, 18, 19, 20页 | 升本压轴：单链表降序构建与落盘 | `malloc`/`free` 动态内存、链表降序有序插入 `insert_sorted`、文件落盘与内存回收 |
| 4 | [`exercise_fix_exam_traps.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L16_comprehensive-review/exercises/exercise_fix_exam_traps.c) | 第4, 8, 10, 15, 17页 | 专升本经典改错：四大真题排雷 | 宏替换括号结界、常量只读区保护、结构体整包置换铁律、动态内存安全 |

---

## 🏫 教学实施精细化指引

### 1. 变量存储区、作用域与生命期全景图（PPT 第13页）
```text
  【静态存储区（数据段）】  ───> 全局变量、static 局部变量（生命期：程序始终，仅初始化一次）
  【栈区（Stack）】        ───> 普通 auto 局部变量、函数形参（生命期：随栈帧分配与销毁）
  【堆区（Heap）】         ───> malloc 动态申请内存（生命期：程序员手动 free 释放）
  【只读常量区】           ───> 字符串常量 "Hello"（权限：只读，强改导致崩溃）
```

### 2. 升本压轴大题：单链表按成绩降序有序插入（PPT 第18页）
```text
  [新建节点 new_node] ──> (查找插入缝隙: current->next->score < new_node->score)
  [指针穿针引线] ───────> new_node->next = current->next; current->next = new_node;
```

---

## ⏱️ 4课时（180分钟）一体化课堂落地时间分配

| 课时 | 时长 | 教学环节 | 核心任务与对应 PPT |
|:---:|:---:|:---|:---|
| **第1课时** | 45 min | 基本常识、表达式短路与控制流地雷 | PPT 第1~5页：进制补码、整型溢出、逻辑短路空气开关、`switch` 穿透、空循环分号 |
| **第2课时** | 45 min | 数组线性存储、指针滑动时序与函数隔离 | PPT 第6~12页：二维行优先、字符数组 `\0`、`*p++` 时序、`swap` 三国演义对决 |
| **第3课时** | 45 min | static 续命、结构共用体与预处理宏 | PPT 第13~17页：`static` 变量生命期、共用体内存覆盖、整包置换铁律、带参宏展开 |
| **第4课时** | 45 min | 升本压轴实战：单链表降序构建与持久化 | PPT 第18~20页：`16.3_bachelor_rush` 链表实战、同伴 Code Review 评分、全课总结寄语 |

---

## 📊 代码资产状态

| 资产类别 | 包含文件 | 当前状态 | 备注 |
|:---|:---|:---:|:---|
| **课堂演示代码** | `16.1_exam_traps.c`, `16.2_static_and_scope.c` | **已定稿** | 2 份演示源文件全量通过编译测试 |
| **起步模板** | `task1_exam_traps_starter.c`, `task2_static_and_scope_starter.c`, `task3_bachelor_rush_starter.c` | **已定稿** | 3 份上机任务骨架 |
| **当堂练习** | `exercises_16.md`, `exercise_fix_exam_traps.c` | **已定稿** | 1 份测评题单 + 1 份改错实操 |
| **参考答案** | `16.3_bachelor_rush.c`, `exercises_16_answers.md` | **已定稿** | 1 份压轴大题代码 + 1 份全真题解析 |

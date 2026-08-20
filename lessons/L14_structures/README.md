# 第14讲 — 开启自定义数据世界（结构体与学生信息管理）

> **对应章节**：第9章 用户自己建立数据类型（9.1 定义和使用结构体变量、9.2 使用结构体数组、9.3 结构体指针）  
> **对应课件**：《C语言程序设计》第14讲 PPT逐页文稿与教学设计（共20页·双书融合工程实践版）  
> **融合教材**：
> - 《C程序设计（第五版）》· 谭浩强 著（结构体类型定义、嵌套结构、结构指针与传参性能开销）
> - 《C语言程序设计（第3版）》· 何钦铭 颜晖 主编（手机通讯录设计、学生多科成绩综合降序排序）
> - 湖南大学《程序设计》课件（结构体内存块复制、结构指针自适应步长、禁止整体关系比较）
> - 北京石油化工学院《C语言程序设计》课件（画图纸 vs 盖房子物理模型、点与箭头运算符优先级对决）  
> **课时设置**：4课时（180分钟）理实一体化大课  
> **核心指标**：达成**“能说清（懂原理）、能读懂（会引用）、能写出（会构建）、能测试（健壮性）”**的四维能力指标。

---

## 📂 代码资产与目录结构

```
lessons/L14_structures/
├── README.md                                # 本讲教学说明与全景导学指南
├── lecture-demo/                            # 课堂演示代码（教师现场讲解与演示）
│   ├── 14.1_struct_basics.c                 # 结构体基础与嵌套：画图纸vs盖房子、字符数组赋值排雷、块复制魔法 (PPT 第4~8页)
│   └── 14.2_struct_pointer.c                # 结构指针与传参性能：三大访问语法对决、优先级解密、值传递vs指针传递开销 (PPT 第11~14页)
├── starter/                                 # 学生起步模板（上机骨架与 TODO 指引）
│   ├── task1_struct_basics_starter.c        # 任务1：结构体基础与嵌套模板 (PPT 第6, 7页)
│   ├── task2_struct_ptr_starter.c           # 任务2：结构指针与箭头访问模板 (PPT 第11, 12页)
│   └── task3_student_sorter_starter.c       # 任务3：学生总分计算与排序模板 (PPT 第17, 18页)
├── exercises/                               # 当堂练习与评测
│   ├── exercises_14.md                      # 结构体找茬、运算符大对决、整包置换辨析、同伴测试、小测 (PPT 第4, 8, 11, 12, 16, 17, 19, 20页)
│   └── exercise_fix_struct_errors.c         # 专升本经典改错：末尾漏分号、字符数组赋值、指针误用点、未初始化指针 (PPT 第4, 12, 16页)
└── solutions/                               # 教师参考答案（教师私有，不公开）
    ├── 14.3_student_sorter.c                # 任务3/实操参考答案：学生多科成绩降序排序器（起泡排序 + 整包置换铁律） (PPT 第9, 10, 17, 18页)
    └── exercises_14_answers.md              # 评测标准答案与专升本深度考点解析
```

---

## 🗺️ 代码资产与 PPT 页码映射

| 序号 | 资产源文件 | 对应 PPT 页码 | 教学定位 | 核心考点 / 技能点 |
|:---:|:---|:---:|:---|:---|
| 1 | [`14.1_struct_basics.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L14_structures/lecture-demo/14.1_struct_basics.c) | 第4, 5, 6, 7, 8页 | 课上精讲：结构体图纸、嵌套与块复制 | 类型不占内存 vs 变量分配空间、嵌套结构体 Date、`strcpy` 字符数组赋值排雷、`stu3 = stu1` 块复制 |
| 2 | [`14.2_struct_pointer.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L14_structures/lecture-demo/14.2_struct_pointer.c) | 第11, 12, 13, 14页 | 核心攻坚：结构指针与传参性能大对决 | 三大等价访问形态（`stu.id` <=> `(*ptr).id` <=> `ptr->id`）、`.` 与 `*` 优先级陷阱、值传递栈拷贝 vs 指针传递零开销 |
| 3 | [`14.3_student_sorter.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L14_structures/solutions/14.3_student_sorter.c) | 第9, 10, 17, 18页 | 工业实战：学生多科成绩降序排序器 | 结构体数组批量管理、降序起泡排序算法、【整包置换铁律】彻底杜绝人分错位灾难、格式化对齐打印 |
| 4 | [`exercise_fix_struct_errors.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L14_structures/exercises/exercise_fix_struct_errors.c) | 第4, 12, 16页 | 专升本经典改错：结构体四大致命翻车地雷 | 结构体定义末尾漏写分号、字符数组成员非法赋值、普通变量误用箭头、未初始化结构指针空中解引用 |

---

## 🏫 教学实施精细化指引

### 1. “画图纸”与“盖房子”的物理模型（PPT 第4页）
```text
  【结构体定义 struct Student】       【变量声明 struct Student stu1】
  ┌─────────────────────────┐          ┌─────────────────────────┐
  │ int id;                 │          │ [ 101 ]   (4字节)       │
  │ char name[20];          │ ──实例化─>│ [ "张三" ](20字节)      │
  │ float score;            │          │ [ 85.5 ]  (4字节)       │
  └─────────────────────────┘          └─────────────────────────┘
   (抽象蓝图，不占物理内存)                  (真实房子，分配物理栈空间)
```

### 2. 结构体指针三大等价访问形态（PPT 第12页）
$$\text{stu.id} \iff (*\text{ptr}).\text{id} \iff \text{ptr}\rightarrow\text{id}$$
- **优先级铁律**：点运算符 `.` 为第 1 级优先级，解引用 `*` 为第 2 级。`(*ptr).id` 括号不可省，写成 `*ptr.id` 会直接编译报错！
- **平民与特工法则**：普通变量是平民用点 `.`；指针变量是特工发射箭头 `->`！

### 3. 结构体数组排序的【整包置换铁律】（PPT 第17页）
```c
// 🚨 严禁单独交换分数字段 (会导致张冠李戴错配灾难)！
// ✅ 正确姿势：整只结构体收纳盒一并移动
struct Student temp = arr[j];
arr[j] = arr[j + 1];
arr[j + 1] = temp;
```

---

## ⏱️ 4课时（180分钟）一体化课堂落地时间分配

| 课时 | 时长 | 教学环节 | 核心任务与对应 PPT |
|:---:|:---:|:---|:---|
| **第1课时** | 45 min | 痛点导入与结构体类型定义 | PPT 第1~8页：并排数组噩梦、定义模板图纸、声明变量、嵌套结构体、句点访问与块复制 |
| **第2课时** | 45 min | 结构体数组与批量数据计算 | PPT 第9~10页：结构体数组内存模型、双重循环输入、总分与平均分计算实战 |
| **第3课时** | 45 min | 结构体指针、运算符对决与传参开销 | PPT 第11~16页：句点 vs 箭头优先级、值传递 vs 地址传递栈帧开销、typedef 别名、四大高频雷区 |
| **第4课时** | 45 min | 上机工坊：极客班级成绩排序系统 | PPT 第17~20页：`14.3_student_sorter` 编码演进、整包置换、同伴 Code Review 极限测试、离堂小测 |

---

## 📊 代码资产状态

| 资产类别 | 包含文件 | 当前状态 | 备注 |
|:---|:---|:---:|:---|
| **课堂演示代码** | `14.1_struct_basics.c`, `14.2_struct_pointer.c` | **已定稿** | 2 份演示源文件全量通过编译测试 |
| **起步模板** | `task1_struct_basics_starter.c`, `task2_struct_ptr_starter.c`, `task3_student_sorter_starter.c` | **已定稿** | 3 份上机任务骨架 |
| **当堂练习** | `exercises_14.md`, `exercise_fix_struct_errors.c` | **已定稿** | 1 份测评题单 + 1 份改错实操 |
| **参考答案** | `14.3_student_sorter.c`, `exercises_14_answers.md` | **已定稿** | 1 份代码答案 + 1 份题目解析 |

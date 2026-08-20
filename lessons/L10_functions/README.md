# 第10讲 — 拆分大问题的“乐高积木”（函数基础与模块化程序设计）

> **对应章节**：第7章 函数的定义、调用与参数传递  
> **对应课件**：《C语言程序设计》第10讲 PPT逐页文稿与教学设计（共20页·双书融合深度优化版）  
> **融合教材**：
> - 《C程序设计（第五版）》· 谭浩强 著（函数定义四要素、返回值强制类型截断天条、变量作用域与生存期）
> - 《C语言程序设计（第3版）》· 何钦铭 颜晖 主编（函数原型声明先声明后使用、单一职责原则、回文数函数）
> - 北京石油化工学院《C语言程序设计》课件（圆形体体积计算器“3层5函数”架构）
> - 湖南大学《程序设计》课件（形参实参栈帧物理隔离与单向值传递定理、`static` 静态局部变量）  
> **课时设置**：4课时（180分钟）理实一体化大课  
> **核心指标**：达成**“能说清（懂哲学）、能读懂（通语法）、能写出（规范化）、能测试（健壮性）”**的四维能力指标。

---

## 📂 代码资产与目录结构

```
lessons/L10_functions/
├── README.md                                # 本讲教学说明与全景导学指南
├── lecture-demo/                            # 课堂演示代码（教师现场讲解与演示）
│   ├── 10.1_circular_calculator.c           # 圆形体体积计算器：“3层5函数”模块化架构、原型声明与定义分离、单向值传递 (PPT 第5, 6, 7, 11页)
│   └── 10.2_scope_and_static.c              # 作用域、局部遮蔽全局与 static 静态局部变量计数器 (PPT 第12, 13, 14页)
├── starter/                                 # 学生起步模板（上机骨架与 TODO 指引）
│   ├── task1_circular_calc_starter.c        # 任务1：圆形体体积计算器模板 (PPT 第5, 6页)
│   ├── task2_palindrome_starter.c           # 任务2：回文数判定函数模板 (PPT 第17~18页)
│   └── task3_static_counter_starter.c       # 任务3：静态局部变量计数器模板 (PPT 第14页)
├── exercises/                               # 当堂练习与评测
│   ├── exercises_10.md                      # 函数定义与声明正误找茬、形参实参栈帧追踪、返回值截断计算、同伴测试、小测 (PPT 第6, 7, 9, 11, 13, 14, 16, 19, 20页)
│   └── exercise_fix_function_errors.c       # 专升本经典改错：函数首部多加分号、形参漏写类型、非void分支漏写return (PPT 第11, 16页)
└── solutions/                               # 教师参考答案（教师私有，不公开）
    ├── 10.3_palindrome_checker.c            # 任务2/实操参考答案：单一职责与防御性回文数判定器 (is_palindrome + read_valid_integer) (PPT 第17~19页)
    └── exercises_10_answers.md              # 评测标准答案与专升本深度考点解析
```

---

## 🗺️ 代码资产与 PPT 页码映射

| 序号 | 资产源文件 | 对应 PPT 页码 | 教学定位 | 核心考点 / 技能点 |
|:---:|:---|:---:|:---|:---|
| 1 | [`10.1_circular_calculator.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L10_functions/lecture-demo/10.1_circular_calculator.c) | 第5, 6, 7, 11页 | 课上精讲：3层5函数模块化架构 | 自顶向下拆解（调度层、计算控制层、专业工具层）、函数原型声明与定义分离、形参实参单向值传递、返回值类型强制转换 |
| 2 | [`10.2_scope_and_static.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L10_functions/lecture-demo/10.2_scope_and_static.c) | 第12, 13, 14页 | 内存进阶：作用域与 static 机制 | 局部变量（栈区随生随死） vs 全局变量（常驻内存）、同名局部遮蔽全局原则、`static` 静态局部变量单次初始化与状态保留 |
| 3 | [`10.3_palindrome_checker.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L10_functions/solutions/10.3_palindrome_checker.c) | 第17~19页 | 工业实战：关注点分离与防御性检测 | 单一职责原则（输入清洗 `read_valid_integer` 与业务判定 `is_palindrome` 解耦）、纯数学逆序算法、负数安检与缓冲区冲刷防御 |
| 4 | [`exercise_fix_function_errors.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L10_functions/exercises/exercise_fix_function_errors.c) | 第6, 11, 16页 | 专升本经典改错：函数四大翻车陷阱 | 函数定义首部末尾误加分号、形参漏写类型、非 void 分支漏写 return、返回值类型不匹配导致精度被截断 |

---

## 🏫 教学实施精细化指引

### 1. 结构化“3层架构”解耦模型（PPT 第5页）
```text
                     main() (第1层：调度总指挥)
                       │
                     cal()  (第2层：业务分流控制器)
                       │
         ┌─────────────┼─────────────┐
    vol_ball()    vol_cylind()    vol_cone() (第3层：专业计算专家)
```

### 2. 形参实参物理隔离与单向值传递定理（Pass by Value）（PPT 第9~10页）
```text
  【主调函数栈区】                       【被调函数栈区】
  ┌───────────────────────┐            ┌───────────────────────┐
  │ 变量 a: [ 3 ] (物理单元)│ ──值传递──>│ 形参 x: [ 3 ] (物理单元)│
  └───────────────────────┘            └───────────────────────┘
          ▲                                    │ 
          │ (物理完全隔离，无法逆向)              ▼ 经过 x = 9 运算
          └────────── ❌ ──────────────────────│ 形参 x: [ 9 ]         
                                               └───────────────────────┘
                                                (临时形参释放，实参a不受影响)
```
- **核心结论**：形参只是实参的**临时数据复印件**，在被调函数内修改形参，主调函数中的实参毫发无损！

### 3. 返回值转换铁律（PPT 第11页）
- **函数首部声明的返回值类型拥有最高决定权**！
- 若 `return` 表达式的类型与函数声明类型不一致，系统自动将表达式强制转换为函数的声明类型（如 `double` 截断为 `int`）。

---

## ⏱️ 4课时（180分钟）一体化课堂落地时间分配

| 课时 | 时长 | 教学环节 | 核心任务与对应 PPT |
|:---:|:---:|:---|:---|
| **第1课时** | 45 min | 模块化设计哲学与函数定义声明 | PPT 第1~7页：代码复印泥潭痛点、自顶向下拆解、3层5函数架构、函数定义4要素、原型声明先声明后使用 |
| **第2课时** | 45 min | 形参实参数据隔离与单向值传递 | PPT 第8~11页：实参形参虚实结合、物理栈帧隔离图、单向值传递铁律、返回值类型强制截断转换 |
| **第3课时** | 45 min | 变量作用域、同名遮蔽与 static | PPT 第12~16页：局部变量 vs 全局变量、局部遮蔽全局原则、`static` 静态局部变量计数器、代码诊所排雷 |
| **第4课时** | 45 min | 上机工坊：回文数检测器与同伴测试 | PPT 第17~20页：`10.3_palindrome_checker` 单一职责编码、极限黑盒压测、同伴互评自查、离堂小测 |

---

## 📊 代码资产状态

| 资产类别 | 包含文件 | 当前状态 | 备注 |
|:---|:---|:---:|:---|
| **课堂演示代码** | `10.1_circular_calculator.c`, `10.2_scope_and_static.c` | **已定稿** | 2 份演示源文件全量通过编译测试 |
| **起步模板** | `task1_circular_calc_starter.c`, `task2_palindrome_starter.c`, `task3_static_counter_starter.c` | **已定稿** | 3 份上机任务骨架 |
| **当堂练习** | `exercises_10.md`, `exercise_fix_function_errors.c` | **已定稿** | 1 份测评题单 + 1 份改错实操 |
| **参考答案** | `10.3_palindrome_checker.c`, `exercises_10_answers.md` | **已定稿** | 1 份代码答案 + 1 份题目解析 |

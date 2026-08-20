# 第15讲 — 数据的持久化封印（文件操作与异常安全防护）

> **对应章节**：第10章 对文件的输入输出（10.1~10.5 文件的打开关闭、顺序读写、随机读写与出错检测）  
> **对应课件**：《C语言程序设计》第15讲 PPT逐页文稿与教学设计（共20页·双书融合工程实践版）  
> **融合教材**：
> - 《C程序设计（第五版）》· 谭浩强 著（缓冲文件系统、FILE 结构体、字符/字符串/格式化读写、文件位置指针控制）
> - 《C语言程序设计（第3版）》· 何钦铭 颜晖 主编（手机通讯录持久化保存、成绩单结构化读写、feof 循环控制）
> - 湖南大学《程序设计》课件（异常防御盾 `feof`、`ferror`、`clearerr`，`fopen` 安全防御套路）
> - 北京石油化工学院《C语言程序设计》课件（文本文件 vs 二进制文件底层解密、中转缓冲区物理模型）  
> **课时设置**：4课时（180分钟）理实一体化大课  
> **核心指标**：达成**“能说清（懂本质）、能读懂（会架构）、能写出（可应用）、能测试（筑防线）”**的四维能力指标。

---

## 📂 代码资产与目录结构

```
lessons/L15_files/
├── README.md                                # 本讲教学说明与全景导学指南
├── lecture-demo/                            # 课堂演示代码（教师现场讲解与演示）
│   ├── 15.1_file_copy.c                     # 文件字符级拷贝：fgetc/fputc、EOF哨兵、int ch类型、fclose冲刷 (PPT 第5, 6, 7, 8, 10, 11页)
│   └── 15.2_score_persistence.c             # 结构体持久化：fprintf/fscanf格式化读写、fscanf==3安全边界、排行榜再现 (PPT 第12, 13, 17, 18页)
├── starter/                                 # 学生起步模板（上机骨架与 TODO 指引）
│   ├── task1_file_copy_starter.c            # 任务1：字符级文件拷贝模板 (PPT 第11页)
│   ├── task2_score_persistence_starter.c    # 任务2：成绩数据格式化持久化模板 (PPT 第12, 13, 17页)
│   └── task3_safe_logger_starter.c          # 任务3：系统日志追加器模板 (PPT 第8, 16页)
├── exercises/                               # 当堂练习与评测
│   ├── exercises_15.md                      # 打开模式找茬、缓冲区问答、异常防护盾辨析、同伴测试、小测 (PPT 第5, 7, 8, 9, 10, 13, 16, 19, 20页)
│   └── exercise_fix_file_errors.c           # 专升本经典改错：fopen漏NULL检查、日志误用w模式、char接收EOF、漏写fclose (PPT 第7, 8, 10, 11页)
└── solutions/                               # 教师参考答案（教师私有，不公开）
    ├── 15.3_safe_logger.c                   # 任务3/实操参考答案：工业级安全日志追加器 (模式a + ferror/feof/clearerr防护盾) (PPT 第7, 8, 16, 17, 18页)
    └── exercises_15_answers.md              # 评测标准答案与专升本深度考点解析
```

---

## 🗺️ 代码资产与 PPT 页码映射

| 序号 | 资产源文件 | 对应 PPT 页码 | 教学定位 | 核心考点 / 技能点 |
|:---:|:---|:---:|:---|:---|
| 1 | [`15.1_file_copy.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L15_files/lecture-demo/15.1_file_copy.c) | 第5, 6, 7, 8, 10, 11页 | 课上精讲：字符流拷贝与缓冲区机制 | 缓冲文件系统 512B 仓库、`fgetc`/`fputc` 字节级流动、`int ch` 接收 `EOF`、`fclose` 强制冲刷落盘 |
| 2 | [`15.2_score_persistence.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L15_files/lecture-demo/15.2_score_persistence.c) | 第12, 13, 17, 18页 | 核心攻坚：结构体数据格式化持久化 | 序列化（内存->磁盘）与反序列化（磁盘->内存）、`fprintf`/`fscanf` 制表排版、`fscanf == 3` 安全边界 |
| 3 | [`15.3_safe_logger.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L15_files/solutions/15.3_safe_logger.c) | 第7, 8, 16, 17, 18页 | 工业实战：异常防御型系统日志追加器 | 追加模式 `"a"` 安全特性、`fp == NULL` 拦截、`ferror` 硬件故障排查、`clearerr` 状态复位、`feof` 校验 |
| 4 | [`exercise_fix_file_errors.c`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L15_files/exercises/exercise_fix_file_errors.c) | 第7, 8, 10, 11页 | 专升本经典改错：文件四大翻车地雷 | `fopen` 漏写 `NULL` 检查、日志误用 `"w"` 抹除历史、`char` 接收 `EOF` 判别失效、漏写 `fclose` 丢数据 |

---

## 🏫 教学实施精细化指引

### 1. 缓冲文件系统与 512 字节中转仓库（PPT 第5页）
```text
  [程序数据区] ─(写入)─> [内存输出缓冲区 (512B)] ──(满载或fclose时落盘)──> [磁盘文件]
  [程序数据区] <─(读取)─ [内存输入缓冲区 (512B)] <──(预先批量读取)─────── [磁盘文件]
```

### 2. 打开模式攻防矩阵（PPT 第8页）
- **`"r"`**：只读模式，文件不存在直接返回 `NULL` 报错；
- **`"w"`**：只写模式，文件存在则**瞬间无情抹除重建**（危险！）；
- **`"a"`**：追加模式，文件存在则光标移至末尾安全累加，文件不存在自动创建（日志首选！）。

### 3. 标准文件操作函数全景选择表（PPT 第15页）
$$\begin{array}{|c|c|c|c|}
\hline
\textbf{应用场景} & \textbf{写入函数} & \textbf{读取函数} & \textbf{最小物理单位} \\
\hline
\text{单字节/字符流} & \text{fputc} & \text{fgetc} & 1 \text{ 字节} \\
\text{文本行/日志} & \text{fputs} & \text{fgets} & \text{一行 (遇换行结束)} \\
\text{表格化/结构化数据} & \text{fprintf} & \text{fscanf} & \text{格式控制符} \\
\text{结构体数组大宗打包} & \text{fwrite} & \text{fread} & \text{指定 size 字节块} \\
\hline
\end{array}$$

---

## ⏱️ 4课时（180分钟）一体化课堂落地时间分配

| 课时 | 时长 | 教学环节 | 核心任务与对应 PPT |
|:---:|:---:|:---|:---|
| **第1课时** | 45 min | 文件系统、文本与二进制、FILE 探针 | PPT 第1~6页：内存失忆症、ASCII vs 二进制底理解析、缓冲文件系统、FILE 探针结构体 |
| **第2课时** | 45 min | 打开关闭控制流与攻防模式矩阵 | PPT 第7~10页：`fopen` 与 NULL 拦截、`"r"/"w"/"a"` 攻防矩阵、找茬排雷、`fclose` 冲刷机制 |
| **第3课时** | 45 min | 三级读写金刚与异常防御体系 | PPT 第11~16页：`fgetc/fputc`、`fgets/fputs`、`fprintf/fscanf`、`feof/ferror/clearerr` 防护盾 |
| **第4课时** | 45 min | 上机工坊：成绩持久化与安全日志管理 | PPT 第17~20页：`15.2_score_persistence`、`15.3_safe_logger` 编码演进、同伴黑盒对抗、离堂小测 |

---

## 📊 代码资产状态

| 资产类别 | 包含文件 | 当前状态 | 备注 |
|:---|:---|:---:|:---|
| **课堂演示代码** | `15.1_file_copy.c`, `15.2_score_persistence.c` | **已定稿** | 2 份演示源文件全量通过编译测试 |
| **起步模板** | `task1_file_copy_starter.c`, `task2_score_persistence_starter.c`, `task3_safe_logger_starter.c` | **已定稿** | 3 份上机任务骨架 |
| **当堂练习** | `exercises_15.md`, `exercise_fix_file_errors.c` | **已定稿** | 1 份测评题单 + 1 份改错实操 |
| **参考答案** | `15.3_safe_logger.c`, `exercises_15_answers.md` | **已定稿** | 1 份代码答案 + 1 份题目解析 |

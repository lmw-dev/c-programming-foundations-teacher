# 教学资产交付与 VS Code 验证全景交接文档

**日期**：2026-08-14  
**维护人**：Antigravity  
**关联课件**：`/Users/liumingwei/vaults/WorkbenchVault/1_Projects/P-202608-Adjunct-Teaching_C-Language-Foundation/02-课件逐字稿/第01讲-PPT逐页文稿-待审定.md`  
**代码资产目录**：`lessons/L01_intro/`  

---

## 一、 本次重构与完善概览

本次对第 01 讲（L01_intro）完成了**代码与教案架构的规范化升级**：

1. **目录纯净化与架构升级**：
   - 将原位于 `lecture-demo/` 目录下的导学案与讲次总览合并，重构升级为全景教案 [`lessons/L01_intro/README.md`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L01_intro/README.md)。
   - `lecture-demo/` 目录现保持职责单一，仅存放纯粹的 `.c` 现场演示代码。
2. **教材与 PPT 逐字稿全量对齐**：
   - 语法规范：全量代码统一使用标准 C99/C11，标准入口 `int main(void)`，配合 `#include <stdio.h>` 与 `return 0;`。
   - 包含：4 份演示源文件、3 份上机任务起步模板、1 份当堂题单 + 1 份改错练习、4 份参考答案 + 1 份测评解析。
3. **VS Code 一体化开发环境**：
   - 配置了 `.vscode/tasks.json`、`.vscode/launch.json`、`.vscode/settings.json` 与自动化校验脚本 `tools/verify_all.sh`。

---

## 二、 最终规范化目录结构

```
lessons/L01_intro/
├── README.md                                # 讲次总览、PPT 18页映射与 4 课时一体化导学案
├── lecture-demo/                            # 纯 .c 课堂现场演示代码
│   ├── 1.1_hello_world.c                    # PPT 第5~6页：最简C结构
│   ├── 1.2_multi_line_output.c              # PPT 第7~8页：多行输出与换行机制
│   ├── 1.3_student_card.c                   # PPT 第12~13页：三行名片标准案例
│   └── 1.4_error_playground.c               # PPT 第11页：常见错误排雷
├── starter/                                 # 纯 .c 学生起步模板
│   ├── task1_hello_starter.c                # 任务1起步骨架
│   ├── task2_student_card_starter.c         # 任务2个人名片起步骨架
│   └── task3_goal_card_starter.c            # 任务3个性化目标起步骨架
├── exercises/                               # 当堂练习与评测
│   ├── exercises_01.md                      # 当堂题单与离堂小测
│   └── exercise_fix_errors.c                # 经典改错练习
└── solutions/                               # 教师参考答案（私有）
    ├── task1_hello_solution.c               # 任务1参考答案
    ├── task2_student_card_solution.c        # 任务2参考答案
    ├── task3_goal_card_solution.c           # 任务3参考答案
    ├── homework_01_solution.c               # 课后作业参考答案（自我介绍）
    └── exercises_01_answers.md              # 评测标准答案与解析
```

---

## 三、 VS Code 验证指南

1. **快捷键编译**：在任何 `.c` 文件中按 <kbd>Cmd</kbd> + <kbd>Shift</kbd> + <kbd>B</kbd>（Mac）或 <kbd>Ctrl</kbd> + <kbd>Shift</kbd> + <kbd>B</kbd>（Win），编译产物输出至 `bin/`。
2. **全量自动化校验**：运行 `./tools/verify_all.sh` 批量验证全库 C 文件语法与执行。
3. **断点调试**：打上红点断点后按 <kbd>F5</kbd>，选择 `C/C++: 调试当前文件 (macOS/Linux LLDB)`。

---

## 四、 后续讲次模板标准建议

以后在构建 `L02_data-types` ~ `L16_comprehensive-review` 时，统一沿用此 **L01 范式**：
- `lessons/Lxx_xxx/README.md` 作为该讲的唯一全景导学与资产说明文档。
- `lecture-demo/`、`starter/`、`solutions/` 保持为纯 `.c` 代码库。

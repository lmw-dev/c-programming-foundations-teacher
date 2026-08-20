# 教学资产交付与全景维护交接文档

**更新日期**：2026-08-20  
**维护人**：Antigravity  
**关联课件**：
- 第01讲：`/Users/liumingwei/vaults/WorkbenchVault/1_Projects/P-202608-Adjunct-Teaching_C-Language-Foundation/02-课件逐字稿/第01讲-PPT逐页文稿-待审定.md`
- 第02讲：`/Users/liumingwei/vaults/WorkbenchVault/1_Projects/P-202608-Adjunct-Teaching_C-Language-Foundation/02-课件逐字稿/lecture-02-ppt-v3.md`
- 第03讲：`/Users/liumingwei/vaults/WorkbenchVault/1_Projects/P-202608-Adjunct-Teaching_C-Language-Foundation/02-课件逐字稿/lecture-03-ppt.md`
- 第04讲：`/Users/liumingwei/vaults/WorkbenchVault/1_Projects/P-202608-Adjunct-Teaching_C-Language-Foundation/02-课件逐字稿/lecture-04-ppt.md`
- 第05讲：`/Users/liumingwei/vaults/WorkbenchVault/1_Projects/P-202608-Adjunct-Teaching_C-Language-Foundation/02-课件逐字稿/lecture-05-ppt.md`
- 第06讲：`/Users/liumingwei/vaults/WorkbenchVault/1_Projects/P-202608-Adjunct-Teaching_C-Language-Foundation/02-课件逐字稿/lecture-06-ppt.md`
- 第07讲：`/Users/liumingwei/vaults/WorkbenchVault/1_Projects/P-202608-Adjunct-Teaching_C-Language-Foundation/02-课件逐字稿/lecture-07-ppt.md`
- 第08讲：`/Users/liumingwei/vaults/WorkbenchVault/1_Projects/P-202608-Adjunct-Teaching_C-Language-Foundation/02-课件逐字稿/lecture-08-ppt.md`
- 第09讲：`/Users/liumingwei/vaults/WorkbenchVault/1_Projects/P-202608-Adjunct-Teaching_C-Language-Foundation/02-课件逐字稿/lecture-09-ppt.md`
- 第10讲：`/Users/liumingwei/vaults/WorkbenchVault/1_Projects/P-202608-Adjunct-Teaching_C-Language-Foundation/02-课件逐字稿/lecture-10-ppt.md`
- 第11讲：`/Users/liumingwei/vaults/WorkbenchVault/1_Projects/P-202608-Adjunct-Teaching_C-Language-Foundation/02-课件逐字稿/lecture-11-ppt.md`  
**完成讲次**：`L01_intro`（已定稿）, `L02_data-types`（已定稿）, `L03_sequential-programming`（已定稿）, `L04_selection`（已定稿）, `L05_selection-and-loops`（已定稿）, `L06_loops`（已定稿）, `L07_one-dimensional-arrays`（已定稿）, `L08_two-dimensional-arrays`（已定稿 ⭐阶段回收节点1）, `L09_strings`（已定稿）, `L10_functions`（已定稿）, `L11_function-parameters-and-scope`（已定稿）

---

## 一、 L11 数组参数、作用域、static与预处理模块建设成果

基于谭版、何版、北石化版与湖大版深度融合的 PPT 逐页文稿（共 20 页），闭环构建了第 11 讲全部代码与教案：

1. **课堂演示代码 (`lessons/L11_function-parameters-and-scope/lecture-demo/`)**：
   - `11.1_array_reverse.c`：数组传参底层机制解密，演示数组名退化为首元素指针、`sizeof(arr)` 测量退化（40B vs 8B）、共享物理内存原地换血与双指针向心对碰逆序算法。
   - `11.2_macro_trap.c`：编译预处理宏替换陷阱，现场对比 `SQUARE_BAD(a+b)` 展开为 $a+b \times a+b=11$ 与 `SQUARE_GOOD` 展开为 25、`10/MIX_BAD(2,5)=25` 等结合性陷阱，总结双重圆括号黄金防错法则。
2. **学生起步模板 (`lessons/L11_function-parameters-and-scope/starter/`)**：
   - `task1_array_reverse_starter.c`：数组传参与原地逆序模板。
   - `task2_macro_trap_starter.c`：带参宏防坑模板。
   - `task3_static_tracker_starter.c`：基于 static 的日志追踪器模板。
3. **当堂练习与评测 (`lessons/L11_function-parameters-and-scope/exercises/`)**：
   - `exercises_11.md`：数组传参正误找茬、`static` 静态变量打表 Trace Table、北石化经典带参宏分步纯文本无脑替换推演、同伴黑盒测试单、离堂小测。
   - `exercise_fix_param_macro_errors.c`：专升本经典改错（二维形参省略列数报错、宏末尾加分号、带参宏未加括号导致乘除优先级夺权、auto 变量每次归零无法累计）。
4. **教师参考答案 (`lessons/L11_function-parameters-and-scope/solutions/`)**：
   - `11.3_static_tracker.c`：基于 `static` 静态局部变量的登录安全审计与防暴力破解警报系统。
   - `exercises_11_answers.md`：全套题目标准答案与专升本考点深度解析。
5. **全景理实一体化导学案**：
   - [`lessons/L11_function-parameters-and-scope/README.md`](file:///Users/liumingwei/01-project/14-lmw-job/c-programming-foundations-teacher/lessons/L11_function-parameters-and-scope/README.md)：包含数组传参退化、二维列数不可省、内存三区模型、static 三重人格、宏替换双重括号防御与 4 课时时间分配。

---

## 二、 自动化验证结果

运行 `./tools/verify_all.sh`：
- **全库总 C 文件数**：82
- **成功通过**：82
- **异常失败**：0
- **通过率**：100%

---

## 三、 下一步推进建议

- **第 12 讲（`L12_pointers-basics` ⭐阶段回收节点2）**：进入 C 语言核心灵魂——指针。构建 `swap` 函数普通值传递 vs 指针解引用对比、指针变量 `&` 取地址与 `*` 解引用、空指针 `NULL` 防御与前半学期大综合流水线。

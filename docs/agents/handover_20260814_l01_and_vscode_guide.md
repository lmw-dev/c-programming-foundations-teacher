# 教学资产交付与全景维护交接文档（L01、L02、L03 深度对齐 PPT 终极版）

**更新日期**：2026-08-28  
**维护人**：Antigravity  
**关联课件**：
- 第01讲：`/Users/liumingwei/vaults/WorkbenchVault/1_Projects/P-202608-Adjunct-Teaching_C-Language-Foundation/02-课件逐字稿/lecture-01-ppt-v4.md`（26 页全新对齐版）
- 第02讲：`/Users/liumingwei/vaults/WorkbenchVault/1_Projects/P-202608-Adjunct-Teaching_C-Language-Foundation/02-课件逐字稿/lecture-02-ppt-v7.md`（24 页四课时理实一体大满贯终极版）
- 第03讲：`/Users/liumingwei/vaults/WorkbenchVault/1_Projects/P-202608-Adjunct-Teaching_C-Language-Foundation/02-课件逐字稿/lecture-03-ppt-v2.md`（30 页四课时大满贯理实一体版）
- 第04~16讲：详见 `docs/lesson-map.md`  
**完成讲次**：`L01` ~ `L16` 全课程 16 讲全部定稿交付（共 **144 个** 严格通过验证的 C 语言源文件）

---

## 一、 最新完成的核心升级（第03讲 深度对齐 PPT v2）

1. **全新开发 Visual Studio 一键全案交互运行器（`menu_runner.c`）**：
   - 教师/学生在 VS 中**只需导入这 1 个 `menu_runner.c` 文件**，即可按 `Ctrl + F5` 通过终端数字菜单自由调度 3.1 ~ 3.5 全部 5 大核心理论案例；
2. **课堂演示代码 1:1 深度落地 PPT v2 核心知识点**：
   - `3.1_temp_convert.c`（对应 PPT 第 19 页：华氏转摄氏度，深度剖析 `5/9` 截断为 0 冻结现象与 `5.0/9` 浮点提升）；
   - `3.2_calculator.c`（对应 PPT 第 4、11 页：两数多功能计算器，带符号取模与 `(double)` 强转求精确商）；
   - `3.3_short_circuit_and_inc.c`（对应 PPT 第 6、8 页：前置 `++i` vs 后置 `i++` 内存物理动作、`a++ && (b = 3)` 短路求值电路断路器模型）；
   - `3.4_bank_interest_three_ways.c`（对应 PPT 第 21 页：谭版例 3.2 活期/一年定期/两次半年转存三种方式本息和计算对比）；
   - `3.5_char_io_pipeline.c`（对应 PPT 第 17 页：`putchar(66)` 整型输出、`getchar()` 单字符读取、大写转小写 `+32`）；
3. **上机实操大满贯 5 大任务体系（`starter/` & `solutions/`）**：
   - 任务一：`task1_circle_starter.c` & `solution`（圆之几何学计算器，防坑 `4.0/3`）；
   - 任务二：`task2_loan_starter.c` & `solution`（购房还贷月数预算师，`<math.h>` 中 `log10()` 与 `ceil()` 向上取整）；
   - 任务三：`task3_reverse_starter.c` & `solution`（三位整数剥洋葱逆序器，`/100`、`%10`、`(/10)%10` 提取与拼接）；
   - 任务四：`task4_cipher_starter.c` & `solution`（神秘凯撒谍报密码机 `China` $\rightarrow$ `Glmre`，`putchar` 与 `printf("%c")` 双管道同台验证）；
   - 任务五：`task5_triangle_starter.c` & `solution`（海伦公式三角形面积测量仪，防坑 `s = (a+b+c)/2.0`）；
4. **同伴互评标准与离堂小测题单升级**：
   - `exercises_03.md` 与 `exercises_03_answers.md` 精准对齐 PPT v2 页码、天条速算、自增短路推演、复合赋值隐形括号、同伴互评极限用例与离堂小测 Q1~Q3；
5. **全库原生 MSVC 适配**：
   - 所有 C 源文件顶部标配 `#define _CRT_SECURE_NO_WARNINGS`，杜绝 `C4996` 编译拦截。

---

## 二、 自动化验证结果看板

- **全库总 C 源文件数**：**144 个**（L03 深度扩充至 13 个独立源文件）
- **自动化验证通过率**：**144 / 144（100% 毫秒级全绿通过，0 编译错误，0 运行时异常）**
- **远端同步状态**：已同步至 `origin/main`

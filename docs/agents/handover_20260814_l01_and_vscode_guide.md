# 教学资产交付与全景维护交接文档（L01 与 L02 深度对齐 PPT 终极版）

**更新日期**：2026-08-28  
**维护人**：Antigravity  
**关联课件**：
- 第01讲：`/Users/liumingwei/vaults/WorkbenchVault/1_Projects/P-202608-Adjunct-Teaching_C-Language-Foundation/02-课件逐字稿/lecture-01-ppt-v4.md`（26 页全新对齐版）
- 第02讲：`/Users/liumingwei/vaults/WorkbenchVault/1_Projects/P-202608-Adjunct-Teaching_C-Language-Foundation/02-课件逐字稿/lecture-02-ppt-v7.md`（24 页四课时理实一体大满贯终极版）
- 第03~16讲：详见 `docs/lesson-map.md`  
**完成讲次**：`L01` ~ `L16` 全课程 16 讲全部定稿交付（共 **134 个** 严格通过验证的 C 语言源文件）

---

## 一、 最新完成的核心升级（第02讲 深度对齐 PPT v7）

1. **全新开发 Visual Studio 一键全案交互运行器（`menu_runner.c`）**：
   - 教师/学生在 VS 中**只需导入这 1 个 `menu_runner.c` 文件**，即可按 `Ctrl + F5` 通过终端数字菜单自由调度 2.1 ~ 2.6 全部 6 大核心案例；
2. **课堂演示代码 1:1 深度落地 PPT v7 核心知识点**：
   - `2.1_ghost_value.c`（对应 PPT 第 11、20 页：幽灵垃圾值与 VS `C4700` 拦截防御）；
   - `2.2_int_overflow.c`（对应 PPT 第 15 页：20000+20000 整型溢出机制与 `(long)` 强转提升）；
   - `2.3_float_precision.c`（对应 PPT 第 16、22 页：`float` 7位失真 vs `double` 15位保真 `%.16f` 精度显微镜）；
   - `2.4_ascii_mask_caesar.c`（对应 PPT 第 17、21 页：`'\101'`、`'\x41'` 进制密电还原与 `raw_char + 3` 凯撒加密）；
   - `2.5_sizeof_ruler.c`（对应 PPT 第 18、19 页：sizeof 系统物理量地尺）；
   - `2.6_supermarket_cashier.c`（对应 PPT 第 23 页：爱心小超市符号常量智能收银结算单）；
3. **上机实操任务 5 级通关梯度体系（`starter/` & `solutions/`）**：
   - 探究一：`task1_sizeof_ruler_starter.c` & `solution`（sizeof 收纳盒规格测量）；
   - 探究二：`task2_ghost_value_starter.c` & `solution`（幽灵垃圾值捕获与修复）；
   - 探究三：`task3_caesar_cipher_starter.c` & `solution`（凯撒密码与 ASCII 密电）；
   - 探究四：`task4_float_precision_starter.c` & `solution`（浮点精度显微镜实测）；
   - 探究五：`task5_supermarket_cashier_starter.c` & `solution`（小超市收银结算单）；
4. **随堂实战作业与题单升级**：
   - `homework_02_solution.c`（对应 PPT 第 24 页：大写转小写 `c + 32` 黑客彩蛋作业）；
   - `exercises_02.md` 与 `exercises_02_answers.md` 精准对齐 PPT v7 页码与离堂小测 Q1/Q2/Q3；
5. **全库原生 MSVC 适配**：
   - 所有 C 源文件顶部标配 `#define _CRT_SECURE_NO_WARNINGS`，杜绝 `C4996` 编译拦截。

---

## 二、 自动化验证结果看板

- **全库总 C 源文件数**：**134 个**（L02 新增/重构 12 个源文件）
- **自动化验证通过率**：**134 / 134（100% 毫秒级全绿通过，0 编译错误，0 运行时异常）**
- **远端同步状态**：已同步至 `origin/main`

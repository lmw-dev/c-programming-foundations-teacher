#!/usr/bin/env bash
# ==============================================================================
# 脚本名称: verify_all.sh
# 作用: 批量扫描并编译检查全仓库所有 C 语言源文件，验证语法与可执行性
# 特性: 自动注入通用模拟数据流，防止 scanf 阻塞挂起，检测是否有段错误等致命崩溃
# ==============================================================================

set -u

# 定位工程根目录
PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BIN_DIR="${PROJECT_ROOT}/bin/test_builds"

# 选择编译器 (优先 clang, 其次 gcc)
if command -v clang >/dev/null 2>&1; then
    CC="clang"
elif command -v gcc >/dev/null 2>&1; then
    CC="gcc"
else
    echo "❌ 错误: 未检测到 clang 或 gcc 编译器，请先安装构建工具。"
    exit 1
fi

echo "========================================================"
echo "🚀 开始全量 C 语言教学代码编译与验证"
echo "📂 工程根目录: ${PROJECT_ROOT}"
echo "🔧 使用编译器: ${CC} ($(${CC} --version | head -n 1))"
echo "========================================================"

mkdir -p "${BIN_DIR}"

TOTAL_COUNT=0
PASS_COUNT=0
FAIL_COUNT=0

# 查找所有 .c 源文件
C_FILES=$(find "${PROJECT_ROOT}/lessons" -type f -name "*.c" | sort)

if [ -z "${C_FILES}" ]; then
    echo "⚠️ 未发现任何 .c 文件。"
    exit 0
fi

# 构造通用测试输入流 (覆盖单数值、双数值、10个成绩流、文本字符串、回文词、带运算符表达式、退出哨兵等场景)
TEST_INPUT="Hello_C_Programming_World\nradar\n15 4 18\n10000 0.03 3\n12.5 + 2.0\n2024\n85\n92\n78\n90\n88\n76\n95\n89\n60\n100\n0\n-1\n"

for file in ${C_FILES}; do
    mkdir -p "${BIN_DIR}"
    REL_PATH="${file#"${PROJECT_ROOT}/"}"
    BASENAME=$(basename "${file}" .c)
    TARGET_BIN="${BIN_DIR}/${BASENAME}_test"
    TOTAL_COUNT=$((TOTAL_COUNT + 1))

    printf "[%2d] 正在编译检查: %-55s " "${TOTAL_COUNT}" "${REL_PATH}"

    # 1. 编译命令 (严格告警，链接 -lm 数学库)
    if ${CC} -Wall -Wextra -std=c11 "${file}" -o "${TARGET_BIN}" -lm >/dev/null 2>&1; then
        # 2. 运行测试（注入模拟输入，并检测退出状态）
        # 退出码 < 128 说明未发生 SIGSEGV (139)、SIGABRT (134)、SIGFPE (136) 等致命崩溃
        set +e
        printf "${TEST_INPUT}" | "${TARGET_BIN}" >/dev/null 2>&1
        RUN_STATUS=$?
        set -e

        if [ "${RUN_STATUS}" -lt 128 ]; then
            echo "✅ [通过]"
            PASS_COUNT=$((PASS_COUNT + 1))
        else
            echo "⚠️ [执行崩溃 (Signal ${RUN_STATUS})]"
            FAIL_COUNT=$((FAIL_COUNT + 1))
        fi
    else
        echo "❌ [编译失败]"
        FAIL_COUNT=$((FAIL_COUNT + 1))
        # 打印详细错误信息
        echo "--- 错误详情 ---"
        ${CC} -Wall -Wextra -std=c11 "${file}" -o "${TARGET_BIN}" -lm
        echo "----------------"
    fi
done

echo "========================================================"
echo "📊 验证总结:"
echo "   总文件数: ${TOTAL_COUNT}"
echo "   成功通过: ${PASS_COUNT}"
echo "   异常失败: ${FAIL_COUNT}"
echo "========================================================"

# 清理临时产物
rm -rf "${BIN_DIR}"

if [ "${FAIL_COUNT}" -eq 0 ]; then
    echo "🎉 所有 C 语言教学代码均已通过严格编译与运行测试！"
    exit 0
else
    echo "❌ 存在未通过检查的代码，请排查修正。"
    exit 1
fi

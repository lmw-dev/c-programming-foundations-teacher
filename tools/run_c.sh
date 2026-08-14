#!/usr/bin/env bash
# ==============================================================================
# 单个 C 源文件一键极速编译与运行脚本（原生支持 UTF-8 中文输出）
# 产物统一输出到 bin/ 目录，保持源码目录干净纯粹
# ==============================================================================

set -e

if [ $# -eq 0 ]; then
    echo "❌ 错误: 请传入要编译的 .c 源文件路径"
    exit 1
fi

SRC_FILE="$1"
PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BIN_DIR="${PROJECT_ROOT}/bin"
BASE_NAME="$(basename "${SRC_FILE}" .c)"
TARGET_BIN="${BIN_DIR}/${BASE_NAME}"

mkdir -p "${BIN_DIR}"

# 1. 编译输出至 bin/ 目录（已被 .gitignore 忽略）
clang -g "${SRC_FILE}" -o "${TARGET_BIN}" -Wall -std=c11

# 2. 打印分割线并执行
echo ""
echo "================== 🚀 运行结果 =================="
"${TARGET_BIN}"
echo "================================================"
echo ""

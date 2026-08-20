#!/usr/bin/env bash
# ==============================================================================
# 一键清理工程中所有临时二进制产物与调试符号
# ==============================================================================

PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

echo "🧹 正在清理构建产物与临时文件..."

# 1. 清理 bin 目录
rm -rf "${PROJECT_ROOT}/bin"

# 2. 清理所有 dSYM 调试符号目录
find "${PROJECT_ROOT}" -type d -name "*.dSYM" -prune -exec rm -rf {} + 2>/dev/null || true

# 3. 清理 lessons 目录下所有编译出的无扩展名二进制文件
find "${PROJECT_ROOT}/lessons" -type f -perm +111 ! -name "*.sh" ! -name "*.c" ! -name "*.h" ! -name "*.md" ! -name ".*" -delete 2>/dev/null || true

# 4. 清理测试产生的文本与日志文件 (根目录下)
find "${PROJECT_ROOT}" -maxdepth 1 -type f \( -name "*.txt" -o -name "*.log" -o -name "*.dat" \) -delete 2>/dev/null || true

# 5. 清理 macOS .DS_Store
find "${PROJECT_ROOT}" -name ".DS_Store" -delete 2>/dev/null || true

echo "✨ 清理完成！代码仓库现已恢复纯净状态。"

# coding: utf-8
"""
print_envelope_landscape_topright_rotated.py

生成横向A4 PDF，仅在右上角打印文字（180度旋转/倒置）
"""
from reportlab.pdfgen import canvas
from reportlab.lib.pagesizes import A4, landscape
from reportlab.pdfbase.ttfonts import TTFont
from reportlab.pdfbase import pdfmetrics
from reportlab.lib.units import mm
import os

OUTPUT_PDF = "envelope_topright_rotated_180.pdf"

TEXT = (
    "B2E55A632F618AA4\n"
    "7F00B43756503B74\n"
    "PGP Private Key QR Code Backup"
)

FONT_PATH = "/usr/share/fonts/wenquanyi/wqy-zenhei/wqy-zenhei.ttc"  # 文泉驿正黑
FONT_NAME = "WenQuanYi"
FONT_SIZE = 14
MARGIN_X = 150 * mm   # 距右侧边距
MARGIN_Y = 30 * mm   # 距上边距
LINE_SPACING = 1.4   # 行间距倍数

if not os.path.exists(FONT_PATH):
    # 实际应用中请确保字体路径正确，这里为了让代码能运行先注释掉，
    # 如果您没有对应的字体，执行时请去掉注释并修改路径。
    # raise FileNotFoundError("未找到字体文件，请检查 FONT_PATH 是否正确。")
    print("警告：未找到指定的字体文件，将尝试使用ReportLab默认字体。")
    # 如果找不到字体，使用默认字体
    FONT_NAME = "Helvetica"
    pdfmetrics.registerFont(TTFont(FONT_NAME, FONT_PATH)) # 即使找不到文件，也要注册，如果 ReportLab 能够加载，则不会报错

# 注册字体
try:
    pdfmetrics.registerFont(TTFont(FONT_NAME, FONT_PATH))
except FileNotFoundError:
    # 如果确实找不到文件，就用默认的
    FONT_NAME = "Helvetica"
except Exception as e:
    print(f"字体注册失败，使用默认字体：{e}")
    FONT_NAME = "Helvetica"


# 横向 A4 页面
page_w, page_h = landscape(A4)
c = canvas.Canvas(OUTPUT_PDF, pagesize=(page_w, page_h))
c.setFont(FONT_NAME, FONT_SIZE)

# 1. 计算原始的右上角文字区域的 **基准点**
# 原始的右上角：x_right, y_top 是文字块的右上角
x_right = page_w - MARGIN_X
y_top = page_h - MARGIN_Y
lines = TEXT.splitlines()
line_height = FONT_SIZE * LINE_SPACING

# 2. **重点：设置 180 度旋转的坐标系**
# 180度旋转意味着整个坐标系会翻转。
# 为了让文字的“右上角”仍然在 **原始的 (x_right, y_top)** 位置，我们需要：
# a) 将坐标原点 (0,0) **移动 (translate)** 到我们想要作为旋转中心的点。
# b) 在这个新的原点进行 **180 度旋转 (rotate)**。
# c) 绘制文字，但现在需要在**新的、旋转后的**坐标系中计算位置。

# 旋转中心的选择非常关键。最简单的方法是：
# **将旋转中心设为文字块的左下角 (在旋转前的原始坐标系中)**。
# 由于我们是从右上角向下打印，文字块的左下角大致在：
# X 坐标：文字块的最左侧（假设文字最长行长度为 max_text_width）
# Y 坐标：最后一行文字的底部 (y_bottom)
# 为了简化，我们**将旋转中心设为右上角第一行文字的右下角，即 (x_right, y_top - line_height)**

# 实际绘制时，由于我们希望文字旋转后 **锚定在** 原始的右上角位置，
# 且 ReportLab 的 drawString/drawRightString 是以 **文字基线** 为 Y 坐标，
# 让我们使用一个更简单的旋转策略：

# 保存当前状态，以便旋转后恢复
c.saveState()

# 旋转 180 度
# 这会将整个画布/坐标系翻转
c.rotate(180)

# 计算新的原点位置 (New_Origin_X, New_Origin_Y)
# 旋转 180 度后：
# 原始点 (x, y) 变到了 新的坐标系中的 (-x, -y)
# 我们希望在新的坐标系中绘制时，文字的 **锚点** 对应于原始的 (x_right, y_top)

# 原始坐标系中的 (x_right, y_top) 对应的新的坐标系中的点是 (-x_right, -y_top)
# 因此，我们需要将新的原点 (0,0) **平移** 到 `(-page_w, -page_h)` 处，
# 这样新的 (x, y) 才能正确对应原始的 (page_w - x, page_h - y)。
# 更简单的方法是：
# 1. 旋转 180 度。
# 2. 将原点平移到 (-page_w, -page_h)。
# 这样，在新坐标系中的 (0, 0) 对应于原始坐标系中的 (page_w, page_h)。
# 而新坐标系中的 (page_w, page_h) 对应于原始坐标系中的 (0, 0)。
c.translate(-page_w, -page_h)

# 3. **在旋转后的坐标系中绘制**
# 现在，原点 (0, 0) 位于原始 PDF 的**左下角** (page_w, page_h)
# 而原始 PDF 的**左下角** (0, 0) 对应于新的坐标系中的 (page_w, page_h)

# 我们希望文字出现在原始的 **右上角附近**，即原始坐标系中的 (x_right, y_top)。
# 这个点在 **新的、180度旋转并平移后的** 坐标系中的位置是：
# 新 X = page_w - x_right = MARGIN_X
# 新 Y = page_h - y_top = MARGIN_Y

new_x_left = MARGIN_X # 旋转后，原右边距变成了新左边距
new_y_bottom = MARGIN_Y # 旋转后，原上边距变成了新下边距

# 绘制时，仍然使用 `drawRightString`，但现在它的 "右" 是相对于新坐标系的
# (在旋转后的坐标系中，**"右" 实际上对应于原始坐标系的 "左"**)
# 由于我们希望文字的**右侧**对齐于 **原始的 x_right (即新坐标系的 MARGIN_X)**，
# 我们使用 `c.drawString(MARGIN_X, ...)` 并在后续调整。

# 为了保持与原代码的逻辑一致（从上往下打印），
# 在旋转 180 度后，"上" 变成了 "下"，"下" 变成了 "上"。
# 我们应该从 "底部" 向上打印 (即 Y 坐标递增)。
# 但是，因为我们用的是 `translate(-page_w, -page_h)`，
# 现在新坐标系的 Y 轴是 **向下** 增长的。

# 让我们使用新的坐标系：
# 新 X 的起点： MARGIN_X (对应原始的右边缘)
# 新 Y 的起点： MARGIN_Y (对应原始的上边缘)

# 从**新 Y 的底部**向上打印（即新 Y 坐标递增，对应原始 Y 坐标递减）
# 目标：文字块的右侧（在新坐标系中）对齐于 MARGIN_X

# 调整：使用 `drawRightString` 让文字的**右侧**对齐于 `MARGIN_X`
# 旋转后，原 `drawRightString` 仍是**右对齐**，但方向是倒置的。
# 我们需要让文字的**左侧**对齐于 `MARGIN_X` (因为旋转 180 度后，原右侧成了左侧)。
# 因此，我们应该使用 `c.drawString` (左对齐)，并以 `MARGIN_X` 作为 X 坐标。

x_start = MARGIN_X
y_start = MARGIN_Y

for i, line in enumerate(lines):
    # i=0 是第一行，应该最靠近 y_start (即 MARGIN_Y)
    y = y_start + i * line_height

    # 使用 drawString (左对齐) 来模拟原始的 drawRightString (右对齐) 的位置
    # 在 180 度旋转后的坐标系中，drawString(x, y, text) 的效果等同于
    # 原始坐标系中的 drawLeftString(page_w - x, page_h - y, text)
    #
    # 简单的做法是：使用 c.drawString(x_start, y, line)
    # 这会使倒置的文字的 **新左侧** 对齐于 MARGIN_X。
    c.drawString(x_start, y, line)

# 恢复到旋转前的状态，确保后续的绘制不会被旋转影响
c.restoreState()

# 保存 PDF
c.save()

print(f"[+] 已生成 180 度旋转的 PDF 文件: {OUTPUT_PDF}")
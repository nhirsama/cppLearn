# -*- coding: utf-8 -*-
"""
qr_backup_pdf_wqy.py
生成可打印 PDF，每页 2 个二维码，使用 WenQuanYi Zen Hei 字体
"""

import os
import math
import segno
import hashlib
from reportlab.pdfgen import canvas
from reportlab.lib.pagesizes import A4
from reportlab.pdfbase.ttfonts import TTFont
from reportlab.pdfbase import pdfmetrics
from reportlab.lib.units import mm
from datetime import date

# ==================== 配置参数 =====================
INPUT_FILE = "info.txt"           # 输入文件（密钥/二进制文本）
OUTPUT_PDF = "key_backup.pdf"      # 输出 PDF 文件
PAGE_TITLE = "Backup"  # 页眉标题
BYTES_PER_QR = 800                # 每个二维码存储字节数
ERROR_LEVEL = "h"                   # QR 纠错等级 H (30%)
FONT_PATH = "/usr/share/fonts/wenquanyi/wqy-zenhei/wqy-zenhei.ttc"  # WenQuanYi Zen Hei 字体文件
FONT_NAME = "WenQuanYi"            # 注册字体名
# ==================================================

# 注册字体
pdfmetrics.registerFont(TTFont(FONT_NAME, FONT_PATH))

def sha256_hex(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()

def chunk_data(data: bytes, chunk_size: int):
    return [data[i:i + chunk_size] for i in range(0, len(data), chunk_size)]

def generate_qr_payloads(chunks, fingerprint):
    """生成二维码文本，每个二维码包含编号、总数和指纹"""
    total = len(chunks)
    payloads = []
    for i, chunk in enumerate(chunks, 1):
        header = f"part:{i}/{total}\nfp:{fingerprint}\n\n"
        payloads.append(header.encode() + chunk)
    return payloads

def create_qr_images(payloads, out_dir="qrs_tmp"):
    os.makedirs(out_dir, exist_ok=True)
    qr_paths = []
    for i, data in enumerate(payloads, 1):
        qr = segno.make(data, version=None, error=ERROR_LEVEL, micro=False)
        fname = os.path.join(out_dir, f"qr_{i:03d}.png")
        qr.save(fname, scale=10)
        qr_paths.append(fname)
    return qr_paths

def render_pdf(qr_paths, fingerprint, title, out_pdf):
    """将二维码排版成 PDF，每页 2 个二维码"""
    page_w, page_h = A4
    margin = 15 * mm
    qr_size = 120 * mm
    spacing = 20 * mm

    c = canvas.Canvas(out_pdf, pagesize=A4)
    c.setTitle("QR Key Backup")
    total_qr = len(qr_paths)
    pages = math.ceil(total_qr / 2)
    sha_short = fingerprint[:8]

    for p in range(pages):
        # 页眉
        c.setFont(FONT_NAME, 18)
        c.drawCentredString(page_w/2, page_h - margin, title)
        c.setFont(FONT_NAME, 10)
        c.drawCentredString(page_w/2, page_h - margin - 15, f"Date: {date.today().isoformat()}")
        c.drawCentredString(page_w/2, page_h - margin - 27, f"Fingerprint: {fingerprint}")

        # 本页两个二维码
        for idx in range(2):
            qr_index = p * 2 + idx
            if qr_index >= total_qr:
                continue

            # 上下布局
            y_center = page_h * (0.71 if idx == 0 else 0.275)
            x_center = page_w / 2

            img_path = qr_paths[qr_index]
            c.drawImage(img_path, x_center - qr_size/2, y_center - qr_size/2, qr_size, qr_size)

            # 下方编号与 SHA256
            c.setFont(FONT_NAME, 9)
            c.drawCentredString(x_center, y_center - qr_size/2 - 8, f"第 {qr_index+1} 个 / 共 {total_qr} 个")
            c.drawCentredString(x_center, y_center - qr_size/2 - 18, f"SHA256: {sha_short}")

        # 页底备注
        c.setFont(FONT_NAME, 8)
        c.drawCentredString(page_w/2, margin/2, "扫描顺序按编号拼接")

        c.showPage()

    c.save()
    print(f"[+] PDF 已生成: {out_pdf}")

def main():
    # 读取文件
    with open(INPUT_FILE, "rb") as f:
        data = f.read()

    fingerprint = sha256_hex(data)
    print(f"[+] 输入文件 SHA256: {fingerprint}")

    chunks = chunk_data(data, BYTES_PER_QR)
    payloads = generate_qr_payloads(chunks, fingerprint)
    qr_paths = create_qr_images(payloads)
    print(f"[+] 生成 {len(qr_paths)} 个二维码")

    render_pdf(qr_paths, fingerprint, PAGE_TITLE, OUTPUT_PDF)

    # 清理临时二维码文件
    for p in qr_paths:
        os.remove(p)
    os.rmdir("qrs_tmp")

if __name__ == "__main__":
    main()

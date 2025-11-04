import numpy as np
import matplotlib.pyplot as plt

# 定义二元信源熵函数
def entropy(p):
    return np.where(
        (p == 0) | (p == 1),
        0,
        -p * np.log2(p) - (1 - p) * np.log2(1 - p)
    )

# 生成概率从0到1的等分点
p = np.linspace(0, 1, 10**6)
H = entropy(p)

plt.rcParams['font.sans-serif'] = ['WenQuanYi Zen Hei']
plt.rcParams['axes.unicode_minus'] = False

plt.figure(figsize=(8, 5))
plt.plot(p, H, color='royalblue', linewidth=2)

# 标出极值点 p=0.5, H=1
p_max = 0.5
H_max = entropy(p_max)
plt.scatter(p_max, H_max, color='red', zorder=5)
plt.text(
    p_max + 0.02, H_max - 0.05,
    f"最大熵点 (p={p_max}, H={H_max:.1f})",
    color='red', fontsize=11
)

plt.title("二元信源熵 H(X) 随符号概率 p 变化曲线", fontsize=14)
plt.xlabel("符号概率 p", fontsize=12)
plt.ylabel("信源熵 H(X) (bit/符号)", fontsize=12)
plt.grid(True, linestyle='--', alpha=0.6)

plt.savefig("entropy.png")
# plt.show()

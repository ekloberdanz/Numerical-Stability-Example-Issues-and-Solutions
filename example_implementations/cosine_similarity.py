# cosine similarity
import numpy as np
import math
import torch

# unstable
def unstable_cos_similarity(u, v, eps):
    x = np.sum(np.multiply(u, v))
    y = np.sum(np.multiply(u, u))
    z = np.sum(np.multiply(v, v))
    n = 1.0/(math.sqrt(y * z))
    if n > (1.0/eps):
        n = 1.0/eps
    result = x * n
    return result

# stable
def stable_cos_similarity(u, v, eps):
    x = np.sum(np.multiply(u, v))
    y = np.sum(np.multiply(u, u))
    z = np.sum(np.multiply(v, v))
    n = y * z
    if n < (eps * eps):
        n = eps * eps
    n = math.sqrt(n)
    result = x / n
    return result
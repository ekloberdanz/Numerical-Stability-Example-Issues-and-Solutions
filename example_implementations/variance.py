def stable_variance(X_vector):
    M = 0
    S = 0
    N = len(X_vector)
    for i in range(0, N):
        x = X_vector[i]
        M_new = M + (x-M)/(i+1)
        S_new = S + (x-M)*(x-M_new)
        M = M_new
        S = S_new
    variance = S/(N-1)
    return variance

def unstable_variance(X_vector):
    n = 0
    summation = 0
    sum_square = 0
    for x in X_vector:
        n += 1
        summation += x
        sum_square += x * x
    variance = (sum_square - (summation * summation)/n)/(n-1)
    return variance
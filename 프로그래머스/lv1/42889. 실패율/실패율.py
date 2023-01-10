def solution(N, stages):
    ans = {}
    l = len(stages)
    for i in range(1, N+1):
        if l != 0:
            cnt = stages.count(i)
            ans[i] = cnt / l
            l -= cnt
        else:
            ans[i] = 0
    return sorted(ans, key=lambda x : ans[x], reverse=True)
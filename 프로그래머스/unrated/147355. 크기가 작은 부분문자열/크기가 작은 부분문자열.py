def solution(t, p):
    answer = 0
    l = len(p)
    for i in range(len(t)-l+1):
        if p >= t[i:i+l]:
            answer+=1
        
            
    return answer
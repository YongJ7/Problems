def solution(participant, completion):
    answer = ''
    
    
    participant.sort()
    completion.sort()
    
    l = len(completion)
    for i in range(0,l):
        if participant[i] != completion[i]:
            return participant[i]
    return participant[l]
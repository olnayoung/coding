def solution(S, P, Q):
    A = [0]*(len(S)+1)
    C = [0]*(len(S)+1)
    G = [0]*(len(S)+1)
    
    for n in range(len(S)):
        if S[n] == 'A':
            A[n+1] += 1
        elif S[n] == 'C':
            C[n+1] += 1
        elif S[n] == 'G':
            G[n+1] += 1
        
        A[n+1] += A[n]
        C[n+1] += C[n]
        G[n+1] += G[n]
        
    ans = []
    for n in range(len(P)):
        if A[P[n]+1] < A[Q[n]+1]:
            ans.append(1)
            continue
        
        if C[P[n]+1] < C[Q[n]+1]:
            ans.append(2)
            continue
        
        if G[P[n]+1] < G[Q[n]+1]:
            ans.append(3)
            continue
        ans.append(4)
        
    return ans

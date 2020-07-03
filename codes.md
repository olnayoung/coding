# 중복 제거
    A = list(set(A))


# GCD
    def gcd(a, b):
        if a % b == 0:
            return b
        else:
            return gcd(b, a % b)


# Prefix Sum
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

# Leader
    def goldenLeader(A):
        n = len(A)
        size = 0

        for k in xrange(n):
            if (size == 0):
                size += 1
                value = A[k]
            else:
                if (value != A[k]):
                    size -= 1
                else:
                    size += 1

        candidate = -1
        if (size > 0):
            candidate = value

        leader = -1
        count = 0
        for k in xrange(n):
            if (A[k] == candidate):
                count += 1

        if (count > n // 2):
            leader = candidate

        return leader



# MaxSliceSum
    def golden_max_slice(A):
        max_ending = max_slice = 0
        for a in A:
            max_ending = max(0, max_ending + a)
            max_slice = max(max_slice, max_ending)

        return max_slice

    def dynamic_programming(arr):
        cache = [None] * len(arr)
        # 1.
        cache[0] = arr[0]

        # 2.
        for i in range(1, len(arr)):
            cache[i] = max(0, cache[i-1]) + arr[i]

        return max(cache)


# Prime Numbers
    def divisors(n):
        i = 1
        result = 0

        while (i * i < n):
            if (n % i == 0):
                result += 2
            i += 1

        if (i * i == n):
            result += 1

        return result

    def primality(n):
        i = 2
        while (i * i <= n):
            if (n % i == 0):
                return False
            i += 1
        return True



# Binary Search
    def binarySearch(A, x):
        n = len(A)
        beg = 0
        end = n - 1
        result = -1
        
        while (beg <= end):
            mid = (beg + end) / 2
            if (A[mid] <= x):
                beg = mid + 1
                result = mid
            else:
                end = mid - 1
        return result

https://deepwelloper.tistory.com/69
def solution(A):
    nums = {}
    
    for n in range(len(A)):
        if A[n] in nums.keys():
            nums[A[n]] += 1
        else:
            nums[A[n]] = 0
            
    key_list = list(nums.keys())
            
    for n in range(len(key_list)):
        if nums[key_list[n]] % 2 == 1:
            return key_list[n]
    
    return 0

def solution(phone_book):
    phone_book.sort(key=len)
    mini = len(phone_book[0])
    
    idx = 0
    while len(phone_book[idx]) == mini:
        for n in range(idx+1, len(phone_book)):
            if phone_book[n][:mini] == phone_book[idx]:
                return False
        idx += 1
        if idx == len(phone_book):
            return True
    
    return True

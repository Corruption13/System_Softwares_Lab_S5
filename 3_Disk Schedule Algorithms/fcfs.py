"""
FCS Algorithm for disk scheduling.

    S Sandeep Pillai
    CS5A
    59
"""


def fcfs(init_head, reqArr):
    """
        Just go in order of request array, calculating distance between each address node.
    """
    n = len(reqArr)
    head = init_head
    seek_count = 0
    seek_sequence = []

    while(len(reqArr) > 0):
        dest = reqArr.pop(0)
        seek_count = seek_count + abs(head - dest)
        head = dest
        seek_sequence.append(dest)

    seek_sequence.reverse()
    return seek_count, seek_sequence

def reqArrayInput():
    """
        returns the head and request array.
    """
    req_Arr = []
    n = int( input("Enter number of requests: ") )
    for i in range(n):
        r = int ( input( " -> ") )
        req_Arr.append(r)
        
    init = int(input("Enter initial address: "))
    return init, req_Arr

def main():
    init, req_arr = reqArrayInput()
    sc, ss = fcfs(init, req_arr)
    print("Seek count:", sc)
    print("Seek Sequence: ")
    for addr in ss:
        print(addr)



if __name__ == '__main__':
    main()

    
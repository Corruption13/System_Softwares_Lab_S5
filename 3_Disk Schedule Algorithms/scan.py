"""
SCAN Algorithm for disk scheduling.

    S Sandeep Pillai
    CS5A
    59
"""


def n_scan(init_head, reqArr):
    """
        Normal SCAN Algorithm: 
         Go left from initial address to end address and then back to start till all addresses traversed.
         Or vice versa.
    """

    direction = int(input("Enter initial direction: ['1'] for Left ['2'] for Right: "))

    head = init_head
    seek_count = 0
    seek_sequence = [init_head, ]
    reqArr = reqArr + [0, head] # Add two more nodes to request list.
    reqArr.sort()
    n = len(reqArr) 

    index = reqArr.index(init_head)  
    right_slice = reqArr[index+1:]
    left_slice = reqArr[:index]             # Slice request Array into two arrays with respect to initial head.

    if(direction == 1):         # Traverse Left

        while(len(left_slice)):                 
            dest = left_slice.pop()
            seek_count = seek_count + abs(head - dest)
            head = dest
            seek_sequence.append(dest)
                                                    # Go DOWN left slice and then UP right slice 

        while(len(right_slice) > 0):
            dest = right_slice.pop(0)
            seek_count = seek_count + abs(head - dest)
            head = dest
            seek_sequence.append(dest)

    elif(direction == 2 ):

        while(len(right_slice) > 0):
            dest = right_slice.pop(0)
            seek_count = seek_count + abs(head - dest)
            head = dest
            seek_sequence.append(dest)
                                                    # Go UP right slice and then DOWN left slice    

        while(len(left_slice)):
            dest = left_slice.pop()
            seek_count = seek_count + abs(head - dest)
            head = dest
            seek_sequence.append(dest)
    else:
        print("Incorrect direction provided")
        return 0, [0]

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
    sc, ss = n_scan(init, req_arr)
    print("Seek count:", sc)
    print("Seek Sequence: ")
    for addr in ss:
        print(addr)



if __name__ == '__main__':
    main()
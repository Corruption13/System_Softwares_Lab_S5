"""
C-SCAN Algorithm for disk scheduling.

    S Sandeep Pillai
    CS5A
    59
"""


def c_scan(init_head, reqArr):
    """
        Circular SCAN Algorithm: 
         Go left from initial address to end address and then reset back to start 
         index and then traverse all remaining addresses in same order.
         Or vice versa.
         Direction is decided by nearest first initial node with respect to head.

    """
    head = init_head
    seek_count = 0
    seek_sequence = [init_head, ]
    reqArr = reqArr + [0, head] # Add two more nodes to request list.
    reqArr.sort()
    n = len(reqArr) 
    end = 200
    index = reqArr.index(head)
    right_slice = reqArr[index+1:]
    left_slice = reqArr[:index]
    while(True):  # We need the end of cylinder for c-scan i guess.
        end = int(input("Enter address of left-most cylinder: "))
        if(end < right_slice[-1]):
            print("Must be greater than ", right_slice[-1])
        else:
            right_slice.append(end) # Add max_address to right slice.
            break

    if(head - left_slice[-1] < right_slice[0] - head):  # If nearest address from initial head is towards left, go left.

        print("\n<<< Optimal Path is towards left! >>>\n")
        while(len(left_slice)):
            dest = left_slice.pop()
            seek_count = seek_count + abs(head - dest)
            head = dest
            seek_sequence.append(dest)

        head = end    # Set head to right-most address

        while(len(right_slice) > 0):
            dest = right_slice.pop()
            seek_count = seek_count + abs(head - dest)
            head = dest
            seek_sequence.append(dest)

    elif(head - left_slice[-1] >= right_slice[0] - head):  # If nearest address from initial head is towards right, go right.
        
        print("\n<<< Optimal Path is towards right! >>>\n")
        while(len(right_slice) > 0):
            dest = right_slice.pop(0)
            seek_count = seek_count + abs(head - dest)
            head = dest
            seek_sequence.append(dest)

        head = 0      # Set head to left-most address
        
        while(len(left_slice)):
            dest = left_slice.pop(0)
            seek_count = seek_count + abs(head - dest)
            head = dest
            seek_sequence.append(dest)

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
    sc, ss = c_scan(init, req_arr)
    print("Seek count:", sc)
    print("Seek Sequence: ")
    for addr in ss:
        print(addr, end=" -> ")



if __name__ == '__main__':
    main()
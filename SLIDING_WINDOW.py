# TECHNIQUE [ SLIDING WINDOW ]
#
# We want to get a sum of ALL SUB-ARRAYS of size 'k'
# Since Sub-Array's are contiguous, we can use Sliding Window
#                           -> If we want to traverse one element at a time
#                           -> Operates on Linear DS like -> Linked List, Array, String etc.
#                           -> While Sliding, notice what operations we are repeating, and avoid those
#                               

def sum_subarray_k_length (arr, k):

# Sliding Window:
    # Because we want to work on each possible sub-array [ which are contiguous ]
    # If the first sub-array is [ 0 -> K] and the second is [ 1 => (K + 1) ], do NOT re-add the numbers from [ 1 to K ]

    i = 0
    sub_arr_sum = sum(arr[0 : k])

    while (i < len(arr) - k):
        # Adding a new element and subtracting the first one (avoids repetition)
        sub_arr_sum = sub_arr_sum + arr[k + i] - arr[i]
        i += 1

#* print("sum: arr[" + str(i) + "] -> arr[" + str(k + i) + "] = " + str(sub_arr_sum))



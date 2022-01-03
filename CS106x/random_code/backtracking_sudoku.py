class Solution:
    #User Defined
    N = 9
    EMP_STR = " " #Empty String
    BOARD = [ #make it more user friendly
[" ", " ", " ", " ", " ", " ", " ", " ", " "],

[" ", " ", " ", " ", " ", " ", " ", " ", " "],

[" ", " ", " ", " ", " ", " ", " ", " ", " "],

[" ", " ", " ", " ", " ", " ", " ", " ", " "],

[" ", " ", " ", " ", " ", " ", " ", " ", " "],

[" ", " ", " ", " ", " ", " ", " ", " ", " "],

[" ", " ", " ", " ", " ", " ", " ", " ", " "],

[" ", " ", " ", " ", " ", " ", " ", " ", " "],

[" ", " ", " ", " ", " ", " ", " ", " ", " "]]

#Interesting Note - When you fill a few entries in the board above, the algorithm will generate ALL possible solutions for that
#given initial state. Most puzzles online fill entries in such a way that ONLY 1 solution is possible.

#################################################################################################################################
# DO NOT CHANGE BELOW
#################################################################################################################################

    def isvalid(self, board, x, j, i):
        row_nums = []
        col_nums = []
        sqr_nums = []
        
        for r in range(0, self.N):
            if board[j][r] != self.EMP_STR:
                row_nums.append(int(board[j][r]))
            if board[r][i] != self.EMP_STR:
                col_nums.append(int(board[r][i]))

        sqr_row = (i//3)*3
        sqr_col = (j//3)*3

        for c in range(0, 3):
            for r in range(0,3):
                if board[sqr_col + c][sqr_row + r] != self.EMP_STR:
                    sqr_nums.append(int(board[sqr_col + c][sqr_row + r]))

        #To make this function faster, "return False" whenever we find the exact match in row, col or square.
        #Dont do an exhaustive search on all existing numbers and then see if input is valid
        if x in row_nums or x in col_nums or x in sqr_nums:
            return False
        
        return True
        
    def solveSudokuHelper(self, board, j, i):
        
    #Will execute ONLY for Valid cases [ Because Invalid cases never reach here ]
        if(j == self.N): #OOB
            for r in board:
                print(r)
                print("\n")
            print("\n\n")
            return
                            
        if board[j][i] == self.EMP_STR:
            for x in range(1, self.N + 1): #From an exhaustive input list
#Core Algo Start
                if(self.isvalid(board, x, j, i)): #Find the valid inputs

                    #Change the STATE of the 'board' by feeding a Valid input
                    board[j][i] = str(x)
                    
                    #Go to the next state with the given choice/input
                    if(i == self.N - 1):
                        self.solveSudokuHelper(board, j + 1, 0)
                    else:
                        self.solveSudokuHelper(board, j, i + 1)
                        
                    board[j][i] = self.EMP_STR #Reset the chosen action [ Essence of Back-Tracking ]
#Core Algo end
                else:
                    continue #for this algo, if we NEVER find a Valid input, the chain breaks
        else: #If number exists then just move on [ jump to next state without changing the current ]
            if(i == self.N - 1):
                #Pass the current state i.e. "board
                #and also information on how to go to
                #the next state i.e. 'j + 1, 0'" etc.
                self.solveSudokuHelper(board, j + 1, 0)
            else:
                self.solveSudokuHelper(board, j, i + 1)  
            
    def solveSudoku(self):
        
        #Current State is represented by [board, i,j]
        self.solveSudokuHelper(self.BOARD, 0, 0)
        """
        Do not return anything, modify board in-place instead.
        """

s = Solution()
s.solveSudoku()

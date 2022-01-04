class Solution:
	def generateMatrix(self, A):
        b_most=A-1
        r_most=A-1
        top_most=0
        left_most=0
        direction=0
        curr_row=0
        curr_col=0
        n=1
        result = []
        r=[]
        for j in range(A):
            r.append(0)
        for i in range(A):
            result.append(r)
        
        while(n<=A*A):
            if(direction==0 and n<=A*A):
                for curr_col in range(left_most,r_most+1):   
                    result[curr_row][curr_col]=n
                    n=n+1
                direction=1
                top_most=top_most+1
                curr_col=curr_col+1
            
            elif(direction==1 and n<=A*A):
                curr_row=top_most
                while curr_row<=b_most:   
                    result[curr_row][curr_col]=n
                    n=n+1
                    curr_row=curr_row+1

                direction=2
                r_most=r_most-1
                curr_row=curr_row-1
            
            elif(direction==2 and n<=A*A):
                curr_col=r_most
                while curr_col>=left_most:
                    result[curr_row][curr_col]=n
                    n=n+1
                    curr_col=curr_col-1

                direction=3
                b_most=b_most-1
                curr_col=curr_col+1
            
            else:
                curr_row=b_most
                while curr_row>=top_most:
                    result[curr_row][curr_col]=n
                    n=n+1
                    curr_row=curr_row-1

                direction=0
                left_most=left_most+1
                curr_row=curr_row+1
               
        return result
    